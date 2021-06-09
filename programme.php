<?php

include("bdd.php");
include("utilisateur.php");



class Programme
{
    
    private $_AfficherProgramme;
    private $_id;
    
     // Constructeur
     public function __construct($bdd)
     {      
        $this->_bdd = $bdd;
     }
    // Fonction permettant de crée un programme.
    function CreeProgramme($Email,$Nom) 
    { 
      
        // Requête SQL, permettant d'ajouter un programme dans la base de données.
        $this->_bdd->beginTransaction();
        $selectid = $this->_bdd->query("SELECT * FROM `utilisateur` WHERE `Email`= '".$Email."'");
        
        $id = $selectid->fetch();
        
        $ajoutprogramme = $this->_bdd->query('INSERT INTO `programme`(`Id_Programme`, `Nom`,`Id_Utilisateur`) VALUES (NULL,"'.$Nom.'","'.$id['Id_Utilisateur'].'")');
        
        $Result = $this->_bdd->query($ajoutprogramme);
        $lastID = $this->_bdd->lastInsertId();
        if($lastID){ 
            $this->_id = $lastID;
            $this->_bdd->commit();
           
        }else{
            $this->_bdd->rollback();
            echo "erreur anormal create programe.php ".$req;
            return null;
        }
    }

    function AddSceneByID($idScene){

      $this->_bdd->query('INSERT INTO `sceneprogramme`(`Id_SceneProgramme`, `Id_Scene`, `Id_Programme`) VALUES (NULL,'.$idScene.','.$this->_id.')');

    }
    
    function setafficherprogramme($Email)
    {
      
        $selectprogramme = $this->_bdd->query('SELECT programme.Nom FROM programme INNER JOIN utilisateur WHERE programme.Id_Utilisateur = utilisateur.Id_Utilisateur AND utilisateur.Email = "'.$Email.'"');
        $i=0;
        while($selectprogrammes = $selectprogramme->fetch())
        { 
          $this->_AfficherProgramme[$i] = $selectprogrammes['Nom']; 
          $i++;  
        }
    }
    function getNomProgramme()
    {
      return $this->_AfficherProgramme;
    }
}
