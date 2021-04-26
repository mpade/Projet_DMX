<?php 
    include("bdd.php");  ?>
<?php

    // Déclaration de la classe user
    class user
    {
        // Propriétés de la classe User
        private $_Nom;
        private $_Prenom;
        private $_Email;
        private $_Pass;
        private $_Grade;
        private $_AfficherProgramme;
        
        
        // Constructeur
        public function __construct($bdd)
        {      
            $this->_bdd = $bdd;
        }

        // Méthodes de la classe User
        
        // Fonction qui permet à l'utilisateur de se connecter à l'IHM WEB
        function Connexion($Email,$Pass)
        {
                $req = $this->_bdd->prepare("SELECT * FROM `utilisateur` WHERE `utilisateur`.`Email` = :email AND `utilisateur`.`MotDePasse` = :pass");
                $req->bindParam('email', $Email, PDO::PARAM_STR);
                $req->bindParam('pass', $Pass, PDO::PARAM_STR);
                $req->execute();
                $result = $req->fetch(PDO::FETCH_ASSOC);
    
                if ($result['MotDePasse'] == $Pass) {
                    $this->_Nom = $result['Nom'];
                    return $result['Email'];
                } else {
                    echo "Identifiant ou mot de passe incorrect";
                }
            }

        function setNom($Email)
        {
            $setNom = $this->_bdd->query('SELECT Nom FROM utilisateur WHERE Email = "'.$Email.'"');
            $setNom = $setNom->fetch();  
            $this->_Nom = $setNom['Nom'];
        }
        function setPrenom($Email)
        {
            $setPrenom = $this->_bdd->query('SELECT Prenom FROM utilisateur WHERE Email = "'.$Email.'"');
            $setPrenom = $setPrenom->fetch();  
            $this->_Prenom = $setPrenom['Prenom'];
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
    
        // Fonction qui retourne l'adresse mail de l'utilisateur
        function getEmail()
        {
            return $this->_Email;
        }
        // Fonction qui retourne le nom de l'utilisateur
        function getNom()
        {
            return $this->_Nom;
        }
        // Fonction qui retourne le prénom de l'utilisateur
        function getPrenom()
        {
            return $this->_Prenom;
        }
        function getNomProgramme()
        {
            return $this->_AfficherProgramme;
        }
        // Fonction qui retourne le grade de l'utilisateur
        function getGrade()
        {
            return $this->_Grade;
        }

        function deconnexion()
        {
            session_destroy();
            session_unset();   
            ?><script>window.location.replace("index.php");</script><?php
        }
        // Fonction permettant de crée un programme.
        function Programme($Email,$Nom)
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

        
    }

?>