<?php
include ("globals/isLoanPending.inc");

get_post_ifset("fighter_number, torpedo_number, armor_number, total_cost, total_cost2, hull_upgrade, engine_upgrade, power_upgrade, fighter_upgrade, sensors_upgrade, beams_upgrade, armor_upgrade, cloak_upgrade, ecm_upgrade, torp_launchers_upgrade, shields_upgrade");

if ($playerinfo['turns'] < 1)
{
	echo "$l_trade_turnneed<BR><BR>";
}
else
{
	if ($sectorinfo['port_type'] == "upgrades")
	{
		if (isLoanPending($playerinfo['player_id']))
		{
			echo "$l_port_loannotrade<p>";
			echo "<A HREF=igb.php>$l_igb_term</a><p>";
			echo $l_global_mmenu;
			include ("footer.php");
			die();
		}

		$hull_upgrade_cost = 0;
		if($shipinfo['hull'] == $shipinfo['hull_normal']){
			if ($hull_upgrade > $classinfo['maxhull'])
				$hull_upgrade = $classinfo['maxhull'];

			if ($hull_upgrade < $classinfo['minhull'])
				$hull_upgrade = $classinfo['minhull'];

			if ($hull_upgrade > $shipinfo['hull_normal'])
			{
				$hull_upgrade_cost = phpChangeDelta($hull_upgrade, $shipinfo['hull_normal']);
			}
		}
		else
		{
			$hull_upgrade = $shipinfo['hull_normal'];
		}

		$engine_upgrade_cost = 0;
		if($shipinfo['engines'] == $shipinfo['engines_normal']){
			if ($engine_upgrade > $classinfo['maxengines'])
				$engine_upgrade = $classinfo['maxengines'];

			if ($engine_upgrade < $classinfo['minengines'])
				$engine_upgrade = $classinfo['minengines'];

			if ($engine_upgrade > $shipinfo['engines_normal'])
			{
				$engine_upgrade_cost = phpChangeDelta($engine_upgrade, $shipinfo['engines_normal']);
			}
		}
		else
		{
			$engine_upgrade = $shipinfo['engines_normal'];
		}

		$power_upgrade_cost = 0;
		if($shipinfo['power'] == $shipinfo['power_normal']){
			if ($power_upgrade > $classinfo['maxpower'])
				$power_upgrade = $classinfo['maxpower'];

			if ($power_upgrade < $classinfo['minpower'])
				$power_upgrade = $classinfo['minpower'];

			if ($power_upgrade > $shipinfo['power_normal'])
			{
				$power_upgrade_cost = phpChangeDelta($power_upgrade, $shipinfo['power_normal']);
			}
		}
		else
		{
			$power_upgrade = $shipinfo['power_normal'];
		}

		$fighter_upgrade_cost = 0;
		if($shipinfo['fighter'] == $shipinfo['fighter_normal']){
			if ($fighter_upgrade > $classinfo['maxfighter'])
				$fighter_upgrade = $classinfo['maxfighter'];

			if ($fighter_upgrade < $classinfo['minfighter'])
				$fighter_upgrade = $classinfo['minfighter'];

			if ($fighter_upgrade > $shipinfo['fighter_normal'])
			{
				$fighter_upgrade_cost = phpChangeDelta($fighter_upgrade, $shipinfo['fighter_normal']);
			}
		}
		else
		{
			$fighter_upgrade = $shipinfo['fighter_normal'];
		}

		$sensors_upgrade_cost = 0;
		if($shipinfo['sensors'] == $shipinfo['sensors_normal']){
			if ($sensors_upgrade > $classinfo['maxsensors'])
				$sensors_upgrade = $classinfo['maxsensors'];

			if ($sensors_upgrade < $classinfo['minsensors'])
				$sensors_upgrade = $classinfo['minsensors'];

			if ($sensors_upgrade > $shipinfo['sensors_normal'])
			{
				$sensors_upgrade_cost = phpChangeDelta($sensors_upgrade, $shipinfo['sensors_normal']);
			}
		}
		else
		{
			$sensors_upgrade = $shipinfo['sensors_normal'];
		}

		$beams_upgrade_cost = 0;
		if($shipinfo['beams'] == $shipinfo['beams_normal']){
			if ($beams_upgrade > $classinfo['maxbeams'])
				$beams_upgrade = $classinfo['maxbeams'];

			if ($beams_upgrade < $classinfo['minbeams'])
				$beams_upgrade = $classinfo['minbeams'];

			if ($beams_upgrade > $shipinfo['beams_normal'])
			{
				$beams_upgrade_cost = phpChangeDelta($beams_upgrade, $shipinfo['beams_normal']);
			}
		}
		else
		{
			$beams_upgrade = $shipinfo['beams_normal'];
		}

		$armor_upgrade_cost = 0;
		if($shipinfo['armor'] == $shipinfo['armor_normal']){
			if ($armor_upgrade > $classinfo['maxarmor'])
				$armor_upgrade = $classinfo['maxarmor'];

			if ($armor_upgrade < $classinfo['minarmor'])
				$armor_upgrade = $classinfo['minarmor'];

			if ($armor_upgrade > $shipinfo['armor_normal'])
			{
				$armor_upgrade_cost = phpChangeDelta($armor_upgrade, $shipinfo['armor_normal']);
			}
		}
		else
		{
			$armor_upgrade = $shipinfo['armor_normal'];
		}

		$cloak_upgrade_cost = 0;
		if($shipinfo['cloak'] == $shipinfo['cloak_normal']){
			if ($cloak_upgrade > $classinfo['maxcloak'])
				$cloak_upgrade = $classinfo['maxcloak'];

			if ($cloak_upgrade < $classinfo['mincloak'])
				$cloak_upgrade = $classinfo['mincloak'];

			if ($cloak_upgrade > $shipinfo['cloak_normal'])
			{
				$cloak_upgrade_cost = phpChangeDelta($cloak_upgrade, $shipinfo['cloak_normal']);
			}
		}
		else
		{
			$cloak_upgrade = $shipinfo['cloak_normal'];
		}

		$torp_launchers_upgrade_cost = 0;
		if($shipinfo['torp_launchers'] == $shipinfo['torp_launchers_normal']){
			if ($torp_launchers_upgrade > $classinfo['maxtorp_launchers'])
				$torp_launchers_upgrade = $classinfo['maxtorp_launchers'];

			if ($torp_launchers_upgrade < $classinfo['mintorp_launchers'])
				$torp_launchers_upgrade = $classinfo['mintorp_launchers'];

			if ($torp_launchers_upgrade > $shipinfo['torp_launchers_normal'])
			{
				$torp_launchers_upgrade_cost = phpChangeDelta($torp_launchers_upgrade, $shipinfo['torp_launchers_normal']);
			}
		}
		else
		{
			$torp_launchers_upgrade = $shipinfo['torp_launchers_normal'];
		}

		$shields_upgrade_cost = 0;
		if($shipinfo['shields'] == $shipinfo['shields_normal']){
			if ($shields_upgrade > $classinfo['maxshields'])
				$shields_upgrade = $classinfo['maxshields'];

			if ($shields_upgrade < $classinfo['minshields'])
				$shields_upgrade = $classinfo['minshields'];

			if ($shields_upgrade > $shipinfo['shields_normal'])
			{
				$shields_upgrade_cost = phpChangeDelta($shields_upgrade, $shipinfo['shields_normal']);
			}
		}
		else
		{
			$shields_upgrade = $shipinfo['shields_normal'];
		}

		$ecm_upgrade_cost = 0;
		if($shipinfo['ecm'] == $shipinfo['ecm_normal']){
			if ($ecm_upgrade > $classinfo['maxecm'])
				$ecm_upgrade = $classinfo['maxecm'];

			if ($ecm_upgrade < $classinfo['minecm'])
				$ecm_upgrade = $classinfo['minecm'];

			if ($ecm_upgrade > $shipinfo['ecm_normal'])
			{
				$ecm_upgrade_cost = phpChangeDelta($ecm_upgrade, $shipinfo['ecm_normal']);
			}
		}
		else
		{
			$ecm_upgrade = $shipinfo['ecm_normal'];
		}

		if ($fighter_number < 0)
			 $fighter_number = 0;
		$fighter_number	= round(abs($fighter_number));
		$fighter_max	 = NUM_FIGHTERS($shipinfo['fighter']) - $shipinfo['fighters'];
		if ($fighter_max < 0)
		{
			$fighter_max = 0;
		}
		if ($fighter_number > $fighter_max)
		{
			$fighter_number = $fighter_max;
		}

		if(!class_exists($shipinfo['fighter_class'])){
			include ("class/" . $shipinfo['fighter_class'] . ".inc");
		}

		$fighterobject = new $shipinfo['fighter_class']();
		$fighter_price_modifier = $fighterobject->price_modifier;
		$fighter_price = $fighterobject->fighter_price;
		$fighter_cost	= $fighter_number * $fighter_price * $fighter_price_modifier;
		if ($torpedo_number < 0)
			 $torpedo_number = 0;
		$torpedo_number	= round(abs($torpedo_number));
		$torpedo_max	 = NUM_TORPEDOES($shipinfo['torp_launchers']) - $shipinfo['torps'];
		if ($torpedo_max < 0)
		{
			$torpedo_max = 0;
		}
		if ($torpedo_number > $torpedo_max)
		{
			$torpedo_number = $torpedo_max;
		}

		if(!class_exists($shipinfo['torp_class'])){
			include ("class/" . $shipinfo['torp_class'] . ".inc");
		}

		$torpobject = new $shipinfo['torp_class']();
		$torp_price_modifier = $torpobject->price_modifier;
		$torpedo_price = $torpobject->torpedo_price;
		$torpedo_cost = $torpedo_number * $torpedo_price * $torp_price_modifier;
		if ($armor_number < 0)
			 $armor_number = 0;
		$armor_number = round(abs($armor_number));
		$armor_max = NUM_armor($shipinfo['armor']) - $shipinfo['armor_pts'];
		if ($armor_max < 0)
		{
			$armor_max = 0;
		}
		if ($armor_number > $armor_max)
		{
			$armor_number = $armor_max;
		}

		if(!class_exists($shipinfo['armor_class'])){
			include ("class/" . $shipinfo['armor_class'] . ".inc");
		}

		$armorobject = new $shipinfo['armor_class']();
		$armor_price_modifier = $armorobject->price_modifier;
		$armor_price = $armorobject->armor_price;
		$armor_cost	 = $armor_number * $armor_price * $armor_price_modifier;

		$total_cost = $hull_upgrade_cost + $engine_upgrade_cost + $power_upgrade_cost + $fighter_upgrade_cost + $ecm_upgrade_cost +
						$sensors_upgrade_cost + $beams_upgrade_cost + $armor_upgrade_cost + $cloak_upgrade_cost + $shields_upgrade_cost +
						$torp_launchers_upgrade_cost + $fighter_cost + $torpedo_cost + $armor_cost;

		$total_cost = round($total_cost * $alliancefactor);

		if ($total_cost > $playerinfo['credits'])
		{
			echo "$l_ports_needcredits " . NUMBER($total_cost) . " $l_ports_needcredits1 " . NUMBER($playerinfo['credits']) . " $l_credits.";
		}
		else
		{
			$trade_credits = NUMBER(abs($total_cost));
			echo "<TABLE BORDER=2 CELLSPACING=2 CELLPADDING=2 BGCOLOR=#400040 WIDTH=600 ALIGN=CENTER>
			 <TR>
				<TD colspan=99 align=center bgcolor=#300030><font size=3 color=white><b>$l_trade_result</b></font></TD>
			 </TR>
			 <TR>
				<TD colspan=99 align=center><b><font color=red>$l_cost : " . $trade_credits . " $l_credits</font></b></TD>
			 </TR>";

			 //	Total cost is " . NUMBER(abs($total_cost)) . " credits.<BR><BR>";
			$debug_query = $db->Execute("UPDATE {$db_prefix}players SET credits=credits-$total_cost,turns=turns-1, turns_used=turns_used+1 WHERE player_id=$playerinfo[player_id]");
			db_op_result($debug_query,__LINE__,__FILE__);

			$query = "UPDATE {$db_prefix}ships SET class=$shipinfo[class] ";

			if ($hull_upgrade > $shipinfo['hull_normal'])
			{
				$query = $query . ", hull=$hull_upgrade, hull_normal=$hull_upgrade";
				BuildOneCol("$l_hull $l_trade_upgraded $hull_upgrade");
			}
			if ($engine_upgrade > $shipinfo['engines_normal'])
			{
				$query = $query . ", engines=$engine_upgrade, engines_normal=$engine_upgrade";
				BuildOneCol("$l_engines $l_trade_upgraded $engine_upgrade");
			}
			if ($power_upgrade > $shipinfo['power_normal'])
			{
				$query = $query . ", power=$power_upgrade, power_normal=$power_upgrade";
				BuildOneCol("$l_power $l_trade_upgraded $power_upgrade");
			}
			if ($fighter_upgrade > $shipinfo['fighter_normal'])
			{
				$query = $query . ", fighter=$fighter_upgrade, fighter_normal=$fighter_upgrade";
				BuildOneCol("$l_fighter $l_trade_upgraded $fighter_upgrade");
			}
			if ($sensors_upgrade > $shipinfo['sensors_normal'])
			{
				$query = $query . ", sensors=$sensors_upgrade, sensors_normal=$sensors_upgrade";
				BuildOneCol("$l_sensors $l_trade_upgraded $sensors_upgrade");
			}
			if ($beams_upgrade > $shipinfo['beams_normal'])
			{
				$query = $query . ", beams=$beams_upgrade, beams_normal=$beams_upgrade";
				BuildOneCol("$l_beams $l_trade_upgraded $beams_upgrade");
			}
			if ($armor_upgrade > $shipinfo['armor_normal'])
			{
				$query = $query . ", armor=$armor_upgrade, armor_normal=$armor_upgrade";
				BuildOneCol("$l_armor $l_trade_upgraded $armor_upgrade");
			}
			if ($cloak_upgrade > $shipinfo['cloak_normal'])
			{
				$query = $query . ", cloak=$cloak_upgrade, cloak_normal=$cloak_upgrade";
				BuildOneCol("$l_cloak $l_trade_upgraded $cloak_upgrade");
			}
			if ($torp_launchers_upgrade > $shipinfo['torp_launchers_normal'])
			{
				$query = $query . ", torp_launchers=$torp_launchers_upgrade, torp_launchers_normal=$torp_launchers_upgrade";
				BuildOneCol("$l_torp_launch $l_trade_upgraded $torp_launchers_upgrade");
			}
			if ($shields_upgrade > $shipinfo['shields_normal'])
			{
				$query = $query . ", shields=$shields_upgrade, shields_normal=$shields_upgrade";
				BuildOneCol("$l_shields $l_trade_upgraded $shields_upgrade");
			}
			if ($ecm_upgrade > $shipinfo['ecm_normal'])
			{
				$query = $query . ", ecm=$ecm_upgrade, ecm_normal=$ecm_upgrade";
				BuildOneCol("$l_ecm $l_trade_upgraded $ecm_upgrade");
			}
			if ($fighter_number)
			{
				$query = $query . ", fighters=fighters+$fighter_number";
				BuildTwoCol("$l_fighters $l_trade_added:", $fighter_number, "left", "right" );
			}
			if ($torpedo_number)
			{
				$query = $query . ", torps=torps+$torpedo_number";
				BuildTwoCol("$l_torps $l_trade_added:", $torpedo_number, "left", "right" );
			}
			if ($armor_number)
			{
				$query = $query . ", armor_pts=armor_pts+$armor_number";
				BuildTwoCol("$l_armorpts $l_trade_added:", $armor_number, "left", "right" );
			}

			$query = $query . " WHERE ship_id=$shipinfo[ship_id]";
			$debug_query = $db->Execute("$query");
			db_op_result($debug_query,__LINE__,__FILE__);

			$hull_upgrade=0;
			echo "
			</table>
			";
		}
		echo "<BR><BR> <A HREF=port.php>$l_clickme</A> $l_port_returntospecial";
	}
}

//-------------------------------------------------------------------------------------------------

echo "<BR><BR>";
echo $l_global_mmenu;

include ("footer.php");

?>
