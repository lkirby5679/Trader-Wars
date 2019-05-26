<?php
include ("languages/$langdir/lang_attack.inc");

include ("globals/combat_functions.inc");
include ("globals/planet_bounty_check.inc");
include ("globals/collect_bounty.inc");
include ("globals/db_kill_player.inc");
include ("globals/player_ship_destroyed.inc");
include ("globals/send_system_im.inc");
include ("globals/set_max_credits.inc");
include ("globals/log_move.inc");
include ("globals/calc_ownership.inc");
include ("globals/gen_score.inc");
include ("globals/insert_news.inc");
include ("globals/sector_defense_battle.inc");
include ("globals/get_rating_change.inc");
include ("globals/artifacts_move.inc");

// check sector defense
if($playerinfo['team'] == 0)
{
	$result3 = $db->Execute ("SELECT defense_type, SUM(quantity) as amount FROM {$db_prefix}sector_defense WHERE sector_id='$shipinfo[sector_id]' and player_id != '$playerinfo[player_id]' GROUP BY defense_type");
}
else
{
	$result3 = $db->Execute ("SELECT {$db_prefix}sector_defense.defense_type, SUM({$db_prefix}sector_defense.quantity) as amount FROM {$db_prefix}sector_defense, {$db_prefix}players WHERE {$db_prefix}sector_defense.sector_id='$shipinfo[sector_id]' and {$db_prefix}sector_defense.player_id != '$playerinfo[player_id]' and ({$db_prefix}players.player_id={$db_prefix}sector_defense.player_id and {$db_prefix}players.team != $playerinfo[team]) GROUP BY {$db_prefix}sector_defense.defense_type");
}
db_op_result($result3,__LINE__,__FILE__);

if ($result3 > 0)
{
	while (!$result3->EOF)
	{
		$row = $result3->fields;
		$defenses[$row['defense_type']] = $row['amount'];

		$result3->MoveNext();
	}
}
$result3->close();

$is_header = 0;

if ($defenses['fighters'] > 0 && $playerinfo['player_id'] != 3)
{
	unset($_SESSION['movedefense'], $movedefense);
	$template_object->enable_gzip = 0;
	$destination=$shipinfo['sector_id'];
	include ("sector_defense/fighters.inc");
	echo $l_global_mmenu;
	include ("footer.php");
	die();
}

		if($shipinfo['class'] >= $dev_nova_shiplimit){
			if($shipdevice['dev_nova']['amount'] != "0"){
				if($planetinfo['owner'] != 3){
					if($playerinfo['turns'] > $dev_nova_turnsused){
						if($targetinfo['player_id'] <= 3){
							$rating_nova_planet = 0;
						}
						$rating_change=get_rating_change($playerinfo['rating'], $ownerinfo['rating'], $rating_nova_planet, $ownerinfo['player_id']);
						$debug_query = $db->Execute("UPDATE {$db_prefix}players SET rating=rating+$rating_change, turns_used=turns_used+$dev_nova_turnsused, turns=turns-$dev_nova_turnsused WHERE player_id=$playerinfo[player_id]");
						db_op_result($debug_query,__LINE__,__FILE__);

						$debug_query = $db->Execute("UPDATE {$db_prefix}ship_devices SET amount=0 WHERE device_id=" . $shipdevice['dev_nova']['device_id']);
						db_op_result($debug_query,__LINE__,__FILE__);
						$novarand = rand(1, 100);

						if(rand(1, 100) > $dev_nova_explode){

							$isfedbounty = planet_bounty_check($playerinfo, $shipinfo['sector_id'], $ownerinfo, 1);

							if($isfedbounty > 0)
							{
								echo $l_by_fedbounty2 . "<BR><BR>";
							}
// end<br>
							$res = $db->SelectLimit("SELECT last_login FROM {$db_prefix}players WHERE player_id = $planetinfo[owner]", 1);
							$last_login = $res->fields['last_login'];
							$res->close();
							send_system_im($planetinfo['owner'], $l_planet_imtitleattack, $playerinfo['character_name'] . " $l_planet_imnova $planetinfo[name] $l_planet_iminsector $planetinfo[sector_name].", $last_login);

							if(rand(1, 100) <= ($dev_nova_percent + $shipdevice['dev_nova']['amount'])){
								 if($enable_spies)
								 {
									$res = $db->Execute("SELECT {$db_prefix}spies.*, {$db_prefix}planets.name, {$db_prefix}planets.sector_id FROM {$db_prefix}spies INNER JOIN {$db_prefix}planets ON {$db_prefix}spies.planet_id = {$db_prefix}planets.planet_id WHERE {$db_prefix}spies.planet_id = '$planet_id' ");
									while (!$res->EOF)
									{
										$owners = $res->fields;
										playerlog($owners[owner_id], "LOG2_SPY_CATACLYSM", "$owners[spy_id]|$owners[name]|$owners[sector_id]");
										$res->MoveNext();
									}
									$res->close();
									$db->Execute("DELETE FROM {$db_prefix}spies WHERE planet_id = '$planet_id' ");
								}

								$debug_query = $db->Execute("DELETE from {$db_prefix}planets where planet_id=$planet_id");
								db_op_result($debug_query,__LINE__,__FILE__);

								$averagetechlvl = floor((($planetinfo['fighter'] + $planetinfo['sensors'] + $planetinfo['beams'] + $planetinfo['torp_launchers'] + $planetinfo['shields'] + $planetinfo['jammer'] + $planetinfo['cloak']) / 7) / 600 * 100);
								if($targetinfo['player_id'] <= 3){
									$rating_nova_destroy_planet = 0;
								}
								$rating_change=get_rating_change($playerinfo['rating'], $ownerinfo['rating'], $rating_nova_destroy_planet * $averagetechlvl, $ownerinfo['player_id']);
								$debug_query = $db->Execute("UPDATE {$db_prefix}players SET rating=rating+$rating_change, planets_destroyed=planets_destroyed+1 WHERE player_id=$playerinfo[player_id]");
								db_op_result($debug_query,__LINE__,__FILE__);
// check for ships and destroy them
								$result4 = $db->Execute("SELECT * FROM {$db_prefix}ships WHERE planet_id=$planet_id AND on_planet='Y'");
								$shipsonplanet = $result4->RecordCount();

								if ($shipsonplanet > 0)
								{
									$l_cmb_shipdock2 = str_replace("[cmb_shipsonplanet]", $shipsonplanet, $l_cmb_shipdock2);
									echo "<BR><BR><CENTER>$l_cmb_shipdock2</CENTER><BR><BR>\n";
									while (!$result4->EOF)
									{
										$onplanet = $result4->fields;

										$ship_id = stripnum($onplanet['ship_id']);

										$result2 = $db->Execute ("SELECT * FROM {$db_prefix}players WHERE currentship=$onplanet[ship_id]");
										$targetinfo = $result2->fields;
										$result2->close();

										$result = $db->Execute ("SELECT * FROM {$db_prefix}ships WHERE ship_id='$ship_id'");
										$targetship = $result->fields;
										$result->close();

										$targetshipdevice = $db->GetToFieldArray("SELECT * FROM {$db_prefix}ship_devices WHERE ship_id=$ship_id", '', 'class');

										/* determine percent chance of success in detecting target ship - based on player's sensors and opponent's cloak */
										$targetcloak = floor($targetship['cloak'] * 0.75);

										$success = SCAN_SUCCESS($shipinfo['sensors'], $targetcloak, $shiptypes[$targetship['class']]['basehull']);

										$targetengines = floor($targetship['engines'] * 0.50);

										$flee = SCAN_SUCCESS($shipinfo['engines'], $targetengines, $shiptypes[$targetship['class']]['basehull']);
										$roll = mt_rand(1, 100);
										$roll2 = mt_rand(1, 100);

										if ($flee < $roll2)
										{
											echo "$l_att_flee<BR><BR>";
											$debug_query = $db->Execute("UPDATE {$db_prefix}players SET turns=turns-1,turns_used=turns_used+1 WHERE player_id=$playerinfo[player_id]");
											db_op_result($debug_query,__LINE__,__FILE__);
											playerlog($targetinfo['player_id'], "LOG5_ATTACK_OUTMAN", "$playerinfo[character_name]");
											$debug_query = $db->Execute ("UPDATE {$db_prefix}ships SET on_planet='N' WHERE ship_id=$ship_id");
											db_op_result($debug_query,__LINE__,__FILE__);
										}else if ($roll > $success)
										{
											/* if scan fails - inform both player and target. */
											echo "$l_planet_noscan<BR><BR>";
											$debug_query = $db->Execute("UPDATE {$db_prefix}players SET turns=turns-1,turns_used=turns_used+1 WHERE player_id=$playerinfo[player_id]");
											db_op_result($debug_query,__LINE__,__FILE__);
											playerlog($targetinfo['player_id'], "LOG5_ATTACK_OUTSCAN", "$playerinfo[character_name]");
											$debug_query = $db->Execute ("UPDATE {$db_prefix}ships SET on_planet='N' WHERE ship_id=$ship_id");
											db_op_result($debug_query,__LINE__,__FILE__);
										}
										else
										{
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
												/* need to change warp destination to random sector in universe */
												if($targetinfo['player_id'] <= 3){
													$rating_attack_ship = 0;
												}
												$rating_change=get_rating_change($playerinfo['rating'], $targetinfo['rating'], $rating_attack_ship, $targetinfo['player_id']);
												$source_sector = $shipinfo['sector_id'];
												$findem = $db->SelectLimit("SELECT sector_id FROM {$db_prefix}universe where sg_sector = 0 and sector_id > 3 ORDER BY rand()", 1);
												$dest_sector = $findem->fields['sector_id'];

												$debug_query = $db->SelectLimit("SELECT zone_id FROM {$db_prefix}universe WHERE sector_id=$source_sector", 1);
												db_op_result($debug_query,__LINE__,__FILE__);
												$zones = $debug_query->fields;
												$debug_query->close();

												$debug_query = $db->Execute("UPDATE {$db_prefix}players SET turns=turns-1,turns_used=turns_used+1,rating=rating+$rating_change WHERE player_id=$playerinfo[player_id]");
												db_op_result($debug_query,__LINE__,__FILE__);

												playerlog($targetinfo['player_id'], "LOG5_ATTACK_EWD", "$playerinfo[character_name]");

												$debug_query = $db->Execute ("UPDATE {$db_prefix}ships SET sector_id=$dest_sector, cleared_defenses=' ', on_planet='N' WHERE ship_id=$ship_id");
												db_op_result($debug_query,__LINE__,__FILE__);
												$debug_query = $db->Execute("UPDATE {$db_prefix}ship_devices SET amount=amount-1 WHERE device_id=" . $targetshipdevice['dev_emerwarp']['device_id']);
												db_op_result($debug_query,__LINE__,__FILE__);

												log_move($targetinfo['player_id'],$targetship['ship_id'],$source_sector,$dest_sector,$shipinfo['class'],$shipinfo['cloak'],$zones['zone_id']);
												echo "$l_att_ewd<BR><BR>";
											}
											else
											{
												echo "<BR>$targetinfo[character_name]". $l_att_sdest ."<BR>";
												if ($targetshipdevice['dev_escapepod']['amount'] == 1)
												{
													echo "$l_att_espod<BR><BR>";

													player_ship_destroyed($ship_id, $targetinfo['player_id'], $targetinfo['rating'], $playerinfo['player_id'], $playerinfo['rating'], "killednovapod");

													playerlog($targetinfo['player_id'], "LOG5_ATTACK_LOSE", "$playerinfo[character_name]|Y");

													collect_bounty($playerinfo['player_id'],$targetinfo['player_id']);
												}
												else
												{
													playerlog($targetinfo['player_id'], "LOG5_ATTACK_LOSE", "$playerinfo[character_name]|N");
													db_kill_player($targetinfo['player_id'], $playerinfo['player_id'], $playerinfo['rating'], "killednova");
													collect_bounty($playerinfo['player_id'],$targetinfo['player_id']);
												}
											}
										}
										$result4->MoveNext();
									}
									$debug_query = $db->Execute("SELECT * FROM {$db_prefix}ships WHERE storage_planet_id = $planet_id");
									db_op_result($debug_query,__LINE__,__FILE__);
									if ($debug_query > 0)
									{
										while (!$debug_query->EOF)
										{
											$ship_id = $debug_query->fields['ship_id'];
											$delete_query = $db->Execute("DELETE FROM {$db_prefix}ships WHERE ship_id = $ship_id");
											db_op_result($delete_query,__LINE__,__FILE__);
											$delete_query = $db->Execute("DELETE FROM {$db_prefix}ship_devices WHERE ship_id = $ship_id");
											db_op_result($delete_query,__LINE__,__FILE__);
											$delete_query = $db->Execute("DELETE FROM {$db_prefix}ship_holds WHERE ship_id = $ship_id");
											db_op_result($delete_query,__LINE__,__FILE__);
											$debug_query->MoveNext();
										}
									}
									$debug_query->close();
// end
								}
								$result4->close();
								calc_ownership($shipinfo[sector_id]);
								playerlog($ownerinfo['player_id'], "LOG4_PLANET_novaED_D", "$planetinfo[name]|$shipinfo[sector_id]|$playerinfo[character_name]");
								gen_score($ownerinfo['player_id']);

								$playernames = $playerinfo['character_name'];
								insert_news($playernames, 1, "nova");
								artifacts_move($planet_id, 0, 0);
								close_database();
								echo "<META HTTP-EQUIV=\"Refresh\" CONTENT=\"0;URL=main.php\">";
							}else{
								$planetinfo['sector_defense_weapons'] = floor($planetinfo['sector_defense_weapons'] * (rand(($dev_nova_damage - $shipdevice['dev_nova']['amount']), 100) * 0.01));
								$planetinfo['sector_defense_sensors'] = floor($planetinfo['sector_defense_sensors'] * (rand(($dev_nova_damage - $shipdevice['dev_nova']['amount']), 100) * 0.01));
								$planetinfo['sector_defense_cloak'] = floor($planetinfo['sector_defense_cloak'] * (rand(($dev_nova_damage - $shipdevice['dev_nova']['amount']), 100) * 0.01));
								$planetinfo['fighter'] = floor($planetinfo['fighter'] * (rand(($dev_nova_damage - $shipdevice['dev_nova']['amount']), 100) * 0.01));
								$planetinfo['sensors'] = floor($planetinfo['sensors'] * (rand(($dev_nova_damage - $shipdevice['dev_nova']['amount']), 100) * 0.01));
								$planetinfo['beams'] = floor($planetinfo['beams'] * (rand(($dev_nova_damage - $shipdevice['dev_nova']['amount']), 100) * 0.01));
								$planetinfo['torp_launchers'] = floor($planetinfo['torp_launchers'] * (rand(($dev_nova_damage - $shipdevice['dev_nova']['amount']), 100) * 0.01));
								$planetinfo['shields'] = floor($planetinfo['shields'] * (rand(($dev_nova_damage - $shipdevice['dev_nova']['amount']), 100) * 0.01));
								$planetinfo['jammer'] = floor($planetinfo['jammer'] * (rand(($dev_nova_damage - $shipdevice['dev_nova']['amount']), 100) * 0.01));
								$planetinfo['cloak'] = floor($planetinfo['cloak'] * (rand(($dev_nova_damage - $shipdevice['dev_nova']['amount']), 100) * 0.01));
								$planetinfo['torps'] = floor($planetinfo['torps'] * (rand(($dev_nova_damage - $shipdevice['dev_nova']['amount']), 100) * 0.01));
								$planetinfo['fighters'] = floor($planetinfo['fighters'] * (rand(($dev_nova_damage - $shipdevice['dev_nova']['amount']), 100) * 0.01));
								$planetinfo['colonists'] = floor($planetinfo['colonists'] * (rand(($dev_nova_damage - $shipdevice['dev_nova']['amount']), 100) * 0.01));
								$planetinfo['credits'] = floor($planetinfo['credits'] * (rand(($dev_nova_damage - $shipdevice['dev_nova']['amount']), 100) * 0.01));
								$planetinfo['energy'] = floor($planetinfo['energy'] * (rand(($dev_nova_damage - $shipdevice['dev_nova']['amount']), 100) * 0.01));

								$debug_query = $db->Execute("UPDATE {$db_prefix}planets SET torps=$planetinfo[torps], fighters=$planetinfo[fighters], colonists=$planetinfo[colonists], credits=$planetinfo[credits], energy=$planetinfo[energy], fighter=$planetinfo[fighter], sensors=$planetinfo[sensors], beams=$planetinfo[beams], torp_launchers=$planetinfo[torp_launchers], shields=$planetinfo[shields], jammer=$planetinfo[jammer], cloak=$planetinfo[cloak] WHERE planet_id=$planet_id");
								db_op_result($debug_query,__LINE__,__FILE__);

								set_max_credits($planet_id);

								echo "$l_planet_novamiss<BR>";
								$playernames = $playerinfo['character_name'];
								insert_news($playernames, 1, "novamiss");

								if(rand(1, 100) <= $dev_nova_explode){
									$averagetechlvl = ($shipinfo['hull'] + $shipinfo['engines'] + $shipinfo['power'] + $shipinfo['fighter'] + $shipinfo['sensors'] + $shipinfo['beams'] + $shipinfo['torp_launchers'] + $shipinfo['shields'] + $shipinfo['cloak'] + $shipinfo['armor'] + $shipinfo['ecm']) / 11;
									if($averagetechlvl > $dev_nova_destroylevel){
										$shipinfo['hull'] = floor($shipinfo['hull'] * (rand(50, 75) * 0.01));
										$shipinfo['engines'] = floor($shipinfo['engines'] * (rand(50, 75) * 0.01));
										$shipinfo['power'] = floor($shipinfo['power'] * (rand(50, 75) * 0.01));
										$shipinfo['fighter'] = floor($shipinfo['fighter'] * (rand(50, 75) * 0.01));
										$shipinfo['sensors'] = floor($shipinfo['sensors'] * (rand(50, 75) * 0.01));
										$shipinfo['beams'] = floor($shipinfo['beams'] * (rand(50, 75) * 0.01));
										$shipinfo['torp_launchers'] = floor($shipinfo['torp_launchers'] * (rand(50, 75) * 0.01));
										$shipinfo['shields'] = floor($shipinfo['shields'] * (rand(50, 75) * 0.01));
										$shipinfo['cloak'] = floor($shipinfo['cloak'] * (rand(50, 75) * 0.01));
										$shipinfo['armor'] = floor($shipinfo['armor'] * (rand(50, 75) * 0.01));
										$shipinfo['armor_pts'] = floor($shipinfo['armor_pts'] * (rand(50, 75) * 0.01));
										$shipinfo['torps'] = floor($shipinfo['torps'] * (rand(50, 75) * 0.01));
										$shipinfo['fighters'] = floor($shipinfo['fighters'] * (rand(50, 75) * 0.01));
										$shipinfo['credits'] = floor($shipinfo['credits'] * (rand(50, 75) * 0.01));
										$shipinfo['energy'] = floor($shipinfo['energy'] * (rand(50, 75) * 0.01));
										$shipinfo['ecm'] = floor($shipinfo['ecm'] * (rand(50, 75) * 0.01));

										echo "<font color='#ff0000' size='4'><B>$l_planet_novaexplode</B></font>";

										$debug_query = $db->Execute("UPDATE {$db_prefix}ships SET engines=$shipinfo[engines], power=$shipinfo[power], armor=$shipinfo[armor], armor_pts=$shipinfo[armor_pts], torps=$shipinfo[torps], fighters=$shipinfo[fighters], hull=$shipinfo[hull], energy=$shipinfo[energy], fighter=$shipinfo[fighter], sensors=$shipinfo[sensors], beams=$shipinfo[beams], torp_launchers=$shipinfo[torp_launchers], shields=$shipinfo[shields], cloak=$shipinfo[cloak], ecm=$shipinfo[ecm] WHERE ship_id=$shipinfo[ship_id]");
										db_op_result($debug_query,__LINE__,__FILE__);
									}else{
										if ($shipdevice['dev_escapepod']['amount'] == 1) 
										{
											echo "$l_cmb_escapepodlaunched<BR><BR>";
//											echo "<BR><BR>player_id=$onplanet[player_id]<BR><BR>";
											player_ship_destroyed($shipinfo['ship_id'], $playerinfo['player_id'], $playerinfo['rating'], 0, 0, "killednovabackfirepod");

											playerlog($shipinfo['player_id'],"LOG4_SHIP_novaED_D", "$playerinfo[character_name]|Y");

											$playernames = $playerinfo['character_name']."|".$playerinfo['character_name'];
											insert_news($playernames, 1, "targetepod");
										}else{
											playerlog($playerinfo['player_id'], "LOG4_SHIP_novaED_D", "$playerinfo[character_name]|N");
											db_kill_player($playerinfo['player_id'], 0, 0, "killednovabackfire");
											$playernames = $playerinfo['character_name']."|".$playerinfo['character_name'];
											insert_news($playernames, 1, "targetdies");
										}
										echo "<font color='#ff0000' size='4'><B>$l_planet_novaexplode2</B></font>";
									}
								}

								$max_sector_defense_fighters = 0;
								$max_defense = $db->Execute("SELECT sector_defense_weapons from {$db_prefix}planets where owner = 2 and sector_id = $planetinfo[sector_id] and base = 'Y'");
								db_op_result($max_defense,__LINE__,__FILE__);
								if ($max_defense > 0)
								{
									while (!$max_defense->EOF)
									{
										$max_sector_defense_fighters += NUM_PER_LEVEL($max_defense->fields['sector_defense_weapons']) * $sector_fighter_multiplier;
										$max_defense->MoveNext();
									}
								}
								$max_defense->close();

								// move fighters and toprs from planet to sector defense
								$res = $db->SelectLimit("SELECT * from {$db_prefix}sector_defense where defense_type = 'fighters' and player_id=$planetinfo[owner] and sector_id=$shipinfo[sector_id]", 1);
								$row = $res->fields;
								$res->close();
								$energy_required = ROUND($row['quantity'] * $energy_per_fighter);
								$res4 = $db->Execute("SELECT IFNULL(SUM(energy),0) as energy_available from {$db_prefix}planets where owner = $planetinfo[owner] and sector_id = $shipinfo[sector_id]"); 
								$energy_available = $res4->fields['energy_available'];
								$res4->close();
								$availiblefighters = max(0, (NUM_FIGHTERS($planetinfo['sector_defense_weapons']) - $row['quantity']));
								$maxfighters = min(min(floor(($energy_available - $energy_required) / $energy_per_fighter), $availiblefighters), $max_sector_defense_fighters);
								if($planetinfo['fighters'] < $maxfighters)
								{
									$maxfighters = $planetinfo['fighters'];
								}
								$addfighters = floor($maxfighters * (rand(10, 30) * 0.01));

								$res = $db->SelectLimit("SELECT * from {$db_prefix}sector_defense where defense_type = 'mines' and player_id=$planetinfo[owner] and sector_id=$shipinfo[sector_id]", 1);
								$row = $res->fields;
								$res->close();
								$maxmines = max(0, (NUM_TORPEDOES($planetinfo['sector_defense_weapons']) - $row['quantity']));
								if($planetinfo['torps'] < $maxmines)
								{
									$maxmines = $planetinfo['torps'];
								}
								$addmines = floor($maxmines * (rand(10, 20) * 0.01));

// Start of quick hack until sector_defense_battle() function finished
// Whomever had the most fighters wins.  And the winner has a ratio of what attacked them removed from both fighters and mines.
// The loser has everything wiped.

								$resultSDb = $db->Execute("SELECT SUM({$db_prefix}sector_defense.quantity) as total from {$db_prefix}sector_defense, {$db_prefix}players WHERE 
								{$db_prefix}sector_defense.sector_id=$shipinfo[sector_id] and {$db_prefix}sector_defense.player_id != '$playerinfo[player_id]'
								and (({$db_prefix}players.player_id = {$db_prefix}sector_defense.player_id) and ({$db_prefix}players.team != $playerinfo[team] or $playerinfo[team] = 0)) and {$db_prefix}sector_defense.defense_type = 'fighters'");
								db_op_result($resultSDb,__LINE__,__FILE__);

								if($resultSDb->recordcount() > 0)
								{
									$total_fighters += $resultSDb->fields['quantity'];
									if($total_fighters > $addfighters)
									{
										$ratio_left = 1 - ($addfighters / $total_fighters);
										$addfighters = 0;
										$addmines = 0;
										$resultSDb = $db->Execute("UPDATE {$db_prefix}sector_defense, {$db_prefix}players SET {$db_prefix}sector_defense.quantity = {$db_prefix}sector_defense.quantity * $ratio_left WHERE 
										{$db_prefix}sector_defense.sector_id=$shipinfo[sector_id] and {$db_prefix}sector_defense.player_id != '$playerinfo[player_id]'
										and (({$db_prefix}players.player_id = {$db_prefix}sector_defense.player_id) and ({$db_prefix}players.team != $playerinfo[team] or $playerinfo[team] = 0))");
										db_op_result($resultSDb,__LINE__,__FILE__);
									}
									else
									{
										$resultSDb = $db->Execute("SELECT {$db_prefix}sector_defense.defense_id from {$db_prefix}sector_defense, {$db_prefix}players WHERE 
										{$db_prefix}sector_defense.sector_id=$shipinfo[sector_id] and {$db_prefix}sector_defense.player_id != '$playerinfo[player_id]'
										and (({$db_prefix}players.player_id = {$db_prefix}sector_defense.player_id) and ({$db_prefix}players.team != $playerinfo[team] or $playerinfo[team] = 0))");
										db_op_result($resultSDb,__LINE__,__FILE__);
										while (!$resultSDb->EOF)
										{
											$defense_id = $resultSDb->fields['defense_id'];
											$res2 = $db->Execute("DELETE FROM {$db_prefix}sector_defense WHERE defense_id = $defense_id");
											$resultSDb->MoveNext();
										}
										$ratio_left = 1 - ($total_fighters / $addfighters);
										$addfighters *= $ratio_left;
										$addmines *= $ratio_left;
									}
								}

								if ($addfighters > 0)
								{
									if ($fighter_id != 0)
									{
										$fighter_query = $db->Execute("UPDATE {$db_prefix}sector_defense set quantity=quantity + $addfighters " .
																	"where defense_id = $fighter_id");
										db_op_result($fighter_query,__LINE__,__FILE__);
									}
									else
									{
										$fighter_query = $db->Execute("INSERT INTO {$db_prefix}sector_defense " .
																	"(player_id,sector_id,defense_type,quantity, weapon_class) values " .
																	"($planetinfo[owner], $shipinfo[sector_id], 'fighters',$addfighters, 'Sector_Fighter')");
										db_op_result($fighter_query,__LINE__,__FILE__);
									}
								}

								if ($addmines > 0)
								{
									$res = $db->Execute("SELECT * from {$db_prefix}sector_defense where defense_type = 'mines' and player_id=$planetinfo[owner] and sector_id=$shipinfo[sector_id]");
									$row = $res->fields;
									$res->close();
									if ($row['defense_id'] != 0)
									{
										$mines_query = $db->Execute("UPDATE {$db_prefix}sector_defense set quantity=quantity + $addmines " .
																	"where defense_id = $row[defense_id]");
										db_op_result($mines_query,__LINE__,__FILE__);
									}
									else
									{
										$mines_query = $db->Execute("INSERT INTO {$db_prefix}sector_defense " .
																	"(player_id,sector_id,defense_type,quantity, weapon_class) values " .
																	"($planetinfo[owner], $shipinfo[sector_id], 'mines',$addmines, 'Sector_Mine')");
										db_op_result($mines_query,__LINE__,__FILE__);
									}
								}
// End of quick hack until sector_defense_battle() function finished

//								sector_defense_battle($fighter_id, $addfighters, $addmines);
							}
						}else{
							$averagetechlvl = ($shipinfo['hull'] + $shipinfo['engines'] + $shipinfo['power'] + $shipinfo['fighter'] + $shipinfo['sensors'] + $shipinfo['beams'] + $shipinfo['torp_launchers'] + $shipinfo['shields'] + $shipinfo['cloak'] + $shipinfo['armor'] + $shipinfo['ecm']) / 11;
							if($averagetechlvl > $dev_nova_destroylevel){
								$shipinfo['hull'] = floor($shipinfo['hull'] * (rand(50, 75) * 0.01));
								$shipinfo['engines'] = floor($shipinfo['engines'] * (rand(50, 75) * 0.01));
								$shipinfo['power'] = floor($shipinfo['power'] * (rand(50, 75) * 0.01));
								$shipinfo['fighter'] = floor($shipinfo['fighter'] * (rand(50, 75) * 0.01));
								$shipinfo['sensors'] = floor($shipinfo['sensors'] * (rand(50, 75) * 0.01));
								$shipinfo['beams'] = floor($shipinfo['beams'] * (rand(50, 75) * 0.01));
								$shipinfo['torp_launchers'] = floor($shipinfo['torp_launchers'] * (rand(50, 75) * 0.01));
								$shipinfo['shields'] = floor($shipinfo['shields'] * (rand(50, 75) * 0.01));
								$shipinfo['cloak'] = floor($shipinfo['cloak'] * (rand(50, 75) * 0.01));
								$shipinfo['armor'] = floor($shipinfo['armor'] * (rand(50, 75) * 0.01));
								$shipinfo['armor_pts'] = floor($shipinfo['armor_pts'] * (rand(50, 75) * 0.01));
								$shipinfo['torps'] = floor($shipinfo['torps'] * (rand(50, 75) * 0.01));
								$shipinfo['fighters'] = floor($shipinfo['fighters'] * (rand(50, 75) * 0.01));
								$shipinfo['credits'] = floor($shipinfo['credits'] * (rand(50, 75) * 0.01));
								$shipinfo['energy'] = floor($shipinfo['energy'] * (rand(50, 75) * 0.01));
								$shipinfo['ecm'] = floor($shipinfo['ecm'] * (rand(50, 75) * 0.01));

								echo "<font color='#ff0000' size='4'><B>$l_planet_novaexplode</B></font>";

								$debug_query = $db->Execute("UPDATE {$db_prefix}ships SET engines=$shipinfo[engines], power=$shipinfo[power], armor=$shipinfo[armor], armor_pts=$shipinfo[armor_pts], torps=$shipinfo[torps], fighters=$shipinfo[fighters], hull=$shipinfo[hull], energy=$shipinfo[energy], fighter=$shipinfo[fighter], sensors=$shipinfo[sensors], beams=$shipinfo[beams], torp_launchers=$shipinfo[torp_launchers], shields=$shipinfo[shields], cloak=$shipinfo[cloak], ecm=$shipinfo[ecm] WHERE ship_id=$shipinfo[ship_id]");
								db_op_result($debug_query,__LINE__,__FILE__);
							}else{
								if ($shipdevice['dev_escapepod']['amount'] == 1) 
								{
									echo "$l_cmb_escapepodlaunched<BR><BR>";
//									echo "<BR><BR>player_id=$onplanet[player_id]<BR><BR>";
									player_ship_destroyed($shipinfo['ship_id'], $playerinfo['player_id'], $playerinfo['rating'], 0, 0, "killednovabackfirepod");

									playerlog($shipinfo['player_id'],"LOG4_SHIP_novaED_D", "$playerinfo[character_name]|Y");

									$playernames = $playerinfo['character_name']."|".$playerinfo['character_name'];
									insert_news($playernames, 1, "targetepod");
								}else{
									playerlog($playerinfo['player_id'], "LOG4_SHIP_novaED_D", "$playerinfo[character_name]|N");
									db_kill_player($playerinfo['player_id'], 0, 0, "killednovabackfire");
									$playernames = $playerinfo['character_name']."|".$playerinfo['character_name'];
									insert_news($playernames, 1, "targetdies");
								}
								echo "<font color='#ff0000' size='4'><B>$l_planet_novaexplode2</B></font>";
							}
						}
					}else{
						echo str_replace("[turns]", $dev_nova_turnsused, $l_planet_novaturns) . "<BR>";
					}
				}else{
					echo "$l_planet_novafed<BR>";
				}
			}else{
					echo "$l_planet_nonova<BR>";
			}
		}else{
				echo "$l_planet_wrongclass<BR>";
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

?>