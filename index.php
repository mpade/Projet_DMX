<?php 
    // Démarrage des sessions + include des classes
    session_start();
    include("bdd.php"); 
    include("utilisateur.php"); 
    
?>
<!DOCTYPE html>
<html lang="fr">
    <head>
        <meta charset="UTF-8">
        <meta http-equiv="X-UA-Compatible" content="IE=edge">
        <meta name="viewport" content="width=device-width, initial-scale=1.0">
        <title>Accueil</title>
    </head>
    <body>
        <!-- Formulaire de connexion -->
        <form action="index.php" method="POST">
            <input type="text" name="email" placeholder="Adresse e-mail">
            <input type="password" name="pass" placeholder="Mot de passe">
            <input type="submit" name="connexion" value="Se connecter">
        </form>
    </body>
</html>

<?php

    // Traitement des données présentent dans le formulaire de connexion
    if (isset($_POST['connexion'])) 
    {
        if(isset($_POST['email']) && isset($_POST['pass']))
        {
            $user = new user($bdd);
            $user->Connexion($_POST['email'], $_POST['pass']);
        }

        
    }
  
    
?>




