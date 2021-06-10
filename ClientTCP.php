<?php

class TCPclient{

    private $_adress;
    private $_port;
    private $socket;
    private $_bdd;


    public function __construct($adress, $port, $bdd)
    {
        
        $this->_adress = $adress;
        $this->_port = $port;
        $this->_bdd = $bdd;
        
        

    }

    public function setConnexion(){
        //echo "Essai de connexion a '$this->_adress' sur le prot '$this->_port'....";
        $this->socket = socket_create(AF_INET,SOCK_STREAM, SOL_TCP);
        if($this->socket == false){
            echo "socket_create() a echoue :". socket_strerror(socket_last_error()). "<br>";
        }else{
        $result = socket_connect($this->socket, $this->_adress, $this->_port);
        if($this->socket == false){
            echo "socket_connect() a echoue :". socket_strerror(socket_last_error($this->socket)). "<br>";
        }else{
            //echo "ok <br>";
        }
    }
    }
    public function getWrite($idprog){


        // /r/equete pour aller chercher l'address des lampe et la value en bdd ainsi que le temps
       $i = 0;
        $SelectIdScene = $this->_bdd->query("SELECT Id_Scene FROM sceneprogramme WHERE Id_Programme = '".$idprog."'");
        while($SelectIdScenes = $SelectIdScene->fetch())
        {
             

            $selectIdSequence = $this->_bdd->query("SELECT Id_Sequence FROM sequencescene WHERE Id_Scene = '".$SelectIdScenes['Id_Scene']."' ORDER BY  sequencescene.Order ASC");
             
            while($selectIdSequences = $selectIdSequence->fetch())
            {
                $idsequence =$selectIdSequences['Id_Sequence'];

                $selectAdressEquipement = $this->_bdd->query("SELECT `Id_AdressEquipement` FROM `sequenceusedequipement` WHERE `Id_Sequence` = '".$selectIdSequences['Id_Sequence']."'");
                while($selectAdressEquipements = $selectAdressEquipement->fetch())
                {
                    

                    $selectAdressIdEquipement =$this->_bdd->query("SELECT `Adresse`,`Id_Equipement` FROM `adressequipement` WHERE `Id_AdressEquipement` =  '".$selectAdressEquipements['Id_AdressEquipement']."'");
                    while($selectAdressIdEquipements = $selectAdressIdEquipement->fetch())
                    {
                     $adresse = $selectAdressIdEquipements['Adresse'];

                        $selectIdPropertyOrder =$this->_bdd->query("SELECT `Id_Property`,`Order` FROM `property` WHERE `Id_Equipement` = '".$selectAdressIdEquipements['Id_Equipement']."'");
                        while($selectIdPropertyOrders = $selectIdPropertyOrder->fetch())
                        {
                            $selectValue =$this->_bdd->query("SELECT `value` FROM `valueproper` WHERE `id_property` = '".$selectIdPropertyOrders['Id_Property']."' and `id_sequence` = '".$idsequence."'");
                            $selectValues = $selectValue->fetch();
                            $adresse += $selectIdPropertyOrders['Order'] -1;
                            
                            $trame[$i] =  "CV:".$adresse.",".$selectValues['value'];
                            $i++;
                        }
                    }
                }
                $selectduree = $this->_bdd->query("SELECT `Duree` FROM `sequence` WHERE `Id_Sequence` = '".$selectIdSequences['Id_Sequence']."'");
                $selectdurees = $selectduree->fetch();
                $trame[$i] =  "TE:".$selectdurees['Duree'];
                $i++;
            }
        }

        for($x = 0; $x < count($trame); $x++)
        {
            
            $this->setConnexion();
            socket_write($this->socket, $trame[$x], strlen($trame[$x]));
            print_r($trame[$x]);
            $this->setClose();
           
        }
        
        
    }
    public function getRecv(){
        socket_recv($this->socket, $donnes,2048,0);
        return $donnes;
    }
    public function setClose(){
        socket_close($this->socket);
    }
    public function getAdress(){
        return $this->_adress;
    }
    public function getPort(){
        return $this->_port;
    }

}

?>