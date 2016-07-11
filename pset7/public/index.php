<?php

    // configuration
    require("../includes/config.php"); 
     $rows =CS50::query("SELECT * FROM portfolio WHERE user_id = ?", $_SESSION["id"]);	
	
	$portfolio = [];
	
	foreach ($rows as $row)	
    {   
        
        $stock = lookup($row["symbol"]);
        
        
        $stock["shares"] = $row["shares"];
        
    
        $stock["total"] = $row["shares"] * $stock["price"];
        
        
        $portfolio[] = $stock;
    }
    
    
   $users = CS50::query("SELECT * FROM users WHERE id = ?", $_SESSION["id"]);
    // render portfolio 
    render("portfolio.php", ["title" => "Portfolio", "portfolio" => $portfolio, "users" => $users]);

?>
