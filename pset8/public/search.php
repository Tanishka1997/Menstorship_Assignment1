<?php

    require(__DIR__ . "/../includes/config.php");

    // numerically indexed array of places
    $places = [];

   $geo=$_GET["geo"];
   $geo=trim($geo);
   $geo=explode(",",$geo);
   if(count($geo)==0){
       echo("Please enter a query string.");
   }
   if(count($geo)==1){
       $places=CS50::query("SELECT * FROM places WHERE postal_code LIKE ?","%".$_GET["geo"]."%");
       implode(" ",$geo);
   }
   else
   $places=CS50::query("SELECT * FROM places WHERE MATCH(postal_code, place_name,) AGAINST (?)", $_GET["geo"]);
    // output places as JSON (pretty-printed for debugging convenience)
    header("Content-type: application/json");
    print(json_encode($places, JSON_PRETTY_PRINT));

?>