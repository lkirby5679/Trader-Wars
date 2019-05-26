<?php
include ("globals/isLoanPending.inc");

	$title=$l_upgrade_port_title;

	if($zoneinfo['zone_id'] != 3){
		$res2 = $db->Execute("SELECT SUM(amount) as total_bounty FROM {$db_prefix}bounty WHERE (placed_by = 3 or placed_by = 1) AND bounty_on = $playerinfo[player_id]");
		if ($res2)
		{
			$bty = $res2->fields;
			if ($bty['total_bounty'] > 0)
			{
				if ($pay < 1)
				{
					echo $l_port_bounty;
					$l_port_bounty2 = str_replace("[amount]",NUMBER($bty['total_bounty']),$l_port_bounty2);
					echo $l_port_bounty2 . "<BR>";
					echo "<A HREF=\"bounty.php\">$l_by_placebounty</A><BR><BR>";
					echo $l_global_mmenu;
					include ("footer.php");
					die();
				}
				elseif($pay==2){
				// Make bounty payments
					$getbountyid = $db->Execute("SELECT * FROM {$db_prefix}bounty WHERE (placed_by = 3 or placed_by = 1)  and bounty_on=$playerinfo[player_id] order by bounty_id ");
					db_op_result($getbountyid,__LINE__,__FILE__);
						$pmt_amt=StripNonNum($pmt_amt);
						  if (($pmt_amt=="") or ($pmt_amt <= 0))
 								$pmt_amt=0;		
						if ($pmt_amt > $playerinfo['credits']){	
							$pmt_amt=$playerinfo['credits'];
							}
						$temptotal=$pmt_amt;
						if ($getbountyid->RecordCount() > 0)
						{
							while (!$getbountyid->EOF)
							{
								$bounty = $getbountyid->fields;
								if ($bounty['amount']<= $temptotal){
								$bountyupdate = $db->Execute("delete from  {$db_prefix}bounty  where bounty_id=$bounty[bounty_id]");
								db_op_result($bountyupdate,__LINE__,__FILE__);
								$temptotal=$temptotal-$bounty['amount'];
								}else{
								
								$bountyupdate = $db->Execute("update {$db_prefix}bounty set amount=amount-$temptotal where bounty_id=$bounty[bounty_id]");
								$temptotal=0;
								db_op_result($bountyupdate,__LINE__,__FILE__);
								}
							
							$getbountyid->MoveNext();	
							}
						}
						$getbountyid->close();
						$debug_query = $db->Execute("UPDATE {$db_prefix}players SET credits=credits-$pmt_amt WHERE player_id = $playerinfo[player_id]");
						db_op_result($debug_query,__LINE__,__FILE__);

						$template_object->assign("error_msg", $l_port_bountypaid);
						$template_object->assign("error_msg2", "");
						$template_object->assign("gotomain", $l_global_mmenu);
						$template_object->display($templatename."genericdie.tpl");
						include ("footer.php");
						die();
				}
				else
				{
					if ($playerinfo['credits'] < $bty['total_bounty'])
					{
						$l_port_btynotenough = str_replace("[amount]",NUMBER($bty['total_bounty']),$l_port_btynotenough);
						$l_creds_to_spend=str_replace("[credits]",NUMBER($playerinfo['credits']),$l_creds_to_spend);
						$template_object->assign("notenough", $l_port_btynotenough);
						$template_object->assign("l_pay_partial", $l_pay_partial);
						$template_object->assign("l_creds_to_spend", $l_creds_to_spend);
						$template_object->assign("l_pay_button", $l_pay_button);
						$template_object->assign("gotomain", $l_global_mmenu);
						$template_object->display($templatename."bountypay.tpl");
						include ("footer.php");
						die();
					}
					else
					{
						$debug_query = $db->Execute("UPDATE {$db_prefix}players SET credits=credits-$bty[total_bounty] WHERE player_id = $playerinfo[player_id]");
						db_op_result($debug_query,__LINE__,__FILE__);

						$debug_query = $db->Execute("DELETE from {$db_prefix}bounty WHERE bounty_on = $playerinfo[player_id] AND (placed_by = 3 or placed_by = 1)");
						db_op_result($debug_query,__LINE__,__FILE__);

						$template_object->assign("error_msg", $l_port_bountypaid);
						$template_object->assign("error_msg2", "");
						$template_object->assign("gotomain", $l_global_mmenu);
						$template_object->display($templatename."genericdie.tpl");
						include ("footer.php");
						die();
					}
				}
			}
		}
		$res2->close();
		$alliancefactor = 1;
	}
	else
	{
		$res2 = $db->Execute("SELECT COUNT(*) as number_of_bounties FROM {$db_prefix}bounty WHERE (placed_by = 3 or placed_by = 1) AND bounty_on = $playerinfo[player_id]");
		if ($res2)
		{
			$alliancefactor = $alliancefactor * max($res2->fields['number_of_bounties'], 1);
		}
		$res2->close();
	}

	if (isLoanPending($playerinfo['player_id']))
	{
		$template_object->assign("error_msg", $l_port_loannotrade);
		$template_object->assign("error_msg2", "<A HREF=igb.php>$l_igb_term</a>");
		$template_object->assign("gotomain", $l_global_mmenu);
		$template_object->display($templatename."genericdie.tpl");
		include ("footer.php");
		die();
	}
	$fighter_max = NUM_FIGHTERS($shipinfo['fighter']);
	$fighter_free = $fighter_max - $shipinfo['fighters'];
	$torpedo_max = NUM_TORPEDOES($shipinfo['torp_launchers']);
	$torpedo_free = $torpedo_max - $shipinfo['torps'];
	$armor_max = NUM_armor($shipinfo['armor']);
	$armor_free = $armor_max - $shipinfo['armor_pts'];
$template_object->assign("fighter_max", $fighter_max);
$template_object->assign("fighter_free", $fighter_free);
$template_object->assign("number_fighter_free", NUMBER($fighter_free));
$template_object->assign("torpedo_max", $torpedo_max);
$template_object->assign("torpedo_free", $torpedo_free);
$template_object->assign("number_torpedo_free", NUMBER($torpedo_free));
$template_object->assign("armor_max", $armor_max);
$template_object->assign("armor_free", $armor_free);
$template_object->assign("number_armor_free", NUMBER($armor_free));

$template_object->assign("title", $title);
$fighter_form = "";
	if(!class_exists($shipinfo['fighter_class'])){
		include ("class/" . $shipinfo['fighter_class'] . ".inc");
	}

	$fighterobject = new $shipinfo['fighter_class']();
	$fighter_price_modifier = $fighterobject->price_modifier;
	$fighter_price = $fighterobject->fighter_price;
	if ($shipinfo['fighters'] != $fighter_max)
	{
	$fighter_form = "+ form.fighter_number.value * $fighter_price * $alliancefactor * $fighter_price_modifier ";
	}
$template_object->assign("fighter_form", $fighter_form);
$torpedo_form = "";
	if(!class_exists($shipinfo['torp_class'])){
		include ("class/" . $shipinfo['torp_class'] . ".inc");
	}

	$torpobject = new $shipinfo['torp_class']();
	$torp_price_modifier = $torpobject->price_modifier;
	$torpedo_price = $torpobject->torpedo_price;

	if ($shipinfo['torps'] != $torpedo_max)
	{
	$torpedo_form = "+ form.torpedo_number.value * $torpedo_price * $alliancefactor * $torp_price_modifier ";
	}
$template_object->assign("torpedo_form", $torpedo_form);
$armor_form = "";
	if(!class_exists($shipinfo['armor_class'])){
		include ("class/" . $shipinfo['armor_class'] . ".inc");
	}

	$armorobject = new $shipinfo['armor_class']();
	$armor_price_modifier = $armorobject->price_modifier;
	$armor_price = $armorobject->armor_price;
	if ($shipinfo['armor_pts'] != $armor_max)
	{
	$armor_form = "+ form.armor_number.value * $armor_price * $alliancefactor * $armor_price_modifier ";
	}
$template_object->assign("armor_form", $armor_form);

// Create dropdowns when called
function dropdown($element_name,$current_value, $max_value)
{
	$i = $current_value;
	$dropdownvar = "<select size='1' name='$element_name'";
	$dropdownvar = "$dropdownvar ONCHANGE=\"countTotal()\">\n";
	while ($i <= $max_value)
	{
		if ($current_value == $i)
		{
			$dropdownvar = "$dropdownvar		<option value='$i' selected>$i</option>\n";
		}
		else
		{
			$dropdownvar = "$dropdownvar		<option value='$i'>$i</option>\n";
		}
	 $i++;
	}
	$dropdownvar = "$dropdownvar		 </select>\n";
	return $dropdownvar;
}

$l_creds_to_spend=str_replace("[credits]",NUMBER($playerinfo['credits']),$l_creds_to_spend);
$template_object->assign("l_creds_to_spend", $l_creds_to_spend);

if ($allow_ibank)
{
	$igblink = "\n<A HREF=igb.php>$l_igb_term</a>";
	$l_ifyouneedmore=str_replace("[igb]",$igblink,$l_ifyouneedmore);
	$template_object->assign("l_ifyouneedmore", $l_ifyouneedmore);
}
else
{
	$template_object->assign("l_ifyouneedmore", "");
}

$template_object->assign("l_by_placebounty", $l_by_placebounty);
$template_object->assign("l_ship_levels", $l_ship_levels);
$template_object->assign("l_cost", $l_cost);
$template_object->assign("l_current_level", $l_current_level);
$template_object->assign("l_upgrade", $l_upgrade);
$template_object->assign("l_hull", $l_hull);
$template_object->assign("ship_hull", NUMBER($shipinfo['hull']));

if($shipinfo['hull'] == $shipinfo['hull_normal']){
	$ship_hull_dropdown = dropdown("hull_upgrade",$shipinfo['hull'], $classinfo['maxhull']);
}
else
{
	$ship_hull_dropdown = $l_ports_needrepair . "<input type=\"hidden\" name=\"hull_upgrade\" value=\"" . $shipinfo['hull'] . "\">";
}

$template_object->assign("ship_hull_dropdown", $ship_hull_dropdown);

$template_object->assign("l_engines", $l_engines);
$template_object->assign("ship_engines", NUMBER($shipinfo['engines']));

if($shipinfo['engines'] == $shipinfo['engines_normal']){
	$ship_engines_dropdown = dropdown("engine_upgrade",$shipinfo['engines'], $classinfo['maxengines']);
}
else
{
	$ship_engines_dropdown = $l_ports_needrepair . "<input type=\"hidden\" name=\"engine_upgrade\" value=\"" . $shipinfo['engines'] . "\">";
}
$template_object->assign("ship_engines_dropdown", $ship_engines_dropdown);

$template_object->assign("l_power", $l_power);
$template_object->assign("ship_power", NUMBER($shipinfo['power']));

if($shipinfo['power'] == $shipinfo['power_normal']){
	$ship_power_dropdown = dropdown("power_upgrade",$shipinfo['power'], $classinfo['maxpower']);
}
else
{
	$ship_power_dropdown = $l_ports_needrepair . "<input type=\"hidden\" name=\"power_upgrade\" value=\"" . $shipinfo['power'] . "\">";
}
$template_object->assign("ship_power_dropdown", $ship_power_dropdown);

$template_object->assign("l_fighter", $l_fighter);
$template_object->assign("ship_fighter", NUMBER($shipinfo['fighter']));

if($shipinfo['fighter'] == $shipinfo['fighter_normal']){
	$ship_fighter_dropdown = dropdown("fighter_upgrade",$shipinfo['fighter'], $classinfo['maxfighter']);
}
else
{
	$ship_fighter_dropdown = $l_ports_needrepair . "<input type=\"hidden\" name=\"fighter_upgrade\" value=\"" . $shipinfo['fighter'] . "\">";
}
$template_object->assign("ship_fighter_dropdown", $ship_fighter_dropdown);

$template_object->assign("l_sensors", $l_sensors);
$template_object->assign("ship_sensors", NUMBER($shipinfo['sensors']));

if($shipinfo['sensors'] == $shipinfo['sensors_normal']){
	$ship_sensors_dropdown = dropdown("sensors_upgrade",$shipinfo['sensors'], $classinfo['maxsensors']);
}
else
{
	$ship_sensors_dropdown =  $l_ports_needrepair . "<input type=\"hidden\" name=\"sensors_upgrade\" value=\"" . $shipinfo['sensors'] . "\">";
}
$template_object->assign("ship_sensors_dropdown", $ship_sensors_dropdown);

$template_object->assign("l_beams", $l_beams);
$template_object->assign("ship_beams", NUMBER($shipinfo['beams']));

if($shipinfo['beams'] == $shipinfo['beams_normal']){
	$ship_beams_dropdown = dropdown("beams_upgrade",$shipinfo['beams'], $classinfo['maxbeams']);
}
else
{
	$ship_beams_dropdown =  $l_ports_needrepair . "<input type=\"hidden\" name=\"beams_upgrade\" value=\"" . $shipinfo['beams'] . "\">";
}
$template_object->assign("ship_beams_dropdown", $ship_beams_dropdown);

$template_object->assign("l_armor", $l_armor);
$template_object->assign("ship_armor", NUMBER($shipinfo['armor']));

if($shipinfo['armor'] == $shipinfo['armor_normal']){
	$ship_armor_dropdown = dropdown("armor_upgrade",$shipinfo['armor'], $classinfo['maxarmor']);
}
else
{
	$ship_armor_dropdown = $l_ports_needrepair . "<input type=\"hidden\" name=\"armor_upgrade\" value=\"" . $shipinfo['armor'] . "\">";
}
$template_object->assign("ship_armor_dropdown", $ship_armor_dropdown);

$template_object->assign("l_cloak", $l_cloak);
$template_object->assign("ship_cloak", NUMBER($shipinfo['cloak']));

if($shipinfo['cloak'] == $shipinfo['cloak_normal']){
	$ship_cloak_dropdown = dropdown("cloak_upgrade",$shipinfo['cloak'], $classinfo['maxcloak']);
}
else
{
	$ship_cloak_dropdown = $l_ports_needrepair . "<input type=\"hidden\" name=\"cloak_upgrade\" value=\"" . $shipinfo['cloak'] . "\">";
}
$template_object->assign("ship_cloak_dropdown", $ship_cloak_dropdown);

$template_object->assign("l_ecm", $l_ecm);
$template_object->assign("ship_ecm", NUMBER($shipinfo['ecm']));

if($shipinfo['ecm'] == $shipinfo['ecm_normal']){
	$ship_ecm_dropdown = dropdown("ecm_upgrade",$shipinfo['ecm'], $classinfo['maxecm']);
}
else
{
	$ship_ecm_dropdown = $l_ports_needrepair . "<input type=\"hidden\" name=\"ecm_upgrade\" value=\"" . $shipinfo['ecm'] . "\">";
}
$template_object->assign("ship_ecm_dropdown", $ship_ecm_dropdown);

$template_object->assign("l_torp_launch", $l_torp_launch);
$template_object->assign("ship_torp_launchers", NUMBER($shipinfo['torp_launchers']));

if($shipinfo['torp_launchers'] == $shipinfo['torp_launchers_normal']){
	$ship_torp_launchers_dropdown = dropdown("torp_launchers_upgrade",$shipinfo['torp_launchers'], $classinfo['maxtorp_launchers']);
}
else
{
	$ship_torp_launchers_dropdown = $l_ports_needrepair . "<input type=\"hidden\" name=\"torp_launchers_upgrade\" value=\"" . $shipinfo['torp_launchers'] . "\">";
}
$template_object->assign("ship_torp_launchers_dropdown", $ship_torp_launchers_dropdown);

$template_object->assign("l_shields", $l_shields);
$template_object->assign("ship_shields", NUMBER($shipinfo['shields']));

if($shipinfo['shields'] == $shipinfo['shields_normal']){
	$ship_shields_dropdown = dropdown("shields_upgrade",$shipinfo['shields'], $classinfo['maxshields']);
}
else
{
	$ship_shields_dropdown = $l_ports_needrepair . "<input type=\"hidden\" name=\"shields_upgrade\" value=\"" . $shipinfo['shields'] . "\">";
}
$template_object->assign("ship_shields_dropdown", $ship_shields_dropdown);

$template_object->assign("l_item", $l_item);
$template_object->assign("l_cost", $l_cost);
$template_object->assign("l_current", $l_current);
$template_object->assign("l_max", $l_max);
$template_object->assign("l_qty", $l_qty);

$template_object->assign("l_fighters", $l_fighters);
$template_object->assign("fighter_cost", NUMBER($fighter_price * $alliancefactor));
$template_object->assign("fighter_current", NUMBER($shipinfo['fighters']) . " / " . NUMBER($fighter_max));
$template_object->assign("total_fighters", $shipinfo['fighters']);

$template_object->assign("l_torps", $l_torps);
$template_object->assign("torp_cost", NUMBER($torpedo_price * $alliancefactor));
$template_object->assign("torp_current", NUMBER($shipinfo['torps']) . " / " . NUMBER($torpedo_max));
$template_object->assign("total_torps", $shipinfo['torps']);

$template_object->assign("l_armorpts", $l_armorpts);
$template_object->assign("armor_cost", NUMBER($armor_price * $alliancefactor));
$template_object->assign("armor_current", NUMBER($shipinfo['armor_pts']) . " / " . NUMBER($armor_max));
$template_object->assign("total_armor", $shipinfo['armor_pts']);

$template_object->assign("l_buy", $l_buy);
$template_object->assign("l_totalcost", $l_totalcost);
$template_object->assign("l_would_dump", $l_would_dump);
$template_object->assign("l_here", $l_here);
$template_object->assign("l_full", $l_full);

$template_object->assign("player_credits", $playerinfo[credits]);
$template_object->assign("upgrade_cost", $upgrade_cost);
$template_object->assign("alliancefactor", $alliancefactor);
$template_object->assign("upgrade_factor", $upgrade_factor);
$template_object->assign("l_no_credits", $l_no_credits);

$template_object->assign("gotomain", $l_global_mmenu);
$template_object->display($templatename."port_upgrades.tpl");

include ("footer.php");

?>
