<?php 
    // Démarrage des sessions + include des classes + vérification de la session
    session_start(); 
    include('bdd.php');
    include('programme.php');
    $programme = new programme($bdd);
    $user = new user($bdd);
    $user->setinformations($_SESSION['Email']);
    echo $user->getNom();
    echo $user->getPrenom();
    
    
    
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
        
           
             
    if(isset($_POST['ajoutprogramme']))
    {
        $programme->CreeProgramme($_SESSION['Email'], $_POST['nomprogramme']);
    }  
    if(isset($_POST['Programme']))
    {
        
        ?>
        <form action="" method="POST">
            <input type="text" name="nomprogramme" placeholder="Nom du programme">
            <input type="checkbox" name="ajoutscene" value="Scene 1">
            <input type="checkbox" name="ajoutscene" value="Scene 2">
            <input type="checkbox" name="ajoutscene" value="Scene 3">     
            <input type="submit" name="ajoutprogramme" value="Ajouter programme">
        </form>  
       <?php
       

    }
    
    ?>
    
        <form action="" method="POST">
        <input type="submit" name="Programme" value="Crée un programme">
        </form> 
    <?php
        if(isset($_POST['voirprogramme']))
        {
            $programme->setafficherprogramme($_SESSION['Email']);
            $programme = $programme->getNomProgramme();
           
            for($i=0 ;$i<sizeof($programme); $i++)
            {
                echo $programme[$i];
            }
            
    ?>   
        
    <?php    
    }
    ?><form action="" method="POST">  
            <input type="submit" name="voirprogramme" value="Voir mes programme">
        </form> 
    
             
        
</body>
</html>