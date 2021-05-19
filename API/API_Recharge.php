<?php
include "../bdd.php";
include "../gestion.php";
$selectprogrammes = $bdd->query("SELECT * FROM programme");
$programmeindex = 0;

// while($selectprogramme = $selectprogrammes->fetch()) 
// {
//     $prog[$programmeindex++] = new gestion($selectprogramme['Id_Programme'], $selectprogramme['Nom']);
// }

echo json_encode($selectprogrammes->fetch());