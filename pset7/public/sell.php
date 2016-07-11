<?php
 require("../includes/config.php"); 
if($_SERVER["REQUEST_METHOD"]=="POST"){
    if(empty($_POST["symbol"])){
        apologize("Please enter the stock symbol.");
    }
    $stock = lookup($_POST["symbol"]);
    if($stock===false){
        apologize("Entered stock symbol was invalid.");
    }
    $rows=CS50::query("SELECT shares FROM portfolio WHERE user_id = ? and symbol = ?", $_SESSION["id"], strtoupper($_POST["symbol"]));
   if(count($rows)!=1){
       apologize("Entered stock symbol was invalid.");
   }
   else{
       $shares=$rows[0]["shares"];
       $value=$shares*$stock["price"];
       $query=CS50::query("DELETE FROM portfolio WHERE user_id =? AND symbol=?",$_SESSION["id"],strtoupper($_POST["symbol"]));
       if($query==false){
           apologize("Error during selling");
       }
       $query=CS50::query("UPDATE users SET cash=cash+? WHERE id=?",$value,$_SESSION["id"]);
       if($query==false){
           apologize("Error during selling");
       }
    $query = CS50::query("INSERT INTO history(user_id, type, symbol, shares, price, date) VALUES (?, ?, ?, ?, ?, Now())"
                ,$_SESSION["id"], 0, strtoupper($_POST["symbol"]), $shares, $stock["price"]);
       echo("Transaction Success");
   }    
}
?>
