<?php
// This program is free software; you can redistribute it and/or modify it   
// under the terms of the GNU General Public License as published by the	 
// Free Software Foundation; either version 2 of the License, or (at your	
// option) any later version.												
// 
// File: attack.php

include ("config/config.php");
include ("languages/$langdir/lang_attack.inc");
include ("languages/$langdir/lang_bounty.inc");
include ("languages/$langdir/lang_planets.inc");
include ("languages/$langdir/lang_combat.inc");
include ("globals/combat_functions.inc");
include ("globals/ship_bounty_check.inc");
include ("globals/collect_bounty.inc");
include ("globals/db_kill_player.inc");
include ("globals/player_ship_destroyed.inc");
include ("globals/send_system_im.inc");
include ("globals/log_move.inc");
include ("globals/get_rating_change.inc");
include ("globals/device_ship_tech_modify.inc");

get_post_ifset("player_id, ship_id");

$template_object->enable_gzip = 0;

$title = $l_att_title;

if (checklogin() or $tournament_setup_access == 1)
{
	$template_object->enable_gzip = 0;
	include ("footer.php");
	die();
}

if($playerinfo['template'] == '' or !isset($playerinfo['template'])){
	$templatename = $default_template;
}else{
	$templatename = $playerinfo['template'];
}
include ("header.php");

if($base_template[basename($_SERVER['PHP_SELF'])] == 1){
	include ("globals/base_template_data.inc");
}
else
{
	$template_object->assign("title", $title);
	$template_object->assign("templatename", $templatename);
}

echo "<H1>$title</H1>\n";

mt_srand(hexdec(AAT_substr(md5(microtime()), -8)) & 0x7fffffff);

$player_id = stripnum($player_id);
$ship_id = stripnum($ship_id);

$result2 = $db->SelectLimit("SELECT * FROM {$db_prefix}players WHERE player_id='$player_id'", 1);
$targetinfo = $result2->fields;

$result = $db->SelectLimit("SELECT * FROM {$db_prefix}ships WHERE ship_id='$ship_id'", 1);
$targetship = $result->fields;

$targetshipdevice = $db->GetToFieldArray("SELECT * FROM {$db_prefix}ship_devices WHERE ship_id=$ship_id", '', 'class');

$targetship = device_ship_tech_modify($targetship, $targetshipdevice);
$shipinfo = device_ship_tech_modify($shipinfo, $shipdevice);

if ($playerinfo['team'] == $targetinfo['team'] && $targetinfo['team'] > 0)
{
	$template_object->assign("error_msg", $l_att_flee);
	$template_object->assign("gotomain", $l_global_mmenu);
	$template_object->display($templatename."attackdie.tpl");
	include ("footer.php");
	die();
}

if ($targetship['sector_id'] != $shipinfo['sector_id'] || $targetship['on_planet'] == "Y")
{
	$template_object->assign("error_msg", $l_att_notarg);
	$template_object->assign("gotomain", $l_global_mmenu);
	$template_object->display($templatename."attackdie.tpl");
	include ("footer.php");
	die();
}

if ($playerinfo['turns'] < 1)
{
	$template_object->assign("error_msg", $l_att_noturn);
	$template_object->assign("gotomain", $l_global_mmenu);
	$template_object->display($templatename."attackdie.tpl");
	include ("footer.php");
	die();
}

/* determine percent chance of success in detecting target ship - based on player's sensors and opponent's cloak */
$targetcloak = $targetship['cloak'];

$success = SCAN_SUCCESS($shipinfo['sensors'], $targetcloak, $shiptypes[$targetship['class']]['basehull']);

$targetengines = $targetship['engines'];

$flee = SCAN_SUCCESS($shipinfo['engines'], $targetengines, $shiptypes[$targetship['class']]['basehull']); 
$roll = mt_rand(1, 100);
$roll2 = mt_rand(1, 100);

$res = $db->Execute("SELECT allow_attack,{$db_prefix}universe.zone_id FROM {$db_prefix}zones,{$db_prefix}universe WHERE sector_id='$targetship[sector_id]' AND {$db_prefix}zones.zone_id={$db_prefix}universe.zone_id");
$query97 = $res->fields;

if ($query97['allow_attack'] == 'N' and $onplanet == 0)
{
	$template_object->assign("error_msg", $l_att_noatt);
	$template_object->assign("gotomain", $l_global_mmenu);
	$template_object->display($templatename."attackdie.tpl");
	include ("footer.php");
	die();
}

if ($flee < $roll2)
{
	send_system_im($targetinfo['player_id'], $l_att_imtitle, $playerinfo['character_name'] . " $l_att_imbody", $targetinfo['last_login']);
	$debug_query = $db->Execute("UPDATE {$db_prefix}players SET turns=turns-1,turns_used=turns_used+1 WHERE player_id=$playerinfo[player_id]");
	db_op_result($debug_query,__LINE__,__FILE__);
	playerlog($targetinfo['player_id'], "LOG5_ATTACK_OUTMAN", "$playerinfo[character_name]");
	$template_object->assign("error_msg", $l_att_flee);
	$template_object->assign("gotomain", $l_global_mmenu);
	$template_object->display($templatename."attackdie.tpl");
	include ("footer.php");
	die();
}

if ($roll > $success)
{
	/* if scan fails - inform both player and target. */
	$debug_query = $db->Execute("UPDATE {$db_prefix}players SET turns=turns-1,turns_used=turns_used+1 WHERE player_id=$playerinfo[player_id]");
	db_op_result($debug_query,__LINE__,__FILE__);

	playerlog($targetinfo['player_id'], "LOG5_ATTACK_OUTSCAN", "$playerinfo[character_name]");
	$template_object->assign("error_msg", $l_planet_noscan);
	$template_object->assign("gotomain", $l_global_mmenu);
	$template_object->display($templatename."attackdie.tpl");
	include ("footer.php");
	die();
}

/* if scan succeeds, show results and inform target. */
$shipavg = $targetship['basehull'] + ($targetship['hull'] + $targetship['engines'] + $targetship['power'] + $targetship['fighter'] + $targetship['sensors'] + $targetship['beams'] + $targetship['torp_launchers'] + $targetship['shields'] + $targetship['cloak'] + $targetship['armor'] + $targetship['ecm']) / 11;

if ($shipavg > $ewd_maxavgtechlevel)
{
	$chance = round($shipavg / $max_tech_level) * 100;
}
else
{
	$chance = 0;
}

$random_value = mt_rand(1,100);
if ($targetshipdevice['dev_emerwarp']['amount'] > 0 && $random_value > $chance)
{
	send_system_im($targetinfo['player_id'], $l_att_imtitle, $playerinfo['character_name'] . " $l_att_imbody", $targetinfo['last_login']);
	/* need to change warp destination to random sector in universe */
	$rating_change=get_rating_change($playerinfo['rating'], $targetinfo['rating'], $rating_attack_ship);
	$source_sector = $shipinfo['sector_id'];

	$findem = $db->SelectLimit("SELECT sector_id FROM {$db_prefix}universe where sg_sector = 0 and sector_id > 3 ORDER BY rand()", 1);
	$dest_sector = $findem->fields['sector_id'];

	$debug_query = $db->SelectLimit("SELECT zone_id FROM {$db_prefix}universe WHERE sector_id=$source_sector", 1);
	db_op_result($debug_query,__LINE__,__FILE__);
	$zones = $debug_query->fields;

	$debug_query = $db->Execute("UPDATE {$db_prefix}players SET turns=turns-1,turns_used=turns_used+1,rating=rating+$rating_change WHERE player_id=$playerinfo[player_id]");
	db_op_result($debug_query,__LINE__,__FILE__);

	playerlog($targetinfo['player_id'], "LOG5_ATTACK_EWD", "$playerinfo[character_name]");

	$debug_query = $db->Execute ("UPDATE {$db_prefix}ships SET sector_id=$dest_sector, cleared_defenses=' ', on_planet='N' WHERE ship_id=$ship_id");
	db_op_result($debug_query,__LINE__,__FILE__);
	$debug_query = $db->Execute("UPDATE {$db_prefix}ship_devices SET amount=amount-1 WHERE device_id=" . $targetshipdevice['dev_emerwarp']['device_id']);
	db_op_result($debug_query,__LINE__,__FILE__);

	log_move($targetinfo['player_id'],$targetship['ship_id'],$source_sector,$dest_sector,$shipinfo['class'],$shipinfo['cloak'],$zones['zone_id']);
	$template_object->assign("error_msg", $l_att_ewd);
	$template_object->assign("gotomain", $l_global_mmenu);
	$template_object->display($templatename."attackdie.tpl");
	include ("footer.php");
	die();
}


echo "<H1>$title</H1>\n";

echo "<center><br><b><font size=3 color=#00ff00>$l_att_att</font> <font size=3 color=#00ffff>$targetinfo[character_name]</font> <font size=3 color=#00ff00>$l_abord</font> <font size=3 color=#ffffff>$targetship[name]</font></b><BR><BR>";

send_system_im($targetinfo['player_id'], $l_att_imtitle, $playerinfo['character_name'] . " $l_att_imbody", $targetinfo['last_login']);

$isfedbounty = ship_bounty_check($playerinfo, $shipinfo['sector_id'], $targetinfo, 1);

if($isfedbounty > 0)
{
	echo $l_by_fedbounty2 . "<BR><BR>";
}

if ($targetshipdevice['dev_emerwarp']['amount'] > 0)
{
	playerlog($targetinfo['player_id'], "LOG5_ATTACK_EWDFAIL", $playerinfo['character_name']);
}


// get attacker beam, shield and armor values
$attacker_shield_energy = floor($shipinfo['energy'] * 0.4);
$attacker_beam_energy = $shipinfo['energy'] - $attacker_shield_energy;

$attackershields = NUM_SHIELDS($shipinfo['shields']);

if ($attackershields < $attacker_shield_energy)
{
	$attacker_shield_energy = $attackershields;
}

$attackerbeams = NUM_BEAMS($shipinfo['beams']);

if ($attackerbeams < $attacker_beam_energy)
{
	$attacker_beam_energy = $attackerbeams;
}

$attackerenergyset = $attacker_beam_energy + $attacker_shield_energy;

$attack_beamtofighter_dmg = floor($attacker_beam_energy * 0.05);
$attack_beamtotorp_dmg = floor($attacker_beam_energy * 0.025);

// get target beam, shield and armor values
$target_shield_energy = floor($targetship['energy'] * 0.4);
$target_beam_energy = $targetship['energy'] - $target_shield_energy;

$targetshields = NUM_SHIELDS($targetship['shields']);

if ($targetshields < $target_shield_energy)
{
	$target_shield_energy = $targetshields;
}

$targetbeams = NUM_BEAMS($targetship['beams']);

if ($targetbeams < $target_beam_energy)
{
	$target_beam_energy = $targetbeams;
}

$targetenergyset = $target_shield_energy + $target_beam_energy;

$target_beamtofighter_dmg = floor($target_beam_energy * 0.05);
$target_beamtotorp_dmg = floor($target_beam_energy * 0.025);

// next
$attackertorps = $shipinfo['torps'];

$attackerarmor = $shipinfo['armor_pts'];

$attackerfighters = $shipinfo['fighters'];

$targettorps = $targetship['torps'];

$targetarmor = $targetship['armor_pts'];

$targetfighters = $targetship['fighters'];

$attackerlowpercent = ecmcheck($targetship['ecm'], $shipinfo['sensors'], $full_attack_modifier);
$targetlowpercent = ecmcheck($shipinfo['ecm'], $targetship['sensors'], -$full_attack_modifier);

$targetshipshields = $targetship['shields'];
$targetshiparmor = $targetship['armor'];
$targetshiptorp_launchers = $targetship['torp_launchers'];
$targetshipbeams = $targetship['beams'];
$targetshipfighter = $targetship['fighter'];
$targetname = $targetinfo['character_name'];

if(!class_exists($shipinfo['fighter_class'])){
	include ("class/" . $shipinfo['fighter_class'] . ".inc");
}

$attackobject = new $shipinfo['fighter_class']();
$fighter_damage_shields = $attackobject->fighter_damage_shields;
$fighter_damage_all = $attackobject->fighter_damage_all;
$fighter_hit_pts = $attackobject->fighter_hit_pts;

if(!class_exists($shipinfo['beam_class'])){
	include ("class/" . $shipinfo['beam_class'] . ".inc");
}

$attackobject = new $shipinfo['beam_class']();
$beam_damage_shields = $attackobject->beam_damage_shields;
$beam_damage_all = $attackobject->beam_damage_all;

if(!class_exists($shipinfo['torp_class'])){
	include ("class/" . $shipinfo['torp_class'] . ".inc");
}

$attackobject = new $shipinfo['torp_class']();
$torp_damage_shields = $attackobject->torp_damage_shields;
$torp_damage_all = $attackobject->torp_damage_all;
$torp_hit_pts = $attackobject->torp_hit_pts;

if(!class_exists($shipinfo['shield_class'])){
	include ("class/" . $shipinfo['shield_class'] . ".inc");
}

$attackobject = new $shipinfo['shield_class']();
$ship_shield_hit_pts = $attackobject->ship_shield_hit_pts;

if(!class_exists($shipinfo['armor_class'])){
	include ("class/" . $shipinfo['armor_class'] . ".inc");
}

$attackobject = new $shipinfo['armor_class']();
$ship_armor_hit_pts = $attackobject->hit_pts;

if(!class_exists($targetship['fighter_class'])){
	include ("class/" . $targetship['fighter_class'] . ".inc");
}

$targetobject = new $targetship['fighter_class']();
$fighter_damage_shields = $targetobject->fighter_damage_shields;
$fighter_damage_all = $targetobject->fighter_damage_all;
$fighter_hit_pts = $targetobject->fighter_hit_pts;

if(!class_exists($targetship['beam_class'])){
	include ("class/" . $targetship['beam_class'] . ".inc");
}

$targetobject = new $targetship['beam_class']();
$beam_damage_shields = $targetobject->beam_damage_shields;
$beam_damage_all = $targetobject->beam_damage_all;

if(!class_exists($targetship['torp_class'])){
	include ("class/" . $targetship['torp_class'] . ".inc");
}

$targetobject = new $targetship['torp_class']();
$torp_damage_shields = $targetobject->torp_damage_shields;
$torp_damage_all = $targetobject->torp_damage_all;
$torp_hit_pts = $targetobject->torp_hit_pts;

if(!class_exists($targetship['shield_class'])){
	include ("class/" . $targetship['shield_class'] . ".inc");
}

$targetobject = new $targetship['shield_class']();
$ship_shield_hit_pts = $targetobject->ship_shield_hit_pts;

if(!class_exists($targetship['armor_class'])){
	include ("class/" . $targetship['armor_class'] . ".inc");
}

$targetobject = new $targetship['armor_class']();
$ship_armor_hit_pts = $targetobject->ship_armor_hit_pts;

update_player_experience($playerinfo['player_id'], $attacking_ship);
include ("combat.php");

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
			<td width='12%'><FONT COLOR='RED'><B>&nbsp;".NUMBER($attack_energy_left)."&nbsp;</B></FONT></td>
			<td width='17%'><FONT COLOR='RED'><B>&nbsp;".NUMBER($attacker_fighters_left2)."&nbsp;</B></FONT></td>
			<td width='18%'><FONT COLOR='RED'><B>&nbsp;".NUMBER($attacker_shields_left)."&nbsp;</B></FONT></td>
			<td width='11%'><FONT COLOR='RED'><B>&nbsp;".NUMBER($attacker_torps_left)."&nbsp;</B></FONT></td>
			<td width='11%'><FONT COLOR='RED'><B>&nbsp;".NUMBER($attacker_armor_left)."&nbsp;</B></FONT></td>
			</tr>";

echo "			<tr><td colspan=6 align=center>&nbsp;</td></tr>
			</table>
			</CENTER>
	";

$armor_lost=$shipinfo['armor_pts']-$attacker_armor_left;
$fighters_lost=$shipinfo['fighters']-$attacker_fighters_left2;
$torps_lost=$shipinfo['torps']-$attacker_torps_left;
$energy_lost=$attackerenergyset - ($attacker_energy_left + $attacker_shields_left);

$debug_query = $db->Execute("UPDATE {$db_prefix}ships SET armor_pts=GREATEST(armor_pts - $armor_lost, 0), energy=GREATEST(energy - $energy_lost, 0), fighters=GREATEST(fighters - $fighters_lost, 0), torps=GREATEST(torps - $torps_lost, 0) WHERE ship_id=$shipinfo[ship_id]");
db_op_result($debug_query,__LINE__,__FILE__);

$armor_lost=$targetship['armor_pts']-$target_armor_left;
$fighters_lost=$targetship['fighters']-$target_fighters_left2;
$torps_lost=$targetship['torps']-$target_torps_left;
$energy_lost=$targetenergyset - ($target_energy_left + $target_shields_left);

$debug_query = $db->Execute("UPDATE {$db_prefix}ships SET armor_pts=GREATEST(armor_pts - $armor_lost, 0), energy=GREATEST(energy - $energy_lost, 0), fighters=GREATEST(fighters - $fighters_lost, 0), torps=GREATEST(torps - $torps_lost, 0) WHERE ship_id=$targetship[ship_id]");
db_op_result($debug_query,__LINE__,__FILE__);

if(($attacker_armor_left < 1 and $attacker_shields_left < 1) and ($target_armor_left < 1 and $target_shields_left < 1)){

	update_player_experience($playerinfo['player_id'], $destroying_enemyship + $losing_yourship);
	update_player_experience($targetinfo['player_id'], $destroying_enemyship + $losing_yourship);
	//	target_died();
	echo "<BR><font color=#00ffff>$targetinfo[character_name]</font><font color=#00ff00>". $l_att_sdest ."</font><BR>";
	if ($targetshipdevice['dev_escapepod']['amount'] == 1)
	{
		echo "<font color=#ffff00>$l_att_espod</font><BR><BR>";

		player_ship_destroyed($targetship['ship_id'], $targetinfo['player_id'], $targetinfo['rating'], $playerinfo['player_id'], $playerinfo['rating'], "killedshippod");

		playerlog($targetinfo['player_id'], "LOG5_ATTACK_LOSE", "$playerinfo[character_name]|Y");

		collect_bounty($playerinfo['player_id'],$targetinfo['player_id']);
	}
	else
	{
		playerlog($targetinfo['player_id'], "LOG5_ATTACK_LOSE", "$playerinfo[character_name]|N");
		db_kill_player($targetinfo['player_id'], $playerinfo['player_id'], $playerinfo['rating'], "killedship");
		collect_bounty($playerinfo['player_id'],$targetinfo['player_id']);
	}

	//	attacker_died();
	echo "<font color=#ff0000><b>$l_att_yshiplost</b></font><BR><BR>";
	if ($shipdevice['dev_escapepod']['amount'] == 1)
	{
		echo "<b><font color=#ffff00>$l_att_loosepod</font></b><BR><BR>";

		player_ship_destroyed($shipinfo['ship_id'], $playerinfo['player_id'], $playerinfo['rating'], $targetinfo['player_id'], $targetinfo['rating'], "killedshippod");

		collect_bounty($targetinfo['player_id'],$playerinfo['player_id']);
	}
	else
	{
		db_kill_player($playerinfo['player_id'], $targetinfo['player_id'], $targetinfo['rating'], "killedship");
		collect_bounty($targetinfo['player_id'],$playerinfo['player_id']);
	}

echo $l_global_mmenu;

	include ("footer.php");
	die();
}

if(($attacker_armor_left < 1 and $attacker_shields_left < 1) or ($target_armor_left < 1 and $target_shields_left < 1)){

	if ($target_armor_left < 1 and $target_shields_left < 1)
	{
		//	target_died();
		update_player_experience($playerinfo['player_id'], $destroying_enemyship);
		update_player_experience($targetinfo['player_id'], $losing_yourship);
		echo "<BR><font color=#00ffff>$targetinfo[character_name]</font><font color=#00ff00>". $l_att_sdest ."</font><BR>";
		if ($targetshipdevice['dev_escapepod']['amount'] == 1)
		{
			echo "<font color=#ffff00>$l_att_espod</font><BR><BR>";

			player_ship_destroyed($targetship['ship_id'], $targetinfo['player_id'], $targetinfo['rating'], $playerinfo['player_id'], $playerinfo['rating'], "killedshippod");

			playerlog($targetinfo['player_id'], "LOG5_ATTACK_LOSE", "$playerinfo[character_name]|" . $targetshipdevice['dev_escapepod']['amount']);

			collect_bounty($playerinfo['player_id'],$targetinfo['player_id']);
		}
		else
		{
			playerlog($targetinfo['player_id'], "LOG5_ATTACK_LOSE", "$playerinfo[character_name]|" . $targetshipdevice['dev_escapepod']['amount']);
			db_kill_player($targetinfo['player_id'], $playerinfo['player_id'], $playerinfo['rating'], "killedship");
			collect_bounty($playerinfo['player_id'],$targetinfo['player_id']);
		}

		$rating_change=get_rating_change($playerinfo['rating'], $targetinfo['rating'], $rating_attack_ship);

		adminlog("LOG0_ADMIN_COMBAT", "<font color=yellow><B>Salvage Ship Values:</B></font><BR> " . print_r($targetship, true) . "<br>");
		$ship_value=$upgrade_cost*(round(mypw($upgrade_factor, $targetship['hull']))+round(mypw($upgrade_factor, $targetship['engines']))+round(mypw($upgrade_factor, $targetship['power']))+round(mypw($upgrade_factor, $targetship['fighter']))+round(mypw($upgrade_factor, $targetship['sensors']))+round(mypw($upgrade_factor, $targetship['beams']))+round(mypw($upgrade_factor, $targetship['torp_launchers']))+round(mypw($upgrade_factor, $targetship['shields']))+round(mypw($upgrade_factor, $targetship['armor']))+round(mypw($upgrade_factor, $targetship['cloak']))+round(mypw($upgrade_factor, $targetship['ecm'])));
		$ship_salvage_rate = mt_rand(10,20);
		$ship_salvage=$ship_value * ($ship_salvage_rate/100);
		$debug_query = $db->Execute ("UPDATE {$db_prefix}players SET credits=credits+$ship_salvage, rating=rating+$rating_change WHERE player_id=$playerinfo[player_id]");
		db_op_result($debug_query,__LINE__,__FILE__);

		$l_att_ysalv=str_replace("[ship_salvage_rate]","<font color=#ffffff>". $ship_salvage_rate . "</font>",$l_att_ysalv);
		$l_att_ysalv=str_replace("[ship_salvage]","<font color=#ffffff>". NUMBER($ship_salvage) . "</font>",$l_att_ysalv);
		$l_att_ysalv=str_replace("[rating_change]","<font color=#ffffff>". NUMBER(abs($rating_change)) . "</font>",$l_att_ysalv);

		echo "<font color=#00ff00>$l_att_ysalv</font>";
		adminlog("LOG0_ADMIN_COMBAT", "<font color=yellow><B>Salvage Values:</B></font><BR> Ship Value: $ship_value - $l_att_ysalv : upgrade_cost = $upgrade_cost, upgrade_factor = $upgrade_factor<br>");

		$armor_lost=$targetship['armor_pts']-$target_armor_left;
		$fighters_lost=$targetship['fighters']-$target_fighters_left2;
		$torps_lost=$targetship['torps']-$target_torps_left;
		$energy_lost=$targetenergyset - ($attacker_energy_left + $attacker_shields_left);

		echo "<font color=#00ff00>$targetinfo[character_name] $l_att_lost <font color=#ffffff>". NUMBER($armor_lost) . "</font> $l_armorpts, <font color=#ffffff>" . NUMBER($fighters_lost) . "</font> $l_fighters, $l_att_andused <font color=#ffffff>". NUMBER($energy_lost) . "</font> $l_energy, <font color=#ffffff>" . NUMBER($torps_lost) . "</font> $l_torps.</font><BR><BR>";
	}
	else
	{
		$l_att_stilship=str_replace("[name]",$targetinfo['character_name'],$l_att_stilship);
		echo "<b><font color=#ff0000>$l_att_stilship</font></b><BR>";

		if($target_armor_left > 0)
			calc_internal_damage($targetship['ship_id'], 0, ($targetship['armor_pts']-$target_armor_left) / $targetship['armor_pts']);
		$armor_lost=$targetship['armor_pts']-$target_armor_left;
		$fighters_lost=$targetship['fighters']-$target_fighters_left2;
		$torps_lost=$targetship['torps']-$target_torps_left;
		$energy_lost=$targetenergyset - ($attacker_energy_left + $attacker_shields_left);

		playerlog($targetinfo['player_id'], "LOG5_ATTACKED_WIN", "$playerinfo[character_name]|$armor_lost|$fighters_lost");
		echo "<font color=#00ff00>$targetinfo[character_name] $l_att_lost <font color=#ffffff>". NUMBER($armor_lost) . "</font> $l_armorpts, <font color=#ffffff>" . NUMBER($fighters_lost) . "</font> $l_fighters, $l_att_andused <font color=#ffffff>". NUMBER($energy_lost) . "</font> $l_energy, <font color=#ffffff>" . NUMBER($torps_lost) . "</font> $l_torps.</font><BR><BR>";
	}

	if ($attacker_armor_left < 1 and $attacker_shields_left < 1)
	{
		//	attacker_died();
		update_player_experience($targetinfo['player_id'], $destroying_enemyship);
		update_player_experience($playerinfo['player_id'], $losing_yourship);
		echo "<font color=#ff0000><b>$l_att_yshiplost</b></font><BR><BR>";
		if ($shipdevice['dev_escapepod']['amount'] == 1)
		{
			echo "<b><font color=#ffff00>$l_att_loosepod</font></b><BR><BR>";

			player_ship_destroyed($shipinfo['ship_id'], $playerinfo['player_id'], $playerinfo['rating'], $targetinfo['player_id'], $targetinfo['rating'], "killedshippod");

			collect_bounty($targetinfo['player_id'],$playerinfo['player_id']);
		}
		else
		{
			db_kill_player($playerinfo['player_id'], $targetinfo['player_id'], $targetinfo['rating'], "killedship");
			collect_bounty($targetinfo['player_id'],$playerinfo['player_id']);
		}

		adminlog("LOG0_ADMIN_COMBAT", "<font color=yellow><B>Salvage Ship Values:</B></font><BR> " . print_r($shipinfo, true) . "<br>");
		$ship_value=$upgrade_cost*(round(mypw($upgrade_factor, $shipinfo['hull']))+round(mypw($upgrade_factor, $shipinfo['engines']))+round(mypw($upgrade_factor, $shipinfo['power']))+round(mypw($upgrade_factor, $shipinfo['fighter']))+round(mypw($upgrade_factor, $shipinfo['sensors']))+round(mypw($upgrade_factor, $shipinfo['beams']))+round(mypw($upgrade_factor, $shipinfo['torp_launchers']))+round(mypw($upgrade_factor, $shipinfo['shields']))+round(mypw($upgrade_factor, $shipinfo['armor']))+round(mypw($upgrade_factor, $shipinfo['cloak']))+round(mypw($upgrade_factor, $shipinfo['ecm'])));
		$ship_salvage_rate = mt_rand(10,20);
		$ship_salvage=$ship_value * ($ship_salvage_rate/100);

		$debug_query = $db->Execute ("UPDATE {$db_prefix}players SET credits=credits+$ship_salvage WHERE player_id=$targetinfo[player_id]");
		db_op_result($debug_query,__LINE__,__FILE__);

		$l_att_salv=str_replace("[ship_salvage_rate]","<font color=#ffffff>". $ship_salvage_rate . "</font>",$l_att_salv);
		$l_att_salv=str_replace("[ship_salvage]","<font color=#ffffff>". NUMBER($ship_salvage) . "</font>",$l_att_salv);
		$l_att_salv=str_replace("[name]","<font color=#00ffff>". $targetinfo['character_name'] . "</font>",$l_att_salv);

		echo "<font color=#00ff00>$l_att_salv</font><BR></CENTER>";
		adminlog("LOG0_ADMIN_COMBAT", "<font color=yellow><B>Salvage Values:</B></font><BR> Ship Value: $ship_value - $l_att_salv : upgrade_cost = $upgrade_cost, upgrade_factor = $upgrade_factor<br>");

		$armor_lost=$shipinfo['armor_pts']-$attacker_armor_left;
		$fighters_lost=$shipinfo['fighters']-$attacker_fighters_left2;
		$torps_lost=$shipinfo['torps']-$attacker_torps_left;
		$energy_lost=$attackerenergyset - ($attacker_energy_left + $attacker_shields_left);

		echo "<center><font color=#00ff00>$l_att_ylost <font color=#ffffff>". NUMBER($armor_lost) . "</font> $l_armorpts, <font color=#ffffff>" . NUMBER($fighters_lost) . "</font> $l_fighters, $l_att_andused <font color=#ffffff>". NUMBER($energy_lost) . "</font> $l_energy, <font color=#ffffff>" . NUMBER($torps_lost) . "</font> $l_torps.</font><BR><BR></CENTER>";
	}
	else
	{
		if($attacker_armor_left > 0)
			calc_internal_damage($shipinfo['ship_id'], 0, ($shipinfo['armor_pts']-$attacker_armor_left) / $shipinfo['armor_pts']);
		$armor_lost=$shipinfo['armor_pts']-$attacker_armor_left;
		$fighters_lost=$shipinfo['fighters']-$attacker_fighters_left2;
		$torps_lost=$shipinfo['torps']-$attacker_torps_left;
		$energy_lost=$attackerenergyset - ($attacker_energy_left + $attacker_shields_left);

		$rating_change=get_rating_change($playerinfo['rating'], $targetinfo['rating'], $rating_attack_ship);
		$debug_query = $db->Execute ("UPDATE {$db_prefix}players SET turns=turns-1, turns_used=turns_used+1, rating=rating+$rating_change WHERE player_id=$playerinfo[player_id]");
		db_op_result($debug_query,__LINE__,__FILE__);

		echo "<center><font color=#00ff00>$l_att_ylost <font color=#ffffff>". NUMBER($armor_lost) . "</font> $l_armorpts, <font color=#ffffff>" . NUMBER($fighters_lost) . "</font> $l_fighters, $l_att_andused <font color=#ffffff>". NUMBER($energy_lost) . "</font> $l_energy, <font color=#ffffff>" . NUMBER($torps_lost) . "</font> $l_torps.</font><BR><BR></CENTER>";
	}
echo $l_global_mmenu;

	include ("footer.php");
	die();
}


// both players bounced

$l_att_stilship=str_replace("[name]",$targetinfo['character_name'],$l_att_stilship);
echo "<b><font color=#ff0000>$l_att_stilship</font></b><BR><br>";

if($target_armor_left > 0)
	calc_internal_damage($targetship['ship_id'], 0, ($targetship['armor_pts']-$target_armor_left) / $targetship['armor_pts']);
$armor_lost=$targetship['armor_pts']-$target_armor_left;
$fighters_lost=$targetship['fighters']-$target_fighters_left2;
$torps_lost=$targetship['torps']-$target_torps_left;
$energy_lost=$targetenergyset - ($attacker_energy_left + $attacker_shields_left);

playerlog($targetinfo['player_id'], "LOG5_ATTACKED_WIN", "$playerinfo[character_name]|$armor_lost|$fighters_lost");
echo "<font color=#00ff00>$targetinfo[character_name] $l_att_lost <font color=#ffffff>". NUMBER($armor_lost) . "</font> $l_armorpts, <font color=#ffffff>" . NUMBER($fighters_lost) . "</font> $l_fighters, $l_att_andused <font color=#ffffff>". NUMBER($energy_lost) . "</font> $l_energy, <font color=#ffffff>" . NUMBER($torps_lost) . "</font> $l_torps.</font><BR><BR>";

if($attacker_armor_left > 0)
	calc_internal_damage($shipinfo['ship_id'], 0, ($shipinfo['armor_pts']-$attacker_armor_left) / $shipinfo['armor_pts']);
$armor_lost=$shipinfo['armor_pts']-$attacker_armor_left;
$fighters_lost=$shipinfo['fighters']-$attacker_fighters_left2;
$torps_lost=$shipinfo['torps']-$attacker_torps_left;
$energy_lost=$attackerenergyset - ($attacker_energy_left + $attacker_shields_left);

$rating_change=get_rating_change($playerinfo['rating'], $targetinfo['rating'], $rating_attack_ship);
$debug_query = $db->Execute ("UPDATE {$db_prefix}players SET turns=turns-1, turns_used=turns_used+1, rating=rating+$rating_change WHERE player_id=$playerinfo[player_id]");
db_op_result($debug_query,__LINE__,__FILE__);

echo "<font color=#00ff00>$l_att_ylost <font color=#ffffff>". NUMBER($armor_lost) . "</font> $l_armorpts, <font color=#ffffff>" . NUMBER($fighters_lost) . "</font> $l_fighters, $l_att_andused <font color=#ffffff>". NUMBER($energy_lost) . "</font> $l_energy, <font color=#ffffff>" . NUMBER($torps_lost) . "</font> $l_torps.</font><BR><BR></CENTER>";

echo "<br><br>";

echo $l_global_mmenu;

include ("footer.php");

?>
