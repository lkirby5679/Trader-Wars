<H1>{$title}</H1>

<table border=0 cellspacing=0 cellpadding=2 width="100%" align=center>
<tr><td>
	<div align=center>
	<img src="images/icons/{$teamicon}"><br>
	<h3><font color=white><B>{$teamname}</B>
	<br><font size=2>"<i>{$teamdescription}</i>"</font></H3>
	
	{if $playerteammatch}
		<font color=white>
		{if $isplayercreator}
			$l_team_coord&nbsp;
		{else}
			$l_team_member&nbsp;
		{/if}
		{$l_options}<br><font size=2>
		{if $playerteammatch}
			[<a href='teams.php?command=9&team_id={$playerteamid}'>{$l_team_ed}</a>] - 
		{/if}
		[<a href=teams.php?command=7&team_id={$playerteamid}>{$l_team_inv}</a>] - [<a href=teams.php?command=4&team_id={$playerteamid}>{$l_team_cancelinv}</a>] - [<a href=teams.php?command=2&team_id={$playerteamid}>{$l_team_leave}</a>]</font></font>
	{/if}
	{if !$teaminvite}
		<br><br><font color=blue size=2><b>{$l_team_noinvite}</b></font><BR><br>
		{if $playerteamid == 0}
			{$l_team_ifyouwant}<BR>
	 		<a href="teams.php?command=6">{$l_clickme}</a> {$l_team_tocreate}<BR><BR>
		{/if}
	{else}
		<br><br><font color=blue size=2><b>{$l_team_injoin} 
		<a href=teams.php?command=1&team_id={$teaminvite}>{$inviteinfo}</A>.</b></font><BR>
		echo "<A HREF=teams.php?command=3&team_id={$teaminvite}>{$l_clickme}</A> {$l_team_tojoin} <B>{$inviteinfo}</B> {$l_team_or} <A HREF=teams.php?command=8&team_id={$teaminvite}>{$l_clickme}</A> {$l_team_reject}<BR><BR>
	{/if}

	</div>
	

<table cellspacing = "0" cellpadding = "0" width="799" border = "0" align="center">
				<tr>
					<td><img src = "templates/{$templatename}images/planet-top.gif"></td>
				</tr>
				<tr>
					<td background = "templates/{$templatename}images/planet-bg.gif">
						<table cellspacing = "0" cellpadding = "0" border = "0" width = "100%">
						<tr>
							<td><img src = "templates/{$templatename}images/spacer.gif" width = "10" height = "1"></td>
							<td>	
								<table cellspacing = "0" cellpadding = "0" border = "0" width="99%">
								<tr>
									<td colspan = "2"><img src = "templates/{$templatename}images/spacer.gif" width = "1" height = "10"></td>
								</tr>
<tr>
	<td><font color=white>{$l_team_members}</font></td>
	</tr>
	<tr bgcolor={$zonecolor}>
	<td bgcolor={$zonecolor}>&nbsp;</td>
	</tr><tr bgcolor=#000000>
	{php}
	for($i = 0; $i<$teamcount; $i++) {
		echo "<td> - $teammember[$i] ($l_score $memberscore[$i]])";
		if ($memberowner[$i]) {
			echo " - <font size=2>[<a href=\"teams.php?command=5&who=$memberid[$i]\">$l_team_eject</A>]</font></td>";
		} else {
			if ($iscreator[$i])
			{
				echo " - $l_team_coord</td>";
			}
		}
		echo "</tr><tr bgcolor=#000000>";
	}
	{/php}
	<td bgcolor=#000000><font color=white>{$l_team_pending} <B>{$teamname}</B></font></td>
	</tr><tr>
	{if $membercount != 0}
		</tr><tr bgcolor=#000000>
	{php}
		for($i = 0; $i<$membercount; $i++) {
			echo "<td> - $membername[$i]</td>";
			echo "</tr><tr bgcolor=#000000>";
		}
	{/php}
	{else}
		<td>{$l_team_noinvites} <B>{$teamname}</B>.</td>
		</tr><tr>
	{/if}
	</tr>	<tr>
									<td colspan = "2"><img src = "templates/{$templatename}images/spacer.gif" width = "1" height = "12"></td>
								</tr>																																											
								</table>
								

							</td>
							<td><img src = "templates/{$templatename}images/spacer.gif" width = "1" height = "1"></td>
						</tr>
						</table>
					</td>
				</tr>
				<tr>
					<td><img src = "templates/{$templatename}images/planet-bot.gif"></td>
				</tr>

</table>

</td></tr>

<tr><td><BR><BR><a href="teams.php">{$l_clickme}</a> {$l_team_menu}.<BR></td></tr>
<tr><td><br><br>{$gotomain}<br><br></td></tr>
</table>
