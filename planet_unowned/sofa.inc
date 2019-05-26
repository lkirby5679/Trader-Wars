<?php
include ("languages/$langdir/lang_attack.inc");
include ("globals/combat_functions.inc");
include ("globals/planet_bounty_check.inc");

		$isfedbounty = planet_bounty_check($playerinfo, $shipinfo['sector_id'], $ownerinfo, 0);

		if($isfedbounty > 0)
		{
			echo $l_by_fedbounty . "<BR><BR>";
		}
		else
		{
			echo $l_by_nofedbounty . "<BR><BR>";
		}

		if($planetinfo['owner'] != 3){
			$l_planet_att_link="<a href='planet.php?planet_id=$planet_id&command=attackpreview'>" . $l_planet_att_link ."</a>";
			$l_planet_att=str_replace("[attack]",$l_planet_att_link,$l_planet_att);
		}
		$l_planet_scn_link="<a href='planet.php?planet_id=$planet_id&command=scan'>" . $l_planet_scn_link ."</a>";
		$l_planet_scn=str_replace("[scan]",$l_planet_scn_link,$l_planet_scn);
		echo "$l_planet_att<BR>";
		echo "$l_planet_scn<BR>";

		echo "<a href='planet.php?planet_id=$planet_id&command=sofabomb'>$l_sofa</a><b>$l_planet_att_sure</b><BR>";
		echo "<BR><a href='planet.php?planet_id=$planet_id'>$l_clickme</a> $l_toplanetmenu<BR><BR>";

		if ($allow_ibank)
		{
			echo "$l_ifyouneedplan <A HREF=\"igb.php?planet_id=$planet_id\">$l_igb_term</A>.<BR><BR>";
		}

		echo "<A HREF =\"bounty.php\">$l_by_placebounty</A><p>";
		echo $l_global_mmenu;
		include ("footer.php");
		die();

?>