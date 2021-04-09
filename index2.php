<?php 
    // Démarrage des sessions + include des classes + vérification de la session
    session_start(); 
    include('bdd.php');
    include('utilisateur.php'); 
    $user = new user($bdd);
    if(empty($_SESSION['Email']))
    {
        ?><script>window.location.replace("index.php");</script><?php
    }
?>

<!DOCTYPE html>
<html lang="fr">
<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Connecté</title>
</head>
<body>
<?php
    // On appelle la méthode déconnexion pour se déconnecter
    if(isset($_POST['deconnexion']))
    {
        $user->deconnexion();
    }
    ?>
    <!-- Formulaire de déconnexion "bouton se déconecter" -->
        <form action="" method="POST">
        <input type="submit" name="deconnexion" value="Se déconnecter">
        </form>   
<?php 
    if(isset($_POST['Programme']))
    {
        $user->Programme();
    }
    ?>
        <form action="" method="POST">
        <input type="submit" name="Programme" value="Crée un programme">
        </form>      
        
</body>
</html>