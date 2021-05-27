<?php
session_start();
extract($_POST);  
//on extracte les informations reçu en js pour traitement en php après on le décode est on le mais dans tabreturn.
$tabReturn = json_decode($_POST['json'],true);
echo json_encode($tabReturn);
$tabReturn['mail'];
$tabReturn['name_prog'];
// $tabReturn['name_scene'];
include "../programme.php";
$programme = new programme($bdd);
$programme->CreeProgramme($_SESSION['email'],$tabReturn['name_prog']);






