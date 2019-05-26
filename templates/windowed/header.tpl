<!DOCTYPE html PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN">
<html>
 <head>
  <META HTTP-EQUIV="Content-Type" CONTENT="text/html; charset=ISO-8859-1">
  <link rel="icon" href="favicon.ico"> 
  <link rel="shortcut icon" href="favicon.ico">
  <link rel="stylesheet" href="{$style_sheet_file}" type="text/css">


<link rel="stylesheet" type="text/css" href="
{php}
if(is_file("templates/" . $templatename . "player_window_positions/" . $player_id . "_window_positions.css"))
{
	echo "templates/" . $templatename . "player_window_positions/" . $player_id . "_window_positions.css";
}
else
{
	echo "templates/" . $templatename . "player_window_positions/default_window_positions.css";
}
{/php}
">
  <title>{$Title}</title>
 </head>
{if $no_body != 1}
{if $currentprogram != "main.inc"}
<body marginheight=0 marginwidth=0 topmargin=0 leftmargin=0 background="templates/{$templatename}images/bgoutspace1.gif" bgcolor="#000000" text="#c0c0c0" link="#52ACEA" vlink="#52ACEA" alink="#52ACEA">
{else}
<body marginheight=0 marginwidth=0 topmargin=0 leftmargin=0 bgcolor="#222222" text="#c0c0c0" link="#52ACEA" vlink="#52ACEA" alink="#52ACEA">
{/if}
{$banner_top}

{if $currentprogram != "main.inc"}
<table width="100%" border=0 cellspacing=0 cellpadding=0>
	<tr>		  
	  <td>
{/if}
{/if}
