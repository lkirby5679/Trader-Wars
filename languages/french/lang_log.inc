<?php
$l_log_months = array('jaanuar','veebruar','m&auml;rts','aprill','mai','juuni','juuli','august','september','oktoober','november','detsember');
$l_log_months_short = array('jaan','veebr','m&auml;rts','apr','mai','juuni','juuli','aug','sept','okt','nov','dets');
$l_log_pod = "&Otilde;nneks oli Sul p&auml;&auml;stekapsel!";
$l_log_nopod = "<font color=yellow><b>Sul ei olnud p&auml;&auml;stekapslit. Sa hukkusid.</b></font>";
$l_log_log = "M&auml;ngija [player] logi";
$l_log_start = "Sissekanded:";
$l_log_end = "Logi l&otilde;pp:";
$l_log_click = "Vajuta <A HREF=main.php><font color=#00ff00>siia</font></A> et minna peamen&uuml;&uuml;sse.";
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

$l_log_text["LOG_LOGIN"] = "Logisid sisse aadressilt [ip].";
$l_log_title["LOG_LOGIN"] = "Sisse logimine";
$l_log_text["LOG_LOGOUT"] = "Logisid v&auml;lja aadressilt [ip].";
$l_log_title["LOG_LOGOUT"] = "V&auml;lja logimine";
$l_log_text["LOG5_ATTACK_OUTMAN"] = "[player] v&otilde;ttis Su laeva sihikule, aga Su piloodioskused ja head mootorid v&otilde;imaldasid Sul vaenlase eest &auml;ra lennata.";
$l_log_title["LOG5_ATTACK_OUTMAN"] = "P&otilde;genemine!";
$l_log_text["LOG5_ATTACK_OUTSCAN"] = "Su sensorid avastasid, et m&auml;ngija [player] relvad &uuml;rituvad Su laevale lukustuda, aga Su radarisegajad suutsid vaenlase primitiivseid sensoreid lollitada.";
$l_log_title["LOG5_ATTACK_OUTSCAN"] = "Segamine &otilde;nnestus!";
$l_log_text["LOG5_ATTACK_EWD"] = "Sind tabas m&auml;ngija [player] reeturlik r&uuml;nnak. Sa j&otilde;udsid veel n&auml;ha vaenlase l&otilde;hkepeade l&auml;henemist, enne kui Sa h&auml;daabi varbi nupule vajutasid. Maailm &auml;hmastus korraks, ja Sa arvasid, et Sa oledki juba surnud. Kui Sa l&otilde;puks ikkagi silmad avasid, n&auml;gid Sa, et Su laev on turvaliselt mujale kantud. Aga kuhu, seda Sa ei tea...";
$l_log_title["LOG5_ATTACK_EWD"] = "H&auml;daabi varp!";
$l_log_text["LOG5_ATTACK_EWDFAIL"] = "Su sensorid avastasid, et m&auml;ngija [player] laev on Su sihikule v&otilde;tnud. \"Parem laev varpida kui p&auml;&auml;stekapsel Sol-i parkida,\" m&otilde;tlesid Sa h&auml;daabi varbi nuppu vajutades. Mootoriruumist kostis imelik heli ja Sa tundsid p&otilde;leva isolatsiooni l&otilde;hna. \"K****i varp v&otilde;i asi!\", karjatasid Sa, pekstes vaest pardaarvutit. Arvuti piiksus suurest pahameelest, kuid Sa olid sunnitud valmistuma l&auml;henevaks v&otilde;itluseks ja ei kuulanud seda enam...";
$l_log_title["LOG5_ATTACK_EWDFAIL"] = "H&auml;daabi varp <font color=red>ei t&ouml;&ouml;tanud!</font>";
$l_log_text["LOG5_ATTACK_LOSE"] = "[player] r&uuml;ndas Su laeva. Proovisid, mis Sa proovisid, Sa ei suutnud t&otilde;rjuda m&auml;ngija [player] superrelvi. Su laev purustati. ";
$l_log_title["LOG5_ATTACK_LOSE"] = "<font color=red>Lahing kaotatud!</font>";
$l_log_text["LOG5_ATTACKED_WIN"] = "[player] r&uuml;ndas Su laeva. P&auml;rast l&uuml;hikest v&otilde;itlust lahingutegevus peatus. Sa kaotasid [armor] soomusepunkti ja [fighters] h&auml;vitajat.";
$l_log_title["LOG5_ATTACKED_WIN"] = "<font color=yellow>T&uuml;hi v&otilde;itlus</font>";
$l_log_text["LOG5_HIT_MINES"] = "Sa p&otilde;rkasid vastu [mines] miini, kui Sa liikusid sektoris [sector].";
$l_log_title["LOG5_HIT_MINES"] = "<font color=yellow>Miinihoiatus!</font>";
$l_log_text["LOG5_SHIP_DESTROYED_MINES"] = "Su laev h&auml;vis miiniv&auml;ljal sektoris [sector]. ";
$l_log_title["LOG5_SHIP_DESTROYED_MINES"] = "<font color=red>Miiniv&auml;li!</font>";
$l_log_text["LOG5_PLANET_DEFEATED_D"] = "[name] alistas Su planeedi [planet_name] sektoris [sector]. &Otilde;nneks olid sealsed elanikud Sulle nii lojaalsed, et otsustasid ennast pigem koos planeediga h&auml;vitada kui et langeda sellise j&otilde;hkardi meelevalda. Sa organiseerisid suure matuseteenistuse, et m&auml;lestada neid vapraid inimesi, kes end koos planeediga ohverdasid.";
$l_log_title["LOG5_PLANET_DEFEATED_D"] = "<font color=yellow>Planeet h&auml;vitatud!</font>";
$l_log_text["LOG5_PLANET_DEFEATED"] = "Nurjatu [name] alistas Su planeedi [planet_name] sektoris [sector]. Planeedi elanikud lausa tervitasid oma uut valitsejat! Sa kuulsid FNN teadet: \"Saime ometi l&otilde;puks sellest vanast tolast lahti! Meile ei meeldi valitsejad, kes meid kaitsta ei suuda!\". Sa vandusid, et nad veel maksavad oma jultumuse eest...";
$l_log_title["LOG5_PLANET_DEFEATED"] = "<font color=red>Planeet alistatud!</font>";
$l_log_text["LOG5_PLANET_NOT_DEFEATED"] = "[name] r&uuml;ndas Su planeeti [planet_name] sektoris [sector]. Planeedi elanikud osutasid sissetungijale ennast&uuml;letavat vastupanu ja suutsid m&auml;ngija [name] laeva h&auml;vitada. Rusudest &otilde;nnestus neil isegi midagi k&auml;tte saada : [goods] tarbekaupa, [ore] maaki, [organics] orgaanikat ja [salvage]% laevast v&auml;&auml;rtusega [credits] raha.";
$l_log_title["LOG5_PLANET_NOT_DEFEATED"] = "V&otilde;it!";
$l_log_title["LOG0_RAW"] = "Teade:";
$l_log_text["LOG5_DEFS_DESTROYED"] = "[quantity] [type] purustati sektoris [sector].";
$l_log_title["LOG5_DEFS_DESTROYED"] = "Sektori kaitsed purustatud";
$l_log_text["LOG0_PLANET_EJECT"] = "Sind sunniti sektoris [sector] planeedilt lahkuma, sest [name] lahkus liidust.";
$l_log_title["LOG0_PLANET_EJECT"] = "V&auml;lja visatud!";
$l_log_text["LOG0_BADLOGIN"] = "Viga sisse logimisel aadressilt [ip].";
$l_log_title["LOG0_BADLOGIN"] = "Viga sisse logimisel";
$l_log_text["LOG6_PLANET_SCAN"] = "[name] skaneeris Su planeeti [planet_name] sektoris [sector].";
$l_log_title["LOG6_PLANET_SCAN"] = "Planeet skaneeritud";
$l_log_text["LOG6_PLANET_SCAN_FAIL"] = "[name] &uuml;ritas skaneerida Su planeeti [planet_name] sektoris [sector], aga ei saanud midagi teada.";
$l_log_title["LOG6_PLANET_SCAN_FAIL"] = "Planeeti &uuml;ritati skaneerida";
$l_log_text["LOG6_SHIP_SCAN"] = "[player] skaneeris Su laeva.";
$l_log_title["LOG6_SHIP_SCAN"] = "Laev skaneeritud";
$l_log_text["LOG6_SHIP_SCAN_FAIL"] = "[player] &uuml;ritas skaneerida Su laeva, aga ei saanud midagi teada.";
$l_log_title["LOG6_SHIP_SCAN_FAIL"] = "Laeva &uuml;ritati skaneerida";
$l_log_text["LOG5_KABAL_ATTACK"] = "R&uuml;ndan m&auml;ngijat [player]...";
$l_log_title["LOG5_KABAL_ATTACK"] = "R&uuml;nnak";
$l_log_text["LOG7_STARVATION"] = "Planeet [name] sektoris [sector] ei suuda oma elanikkonda toita! Vajatakse rohkem orgaanikat. [starvation] kolonisti suri n&auml;lga. Colonists started starving on [date].";
$l_log_title["LOG7_STARVATION"] = "<font color=yellow>N&auml;ljah&auml;da!</font>";
$l_log_title["LOG0_TOW"] = "V&auml;lja t&otilde;stetud!";
$l_log_text["LOG0_TOW"] 	 = "Your ship has been towed from sector [sector] to sector [newsector] because your average tech level exceeded the limit value of [hull] or you have a ship in storage.";
$l_log_text["LOG5_DEFS_DESTROYED_F"] = "Sa purustasid [fighters] h&auml;vitajat sektoris [sector].";
$l_log_title["LOG5_DEFS_DESTROYED_F"] = "H&auml;vitajad purustatud";
$l_log_text["LOG5_DEFS_KABOOM"] = "H&auml;vitajad purustasid Su laeva sektoris [sector]. ";
$l_log_title["LOG5_DEFS_KABOOM"] = "<font color=red>Laev purustatud!</font>";
$l_log_text["LOG0_HARAKIRI"] = "Sa t&uuml;dinesid sellest m&auml;ngust ja leidsid, et galaktika n&auml;eb ilma Sinuta parem v&auml;lja. Seega - Sa h&auml;vitasid oma laeva. Kinnitatud aadressilt [ip].";
$l_log_title["LOG0_HARAKIRI"] = "<font color=red>Eneseh&auml;vitus!</font>";
$l_log_text["LOG0_TEAM_REJECT"] = "[player] keeldus Su liiduga [teamname] &uuml;hinemast.";
$l_log_title["LOG0_TEAM_REJECT"] = "Kutse tagasi l&uuml;katud";
$l_log_text["LOG0_TEAM_RENAME"] = "Sa nimetasid oma liidu &uuml;mber. Uueks nimeks sai [team].";
$l_log_title["LOG0_TEAM_RENAME"] = "Liit &uuml;mber nimetatud";
$l_log_text["LOG0_TEAM_M_RENAME"] = "Sinu liidu koordinaator nimetas liidu &uuml;mber. Uueks nimeks sai [team].";
$l_log_title["LOG0_TEAM_M_RENAME"] = "Liit &uuml;mber nimetatud";
$l_log_text["LOG0_TEAM_KICK"] = "Sind visati liidust [team] v&auml;lja.";
$l_log_title["LOG0_TEAM_KICK"] = "Liidust v&auml;lja visatud!";
$l_log_text["LOG0_TEAM_CREATE"] = "Sa oled loonud uue liidu [team].";
$l_log_title["LOG0_TEAM_CREATE"] = "Uus liit loodud";
$l_log_text["LOG0_TEAM_LEAVE"] = "Sa oled lahkunud liidust [team].";
$l_log_title["LOG0_TEAM_LEAVE"] = "Liidust lahkunud";
$l_log_text["LOG0_TEAM_NEWLEAD"] = "Sa oled lahkunud liidust [team]. Sa andsid koordinaatori vastutusrikka rolli &uuml;le m&auml;ngijale [name].";
$l_log_title["LOG0_TEAM_NEWLEAD"] = "Liidust lahkunud";
$l_log_text["LOG0_TEAM_LEAD"] = "Su liidu [team] koordinaator otsustas liidust lahkuda. Sind on m&auml;&auml;ratud tema vastutusrikkale ametikohale.";
$l_log_title["LOG0_TEAM_LEAD"] = "Ametik&otilde;rgendus!";
$l_log_text["LOG0_TEAM_JOIN"] = "Sa &uuml;hinesid liiduga [team].";
$l_log_title["LOG0_TEAM_JOIN"] = "&Uuml;hinenud liiduga";
$l_log_text["LOG0_TEAM_NEWMEMBER"] = "[name] n&otilde;ustus &uuml;hinema liiduga [team]. J&auml;lle &uuml;ks kivi galaktika &uuml;lemv&otilde;imu m&uuml;&uuml;ris!";
$l_log_title["LOG0_TEAM_NEWMEMBER"] = "Uus liige";
$l_log_text["LOG0_TEAM_INVITE"] = "Sind on kutsutud &uuml;hinema liiduga [team].";
$l_log_title["LOG0_TEAM_INVITE"] = "Kutse";
$l_log_text["LOG0_TEAM_NOT_LEAVE"] = "[player] lahkus Su liidust.";
$l_log_title["LOG0_TEAM_NOT_LEAVE"] = "Liit kaotas &uuml;he liikme";
$l_log_text["LOG0_ADMIN_HARAKIRI"] = "[player] tegi aadressilt [ip] eneseh&auml;vituse.";
$l_log_title["LOG0_ADMIN_HARAKIRI"] = "Eneseh&auml;vitus";
$l_log_text["LOG0_ADMIN_ILLEGVALUE"] = "M&auml;ngijal [player] oli [quantity] [type], maksimaalselt suutis ta kanda [holds].";
$l_log_title["LOG0_ADMIN_ILLEGVALUE"] = "Lubamatu kogus laeval";
$l_log_text["LOG0_ADMIN_PLANETDEL"] = "[attacker] &uuml;ritas vallutada m&auml;ngija [defender] planeeti sektoris [sector]. Elanikud h&auml;vitasid planeedi.";
$l_log_title["LOG0_ADMIN_PLANETDEL"] = "Planeet h&auml;vitatud";
$l_log_text["LOG0_defense_DEGRADE"] = "Sektori kaitse h&auml;vitajad sektoris [sector] v&auml;henesid [degrade] protsenti energianappuse t&otilde;ttu.";
$l_log_title["LOG0_defense_DEGRADE"] = "<font color=yellow>Sektori kaitseid v&auml;hem!</font>";
$l_log_text["LOG5_PLANET_CAPTURED"] = "Sa alistasid planeedi, mille omanik oli [owner]. Sellel oli [cols] kolonisti ja [credits] raha.";
$l_log_title["LOG5_PLANET_CAPTURED"] = "Planeet alistatud!";
$l_log_text["LOG0_CHEAT_TEAM"] = "M&auml;ngija [player] IP-aadressilt [ip] &uuml;ritas kedagi v&otilde;&otilde;rast liidust v&auml;lja visata. Tema laev h&auml;vitati!";
$l_log_text["LOG0_BOUNTY_CLAIMED"] = "Sa said k&auml;tte [amount] raha suuruse pearaha, kuna purustasid m&auml;ngija [bounty_on] laeva. Pearaha oli v&auml;lja pannud [placed_by].";
$l_log_title["LOG0_BOUNTY_CLAIMED"] = "Pearaha k&auml;tte saadud";
$l_log_text["LOG0_BOUNTY_PAID"] = "Su pearaha m&auml;ngija [bounty_on] eest on summas [amount] v&auml;lja makstud.";
$l_log_text["LOG0_BOUNTY_TAX_PAID"] = "The Fedration bounty on [bounty_on] has been taxed for the amount of [amount] credits.";
$l_log_title["LOG0_BOUNTY_PAID"] = "Pearaha v&auml;lja makstud";
$l_log_text["LOG0_BOUNTY_CANCELLED"] = "Su pearaha m&auml;ngija [bounty_on] eest summas [amount] raha on Sulle tagastatud.";
$l_log_title["LOG0_BOUNTY_CANCELLED"] = "Pearaha tagasi makstud";
$l_log_text["LOG0_BOUNTY_FEDBOUNTY"] = "F&ouml;deratsioon on Su laeva eest [amount] suuruse pearaha v&auml;lja pannud.";
$l_log_title["LOG0_BOUNTY_FEDBOUNTY"] = "F&ouml;deratsiooni pearaha!";
$l_log_text["LOG0_BOUNTY_ALLIANCEBOUNTY"] = "The Alliance has placed a bounty on you for the amount of [amount] credits.";
$l_log_title["LOG0_BOUNTY_ALLIANCEBOUNTY"] = "Alliance Bounty!";
$l_log_text["LOG0_ADMIN_PLANETIND"] 	= "[sector] planet [planetname] ([planetid]) owned by [owner] became independant. Average Tech: [avgtech]";
$l_log_title["LOG0_ADMIN_PLANETIND"] 	= "Planet went independant.";
$l_log_text["LOG0_ADMIN_INDYPURGE"] 	= "Independant planet [planetname] ([planetid]) owned by [owner] in [sector] was purged. Average Tech: [avgtech]";
$l_log_title["LOG0_ADMIN_INDYPURGE"] 	= "Independant Planet Purged.";
$l_log_text["LOG0_ADMIN_NEVEROWNEDPURGE"] 	= "Never Owned planet [planetname] ([planetid]) created on [date] in [sector] was purged. Average Tech: [avgtech]";
$l_log_title["LOG0_ADMIN_NEVEROWNEDPURGE"] 	= "Never Owned Planet Purged.";

$l_log_text["LOG0_IGB_TRANSFER1"] = "M&auml;ngija [name] kandis Su pangakontole üle [sum] raha.";
$l_log_title["LOG0_IGB_TRANSFER1"] = "Raha &uuml;le kantud";
$l_log_text["LOG0_IGB_TRANSFER2"] = "Sa kandsid m&auml;ngija [name] pangakontole [sum] raha.";
$l_log_title["LOG0_IGB_TRANSFER2"] = "Raha &uuml;le kantud";

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
$l_log_text["LOG9_PROBE_DETECTED_GATEWAY"]="<font color='#00ff00'>Seeker Probe [probe_id] in sector [sector] detected a Gateway Sector</font>";
$l_log_title["LOG9_PROBE_DETECTED_GATEWAY"] 		= "[probe_type] <font color='yellow'>Seeker Probe Report</font>";

// added

$l_log_text["LOG2_SPY_NEWSHIP"] = "Vous avez perdu votre espion [id] sur le vaissau [shipname] appartenant à [name], parce que le joueur a acheter un nouveau vaissau.";
$l_log_title["LOG2_SPY_NEWSHIP"] = "<font color=yellow>Espion perdu!</font>";

$l_log_text["LOG2_SPY_SEND_FAIL"] = "[name] a essayer d'envoyer un espion sur votre planète [planet_name] dans le secteur [sector], mais vos détecteur l'on détecter et maintenant il est mort.";
$l_log_title["LOG2_SPY_SEND_FAIL"] = "<font color=yellow>Espion enemi tuer!</font>";

$l_log_text["LOG2_SPY_SABOTAGE"] = "Votre espion [id] sur la planète [planet_name] dans le secteur [sector] a comencer le sabotage. La production décroit par [data] sur cette planète.";
$l_log_title["LOG2_SPY_SABOTAGE"] = "<font color=#00FF00>Sabotage commencer!</font>";

$l_log_text["LOG2_SPY_BIRTH"] = "Votre espion [id] sur la planète [planet_name] dans le secteur [sector] a comencer à réduire les naisance de [data] sur cette planète.";
$l_log_title["LOG2_SPY_BIRTH"] = "<font color=#00FF00>Réduction des naissances!</font>";

$l_log_text["LOG2_SPY_INTEREST"] = "Votre espion [id] sur la planète [planet_name] dans le secteur [sector] a comencer a colecter les intérets de la planète de [data] pour vous.";
$l_log_title["LOG2_SPY_INTEREST"] = "<font color=#00FF00>Vols des intérets!</font>";

$l_log_text["LOG2_SPY_MONEY"] = "Votre espion [id] sur la planète [planet_name] dans le secteur [sector] a voler [data] crédits pour vous!";
$l_log_title["LOG2_SPY_MONEY"] = "<font color=#00FF00>Crédits volés!</font>";

$l_log_text["LOG2_SPY_TORPS"] = "Votre espion [id] sur la planète [planet_name] dans le secteur [sector] a détruit [data] torpies de la planète!";
$l_log_title["LOG2_SPY_TORPS"] = "<font color=#00FF00>Torpilles détruites!</font>";

$l_log_text["LOG2_SPY_FITS"] = "Votre espion [id] sur la planète [planet_name] dans le secteur [sector] a détruit [data] intercepteurs de la planète!";
$l_log_title["LOG2_SPY_FITS"] = "<font color=#00FF00>Intercepteurs détruits!</font>";

$l_log_text["LOG2_SPY_CPTURE"] = "Votre espion [id] sur la planète [planet_name] dans le secteur [sector] a capturer cette planète pour vous!! Vous êtes content de lui...";
$l_log_title["LOG2_SPY_CPTURE"] = "<font color=#00FF00>planète CAPTUREE!</font>";

$l_log_text["LOG2_SPY_CPTURE_OWNER"] = "Un espion de [name] a capturer votre planète [planet_name] dans le secteur [sector]! Il pense que ce sera plus facile de récuperer vos planète plus fréquement...";
$l_log_title["LOG2_SPY_CPTURE_OWNER"] = "<font color=red>Planète perdue!</font>";

$l_log_text["LOG2_SPY_KILLED_SPYOWNER"] = "Vous n'avez pas reçu de message de votre espion [id] sur la planète [planet_name] dans le secteur [sector] depuis un moment - Vous pensez que votre camouflage n'as pas été suffisant et qu'il a été tuer.";
$l_log_title["LOG2_SPY_KILLED_SPYOWNER"] = "<font color=yellow>Espion perdu!</font>";

$l_log_text["LOG2_SPY_KILLED"] = "Vos détecteurs ont détecter un espion à [name] sur votre planète [planet_name] dans le secteur [sector]. L'espion et mort maintenant.";
$l_log_title["LOG2_SPY_KILLED"] = "<font color=yellow>Enemy Spy Killed!</font>";

$l_log_text["LOG2_SHIPSPY_KILLED"] = "Vous n'avez pas reçu de message de votre espion [id] sur le vaissau [shipname] du joueur [name] depuis un moment - Vous pensez que votre camouflage n'as pas été suffisant et qu'il a été tuer.";
$l_log_title["LOG2_SHIPSPY_KILLED"] = "<font color=yellow>Espion perdu!</font>";

$l_log_text["LOG2_SPY_CATACLYSM"] = "Votre espion [id] sur la planète [planet_name] dans le secteur [sector] est mort dans un terrible cataclisme avec cette planète.";
$l_log_title["LOG2_SPY_CATACLYSM"] = "<font color=yellow>Espion perdu!</font>";

$l_log_text["LOG2_SHIPSPY_CATACLYSM"] = "Votre espion [id] sur le vaissau [shipname] du joueur [name] est mort dans un terrible cataclisme avec ce vaissau.";
$l_log_title["LOG2_SHIPSPY_CATACLYSM"] = "<font color=yellow>Spy Lost!</font>";

$l_log_text["LOG2_SPY_TOSHIP"] = "Votre espion [id] de la planète [planet_name] dans le secteur [sector] a infiltrer le vaissau [shipname] du joueur [playername] et agit maintenant là.";
$l_log_title["LOG2_SPY_TOSHIP"] = "<font color=#00FF00>Infiltration d'un vaissau enemi!</font>";

$l_log_text["LOG2_SPY_TOPLANET"] = "Votre espion [id] sur le vaissau [shipname] de [playername] a infiltrer la planète [planet_name] dans le secteur [sector] et agit maintenant là.";
$l_log_title["LOG2_SPY_TOPLANET"] = "<font color=#00FF00>Infiltration d'une planète enemie!</font>";

$l_log_text["LOG5_PLANET_YOUR_CAPTURED"]   = "Votre planète [planet_name] dans le secteur [sector] a été vaincue par [name].";
$l_log_title["LOG5_PLANET_YOUR_CAPTURED"]  = "<font color=red>Planète capturée!</font>";
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

$l_log_text["LOG5_PLANET_BOMBED"] = "Votre planète [planet_name] dans le secteur [sector] a été bombardée par [name]. vous utilisez [beams] énergie et [torps] torpille pour votre défence.  Vous avez perdu [figs] intercepteurs.";
$l_log_title["LOG5_PLANET_BOMBED"] = "<font color=red>planète bombardée!</font>";


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
$l_log_text["LOG9_PROBEHUNTER_SUCCEED"]="One of your Probe Hunters has destroyed a [probe_type] owned by [name] in [sector].";
$l_log_title["LOG9_PROBEHUNTER_SUCCEED"] 		= "Probe Hunter destroyed [probe_type]</font>";
$l_log_text["LOG9_PROBEHUNTER_DESTROYED"]="Your [probe_type] in sector [sector] was attacked and destroyed by a Probe Hunter owned by [name].";
$l_log_title["LOG9_PROBEHUNTER_DESTROYED"] 		= "[probe_type] <font color='yellow'>Probe Attacked and Destroyed</font>";
$l_log_text["LOG9_PROBEHUNTER_EXPLODED"]="Your Probe Hunter in sector [sector] was lost when the resulting explosion from its attack on the [probe_type] owned by [name] enveloped it.";
$l_log_title["LOG9_PROBEHUNTER_EXPLODED"] 		= "Probe Hunter Probe <font color='yellow'>Destroyed</font>";

?>
