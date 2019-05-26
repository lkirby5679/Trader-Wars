<!DOCTYPE html PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN">
<html>
 <head>
  <META HTTP-EQUIV="Content-Type" CONTENT="text/html; charset=ISO-8859-1">
  <link rel="icon" href="favicon.ico"> 
  <link rel="shortcut icon" href="favicon.ico" type="image/x-icon">
  <link rel="stylesheet" href="{$style_sheet_file}" type="text/css">
  <title>{$Title}</title>
 </head>
{if $no_body != 1}
<body marginheight=0 marginwidth=0 topmargin=0 leftmargin=0 background="
{php}
if(!isset($spiral_arm) || $spiral_arm == '')
	$spiral_arm = mt_rand(0,5);
if(is_file($gameroot."templates/".$templatename."images/galactic_arm" . $spiral_arm . ".jpg")){
 echo "templates/" . $templatename . "images/galactic_arm" . $spiral_arm . ".jpg";
}else{
 echo $header_bg_image;
}
{/php}
" bgcolor="#000000" text="#c0c0c0" link="#52ACEA" vlink="#52ACEA" alink="#52ACEA">
{$banner_top}
<table width="100%" border=0 cellspacing=0 cellpadding=0>
	<tr>		  
	  <td>
{/if}
