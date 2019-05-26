<?php
// This program is free software; you can redistribute it and/or modify it   
// under the terms of the GNU General Public License as published by the	 
// Free Software Foundation; either version 2 of the License, or (at your	
// option) any later version.												
// 
// File: header.php

include ("config/config.php");
include ("languages/$langdir/lang_contact_admin.inc");

$title = $l_contact_admin_title;

if($playerinfo['template'] == '' or !isset($playerinfo['template'])){
	$templatename = $default_template;
}else{
	$templatename = $playerinfo['template'];
}
include ("header.php");

if($base_template[basename($_SERVER['PHP_SELF'])] == 1){
	include ("globals/base_template_data.inc");
}
else
{
	$template_object->assign("title", $title);
	$template_object->assign("templatename", $templatename);
}

function GetIP()
{
   if (getenv("HTTP_CLIENT_IP") && strcasecmp(getenv("HTTP_CLIENT_IP"), "unknown"))
           $ip = getenv("HTTP_CLIENT_IP");
       else if (getenv("HTTP_X_FORWARDED_FOR") && strcasecmp(getenv("HTTP_X_FORWARDED_FOR"), "unknown"))
           $ip = getenv("HTTP_X_FORWARDED_FOR");
       else if (getenv("REMOTE_ADDR") && strcasecmp(getenv("REMOTE_ADDR"), "unknown"))
           $ip = getenv("REMOTE_ADDR");
       else if (isset($_SERVER['REMOTE_ADDR']) && $_SERVER['REMOTE_ADDR'] && strcasecmp($_SERVER['REMOTE_ADDR'], "unknown"))
           $ip = $_SERVER['REMOTE_ADDR'];
       else
           $ip = "unknown";
   return($ip);
}/*-------GetIP()-------*/

$remote_ip=GetIP();

$debug_query = $db->Execute("SELECT * FROM {$db_prefix}ip_bans WHERE '$remote_ip' LIKE ban_mask and email > '3'");
db_op_result($debug_query,__LINE__,__FILE__);

if($debug_query->RecordCount() != 0)
{
	$l_contact_admin_thanks_comment = "<br><br><font color=\"red\" size=\"2\">This IP has been BANNED and nothing will be accepted from it.  <p>Have a Nice Day!</font><br>";
	$template_object->assign("l_contact_admin_thanks_comment", $l_contact_admin_thanks_comment);
	$template_object->assign("l_contact_admin_close", $l_contact_admin_close);
	$template_object->assign("l_contact_admin_email_alert", $l_contact_admin_email_alert);
	$template_object->display($default_template."contactthanks.tpl");

	$index_page = 1;
	include ("footer.php");
	die();
}

$template_object->assign("l_contact_admin_email_alert", $l_contact_admin_email_alert);
$template_object->assign("l_contact_admin_name_alert", $l_contact_admin_name_alert);
$template_object->assign("l_contact_admin_comment_alert", $l_contact_admin_comment_alert);
$template_object->assign("l_contact_admin_name", $l_contact_admin_name);
$template_object->assign("l_contact_admin_email", $l_contact_admin_email);
$template_object->assign("l_contact_admin_comment", $l_contact_admin_comment);
$template_object->assign("l_contact_admin_close", $l_contact_admin_close);
$template_object->assign("l_contact_admin_submit", $l_contact_admin_submit);

$template_object->display($default_template."contact.tpl");

$index_page = 1;
include ("footer.php");
?>

