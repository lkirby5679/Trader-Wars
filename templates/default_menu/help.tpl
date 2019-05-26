<H1>{$title}</H1>

<table cellspacing = "0" cellpadding = "0" width="799" border = "1" align="center">
				<tr>
					<td bgcolor="#000000">
						<table cellspacing = "0" cellpadding = "0" border = "0" width = "100%">
						<tr>
							<td><img src = "templates/{$templatename}images/spacer.gif" width = "10" height = "1"></td>
							<td>	
								<table cellspacing = "0" cellpadding = "0" border = "0" width="99%">
								<tr>
									<td colspan = "2"><img src = "templates/{$templatename}images/spacer.gif" width = "1" height = "10"></td>
								</tr><tr><td><p>
{php}
for($i = 0; $i < $templatecount; $i++){
	echo $templatehelp[$i];
}
{/php}
</td></tr>

			<tr>
									<td colspan = "2"><img src = "templates/{$templatename}images/spacer.gif" width = "1" height = "12"></td>
								</tr>																																											
								</table>
								

							</td>
							<td><img src = "templates/{$templatename}images/spacer.gif" width = "1" height = "1"></td>
						</tr>
						</table>
					</td>
				</tr>
</table>

<table border=0 cellspacing=0 cellpadding=2 width="100%" align="center">
<tr><td align="center"><a href="javascript:window.close();">{$l_help_closewindow}</a>
</td></tr>
</table>
