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
        <div class="boxform">
            <div class="connexion">
                <!-- Formulaire de connexion -->
                <form action="index.php" method="POST">
                    <input type="text" name="email" placeholder="Adresse e-mail">
                    <input type="password" name="pass" placeholder="Mot de passe">
                    <input type="submit" name="connexion" value="Se connecter">
                </form>
            </div>
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
                ?><script>window.location.replace("index2.php");</script><?php
            }
        } 
    }
?>
    
  





