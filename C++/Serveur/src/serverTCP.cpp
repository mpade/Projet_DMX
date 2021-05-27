#include "../include/serverTCP.h"

serverTCP::serverTCP()
{

}
bool serverTCP::createSocket()
{
   int opt = TRUE;
   this->sock = socket(AF_INET, SOCK_STREAM,0);

   if (this->sock != INVALID_SOCKET)
    {
        return true;
    }
    else
    {
        return false;
    }

}

bool serverTCP::connectServer(int port)
{

    int resultBindServer;

    sin.sin_addr.s_addr = htonl(INADDR_ANY);
    sin.sin_family = AF_INET;
    sin.sin_port = htons(port);

    resultBindServer = bind(this->sock, (SOCKADDR *)&sin, sizeof(sin));

    if (resultBindServer != SOCKET_ERROR)
    {
        cout << "Patientez pendant que le client se connecte sur le port " << port << "..." << endl;
        listen(this->sock, 6);
        return true;
    }
    else
    {
        return false;
    }
}

bool serverTCP::acceptCom()
{

    this->csock = accept(this->sock, (SOCKADDR *)&this->csin, &this->recsize);

    if (this->csock != -1)
    {
        notifyClientConnected(csock, csin, csin);
        return true;
    }
    else
    {
        return false;
    }

}

bool serverTCP::closeSocketClient()
{

    int resultCloseCSock;

    resultCloseCSock = close(this->csock);

    if (resultCloseCSock == 0)
    {
        return true;
    }
    else
    {
        return false;
    }

}

bool serverTCP::closeListenSocket()
{

    int resultCloseSocket;

    resultCloseSocket = close(this->sock);

    if (resultCloseSocket == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void serverTCP::addListener(TCPServerEventListener *l)
{
    listeners.push_back(l);}
void serverTCP::notifyClientConnected(SOCKET csock, SOCKADDR_IN csinIp, SOCKADDR_IN csinPort)
{
    for (int i = 0; i < listeners.size(); i++)
    {
        listeners[i]->onClientConnected(csock, csinIp, csinPort);
    }
}

string serverTCP::readBuffer()
{

    char bufferClient[50] = {0};
    int resultReadBuffer;

    resultReadBuffer = recv(this->csock, &bufferClient, sizeof(bufferClient), 0);
    // Gestion d'erreur du nouveau socket
    if (resultReadBuffer == -1)
    {
        cout << "erreur lors de la reception du message client" << endl;

    }
    else
    {
        // Le serveur affiche le message reçu
        cout << "Chaine reçu : " << bufferClient << endl;
return bufferClient;


    }


}
const std::vector<std::string> serverTCP::explode(const std::string& msg, const char& c)
{
	std::string buff = "";
	std::vector<std::string> v;
	for (int i = 0; i < msg.length(); i++)
	{
		char compare = msg[i];
		if (compare != c) buff += compare;
		else if (compare == c && buff != "")
		{
			v.push_back(buff);
			buff = "";
		}
	}
	if (buff != "")
		v.push_back(buff);

	return v;
}
serverTCP::~serverTCP()
{
    //dtor
}
