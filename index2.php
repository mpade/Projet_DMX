<?php
####################################################
####################################################
####################################################
#// PARTIE 1 : Dans la partie 1 on retrouve les    #
#// sessions puis les conditions qui vont          #
#// permettrent de crée,modifié ou encore          #
#// supprimer un programme dans la base de données.#
#                                                  #
#// PARTIE 2 : Dans la partie 2 on retrouve la     #
#// totalité des formulaire présents sur le site.  #
####################################################
####################################################
####################################################
?>

<?php 

            ####################################################
            ################<!-- PARTIE 1 -->###################
            #################################################### 
            
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
    
    // Si la session n'est pas rempli ou invalide l'utilisateur sera redirigé sur la page de connexion
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
            <script src="sources.js">
            
            </script>
        </head>
    <body>
    <?php

    // Requête permettant d'aller chercher tous les programmes en base de données 
    $selectprogrammes = $bdd->query("SELECT * FROM programme");
    $programmeindex = 0;

    $selectscene = $bdd->query("SELECT * FROM scene");
    $sceneindex = 0;

    // Boucle permettant d'afficher les scène dans une liste déroulante
     while($selectscenes = $selectscene->fetch())
     {
         $scene[$sceneindex++] = new gestion($selectscenes['Id_Scene'], $selectscenes['Nom']);
         
     }
    // Boucle permettant d'afficher dans la liste déroulante les programmes présents sur la base de données
    while($selectprogramme = $selectprogrammes->fetch()) 
    {

        $prog[$programmeindex++] = new gestion($selectprogramme['Id_Programme'], $selectprogramme['Nom']);
    }



   

    // Permet de supprimer les programmes présents dans la base de données
    if (isset($_GET["voirprogramme"])) 
    {

        foreach ($prog as $objetprogramme) 
        {
            if ($objetprogramme->getId() == $_GET["voirprogramme"]) 
            {
                $deleteprogrammes = $bdd->prepare("DELETE FROM programme WHERE Id_Programme =:id");
                $deleteprogrammes->execute([
                'id' => $objetprogramme->getId()
                ]);?>
                <script> function timedRefresh(timeoutPeriod) {
                    setTimeout("location.reload(true);",timeoutPeriod);
                }window.onload = timedRefresh(0); </script><?php
                
            }
        }
    }    

    // Permet de modifié le nom des programme présent dans la base de données
    if (isset($_GET["modifieprogramme"])) 
    {
    
        
        foreach ($prog as $objetprogramme) 
        {
            if ($objetprogramme->getId() == $_GET["modifieprogramme"]) 
            {
                
                ?>
                <form action="" method="POST">
                    <input type="text" name="nommodifiee" placeholder="Nouveau nom du programme">
                    <input type="submit"  name="nommodifie" value="Valider" >
                </form>
                <?php
                if(isset($_POST['nommodifie']))
                {
                    $bdd->query("UPDATE `programme` SET `Nom`='".$_POST['nommodifiee']."'WHERE `Id_Programme` = '".$objetprogramme->getId()."'");
                    
                ?>   <?php
                
                } 
            }
        }
    }
        ?>

    <?php 
            
        // Permet de créer des programme et enregistrer dans la base de données
        if(isset($_POST['Programme']))
        {
            
            ?>
                <!-- <form action="" method="POST"> -->
                <input type="text" name="nomprogramme" placeholder="Nom du programme" id="nameprog">
                
                <select name="modifieprogramme" id="namescene">
                    <?php
                        echo '<option value="0">Choisir les scènes</option>';
                        foreach ($scene as $objectscene)
                        { 
                            echo '<option value="' . $objectscene->getId() . '">' . $objectscene->getNom() . '</option>';
                        }
                        
                    ?>
                </select> 
                <input type="submit" name="ajoutprogramme" onclick="Programme_creation(nameprog)" value="Ajouter programme">
        <?php 
        }  
            // On appelle la méthode déconnexion pour se déconnecter
            if(isset($_POST['deconnexion']))
            {
                $user->deconnexion();
            }
           
            ####################################################
            ################<!-- PARTIE 2 -->###################
            ####################################################   
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
        
        <!-- Formulaire permettant de modifié le nom du programme -->
        <form action="" methode="GET">
            <select name="modifieprogramme">
                <?php
                    echo '<option value="0">Choisir un programme</option>';
                    foreach ($prog as $objectprogramme)
                    { 
                        echo '<option value="' . $objectprogramme->getId() . '">' . $objectprogramme->getNom() . '</option>';
                    }
                    
                ?>
            </select>
            <input type="submit" value=" Modifier programme"></input>
        </form>  

        <!-- Formulaire permettant d'accéder aux listes drag'n drop -->
        <form action="drag.js" method="POST">
            <input type="submit" name="drag" value="Drag'n Drop">
        </form> 
    </body>
</html>

























<!-- 
// if(isset($_POST['ajoutprogramme']))
    // {
    //     $programme->CreeProgramme($_SESSION['Email'], $_POST['nomprogramme']);
    // }  
    // Exécution après avoir cliqué sur le formulaire d'ajout de programme

    // $programme->setafficherprogramme($_SESSION['Email']);echo "c";
            // $programme = $programme->getNomProgramme(); -->