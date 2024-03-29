<?php include('bdd.php'); ?>
<?php

    // Déclaration de la classe user
    class user
    {
        // Propriétés de la classe User
        private $_Nom;
        private $_Prenom;
        private $_Email;
        private $_Pass;
        
        // private $_Grade;
        
        
        
        // Constructeur
        function __construct($bdd)
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

            if ($result['MotDePasse'] == $Pass) 
            {
                $this->_Nom = $result['Nom'];
                $_SESSION['Id'] = $result['Id_Utilisateur'];
                return $result['Email'];
            } 
            else 
            {
                echo "Identifiant ou mot de passe incorrect";
            }
        }

        function Inscription($Nom,$Prenom,$Email,$Pass)
        {
            // Ajoute un utilisateur dans la Base de données
            $inscription = $this->_bdd->prepare("INSERT INTO `utilisateur` (`Id_Utilisateur`, `Nom`, `Prenom`, `Email`, `MotDePasse`) VALUES (NULL, :nom, :prenom, :email, :pass);"); // Requête qui insert en base les informations de l'utilisateur
            $inscription->execute([
                'nom' => $Nom,
                'prenom' => $Prenom,
                'email' => $Email,
                'pass' => $Pass
            ]);
            
        }

        function setinformations($Email)
        {
            $setinformations = $this->_bdd->query('SELECT Prenom,Nom FROM utilisateur WHERE Email = "'.$Email.'"');
            $setinformations = $setinformations->fetch();  
        }
        function getinformations()
        {
            $_Nom = $this->_Nom;
            $_Prenom = $this->_Prenom;
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
        
        
    }

?>