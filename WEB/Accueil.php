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
    include('ClientTCP.php');  
    
    $programme = new programme($bdd);
    $user = new user($bdd);
    $TCPclients = new TCPclient("192.168.65.103", "9012", $bdd);
    $TCPclients->setConnexion();
    $TCPclients->getWrite("48");

    // $user->setinformations($_SESSION['Email']);
    // echo $user->getNom();
    // echo $user->getPrenom();
    
    // Si la session n'est pas rempli ou invalide l'utilisateur sera redirigé sur la page de connexion
    if(empty($_SESSION['Email']))
    {
        ?><script>window.location.replace("index.php");</script><?php
        
    }
?>

<!DOCTYPE html>
    <html lang="fr">
        <head>
            <link rel="stylesheet" href="CSS/style2.css">
            <meta charset="UTF-8">
            <meta http-equiv="X-UA-Compatible" content="IE=edge">
            <meta name="viewport" content="width=device-width, initial-scale=1.0">
            <title>Connecté</title>
            <script src="sources.js">
            
            </script>
        </head>
    <body>
    
    <div class="deconnexion">
        <!-- Formulaire de déconnexion "bouton se déconecter" -->
        <form action="" method="POST">
            <input type="submit" name="deconnexion" value="Se déconnecter">
        </form> 
    </div>

    <div class ="retour">
            <!-- Formulaire permettant d'ajouter des scènes dans un programme -->
            <form action="" method="POST">
                <input type="submit" name="retour" value="Mettre à jour les données">
            </form> 
    </div>

    <?php

    // Requête permettant d'aller chercher tous les programmes en base de données 
    $selectprogrammes = $bdd->query("SELECT * FROM programme WHERE Id_Utilisateur = (SELECT `Id_Utilisateur` FROM `utilisateur` WHERE `Email` = '".$_SESSION['Email']."' )");
    $programmeindex = 0;
    
    // Boucle permettant d'afficher dans la liste déroulante les programmes présents sur la base de données
    while($selectprogramme = $selectprogrammes->fetch()) 
    {
        $prog[$programmeindex++] = new gestion($selectprogramme['Id_Programme'], $selectprogramme['Nom']);
    }

    $selectscene = $bdd->query("SELECT * FROM scene");
    $sceneindex = 0;

    // Boucle permettant d'afficher les scènes dans une liste déroulante
    while($selectscenes = $selectscene->fetch())
    {
        $scene[$sceneindex++] = new gestion($selectscenes['Id_Scene'], $selectscenes['Nom']);
    }

   
    $selectsceneprogramme = $bdd->query('SELECT * FROM programme INNER JOIN sceneprogramme ON programme.Id_Programme = sceneprogramme.Id_Programme INNER JOIN scene ON sceneprogramme.Id_Scene = scene.Id_Scene WHERE programme.Id_Programme = "'.$_GET['modifieprogramme'].'" ');
    $selectsceneprogrammeindex = 0;

    // Boucle permettant d'afficher les scènes faisant du programme sélectionner lors de la modification
    while($selectsceneprogrammes = $selectsceneprogramme->fetch())
    {
        $sceneprogramme[$selectsceneprogrammeindex++] = new gestion($selectsceneprogrammes['Id_SceneProgramme'],$selectsceneprogrammes['Nom']);
    }
    

    // BOUCLES PERMETTANT DE DE RECUPERER LES SCENES FAISANT PARTIT DU PROGRAMME SELECTIONNE.

            // Boucle permettant d'afficher dans la liste déroulante les programmes présents sur la base de données
            // while($modifieprogramme = $modifieprogrammes->fetch()) 
            // {

            //     $progs[$programmeindex++] = new gestion($selectprogramme['Id_Programme'], $selectprogramme['Nom']);
            // }
        
    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


   // Permet de créer des programme et enregistrer dans la base de données
   if(isset($_POST['Programme']))
   {
       ?>
           <div class="ajoutprog">
               <!-- <form action="" method="POST"> -->
               <form action="" method="POST">
               <input type="text" name="nomprogramme" placeholder="Nom du programme" id="nameprog">
               Choisir les scènes à ajouter : 
           
                   <?php
                           foreach ($scene as $objectscene)
                           {    echo  $objectscene->getNom();
                               ?><input type="checkbox" name="ajouterprogramme[]" id="namescene" value="<?php echo  $objectscene->getId() ?>"/>
                           
                               <?php 
                           }  
                   ?>
               <input type="submit" name="ajoutprogramme" value="Ajouter programme">
               </form> 
           </div>
   <?php 
   }  

    if(isset($_POST['ajoutprogramme']))
    {   
        $Program = new Programme($bdd);
        
        $Program->CreeProgramme($_SESSION['Email'],$_POST['nomprogramme']);
        
        foreach ($_POST['ajouterprogramme'] as $idScene)
        {   
            //Requet d'ajout dse idScene dans la tablescne programme
            $Program->AddSceneByID($idScene);

            if(!isset($checkoptions)){
                $checkoptions = $idScene;

            }else{

                $checkoptions .= ",".$idScene;
            }
        }   
        // echo "voici les id scenes : ".$checkoptions;
        // echo "Le programme à été crée avec succès";
    }

        // Permet de supprimer les programmes présents dans la base de données
        if (isset($_GET["supprimerprogramme"])) 
        {
                        $req = $bdd->prepare("DELETE FROM sceneprogramme WHERE Id_Programme =:id; DELETE FROM programme WHERE Id_Programme =:id");
                        $req->bindParam("id",$_GET["supprimerprogramme"],PDO::PARAM_INT);
                        $req->execute(); 
                        echo"programme supprimé avec succès";    
        }    
        
        // Permet de modifié le nom des programme présent dans la base de données
        if (isset($_GET["modifieprogramme"])) 
        {     
            foreach ($prog as $objetprogramme) 
            {
                if ($objetprogramme->getId() == $_GET["modifieprogramme"]) 
                {
                    
                    ?>
                    <div class="modifier">
                    <form action="" method="POST">
                        <input type="text" name="nommodifiee" placeholder="Nouveau nom du programme">
                        <input type="submit"  name="nommodifie" value="Valider la modification" >
                    </form>
                    
                    <select name="voirsceneprogramme">
                        <?php
                            echo '<option value="0">Vos scène sont : </option>';
                            foreach ($sceneprogramme as $objectsceneprogramme)
                            { 
                                echo '<option value="' . $objectsceneprogramme->getId() . '">"'.$objectsceneprogramme->getNom().'"</option>';
                            }
                        ?>
                    </select>
                    </div>
                    <?php
                    
                    if(isset($_POST['nommodifie']))
                    {
                        $bdd->query("UPDATE `programme` SET `Nom`='".$_POST['nommodifiee']."'WHERE `Id_Programme` = '".$objetprogramme->getId()."'");
                        // echo"Le nom du programme a été modifié avec succès";      
                    } 
                }
            } 
        }
        ?>
        <div class ="voirprogramme">
            <?php
                if(isset($_POST['voirprogramme']))
                {
                
                    $programme = new programme($bdd);
                    $programme->setafficherprogramme($_SESSION['Email']);
                    $programme->getNomProgramme();
            ?>
                    Vos programmes, sont le :
            <?php
                    foreach($programme->getNomProgramme() as $objectprogramme)
                    {
                        echo $objectprogramme,'    /    ';
                    }
                    
                }
            ?>  
        </div>

        
    <?php 

        if(isset($_POST['ajouterscenesprogramme']))
        {
            ?>
                <!-- rajouter la méthode d'ajout de scène en bdd sans le nom du programme -->
            <?php
        }

        if(isset($_POST['supprimersceneprogramme']))
        {
            ?>
                <!-- rajouter la méthode de suppresion de scènes dans la bdd sans supprimer le programme -->
            <?php
        }

        if(isset($_POST['lancerprogramme']))
        {
            $TCPclients = new TCPclient("192.168.65.103", "9012", $bdd);
            $TCPclients->setConnexion();
            $TCPclients->getWrite(48);
        }
        
        if(isset($_POST['retour']))
        {
            ?> <script>window.location.replace("Accueil.php");</script> <?php
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
        <div class="creer">
            <!-- Formulaire permettant de crée un programme" -->
            <form action="" method="POST">
                <input type="submit" name="Programme" value="Crée un programme">
            </form> 
        </div>
        
        <div class="supprimer">
            <!-- Formulaire permettant de supprimer un programme" -->
            <form action="" method="GET">
                <select name="supprimerprogramme">
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
        </div>
        
        <div class="modifie">
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
        </div>   
        
        <div class="voirprogramme">
            <!-- Formulaire permettant de crée un programme" -->
            <form action="" method="POST">
                <input type="submit" name="voirprogramme" value="Voir mes programmes">
            </form> 
        </div>

        <div class ="ajouterscenesprogramme">
            <!-- Formulaire permettant d'ajouter des scènes dans un programme -->
            <form action="" method="POST">
                <input type="submit" name="ajouterscenesprogramme" value="Ajouter des scènes">
            </form> 
        </div>

        <div class ="supprimersceneprogramme">
            <!-- Formulaire permettant d'ajouter des scènes dans un programme -->
            <form action="" method="POST">
                <input type="submit" name="supprimersceneprogramme" value="Supprimer des scènes">
            </form> 
        </div>

        <div class ="lancerprogramme">
            <!-- Formulaire permettant d'ajouter des scènes dans un programme -->
            <form action="" method="POST">
                <input type="submit" name="lancerprogramme" value="Lancer le programme">
            </form> 
        </div>
        
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