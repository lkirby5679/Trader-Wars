<?php
include ("languages/$langdir/lang_attack.inc");
include ("globals/combat_functions.inc");


	//
	//
	// Preview of possible attack results
	//
	//

	if ($planetinfo['owner'] != 3)
	{

		echo "<p align=\"center\"><font color=\"Yellow\" size=\"3\"><b>$l_planet_combatpreview</b></font></p>";
		if ($playerinfo['turns'] < 1)
		{
			echo "$l_cmb_atleastoneturn<BR><BR>";
			echo $l_global_mmenu;
			include ("footer.php");
			die();
		}

		$result2 = $db->SelectLimit("SELECT * FROM {$db_prefix}players WHERE player_id='$planetinfo[owner]'", 1);
		$targetinfo = $result2->fields;
		$result2->close();

		// get attacker beam, shield and armor values
		$attacker_shield_energy = floor($shipinfo['energy'] * 0.4);
		$attacker_beam_energy = $shipinfo['energy'] - $attacker_shield_energy;

		$attackershields = NUM_SHIELDS($shipinfo['shields']);

		if ($attackershields < $attacker_shield_energy)
		{
			$attacker_shield_energy = $attackershields;
		}

		$attacker_shield_hit_pts = $attacker_shield_energy * $ship_shield_hit_pts;
		$attacker_armor_hit_pts = $shipinfo['armor_pts'] * $ship_armor_hit_pts;

		$attackerbeams = NUM_BEAMS($shipinfo['beams']);

		if ($attackerbeams < $attacker_beam_energy)
		{
			$attacker_beam_energy = $attackerbeams;
		}

		$attack_beamtofighter_dmg = floor($attacker_beam_energy * 0.05);
		$attack_beamtotorp_dmg = floor($attacker_beam_energy * 0.025);
		$attacker_beam_energy_dmg = ($attacker_beam_energy - floor($attacker_beam_energy * 0.1) - floor($attacker_beam_energy * 0.1)) * $beam_damage_shields;

		$attackertorps = $shipinfo['torps'];

		$attackerarmor = $shipinfo['armor_pts'];

		$attackerfighters = $shipinfo['fighters'];

		$attackerlowpercent = ecmcheck($shipinfo['sensors'], $shipinfo['sensors'], $full_attack_modifier);

		// get target beam, shield and armor values
		$target_shield_energy = floor($planetinfo['energy'] * 0.4);
		$target_beam_energy = $planetinfo['energy'] - $target_shield_energy;

		$base_factor = ($planetinfo['base'] == 'Y') ? round($basedefense * (1 - ($planetinfo['shields'] / $max_tech_level))) : 0;
		if ($planetinfo['shields'] == 0) 
		{
			$targetshields = 0;
		}
		else
		{
			$targetshields = NUM_SHIELDS($planetinfo['shields'] + $base_factor);
		}

		$res = $db->Execute("SELECT * FROM {$db_prefix}ships WHERE planet_id=$planetinfo[planet_id] AND on_planet='Y'");
		while (!$res->EOF)
		{
			$targetshields += NUM_SHIELDS($res->fields['shields']);
			$res->MoveNext();
		}
		$res->close();

		$full_target_shield_energy = $target_shield_energy;

		if (($targetshields * $planet_shield_multiplier) < $target_shield_energy)
		{
			$target_shield_energy = $targetshields;
		}
		else
		{
			$target_shield_energy = floor($target_shield_energy / $planet_shield_multiplier);
		}

		$target_shield_hit_pts = $target_shield_energy * $ship_shield_hit_pts;

		$target_armor_hit_pts = $planetinfo['armor_pts'] * $ship_armor_hit_pts;

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

		$target_beamtofighter_dmg = floor($target_beam_energy * 0.05);
		$target_beamtotorp_dmg = floor($target_beam_energy * 0.025);
		$target_beam_energy_dmg = ($target_beam_energy - floor($target_beam_energy * 0.1) - floor($target_beam_energy * 0.1)) * $beam_damage_shields;

		$base_factor = ($planetinfo['base'] == 'Y') ? round($basedefense * (1 - ($planetinfo['torp_launchers'] / $max_tech_level))) : 0;
		$res = $db->Execute("SELECT * FROM {$db_prefix}ships WHERE planet_id=$planetinfo[planet_id] AND on_planet='Y'");
		$torp_launchers = NUM_TORPEDOES($planetinfo['torp_launchers'] + $base_factor) ;
		$torps = $planetinfo['torps'];
		if ($res)
		{
		   while (!$res->EOF)
			{
				$torps += $res->fields['torps'];  
				$ship_torps =  NUM_TORPEDOES($res->fields['torp_launchers']);
				$torp_launchers = $torp_launchers + $ship_torps;
				$res->MoveNext();
			}
		}
		$res->close();
		if ($torp_launchers > $torps)
		{
			$targettorps = $torps;
		}
		else
		{
			$targettorps = $torp_launchers;
		}

		$targetarmor = $planetinfo['armor_pts'];

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

		$targetlowpercent = ecmcheck($shipinfo['ecm'], $planetinfo['sensors'], -$full_attack_modifier);

		$success = SCAN_SUCCESS($shipinfo['sensors'], $planetinfo['cloak']);
		$roll = mt_rand(1, 100);
		if ($roll > $success)
		{
			$target_beam_energy=0;
		}
		$roll = mt_rand(1, 100);
		if ($roll > $success)
		{
			$targetfighters=0;
		}
		$roll = mt_rand(1, 100);
		if ($roll > $success)
		{
			$target_shield_energy=0;
		}
		$roll = mt_rand(1, 100);
		if ($roll > $success)
		{
			$targettorps=0;
		}
		$roll = mt_rand(1, 100);
		if ($roll > $success)
		{
			$targetarmor=0;
		}

echo "
		<CENTER>
		<table width='75%' border='0' bgcolor=\"#000000\">
		<tr><td colspan=6 align=center><hr></td></tr>
		<tr ALIGN='CENTER'>
		<td width='9%' height='27'></td>
		<td width='12%' height='27'><FONT COLOR='WHITE'>$l_cmb_beams</FONT></td>
		<td width='17%' height='27'><FONT COLOR='WHITE'>$l_cmb_fighters</FONT></td>
		<td width='18%' height='27'><FONT COLOR='WHITE'>$l_cmb_shields</FONT></td>
		<td width='11%' height='27'><FONT COLOR='WHITE'>$l_cmb_torps</FONT></td>
		<td width='11%' height='27'><FONT COLOR='WHITE'>$l_cmb_armor</FONT></td>
		</tr>
		<tr ALIGN='CENTER'>
		<td width='9%'> <FONT COLOR='yellow'><B>$l_cmb_you</B></td>
		<td width='12%'><FONT COLOR='RED'><B>&nbsp;".NUMBER($attacker_beam_energy)."&nbsp;</B></FONT></td>
		<td width='17%'><FONT COLOR='RED'><B>&nbsp;".NUMBER($attackerfighters)."&nbsp;</B></FONT></td>
		<td width='18%'><FONT COLOR='RED'><B>&nbsp;".NUMBER($attacker_shield_energy)."&nbsp;</B></FONT></td>
		<td width='11%'><FONT COLOR='RED'><B>&nbsp;".NUMBER($attackertorps)."&nbsp;</B></FONT></td>
		<td width='11%'><FONT COLOR='RED'><B>&nbsp;".NUMBER($attackerarmor)."&nbsp;</B></FONT></td>
		</tr>
		<tr ALIGN='CENTER'>
		<td width='9%'> <FONT COLOR='RED'>$l_cmb_planet $planetinfo[name]</td>
		<td width='12%'><FONT COLOR='RED'><B>&nbsp;".NUMBER(SCAN_ERROR($shipinfo['sensors'], $planetinfo['jammer'], $target_beam_energy))."&nbsp;</B></FONT></td>
		<td width='17%'><FONT COLOR='RED'><B>&nbsp;".NUMBER(SCAN_ERROR($shipinfo['sensors'], $planetinfo['jammer'], $targetfighters))."&nbsp;</B></FONT></td>
		<td width='18%'><FONT COLOR='RED'><B>&nbsp;".NUMBER(SCAN_ERROR($shipinfo['sensors'], $planetinfo['jammer'], $target_shield_energy))."&nbsp;</B></FONT></td>
		<td width='11%'><FONT COLOR='RED'><B>&nbsp;".NUMBER(SCAN_ERROR($shipinfo['sensors'], $planetinfo['jammer'], $targettorps))."&nbsp;</B></FONT></td>
		<td width='11%'><FONT COLOR='RED'><B>&nbsp;".NUMBER(SCAN_ERROR($shipinfo['sensors'], $planetinfo['jammer'], $targetarmor))."&nbsp;</B></FONT></td>
		</tr>
		<tr><td colspan=6 align=center>&nbsp;</td></tr>
		</table>
		</CENTER>
";

		if($planetinfo['owner'] != 3){
			$l_planet_att_link="<a href='planet.php?planet_id=$planet_id&command=attack'>" . $l_planet_att_link ."</a>";
			$l_planet_att=str_replace("[attack]",$l_planet_att_link,$l_planet_att);
		}
		$l_planet_scn_link="<a href='planet.php?planet_id=$planet_id&command=scan'>" . $l_planet_scn_link ."</a>";
		$l_planet_scn=str_replace("[scan]",$l_planet_scn_link,$l_planet_scn);
		echo "$l_planet_att <b>$l_planet_att_sure</b><p>";
		echo "$l_planet_scn<BR>";

		if ($sofa_on and $planetinfo['owner'] != 3) echo "<a href='planet.php?planet_id=$planet_id&command=sofa'>$l_sofa</a><BR>";

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