<?php


class TCPclient{

    private $_adress;
    private $_port;
    private $socket;


    public function __construct($adress, $port)
    {
        $this->_adress = $adress;
        $this->_port = $port;
        $this->socket = socket_create(AF_INET,SOCK_STREAM, SOL_TCP);
        if($this->socket == false){
            echo "socket_create() a echoue :". socket_strerror(socket_last_error()). "<br>";
        }else{
            //echo "ok <br>";
        }

    }

    public function setConnexion(){
        //echo "Essai de connexion a '$this->_adress' sur le prot '$this->_port'....";
        $result = socket_connect($this->socket, $this->_adress, $this->_port);
        if($this->socket == false){
            echo "socket_connect() a echoue :". socket_strerror(socket_last_error($this->socket)). "<br>";
        }else{
            //echo "ok <br>";
        }
    }
    public function getWrite($nameprog){


        //requete pour aller chercher l'address des lampe et la value en bdd ainsi que le temps



        socket_write($this->socket, $buf, strlen($buf));
        
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