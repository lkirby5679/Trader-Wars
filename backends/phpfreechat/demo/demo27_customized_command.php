<?php


// create the customized command
require_once dirname(__FILE__)."/../src/pfccommand.class.php";
class pfcCommand_roll extends pfcCommand
{
  function run(&$xml_reponse, $clientid, $msg)
  {
    $c =& $this->c;
    
    $nick      = $c->nick;
    $container =& $c->getContainerInstance();
    $text      = trim($msg);
    
    // Call parse roll
    require_once dirname(__FILE__).'/demo27_dice.class.php';
    $dice = new Dice();
    if (!$dice->check($text))
    { 
      $result = $dice->error_get();
      $cmd =& pfcCommand::Factory("error", $c);
      $cmd->run($xml_reponse, $clientid, "Cmd_roll failed: " . $result);
    }
    else
    {
      $result = $dice->roll();
      $container->writeMsg($nick, $result);
    }
    if ($c->debug) pxlog("Cmd_roll[".$c->sessionid."]: msg=".$result, "chat", $c->getId());
  }
}


// create the chat
require_once dirname(__FILE__)."/../src/phpfreechat.class.php";
$params = array();
$params["serverid"]       = md5(__FILE__); // calculate a unique id for this chat
$params["title"]          = "A chat with a customized command (dice roll) - try /roll 2d6";
$params["nick"]           = "guest";
//$params["debug"]          = true;
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