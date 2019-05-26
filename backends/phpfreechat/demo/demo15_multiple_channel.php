<?php

require_once dirname(__FILE__)."/../src/phpfreechat.class.php";

$params["serverid"] = md5(__FILE__); // calculate a unique id for this chat
$params["title"]    = "A simple chat with multiple/dynamic channels (rooms)";
$params["nick"]     = "guest";  // setup the intitial nickname
$params["channel"]  = isset($_GET["channel"]) ? $_GET["channel"] : "room1";
$chat = new phpFreeChat( $params );

?>
<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">
<html>
  <head>
    <meta http-equiv="content-type" content="text/html; charset=utf-8" />
    <title>phpFreeChat demo</title>

    <?php $chat->printJavascript(); ?>
    <?php $chat->printStyle(); ?>

  </head>

  <body>
  <p>Rooms list:</p>
  <ul>
    <li><a href="?channel=room1">#room1</a></li>
    <li><a href="?channel=room2">#room2</a></li>
  </ul> 

<?php
  $c =& phpFreeChatConfig::Instance();
  echo "<p>You are in #".$c->channel."</p>";
?>
<?php $chat->printChat(); ?>

<?php
  // print the current file
  echo "<h2>The source code</h2>";
  $filename = __FILE__;
  echo "<p><code>".$filename."</code></p>";
  echo "<pre style=\"margin: 0 50px 0 50px; padding: 10px; background-color: #DDD;\">";
  $content = file_get_contents($filename);
  echo htmlentities($content);
  echo "</pre>";
?>

  </body>
</html>
