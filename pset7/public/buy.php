<?php
require("../includes/config.php"); 
if($_SERVER["REQUEST_METHOD"]=="POST"){
    if(empty($_POST["symbol"])|| !is_numeric($_POST["shares"]) || !preg_match("/^\d+$/", $_POST["shares"])){
        apologize("Empty correct stock value");
    }
     $stock = lookup($_POST["symbol"]);
        if ($stock ===false)
        {
            apologize("Entered stock symbol was invalid.");
        }
      else{
         
          $value=$stock["price"]*$_POST["shares"];
          $c=CS50::query("SELECT cash FROM users WHERE id=?",$_SESSION["id"]);
          $cash=$c[0]["cash"];
          if($cash<$value){
              apologize("You don't have sufficient amount of deposited money.");
          }
        else{
          $query=CS50::query("INSERT INTO portfolio(user_id,symbol,shares,price) VALUES(?,?,?,?) ON DUPLICATE KEY UPDATE shares = shares + VALUES(shares), price = VALUES(price)"
                    ,$_SESSION["id"], strtoupper($stock["symbol"]), $_POST["shares"], $stock["price"]);
          if ($query === false)
                {
                    apologize("Error while buying shares.");
                }
         else{
             $query = CS50::query("UPDATE users SET cash = cash - ? where id = ?", $value, $_SESSION["id"]);
                if ($query === false)
                {
                    apologize("Error while buying shares.");
                }
              $query = CS50::query("INSERT INTO history(user_id, type, symbol, shares, price, date) VALUES (?, ?, ?, ?, ?, Now())"
                    ,$_SESSION["id"], 1, strtoupper($stock["symbol"]), $_POST["shares"], $stock["price"]);
         
             echo("Transaction Success");
         }   
        }    
          
      }
}
?>