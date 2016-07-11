
</ul>
<table>

    <thead>
        <tr class="container">
            <th>Symbol</th>
            <th>Shares</th>
            <th>Price</th>
            <th>TOTAL</th>
        </tr>
    </thead>

    <tbody>
    <?php
	    foreach ($portfolio as $row)	
        {   
            echo("<tr class='container'>");
            echo("<td class='container'>" . $row["symbol"] . "</td>");
            echo("<td class='container'>" . $row["shares"] . "</td>");
            echo("<td class='container'>$" . number_format($row["price"], 2) . "</td>");
            echo("<td class='container'>$" . number_format($row["total"], 2) . "</td>");
            echo("</tr>");
        }
    ?>

    <tr>
        <td colspan="4">CASH</td>
        <td>$<?=number_format($users[0]["cash"], 2)?></td>
    </tr>

    </tbody>

</table>
