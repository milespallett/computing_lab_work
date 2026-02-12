<?php
$host = "cs22001.cf4dwpplygot.us-east-1.rds.amazonaws.com";
$username = "admin";
$password = "Scareball123!";
$database = "Week4";
$pdo = new PDO("mysql:host=".$host.";dbname=".$database,
$username, $password);
?>