<?php
$host = "database-1.cnq6yies61hk.us-east-1.rds.amazonaws.com";
$username = "admin";
$password = "none-of-your-business";
$database = "MyDandee";
$pdo = new PDO("mysql:host=".$host.";dbname=".$database,
$username, $password);
?>