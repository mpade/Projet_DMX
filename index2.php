<?php 
    // Démarrage des sessions + include des classes + vérification de la session
    session_start(); 
    include('bdd.php');
    include('gestion.php');
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
$selectprogrammes = $bdd->query("SELECT * FROM programme");
$programmeindex = 0;

while($selectprogramme = $selectprogrammes->fetch()) 
{
    $prog[$programmeindex++] = new gestion($selectprogramme['Id_Programme'], $selectprogramme['Nom']);
}

if (isset($_GET["voirprogramme"])) 
{
    foreach ($prog as $objetprogramme) 
    {
        if ($objetprogramme->getId() == $_GET["voirprogramme"]) 
        {
            $deleteprogrammes = $bdd->prepare("DELETE FROM programme WHERE Id_Programme =:id");
            $deleteprogrammes->execute([
            'id' => $objetprogramme->getId()
            ]);
            
        }
    }
}

if (isset($_GET["modifieprogramme"])) 
{
 
    
    foreach ($prog as $objetprogramme) 
    {
        if ($objetprogramme->getId() == $_GET["modifieprogramme"]) 
        {
            
            ?>
            <form action="" method="POST">
                <input type="text" name="nommodifiee" placeholder="Nouveau nom du programme">
                <input type="submit" name="nommodifie" value="Valider">
                </form>
            <?php
            if(isset($_POST['nommodifie']))
            {
                echo "le nom à bien été modifié";
                $bdd->query("UPDATE `programme` SET `Nom`='".$_POST['nommodifiee']."'WHERE `Id_Programme` = '".$objetprogramme->getId()."'");
            }  
        }
    }
}
    // On appelle la méthode déconnexion pour se déconnecter
    if(isset($_POST['deconnexion']))
    {
        $user->deconnexion();
    }
    ?>


     <!-- TOUS LES FORMULAIRES -->

      
<?php 
        
        // Exécution après avoir cliqué sur le formulaire de modification de programme   
          
       
        // Exécution après avoir entré le nom du programme à modifié
        if(isset($_POST['modifieprogramme2']))
            {
                ?>
                <form action="" method="POST">
                <input type="text" name="nommodifie" placeholder="Nouveau nom du programme">
                <input type="submit" name="nommodifie" value="Valider">
                </form>
                <?php
            } 
            // Exécution après avoir entré le nouveau nom du programme
            
            
    // Exécution après avoir cliqué sur le bouton d'ajout programme
    if(isset($_POST['ajoutprogramme']))
    {
        $programme->CreeProgramme($_SESSION['Email'], $_POST['nomprogramme']);
    }  
    // Exécution après avoir cliqué sur le formulaire d'ajout de programme
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
    
    
    

            // $programme->setafficherprogramme($_SESSION['Email']);echo "c";
            // $programme = $programme->getNomProgramme();
        

            
    ?>   
        
    
    
             
    <!-- Formulaire de déconnexion "bouton se déconecter" -->
    <form action="" method="POST">
        <input type="submit" name="deconnexion" value="Se déconnecter">
    </form> 

    <!-- Formulaire permettant de crée un programme" -->
    <form action="" method="POST">
        <input type="submit" name="Programme" value="Crée un programme">
    </form> 

    <!-- Formulaire permettant de supprimer un programme" -->
    <form action="" methode="GET">
        <select name="voirprogramme">
            <?php
                echo '<option value="0">Choisir un programme</option>';
                foreach ($prog as $objectprogramme)
                { 
                    echo '<option value="' . $objectprogramme->getId() . '">' . $objectprogramme->getNom() . '</option>';
                }
            ?>
        </select>
        <input type="submit" value="Supprimer programme"></input>
    </form>
     



    <form action="" methode="GET">
        <select name="modifieprogramme">
            <?php
                echo '<option value="0">Choisir un programme</option>';
                foreach ($prog as $objectprogramme)
                { //envoi les informations du tableau bateau a objetbateau là on travaille en objet
                    echo '<option value="' . $objectprogramme->getId() . '">' . $objectprogramme->getNom() . '</option>';
                }
            ?>
        </select>
        <input type="submit" value=" Modifier programme"></input>
    </form>
     

    

    
    
</body>
</html>