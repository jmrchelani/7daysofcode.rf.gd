
<?php
require('connection.php');
?>


<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Pro Programmer League</title>
    <link rel="stylesheet" href="styles.css"></link>
</head>
<body>
    <a href="index.html" style="text-align: center;">[ HOME ]</a>
    <header>
        <h1 class="logo">Leaderboard</h1>
    </header>
    <section>
        <hr>
        <div style="text-align: center; display: block;">
            
            <?php 
    
                $_pQuery = "SELECT * FROM `leaderboard` ORDER BY `points` DESC ";
                if ($result = $_Connection->query($_pQuery)) {
                    while($row = $result->fetch_assoc()) {
                        echo"<p>". $row["roll"] ." - ". $row["points"] ." point(s)</p>";
                    }
                } 
            
            ?>

        </div>
        <hr>
    </section>
    
    <section>
        <p>I am sorry If there is any kind of grammatical mistake or error, It is alright as long as you can understand what the hell the problem says. Thanks for your time.</p>
    </section>
</body>
</html>