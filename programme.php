<?php

include("bdd.php");
include("utilisateur.php");



class Programme
{
    
    private $_AfficherProgramme;
    
    
     // Constructeur
     public function __construct($bdd)
     {      
        $this->_bdd = $bdd;
     }
    // Fonction permettant de crée un programme.
    function CreeProgramme($Email,$Nom)
    {
        // Requête SQL, permettant de sélectionner l'utilisateur connecté.
        $selectutilisateur = $this->_bdd->query('SELECT Id_Utilisateur FROM utilisateur WHERE Email = "'.$Email.'"');
        $selectutilisateur = $selectutilisateur->fetch();

        // Requête SQL, permettant d'ajouter un programme dans la base de données.
        $ajoutprogramme = $this->_bdd->query('INSERT INTO `programme` (`Nom`,`Id_Utilisateur`) VALUE ("'.$Nom.'","'.$selectutilisateur['Id_Utilisateur'].'")');
        
        // Requête SQL, permettant d'ajouter une ou des scènes à un programme présent en base de données.
        // $ajoutsceneprogramme =('UPDATE `programme` SET `NbScene`=[?]WHERE Id_Utilisateur = ?');


        // $clients = $this->$client->query('SELECT * FROM utilisateur');
    
        

    }
    function setafficherprogramme($Email)
    {
        $selectprogramme = $this->_bdd->query('SELECT programme.Nom FROM programme INNER JOIN utilisateur WHERE programme.Id_Utilisateur = utilisateur.Id_Utilisateur AND utilisateur.Email = "'.$Email.'"');
        $i=0;
        while($selectprogrammes= $selectprogramme->fetch())
        {
          $this->_AfficherProgramme[$i] = $selectprogrammes['Nom']; 
          $i++; 
          
        }
    }
    function getNomProgramme()
    {
        return $this->_AfficherProgramme;
    }
    function ajouterscene($Email,$Nom)
    {

    }
    
}


