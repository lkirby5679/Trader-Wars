<?php
include ("globals/cleanjs.inc");

$title=$l_title_trade;
echo "<H1>$title</H1>\n";

$average_stats = (($shipinfo['hull_normal'] + $shipinfo['cloak_normal'] + $shipinfo['sensors_normal'] + $shipinfo['power_normal'] + $shipinfo['engines_normal'] + $shipinfo['fighter_normal'] + $shipinfo['armor_normal'] + $shipinfo['shields_normal'] + $shipinfo['beams_normal'] + $shipinfo['torp_launchers_normal'] + $shipinfo['ecm_normal'] ) / 11 );
if ($zoneinfo['zone_id'] == 2 && $zoneinfo['max_hull'] < $average_stats && $playerinfo['player_id'] > 3)
{
	echo $l_port_shiptoolarge;
}
else
{
cleanjs('');
echo $cleanjs;
echo "<FORM ACTION=port_purchase.php METHOD=POST>";
echo "<TABLE WIDTH=\"100%\" BORDER=0 CELLSPACING=0 CELLPADDING=0 bgcolor=\"#000000\">";
echo "<TR BGCOLOR=\"#585980\"><TD><B>$l_commodity</B></TD><TD><B>$l_buying/$l_selling</B></TD><TD><B>$l_amount</B></TD><TD><B>$l_price</B></TD><TD><B>$l_buy/$l_sell</B></TD><TD><B>$l_cargo</B></TD><td>$l_port_hold_unit</td></TR>";

$debug_query = $db->Execute("SELECT * FROM {$db_prefix}ship_holds WHERE cargo_name!='energy' and ship_id=$playerinfo[currentship]");
db_op_result($debug_query,__LINE__,__FILE__);

$ship_item_count = 0;
$ship_holds_used = 0;

while(!$debug_query->EOF){
	$ship_commodity_id[$ship_item_count] = $debug_query->fields['hold_id'];
	$ship_commodity_type[$ship_item_count] = $debug_query->fields['cargo_name'];
	$ship_commodity_class[$ship_item_count] = $debug_query->fields['cargo_class'];
	$ship_commodity_amount[$ship_item_count] = $debug_query->fields['amount'];
	$ship_commodity_holds[$ship_item_count] = $debug_query->fields['hold_space'];
	$ship_holds_used += ($debug_query->fields['hold_space'] * $debug_query->fields['amount']);
	$ship_commodity_ref[$ship_commodity_type[$ship_item_count]] = $ship_item_count;

	$ship_item_count++;
	$debug_query->MoveNext();
}
$debug_query->close();

$ship_commodity_id[$ship_item_count] = 0;
$ship_commodity_class[$ship_item_count] = "commodity";
$ship_commodity_type[$ship_item_count] = "energy";
$ship_commodity_amount[$ship_item_count] = $shipinfo['energy'];
$ship_commodity_holds[$ship_item_count] = 0;
$ship_commodity_ref[$ship_commodity_type[$ship_item_count]] = $ship_item_count;
$ship_item_count++;

$debug_query = $db->Execute("SELECT * FROM {$db_prefix}universe_ports WHERE sector_id=$sectorinfo[sector_id]");
db_op_result($debug_query,__LINE__,__FILE__);

$credits_made = 0;
$color = "#3A3B6E";
$amount_buy_tot=0;
while(!$debug_query->EOF){
	$data_id = $debug_query->fields['data_id'];
	$commodity_type = $debug_query->fields['commodity_type'];
	$commodity_amount = $debug_query->fields['commodity_amount'];
	$commodity_price = $debug_query->fields['commodity_price'];
	$goodevil = $debug_query->fields['goodevil'];

	$commodity_query = $db->Execute("SELECT * FROM {$db_prefix}class_modules_commodities WHERE classname='$commodity_type'");
	db_op_result($commodity_query,__LINE__,__FILE__);

	$delta = $commodity_query->fields['delta'];
	$limit = $commodity_query->fields['itemlimit'];
	$price = $commodity_query->fields['price'];
	$hold_space = $commodity_query->fields['hold_space'];

	if($sectorinfo['port_type'] == AAT_strtolower($commodity_type))
	{
		$offered_sell_price = max($commodity_price - $commodity_query->fields['delta'] * $debug_query->fields['commodity_amount'] / $commodity_query->fields['itemlimit'] * $inventory_factor, 0.01);
		if($commodity_type != "energy")
		{
			$amount_player_buy = floor((NUM_HOLDS($shipinfo['hull']) - $ship_holds_used) / $ship_commodity_holds[$ship_commodity_ref[$sectorinfo['port_type']]]);
		}
		else
		{
			$amount_player_buy = NUM_ENERGY($shipinfo['power']) - $shipinfo['energy'];
		}
		$amount_player_buy = min($amount_player_buy, floor(($playerinfo['credits'] + $credits_made) / $offered_sell_price));
		if($amount_player_buy > $commodity_amount)
		{
			$amount_player_buy = $commodity_amount;
		}
		$amount_port_sell = $commodity_amount;
	}
	else
	{
		$offered_buy_price = max($commodity_price + $commodity_query->fields['price'] + $commodity_query->fields['delta'] * $commodity_query->fields['itemlimit'] / $commodity_query->fields['itemlimit'] * $inventory_factor, 0.01);

		if($offered_buy_price <= 0)
			$offered_buy_price = 0.01;

		$ship_commodity_number = $ship_commodity_ref[$commodity_type];
		$amount_port_buy = (isset($ship_commodity_amount[$ship_commodity_number])) ? $ship_commodity_amount[$ship_commodity_number] : 0;
		$amount_port_buy = floor(min($amount_port_buy, $commodity_amount));
		$credits_made += ($amount_port_buy * $offered_buy_price);
		echo "<TR BGCOLOR=\"$color\"><TD>" . ucwords($commodity_type) . "</TD><TD>$l_buying</TD><TD>" . NUMBER($commodity_amount) . "</TD><TD>" . NUMBER($offered_buy_price) . "</TD><TD><INPUT TYPE=TEXT style='text-align:right' NAME=trade_" . str_replace(" ", "_", $commodity_type) . " SIZE=10 MAXLENGTH=20 VALUE=$amount_port_buy></TD><TD>" . NUMBER($ship_commodity_amount[$ship_commodity_number]) . "</TD><td>" . NUMBER($hold_space) . "</td></TR>";
	}
	$commodity_query->close();
	if($color == "#3A3B6E")
	{
		$color = "#23244F";
	}
	else
	{
		$color = "#3A3B6E";
	}
	
	if($commodity_type != "energy")
	{
		$amount_buy_tot+=$amount_port_buy;
	}
	$debug_query->MoveNext();
}
$debug_query->close();

$free_holds = NUM_HOLDS($shipinfo['hull']) - $ship_holds_used;
//echo "Holds used: $ship_holds_used<br>";
//if ($amount_buy_tot==0 || $amount_buy_tot==""){
//	$amount_buy_tot=$free_holds;
//}

//if($sectorinfo['port_type'] != "energy")
//{
//	$amount_player_buy += $amount_buy_tot;
//}

$ship_commodity_number = $ship_commodity_ref[$sectorinfo['port_type']];

echo "<TR BGCOLOR=\"$color\"><TD>" . ucwords($sectorinfo['port_type']) . "</TD><TD>$l_selling</TD><TD>" . NUMBER($amount_port_sell) . "</TD><TD>" . NUMBER(floor($offered_sell_price)) . "</TD><TD><INPUT TYPE=TEXT style='text-align:right' NAME=trade_" . str_replace(" ", "_", $sectorinfo['port_type']) . " SIZE=10 MAXLENGTH=20 VALUE=\"" . floor($amount_player_buy) . "\"></TD><TD>" . NUMBER($ship_commodity_amount[$ship_commodity_number]) . "</TD><td>" . NUMBER($ship_commodity_holds[$ship_commodity_number]) . "</td></TR>";

echo "</TABLE><BR>";
echo "<INPUT TYPE=SUBMIT VALUE=$l_trade ONCLICK=\"clean_js()\">";
echo "</FORM>";

$free_power = NUM_ENERGY($shipinfo['power']) - $shipinfo['energy'];

$l_trade_st_info=str_replace("[free_holds]",NUMBER($free_holds),$l_trade_st_info);
$l_trade_st_info=str_replace("[free_power]",NUMBER($free_power),$l_trade_st_info);
$l_trade_st_info=str_replace("[credits]",NUMBER($playerinfo['credits']),$l_trade_st_info);

echo $l_trade_st_info;
}

echo "\n";
echo "<BR><BR>\n";
echo $l_global_mmenu;
echo "\n";

include ("footer.php");

?>
