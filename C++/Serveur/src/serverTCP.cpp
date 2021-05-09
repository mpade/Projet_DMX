#include "../include/serverTCP.h"

serverTCP::serverTCP(EnttecDMXUSB inter)
{
    interfaceDMX = inter;
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

int serverTCP::readBuffer()
{

    char bufferClient[50] = {0};
    int resultReadBuffer;

    resultReadBuffer = recv(this->csock, &bufferClient, sizeof(bufferClient), 0);
    // Gestion d'erreur du nouveau socket
    if (resultReadBuffer == -1)
    {
        cout << "erreur lors de la reception du message client" << endl;
        return -1;
    }
    else
    {
        // Le serveur affiche le message reçu
        cout << "Chaine reçu : " << bufferClient << endl;

        if (bufferClient[0] == 'C' && bufferClient[1] == 'V' )
        {
            string s = bufferClient;
            int pos = s.find(':');
            string sud = s.substr(pos+1);
            std::vector<std::string> lines = serverTCP::explode(sud, ',');
            string configurationDMX;

            if(interfaceDMX.IsAvailable())
            {
                configurationDMX = interfaceDMX.GetConfiguration();
                cout << "Interface " << interfaceDMX.GetNomInterface() << " detectee" << std::endl << configurationDMX << std::endl;

            interfaceDMX.ResetCanauxDMX();
            interfaceDMX.SendDMX();
            int canal  = 1;
            int valeur = 127;
            interfaceDMX.SetCanalDMX(atoi(lines[0].c_str()), atoi(lines[1].c_str()));
            interfaceDMX.SendDMX();
            }
            else {
                cout << "Interface non detectee !" << endl;
                return 0;
                }
        }else if(bufferClient[0] == 'T' && bufferClient[1] == 'E' )
        {
            string s = bufferClient;
            int pos = s.find(':');
            string sud = s.substr(pos+1);

            sleep(atoi(sud.c_str()));
        }
        return 1;
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
