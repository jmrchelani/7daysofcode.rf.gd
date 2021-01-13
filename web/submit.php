<?php
require('connection.php');

$_ans = $_POST["answer"];
$_roll = $_POST["roll"];
$_day = gotIt($_POST["day"]);
$_points = [0, 15, 25, 25, 35, 75, 75, 75];

//Initialize the szQuery variable for usage with a long string.
$szQuery = " ";


//Format szQuery with the MySQL query.
$szQuery = "SELECT * FROM `" . $_UsersTable ."` WHERE `questionNo` = '" . $_day . "'";

//Gather the result for usage with mysql_fetch_object, and query szQuery. Will die with mysql_error if there is an error.
$_qResult = mysqli_query($_Connection, $szQuery) or die(mysqli_error($_Connection));

//If statement: if the number of rows queried is not 0; success
if(mysqli_num_rows($_qResult) != 0)
{
	//Fetch the user's info into $_qFetch to be used as an object to compare the password.
	$_qFetch = mysqli_fetch_object($_qResult);

	//This will check if $_qFetch->pass and $szEscapedPass are the same.
	if(strcmp($_qFetch->Answer, $_ans) == 0)
	{
        $_ez = getIt($_day);
        $szQuery = "SELECT * FROM `leaderboard` WHERE `roll` = '". $_roll ."'";
        $_qResult = mysqli_query($_Connection, $szQuery) or die(mysqli_error($_Connection));
        if(mysqli_num_rows($_qResult) != 0) {
            $_qFetch = mysqli_fetch_object($_qResult);
            $_ok = 'points';
            $_old = intval($_qFetch->$_ok);
            $_total = $_old + $_points[$_day];
            if($_qFetch->$_ez != 0) return header("Location: already.html");
            $szQuery = "UPDATE `leaderboard` SET `points` = '". $_total ."', `". $_ez ."` = 1 WHERE `roll` = '". $_roll ."'";
            $_qResult = mysqli_query($_Connection, $szQuery) or die(mysqli_error($_Connection));
            header("Location: success.html");
        } else {
            $szQuery = "INSERT INTO `leaderboard` (`roll`, `points`, `". $_ez ."`) VALUES ('". $_roll ."', ". $_points[$_day] .", 1)";
            $_qResult = mysqli_query($_Connection, $szQuery) or die(mysqli_error($_Connection));
            header("Location: success.html");
        }
	}
	else
	{
		//If false, send the user to index.
		header("Location: wrong.html");
	}
}


function getIt($num) {
    switch ($num) {
        case 1:
            return 'A';
        case 2:
            return 'B';
        case 3:
            return 'C';
        case 4:
            return 'D';
        case 5:
            return 'E';
        case 6:
            return 'F';
        case 7:
            return 'G';
    }
}

function gotIt($num) {
    switch ($num) {
        case "M":
            return 1;
        case "T":
            return 2;
        case "W":
            return 3;
        case "Y":
            return 4;
        case "F":
            return 5;
        case "S":
            return 6;
        case "D":
            return 7;
    }
}

?>