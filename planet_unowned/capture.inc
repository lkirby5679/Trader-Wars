<?php
include ("languages/$langdir/lang_attack.inc");

include ("globals/change_planet_ownership.inc");
include ("globals/get_player.inc");
include ("globals/calc_ownership.inc");
include ("globals/gen_score.inc");
include ("globals/planet_log.inc");
include ("globals/capture_planet_ships.inc");
include ("globals/good_neutral_evil.inc");

//
//
// Capture Unowned or Defeated planet
//
//

	if ($planetinfo['owner'] == 0 || $planetinfo['defeated'] == 'Y')
	{
		echo "$l_planet_captured<BR>";
		if ($enable_spies)
		{
			$spies = $db->Execute("SELECT COUNT(spy_id) as total FROM {$db_prefix}spies WHERE active='Y' AND ship_id = '0' AND planet_id = $planet_id");
			db_op_result($spies,__LINE__,__FILE__);
			$num_spies = $spies->RecordCount();
		}
		else
		{
			$num_spies = 0;
		}
		change_planet_ownership($planet_id, 0, $playerinfo['player_id']);

		if($planetinfo['owner'] != 0 && $planetinfo['owner'] != 2 && $planetinfo['owner'] != 3)
			update_player_experience($playerinfo['player_id'], $defeating_planet);

		if($planetinfo['owner'] != 0 && (($planetinfo['team'] != $playerinfo['team'] && $playerinfo['team'] != 0) || $playerinfo['team'] == 0)){
			$debug_query = $db->Execute("UPDATE {$db_prefix}players SET captures=captures+1, planet_update='Y' WHERE player_id=$playerinfo[player_id]");
			db_op_result($debug_query,__LINE__,__FILE__);
		}

		$new_age = floor(($display_percentage_age / 2) + mt_rand(0, $display_percentage_age));
		$capture_countdown = mt_rand(floor($capture_countdown_max / 3), $capture_countdown_max);
		$capture_quickfind = floor($planetinfo['credits'] * ((mt_rand(floor($capture_quickfind_percentage / 2), $capture_quickfind_percentage) + $num_spies) * 0.01));
		$hiddencredits = max($planetinfo['credits'] - $capture_quickfind, 0);
		$persuasion_countdown = mt_rand(floor($persuasion_countdown_max / 3), $persuasion_countdown_max);
		if($planetinfo['owner'] == 0)
		{
			$old_owner_rating = 0;
		}
		else
		{
			$old_rating = good_neutral_evil($planetinfo['owner']);
			$old_owner_rating = $old_rating[0];
		}

		$debug_query = $db->Execute("UPDATE {$db_prefix}planets SET last_owner_rating = $old_owner_rating, persuasion_countdown = $persuasion_countdown, credits = $capture_quickfind, captured_countdown = $capture_countdown, hidden_credits = $hiddencredits, use_age=$new_age, cargo_hull = 0, cargo_power = 0, team=null, owner=$playerinfo[player_id], base='N', defeated='N' WHERE planet_id=$planet_id");
		db_op_result($debug_query,__LINE__,__FILE__);
		$debug_query = $db->Execute("DELETE from {$db_prefix}autotrades WHERE planet_id = $planet_id");
		db_op_result($debug_query,__LINE__,__FILE__);

		$ownership = calc_ownership($shipinfo['sector_id']);

		if (!empty($ownership))
			echo "$ownership<p>";

		if ($planetinfo['owner'] != 0)
		{
			gen_score($planetinfo['owner']);
		}

		if ($planetinfo['owner'] != 0)
		{
			$res = $db->SelectLimit("SELECT character_name FROM {$db_prefix}players WHERE player_id=$planetinfo[owner]", 1);
			$query = $res->fields;
			$res->close();
			$planetowner=$query['character_name'];
			playerlog($planetinfo['owner'],"LOG5_PLANET_YOUR_CAPTURED","$planetinfo[name]|$shipinfo[sector_id]|$playerinfo[character_name]");
		}
		else
		{
			$planetowner="$l_planet_noone";
		}  

		$res2=$db->Execute("SELECT UNIX_TIMESTAMP(MAX(time)) as lasttime FROM {$db_prefix}planet_log WHERE planet_id=".$planetinfo['planet_id']." AND (action=".PLOG_CAPTURE." OR action=".PLOG_GENESIS_CREATE.")");
		$lasttime=$res2->fields['lasttime'];
		if ($lasttime)
		{
			$curtime = TIME();
			$difftime = ($curtime - $lasttime) / 60;
			if ($difftime <= 10)
			{
				adminlog("LOG0_RAW","<font color=yellow><B>Rapid planet recapture:</B></font><BR>planet_id=<B>".$planetinfo['planet_id']."</B>, sector=<B>".$shipinfo['sector_id']."</B>, attacker: <B>".get_player($playerinfo['player_id'])."</B>, owner: <B>".get_player($planetinfo['owner'])."</B>. Time difference=<B>".NUMBER($difftime,1)."</B> minutes. Money: <B>".$planetinfo['credits']."</B>, colonists: <B>".$planetinfo['colonists']."</B>.");
			}
			$res2->close();
		}
		planet_log($planetinfo['planet_id'],$planetinfo['owner'],$playerinfo['player_id'],"PLOG_CAPTURE");
		playerlog($playerinfo['player_id'], "LOG5_PLANET_CAPTURED", "$planetinfo[colonists]|$planetinfo[credits]|$planetowner");
		capture_planet_ships($playerinfo['player_id'], $planetinfo['planet_id']);

		echo "<BR><a href='planet.php?planet_id=$planet_id'>$l_clickme</a> $l_toplanetmenu<BR><BR>";

		if ($allow_ibank)
		{
			echo "$l_ifyouneedplan <A HREF=\"igb.php?planet_id=$planet_id\">$l_igb_term</A>.<BR><BR>";
		}

		echo "<A HREF =\"bounty.php\">$l_by_placebounty</A><p>";
		echo $l_global_mmenu;
		include ("footer.php");
		die();
	}
	else
	{
		echo "$l_planet_notdef<BR>";

		echo "<BR><a href='planet.php?planet_id=$planet_id'>$l_clickme</a> $l_toplanetmenu<BR><BR>";

		if ($allow_ibank)
		{
			echo "$l_ifyouneedplan <A HREF=\"igb.php?planet_id=$planet_id\">$l_igb_term</A>.<BR><BR>";
		}
		echo "<A HREF =\"bounty.php\">$l_by_placebounty</A><p>";
		echo $l_global_mmenu;
		include ("footer.php");
		die();
	}

?>