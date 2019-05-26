<H1>{$title}</H1>

<table width="80%" border="0" cellspacing="0" cellpadding="0" align="center">
  <tr>
		<td width=18><img src = "templates/{$templatename}images/g-top-left.gif"></td>
		<td width=101><img src = "templates/{$templatename}images/g-top-midleft.gif"></td>
		<td width="100%"><img src = "templates/{$templatename}images/g-top-midright.gif" width="100%" height="20"></td>
		<td width=18><img src = "templates/{$templatename}images/g-top-right.gif"></td>
  </tr>
  <tr>
    <td background="templates/{$templatename}images/g-mid-left.gif">&nbsp;</td>
    <td bgcolor="#000000" valign="top" align="center" colspan=2>
		<table cellspacing = "0" cellpadding = "0" border = "0" width="100%">

{if $confirm == "add"}
	<form action="warpedit_add.php" method="post">
	<input type="hidden" name="oneway" value={$oneway}>
	<input type="hidden" name="target_sector" value={$target_sector}>

	<tr><td>{$l_player}&nbsp;{$l_credits}: {$playercredits}</td></tr>
	<tr><td>{$l_ship}&nbsp;{$l_energy}: {$shipenergy}</td></tr>
	<tr><td>&nbsp;</td></tr>
	{if $cost != 0}
		<tr><td>{$l_warp_create}{$startsector}{$l_warp_andsector}{$target_sector}{$l_warp_distance}{$distance}{$l_warp_lightyears}.<br><br>
		{$l_warp_costcreate}&nbsp;{$cost} credits<br><br>{$l_warp_costenergy}{$energycost}<br><br></td></tr>
	{/if}
	<tr><td>{$l_warp_query}&nbsp;{$target_sector}</td></tr>
	<tr><td>{$l_warp_oneway}&nbsp;
	{if $oneway == "oneway"}
		{$l_yes}
	{else}
		{$l_no}
	{/if}
	<br><br></td></tr>

	<tr><td><input type="submit" value="{$l_submit}" onclick="clean_js()"><input type="reset" value="{$l_reset}"></td><tr>
	</form>
{/if}

{if $confirm == "delete"}
	<form action="warpedit_delete.php" method="post">
	<input type="hidden" name="bothway" value={$bothway}>
	<input type="hidden" name="target_sector" value={$target_sector}>

	<tr><td>{$l_player}&nbsp;{$l_credits}: {$playercredits}</td></tr>
	<tr><td>{$l_ship}&nbsp;{$l_energy}: {$shipenergy}</td></tr>
	<tr><td>&nbsp;</td></tr>
	{if $cost != 0}
		<tr><td>{$l_warp_delete}{$startsector}{$l_warp_andsector}{$target_sector}{$l_warp_distance}{$distance}{$l_warp_lightyears}.<br><br>
		{$l_warp_costdelete}&nbsp;{$cost} credits<br><br>{$l_warp_costenergy}{$energycost}<br><br></td></tr>
	{/if}
	<tr><td>{$l_warp_destquery}&nbsp;{$target_sector}</td></tr>
	<tr><td>{$l_warp_bothway}?&nbsp;{if $bothway == "bothway"}
		{$l_yes}
	{else}
		{$l_no}
	{/if}
	<br><br></td></tr>

	<tr><td><input type="submit" value="{$l_submit}" onclick="clean_js()"><input type="reset" value="{$l_reset}"></td><tr>
	</form>
{/if}
<tr><td colspan=2><br><br>{$gotomain}<br><br></td></tr>
		</table>
	</td>
    <td background="templates/{$templatename}images/g-mid-right.gif">&nbsp;</td>
  </tr>
  <tr>
		<td width=18><img src = "templates/{$templatename}images/g-bottom-left.gif"></td>
		<td width=101><img src = "templates/{$templatename}images/g-bottom-midleft.gif"></td>
		<td width="100%"><img src = "templates/{$templatename}images/g-bottom-midright.gif" width="100%" height="12"></td>
		<td width=18><img src = "templates/{$templatename}images/g-bottom-right.gif"></td>
  </tr>
</table>
