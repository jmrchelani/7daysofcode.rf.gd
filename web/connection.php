<?php

$_Host = "";
$_User = "";
$_Pass = "";

$_Database = "";

$_UsersTable = "";

//Connect to MySQL using mysql_connect()
$_Connection = mysqli_connect($_Host, $_User, $_Pass) or die(mysql_error()); 
//Select the database defined in $_Database.
mysqli_select_db($_Connection, $_Database);

?>