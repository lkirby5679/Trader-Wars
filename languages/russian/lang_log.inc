<?php
$l_log_months 		 = array('������','�������','����','������','���','����','����','������','��������','�������','������','�������');
$l_log_months_short 	 = array('���','���','����','���','���','����','����','���','����','���','���','���');
$l_log_pod 		 = "������, ��� � ��� ���� ������������ �������!";
$l_log_nopod 		 = "<font color=yellow><b>� ��� �� ���� ������������ ������� � �� �������.</b></font>";
$l_log_log 		 = "������ [player]";
$l_log_start 		 = "������ ��";
$l_log_end 		 = "����� ������ ��";
$l_log_click 		 = "������� <A HREF=main.php><font color=#00ff00>�����</font></A> ��� �������� � ������� ����.";
$l_log_select 		 = "Select a Log:";
$l_log_general 		 = "General Log";
$l_log_dig 		 = "Dignitary Log";
$l_log_spy 		 = "Spy Log";
$l_log_disaster 		 = "Planet Disaster Log";
$l_log_nova 		 = "Nova Device Log";
$l_log_attack 		 = "Attack Log";
$l_log_scan 		 = "Scan Log";
$l_log_starv 		 = "Planet Starvation Log";
$l_log_probe 		 = "Probe Log";
$l_log_autotrade 		 = "Auto Trade Log";
$l_log_combined 		 = "Combined Log";

$l_log_text["LOG_LOGIN"] 	 = "�� ����� � ���� [ip].";
$l_log_title["LOG_LOGIN"]  = "����";
$l_log_text["LOG_LOGOUT"]  = "�� ����� � ���� [ip].";
$l_log_title["LOG_LOGOUT"] = "�����";
$l_log_text["LOG5_ATTACK_OUTMAN"] 		= "[player] ������� �� �����, �� ���� ������ ������������� � �������� ��������� ��������� �������� �����.";
$l_log_title["LOG5_ATTACK_OUTMAN"] 	= "������ ���������!";
$l_log_text["LOG5_ATTACK_OUTSCAN"] 	= "�� �������, ��� ������ [player] ��������� �� ��� �������, �� ���� ���������� �������� ������� ����������.";
$l_log_title["LOG5_ATTACK_OUTSCAN"] 	= "������� ����������!";
$l_log_text["LOG5_ATTACK_EWD"] 		= "�� ��������� ��������� ����� [player]. �� ������� ������� �������, � ������ ������ �� ������ ������� ���������� ��������������. ��� ������ ��� ������������, � �� ��������� �� ��������, ��� �������. �� ����� �� ������� �����, �� �������, ��� ������������ ��������� � �����-�� ������ ������. �� � �����...";
$l_log_title["LOG5_ATTACK_EWD"] 		= "������ ���������� ��������������!";
$l_log_text["LOG5_ATTACK_EWDFAIL"] 	= "���� ������� ������� �������������� ������� [player]. \"����� �� ���������\", �������� ��, ������� �� ������ ������� ���������� ��������������. �� ������������� ������ ���������� �������� ���� � ������� �������. \"����������� ��������!\", ���������� ��, ������ �� ����������. ��������� ����� �������� ������������ �����, � �� ������������� � ������������� �����...";
$l_log_title["LOG5_ATTACK_EWDFAIL"] 	= "<font color=red>����� �������</font> ���������� ��������������!";
$l_log_text["LOG5_ATTACK_LOSE"] 		= "��� ������� �������� [player]. ��� �� �� ����������, ��� �� ������� ������ ������������� ���� [player]. ��� ������� ���������. ";
$l_log_title["LOG5_ATTACK_LOSE"] 		= "<font color=red>����� ���������!</font>";
$l_log_text["LOG5_ATTACKED_WIN"] 		= "[player] �������� ��� �������. �� ���������� ����������� �������. ���� ����� ���������� �� [armor], � ������ ������������ ��������� [fighters].";
$l_log_title["LOG5_ATTACKED_WIN"] 		= "<font color=yellow>�����������!</font>";
$l_log_text["LOG5_HIT_MINES"] 		= "�� ��������� �� [mines] ��� ��� ����� � ������ [sector].";
$l_log_title["LOG5_HIT_MINES"] 		= "<font color=yellow>������ ����!</font>";
$l_log_text["LOG5_SHIP_DESTROYED_MINES"] 	= "��� ������� ��� ��������� �� ������ ���� � ������� [sector]. ";
$l_log_title["LOG5_SHIP_DESTROYED_MINES"] 	= "<font color=red>������ ����!</font>";
$l_log_text["LOG5_PLANET_DEFEATED_D"] 	= "���� ������� [planet_name] � ������� [sector] ���� ��������� � ��� � [name]. � �������, ����������� ������ ������ ������� ��� �� ����. ������ ������� ������ ���������� ������� ���� ��� �� ������ � ���� �����. �� �������� ��������� �������� � ������ � ����� ��������� ������.";
$l_log_title["LOG5_PLANET_DEFEATED_D"] 	= "<font color=yellow>������� ����������</font>";
$l_log_text["LOG5_PLANET_DEFEATED"] 	= "���� ������� [planet_name] � ������� [sector] ���� ��������� � ��� � ������� [name]. ������ ������� ������������ ������ ���������. �� ������� ��������� �� ��� : \"�� ���� ���������� �� ����� ��������! ��� �� ����� ������� ���������, ������� �� � ��������� ��� ��������!\". �� ��������� ��������� �� �� �� �����������.";
$l_log_title["LOG5_PLANET_DEFEATED"] 	= "<font color=red>������� ���������!</font>";
$l_log_text["LOG5_PLANET_NOT_DEFEATED"] 	= "���� ������� [planet_name] � ������� [sector] ��������� [name]. ������ ������� ������������ ������������� � ������ ���������� ����������. ��� ������� ��������� ������� �� ��������: [goods] �������, [ore] ����, [organics] �������� � [salvage]% ��������� ������� �� [credits] ������.";
$l_log_title["LOG5_PLANET_NOT_DEFEATED"] 	= "������!";
$l_log_title["LOG0_RAW"] 			= "�������";
$l_log_text["LOG5_DEFS_DESTROYED"] 	= "[quantity] [type] ���������� � ������� [sector].";
$l_log_title["LOG5_DEFS_DESTROYED"] 	= "������ ����������� �������������� �������";
$l_log_text["LOG0_PLANET_EJECT"] 		= "�� ���� ��������� � ������� � ������� [sector] �� ������� ������ [name] �� �������.";
$l_log_title["LOG0_PLANET_EJECT"] 		= "<font color=yellow>����������!</font>";
$l_log_text["LOG0_BADLOGIN"] 		= "���� ��������� ������� ����� � ���� [ip].";
$l_log_title["LOG0_BADLOGIN"] 		= "<font color=red>��������� ����</font>";
$l_log_text["LOG6_PLANET_SCAN"] 		= "[name] ������������� ���� ������� [planet_name] � ������� [sector].";
$l_log_title["LOG6_PLANET_SCAN"] 		= "<font color=brown>������������ �������</font>";
$l_log_text["LOG6_PLANET_SCAN_FAIL"] 	= "[name] ������� �������������� ���� ������� [planet_name] � ������� [sector], �� ��������.";
$l_log_title["LOG6_PLANET_SCAN_FAIL"] 	= "<font color=green>��������� ������������ �������</font>";
$l_log_text["LOG6_SHIP_SCAN"] 		= "[player] ������������� ��� �������.";
$l_log_title["LOG6_SHIP_SCAN"] 		= "<font color=brown>������������ �������</font>";
$l_log_text["LOG6_SHIP_SCAN_FAIL"] 	= "[player] �������� ������� ����������� ��� �������.";
$l_log_title["LOG6_SHIP_SCAN_FAIL"] 	= "<font color=green>��������� ������������ �������</font>";
$l_log_text["LOG5_KABAL_ATTACK"] 		= "����� [player]... (�����!)";
$l_log_title["LOG5_KABAL_ATTACK"] 		= "����� (�����!)";
$l_log_text["LOG7_STARVATION"] 		= "[name] �� ������ � ������� [sector] �� ����� ���������� ��� ���������! ���������� ������ ��������. [starvation] ���������� ������ � ������. Colonists started starving on [date].";
$l_log_title["LOG7_STARVATION"] 		= "<font color=yellow>���������!</font>";
$l_log_title["LOG0_TOW"] 			= "<font color=yellow>������������!</font>";
$l_log_text["LOG0_TOW"] 	 = "Your ship has been towed from sector [sector] to sector [newsector] because your average tech level exceeded the limit value of [hull] or you have a ship in storage.";
$l_log_text["LOG5_DEFS_DESTROYED_F"] 	= "�� ���������� [fighters] ������������ ��������������� ������ [sector].";
$l_log_title["LOG5_DEFS_DESTROYED_F"] 	= "��������� �������";
$l_log_text["LOG5_DEFS_KABOOM"] 		= "��� ������� ��������� ������������ ������ ������� [sector]. ";
$l_log_title["LOG5_DEFS_KABOOM"] 		= "<font color=red>������� ���������!</font>";
$l_log_text["LOG0_HARAKIRI"] 		= "�� ������ �� ������������ ���� ������ � ������, ��� �� ��������� � ��� ��� ������ �������. ������������ � ���� [ip].";
$l_log_title["LOG0_HARAKIRI"] 		= "<font color=red>���������������!</font>";
$l_log_text["LOG0_TEAM_REJECT"] 		= "[player] ��������� �������� � ��� ������ [teamname].";
$l_log_title["LOG0_TEAM_REJECT"] 		= "����������� ���������";
$l_log_text["LOG0_TEAM_RENAME"] 		= "�� ������������� ��� ������ � [team].";
$l_log_title["LOG0_TEAM_RENAME"] 		= "������ ������������";
$l_log_text["LOG0_TEAM_M_RENAME"] 		= "����������� ������������ ������ � [team].";
$l_log_title["LOG0_TEAM_M_RENAME"] 	= "������ ������������";
$l_log_text["LOG0_TEAM_KICK"] 		= "��� ��������� �� ������� [team].";
$l_log_title["LOG0_TEAM_KICK"] 		= "<font color=yellow>���������� �� �������!</font>";
$l_log_text["LOG0_TEAM_CREATE"] 		= "�� ������� ����� ������ [team].";
$l_log_title["LOG0_TEAM_CREATE"] 		= "<font color=green>����� ������</font>";
$l_log_text["LOG0_TEAM_LEAVE"] 		= "�� �������� ������ [team].";
$l_log_title["LOG0_TEAM_LEAVE"] 		= "������ �������";
$l_log_text["LOG0_TEAM_NEWLEAD"] 		= "�� �������� ������ [team] � �������� ���������� [name].";
$l_log_title["LOG0_TEAM_NEWLEAD"] 		= "������ �������";
$l_log_text["LOG0_TEAM_LEAD"] 		= "��� ����������� ����� �������� ������ [team]. ��� ��������� �� ��� �����.";
$l_log_title["LOG0_TEAM_LEAD"] 		= "���������!";
$l_log_text["LOG0_TEAM_JOIN"] 		= "�� �������������� � ������� [team].";
$l_log_title["LOG0_TEAM_JOIN"] 		= "���������� � ������";
$l_log_text["LOG0_TEAM_NEWMEMBER"] 	= "[name] ����� �������������� � [team]. ��� ������ ����������� � ���������� � ���������.";
$l_log_title["LOG0_TEAM_NEWMEMBER"] 	= "����� ���� �������";
$l_log_text["LOG0_TEAM_INVITE"] 		= "��� ���������� � ������ [team].";
$l_log_title["LOG0_TEAM_INVITE"] 		= "�����������";
$l_log_text["LOG0_TEAM_NOT_LEAVE"] 	= "[player] ����� �� �������.";
$l_log_title["LOG0_TEAM_NOT_LEAVE"] 	= "������ ����� �������";
$l_log_text["LOG0_ADMIN_HARAKIRI"] 	= "[player] ��������������� � ���� [ip].";
$l_log_title["LOG0_ADMIN_HARAKIRI"] 	= "���������������";
$l_log_text["LOG0_ADMIN_ILLEGVALUE"] 	= "� [player] ���� [quantity] [type], ��� ��������� [holds]";
$l_log_title["LOG0_ADMIN_ILLEGVALUE"] 	= "������������ ��������";
$l_log_text["LOG0_ADMIN_PLANETDEL"] 	= "[attacker] ��������� ��������� ������� [defender] � ������� [sector]. �� ������� ���� ����������.";
$l_log_title["LOG0_ADMIN_PLANETDEL"] 	= "������� ����������";
$l_log_text["LOG0_defense_DEGRADE"] 	= "���������� ������������ ����������� ������� � ������� [sector] ����������� �� [degrade] ��������� ��-�� �������� �������.";
$l_log_title["LOG0_defense_DEGRADE"] 	= "���������� ����������� �������.";
$l_log_text["LOG5_PLANET_CAPTURED"] 	= "�� ��������� ������� [owner]. �� ��� [cols] ���������� � [credits] ������.";
$l_log_title["LOG5_PLANET_CAPTURED"] 	= "������� ���������!";
$l_log_text["LOG0_CHEAT_TEAM"] 		= "����� [player] � ���� [ip] ������� ��������� � ��������. ��� ������� ��� ���������.";
$l_log_text["LOG0_BOUNTY_CLAIMED"] = "�� �������� ������� � ������� [amount] ������ �� ����������� ������� [bounty_on]. ������� ���� ��������� [placed_by].";
$l_log_title["LOG0_BOUNTY_CLAIMED"] = "�������� ��������������.";
$l_log_text["LOG0_BOUNTY_PAID"] = "���� ������� �� [bounty_on] ��������� � ������� [amount] ������.";
$l_log_text["LOG0_BOUNTY_TAX_PAID"] = "The Fedration bounty on [bounty_on] has been taxed for the amount of [amount] credits.";
$l_log_title["LOG0_BOUNTY_PAID"] = "�������������� ���������.";
$l_log_text["LOG0_BOUNTY_CANCELLED"] = "������������� ���� �������������� �� [bounty_on] � ������� [amount] ������ ���� ���������.";
$l_log_title["LOG0_BOUNTY_CANCELLED"] = "�������������� ���������.";
$l_log_text["LOG0_BOUNTY_FEDBOUNTY"] = "��������� ��������� ������� �� ���� ������ � ������� [amount] ������.";
$l_log_title["LOG0_BOUNTY_FEDBOUNTY"] = "����������� �������!";
$l_log_text["LOG0_BOUNTY_ALLIANCEBOUNTY"] = "The Alliance has placed a bounty on you for the amount of [amount] credits.";
$l_log_title["LOG0_BOUNTY_ALLIANCEBOUNTY"] = "Alliance Bounty!";
$l_log_text["LOG0_IGB_TRANSFER1"] = "����� [name] ������� �� ��� ���� � ��� [sum] ������.";
$l_log_title["LOG0_IGB_TRANSFER1"] = "�������� �������";
$l_log_text["LOG0_IGB_TRANSFER2"] = "�� �������� [sum] ������ �� ���� ������ [name].";
$l_log_title["LOG0_IGB_TRANSFER2"] = "�������� �������";

$l_log_text["LOG4_PLANET_novaED_D"] 	= "Your planet [planet_name] in sector [sector] was destroyed with a Nova Bomb by [name]. Absolutely nothing remains to mark the planets former existance.";
$l_log_title["LOG4_PLANET_novaED_D"] 	= "<font color=yellow>Planet destroyed with a Nova Bomb</font>";
$l_log_text["LOG4_SHIP_novaED_D"] 	= "Your ship was destroyed with a Nova Bombed by [name].";
$l_log_title["LOG4_SHIP_novaED_D"] 	= "<font color=yellow>Ship destroyed with a Nova Bomb</font>";
$l_log_text["LOG2_SPY_FOUND_EMBEZZLER"] 	= "Your dignitary number [DIG] on planet [PLANET] has been caught embezzling.  You might want to dismiss them.";
$l_log_title["LOG2_SPY_FOUND_EMBEZZLER"] 	= "<font color=yellow>Embezzler found!</font>";
$l_log_text["LOG9_PROBE_DETECTED_SHIP"]="<font color=yellow>Your probe id [id] detected [ship_name] entering sector [sector]</font>";
$l_log_title["LOG9_PROBE_DETECTED_SHIP"] 		= "Probe Detected Incoming Ship";
$l_log_text["LOG9_PROBE_SCAN_SHIP"]="<font color=yellow>Your probe id [id] scanned [ship_name] entering sector [sector]<br>
Hull: [hull] Engines: [engines] Power: [power] Fighter Bay: [fighter] Sensors: [sensors] Beams: [beams] Torp Launchers: [torps] Armor: [armor] Shields: [shields] Cloak: [cloak]<br>
Armor Points: [armor_pts] Fighters: [fighters] Torpedoes: [avail_torps] Ship Energy: [energy] Credits: [credits] <br>
Mine Deflectors: [deflectors] Emergency Warp: [ewd] Escape Pod: [pod] ECM: [ecm]</font>";
$l_log_title["LOG9_PROBE_SCAN_SHIP"] 		= "Probe Scanned Incoming Ship";
$l_log_text["LOG0_ADMIN_PLANETIND"] 	= "[sector] planet [planetname] ([planetid]) owned by [owner] became independant. Average Tech: [avgtech]";
$l_log_title["LOG0_ADMIN_PLANETIND"] 	= "Planet went independant.";
$l_log_text["LOG0_ADMIN_INDYPURGE"] 	= "Independant planet [planetname] ([planetid]) owned by [owner] in [sector] was purged. Average Tech: [avgtech]";
$l_log_title["LOG0_ADMIN_INDYPURGE"] 	= "Independant Planet Purged.";
$l_log_text["LOG0_ADMIN_NEVEROWNEDPURGE"] 	= "Never Owned planet [planetname] ([planetid]) created on [date] in [sector] was purged. Average Tech: [avgtech]";
$l_log_title["LOG0_ADMIN_NEVEROWNEDPURGE"] 	= "Never Owned Planet Purged.";
$l_log_text["LOG0_TEAM_CANCEL"] 		= "You're invitation to be part of [team] has been canceled.";
$l_log_title["LOG0_TEAM_CANCEL"] 		= "Invitation Canceled";
$l_log_text["LOG10_AUTOTRADE"]="<font color=yellow>Auto Trade for [planetname] in sector [sector] for [totalcost] credits.<br>Goods: [goodsamount] @ [goodsprice] credits - Ore: [oreamount] @ [oreprice] credits - Organics: [organicsamount] @ [organicsprice] credits - Energy: [energyamount] @ [energyprice] credits - Colonists: [colonistamount] @ [colonistprice] credits<br></font>";
$l_log_title["LOG10_AUTOTRADE"] 		= "Auto Trade Report";
$l_log_text["LOG10_AUTOTRADE_ABORTED"]="<font color='#00ff00'>Auto Trade for [planetname] in sector [sector] was aborted due to enemy sector defense in sector [destsector].<br></font>";
$l_log_title["LOG10_AUTOTRADE_ABORTED"] 		= "Auto Trade Report";
$l_log_text["LOG9_PROBE_DESTROYED"]="<font color='#00ff00'>SECTOR defenseS in [sector] destroy your probe.</font>";
$l_log_title["LOG9_PROBE_DESTROYED"] 		= "Probe Destroyed";
$l_log_text["LOG9_PROBE_NOTURNS"]="<font color='#00ff00'>You do not have enough turns for probe [probe_id] to move to [sector]</font>";
$l_log_title["LOG9_PROBE_NOTURNS"] 		= "Probe Report";
$l_log_text["LOG9_PROBE_INVALIDSECTOR"]="<font color='#00ff00'>Moving to sector [target_sector] is not allowed</font>";
$l_log_title["LOG9_PROBE_INVALIDSECTOR"] 		= "Probe Report";
$l_log_text["LOG9_PROBE_DETECTPROBE"]="<font color='#00ff00'>Probe [probe_id] in sector [sector] detected [probe_detect]</font>";
$l_log_title["LOG9_PROBE_DETECTPROBE"] 		= "[probe_type] Probe Report";

// added

$l_log_text["LOG2_SPY_NEWSHIP"] = "����� ���������� �����, �������� ��������� [id], ���������� ����� ��� ���������� ���������� ������� �� ������� ���������� [shipname], ����������� [name], ����������� ������� � ����������.";
$l_log_title["LOG2_SPY_NEWSHIP"] = "<font color=yellow>����� �� ������� ��������</font>";

$l_log_text["LOG2_SPY_SEND_FAIL"] = "[name] ������� ������� ������ �� ���� ������� [planet_name] � ������� [sector], �� ���� ������ ������� ������� ��� �������. ��������� ����� ����.";
$l_log_title["LOG2_SPY_SEND_FAIL"] = "<font color=yellow>��������� ����� ����!</font>";

$l_log_text["LOG2_SPY_SABOTAGE"] = "��� ����� [id] ����������� ���� �� ������� [planet_name] � ������� [sector]. ������������ �� ���� ������� ��������� �� [data].";
$l_log_title["LOG2_SPY_SABOTAGE"] = "<font color=#00FF00>����!</font>";

$l_log_text["LOG2_SPY_BIRTH"] = "��� ����� [id] �� ������� [planet_name] � ������� [sector] �������� ������� ����������� �� [data].";
$l_log_title["LOG2_SPY_BIRTH"] = "<font color=#00FF00>������� ����������� ������!</font>";

$l_log_text["LOG2_SPY_INTEREST"] = "��� ����� [id] �� ������� [planet_name] � ������� [sector] ����� ���������� ��� [data] ������� �������.";
$l_log_title["LOG2_SPY_INTEREST"] = "<font color=#00FF00>���������� �������� ������!</font>";

$l_log_text["LOG2_SPY_MONEY"] = "��� ����� [id] �� ������� [planet_name] � ������� [sector] ����� ��� ��� [data] ������!";
$l_log_title["LOG2_SPY_MONEY"] = "<font color=#00FF00>��� ������� �����!</font>";

$l_log_text["LOG2_SPY_TORPS"] = "��� ����� [id] �� ������� [planet_name] � ������� [sector] ��������� [data] planetary torpedoes!";
$l_log_title["LOG2_SPY_TORPS"] = "<font color=#00FF00>����� ��������!</font>";

$l_log_text["LOG2_SPY_FITS"] = "��� ����� [id] �� ������� [planet_name] � ������� [sector] ��������� � ���� ����������� [data] ������������!";
$l_log_title["LOG2_SPY_FITS"] = "<font color=#00FF00>��������� �����!</font>";

$l_log_text["LOG2_SPY_CPTURE"] = "��� ����� [id] �� ������� [planet_name] � ������� [sector] ������� ���������!! � ��� �������� ��������...";
$l_log_title["LOG2_SPY_CPTURE"] = "<font color=#00FF00>������ �������!</font>";

$l_log_text["LOG2_SPY_CPTURE_OWNER"] = "����� ������������ [name] �������� ���� ������� [planet_name] � ������� [sector]! ��� �� ��������� ������ ��������� �������� �� ��������...";
$l_log_title["LOG2_SPY_CPTURE_OWNER"] = "<font color=red>������� ��������!</font>";

$l_log_text["LOG2_SPY_KILLED_SPYOWNER"] = "�� ������ [id] � ������� [planet_name] � ������� [sector] ����� �� ���� ������ - ������ �� ������������ � ����.";
$l_log_title["LOG2_SPY_KILLED_SPYOWNER"] = "<font color=yellow>����� �� ������� ��������</font>";

$l_log_text["LOG2_SPY_KILLED"] = "���� ������ �� ������� [planet_name]  � ������� [sector] ������� ������ ������� [name]. ��� ���� ��������.";
$l_log_title["LOG2_SPY_KILLED"] = "<font color=yellow>��������� ��������� �����!</font>";

$l_log_text["LOG2_SHIPSPY_KILLED"] = "�� ������ [id] �� ������� [shipname], ����������� [name] ����� �� ���� ������ - ������ �� ������������ � ����.";
$l_log_title["LOG2_SHIPSPY_KILLED"] = "<font color=yellow>����� �� ������� ��������!</font>";

$l_log_text["LOG2_SPY_CATACLYSM"] = "��� ����� [id] �� ������� [planet_name] � ������� [sector] ������ ��� ����� ��� �������� ���������� �� �������.";
$l_log_title["LOG2_SPY_CATACLYSM"] = "<font color=yellow>����� �� ������� ��������!</font>";

$l_log_text["LOG2_SHIPSPY_CATACLYSM"] = "��� ����� [id] �� ������� [shipname] ��� ������������� [name] ����� � ����������� ����������.";
$l_log_title["LOG2_SHIPSPY_CATACLYSM"] = "<font color=yellow>����� �� ������� ��������!</font>";

$l_log_text["LOG2_SPY_TOSHIP"] = "��� ����� [id] � ������� [planet_name] � ������� [sector] ���������� �� ������� [shipname] ����������� [playername]. ����� ������!";
$l_log_title["LOG2_SPY_TOSHIP"] = "<font color=#00FF00>����� ���������� �� ��������� �������!</font>";

$l_log_text["LOG2_SPY_TOPLANET"] = "��� ����� [id] � ������� [shipname] ������������ [playername] ��������� �� ������� [planet_name] � ������� [sector]. ����� ����� ������.";
$l_log_title["LOG2_SPY_TOPLANET"] = "<font color=#00FF00>������� �� ��������� �������!</font>";

$l_log_text["LOG5_PLANET_YOUR_CAPTURED"]   = "���� ������� [planet_name] � ������� [sector] ���� ��������� ����������� [name].";
$l_log_title["LOG5_PLANET_YOUR_CAPTURED"]  = "<font color=red>������� ���������!</font>";
$l_log_text["LOG5_STORAGE_EWD"] 		= "Your planet is surprised by [player]'s attack. One of your stored ships made an Emergency Warp to [sector] and landed on planet [planet]";
$l_log_title["LOG5_STORAGE_EWD"] 		= "Stored Ship Emergency warp!";
$l_log_text["LOG5_STORAGE_EWDFAIL"] 	= "A stored ships Emergency Warp Device FAILED!  The stored ship was captured by [player] after they defeated your planet!";
$l_log_title["LOG5_STORAGE_EWDFAIL"] 	= "Stored Ship Emergency warp <font color=red>failed!</font>";
$l_log_text["LOG5_STORAGE_CAPTURED"] 	= "A stored ship was captured by [player] after they defeated one of your planets!";
$l_log_title["LOG5_STORAGE_CAPTURED"] 	= "Stored Ship <font color=red>CAPTURED!</font>";

$l_log_text["LOG1_DIG_PRODUCTION"] = "Your dignitary [id] on planet [planet_name] in sector [sector] starts building production.";
$l_log_title["LOG1_DIG_PRODUCTION"] = "<font color=#00FF00>Production Building  Started!</font>";
$l_log_text["LOG1_DIG_BIRTHDEC"] = "Your dignitary [id] on planet [planet_name] in sector [sector] decreasing birthrate.";
$l_log_title["LOG1_DIG_BIRTHDEC"] = "<font color=#00FF00>Birthrate Decreased!</font>";
$l_log_text["LOG1_DIG_BIRTHINC"] = "Your dignitary [id] on planet [planet_name] in sector [sector] increasing birthrate.";
$l_log_title["LOG1_DIG_BIRTHINC"] = "<font color=#00FF00>Birthrate Increased!</font>";
$l_log_text["LOG1_DIG_SPYHUNT"] = "Your dignitary [id] on planet [planet_name] in sector [sector] began searching for spys on that planet.";
$l_log_title["LOG1_DIG_SPYHUNT"] = "<font color=#00FF00>Spy Hunter!</font>";
$l_log_text["LOG1_DIG_INTEREST"] = "Your dignitary [id] on planet [planet_name] in sector [sector] starts boosting credit production.";
$l_log_title["LOG1_DIG_INTEREST"] = "<font color=#00FF00>Interest Building Started!</font>";
$l_log_text["LOG1_DIG_MONEY"] = "Dignitary [id] on planet [planet_name] embezzled [data] credits and donated to you!";
$l_log_title["LOG1_DIG_MONEY"] = "<font color=#00FF00>You Recieved Embezzled  Credits!</font>";
$l_log_text["LOG1_DIG_KILLED_SPY"] = "Your dignitary detected player [name]'s spy on your planet [planet_name] in sector [sector]. The spy is killed now.";
$l_log_title["LOG1_DIG_KILLED_SPY"] = "<font color=yellow>Enemy Spy Killed!</font>";
$l_log_text["LOG1_DIG_CATACLYSM"] = "Your dig [id] on planet [planet_name] in sector [sector] perished in a terrible cataclysm with that planet.";
$l_log_title["LOG1_DIG_CATACLYSM"] = "<font color=yellow>dig Lost!</font>";
$l_log_text["LOG1_SHIPDIG_CATACLYSM"] = "Your dig [id] on player [name]'s ship [shipname] perished in a terrible cataclysm with that ship.";
$l_log_title["LOG1_SHIPDIG_CATACLYSM"] = "<font color=yellow>dig Lost!</font>";
$l_log_text["LOG1_DIG_TORPS"] = "Your dignitary [id] on planet [planet_name] in sector [sector] built [data] planetary torpedoes!";
$l_log_title["LOG1_DIG_TORPS"] = "<font color=#00FF00>Torpedoes Built!</font>";
$l_log_text["LOG1_DIG_FITS"] = "Your dignitary [id] on planet [planet_name] in sector [sector] built [data] planetary fighters!";
$l_log_title["LOG1_DIG_FITS"] = "<font color=#00FF00>Fighters Built!</font>";

$l_log_text["LOG5_PLANET_BOMBED"] = "[name] ������������� ���� ������� [planet_name] � ������� [sector]. ����������� ������� ������������ [beams] ������� � [torps] ������.  ������: [figs] ������������.";
$l_log_title["LOG5_PLANET_BOMBED"] = "<font color=red>������� ��������������!</font>";


$l_log_text["LOG5_SM_ATTACK"] 	= "Ship Sensors detected an incoming Sector Missile being fired from [sector] by [player]!";
$l_log_title["LOG5_SM_ATTACK"] 	= "<font color=red>INCOMING SECTOR MISSILE DETECTED</font>";
$l_log_text["LOG5_SM_OUTMAN"] 		= "A Sector Missile fired by [player] was spotted warping into the sector and you evaded the attack.";
$l_log_title["LOG5_SM_OUTMAN"] 	= "Sector Missile Evasive action!";
$l_log_text["LOG5_SM_OUTSCAN"] 	= "You detected [player]'s an incoming Sector Missile trying to fix on your ship, but your cloak generators managed to fool the Sector Missiles sensor circuits.";
$l_log_title["LOG5_SM_OUTSCAN"] 	= "Sector Missile Cloak successful!";
$l_log_text["LOG5_SM_EWD"] 		= "You are surprised by [player]'s Sector Missile attack and engage the Emergency Warp Device jumping to an unknown sector.";
$l_log_title["LOG5_SM_EWD"] 		= "Sector Missile Emergency warp!";
$l_log_text["LOG5_SM_EWDFAIL"] 	= "Your sensors detect [player]'s Sector Missile attack and engage the Emergency Warp Device. You hear a strange choking sound coming from the engines room and smell burned circuitry. \"Stupid piece of crap!\", you yell, kicking at the computer. You brace for impact!";
$l_log_title["LOG5_SM_EWDFAIL"] 	= "Sector Missile Emergency warp <font color=red>failed!</font>";
$l_log_text["LOG5_SM_WIN"] 		= "Your ship was attacked by [player] using a Sector Missile. You lost [armor] armor points and [energy] energy units in the attack.";
$l_log_title["LOG5_SM_WIN"] 		= "<font color=yellow>Sector Missile IMPACT!</font>";
$l_log_text["LOG5_SM_LOSE"] 		= "Your ship was destroyed by a Sector Missile from [player].";
$l_log_title["LOG5_SM_LOSE"] 		= "<font color=red>Sector Missile Combat lost!</font>";
$l_log_text["LOG5_CONFISCATION"] 		= "Your ship was confiscated by [player]. Do to excessive attacks on bounty players the [player] has confiscated one of your ships ([ship]).";
$l_log_title["LOG5_CONFISCATION"] 		= "<font color=yellow>Skirmish!</font>";
$l_log_text["LOG5_STORAGE_SUICIDE"] 	= "A stored ship suicided when [player] defeated one of your planets and tried to capture it!";
$l_log_title["LOG5_STORAGE_SUICIDE"] 	= "Stored Ship <font color=red>SUICIDE!</font>";
$l_log_text["LOG5_SURVIVE_PROBE_ATTACK"] 		= "Your ship was attacked by a probe owned by [player] in sector [sector]. You lost [armor] armor points and [energy] energy units in the attack.";
$l_log_title["LOG5_SURVIVE_PROBE_ATTACK"] 		= "<font color=yellow>Probe ATTACK!</font>";
$l_log_text["LOG5_PROBE_ATTACK_FAILED"] 		= "[player] survived an attack by your probe in sector [sector].";
$l_log_title["LOG5_PROBE_ATTACK_FAILED"] 		= "<font color=red>Probe Attack FAILED!</font>";
$l_log_text["LOG5_PROBE_ATTACK_SUCCEEDED"] 		= "Your probe destroyed the ship owned by [player] in sector [sector].";
$l_log_title["LOG5_PROBE_ATTACK_SUCCEEDED"] 		= "<font color=red>Probe Attack Succeeded!</font>";
$l_log_text["LOG5_DESTROYED_PROBE_ATTACK"] 		= "Your ship was destroyed by a probe from [player] in sector [sector].";
$l_log_title["LOG5_DESTROYED_PROBE_ATTACK"] 		= "<font color=red>Probe Attack Lost!</font>";
$l_log_text["LOG5_PLANET_CONFISCATION"] 		= "Your planet was confiscated by [player]. Do to excessive attacks on bounty players the [player] has confiscated one of your planets ([name]) in sector [sector] worth [score] credits.";
$l_log_title["LOG5_PLANET_CONFISCATION"] 		= "<font color=yellow>Planetary Skirmish!</font>";


$l_log_title["LOG0_ADMIN_DBERROR"] 		= "Database Error Occured";
$l_log_title["LOG0_ADMIN_COMBAT"] 		= "Combat Action Result";

$l_log_text["LOG9_PROBE_SCAN_FAIL"]="[name] attempted to scan one of your probes in sector [sector], but failed.";
$l_log_title["LOG9_PROBE_SCAN_FAIL"] 		= "[probe_type] <font color='yellow'>Probe Report</font>";
$l_log_text["LOG9_PROBE_SCAN"]="One of your probes in sector [sector] was scanned by [name].";
$l_log_title["LOG9_PROBE_SCAN"] 		= "[probe_type] <font color='yellow'>Probe Report</font>";
$l_log_text["LOG9_PROBE_ATTACKED"]="One of your probes in sector [sector] was attacked and destroyed by [name].";
$l_log_title["LOG9_PROBE_ATTACKED"] 		= "[probe_type] <font color='yellow'>Probe Destroyed</font>";
$l_log_text["LOG9_PROBE_DETECTED_GATEWAY"]="<font color='#00ff00'>Seeker Probe [probe_id] in sector [sector] detected a Gateway Sector</font>";
$l_log_title["LOG9_PROBE_DETECTED_GATEWAY"] 		= "[probe_type] <font color='yellow'>Seeker Probe Report</font>";

$l_log_text["LOG9_PROBEHUNTER_SUCCEED"]="One of your Probe Hunters has destroyed a [probe_type] owned by [name] in [sector].";
$l_log_title["LOG9_PROBEHUNTER_SUCCEED"] 		= "Probe Hunter destroyed [probe_type]</font>";
$l_log_text["LOG9_PROBEHUNTER_DESTROYED"]="Your [probe_type] in sector [sector] was attacked and destroyed by a Probe Hunter owned by [name].";
$l_log_title["LOG9_PROBEHUNTER_DESTROYED"] 		= "[probe_type] <font color='yellow'>Probe Attacked and Destroyed</font>";
$l_log_text["LOG9_PROBEHUNTER_EXPLODED"]="Your Probe Hunter in sector [sector] was lost when the resulting explosion from its attack on the [probe_type] owned by [name] enveloped it.";
$l_log_title["LOG9_PROBEHUNTER_EXPLODED"] 		= "Probe Hunter Probe <font color='yellow'>Destroyed</font>";

?>
