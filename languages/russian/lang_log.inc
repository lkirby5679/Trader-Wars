<?php
$l_log_months 		 = array('Январь','Февраль','Март','Апрель','Май','Июнь','Июль','Август','Сентябрь','Октябрь','Ноябрь','Декабрь');
$l_log_months_short 	 = array('Янв','Фев','Март','Апр','Май','Июнь','Июль','Авг','Сент','Окт','Ноя','Дек');
$l_log_pod 		 = "Хорошо, что у вас была спасательная капсула!";
$l_log_nopod 		 = "<font color=yellow><b>У вас не было спасательной капсулы и вы погибли.</b></font>";
$l_log_log 		 = "Журнал [player]";
$l_log_start 		 = "Запись за";
$l_log_end 		 = "Конец записи за";
$l_log_click 		 = "Нажмите <A HREF=main.php><font color=#00ff00>здесь</font></A> для возврата в главное меню.";
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

$l_log_text["LOG_LOGIN"] 	 = "Вы вошли с узла [ip].";
$l_log_title["LOG_LOGIN"]  = "Вход";
$l_log_text["LOG_LOGOUT"]  = "Вы вышли с узла [ip].";
$l_log_title["LOG_LOGOUT"] = "Выход";
$l_log_text["LOG5_ATTACK_OUTMAN"] 		= "[player] заходил на атаку, но ваши навыки пилотирования и отличные двигатели позволили избежать атаки.";
$l_log_title["LOG5_ATTACK_OUTMAN"] 	= "Маневр уклонения!";
$l_log_text["LOG5_ATTACK_OUTSCAN"] 	= "Вы засекли, что орудия [player] наводятся на ваш корабль, но ваша маскировка обманула сенсоры противника.";
$l_log_title["LOG5_ATTACK_OUTSCAN"] 	= "Удачная маскировка!";
$l_log_text["LOG5_ATTACK_EWD"] 		= "Вы удивились внезапной атаке [player]. Вы увидели летящие торпеды, и быстро нажали на кнопку запуска аварийного гипердвигателя. Все вокруг вас расплывается, и на мгновение вы подумали, что погибли. Но когда вы открыли глаза, вы увидели, что благополучно добрались в какой-то другой сектор. Но в какой...";
$l_log_title["LOG5_ATTACK_EWD"] 		= "Запуск аварийного гипердвигателя!";
$l_log_text["LOG5_ATTACK_EWDFAIL"] 	= "Ваши сенсоры засекли приближающийся корабля [player]. \"Лучше не рисковать\", подумали вы, нажимая на кнопку запуска аварийного гипердвигателя. Из двигательного отсека послышался странный звук и запахло горелым. \"Бесполезная железяка!\", выругались вы, врезав по компьютеру. Компьютер начал издавать протестующие звуки, а вы приготовились к надвигающейся битве...";
$l_log_title["LOG5_ATTACK_EWDFAIL"] 	= "<font color=red>Облом системы</font> аварийного гипердвигателя!";
$l_log_text["LOG5_ATTACK_LOSE"] 		= "Ваш корабль атакован [player]. Как вы не старайтесь, вам не устоять против превосходящей мощи [player]. Ваш корабль уничтожен. ";
$l_log_title["LOG5_ATTACK_LOSE"] 		= "<font color=red>Битва проиграна!</font>";
$l_log_text["LOG5_ATTACKED_WIN"] 		= "[player] атаковал ваш корабль. Вы обменялись несколькими ударами. Ваша броня повреждена на [armor], а потери истребителей составили [fighters].";
$l_log_title["LOG5_ATTACKED_WIN"] 		= "<font color=yellow>Перестрелка!</font>";
$l_log_text["LOG5_HIT_MINES"] 		= "Вы нарвались на [mines] мин при входе в сектор [sector].";
$l_log_title["LOG5_HIT_MINES"] 		= "<font color=yellow>Минное поле!</font>";
$l_log_text["LOG5_SHIP_DESTROYED_MINES"] 	= "Ваш корабль был уничтожен на минном поле в секторе [sector]. ";
$l_log_title["LOG5_SHIP_DESTROYED_MINES"] 	= "<font color=red>Минное поле!</font>";
$l_log_text["LOG5_PLANET_DEFEATED_D"] 	= "Ваша планета [planet_name] в секторе [sector] была побеждена в бою с [name]. К счастью, преданность вашего народа сыграла вам на руку. Жители планеты решили уничтожить планету пока она не попала в руки врага. Вы устроили раскошные похороны в память о вашем преданном народе.";
$l_log_title["LOG5_PLANET_DEFEATED_D"] 	= "<font color=yellow>Планета уничтожена</font>";
$l_log_text["LOG5_PLANET_DEFEATED"] 	= "Ваша планета [planet_name] в секторе [sector] была побеждена в бою с ужасным [name]. Жители планеты приветствуют нового правителя. Вы слышите сообщения по ГАН : \"Мы рады избавиться от этого старпера! Нам не нужен вонючий неудачник, который не в состоянии нас защитить!\". Вы поклялись заплатить им за их высокомерие.";
$l_log_title["LOG5_PLANET_DEFEATED"] 	= "<font color=red>Планета побеждена!</font>";
$l_log_text["LOG5_PLANET_NOT_DEFEATED"] 	= "Ваша планета [planet_name] в секторе [sector] атакована [name]. Жители оказали ожесточенное сопротивление и смогли уничтожить захватчика. Они собрали некоторые ресурсы из обломков: [goods] товаров, [ore] руды, [organics] органики и [salvage]% стоимости корабля на [credits] кредов.";
$l_log_title["LOG5_PLANET_NOT_DEFEATED"] 	= "Победа!";
$l_log_title["LOG0_RAW"] 			= "Заметка";
$l_log_text["LOG5_DEFS_DESTROYED"] 	= "[quantity] [type] уничтожено в секторе [sector].";
$l_log_title["LOG5_DEFS_DESTROYED"] 	= "Потери орбитальных оборонительных средств";
$l_log_text["LOG0_PLANET_EJECT"] 		= "Вы были выдворены с планеты в секторе [sector] по причине выхода [name] из альянса.";
$l_log_title["LOG0_PLANET_EJECT"] 		= "<font color=yellow>Выдворение!</font>";
$l_log_text["LOG0_BADLOGIN"] 		= "Была неудачная попытка входа с узла [ip].";
$l_log_title["LOG0_BADLOGIN"] 		= "<font color=red>Неудачный вход</font>";
$l_log_text["LOG6_PLANET_SCAN"] 		= "[name] просканировал вашу планету [planet_name] в секторе [sector].";
$l_log_title["LOG6_PLANET_SCAN"] 		= "<font color=brown>Сканирование планеты</font>";
$l_log_text["LOG6_PLANET_SCAN_FAIL"] 	= "[name] пытался просканировать вашу планету [planet_name] в секторе [sector], но неудачно.";
$l_log_title["LOG6_PLANET_SCAN_FAIL"] 	= "<font color=green>Неудачное сканирование планеты</font>";
$l_log_text["LOG6_SHIP_SCAN"] 		= "[player] просканировал ваш корабль.";
$l_log_title["LOG6_SHIP_SCAN"] 		= "<font color=brown>Сканирование корабля</font>";
$l_log_text["LOG6_SHIP_SCAN_FAIL"] 	= "[player] неудачно пытался сканировать ваш корабль.";
$l_log_title["LOG6_SHIP_SCAN_FAIL"] 	= "<font color=green>Неудачное сканирование корабля</font>";
$l_log_text["LOG5_KABAL_ATTACK"] 		= "Атака [player]... (Кабал!)";
$l_log_title["LOG5_KABAL_ATTACK"] 		= "Атака (Кабал!)";
$l_log_text["LOG7_STARVATION"] 		= "[name] из планет в секторе [sector] не может прокормить все население! Необходимо больше органики. [starvation] колонистов умерло с голоду. Colonists started starving on [date].";
$l_log_title["LOG7_STARVATION"] 		= "<font color=yellow>Голодание!</font>";
$l_log_title["LOG0_TOW"] 			= "<font color=yellow>Отбуксирован!</font>";
$l_log_text["LOG0_TOW"] 	 = "Your ship has been towed from sector [sector] to sector [newsector] because your average tech level exceeded the limit value of [hull] or you have a ship in storage.";
$l_log_text["LOG5_DEFS_DESTROYED_F"] 	= "Вы уничтожили [fighters] истребителей патрулировавших сектор [sector].";
$l_log_title["LOG5_DEFS_DESTROYED_F"] 	= "Уничтожен патруль";
$l_log_text["LOG5_DEFS_KABOOM"] 		= "Ваш корабль уничтожен орбитальными силами сектора [sector]. ";
$l_log_title["LOG5_DEFS_KABOOM"] 		= "<font color=red>Корабль уничтожен!</font>";
$l_log_text["LOG0_HARAKIRI"] 		= "Вы устали от командования этой баржой и решили, что во вселенной и без нее мусора хватает. Подтверждено с узла [ip].";
$l_log_title["LOG0_HARAKIRI"] 		= "<font color=red>Самоуничтожение!</font>";
$l_log_text["LOG0_TEAM_REJECT"] 		= "[player] отказался вступить в ваш альянс [teamname].";
$l_log_title["LOG0_TEAM_REJECT"] 		= "Предложение отклонено";
$l_log_text["LOG0_TEAM_RENAME"] 		= "Вы переименовали ваш альянс в [team].";
$l_log_title["LOG0_TEAM_RENAME"] 		= "Альянс переименован";
$l_log_text["LOG0_TEAM_M_RENAME"] 		= "Координатор переименовал альянс в [team].";
$l_log_title["LOG0_TEAM_M_RENAME"] 	= "Альянс переименован";
$l_log_text["LOG0_TEAM_KICK"] 		= "Вас исключили из альянса [team].";
$l_log_title["LOG0_TEAM_KICK"] 		= "<font color=yellow>Исключение из альянса!</font>";
$l_log_text["LOG0_TEAM_CREATE"] 		= "Вы создали новый альянс [team].";
$l_log_title["LOG0_TEAM_CREATE"] 		= "<font color=green>Новый альянс</font>";
$l_log_text["LOG0_TEAM_LEAVE"] 		= "Вы покинули альянс [team].";
$l_log_title["LOG0_TEAM_LEAVE"] 		= "Альянс покинут";
$l_log_text["LOG0_TEAM_NEWLEAD"] 		= "Вы покинули альянс [team] и передали управление [name].";
$l_log_title["LOG0_TEAM_NEWLEAD"] 		= "Альянс покинут";
$l_log_text["LOG0_TEAM_LEAD"] 		= "Ваш координатор решил покинуть альянс [team]. Вас назначили на его место.";
$l_log_title["LOG0_TEAM_LEAD"] 		= "Повышение!";
$l_log_text["LOG0_TEAM_JOIN"] 		= "Вы присоединились к альянсу [team].";
$l_log_title["LOG0_TEAM_JOIN"] 		= "Вступление в альянс";
$l_log_text["LOG0_TEAM_NEWMEMBER"] 	= "[name] решил присоединиться к [team]. Ваш альянс приблизился к господству в галактике.";
$l_log_title["LOG0_TEAM_NEWMEMBER"] 	= "Новый член альянса";
$l_log_text["LOG0_TEAM_INVITE"] 		= "Вас пригласили в альянс [team].";
$l_log_title["LOG0_TEAM_INVITE"] 		= "Приглашение";
$l_log_text["LOG0_TEAM_NOT_LEAVE"] 	= "[player] вышел из альянса.";
$l_log_title["LOG0_TEAM_NOT_LEAVE"] 	= "Потеря члена альянса";
$l_log_text["LOG0_ADMIN_HARAKIRI"] 	= "[player] самоуничтожился с узла [ip].";
$l_log_title["LOG0_ADMIN_HARAKIRI"] 	= "Самоуничтожение";
$l_log_text["LOG0_ADMIN_ILLEGVALUE"] 	= "У [player] было [quantity] [type], при максимуме [holds]";
$l_log_title["LOG0_ADMIN_ILLEGVALUE"] 	= "Недопустимое значение";
$l_log_text["LOG0_ADMIN_PLANETDEL"] 	= "[attacker] попытался захватить планету [defender] в секторе [sector]. Но планета была уничтожена.";
$l_log_title["LOG0_ADMIN_PLANETDEL"] 	= "Планета уничтожена";
$l_log_text["LOG0_defense_DEGRADE"] 	= "Количество истребителей орбитальной обороны в секторе [sector] уменьшилось на [degrade] процентов из-за нехватки энергии.";
$l_log_title["LOG0_defense_DEGRADE"] 	= "Ослабление орбитальной обороны.";
$l_log_text["LOG5_PLANET_CAPTURED"] 	= "Вы захватили планету [owner]. На ней [cols] колонистов и [credits] кредов.";
$l_log_title["LOG5_PLANET_CAPTURED"] 	= "Планета захвачена!";
$l_log_text["LOG0_CHEAT_TEAM"] 		= "Игрок [player] с узла [ip] пытался мухлевать с альянсом. Его корабль был уничтожен.";
$l_log_text["LOG0_BOUNTY_CLAIMED"] = "Вы получили награду в размере [amount] кредов за уничтожение корабля [bounty_on]. Награда была объявлена [placed_by].";
$l_log_title["LOG0_BOUNTY_CLAIMED"] = "Получено вознаграждение.";
$l_log_text["LOG0_BOUNTY_PAID"] = "Ваша награда за [bounty_on] выплачена в размере [amount] кредов.";
$l_log_text["LOG0_BOUNTY_TAX_PAID"] = "The Fedration bounty on [bounty_on] has been taxed for the amount of [amount] credits.";
$l_log_title["LOG0_BOUNTY_PAID"] = "Вознаграждение выплачено.";
$l_log_text["LOG0_BOUNTY_CANCELLED"] = "Установленное вами вознаграждение за [bounty_on] в размере [amount] кредов было увеличено.";
$l_log_title["LOG0_BOUNTY_CANCELLED"] = "Вознаграждение увеличено.";
$l_log_text["LOG0_BOUNTY_FEDBOUNTY"] = "Федерация назначила награду за вашу голову в размере [amount] кредов.";
$l_log_title["LOG0_BOUNTY_FEDBOUNTY"] = "Федеральная награда!";
$l_log_text["LOG0_BOUNTY_ALLIANCEBOUNTY"] = "The Alliance has placed a bounty on you for the amount of [amount] credits.";
$l_log_title["LOG0_BOUNTY_ALLIANCEBOUNTY"] = "Alliance Bounty!";
$l_log_text["LOG0_IGB_TRANSFER1"] = "Игрок [name] перевел на ваш счет в МГБ [sum] кредов.";
$l_log_title["LOG0_IGB_TRANSFER1"] = "Денежный перевод";
$l_log_text["LOG0_IGB_TRANSFER2"] = "Вы перевели [sum] кредов на счет игрока [name].";
$l_log_title["LOG0_IGB_TRANSFER2"] = "Денежный перевод";

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

$l_log_text["LOG2_SPY_NEWSHIP"] = "Герой Советского Союза, почётный разведчик [id], трагически погиб при исполнении секретного задания на корабле противника [shipname], управляемом [name], отправившим корабль в переплавку.";
$l_log_title["LOG2_SPY_NEWSHIP"] = "<font color=yellow>Связь со шпионом потеряна</font>";

$l_log_text["LOG2_SPY_SEND_FAIL"] = "[name] пытался заслать шпиона на вашу планету [planet_name] в секторе [sector], но ваши радары вовремя засекли эту попытку. Вражеский шпион убит.";
$l_log_title["LOG2_SPY_SEND_FAIL"] = "<font color=yellow>Вражеский шпион убит!</font>";

$l_log_text["LOG2_SPY_SABOTAGE"] = "Ваш шпион [id] организовал бунт на планете [planet_name] в секторе [sector]. Производство на этой планете подорвано на [data].";
$l_log_title["LOG2_SPY_SABOTAGE"] = "<font color=#00FF00>БУНТ!</font>";

$l_log_text["LOG2_SPY_BIRTH"] = "Ваш шпион [id] на планете [planet_name] в секторе [sector] уменьшил уровень рождаемости на [data].";
$l_log_title["LOG2_SPY_BIRTH"] = "<font color=#00FF00>Уровень рождаемости снижен!</font>";

$l_log_text["LOG2_SPY_INTEREST"] = "Ваш шпион [id] на планете [planet_name] в секторе [sector] начал переводить вам [data] прибыли планеты.";
$l_log_title["LOG2_SPY_INTEREST"] = "<font color=#00FF00>Финансовая диверсия начата!</font>";

$l_log_text["LOG2_SPY_MONEY"] = "Ваш шпион [id] на планете [planet_name] в секторе [sector] украл для вас [data] кредов!";
$l_log_title["LOG2_SPY_MONEY"] = "<font color=#00FF00>Вам капнуло бабло!</font>";

$l_log_text["LOG2_SPY_TORPS"] = "Ваш шпион [id] на планете [planet_name] в секторе [sector] уничтожил [data] planetary torpedoes!";
$l_log_title["LOG2_SPY_TORPS"] = "<font color=#00FF00>Взрыв арсенала!</font>";

$l_log_text["LOG2_SPY_FITS"] = "Ваш шпион [id] на планете [planet_name] в секторе [sector] превратил в кучу металлолома [data] истребителей!";
$l_log_title["LOG2_SPY_FITS"] = "<font color=#00FF00>Уничтожен ангар!</font>";

$l_log_text["LOG2_SPY_CPTURE"] = "Ваш шпион [id] на планете [planet_name] в секторе [sector] устроил переворот!! У вас отличная агентура...";
$l_log_title["LOG2_SPY_CPTURE"] = "<font color=#00FF00>Захват планеты!</font>";

$l_log_text["LOG2_SPY_CPTURE_OWNER"] = "Шпион ненавистного [name] захватил вашу планету [planet_name] в секторе [sector]! Вам бы следовало почаще проводить зачистки на планетах...";
$l_log_title["LOG2_SPY_CPTURE_OWNER"] = "<font color=red>Планета потеряна!</font>";

$l_log_text["LOG2_SPY_KILLED_SPYOWNER"] = "От шпиона [id] с планеты [planet_name] в секторе [sector] давно не было вестей - похоже он демаскирован и убит.";
$l_log_title["LOG2_SPY_KILLED_SPYOWNER"] = "<font color=yellow>Связь со шпионом потеряна</font>";

$l_log_text["LOG2_SPY_KILLED"] = "Ваши радары на планете [planet_name]  в секторе [sector] засекли шпиона некоего [name]. Его таки замочили.";
$l_log_title["LOG2_SPY_KILLED"] = "<font color=yellow>Уничтожен вражеский шпион!</font>";

$l_log_text["LOG2_SHIPSPY_KILLED"] = "От шпиона [id] на корабле [shipname], командуемом [name] давно не было вестей - похоже он демаскирован и убит.";
$l_log_title["LOG2_SHIPSPY_KILLED"] = "<font color=yellow>Связь со шпионом потеряна!</font>";

$l_log_text["LOG2_SPY_CATACLYSM"] = "Ваш шпион [id] на планете [planet_name] в секторе [sector] пропал без вести при ужастной катастрофе на планете.";
$l_log_title["LOG2_SPY_CATACLYSM"] = "<font color=yellow>Связь со шпионом потеряна!</font>";

$l_log_text["LOG2_SHIPSPY_CATACLYSM"] = "Ваш шпион [id] на корабле [shipname] под командованием [name] погиб в космической катастрофе.";
$l_log_title["LOG2_SHIPSPY_CATACLYSM"] = "<font color=yellow>Связь со шпионом потеряна!</font>";

$l_log_text["LOG2_SPY_TOSHIP"] = "Ваш шпион [id] с планеты [planet_name] в секторе [sector] просочился на корабль [shipname] командуемый [playername]. Ждите вестей!";
$l_log_title["LOG2_SPY_TOSHIP"] = "<font color=#00FF00>Шпион просочился на вражеский корабль!</font>";

$l_log_text["LOG2_SPY_TOPLANET"] = "Ваш шпион [id] с корабля [shipname] командуемого [playername] высадился на планете [planet_name] в секторе [sector]. Ждите новых вестей.";
$l_log_title["LOG2_SPY_TOPLANET"] = "<font color=#00FF00>Высадка на вражеской планете!</font>";

$l_log_text["LOG5_PLANET_YOUR_CAPTURED"]   = "Ваша планета [planet_name] в секторе [sector] была захвачена ненавистным [name].";
$l_log_title["LOG5_PLANET_YOUR_CAPTURED"]  = "<font color=red>Планета захвачена!</font>";
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

$l_log_text["LOG5_PLANET_BOMBED"] = "[name] бомбардировал вашу планету [planet_name] в секторе [sector]. Планетарные батареи использовали [beams] энергии и [torps] торпед.  Потери: [figs] истребителей.";
$l_log_title["LOG5_PLANET_BOMBED"] = "<font color=red>Планета бомбардирована!</font>";


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
