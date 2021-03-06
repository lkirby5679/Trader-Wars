<?php
$l_log_months 		 = array('Januar','Februar','M�rz','April','Mai','Juni','Juli','August','September','Oktober','November','Dezember');
$l_log_months_short 	 = array('Jan','Feb','Mar','Apr','Mai','Jun','Jul','Aug','Sep','Okt','Nov','Dez');
$l_log_pod 		 = "Gl�cklicherweise hatten Sie eine Rettungskapsel";
$l_log_nopod 		 = "<font color=yellow><b>Sie hatten keine Rettungskapsel.Sie sind gestorben.</b></font>";
$l_log_log 		 = "[Player] Logbuch";
$l_log_start 		 = "Logbuch-Eintrag f�r";
$l_log_end 		 = "Ende des Logbuch-Eintrags f�r";
$l_log_click 		 = "Klick <A HREF=main.php><font color=#00ff00>hier</font></A> um zum Hauptmenu zur�ckzukehren.";
$l_log_select 		 = "W�hlen Sie eine Log:";
$l_log_general 		 = "Haupt-Log";
$l_log_dig 		 = "Dignitary-Log";
$l_log_spy 		 = "Spion-Log";
$l_log_disaster 	 = "Planetenungl�cke-Log";
$l_log_nova 		 = "Nova Ger�te-Log";
$l_log_attack 		 = "Angriffs-Log";
$l_log_scan 		 = "Scan-Log";
$l_log_starv 		 = "Planetenhungers Log";
$l_log_probe 		 = "Sonden-Log";
$l_log_autotrade 	 = "automatisches Handeln Log";
$l_log_combined 	 = "kombinierte Log";

// Log entry data

$l_log_text["LOG_LOGIN"] 	 = "Sie wurden eingeloggt von [ip].";
$l_log_title["LOG_LOGIN"]  = "Eingeloggt";
$l_log_text["LOG_LOGOUT"]  = "Sie wurden ausgeloggt von [ip].";
$l_log_title["LOG_LOGOUT"] = "Ausgeloggt";
$l_log_text["LOG5_ATTACK_OUTMAN"] 		= "[player] wurde in Angriffsposition gesichtet, aber Ihr K�nnen als Pilot und ihren Guten Antriebsaggregaten erlaubten Ihnen dem Feind zu entkommen.";
$l_log_title["LOG5_ATTACK_OUTMAN"] 	= "Ausweichman�ver!";
$l_log_text["LOG5_ATTACK_OUTSCAN"] 	= "Sie sp�rten [player]'s Waffen auf, die versucht haben Ihr Schiff zu fixieren, aber Ihr Unsichtbarkeitsgenerator hat die primitiven Sensoren des Gegners irritiert.";
$l_log_title["LOG5_ATTACK_OUTSCAN"] 	= "Unsichtbarkeit erfolgreich!";
$l_log_text["LOG5_ATTACK_EWD"] 		= "Sie sind von [player]'s tr�gerischer Attacke �berrascht worden. Sie k�nnen die Sprengk�pfe, die auf Sie zufliegen schon riechen, als Sie wie wahnsinnig den Notwarp-Punkt erreichen. Die Welt um Sie herum verschwimmt. F�r eine Millisekunde denken Sie, Sie sind Tod. Als sie nach langer Ruhe ihre Augen �ffnen, sehen Sie, dass sie sicher irgendwohin transportiert wurden. Aber wohin genau? Sie wissen es nicht...";
$l_log_title["LOG5_ATTACK_EWD"] 		= "Notswarp!";
$l_log_text["LOG5_ATTACK_EWDFAIL"] 	= "Ihre Sensoren erkennen [player]'s Schiff in Angriffsposition. \"Lieber in Sicherheit bringen, als draufgehn\", denken Sie, w�hrend Sie den Notwarp-Knopf dr�cken. Sie h�ren einen seltsamen erschreckenden Ton aus Ihrem Triebwerksraum, und Sie riechen eine brennende Schaltung. \"Verdammte Scheisse!\", schreien Sie, w�hrend Sie auf dem Computer herumtrammpeln. Der Computer gibt protestierende Biepser aus, w�hrend Sie sich auch den bevorstehenden Angriff vorbereiten...";
$l_log_title["LOG5_ATTACK_EWDFAIL"] 	= "Notwarp <font color=red>fehlgeschlagen</font>";
$l_log_text["LOG5_ATTACK_LOSE"] 		= "Ihr Schiff wird von [player] angegriffen. Versuchen Sie was Sie k�nnen, aber Sie k�nnen sich selbst nicht vor den �berlegenen Waffen von [player] sch�tzen. Ihr Schiff wurde zerst�rt.";
$l_log_title["LOG5_ATTACK_LOSE"] 		= "<font color=red>Kampf verloren!</font>";
$l_log_text["LOG5_ATTACKED_WIN"] 		= "Ihr Schiff wurde von [player] angegriffen. Sie k�mpfen einige Zeit, dan bricht der Kampf ab. Sie haben verloren. [armor] R�stungspunkt und  [fighters] J�ger sind verloren.";
$l_log_title["LOG5_ATTACKED_WIN"] 		= "<font color=yellow>Verloren!</font>";
$l_log_text["LOG5_HIT_MINES"] 		= "Sie haben [mines] Minen erwischt, w�hrend Sie im Sktor [sector] herumflogen.";
$l_log_title["LOG5_HIT_MINES"] 		= "<font color=yellow>Minenalarm!</font>";
$l_log_text["LOG5_SHIP_DESTROYED_MINES"] 	= "Ihr Schiff wurde von einem Minenfeld in Sktor [sector] zerst�rt. ";
$l_log_title["LOG5_SHIP_DESTROYED_MINES"] 	= "<font color=red>Minenalarm!</font>";
$l_log_text["LOG5_PLANET_DEFEATED_D"] 	= "Ihr Planet [planet_name] im Sektor [sector] wurde erfolgreich gegen [name] verteidigt. Gl�cklicherweise! Die starke Loyalit�t ihrer Bewohner hat den Sieg beg�nstigt. Sie haben sich mutig entschlossen viel eher den Planeten zu zerst�ren, als in die gegnerische H�nde fallen zu lassen. Sie organisieren pr�chtige Begr�bnisse f�r die gefallenen Br�der.";
$l_log_title["LOG5_PLANET_DEFEATED_D"] 	= "<font color=yellow>Planet zerst�rt</font>";
$l_log_text["LOG5_PLANET_DEFEATED"] 	= "Ihr  Planet [planet_name] im Sektor [sector] wurde gegen [name] verteidigt. Die Leute auf dem Planetenen begr�ssen ihren neuen Herrscher. Sie h�ren eine Rede auf FNN: \"Wir sind gl�ckliche diesen alten Sack los zusein!Wir wollen keinen stinkigen Verlierer, der uns nicht besch�tzen kann!\". Sie schw�ren Rache f�r diese Arroganz.";
$l_log_title["LOG5_PLANET_DEFEATED"] 	= "<font color=red>Planet verteidigt!</font>";
$l_log_text["LOG5_PLANET_NOT_DEFEATED"] 	= "Ihr Planet [planet_name] im Sektor [sector] wurde von [name] angegriffen. Die B�rger organisierten eine B�rgerfront, und zerst�rten den Gegener erfolgreich. Sie erbeuteten einige Resourcen: [goods] G�ter, [ore] Erz, [organics] organischer Material and [salvage]% des Werte der Schiffe: [credits] credits.";
$l_log_title["LOG5_PLANET_NOT_DEFEATED"] 	= "Sieg!";
$l_log_title["LOG0_RAW"] 			= "Ank�ndigung";
$l_log_text["LOG5_DEFS_DESTROYED"] 	= "[quantity] [type] wurden im Sektor [sector] zerst�rt.";
$l_log_title["LOG5_DEFS_DESTROYED"] 	= "Sektorverteidigung zerst�rt";
$l_log_text["LOG0_PLANET_EJECT"] 		= "Sie wurden aus dem Planeten in Sektor [sector] geworfen, da [name] das Team verlassen hat.";
$l_log_title["LOG0_PLANET_EJECT"] 		= "Rausgeflogen!";
$l_log_text["LOG0_BADLOGIN"] 		= "Es gab einen Login-Fehlerversuch von [ip].";
$l_log_title["LOG0_BADLOGIN"] 		= "Login fehlgeschlagen";
$l_log_text["LOG6_PLANET_SCAN"] 		= "[name] hat ihren Planeten [planet_name] im Sektor [sector] gescannt.";
$l_log_title["LOG6_PLANET_SCAN"] 		= "Planetenscan";
$l_log_text["LOG6_PLANET_SCAN_FAIL"] 	= "[name] hat versucht Ihren Planeten [planet_name] im Sektor [sector] zu scannen, scheiterte aber.";
$l_log_title["LOG6_PLANET_SCAN_FAIL"] 	= "Planetenscna fehlgeschlagen";
$l_log_text["LOG6_SHIP_SCAN"] 		= "[player] hat ihr Schiff gescnannt.";
$l_log_title["LOG6_SHIP_SCAN"] 		= "Schiffscan";
$l_log_text["LOG6_SHIP_SCAN_FAIL"] 	= "[player] hat versucht ihr Schiff zu scannen, scheiterte aber.";
$l_log_title["LOG6_SHIP_SCAN_FAIL"] 	= "Schiffscan fehlgeschlagen";
$l_log_text["LOG5_KABAL_ATTACK"] 		= "Angriff auf [player]...";
$l_log_title["LOG5_KABAL_ATTACK"] 		= "Angriff";
$l_log_text["LOG7_STARVATION"] 		= "PLaneten [name] in Sektor [sector] kann die Bev�lkerung nicht bestehen bleiben! Es wird mehr organische Material ben�tigt. [starvation] Kolonisten sind verhungert. Colonists started starving on [date].";
$l_log_title["LOG7_STARVATION"] 		= "<font color=yellow>Hungerstod!</font>";
$l_log_title["LOG0_TOW"] 			= "Geschleppt!";
$l_log_text["LOG0_TOW"] 	 = "Your ship has been towed from sector [sector] to sector [newsector] because your average tech level exceeded the limit value of [hull] or you have a ship in storage.";
$l_log_text["LOG5_DEFS_DESTROYED_F"] 	= "Sie haben [fighters] zerst�rt. Sie haben [fighters] Pattrolien in Sektor [sector].";
$l_log_title["LOG5_DEFS_DESTROYED_F"] 	= "J�ger zerst�rt";
$l_log_text["LOG5_DEFS_KABOOM"] 		= "Sie wurden von J�gern im Sektor [sector] zerst�rt. ";
$l_log_title["LOG5_DEFS_KABOOM"] 		= "<font color=red>Schiff zerst�rt!</font>";
$l_log_text["LOG0_HARAKIRI"] 		= "Sie sind m�de diesen Frachtkahn zu befehligen, deshalb haben Sie sich entschieden, dass das Universum ohne diese Rostlaube besser dran ist. Genehmigt von [ip].";
$l_log_title["LOG0_HARAKIRI"] 		= "<font color=red>Selbstzerst�rung!</font>";
$l_log_text["LOG0_TEAM_REJECT"] 		= "[player] hat die Einladung dem Team [teamname] beizutreten ausgeschlagen.";
$l_log_title["LOG0_TEAM_REJECT"] 		= "Einladung abgelehnt!";
$l_log_text["LOG0_TEAM_RENAME"] 		= "Sie haben ihr Team in [team] umgenannt.";
$l_log_title["LOG0_TEAM_RENAME"] 		= "Team umgenannt!";
$l_log_text["LOG0_TEAM_M_RENAME"] 		= "Ihr Temakoordinator hat das Team in [team] umgenannt.";
$l_log_title["LOG0_TEAM_M_RENAME"] 	= "Team umgenannt";
$l_log_text["LOG0_TEAM_KICK"] 		= "Sie wurden aus dem Team [team] herausgeworfen.";
$l_log_title["LOG0_TEAM_KICK"] 		= "Teamrauswurf!";
$l_log_text["LOG0_TEAM_CREATE"] 		= "Sie haben ein neues Team namens [team] erstellt.";
$l_log_title["LOG0_TEAM_CREATE"] 		= "Neues Team erstellt.";
$l_log_text["LOG0_TEAM_LEAVE"] 		= "Sie haben das Team [team] verlassen.";
$l_log_title["LOG0_TEAM_LEAVE"] 		= "Team verlassen";
$l_log_text["LOG0_TEAM_NEWLEAD"] 		= "Sie haben das Team [team] verlassen. Sie haben die Team-F�hrung von [name] abgegeben.";
$l_log_title["LOG0_TEAM_NEWLEAD"] 		= "Team verlassen";
$l_log_text["LOG0_TEAM_LEAD"] 		= "Ihr Teamkoordinator hat entschieden das Team [team] zu verlassen. Sie wurden als sein Nachfolger ernannt.";
$l_log_title["LOG0_TEAM_LEAD"] 		= "Bef�rderung!";
$l_log_text["LOG0_TEAM_JOIN"] 		= "Sie sind dem Team [team] beigetreten.";
$l_log_title["LOG0_TEAM_JOIN"] 		= "Team beigetreten";
$l_log_text["LOG0_TEAM_NEWMEMBER"] 	= "[name] hat dem Beitritt zu [team] zugestimmt. Dies bringt sie einen Schritt zur Herrschaft �ber die Galaxie n�her.";
$l_log_title["LOG0_TEAM_NEWMEMBER"] 	= "Es gibt ein neues Teammitglied!";
$l_log_text["LOG0_TEAM_INVITE"] 		= "Sie werden eingeladen dem Team [team] beizutreten.";
$l_log_title["LOG0_TEAM_INVITE"] 		= "Einladung";
$l_log_text["LOG0_TEAM_NOT_LEAVE"] 	= "[player] hat das Team verlassen.";
$l_log_title["LOG0_TEAM_NOT_LEAVE"] 	= "Team verliert Mitglied";
$l_log_text["LOG0_ADMIN_HARAKIRI"] 	= "[player] hat die Selbstzerst�rung von der Ip [ip] aus eingeleitet.";
$l_log_title["LOG0_ADMIN_HARAKIRI"] 	= "Selbstzerst�rung";
$l_log_text["LOG0_ADMIN_ILLEGVALUE"] 	= "[player] hatte [quantity] [type], mit dem Maximum an Holds von [holds]";
$l_log_title["LOG0_ADMIN_ILLEGVALUE"] 	= "Illegaler Schiffwert";
$l_log_text["LOG0_ADMIN_PLANETDEL"] 	= "[attacker] hat versucht [defender]'s planet im Sektor [sector] einzunehmen. Der Planet wurde stattdessen zerst�rt.";
$l_log_title["LOG0_ADMIN_PLANETDEL"] 	= "Planet zerst�rt";
$l_log_text["LOG0_defense_DEGRADE"] 	= "Sektor-Verteidigungs-J�ger im Sektor [sector] wurden aufgrund mangelder Energie um  [degrade] Prozent ihrer St�rke erniedrigt.";
$l_log_title["LOG0_defense_DEGRADE"] 	= "Sektor-Verteidigung f�llt weiter.";
$l_log_text["LOG5_PLANET_CAPTURED"] 	= "Sie haben einen Planeten von [owner] erobert. Er hatte [cols] Kolonisten und [credits] Credits.";
$l_log_title["LOG5_PLANET_CAPTURED"] 	= "Planet erobert!";
$l_log_text["LOG0_CHEAT_TEAM"] 		= "Der spieler [player] mit der IP-addresse [ip] hat versucht den Team-Kick-cheat anzuwenden. Sein Schiff wurde zerst�rt.";
$l_log_text["LOG0_BOUNTY_CLAIMED"] = "Sie forderten eine Pr�mie von [amount] Credits d�r die Zerst�rung von [bounty_on]'s Schiffes. Die Pr�mie wurde ausgestellt von [placed_by].";
$l_log_title["LOG0_BOUNTY_CLAIMED"] = "Pr�mie gefordert.";
$l_log_text["LOG0_BOUNTY_PAID"] = "Die Pr�mie f�r [bounty_on] wurde ausgezahlt. Die Summe betr�gt [amount] Credits.";
$l_log_text["LOG0_BOUNTY_TAX_PAID"] = "Die Pr�mie f�r [bounty_on] wurde von der F�deration mit [amount] credits besteuert.";
$l_log_title["LOG0_BOUNTY_PAID"] = "Pr�mie bezahlt.";
$l_log_text["LOG0_BOUNTY_CANCELLED"] = "Ihre Pr�mie f�r [bounty_on] mit der Gesamtsumme von [amount] Credits wurde zur�ckerstattet.";
$l_log_title["LOG0_BOUNTY_CANCELLED"] = "Pr�mie zur�ckerstattet.";
$l_log_text["LOG0_BOUNTY_FEDBOUNTY"] = "Die F�deration hat eine Pr�mie von [amount] Credits auf Sie ausgesetzt.";
$l_log_title["LOG0_BOUNTY_FEDBOUNTY"] = "Pr�mie ausgesetzt!";
$l_log_text["LOG0_BOUNTY_ALLIANCEBOUNTY"] = "The Alliance has placed a bounty on you for the amount of [amount] credits.";
$l_log_title["LOG0_BOUNTY_ALLIANCEBOUNTY"] = "Alliance Bounty!";
$l_log_text["LOG0_IGB_TRANSFER1"] = "Der Spieler [name] transferierte [sum] Credits auf Ihr IGB-Konto.";
$l_log_title["LOG0_IGB_TRANSFER1"] = "Credits �bertragen!";
$l_log_text["LOG0_IGB_TRANSFER2"] = "Sie transferierten [sum] Sredits auf Spieler [name]'s IGB-Konto.";
$l_log_title["LOG0_IGB_TRANSFER2"] = "Credits �bertragen!";
$l_log_text["LOG4_PLANET_novaED_D"] 	= "Ihr Planet [planet_name] im Sektor [sector] wurde mit einer Nova Bombe von [name] zerst�rt. Niemand �berlebt. Es sind keine Resourcen �brig.";
$l_log_title["LOG4_PLANET_novaED_D"] 	= "<font color=yellow>Planet mit Nova Bombe zerst�rt</font>";
$l_log_text["LOG4_SHIP_novaED_D"] 	= "Ihr Schiff wurde mit einer Nova Bombe von [name] zerst�rt.";
$l_log_title["LOG4_SHIP_novaED_D"] 	= "<font color=yellow>Schiff mit Nova Bomb zerst�rt</font>";
$l_log_text["LOG2_SPY_FOUND_EMBEZZLER"] 	= "Ihre dignitary-zahl [DIG] des Planeten [PLANET] wurde unterschlagen.  M�glicherweise wollen Sie sie aufgeben.";
$l_log_title["LOG2_SPY_FOUND_EMBEZZLER"] 	= "<font color=yellow>Veruntreuer gefunden!</font>";
$l_log_text["LOG9_PROBE_DETECTED_SHIP"]="<font color=yellow>Ihre Sonde mit der id [id] entdeckte [ship_name], wie es den Sektor [sector] betreten hat.</font>";
$l_log_title["LOG9_PROBE_DETECTED_SHIP"] 		= "Probe Detected Incoming Ship";
$l_log_text["LOG9_PROBE_SCAN_SHIP"]="<font color=yellow>Ihre Sinde mit der id [id] hat das Schiff [ship_name] gescannt, wie es den Sektor [sector] betretten hat<br>H�lle: [hull] Antrieb: [engines] Energie: [power] J�ger: [computer] Sensoren: [sensors] Beams: [beams] Torp Launchers: [torps] R�stung: [armor] Schilde: [shields] Tarnung: [cloak]<br>R�stungspunkt: [armor_pts] J�ger: [fighters] Torpedoes: [avail_torps] Schiffenergie: [energy] Credits: [credits] <br>Minen Deflectoren: [deflectors] Notwarp: [ewd] Rettunsgkapsel: [pod] ECM: [ecm]</font>";
$l_log_title["LOG9_PROBE_SCAN_SHIP"] 		= "Probe Scanned Incoming Ship";
$l_log_text["LOG0_ADMIN_PLANETIND"] 	= "[sector] planet [planetname] ([planetid]) owned by [owner] became independant. Average Tech: [avgtech]";
$l_log_title["LOG0_ADMIN_PLANETIND"] 	= "Planet went independant.";
$l_log_text["LOG0_ADMIN_INDYPURGE"] 	= "Independant planet [planetname] ([planetid]) owned by [owner] in [sector] was purged. Average Tech: [avgtech]";
$l_log_title["LOG0_ADMIN_INDYPURGE"] 	= "Independant Planet Purged.";
$l_log_text["LOG0_ADMIN_NEVEROWNEDPURGE"] 	= "Never Owned planet [planetname] ([planetid]) created on [date] in [sector] was purged. Average Tech: [avgtech]";
$l_log_title["LOG0_ADMIN_NEVEROWNEDPURGE"] 	= "Never Owned Planet Purged.";
$l_log_text["LOG0_TEAM_CANCEL"] 		= "Ihre Einladung f�r das Team [team] wurde zur�ckgezogen.";
$l_log_title["LOG0_TEAM_CANCEL"] 		= "Einladung zur�ckgezogen!";
$l_log_text["LOG10_AUTOTRADE"]="<font color=yellow>Automatisches Handeln f�r [planetname] im Sektor [sector] f�r insgesamt [totalcost] Credits.<br>G�ter: [goodsamount] @ [goodsprice] Credits - Erz: [oreamount] @ [oreprice] Credits - organisches Material: [organicsamount] @ [organicsprice] Credits - Energie: [energyamount] @ [energyprice] Credits - Colonists: [colonistamount] @ [colonistprice] credits<br></font>";
$l_log_title["LOG10_AUTOTRADE"] 		= "Bericht f�r automatisches Handeln";
$l_log_text["LOG10_AUTOTRADE_ABORTED"]="<font color='#00ff00'>Automatisches Handeln f�r [planetname] im Sektor [sector] wurde wegen gegnerischer Sektorverteidigunng im Sektor [destsector] abgebrochen.<br></font>";
$l_log_title["LOG10_AUTOTRADE_ABORTED"] 		= "Bericht f�r automatisches Handeln";

$l_log_text["LOG9_PROBE_DESTROYED"]="<font color='#00ff00'>SEKTORVERTEIDIGUNG i [sector] hat Ihre Sonde zerst�rt.</font>";
$l_log_title["LOG9_PROBE_DESTROYED"] 		= "Sonde zerst�rt!";
$l_log_text["LOG9_PROBE_NOTURNS"]="<font color='#00ff00'>Sie haben nicht gen�gend Truns um die Sonde [probe_id] nach [sector] zu bewegen!</font>";
$l_log_title["LOG9_PROBE_NOTURNS"] 		= "Sondenbericht";
$l_log_text["LOG9_PROBE_INVALIDSECTOR"] = "<font color='#00ff00'>Die Verlegung nach [target_sector] ist nicht erlaubt</font>";
$l_log_title["LOG9_PROBE_INVALIDSECTOR"] 		= "Sondenbericht";
$l_log_text["LOG9_PROBE_DETECTPROBE"]="<font color='#00ff00'>Die Sonde [probe_id] im Sektor [sector] entdeckte [probe_detect]</font>";
$l_log_title["LOG9_PROBE_DETECTPROBE"] 		= "[probe_type] <font color='yellow'>Sondenbericht</font>";
$l_log_text["LOG9_PROBE_DETECTED_GATEWAY"]="<font color='#00ff00'>Seeker Probe [probe_id] in sector [sector] detected a Gateway Sector</font>";
$l_log_title["LOG9_PROBE_DETECTED_GATEWAY"] 		= "[probe_type] <font color='yellow'>Seeker Probe Report</font>";

// added
$l_log_text["LOG5_PLANET_BOMBED"] = "Ihr Planet [planet_name] im Sektor [sector] wurde von [name] bombardiert. Sie haben [beams] Energie und [torps] Torpedos in Ihrer Verteidigung.  Sie haben [figs] J�ger verloren.";
$l_log_title["LOG5_PLANET_BOMBED"] = "<font color=red>Planet bombardiert!</font>";

$l_log_text["LOG1_DIG_PRODUCTION"] = "Ihre dignitary [id] auf dem Planeten [planet_name] im Sector [sector] hat mit der Produktion von Geb�uden begonnen.";
$l_log_title["LOG1_DIG_PRODUCTION"] = "<font color=#00FF00>Geb�udeproduktion begonnen!</font>";
$l_log_text["LOG1_DIG_BIRTHDEC"] = "Ihre dignitary [id] auf dem Planeten [planet_name] im Sektor [sector] hat die Geburtenraten erniedrigt.";
$l_log_title["LOG1_DIG_BIRTHDEC"] = "<font color=#00FF00>Geburtenrate f�llt!</font>";
$l_log_text["LOG1_DIG_BIRTHINC"] = "Ihre dignitary [id] auf dem Planeten [planet_name] im Sektor [sector] erniedrigt die Geburtenrate.";
$l_log_title["LOG1_DIG_BIRTHINC"] = "<font color=#00FF00>Geburtenrate f�llt!</font>";
$l_log_text["LOG1_DIG_SPYHUNT"] = "Ihre dignitary [id] auf dem Planeten [planet_name] im Sektor [sector] hat begonnen nach Spionen auf dem PLaneten zu suchens.";
$l_log_title["LOG1_DIG_SPYHUNT"] = "<font color=#00FF00>Spionen-Jagd!</font>";
$l_log_text["LOG1_DIG_INTEREST"] = "Ihre dignitary [id] auf dem Planeten [planet_name] im Sektor [sector] hat begonnen die Credit-Produktion zu verst�rken.";
$l_log_title["LOG1_DIG_INTEREST"] = "<font color=#00FF00>Interesse an Geb�uden hat begonnen!</font>";
$l_log_text["LOG1_DIG_MONEY"] = "Ihre Dignitary [id] auf dem Planeten [planet_name] produzierte [data] Credits und �bergab sie an Sie!";
$l_log_title["LOG1_DIG_MONEY"] = "<font color=#00FF00>Sie haben frische Credits erhalten!</font>";
$l_log_text["LOG1_DIG_KILLED_SPY"] = "Ihre dignitary entdeckte [name]'s Spion auf ihrem Planet [planet_name] im Sektor [sector]. Der Spion ist nun tod.";
$l_log_title["LOG1_DIG_KILLED_SPY"] = "<font color=yellow>Feindlicher Spion get�tet</font>";
$l_log_text["LOG1_DIG_CATACLYSM"] = "Ihre dig [id] auf dem Planeten [planet_name] im Sektor [sector] ist bei einer schreklichen �berschwemmung auf dem Planetenen umgekommen.";
$l_log_title["LOG1_DIG_CATACLYSM"] = "<font color=yellow>dig verloren!</font>";
$l_log_text["LOG1_SHIPDIG_CATACLYSM"] = "Ihre dig [id] auf [name]'s Schiff [shipname] ist bei einer schrecklichen Katastrophe auf dem Schiff umgekommen.";
$l_log_title["LOG1_SHIPDIG_CATACLYSM"] = "<font color=yellow>dig verloren!</font>";
$l_log_text["LOG1_DIG_TORPS"] = "Ihre dignitary [id] auf dem Planeten [planet_name] im Sektor [sector] baute [data] planetarische Torpedos!";
$l_log_title["LOG1_DIG_TORPS"] = "<font color=#00FF00>Torpedos gebaut!</font>";
$l_log_text["LOG1_DIG_FITS"] = "Ihre dignitary [id] auf dem Planeten [planet_name] im Sektor [sector] baute [data] planetarische J�ger!";
$l_log_title["LOG1_DIG_FITS"] = "<font color=#00FF00>J�ger gebaut!</font>";

$l_log_text["LOG5_PLANET_YOUR_CAPTURED"]   = "Ihr Planet [planet_name] im Sektor [sector] wurde w�hrend der Verteidigung von diesem verdammten [name] eingenommen.";
$l_log_title["LOG5_PLANET_YOUR_CAPTURED"]  = "<font color=red>Planet eingenommern</font>";
$l_log_text["LOG5_STORAGE_EWD"] 		= "Your planet is surprised by [player]'s attack. One of your stored ships made an Emergency Warp to [sector] and landed on planet [planet]";
$l_log_title["LOG5_STORAGE_EWD"] 		= "Stored Ship Emergency warp!";
$l_log_text["LOG5_STORAGE_EWDFAIL"] 	= "A stored ships Emergency Warp Device FAILED!  The stored ship was captured by [player] after they defeated your planet!";
$l_log_title["LOG5_STORAGE_EWDFAIL"] 	= "Stored Ship Emergency warp <font color=red>failed!</font>";
$l_log_text["LOG5_STORAGE_CAPTURED"] 	= "A stored ship was captured by [player] after they defeated one of your planets!";
$l_log_title["LOG5_STORAGE_CAPTURED"] 	= "Stored Ship <font color=red>CAPTURED!</font>";

$l_log_text["LOG2_SPY_NEWSHIP"] = "Sie haben ihren Spion [id] auf [name]'s Schiff [shipname]verloren, weil dieser Spieler ein neues Schiff gekauft hat.";
$l_log_title["LOG2_SPY_NEWSHIP"] = "<font color=yellow>Spion get�tet!</font>";

$l_log_text["LOG2_SPY_SEND_FAIL"] = "[name] hat versucht einen Spion auf Ihren Planeten [planet_name] im Sektor [sector] zu senden, aber Ihre Sensoren entdeckten den Spion. Er ist nun tot.";
$l_log_title["LOG2_SPY_SEND_FAIL"] = "<font color=yellow>Feindlicher Spion get�tet!</font>";

$l_log_text["LOG2_SPY_SABOTAGE"] = "Ihr Spion [id] auf dem Planetenen [planet_name] im Sektor [sector] hat mit der Sabotage begonnen. Die Produktion auf diesem Planeten ist um [data] gefallen.";
$l_log_title["LOG2_SPY_SABOTAGE"] = "<font color=#00FF00>Sabotage begonnen!</font>";

$l_log_text["LOG2_SPY_BIRTH"] = "Ihr Spion [id] auf dem Planeten [planet_name] im Sektor [sector] senkte die Geburtenrate um [data].";
$l_log_title["LOG2_SPY_BIRTH"] = "<font color=#00FF00>Geburterate erniedrigt</font>";

$l_log_text["LOG2_SPY_INTEREST"] = "Ihr Spion [id] auf dem Planetenen [planet_name] im Sektor [sector] hat begonnen Zinsen von [data] einzusammeln.";
$l_log_title["LOG2_SPY_INTEREST"] = "<font color=#00FF00>Zinsen.Diebstahl begonnen!</font>";

$l_log_text["LOG2_SPY_MONEY"] = "Ihr Spion [id] auf dem Planeten [planet_name] im Sektor [sector] hat [data] Credits f�r sie gestohlen!";
$l_log_title["LOG2_SPY_MONEY"] = "<font color=#00FF00>Credits gestohlen!</font>";

$l_log_text["LOG2_SPY_TORPS"] = "Ihr Spion [id] auf dem Planeten [planet_name] im Sektor [sector] zerst�rte [data] planetarische Torpedos!";
$l_log_title["LOG2_SPY_TORPS"] = "<font color=#00FF00>Torpedos zerst�rt!</font>";

$l_log_text["LOG2_SPY_FITS"] = "Ihr Spion [id] auf dem Planeten [planet_name] im Sektor [sector] zerst�rte [data] planetarische J�ger!";
$l_log_title["LOG2_SPY_FITS"] = "<font color=#00FF00>J�ger zerst�rt!</font>";

$l_log_text["LOG2_SPY_CPTURE"] = "Ihr Spion [id] auf dem Planeten [planet_name] im Sektor [sector] hat den Planet eingenommen!!";
$l_log_title["LOG2_SPY_CPTURE"] = "<font color=#00FF00>PLANET EINGENOMMEN!</font>";

$l_log_text["LOG2_SPY_CPTURE_OWNER"] = "[name]'s Spion hat Ihren Planet [planet_name] im Sektor [sector] eingenommen! Es scheint, als w�re es eine weise Idee, den Planeten �fter zu reinigen...";
$l_log_title["LOG2_SPY_CPTURE_OWNER"] = "<font color=red>Planet verloren!</font>";

$l_log_text["LOG2_SPY_KILLED_SPYOWNER"] = "Es gab schon lange keine Nachrichten von ihrem Spion [id] auf dem Planeten [planet_name] im Sektor [sector] - Es scheint, dass sich dieser Idiot nicht gen�gend tarnen konnte, und jetzt get�tet wurde.";
$l_log_title["LOG2_SPY_KILLED_SPYOWNER"] = "<font color=yellow>Spion verloren!</font>";

$l_log_text["LOG2_SPY_KILLED"] = "Ihre Sensoren entdeckten ein Spion von [name] auf ihrem Planeten [planet_name] im Sektor [sector]. Der Spion ist nun get�tet worden.";
$l_log_title["LOG2_SPY_KILLED"] = "<font color=yellow>Feindlicher Spion get�tet!</font>";

$l_log_text["LOG2_SHIPSPY_KILLED"] = "Es gab schon lange keine Nachrichten von ihrem Spion [id] auf dem Planeten [planet_name] im Sektor [sector] - Es scheint, dass sich dieser Idiot nicht gen�gend tarnen konnte, und jetzt get�tet wurde.";
$l_log_title["LOG2_SHIPSPY_KILLED"] = "<font color=yellow>Spion verloren!</font>";

$l_log_text["LOG2_SPY_CATACLYSM"] = "Ihr Spion [id] auf dem Planeten [planet_name] im Sektor [sector] wurde bei einer schrecklichen Katastrophe auf dem Planeten get�tet.";
$l_log_title["LOG2_SPY_CATACLYSM"] = "<font color=yellow>Spion verloren!</font>";

$l_log_text["LOG2_SHIPSPY_CATACLYSM"] = "Ihr Spion [id] auf [name]'s Schiff [shipname] wurde bei einer schreicklichen Katastrophe auf dem Schiff get�tet.";
$l_log_title["LOG2_SHIPSPY_CATACLYSM"] = "<font color=yellow>Spion verloren!</font>";

$l_log_text["LOG2_SPY_TOSHIP"] = "Ihr Spion [id] auf dem Planet [planet_name] im Sektor [sector] infiltrierte [playername]'s Schiff [shipname] und spioniert nun da.";
$l_log_title["LOG2_SPY_TOSHIP"] = "<font color=#00FF00>Spion infiltriert feindliches Schiff!</font>";

$l_log_text["LOG2_SPY_TOPLANET"] = "Ihr Spion [id] auf [playername]'s Schiff [shipname] infiltrierte den Planeten [planet_name] im Sektor [sector] und spioniert nun da.";
$l_log_title["LOG2_SPY_TOPLANET"] = "<font color=#00FF00>Spion infiltriert feindlichen Planeten!</font>";


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
