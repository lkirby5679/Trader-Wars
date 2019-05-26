<?php
    // Start class_modules_planet table

	TextFlush( "Dropping: {$db_prefix}class_modules_planet ");
	$res = $db->Execute("DROP TABLE IF EXISTS `{$db_prefix}class_modules_planet`");
	db_op_result($res,__LINE__,__FILE__);

    TextFlush( "Creating table: {$db_prefix}class_modules_planet ");
	$res = $db->Execute("CREATE TABLE IF NOT EXISTS `{$db_prefix}class_modules_planet` (
	`module_id` int(11) NOT NULL auto_increment,
	`class` varchar(100) default NULL,
	`classname` varchar(100) default NULL,
	`cargoclass` varchar(100) default NULL,
	`program` varchar(100) default NULL,
	`upgradeport` int(11) NOT NULL default '0',
	`deviceport` int(11) NOT NULL default '0',
	`cargoport` int(11) NOT NULL default '0',
	`cargoplanet` int(11) NOT NULL default '0',
	`defaultcargoplanet` int(11) NOT NULL default '0',
	`defaultcargoship` int(11) NOT NULL default '0',
	`shipdevice` int(11) NOT NULL default '0',
	`planetdevice` int(11) NOT NULL default '0',
	`shipdevicemax` int(11) NOT NULL default '0',
	`planetdevicemax` int(11) NOT NULL default '0',
	`researchonly` int(11) NOT NULL default '0',
	`researchcredits` int(11) NOT NULL default '0',
	`researchore` int(11) NOT NULL default '0',
	`researchorganics` int(11) NOT NULL default '0',
	`researchgoods` int(11) NOT NULL default '0',
	`researchenergy` int(11) NOT NULL default '0',
	`researchticks` int(11) NOT NULL default '0',
	`buildcredits` int(11) NOT NULL default '0',
	`buildore` int(11) NOT NULL default '0',
	`buildorganics` int(11) NOT NULL default '0',
	`buildgoods` int(11) NOT NULL default '0',
	`buildenergy` int(11) NOT NULL default '0',
	`buildticks` int(11) NOT NULL default '0',
	`goodevil` int(11) NOT NULL default '0',
	`price` double(32,2) NOT NULL default '0.00',
	`delta` double(32,2) NOT NULL default '0.00',
	`rate` double(32,2) NOT NULL default '0.00',
	`reducerate` double(22,10) NOT NULL default '0.0000000000',
	`increaserate` double(22,10) NOT NULL default '0.0000000000',
	`itemlimit` int(11) NOT NULL default '0',
	`prate` double(32,5) NOT NULL default '0.00000',
	`default_prod` int(11) NOT NULL default '0',
	`default_indy_prod` int(11) NOT NULL default '0',
	`default_create_percent` int(11) NOT NULL default '0',
	`fixed_start_price` int(11) NOT NULL default '0',
	`damage_shields` int(11) NOT NULL default '0',
	`damage_all` int(11) NOT NULL default '0',
	`deflector_damage` int(11) NOT NULL default '0',
	`hit_pts` int(11) NOT NULL default '0',
	`price_modifier` int(11) NOT NULL default '0',
	`energy_usage` int(11) NOT NULL default '0',
	`hold_space` int(11) NOT NULL default '0',
	`enable` char(1) NOT NULL default 'Y',
	PRIMARY KEY	(`module_id`),
	KEY `class` (`class`),
	KEY `classname` (`classname`),
	KEY `cargoclass` (`cargoclass`),
	KEY `upgradeport` (`upgradeport`),
	KEY `deviceport` (`deviceport`),
	KEY `cargoport` (`cargoport`),
	KEY `cargoplanet` (`cargoplanet`),
	KEY `defaultcargoplanet` (`defaultcargoplanet`),
	KEY `defaultcargoship` (`defaultcargoship`),
	KEY `shipdevice` (`shipdevice`),
	KEY `planetdevice` (`planetdevice`),
	KEY `researchonly` (`researchonly`),
	KEY `goodevil` (`goodevil`),
	KEY `price` (`price`),
	KEY `hold_space` (`hold_space`)
) TYPE={$database_type}{$dbencoding}");
    db_op2_result("{$db_prefix}class_modules_planet", $res,__LINE__,__FILE__);
    // End class_modules_planet table
?>