<?php
    class gestion //Permet de faire la gestion des bateaux / utilisateurs présent dans la base de données.
    {

        #getID / getNom, permet d'afficher les informations 

        private $_id;
        private $_nom;


        public function __construct($id, $nom)
        {  
            $this->_id = $id;
            $this->_nom = $nom;

        }
        public function getId()
        {
            return $this->_id;
        }
        public function getNom()
        {
            return $this->_nom;
        }
    }
?>