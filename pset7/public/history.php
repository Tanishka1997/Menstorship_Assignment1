
<table>
    <thead>
    <tr class="container">
        <th>
        Type    
        </th>
        <th>
            Symbol
        </th>
        <th>
            Shares
        </th>
        <th>
            Price
        </th>
        <th>
        Date
        </th>    
    </tr>
    </thead>
    <tbody
    
        <?php 
        require("../includes/config.php"); 
        $t=CS50::query("SELECT type,symbol,shares,price,date FROM history WHERE user_id=?",$_SESSION["id"]);
        $b;
        foreach($t as $row){
           if($row["type"]){
           $b="Buy";    
           }
           else
           $b="Sell";
           echo ("<tr>");
            echo("<td>".$b."</td>");
            echo("<td>".$row["symbol"]."</td>");
            echo("<td>".$row["shares"]."</td>");
            echo("<td>".$row["price"]."</td>");
            echo("<td>".$row["date"]."</td>");
        }
         echo ("</tr>");
        ?>
   
  </tbody>
</table>