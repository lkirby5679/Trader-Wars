<h1>{$title}</h1>

<table width="500" border="1" cellspacing="0" cellpadding="4" align="center">
  <tr>
    <td bgcolor="#000000" valign="top" align="center" colspan=2>
		<table cellspacing = "0" cellpadding = "0" border = "0" width="100%">
<tr><td>
		<table cellspacing = "0" cellpadding = "0" border = "0" width="100%">
{if ($account_creation_closed)}
<tr>
	  <td>{$l_new_closed_message}
</td></tr>
{else}
<form action="new_player_process.php" method="post">
<tr>
	  <td>{$l_login_email}</td>
	  <td><input type="text" name="username" size="20" maxlength="40" value=""></td>
	</tr>
	<tr>
	  <td>{$l_new_shipname}</td>
	  <td><input type="text" name="shipname" size="20" maxlength="20" value=""></td>
	</tr>
	<tr>
	  <td>{$l_new_pname}</td>
	  <td><input type="text" name="character" size="20" maxlength="20" value=""></td>
	</tr>
{if $enable_profilesupport == 1 || $tournament_setup_access == 1 || $tournament_mode == 1 || $profile_only_server == 1}
	<tr>
	  <td colspan="2"><hr>{$l_profile_description}<br><br>
	  <input type="hidden" name="url" value="{$url}">
	  <input type="hidden" name="game" value="{$game}"></td>
	</tr>
	<tr>
	  <td>{$l_profile_name}</td>
	  <td><input type="text" name="profilename" size="30" maxlength="150"></td>
	</tr>
	<tr>
	  <td>{$l_profile_password}</td>
	  <td><input type="password" name="profilepassword" size="20" maxlength="20"></td>
	</tr>
	{if $tournament_setup_access == 1 || $tournament_mode == 1 || $profile_only_server == 1}
		<tr>
		  <td>{$l_profile_required}</td>
		</tr>
	{/if}
	<tr>
	  <td colspan="2"><hr><br></td>
	</tr>
{else}
	<input type="hidden" name="url" value="{$url}">
	<input type="hidden" name="game" value="{$game}">
	<input type="hidden" name="profilename" value="">
	<input type="hidden" name="profilepassword" value="">
{/if}
<input type="hidden" name="game_number" value="{$game_number}">
	<tr><td colspan 2>					  <input type="submit" value="{$l_submit}">
  <input type="reset" value="{$l_reset}">
</td></tr>
<tr><td colspan 2>
  <br><br>{$l_new_info}<br>
</td></tr>
</form>
{/if}
</td></tr>
<tr><td><br><br>{$gotomain}<br><br></td></tr>
		</table>
	</td>
  </tr>
</table>