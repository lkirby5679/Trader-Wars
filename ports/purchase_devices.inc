<?php

include ("globals/isLoanPending.inc");

get_post_ifset("dev_sectormissile_number, fuelscoop_purchase, dev_beacon_number, dev_genesis_number, dev_sectorgenesis_number, probe_number, dev_emerwarp_number, dev_warpedit_number, spy_number, dig_number, dev_minedeflector_number, escapepod_purchase, total_cost, nova_purchase, total_cost2");

if ($playerinfo['turns'] < 1)
{
	echo "$l_trade_turnneed<BR><BR>";
}
else
{
	$trade_ore		= round(abs($trade_ore));
	$trade_organics = round(abs($trade_organics));
	$trade_goods	= round(abs($trade_goods));
	$trade_energy	 = round(abs($trade_energy));

	if ($sectorinfo['port_type'] == "devices")
	{

		if (isLoanPending($playerinfo['player_id']))
		{
			echo "$l_port_loannotrade<p>";
			echo "<A HREF=igb.php>$l_igb_term</a><p>";
			echo $l_global_mmenu;
			include ("footer.php");
			die();
		}

		$dev_beacon_number		= round(abs($dev_beacon_number));
		$dev_beacon_cost			= $dev_beacon_number * $dev_beacon_price;
		$dev_genesis_number		 = round(abs($dev_genesis_number));
		$dev_genesis_cost		 = $dev_genesis_number * $dev_genesis_price;
		$dev_sectorgenesis_number		 = round(abs($dev_sectorgenesis_number));
		$dev_sectorgenesis_cost		 = $dev_sectorgenesis_number * $dev_sectorgenesis_price;
		$dev_emerwarp_number		= min(round(abs($dev_emerwarp_number)), $max_emerwarp - $shipdevice['dev_emerwarp']['amount']);
		$dev_emerwarp_cost		= $dev_emerwarp_number * $dev_emerwarp_price;
		$dev_warpedit_number		= round(abs($dev_warpedit_number));
		$dev_warpedit_cost		= $dev_warpedit_number * $dev_warpedit_price;
		$dev_minedeflector_number = round(abs($dev_minedeflector_number));
		$dev_minedeflector_cost	 = $dev_minedeflector_number * $dev_minedeflector_price;
		$dev_sectormissile_number		= min(round(abs($dev_sectormissile_number)), $max_sectormissile - $shipdevice['dev_sectormissile']['amount']);
		$dev_sectormissile_cost		= $dev_sectormissile_number * $dev_sectormissile_price;

		if ($enable_spies)
		{
			$res=$db->Execute("SELECT count(spy_id) as spy_num from {$db_prefix}spies where owner_id=$playerinfo[player_id] AND ship_id=$shipinfo[ship_id] and active='N'");
			$spy_num = $res->fields['spy_num'];
			$res->close();
			if($spy_num <= $max_spies){
				$spy_number		= min(round(abs($spy_number)), $max_spies - $spy_num);
				$spy_cost				 = $spy_number * $spy_price;
			}
			else
			{
				$spy_number				 = 0;
				$spy_cost				 = 0;
			}
		}
		else
		{
			$spy_number				 = 0;
			$spy_cost				 = 0;
		}

		if($enable_dignitaries)
		{
			$res=$db->Execute("SELECT count(dig_id) as dig_num from {$db_prefix}dignitary where owner_id=$playerinfo[player_id] AND ship_id=$shipinfo[ship_id] and active='N'");
			$dig_num = $res->fields['dig_num'];
			$res->close();
			if($dig_num <= $max_digs){
				$dig_number		= min(round(abs($dig_number)), $max_digs - $dig_num);
				$dig_cost				 = $dig_number * $dig_price;
			}
			else
			{
				$dig_number				 = 0;
				$dig_cost				 = 0;
			}
		}
		else
		{
			$dig_number				 = 0;
			$dig_cost				 = 0;
		}

		$res=$db->Execute("SELECT count(probe_id) as probe_num from {$db_prefix}probe where owner_id=$playerinfo[player_id] AND ship_id=$shipinfo[ship_id]");
		$probe_num = $res->fields['probe_num'];
		$res->close();
		if($probe_num <= $max_probes){
			$probe_number		= min(round(abs($probe_number)), $max_probes - $probe_num);
			$probe_cost				 = $probe_number * $dev_probe;
		}
		else
		{
			$probe_number				 = 0;
			$probe_cost				 = 0;
		}

		$dev_escapepod_cost = 0;
		$dev_fuelscoop_cost = 0;
		if (($escapepod_purchase) && ($shipdevice['dev_escapepod']['amount'] == 0))
		{
			$dev_escapepod_cost = $dev_escapepod_price;
		}
		if (($fuelscoop_purchase) && ($shipdevice['dev_fuelscoop']['amount'] == 0))
		{
			$dev_fuelscoop_cost = $dev_fuelscoop_price;
		}

		$dev_nova_cost = 0;
		if(($nova_purchase != 0) && ($shipdevice['dev_nova']['amount'] == '0') && $zoneinfo['zone_id'] == 3)
		{
			$dev_nova_cost = (((mypw(4.30, $nova_purchase) - mypw(4.30, 0)) * 200) + $dev_nova_price);
		}

		$total_cost = $dev_genesis_cost + $dev_sectorgenesis_cost + $dev_beacon_cost + $dev_emerwarp_cost + $dev_warpedit_cost + $dev_minedeflector_cost + $dev_sectormissile_cost +
						$dev_escapepod_cost + $dev_fuelscoop_cost + $dev_nova_cost + $shields_upgrade_cost + $spy_cost + $dig_cost+ $probe_cost;///

		$total_cost = $total_cost * $alliancefactor;

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

			if ($dev_genesis_number)
			{
				$debug_query = $db->Execute("UPDATE {$db_prefix}ship_devices SET amount=amount+$dev_genesis_number WHERE device_id=" . $shipdevice['dev_genesis']['device_id']);
				db_op_result($debug_query,__LINE__,__FILE__);
				BuildTwoCol("$l_genesis $l_trade_added:", $dev_genesis_number, "left", "right" );
			}
			if ($dev_sectorgenesis_number)
			{
				$debug_query = $db->Execute("UPDATE {$db_prefix}ship_devices SET amount=amount+$dev_sectorgenesis_number WHERE device_id=" . $shipdevice['dev_sectorgenesis']['device_id']);
				db_op_result($debug_query,__LINE__,__FILE__);
				BuildTwoCol("$l_sectorgenesis $l_trade_added:", $dev_sectorgenesis_number, "left", "right" );
			}
			if($dev_beacon_number)
			{
				$debug_query = $db->Execute("UPDATE {$db_prefix}ship_devices SET amount=amount+$dev_beacon_number WHERE device_id=" . $shipdevice['dev_beacon']['device_id']);
				db_op_result($debug_query,__LINE__,__FILE__);
				BuildTwoCol("$l_beacons $l_trade_added:", $dev_beacon_number , "left", "right" );
			}
			if ($dev_emerwarp_number)
			{
				$debug_query = $db->Execute("UPDATE {$db_prefix}ship_devices SET amount=amount+$dev_emerwarp_number WHERE device_id=" . $shipdevice['dev_emerwarp']['device_id']);
				db_op_result($debug_query,__LINE__,__FILE__);
				BuildTwoCol("$l_ewd $l_trade_added:", $dev_emerwarp_number , "left", "right" );
			}
			if ($dev_sectormissile_number)
			{
				$debug_query = $db->Execute("UPDATE {$db_prefix}ship_devices SET amount=amount+$dev_sectormissile_number WHERE device_id=" . $shipdevice['dev_sectormissile']['device_id']);
				db_op_result($debug_query,__LINE__,__FILE__);
				BuildTwoCol("$l_sectormissile $l_trade_added:", $dev_sectormissile_number , "left", "right" );
			}
			if ($dev_warpedit_number)
			{
				$debug_query = $db->Execute("UPDATE {$db_prefix}ship_devices SET amount=amount+$dev_warpedit_number WHERE device_id=" . $shipdevice['dev_warpedit']['device_id']);
				db_op_result($debug_query,__LINE__,__FILE__);
				BuildTwoCol("$l_warpedit $l_trade_added:", $dev_warpedit_number , "left", "right" );
			}
			if ($dev_minedeflector_number)
			{
				$debug_query = $db->Execute("UPDATE {$db_prefix}ship_devices SET amount=amount+$dev_minedeflector_number WHERE device_id=" . $shipdevice['dev_minedeflector']['device_id']);
				db_op_result($debug_query,__LINE__,__FILE__);
				BuildTwoCol("$l_deflect $l_trade_added:", $dev_minedeflector_number , "left", "right" );
			}
			if (($escapepod_purchase) && ($shipdevice['dev_escapepod']['amount'] == 0))
			{
				$debug_query = $db->Execute("UPDATE {$db_prefix}ship_devices SET amount=1 WHERE device_id=" . $shipdevice['dev_escapepod']['device_id']);
				db_op_result($debug_query,__LINE__,__FILE__);
				BuildOneCol("$l_escape_pod $l_trade_installed");
			}
			if (($fuelscoop_purchase) && ($shipinfo['dev_fuelscoop']['amount'] == 0))
			{
				$debug_query = $db->Execute("UPDATE {$db_prefix}ship_devices SET amount=1 WHERE device_id=" . $shipdevice['dev_fuelscoop']['device_id']);
				db_op_result($debug_query,__LINE__,__FILE__);
				BuildOneCol("$l_fuel_scoop $l_trade_installed");
			}
			if(($nova_purchase != 0) && ($shipinfo['dev_nova']['amount'] == 0) && $zoneinfo['zone_id'] == 3)
			{
				$debug_query = $db->Execute("UPDATE {$db_prefix}ship_devices SET amount=$nova_purchase WHERE device_id=" . $shipdevice['dev_nova']['device_id']);
				db_op_result($debug_query,__LINE__,__FILE__);
				BuildOneCol("$l_nova $l_trade_installed");
			}

			if ($spy_number && $enable_spies)
			{
				for ($i=1; $i<=$spy_number; $i++)
				{
					$debug_query = $db->Execute("INSERT INTO {$db_prefix}spies (spy_id, active, owner_id, planet_id, ship_id, job_id, spy_percent, move_type) values ('','N',$playerinfo[player_id],'0','$shipinfo[ship_id]','0','0.0','toship')");
					db_op_result($debug_query,__LINE__,__FILE__);
				}
				BuildTwoCol("$l_spy $l_trade_added:", $spy_number , "left", "right" );
			}

			if($dig_number && $enable_dignitaries)
			{
				for($i=1; $i<=$dig_number; $i++)
				{
					$debug_query = $db->Execute("INSERT INTO {$db_prefix}dignitary (dig_id, active, owner_id, planet_id, ship_id, job_id, percent) values ('','N',$playerinfo[player_id],'0','$shipinfo[ship_id]','0','0.0')");
					db_op_result($debug_query,__LINE__,__FILE__);
				}
				BuildTwoCol("$l_dig $l_trade_added:", $dig_number , "left", "right" );
			}
			if($probe_number)
			{
					buy_them_probe($playerinfo['player_id'], $probe_number);
					BuildTwoCol("$l_probe $l_trade_added:", $probe_number , "left", "right" );
			}

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
