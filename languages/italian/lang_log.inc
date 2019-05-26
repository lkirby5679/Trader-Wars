<?php
$l_log_months 		 = array('Gennaio','Febbraio','Marzo','Aprile','Maggio','Gugno','Luglio','Agosto','Settembre','Ottobre','Novembre','Dicembre');
$l_log_months_short 	 = array('Gen','Feb','Mar','Apr','Mag','Giu','Lug','Ago','Set','Ott','Nov','Dic');
$l_log_pod 		 = "Fortunatamente avevi una capsula di salvataggio!";
$l_log_nopod 		 = "<font color=yellow><b>Non avevi una capsula di salvataggio, sei rimasto ucciso nella distruzione della tua nave.</b></font>";
$l_log_log 		 = "Diario di [player]";
$l_log_start 		 = "Inizio della registrazione per";
$l_log_end 		 = "Fine della registrazione per";
$l_log_click 		 = "Clicca <A HREF=main.php><font color=#00ff00>qui</font></A> tornare al Menu Principale.";
$l_log_select 		 = "Seleziona un rapporto:";
$l_log_general 		 = "Generale";
$l_log_dig 		 = "Nobili";
$l_log_spy 		 = "Spie";
$l_log_disaster 	 = "Disastri planetari";
$l_log_nova 		 = "Dispositivo Nova";
$l_log_attack 		 = "Attacchi";
$l_log_scan 		 = "Scannerizzazioni";
$l_log_starv 		 = "Inedia";
$l_log_probe 		 = "Sonde";
$l_log_autotrade 	 = "AutoRotte";
$l_log_combined 	 = "Combinato";

// Log entry data

$l_log_text["LOG_LOGIN"] 	 = "Ti sei loggato, dall'indirizzo IP [ip].";
$l_log_title["LOG_LOGIN"]  = "Loggato";
$l_log_text["LOG_LOGOUT"]  = "Ti sei sloggato, dall'indirizzo IP [ip].";
$l_log_title["LOG_LOGOUT"] = "Sloggato";
$l_log_text["LOG5_ATTACK_OUTMAN"] 		= "[player] ti stava intercettando su una rotta d'attacco, ma le tua capacità di pilota e i tuoi motori ti hanno permesso di evadere l'attacco.";
$l_log_title["LOG5_ATTACK_OUTMAN"] 	= "Azione evasiva!";
$l_log_text["LOG5_ATTACK_OUTSCAN"] 	= "Hai individuato le armi di [player] cercare di fissare un bersaglio sulla tua nave, ma il tuo occultamento ti ha protetto dai primitivi sensori della nave di [player].";
$l_log_title["LOG5_ATTACK_OUTSCAN"] 	= "Occultamento avvenuto!";
$l_log_text["LOG5_ATTACK_EWD"] 		= "Sei sorpreso dal vile attacco di [player]. Riesci a vedere i siluri in arrivo, mentre cerchi freneticamente il pulsante peril teletrasporto warp d'emergenza. Il mondo intorno a te sembra sciogliersi in un mosaico di colori e, perun millisecondo, pensi di essere morto. Quando infine riapri gli occhi vedi che sei stato trasportato da qualche altra parte, ma dove non lo sai con esattezza..";
$l_log_title["LOG5_ATTACK_EWD"] 		= "Trasporto Warp d'emergenza!";
$l_log_text["LOG5_ATTACK_EWDFAIL"] 	= "I tuoi sensori individuano [player] su una rotta d'intercettazione.. \"Meglio salvi che spiacenti\", pensi, schiacciando il pulsante per il Trasporto Warp d'emergenza. Ma quando senti uno strano borbottio venire dai motori e un preoccupante odore di circuiti bruciati, gridi \"Stupido pezzo di metallo!\", dando un calcio al computer. Questo emetto un beep di protesta, mentre ti prepari per l'imminente battaglia..";
$l_log_title["LOG5_ATTACK_EWDFAIL"] 	= "Trasporto Warp <font color=red>fallito!</font>";
$l_log_text["LOG5_ATTACK_LOSE"] 		= "La tua nave è attaccata da [player]. Nonostante tu combatta con valore, non puoi nulla contro il superiore arsenale del tuo avevrsario.. La tua nave viene distrutta. ";
$l_log_title["LOG5_ATTACK_LOSE"] 		= "<font color=red>Battaglia persa!</font>";
$l_log_text["LOG5_ATTACKED_WIN"] 		= "La tua nave è attaccata da [player]. Combattete valorosamente entrambi, ma presto la battaglia s'interrompe. Hai perso [armor] punti armatura e [fighters] droni nella schermaglia.";
$l_log_title["LOG5_ATTACKED_WIN"] 		= "<font color=yellow>Schermaglia!</font>";
$l_log_text["LOG5_HIT_MINES"] 		= "Hai colpito [mines] mine entrando nel settore [sector].";
$l_log_title["LOG5_HIT_MINES"] 		= "<font color=yellow>Allerta mine!</font>";
$l_log_text["LOG5_SHIP_DESTROYED_MINES"] 	= "La tua nave è stata distrutta da un campo di mine nel settore [sector]. ";
$l_log_title["LOG5_SHIP_DESTROYED_MINES"] 	= "<font color=red>Allerta mine!</font>";
$l_log_text["LOG5_PLANET_DEFEATED_D"] 	= "Il tuo pianeta [planet_name] nel settore [sector] è stato sconfitto in battaglia da [name]. Fortunatamente la grande lealtà dei tuoi cittadini ha giocato in tuo favore: Hanno preferito distruggere il loro stesso pianeta piuttosto che vederlo cadere in mani nemiche! Magnificienti funerali verranno organizzati in loro memoria.";
$l_log_title["LOG5_PLANET_DEFEATED_D"] 	= "<font color=yellow>Pianeta distrutto</font>";
$l_log_text["LOG5_PLANET_DEFEATED"] 	= "Il tuo pianeta [planet_name] nel settore [sector] è stato sconfitto in battaglia da [name]. Il popolo del pianeta da il benvenuto al suo nuovo leader. Un testimone della FNN riferisce: \"Siamo felici di non dover sottostare più a quella vecchia carcassa! Non vogliamo stupidi perdenti che non riescano nemmeno a proteggerci!\".";
$l_log_title["LOG5_PLANET_DEFEATED"] 	= "<font color=red>Pianeta sconfitto!</font>";
$l_log_text["LOG5_PLANET_NOT_DEFEATED"] 	= "Il tuo pianeta [planet_name] nel settore [sector] è stato attaccato da [name]. I cittadini hanno organizzato una grande difesa, riuscendo a distruggere l'attaccante. In più, dai rottami spaziali dopo la battaglia, hanno recuperato [goods] unità di prodotti, [ore] unità di metallo, [organics] unità di organici e il [salvage]% del valore della nave per un totale di [credits] crediti.";
$l_log_title["LOG5_PLANET_NOT_DEFEATED"] 	= "Vittoria!";
$l_log_title["LOG0_RAW"] 			= "Notizia";
$l_log_text["LOG5_DEFS_DESTROYED"] 	= "[quantity] [type] sono stati distrutti nel settore [sector].";
$l_log_title["LOG5_DEFS_DESTROYED"] 	= "Difese del settore distrutte";
$l_log_text["LOG0_PLANET_EJECT"] 		= "Sei stato cacciato dal pianeta nel settore [sector] poichè [name] ha lasciato la squadra.";
$l_log_title["LOG0_PLANET_EJECT"] 		= "Cacciato!";
$l_log_text["LOG0_BADLOGIN"] 		= "C'è stato un tentativo di Login fallito dall'IP [ip].";
$l_log_title["LOG0_BADLOGIN"] 		= "Login fallito";
$l_log_text["LOG6_PLANET_SCAN"] 		= "[name] ha scannerizzato il tuo pianeta [planet_name] nel settore [sector].";
$l_log_title["LOG6_PLANET_SCAN"] 		= "Scan del pianeta";
$l_log_text["LOG6_PLANET_SCAN_FAIL"] 	= "[name] ha tentato di scannerizzare il tuo pianeta [planet_name] nel settore [sector], ma ha fallito.";
$l_log_title["LOG6_PLANET_SCAN_FAIL"] 	= "Scan del pianeta fallito";
$l_log_text["LOG6_SHIP_SCAN"] 		= "[player] ha scannerizzato la tua nave.";
$l_log_title["LOG6_SHIP_SCAN"] 		= "Scan della nave";
$l_log_text["LOG6_SHIP_SCAN_FAIL"] 	= "[player] ha tentato di scannerizzare la tua nave, ma ha fallito.";
$l_log_title["LOG6_SHIP_SCAN_FAIL"] 	= "Scan della nave fallito";
$l_log_text["LOG5_KABAL_ATTACK"] 		= "Attacco al giocatore [player]..";
$l_log_title["LOG5_KABAL_ATTACK"] 		= "Attacco";
$l_log_text["LOG7_STARVATION"] 		= "Pianeti [name] nel settore [sector] non riesce a sostenere la sua popolazione! Più organici sono necessari. [starvation] coloni sono morti di fame. Colonists started starving on [date].";
$l_log_title["LOG7_STARVATION"] 		= "<font color=yellow>Inedia!</font>";
$l_log_title["LOG0_TOW"] 			= "Mosso!";
$l_log_text["LOG0_TOW"] 	 = "La tua nave è stata trasportata dal settore [sector] al settore [newsector] poichè il livello medio di tecnologia della tua nave supera il limite [hull] o hai una nave in custodia.";
$l_log_text["LOG5_DEFS_DESTROYED_F"] 	= "Hai distrutto [fighters] droni in ricognizione nel settore [sector].";
$l_log_title["LOG5_DEFS_DESTROYED_F"] 	= "droni distrutti";
$l_log_text["LOG5_DEFS_KABOOM"] 		= "Sei stato distrutto da uno squadrone di droni nel settore [sector]. ";
$l_log_title["LOG5_DEFS_KABOOM"] 		= "<font color=red>Nave distrutta!</font>";
$l_log_text["LOG0_HARAKIRI"] 		= "Eri stufo di comandare questo rifiuto spaziale, e pensando che l'universo sarebbe stato meglio senza, hai deciso di innescare la sequenza di autodistruzione! Autorizzato dall'IP [ip].";
$l_log_title["LOG0_HARAKIRI"] 		= "<font color=red>Autodistruzione!</font>";
$l_log_text["LOG0_TEAM_REJECT"] 		= "[player] ha rifiutato il tuo invito a far parte della tua squadra, [teamname].";
$l_log_title["LOG0_TEAM_REJECT"] 		= "Invito rifiutato";
$l_log_text["LOG0_TEAM_RENAME"] 		= "Hai rinominato la tua squadra, che ora si chiama [team].";
$l_log_title["LOG0_TEAM_RENAME"] 		= "Squadra rinominata";
$l_log_text["LOG0_TEAM_M_RENAME"] 		= "Il coordiantore della tua squadra ne ha rinominato il nome in [team].";
$l_log_title["LOG0_TEAM_M_RENAME"] 	= "Squadra rinominata";
$l_log_text["LOG0_TEAM_KICK"] 		= "Sei stato espulso dalla squadra [team].";
$l_log_title["LOG0_TEAM_KICK"] 		= "Espulso dalla squadra!";
$l_log_text["LOG0_TEAM_CREATE"] 		= "Hai creato una nuova squadra, [team].";
$l_log_title["LOG0_TEAM_CREATE"] 		= "Nuova squadra creata";
$l_log_text["LOG0_TEAM_LEAVE"] 		= "Hai lasciato la squadra [team].";
$l_log_title["LOG0_TEAM_LEAVE"] 		= "Squadra lasciata";
$l_log_text["LOG0_TEAM_NEWLEAD"] 		= "Hai lasciato la squadra [team]. Hai ceduto la tua carica di coordinatore a [name].";
$l_log_title["LOG0_TEAM_NEWLEAD"] 		= "Squadra lasciata";
$l_log_text["LOG0_TEAM_LEAD"] 		= "Il coordinatore della tua squadra, [team], ha deciso di lasciarla e tu sei stato scelto per prendere il suo posto.";
$l_log_title["LOG0_TEAM_LEAD"] 		= "Promozione!";
$l_log_text["LOG0_TEAM_JOIN"] 		= "Sei entrato a far parte della squadra [team].";
$l_log_title["LOG0_TEAM_JOIN"] 		= "Unito alla squadra";
$l_log_text["LOG0_TEAM_NEWMEMBER"] 	= "[name] ha accettato di unirsi a [team]. Questo vi porta un passo avanti nella dominazione galattica.";
$l_log_title["LOG0_TEAM_NEWMEMBER"] 	= "Nuovo membro della squadra";
$l_log_text["LOG0_TEAM_INVITE"] 		= "Sei stato invitato a far parte di [team].";
$l_log_title["LOG0_TEAM_INVITE"] 		= "Invito";
$l_log_text["LOG0_TEAM_NOT_LEAVE"] 	= "[player] ha lasciato la tua squadra.";
$l_log_title["LOG0_TEAM_NOT_LEAVE"] 	= "Membro lascia la squadra";
$l_log_text["LOG0_ADMIN_HARAKIRI"] 	= "[player] si è autodistrutto dall'ip [ip].";
$l_log_title["LOG0_ADMIN_HARAKIRI"] 	= "Autodistruzione";
$l_log_text["LOG0_ADMIN_ILLEGVALUE"] 	= "[player] ha [quantity] [type], con una quantità massima di [holds]";
$l_log_title["LOG0_ADMIN_ILLEGVALUE"] 	= "Valore della nave illegale";
$l_log_text["LOG0_ADMIN_PLANETDEL"] 	= "[attacker] ha cercato di catturare il pianeta di [defender] nel settore [sector]. Il pianeta invece è stato distrutto.";
$l_log_title["LOG0_ADMIN_PLANETDEL"] 	= "Pianeta distrutto";
$l_log_text["LOG0_defense_DEGRADE"] 	= "Le difese spaziali del settore [sector] sono calate del [degrade] percento a causa di una quantità d'energia insufficiente.";
$l_log_title["LOG0_defense_DEGRADE"] 	= "Difese del settore diminuite.";
$l_log_text["LOG5_PLANET_CAPTURED"] 	= "Hai catturato un pianeta appartenente a [owner]. Sul pianeta c'erano [cols] coloni e [credits] crediti.";
$l_log_title["LOG5_PLANET_CAPTURED"] 	= "Pianeta catturato!";
$l_log_text["LOG0_CHEAT_TEAM"] 		= "Il giocatore [player] il cui indirizzo ip è [ip] ha cercato di sfruttare il team kick anyone cheat. La sua nave è stata distrutta!.";
$l_log_text["LOG0_BOUNTY_CLAIMED"] = "Hai richiesto la taglia di [amount] crediti per la distruzione della nave apartenente a [bounty_on]. La taglia era stata piazzata da [placed_by].";
$l_log_title["LOG0_BOUNTY_CLAIMED"] = "Taglia richiesta.";
$l_log_text["LOG0_BOUNTY_PAID"] = "La tua taglia su [bounty_on] è stata pagata per l'ammontare di [amount] crediti.";
$l_log_text["LOG0_BOUNTY_TAX_PAID"] = "La taglia della Federazione su [bounty_on] è stata tassata per l'ammontare di [amount] crediti.";
$l_log_title["LOG0_BOUNTY_PAID"] = "Taglia pagata.";
$l_log_text["LOG0_BOUNTY_CANCELLED"] = "La tua taglia su [bounty_on] per l'ammontare di [amount] crediti è stata rimborsata.";
$l_log_title["LOG0_BOUNTY_CANCELLED"] = "Taglia rimborsata.";
$l_log_text["LOG0_BOUNTY_FEDBOUNTY"] = "La Federazione ha piazzato una taglia su di te per l'ammontare di [amount] crediti.";
$l_log_title["LOG0_BOUNTY_FEDBOUNTY"] = "Taglia dalla Federazione!";
$l_log_text["LOG0_BOUNTY_ALLIANCEBOUNTY"] = "The Alliance has placed a bounty on you for the amount of [amount] credits.";
$l_log_title["LOG0_BOUNTY_ALLIANCEBOUNTY"] = "Alliance Bounty!";
$l_log_text["LOG0_IGB_TRANSFER1"] = "[name] ha trasferito [sum] crediti sul tuo acconto IGB.";
$l_log_title["LOG0_IGB_TRANSFER1"] = "Crediti trasferiti";
$l_log_text["LOG0_IGB_TRANSFER2"] = "Hai trasferito [sum] crediti sull'acconto IGB di [name].";
$l_log_title["LOG0_IGB_TRANSFER2"] = "Crediti trasferiti";

$l_log_text["LOG4_PLANET_novaED_D"] 	= "Il tuo pianeta [planet_name] nel settore [sector] è stato distrutto con una Bomba Nova da [name]. Assolutamente niente rimane per ricordare la precedente esistenza del pianeta.";
$l_log_title["LOG4_PLANET_novaED_D"] 	= "<font color=yellow>Pianeta distrutto da una Bomba Nova</font>";
$l_log_text["LOG4_SHIP_novaED_D"] 	= "La tua nave è stata distrutta da una Bomba Nova da [name].";
$l_log_title["LOG4_SHIP_novaED_D"] 	= "<font color=yellow>Nave distrutta da una Bomba Nova</font>";
$l_log_text["LOG2_SPY_FOUND_EMBEZZLER"] 	= "Il Nobile numero [DIG] sul pianeta [PLANET] è stato scoperto a rubare. Dovresti licenziarlo.";
$l_log_title["LOG2_SPY_FOUND_EMBEZZLER"] 	= "<font color=yellow>Ladro trovato!</font>";
$l_log_text["LOG9_PROBE_DETECTED_SHIP"]="<font color=yellow>La tua sonda numero [id] ha individuato la nave [ship_name] entrare nel settore [sector]</font>";
$l_log_title["LOG9_PROBE_DETECTED_SHIP"] 		= "Probe Detected Incoming Ship";
$l_log_text["LOG9_PROBE_SCAN_SHIP"]="<font color=yellow>La tua sonda numero [id] ha scannerizzato la nave [ship_name] entrata nel settore [sector]<br>
Stiva: [hull] Motori: [engines] Batterie: [power] Computer: [fighter] Sensori: [sensors] Laser: [beams] Lanciasiluri: [torps] Armatura: [armor] Scudi: [shields] Occultamento: [cloak]<br>
Punti Armatura: [armor_pts] Droni: [fighters] Siluri: [avail_torps] Energia disponibile: [energy] Crediti: [credits] <br>
Deflettori di mine: [deflectors] Warp d'emergenza: [ewd] Capsule di salvataggio: [pod] ECM: [ecm]</font>";
$l_log_title["LOG9_PROBE_SCAN_SHIP"] 		= "Probe Scanned Incoming Ship";
$l_log_text["LOG0_ADMIN_PLANETIND"] 	= "[sector] planet [planetname] ([planetid]) owned by [owner] became independant. Average Tech: [avgtech]";
$l_log_title["LOG0_ADMIN_PLANETIND"] 	= "Planet went independant.";
$l_log_text["LOG0_ADMIN_INDYPURGE"] 	= "Independant planet [planetname] ([planetid]) owned by [owner] in [sector] was purged. Average Tech: [avgtech]";
$l_log_title["LOG0_ADMIN_INDYPURGE"] 	= "Independant Planet Purged.";
$l_log_text["LOG0_ADMIN_NEVEROWNEDPURGE"] 	= "Never Owned planet [planetname] ([planetid]) created on [date] in [sector] was purged. Average Tech: [avgtech]";
$l_log_title["LOG0_ADMIN_NEVEROWNEDPURGE"] 	= "Never Owned Planet Purged.";
$l_log_text["LOG0_TEAM_CANCEL"] 		= "Il tuo invito a far parte di [team] è stato cancellato.";
$l_log_title["LOG0_TEAM_CANCEL"] 		= "Invito cancellato";
$l_log_text["LOG10_AUTOTRADE"]="<font color=yellow>AutoRotta per [planetname] nel settore [sector] per [totalcost] crediti.<br>Prodotti: [goodsamount] @ [goodsprice] crediti - Metallo: [oreamount] @ [oreprice] crediti - Organici: [organicsamount] @ [organicsprice] crediti - Energia: [energyamount] @ [energyprice] crediti - Colonists: [colonistamount] @ [colonistprice] credits<br></font>";
$l_log_title["LOG10_AUTOTRADE"] 		= "Rapporto AutoRotta";
$l_log_text["LOG10_AUTOTRADE_ABORTED"]="<font color='#00ff00'>AutoRotta per [planetname] nel settore [sector] interrotta a causa di difese spaziali ostili nel settore [destsector].<br></font>";
$l_log_title["LOG10_AUTOTRADE_ABORTED"] 		= "Rapporto AutoRotta";

$l_log_text["LOG9_PROBE_DESTROYED"]="<font color='#00ff00'>Difese Spaziali nel settore [sector] distruggono la tua sonda.</font>";
$l_log_title["LOG9_PROBE_DESTROYED"] 		= "Sonda distrutta";
$l_log_text["LOG9_PROBE_NOTURNS"]="<font color='#00ff00'>Non hai abbastanza turni perchè la tua sonda numero [probe_id] possa muovere verso il settore [sector]</font>";
$l_log_title["LOG9_PROBE_NOTURNS"] 		= "Rapporto sonda";
$l_log_text["LOG9_PROBE_INVALIDSECTOR"] = "<font color='#00ff00'>Non è permesso andare nel settore [target_sector]</font>";
$l_log_title["LOG9_PROBE_INVALIDSECTOR"] 		= "Rapporto sonda";
$l_log_text["LOG9_PROBE_DETECTPROBE"]="<font color='#00ff00'>La sonda numero [probe_id] nel settore [sector] ha scoperto [probe_detect]</font>";
$l_log_title["LOG9_PROBE_DETECTPROBE"] 		= "[probe_type] <font color='yellow'>Rapporto sonda</font>";
$l_log_text["LOG9_PROBE_DETECTED_GATEWAY"]="<font color='#00ff00'>Seeker Probe [probe_id] in sector [sector] detected a Gateway Sector</font>";
$l_log_title["LOG9_PROBE_DETECTED_GATEWAY"] 		= "[probe_type] <font color='yellow'>Seeker Probe Report</font>";

// added
$l_log_text["LOG5_PLANET_BOMBED"] = "Il tuo pianeta [planet_name] nel settore [sector] è stato bombardato da [name]. Hai usato [beams] unità d'energia e [torps] siluri per la tua difesa.  Hai perso [figs] droni.";
$l_log_title["LOG5_PLANET_BOMBED"] = "<font color=red>Pianeta bombardato!</font>";

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

$l_log_text["LOG5_PLANET_YOUR_CAPTURED"]   = "Your planet [planet_name] in sector [sector] was defeated in captured by the wretched [name].";
$l_log_title["LOG5_PLANET_YOUR_CAPTURED"]  = "<font color=red>Planet captured!</font>";
$l_log_text["LOG5_STORAGE_EWD"] 		= "Your planet is surprised by [player]'s attack. One of your stored ships made an Emergency Warp to [sector] and landed on planet [planet]";
$l_log_title["LOG5_STORAGE_EWD"] 		= "Stored Ship Emergency warp!";
$l_log_text["LOG5_STORAGE_EWDFAIL"] 	= "A stored ships Emergency Warp Device FAILED!  The stored ship was captured by [player] after they defeated your planet!";
$l_log_title["LOG5_STORAGE_EWDFAIL"] 	= "Stored Ship Emergency warp <font color=red>failed!</font>";
$l_log_text["LOG5_STORAGE_CAPTURED"] 	= "A stored ship was captured by [player] after they defeated one of your planets!";
$l_log_title["LOG5_STORAGE_CAPTURED"] 	= "Stored Ship <font color=red>CAPTURED!</font>";

$l_log_text["LOG2_SPY_NEWSHIP"] = "You lost your spy [id] on [name]'s ship [shipname], because that player bought a new ship.";
$l_log_title["LOG2_SPY_NEWSHIP"] = "<font color=yellow>Spy Lost!</font>";

$l_log_text["LOG2_SPY_SEND_FAIL"] = "[name] tried to send a spy to your planet [planet_name] in sector [sector], but your Sensors detected the spy and he is killed now.";
$l_log_title["LOG2_SPY_SEND_FAIL"] = "<font color=yellow>Enemy Spy Killed!</font>";

$l_log_text["LOG2_SPY_SABOTAGE"] = "Your spy [id] on planet [planet_name] in sector [sector] starts sabotage. Production is decreased by [data] on that planet.";
$l_log_title["LOG2_SPY_SABOTAGE"] = "<font color=#00FF00>Sabotage Started!</font>";

$l_log_text["LOG2_SPY_BIRTH"] = "Your spy [id] on planet [planet_name] in sector [sector] decreased birthrate by [data] on that planet.";
$l_log_title["LOG2_SPY_BIRTH"] = "<font color=#00FF00>Birthrate Decreased!</font>";

$l_log_text["LOG2_SPY_INTEREST"] = "Your spy [id] on planet [planet_name] in sector [sector] starts collecting planet interest by [data] to you.";
$l_log_title["LOG2_SPY_INTEREST"] = "<font color=#00FF00>Interest Stealing Started!</font>";

$l_log_text["LOG2_SPY_MONEY"] = "Your spy [id] on planet [planet_name] in sector [sector] stole [data] credits to you!";
$l_log_title["LOG2_SPY_MONEY"] = "<font color=#00FF00>Credits Have Stolen!</font>";

$l_log_text["LOG2_SPY_TORPS"] = "Your spy [id] on planet [planet_name] in sector [sector] destroyed [data] planetary torpedoes!";
$l_log_title["LOG2_SPY_TORPS"] = "<font color=#00FF00>Torpedoes Destroyed!</font>";

$l_log_text["LOG2_SPY_FITS"] = "Your spy [id] on planet [planet_name] in sector [sector] destroyed [data] planetary fighters!";
$l_log_title["LOG2_SPY_FITS"] = "<font color=#00FF00>Fighters Destroyed!</font>";

$l_log_text["LOG2_SPY_CPTURE"] = "Your spy [id] on planet [planet_name] in sector [sector] captured that planet!! You are a lucky guy...";
$l_log_title["LOG2_SPY_CPTURE"] = "<font color=#00FF00>PLANET CAPTURED!</font>";

$l_log_text["LOG2_SPY_CPTURE_OWNER"] = "[name]'s spy captured your planet [planet_name] in sector [sector]! It seems that it is wise idea to cleanup your planets more frequently...";
$l_log_title["LOG2_SPY_CPTURE_OWNER"] = "<font color=red>Planet Lost!</font>";

$l_log_text["LOG2_SPY_KILLED_SPYOWNER"] = "There are no messages from your spy [id] on planet [planet_name] in sector [sector] for a long time - it seems that your Cloak device couldn't cover him enough and he is killed.";
$l_log_title["LOG2_SPY_KILLED_SPYOWNER"] = "<font color=yellow>Spy Lost!</font>";

$l_log_text["LOG2_SPY_KILLED"] = "Your Sensors detected a [name]'s spy on your planet [planet_name] in sector [sector]. The spy is killed now.";
$l_log_title["LOG2_SPY_KILLED"] = "<font color=yellow>Enemy Spy Killed!</font>";

$l_log_text["LOG2_SHIPSPY_KILLED"] = "There are no messages from your spy [id] on player [name]'s ship [shipname] for a long time - it seems that your Cloak device couldn't cover him enough and he is killed.";
$l_log_title["LOG2_SHIPSPY_KILLED"] = "<font color=yellow>Spy Lost!</font>";

$l_log_text["LOG2_SPY_CATACLYSM"] = "Your spy [id] on planet [planet_name] in sector [sector] perished in a terrible cataclysm with that planet.";
$l_log_title["LOG2_SPY_CATACLYSM"] = "<font color=yellow>Spy Lost!</font>";

$l_log_text["LOG2_SHIPSPY_CATACLYSM"] = "Your spy [id] on player [name]'s ship [shipname] perished in a terrible cataclysm with that ship.";
$l_log_title["LOG2_SHIPSPY_CATACLYSM"] = "<font color=yellow>Spy Lost!</font>";

$l_log_text["LOG2_SPY_TOSHIP"] = "Your spy [id] from planet [planet_name] in sector [sector] infiltrates a player [playername]'s ship [shipname] and acts now there.";
$l_log_title["LOG2_SPY_TOSHIP"] = "<font color=#00FF00>Spy Infiltrates Enemy Ship!</font>";

$l_log_text["LOG2_SPY_TOPLANET"] = "Your spy [id] from player [playername]'s ship [shipname] infiltrates a planet [planet_name] in sector [sector] and acts now there.";
$l_log_title["LOG2_SPY_TOPLANET"] = "<font color=#00FF00>Spy Infiltrates Enemy Planet!</font>";


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
