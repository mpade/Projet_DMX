<?php

session_start();
extract($_POST);

$tabReturn = json_decode($_POST['json'],true);
echo json_encode($tabReturn);
$tabReturn['name_prog'];
include "../programme.php";
$programme->ModifierProgramme($_SESSION['email'],$tabReturn['name_prog']);
