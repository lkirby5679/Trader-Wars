<?php

require_once dirname(__FILE__)."/demo31_show_who_is_online-config.php";

$container =& $pfc_config->getContainerInstance();
$users = $container->getOnlineNick();
$lastmsg = $container->readNewMsg(0);
print_r($lastmsg);

echo "<h1>A demo which explains how to get the connected users list</h1>";

echo '<div style="margin: auto; width: 70%; border: 1px solid red; background-color: #FDD; padding: 1em;">';
$info = "";
$nb_users = count($users);
if ($nb_users <= 1)
  $info = "<strong>%d</strong> user is connected to the <strong>'%s'</strong> channel !";
else
  $info = "<strong>%d</strong> users are connected to the <strong>'%s'</strong> channel !";
echo "<p>".sprintf($info, $nb_users, $pfc_config->channel)."</p>";

echo "<p>Here is the nicknames' list:</p>";
echo "<ul>";
foreach($users as $u)
{
  echo "<li>".$u."</li>";
}
echo "</ul>";
echo "</div>";

?>

<?php
  // print the current file
  echo "<h2>The source code</h2>";

  $filename = dirname(__FILE__)."/demo31_show_who_is_online-config.php";
  echo "<p><code>".$filename."</code></p>";
  echo "<pre style=\"margin: 0 50px 0 50px; padding: 10px; background-color: #DDD;\">";
  $content = file_get_contents($filename);
  echo htmlentities($content);
  echo "</pre>";

  $filename = __FILE__;
  echo "<p><code>".$filename."</code></p>";
  echo "<pre style=\"margin: 0 50px 0 50px; padding: 10px; background-color: #DDD;\">";
  $content = file_get_contents($filename);
  echo htmlentities($content);
  echo "</pre>";
?>
