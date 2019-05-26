<?php
$l_log_months 		 = array('Enero','Febrero','Marzo','Abril','Mayo','Junio','Julio','Agosto','Septiembre','Octubre','Noviembre','Diciembre');
$l_log_months_short 	 = array('Ene','Feb','Mar','Abr','May','Jun','Jul','Ago','Sep','Oct','Nov','Dic');
$l_log_pod 		 = "¡Afortunadamente tienes una cápsula de escape!";
$l_log_nopod 		 = "<font color=yellow><b>No tienes cápsula de escape, has muerto.</b></font>";
$l_log_log 		 = "Registro de [player]";
$l_log_start 		 = "Registro de";
$l_log_end 		 = "Final del registro de";
$l_log_click 		 = "Haz clic <A HREF=main.php><font color=#00ff00>aquí</font></A> para volver al menú principal.";
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

$l_log_text["LOG_LOGIN"] 	 = "Te has conectado desde [ip].";
$l_log_title["LOG_LOGIN"]  = "Conectado";
$l_log_text["LOG_LOGOUT"]  = "Te has desconectado desde [ip].";
$l_log_title["LOG_LOGOUT"] = "Desconectado";
$l_log_text["LOG5_ATTACK_OUTMAN"] 		= "[player] fue descubierto a punto de atacarte, pero tus increible habilidad como piloto y unos buenos motores te permitieron esquivar al enemigo.";
$l_log_title["LOG5_ATTACK_OUTMAN"] 	= "¡Acción evasiva!";
$l_log_text["LOG5_ATTACK_OUTSCAN"] 	= "Detectaste las armas de [player] apuntándote, pero tus generadores de camuflaje consiguieron engañar a los poco avanzados sensores del enemigo.";
$l_log_title["LOG5_ATTACK_OUTSCAN"] 	= "¡Funcionó el camuflaje!";
$l_log_text["LOG5_ATTACK_EWD"] 		= "Has sido sorprendido por el traicionero ataque de [player]. Puedes ver las puntas de combate de los torpedos, mientras llegas fenéticamente al botón de de salto de emergencia. Todo a tu alrededor se vuelve borroso, por un milisegundo, crees estar muerto. Cuando finalmente abres los ojos, ves que fuiste transportado de forma segura a algún sitio. Pero dónde, no lo sabes...";
$l_log_title["LOG5_ATTACK_EWD"] 		= "¡Salto de Emergencia!";
$l_log_text["LOG5_ATTACK_EWDFAIL"] 	= "Tus sensores detectaron a la nave de [player] intentando atacarte. \"Más vale salvar el pellejo que lamentarlo\", piensas, apretando el botón de salto de emergencia. Entonces escuchas un extraño sonido viniendo de la sala de motores y hueles a circuito quemado. \"Menuda cafetera!\", gritas, golpeando la computadora. La computadora lanza unos beeps de protesta mientras te preparas para la batalla que se avecina...";
$l_log_title["LOG5_ATTACK_EWDFAIL"] 	= "Salto de Emergencia ... <font color=red>¡fallido!</font>";
$l_log_text["LOG5_ATTACK_LOSE"] 		= "Tu nave está siendo atacada por [player]. Lo intentas con todas tus fuerzas, pero no puedes defenderte del superior armamento de [player]. Tu nave es destruida. ";
$l_log_title["LOG5_ATTACK_LOSE"] 		= "<font color=red>¡Combate perdido!</font>";
$l_log_text["LOG5_ATTACKED_WIN"] 		= "Tu nave fue atacada por [player]. Luchas durante un rato, y entonces la lucha cesa. Perdiste [armor] puntos de blindaje y [fighters] cazas en la escaramuza.";
$l_log_title["LOG5_ATTACKED_WIN"] 		= "<font color=yellow>¡Escaramuza!</font>";
$l_log_text["LOG5_HIT_MINES"] 		= "Golpeaste [mines] minas al dirigirte al sector [sector].";
$l_log_title["LOG5_HIT_MINES"] 		= "<font color=yellow>¡Alerta, minas!</font>";
$l_log_text["LOG5_SHIP_DESTROYED_MINES"] 	= "Tu nave fue destruida por un campo de minas en el sector [sector]. ";
$l_log_title["LOG5_SHIP_DESTROYED_MINES"] 	= "<font color=red>¡Alerta, minas!</font>";
$l_log_text["LOG5_PLANET_DEFEATED_D"] 	= "Tu planeta [planet_name] en el sector [sector] fue vencido en batalla por [name]. Afortunadamente, la fuerte lealtad de tus ciudadanos jugó a tu favor. Han elegido valientemente destruir el planeta antes de verlo en manos enemigas. Organizas unos majestusos funerales en memoria de tan leal gente.";
$l_log_title["LOG5_PLANET_DEFEATED_D"] 	= "<font color=yellow>Planeta destruido</font>";
$l_log_text["LOG5_PLANET_DEFEATED"] 	= "Tu planeta [planet_name] en el sector [sector] fue vencido en batalla por el canalla [name]. Los colonos del planeta dan la bienvenida al nuevo gobernante. Escuchas un testimonio en FNN : \"¡Estamos contentos de librarnos de ese tonto! ¡No queremos a un apestoso perdedor que no sepa protegernos!\". Juras hacerles pagar por su arrogancia.";
$l_log_title["LOG5_PLANET_DEFEATED"] 	= "<font color=red>¡Planeta vencido!</font>";
$l_log_text["LOG5_PLANET_NOT_DEFEATED"] 	= "Tu planeta [planet_name] en el sector [sector] fue atacado por [name]. Sin embargo los ciudadanos organizaron una valerosa defensa, y consiguieron destruir al oponente. Salvaron unos cuantos recursos de entre los restos espaciales: [goods] en bienes, [ore] de minerales, [organics] de alimentos y el [salvage]% de la nave valorado en [credits] créditos.";
$l_log_title["LOG5_PLANET_NOT_DEFEATED"] 	= "¡Victoria!";
$l_log_title["LOG0_RAW"] 			= "Noticia";
$l_log_text["LOG5_DEFS_DESTROYED"] 	= "[quantity] [type] fueron destruidos en el sector [sector].";
$l_log_title["LOG5_DEFS_DESTROYED"] 	= "Defensas de sector destruidas";
$l_log_text["LOG0_PLANET_EJECT"] 		= "Has sido expulsado del planeta en el sector [sector] porque [name] dejó el equipo.";
$l_log_title["LOG0_PLANET_EJECT"] 		= "¡Expulsado!";
$l_log_text["LOG0_BADLOGIN"] 		= "Ha habido un intento fallido de conexión desde [ip].";
$l_log_title["LOG0_BADLOGIN"] 		= "Conexión fallida";
$l_log_text["LOG6_PLANET_SCAN"] 		= "[name] ha escaneado tu planeta [planet_name] en el sector [sector].";
$l_log_title["LOG6_PLANET_SCAN"] 		= "Escáner de planeta";
$l_log_text["LOG6_PLANET_SCAN_FAIL"] 	= "[name] ha intentado escanear tu planeta [planet_name] en el sector [sector], pero falló.";
$l_log_title["LOG6_PLANET_SCAN_FAIL"] 	= "Escáner de planeta fallido";
$l_log_text["LOG6_SHIP_SCAN"] 		= "[player] ha escaneado tu nave.";
$l_log_title["LOG6_SHIP_SCAN"] 		= "Escáner de nave";
$l_log_text["LOG6_SHIP_SCAN_FAIL"] 	= "[player] intentó escanear tu nave, pero falló.";
$l_log_title["LOG6_SHIP_SCAN_FAIL"] 	= "Escáner de nave fallido";
$l_log_text["LOG5_KABAL_ATTACK"] 		= "Atacando a [player]...";
$l_log_title["LOG5_KABAL_ATTACK"] 		= "Ataque";
$l_log_text["LOG7_STARVATION"] 		= "¡Planetas [name] en el sector [sector] no puede mantener su populación! Se necesitan más alimentos. [starvation] colonos murieron de hambre. Colonists started starving on [date].";
$l_log_title["LOG7_STARVATION"] 		= "<font color=yellow>¡Hambruna!</font>";
$l_log_title["LOG0_TOW"] 			= "¡Remolcado!";
$l_log_text["LOG0_TOW"] 	 = "Your ship has been towed from sector [sector] to sector [newsector] because your average tech level exceeded the limit value of [hull] or you have a ship in storage.";
$l_log_text["LOG5_DEFS_DESTROYED_F"] 	= "Has destruido una patrulla de [fighters] cazas en el sector [sector].";
$l_log_title["LOG5_DEFS_DESTROYED_F"] 	= "Cazas destruidos";
$l_log_text["LOG5_DEFS_KABOOM"] 		= "Fuiste destruido por un destacamento de cazas en el sector [sector]. ";
$l_log_title["LOG5_DEFS_KABOOM"] 		= "<font color=red>¡Nave destruida!</font>";
$l_log_text["LOG0_HARAKIRI"] 		= "Estabas cansado de capitanear esta 'lancha' espacial, así que decidiste que el universo estaría mejor sin ella. Autorizado por [ip].";
$l_log_title["LOG0_HARAKIRI"] 		= "<font color=red>¡Auto-destruido!</font>";
$l_log_text["LOG0_TEAM_REJECT"] 		= "[player] ha rechazado la invitación de sumarse a tu equipo, [teamname].";
$l_log_title["LOG0_TEAM_REJECT"] 		= "Invitación rechazada";
$l_log_text["LOG0_TEAM_RENAME"] 		= "Has renombrado tu equipo como [team].";
$l_log_title["LOG0_TEAM_RENAME"] 		= "Equipo renombrado";
$l_log_text["LOG0_TEAM_M_RENAME"] 		= "Tu coordinador de equipo renombró el equipo como [team].";
$l_log_title["LOG0_TEAM_M_RENAME"] 	= "Equipo renombrado";
$l_log_text["LOG0_TEAM_KICK"] 		= "Has sido expulsado del equipo [team].";
$l_log_title["LOG0_TEAM_KICK"] 		= "¡Expulsado del equipo!";
$l_log_text["LOG0_TEAM_CREATE"] 		= "Has creado un nuevo equipo, [team].";
$l_log_title["LOG0_TEAM_CREATE"] 		= "Creado nuevo equipo";
$l_log_text["LOG0_TEAM_LEAVE"] 		= "Has dejado el equipo [team].";
$l_log_title["LOG0_TEAM_LEAVE"] 		= "Equipo abandonado";
$l_log_text["LOG0_TEAM_NEWLEAD"] 		= "Has dejado el equipo [team]. Renunciaste al liderato del equipo en favor de [name].";
$l_log_title["LOG0_TEAM_NEWLEAD"] 		= "Equipo abandonado";
$l_log_text["LOG0_TEAM_LEAD"] 		= "Tu coordinador de equipo ha decidido dejar [team]. Has sido elegido para ocupar su lugar.";
$l_log_title["LOG0_TEAM_LEAD"] 		= "¡Promoción!";
$l_log_text["LOG0_TEAM_JOIN"] 		= "Te has unido al equipo [team].";
$l_log_title["LOG0_TEAM_JOIN"] 		= "Unión a equipo";
$l_log_text["LOG0_TEAM_NEWMEMBER"] 	= "[name] ha aceptado unirse a [team]. Esto supone para ti un paso más en la dominación galáctica.";
$l_log_title["LOG0_TEAM_NEWMEMBER"] 	= "Nuevo miembro de equipo";
$l_log_text["LOG0_TEAM_INVITE"] 		= "Has sido invitado a formar parte de [team].";
$l_log_title["LOG0_TEAM_INVITE"] 		= "Invitación";
$l_log_text["LOG0_TEAM_NOT_LEAVE"] 	= "[player] ha dejado tu equipo.";
$l_log_title["LOG0_TEAM_NOT_LEAVE"] 	= "Renuncia en el equipo";
$l_log_text["LOG0_ADMIN_HARAKIRI"] 	= "[player] se ha auto-destruido desde el IP [ip].";
$l_log_title["LOG0_ADMIN_HARAKIRI"] 	= "Auto-destrucción";
$l_log_text["LOG0_ADMIN_ILLEGVALUE"] 	= "[player] tuvo [quantity] [type], para un máximo de [holds]";
$l_log_title["LOG0_ADMIN_ILLEGVALUE"] 	= "Ilegal valor en nave";
$l_log_text["LOG0_ADMIN_PLANETDEL"] 	= "[attacker] ha intentado capturar el planeta de [defender] en el sector [sector]. Sin embargo el planeta fue destruido.";
$l_log_title["LOG0_ADMIN_PLANETDEL"] 	= "Planeta destruido";
$l_log_text["LOG0_defense_DEGRADE"] 	= "Cazas de la Defensa de Sector en [sector] rebajados en [degrade] por ciento debido a la falta de energía.";
$l_log_title["LOG0_defense_DEGRADE"] 	= "Defensas de Sector rebajadas.";
$l_log_text["LOG5_PLANET_CAPTURED"] 	= "Capturaste un planeta perteneciente a [owner]. había [cols] colonos y [credits] créditos en él.";
$l_log_title["LOG5_PLANET_CAPTURED"] 	= "¡Planeta capturado!";
$l_log_text["LOG0_CHEAT_TEAM"] 		= "El jugador [player] desde la dirección IP [ip] intentó sacar beneficio del truco de expulsar a cualquiera. Su nave fue destruida.";
$l_log_text["LOG0_BOUNTY_CLAIMED"] = "Reclamaste una recompensa de [amount] créditos por la destrucción de la nave perteneciente a [bounty_on]. La recompensa fue fijada por [placed_by].";
$l_log_title["LOG0_BOUNTY_CLAIMED"] = "Recompensa reclamada";
$l_log_text["LOG0_BOUNTY_PAID"] = "Tu recompensa sobre [bounty_on] ha sido pagada por la cantidad de [amount] créditos.";
$l_log_text["LOG0_BOUNTY_TAX_PAID"] = "The Fedration bounty on [bounty_on] has been taxed for the amount of [amount] credits.";
$l_log_title["LOG0_BOUNTY_PAID"] = "Recompensa pagada.";
$l_log_text["LOG0_BOUNTY_CANCELLED"] = "Tu recompensa sobre [bounty_on] por la cantidad de [amount] créditos ha sido devuelta.";
$l_log_title["LOG0_BOUNTY_CANCELLED"] = "Recompensa reembolsada.";
$l_log_text["LOG0_BOUNTY_FEDBOUNTY"] = "La Federación ha fijado una recompensa sobre ti por la cantidad de [amount] créditos.";
$l_log_title["LOG0_BOUNTY_FEDBOUNTY"] = "¡Recompensa de la Federación!";
$l_log_text["LOG0_BOUNTY_ALLIANCEBOUNTY"] = "The Alliance has placed a bounty on you for the amount of [amount] credits.";
$l_log_title["LOG0_BOUNTY_ALLIANCEBOUNTY"] = "Alliance Bounty!";
$l_log_text["LOG0_IGB_TRANSFER1"] = "El jugador [name] hizo una transferencia de [sum] créditos a tu cuenta de IGB.";
$l_log_title["LOG0_IGB_TRANSFER1"] = "Créditos transferidos";
$l_log_text["LOG0_IGB_TRANSFER2"] = "Transferiste [sum] créditos a la cuenta IGB del jugador [name].";
$l_log_title["LOG0_IGB_TRANSFER2"] = "Créditos transferidos";

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

$l_log_text["LOG2_SPY_NEWSHIP"] = "Perdiste al espía [id] en la nave [shipname] de [name], ya que se compró una nueva nave.";
$l_log_title["LOG2_SPY_NEWSHIP"] = "<font color=yellow>¡Espía perdido!</font>";

$l_log_text["LOG2_SPY_SEND_FAIL"] = "[name] intentó introducir un espía en tu planeta [planet_name] en el sector [sector], pero tus Sensores detectaron al espía y fue eliminado.";
$l_log_title["LOG2_SPY_SEND_FAIL"] = "<font color=yellow>¡Espía enemigo eliminado!</font>";

$l_log_text["LOG2_SPY_SABOTAGE"] = "Tu espía [id] en el planeta [planet_name] en el sector [sector] comienza el sabotaje. La producción es reducida en [data] en el planeta.";
$l_log_title["LOG2_SPY_SABOTAGE"] = "<font color=#00FF00>¡Sabotaje comenzado!</font>";

$l_log_text["LOG2_SPY_BIRTH"] = "Tu espía [id] en el planeta [planet_name] en el sector [sector] redujo la natalidad en [data] en el planeta.";
$l_log_title["LOG2_SPY_BIRTH"] = "<font color=#00FF00>¡Natalidad reducida!</font>";

$l_log_text["LOG2_SPY_INTEREST"] = "Tu espía [id] en el planeta [planet_name] en el sector [sector] comienza a recoger [data] en intereses del planeta para ti.";
$l_log_title["LOG2_SPY_INTEREST"] = "<font color=#00FF00>¡Recogiendo intereses!</font>";

$l_log_text["LOG2_SPY_MONEY"] = "¡Tu espía [id] en el planeta [planet_name] en el sector [sector] robó [data] créditos para ti!";
$l_log_title["LOG2_SPY_MONEY"] = "<font color=#00FF00>¡Créditos robados!</font>";

$l_log_text["LOG2_SPY_TORPS"] = "¡Tu espía [id] en el planeta [planet_name] en el sector [sector] destruyó [data] torpedos planetarios!";
$l_log_title["LOG2_SPY_TORPS"] = "<font color=#00FF00>¡Torpedos destruidos!</font>";

$l_log_text["LOG2_SPY_FITS"] = "¡Tu espía [id] en el planeta [planet_name] en el sector [sector]  destruyó [data] cazas planetarios!";
$l_log_title["LOG2_SPY_FITS"] = "<font color=#00FF00>¡Cazas destruidos!</font>";

$l_log_text["LOG2_SPY_CPTURE"] = "¡¡Tu espía [id] en el planeta [planet_name] en el sector [sector] capturó el planeta!! Tienes mucha suerte...";
$l_log_title["LOG2_SPY_CPTURE"] = "<font color=#00FF00>¡PLANETA CAPTURADO!</font>";

$l_log_text["LOG2_SPY_CPTURE_OWNER"] = "¡Un espía de [name] capturó tu planeta [planet_name] en el sector [sector]! Será mejor que limpies de espías tus planetas más habitualmente...";
$l_log_title["LOG2_SPY_CPTURE_OWNER"] = "<font color=red>¡Planeta Perdido!</font>";

$l_log_text["LOG2_SPY_KILLED_SPYOWNER"] = "No hay mensajes de tu espía [id] en el planeta [planet_name] en el sector [sector] desde hace tiempo - parece que tu dispositivo de Camuflaje no pudo cubrirle lo suficiente y ha sido eliminado.";
$l_log_title["LOG2_SPY_KILLED_SPYOWNER"] = "<font color=yellow>¡Espía Perdido!</font>";

$l_log_text["LOG2_SPY_KILLED"] = "Tus Sensores detectaron un espía de [name] en tu planeta [planet_name] en el sector [sector]. El espía ha sido eliminado.";
$l_log_title["LOG2_SPY_KILLED"] = "<font color=yellow>¡Espía enemigo eliminado!</font>";

$l_log_text["LOG2_SHIPSPY_KILLED"] = "No hay mensajes de tu espía [id] en la nave [shipname], de [name], desde hace tiempo - parece que tu dispositivo de Camuflaje no pudo cubrirle lo suficiente y ha sido eliminado.";
$l_log_title["LOG2_SHIPSPY_KILLED"] = "<font color=yellow>¡Espía Perdido!</font>";

$l_log_text["LOG2_SPY_CATACLYSM"] = "¡Tu espía [id] en el planeta [planet_name] en el sector [sector] pereció junto con el planeta entero en un terrible cataclismo.";
$l_log_title["LOG2_SPY_CATACLYSM"] = "<font color=yellow>¡Espía Perdido!</font>";

$l_log_text["LOG2_SHIPSPY_CATACLYSM"] = "¡Tu espía [id] en la nave [shipname], de [name], pereció junto con la nave en un terrible cataclismo.";
$l_log_title["LOG2_SHIPSPY_CATACLYSM"] = "<font color=yellow>¡Espía Perdido!</font>";

$l_log_text["LOG2_SPY_TOSHIP"] = "Tu espía [id] en el planeta [planet_name] en el sector [sector] se infiltró en la nave [shipname] de [playername] y ahora actúa desde allí.";
$l_log_title["LOG2_SPY_TOSHIP"] = "<font color=#00FF00>¡Espía se infiltra en Nave Enemiga!</font>";

$l_log_text["LOG2_SPY_TOPLANET"] = "Tu espía [id] en la nave [shipname], de [playername], se infiltró en el planeta [planet_name] en el sector [sector] y ahora actúa allí.";
$l_log_title["LOG2_SPY_TOPLANET"] = "<font color=#00FF00>¡Espía se infiltra en Planeta Enemigo!</font>";

$l_log_text["LOG5_PLANET_YOUR_CAPTURED"]   = "Tu planeta [planet_name] en el sector [sector] fue derrotado y capturado por [name].";
$l_log_title["LOG5_PLANET_YOUR_CAPTURED"]  = "<font color=red>¡Planeta capturado!</font>";
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

$l_log_text["LOG5_PLANET_BOMBED"] = "Tu planeta [planet_name] en el sector [sector] fue bombardeado por [name]. Usaste [beams] de energía y [torps] torpedos en la defensa.  Perdiste [figs] cazas.";
$l_log_title["LOG5_PLANET_BOMBED"] = "<font color=red>¡Planeta bombardeado!</font>";
$l_log_text["LOG5_PLANET_CONFISCATION"] 		= "Your planet was confiscated by [player]. Do to excessive attacks on bounty players the [player] has confiscated one of your planets ([name]) in sector [sector] worth [score] credits.";
$l_log_title["LOG5_PLANET_CONFISCATION"] 		= "<font color=yellow>Planetary Skirmish!</font>";


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
