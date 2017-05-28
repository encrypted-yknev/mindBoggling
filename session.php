<?php

session_start();
$_SESSION["user"]=$name;
$_SESSION["name"]=$name_db;
$_SESSION["desc"]=$desc_db;
$_SESSION["location"]=$location_db;
$_SESSION["upvotes"]=$upvotes_db;
$_SESSION["downvotes"]=$downvotes_db;
?>