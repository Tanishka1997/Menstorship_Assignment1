<?php
require("../includes/config.php"); 
if($_SERVER["REQUEST_METHOD"]=="POST")
{   if (empty($_POST["symbol"]))
        {
            apologize("Please enter the stock symbol.");
        }
    $s=lookup($_POST["symbol"]);
    if ($s=== false)
        {
            apologize("Entered stock symbol was invalid.");
        }
        else
        {
            
            render("quote_result.php", ["title" => "Quote", "symbol" => $s["symbol"], "name" => $s["name"], "price" => $s["price"]]);
        }
}
?>