<?php

include ("languages/$langdir/lang_attack.inc");
include ("globals/combat_functions.inc");
include ("globals/planet_bounty_check.inc");
include ("globals/collect_bounty.inc");
include ("globals/db_kill_player.inc");
include ("globals/player_ship_destroyed.inc");
include ("globals/send_system_im.inc");
include ("globals/planet_log.inc");
include ("globals/insert_news.inc");
include ("globals/get_rating_change.inc");
include ("globals/device_ship_tech_modify.inc");

$shipinfo = device_ship_tech_modify($shipinfo, $shipdevice);

	if ($sofa_on and $planetinfo['owner'] != 3)
	{
		if($playerinfo[turns] < 1)
		{
			echo "$l_cmb_atleastoneturn<BR><BR>";
			echo $l_global_mmenu;
			include("footer.php");
			die();
		}
		if($shipinfo[fighters] <1)
		{
			echo "$l_cmb_needfighters<BR><BR>";
			echo $l_global_mmenu;
			include("footer.php");
			die();
		}

		$res = $db->SelectLimit("SELECT last_login FROM {$db_prefix}players WHERE player_id = $ownerinfo[player_id]", 1);
		$last_login = $res->fields['last_login'];
		$res->close();
		send_system_im($ownerinfo['player_id'], $l_planet_imtitleattack, $playerinfo['character_name'] . " $l_planet_imsofa $planetinfo[name] $l_planet_iminsector $planetinfo[sector_name].", $last_login);

		update_player_experience($playerinfo['player_id'], $sofa_planet);
		$isfedbounty = planet_bounty_check($playerinfo, $shipinfo['sector_id'], $ownerinfo, 1);

		if($isfedbounty > 0)
		{
			echo $l_by_fedbounty2 . "<BR><BR>";
		}

		planet_log($planetinfo['planet_id'],$planetinfo['owner'],$playerinfo['player_id'],"PLOG_SOFA");

		$base_factor = ($planetinfo['base'] == 'Y') ? round($basedefense * (1 - ($planetinfo['fighter'] / $max_tech_level))) : 0;
		$planet_comp_level = NUM_FIGHTERS($planetinfo['fighter'] + $base_factor);
		$figs = $planetinfo['fighters'];
		$res = $db->Execute("SELECT * FROM {$db_prefix}ships WHERE planet_id=$planetinfo[planet_id] AND on_planet='Y'");
		if ($res)  
		{
			while (!$res->EOF)  
			{
				$figs += $res->fields['fighters'];  
				$ship_comp =  NUM_FIGHTERS($res->fields['fighter']);  
				$planet_comp_level = $planet_comp_level + $ship_comp;  
				$res->MoveNext();  
			}
		}
		$res->close();

		if ($planet_comp_level > $figs)
		{
			$targetfighters = $figs;
		}
		else
		{
			$targetfighters = $planet_comp_level;
		}

		$base_factor = ($planetinfo['base'] == 'Y') ? round($basedefense * (1 - ($planetinfo['torps'] / $max_tech_level))) : 0;
		$planet_comp_level = NUM_TORPEDOES($planetinfo['torps'] + $base_factor);
		$torps = $planetinfo['torps'];
		$res = $db->Execute("SELECT * FROM {$db_prefix}ships WHERE planet_id=$planetinfo[planet_id] AND on_planet='Y'");
		if ($res)  
		{
			while (!$res->EOF)  
			{
				$torps += $res->fields['torps'];  
				$ship_comp =  NUM_TORPEDOES($res->fields['torps']);  
				$planet_comp_level = $planet_comp_level + $ship_comp;  
				$res->MoveNext();  
			}
		}
		$res->close();

		if ($planet_comp_level > $torps)
		{
			$target_torps_left = $torps;
		}
		else
		{
			$target_torps_left = $planet_comp_level;
		}

		$attacker_fighters_left = $shipinfo['fighters'];
		$target_shield_energy = floor($planetinfo['energy'] * 0.4);
		$target_beam_energy = $planetinfo['energy'] - $target_shield_energy;

		$base_factor = ($planetinfo['base'] == 'Y') ? round($basedefense * (1 - ($planetinfo['beams'] / $max_tech_level))) : 0;
		if ($planetinfo['beams'] == 0) 
		{
			$targetbeams = 0;
		}
		else
		{
			$targetbeams = NUM_BEAMS($planetinfo['beams'] + $base_factor);
		}

		$res = $db->Execute("SELECT * FROM {$db_prefix}ships WHERE planet_id=$planetinfo[planet_id] AND on_planet='Y'");
		while (!$res->EOF)
		{
			$targetbeams += NUM_BEAMS($res->fields['beams']);
			$res->MoveNext();
		}
		$res->close();

		if ($targetbeams < $target_beam_energy)
		{
			$target_beam_energy = $targetbeams;
		}

		$targetenergyset = $target_beam_energy;

		// get attacker beam, shield and armor values
		$attacker_shield_energy = floor($shipinfo['energy'] * 0.4);

		$attackershields = NUM_SHIELDS($shipinfo['shields']);

		if ($attackershields < $attacker_shield_energy)
		{
			$attacker_shield_energy = $attackershields;
		}

		$attackerarmor = $shipinfo['armor_pts'];

		$attackerenergyset = $attacker_shield_energy;

		$targetlowpercent = ecmcheck($shipinfo['ecm'], $planetinfo['sensors'], -$full_attack_modifier);
		$attackerlowpercent = ecmcheck($shipinfo['sensors'], $shipinfo['sensors'], $full_attack_modifier);



		if(!class_exists($shipinfo['fighter_class'])){
			include ("class/" . $shipinfo['fighter_class'] . ".inc");
		}

		$attackobject = new $shipinfo['fighter_class']();
		$fighter_damage_all = $attackobject->fighter_damage_all;

		if(!class_exists($shipinfo['shield_class'])){
			include ("class/" . $shipinfo['shield_class'] . ".inc");
		}

		$attackobject = new $shipinfo['shield_class']();
		$ship_shield_hit_pts = $attackobject->ship_shield_hit_pts;

		if(!class_exists($shipinfo['armor_class'])){
			include ("class/" . $shipinfo['armor_class'] . ".inc");
		}

		$attackobject = new $shipinfo['armor_class']();
		$ship_armor_hit_pts = $attackobject->ship_armor_hit_pts;

		if(!class_exists($planetinfo['fighter_class'])){
			include ("class/planet/" . $planetinfo['fighter_class'] . ".inc");
		}

		$targetobject = new $planetinfo['fighter_class']();
		$fighter_hit_pts = $targetobject->hit_pts;

		if(!class_exists($planetinfo['beam_class'])){
			include ("class/planet/" . $planetinfo['beam_class'] . ".inc");
		}

		$targetobject = new $planetinfo['beam_class']();
		$beam_damage_all = $targetobject->damage_all;
		$beam_damage_shields = $targetobject->damage_shields;

		if(!class_exists($planetinfo['torp_class'])){
			include ("class/planet/" . $planetinfo['torp_class'] . ".inc");
		}

		$targetobject = new $planetinfo['torp_class']();
		$torp_hit_pts = $targetobject->hit_pts;

		//  Check to see if planet detects planet bombs.
		$success = max(min((((5 + $planetinfo['sensors'])-($shipinfo['cloak'])) * 10), 95), 5);

		$$energy_lost = 0;
		//echo "$attackercloak $planetsensors $roll  $success<br>";
		 if (mt_rand(1, 100) < $success)
		{
			// All of Beams Fire
			$ddamageroll=mt_rand(1,25);
			if ($ddamageroll==1){
				$target_beam_energy = round(mt_rand(round($target_beam_energy/2), $target_beam_energy)*2);
				echo "<b><font  color=#ff0000>$l_planet_beamfire1</font></b><br><br>";
			}
			if ($ddamageroll==2){
				$target_beam_energy = round(mt_rand(round($target_beam_energy/2), $target_beam_energy)*3);
				echo "<b><font  color=#ff0000>$l_planet_beamfire2</font></b><br><br>";
			}
			if($ddamageroll==3){
				$target_beam_energy = round(mt_rand(round($target_beam_energy/2), $target_beam_energy)*4);
				echo "<b><font  color=#ff0000>$l_planet_beamfire3</font></b><br><br>";
			}
			if($ddamageroll > 3){
				$target_beam_energy = mt_rand(round($target_beam_energy/2), $target_beam_energy);
				echo "<b><font  color=#ff0000>$l_planet_beamfire4</font></b><br><br>";
			}

			echo "<table width=\"75%\" border=\"1\" cellspacing=\"1\" cellpadding=\"4\" bgcolor=\"#000000\">
			<tr><td colspan=2 align=center><b><font  color=#00ff00>$l_att_beams</font></b></td></tr>
				<tr>
					<td>";

			if($target_beam_energy != 0)
			{
				$target_fire_damage = calc_damage($target_beam_energy, $beam_damage_shields, $targetlowpercent, $targetshipbeams, $shipinfo['shields']);
				if($target_fire_damage[2] == 100){
					echo "<br><font color='#ff0000' ><b><font color=white >" . $planetinfo['name'] . "</font>$l_planet_sofanobeamsshields</b></font><br><br>";
				}

				$target_energy_left = $target_fire_damage[1];

				//
				$attacker_shields = calc_failure($attacker_shield_energy, $shipinfo['shields'], $targetshipbeams);

				$attack_shield_hit_pts = $attacker_shield_energy * $ship_shield_hit_pts;

				//
				$attacker_armor = calc_failure($attackerarmor, $shipinfo['armor'], $targetshipbeams);

				$attack_armor_hit_pts = $attackerarmor * $ship_armor_hit_pts;
				if($target_fire_damage[0] > $attack_shield_hit_pts)
				{
					$target_fire_damage[0] = $target_fire_damage[0] - $attack_shield_hit_pts;
					if($attacker_shield_energy > 0)
						echo "<font color='#00ff00'><b>$l_att_yhits <FONT COLOR='yellow'>" . NUMBER($attacker_shield_energy) . "</font> $l_att_dmg.</b></font><br>";
					echo "<br><font color='#ff0000' ><b>$l_att_ydown</b></font><br><br>";
					$attacker_shields_left = 0;
					$target_energy_left += floor($target_fire_damage[0] / max(1,$beam_damage_shields));
					$target_fire2_damage = calc_damage($target_energy_left, $beam_damage_all, $targetlowpercent, $targetshipbeams, $shipinfo['armor']);
					$target_energy_left += $target_fire2_damage[1];

					if($target_fire2_damage[2] == 100){
						echo "<br><font color='#ff0000' ><b><font color=white >" . $planetinfo['name'] . "</font>$l_planet_sofanobeamsarmor</b></font><br><br>";
					}

					if($target_fire2_damage[0] > $attack_armor_hit_pts)
					{
						$target_fire2_damage[0] = $target_fire2_damage[0] - $attack_armor_hit_pts;
						$attack_damage = floor($attack_armor_hit_pts / max(1,$ship_armor_hit_pts));
						if($attack_damage > 0)
							echo "<font color='#00ff00'><b>$l_att_ayhit <FONT COLOR='yellow'>" . NUMBER($attack_damage) . "</font> $l_att_dmg.</b></font><br>";
						echo "<br><font color='#ff0000' ><b>$l_att_yarm</b></font><br><br>";
						$target_energy_left += floor($target_fire2_damage[0] / max(1,$beam_damage_all));
						$attacker_armor_left = 0;
					}
					else
					{
						$attack_armor_hit_pts = $attack_armor_hit_pts - $target_fire2_damage[0];
						$attacker_armor_used = floor($target_fire2_damage[0] / max(1,$ship_armor_hit_pts));
						echo "<font color='#00ff00'><b>$l_att_ayhit <FONT COLOR='yellow'>" . NUMBER($attacker_armor_used) . "</font> $l_att_dmg.</b></font><br>";
						$attacker_armor_left = floor($attack_armor_hit_pts / $ship_armor_hit_pts);
					}
				}
				else
				{
					$attack_shield_hit_pts = $attack_shield_hit_pts - $target_fire_damage[0];
					$attacker_shields_used = floor($target_fire_damage[0] / max(1,$ship_shield_hit_pts));
					echo "<font color='#00ff00'><b>$l_att_yhits <FONT COLOR='yellow'>" . NUMBER($attacker_shields_used) . "</font> $l_att_dmg.</b></font><br>";
					$attacker_shields_left = floor($attack_shield_hit_pts / $ship_shield_hit_pts);
					$attacker_armor_left = $attackerarmor;
				}
			}
			else
			{
				echo "<br><b><font color='#ff0000'><font color=white>" . $planetinfo['name'] . "</font> $l_att_tnobeams</font><b><br><br>";
				$attacker_shields_left = $attacker_shield_energy;
				$attacker_armor_left = $attackerarmor;
				$target_energy_left = 0;
			}

			echo "</td></tr></table>";

			$armor_lost=$shipinfo['armor_pts']-$attacker_armor_left;
			$energy_lost=$attackerenergyset - $attacker_shields_left;

			$debug_query = $db->Execute("UPDATE {$db_prefix}ships SET armor_pts=GREATEST(armor_pts - $armor_lost, 0), energy=GREATEST(energy - $energy_lost, 0) WHERE ship_id=$shipinfo[ship_id]");
			db_op_result($debug_query,__LINE__,__FILE__);

			$energy_lost=$targetenergyset - $attacker_energy_left;

			$debug_query = $db->Execute("UPDATE {$db_prefix}planets SET energy=GREATEST(energy - $energy_lost, 0) WHERE planet_id=$planetinfo[planet_id]");
			db_op_result($debug_query,__LINE__,__FILE__);


			if($attacker_armor_left < 1 and $attacker_shields_left < 1)
			{
				$free_ore = round($shipinfo['ore']/2);
				$free_organics = round($shipinfo['organics']/2);
				$free_goods = round($shipinfo['goods']/2);
				$ship_value=$upgrade_cost*(round(mypw($upgrade_factor, $shipinfo['hull']))+round(mypw($upgrade_factor, $shipinfo['engines']))+round(mypw($upgrade_factor, $shipinfo['power']))+round(mypw($upgrade_factor, $shipinfo['fighter']))+round(mypw($upgrade_factor, $shipinfo['sensors']))+round(mypw($upgrade_factor, $shipinfo['beams']))+round(mypw($upgrade_factor, $shipinfo['torp_launchers']))+round(mypw($upgrade_factor, $shipinfo['shields']))+round(mypw($upgrade_factor, $shipinfo['armor']))+round(mypw($upgrade_factor, $shipinfo['cloak']))+round(mypw($upgrade_factor, $shipinfo['ecm'])));
				$ship_salvage_rate=mt_rand(0,10);
				$ship_salvage=$ship_value*$ship_salvage_rate/100;
				echo "<BR><CENTER><FONT SIZE='+2' COLOR='RED'><B>$l_cmb_yourshipdestroyed</FONT></B></CENTER><BR>";

				if($shipdevice['dev_escapepod']['amount'] == 1) 
				{
					$shipid1=$shipinfo['ship_id'];
					echo "<CENTER><FONT COLOR='WHITE'>$l_cmb_escapepod</FONT></CENTER><BR><BR>";

					player_ship_destroyed($shipid1, $playerinfo['player_id'], $playerinfo['rating'], 0, 0, "killedsofapod");

					collect_bounty($planetinfo['owner'],$playerinfo['player_id']);
					$playernames = $playerinfo['character_name'];
					insert_news($playernames, 1, "pattackerpod");
				}
				else
				{
					db_kill_player($playerinfo['player_id'], 0, 0, "killedsofa");
					collect_bounty($planetinfo['owner'],$playerinfo['player_id']);
					$playernames = $playerinfo['character_name'];
					insert_news($playernames, 1, "pattackerdied");
				}
			}
			else
			{
				$free_ore=0;
				$free_goods=0;
				$free_organics=0;
				$ship_salvage_rate=0;
				$ship_salvage=0;

				echo "<BR><BR>";
				if($attacker_armor_left > 0)
					calc_internal_damage($shipinfo['ship_id'], 0, ($shipinfo['armor_pts']-$attacker_armor_left) / $shipinfo['armor_pts']);
			}
		}
		else
		{
			$attacker_shields_left = $attacker_shield_energy;
			$attacker_armor_left = $attackerarmor;
		}

		if($attacker_armor_left > 0 or $attacker_shields_left > 0)
		{

			echo "<table width=\"75%\" border=\"1\" cellspacing=\"1\" cellpadding=\"4\" bgcolor=\"#000000\">
			<tr><td colspan=2 align=center><b><font  color=#00ff00>$l_att_fighters</font></b><tr><td width=50%>";

			if($attacker_fighters_left != 0)
			{
				$attack_fighter_damage = calc_damage($attacker_fighters_left, $fighter_damage_all, $attackerlowpercent, $shipinfo['fighter'], $targetshipfighter);

				if($attack_fighter_damage[2] > 0){
					echo "<br><font color='#00ff00'><b><font color='#ff0000'>$l_planet_flauncherfailed1</font><br>$l_planet_flauncherfailed2<font color='#ffffff'>" . (100 - $attack_fighter_damage[2]) . "</font>$l_planet_flauncherfailed3</b></font><br><br>";
				}

				$target_fighter_hit_pts = $targetfighters * $fighter_hit_pts;
				if($attack_fighter_damage[0] > $target_fighter_hit_pts)
				{
					$attack_fighter_damage[0] = $attack_fighter_damage[0] - $target_fighter_hit_pts;
					if($target_fighters_left > 0)
						echo "<font color='#00ff00'><b><FONT COLOR='yellow'>" . NUMBER($target_fighters_left) . "</font> $l_att_of <font color=white>" . $planetinfo['name'] . "</font>$l_att_efhit</b></font><br>";
					echo "<br><font color='#ff0000' ><b><font color=white >" . $planetinfo['name'] . "</font> $l_att_lostf</b></font><br><br>";
					$attacker_fighters_left2 = floor($attack_fighter_damage[0] / $fighter_damage_all);
					$attack_fighter2_damage = calc_damage($attacker_fighters_left2, $fighter_damage_all, $attackerlowpercent, $shipinfo['fighter'], $targetshiptorp_launchers);

					if($attack_fighter2_damage[2] > 0){
						echo "<br><font color='#00ff00'><b><font color='#ff0000'>$l_planet_flauncherfailed1</font><br>$l_planet_flauncherfailed2<font color='#ffffff'>" . (100 - $attack_fighter2_damage[2]) . "</font>$l_planet_flauncherfailed3</b></font><br><br>";
					}

					$target_torp_hit_pts = $target_torps_left * $torp_hit_pts;
					if($attack_fighter2_damage[0] > $target_torp_hit_pts)
					{
						$attack_fighter2_damage[0] = $attack_fighter2_damage[0] - $target_torp_hit_pts;
						$attack_damage = floor($target_torp_hit_pts / $torp_hit_pts);
						if($attack_damage > 0)
							echo "<font color='#00ff00'><b><FONT COLOR='yellow'>" . NUMBER($attack_damage) . "</font> $l_att_of <font color=white>" . $planetinfo['name'] . "</font>$l_att_ethit</b></font><br>";
						echo "<br><font color='#ff0000' ><b><font color=white >" . $planetinfo['name'] . "</font> $l_att_lostt</b></font><br><br>";
						$target_torps_left2 = 0;
					}
					else
					{
						$target_torp_hit_pts = $target_torp_hit_pts - $attack_fighter2_damage[0];
						$target_torps_used = floor($attack_fighter2_damage[0] / $torp_hit_pts);
						echo "<font color='#00ff00'><b><FONT COLOR='yellow'>" . NUMBER($target_torps_used) . "</font> $l_att_of <font color=white>" . $planetinfo['name'] . "</font>$l_att_ethit</b></font><br>";
						$target_torps_left2 = floor($target_torp_hit_pts / $torp_hit_pts);
					}
				}
				else
				{
					$target_fighter_hit_pts = $target_fighter_hit_pts - $attack_fighter_damage[0];
					$target_fighters_used = floor($attack_fighter_damage[0] / $fighter_hit_pts);
					echo "<font color='#00ff00'><b><FONT COLOR='yellow'>" . NUMBER($target_fighters_used) . "</font> $l_att_of <font color=white>" . $planetinfo['name'] . "</font>$l_att_efhit</b></font><br>";
					$target_fighters_left2 = floor($target_fighter_hit_pts / $fighter_hit_pts);
					$target_torps_left2 = $target_torps_left;
				}
			}
			else
			{
				echo "<br><b><font color='#ff0000'>$l_att_anofighters</font><b><br><br>";
				$target_fighters_left2 = $target_fighters_left;
				$target_torps_left2 = $target_torps_left;
				
			}

			echo "</td><td width=50%>";

			if($targetfighters != 0)
			{
				$target_fighter_damage = calc_damage($targetfighters, $fighter_damage_all, $targetlowpercent, $targetshipfighter, $shipinfo['fighter']);

				if($target_fighter_damage[2] == 100){
					echo "<br><font color='#ff0000' ><b><font color=white >" . $planetinfo['name'] . "</font>$l_planet_nodfightertofighter</b></font><br><br>";
				}

				$attack_fighter_hit_pts = $attacker_fighters_left * $fighter_hit_pts;
				if($target_fighter_damage[0] > $attack_fighter_hit_pts)
				{
					$target_fighter_damage[0] = $target_fighter_damage[0] - $attack_fighter_hit_pts;
					if($attacker_fighters_left > 0)
						echo "<font color='#00ff00'><b><FONT COLOR='yellow'>" . NUMBER($attacker_fighters_left) . "</font> $l_att_yfhit</b></font><br>";
					echo "<br><font color='#ff0000' ><b>$l_att_ylostf</b></font><br><br>";
					$target_fighters_left3 = floor($target_fighter_damage[0] / $fighter_damage_all);
					$target_fighter2_damage = calc_damage($target_fighters_left3, $fighter_damage_all, $targetlowpercent, $targetshipfighter, $shipinfo['torp_launchers']);

					if($target_fighter2_damage[2] == 100){
						echo "<br><font color='#ff0000' ><b><font color=white >" . $planetinfo['name'] . "</font>$l_planet_nodfightertotorp</b></font><br><br>";
					}
				}
				else
				{
					$attack_fighter_hit_pts = $attack_fighter_hit_pts - $target_fighter_damage[0];
					$attack_fighters_used = floor($target_fighter_damage[0] / $fighter_hit_pts);
					echo "<font color='#00ff00'><b><FONT COLOR='yellow'>" . NUMBER($attack_fighters_used) . "</font> $l_att_yfhit</b></font><br>";
					$attacker_fighters_left2 = floor($attack_fighter_hit_pts / $fighter_hit_pts);
				}
			}
			else
			{
				echo "<br><b><font color='#ff0000'><font color=white>" . $planetinfo['name'] . "</font> $l_att_tfnoattack</font><b><br><br>";
				$attacker_fighters_left2 = $attacker_fighters_left;
			}

			echo "</td></tr></table>";

			if($targetinfo['player_id'] <= 3){
				$rating_SOFA_attack_planet = 0;
			}
			$rating_change=get_rating_change($playerinfo['rating'], $ownerinfo['rating'], $rating_SOFA_attack_planet, $ownerinfo['player_id']);
			$debug_query = $db->Execute("UPDATE {$db_prefix}players SET rating=rating+$rating_change, turns=turns-1, turns_used=turns_used+1 WHERE player_id=$playerinfo[player_id]");
			db_op_result($debug_query,__LINE__,__FILE__);

			$fighters_lost=$shipinfo['fighters']-$attacker_fighters_left2;

			$debug_query = $db->Execute("UPDATE {$db_prefix}ships SET fighters=GREATEST(fighters-$fighters_lost, 0) WHERE ship_id=$shipinfo[ship_id]");
			db_op_result($debug_query,__LINE__,__FILE__);

			$fighters_lost=$planetinfo['fighters']-$target_fighters_left2;
			$torps_lost=$planetinfo['torps']-$target_torps_left;

			$debug_query = $db->Execute("UPDATE {$db_prefix}planets SET fighters=GREATEST(fighters-$fighters_lost, 0), torps=GREATEST(torps-$torps_lost, 0) WHERE planet_id=$planetinfo[planet_id]");
			db_op_result($debug_query,__LINE__,__FILE__);

			playerlog($ownerinfo['player_id'], "LOG5_PLANET_BOMBED", "$planetinfo[name]|$shipinfo[sector_id]|$playerinfo[character_name]|$beamsused|$torps_lost|$fighters_lost");
		}

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
		echo "$l_command_no<BR>";
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