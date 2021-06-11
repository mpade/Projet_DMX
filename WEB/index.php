<?php 
    // Démarrage des sessions + include des classes
    session_start();
    include("bdd.php"); 
    include("utilisateur.php"); 
    
?>
<!DOCTYPE html>
<html lang="fr">
    <head>
        <link rel="stylesheet" href="CSS/style.css">
        <meta charset="UTF-8">
        <meta http-equiv="X-UA-Compatible" content="IE=edge">
        <meta name="viewport" content="width=device-width, initial-scale=1.0">
        <title>Accueil</title>
    </head>
    <body>
        <div class="connexion">
            <!-- Formulaire de connexion -->
            <form action="index.php" method="POST">
                <input type="text" name="email" placeholder="Adresse e-mail">
                <input type="password" name="pass" placeholder="Mot de passe">
                <input type="submit" name="connexion" value="Se connecter">
            </form>
        </div>
        <div class="inscription">
            <!-- Formulaire de connexion -->
            <form action="index.php" method="POST">
                <input type="text" name="nom" placeholder="Nom">
                <input type="text" name="prenom" placeholder="Prénom"> 
                <input type="text" name="email" placeholder="E-mail">
                <input type="password" name="pass" placeholder="Mot de passe">
                <input type="submit" name="inscription" value="S'inscrire">
            </form>
        </div>
    </body>
</html>

<?php

    // Traitement des données présentent dans le formulaire de connexion
    if (isset($_POST['connexion'])) 
    {
        if(isset($_POST['email']) && isset($_POST['pass']))
        {
            $user = new user($bdd);
            $_SESSION['Email'] = 
            $user->Connexion($_POST['email'], $_POST['pass']);
            if(empty($_SESSION['Email']))
            {
                return "Probleme de champs";    
            }
            else
            {
                ?><script>window.location.replace("Accueil.php");</script><?php
            }
        } 
    }

    if(isset($_POST['inscription'])){
        $user = new user($bdd);
        $_SESSION['Email'] = 
        $user->Inscription($_POST['nom'],$_POST['prenom'],$_POST['email'],$_POST['pass']);
        // if(empty($_POST['nom'] || $_POST['prenom'] || $_POST['email'] || $_POST['pass']))
        // {
        //     return "Probleme les champs sont pas remplis"
        // }
        // else
        // {

        // }
    }
?>
    
  




