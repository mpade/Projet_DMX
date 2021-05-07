<?php

    // Paramètres du PDO (base de donnée,utilisateur,mot de passe)
    $dsn = 'mysql:dbname=Projet_DMX;host=192.168.64.102';
    $user = 'ROOT';
    $password = 'ROOT';

    // Permet de voir si la connexion à la base de données est bonne
    try
    {
        $bdd = new PDO($dsn, $user, $password);
        // Activation des erreurs PDO
        $bdd->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);
        // mode de fetch par défaut : FETCH_ASSOC / FETCH_OBJ / FETCH_BOTH
        $bdd->setAttribute(PDO::ATTR_DEFAULT_FETCH_MODE, PDO::FETCH_ASSOC);
    } 
    // Si le try n'est pas bon on retourne une erreur de connexion à la base de données
    catch (PDOException $e) 
    {
        echo 'Connexion échouée : ' . $e->getMessage();
    }

?>