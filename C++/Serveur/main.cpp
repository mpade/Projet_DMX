#include <iostream>
#include "include/serverTCP.h"
#include "include/enttecdmxusb.h"
#define DMXDEVICE "/dev/ttyUSB0"
using namespace std;
class myServerEventListener : public TCPServerEventListener
{
public:
    virtual void onClientConnected(SOCKET csock, SOCKADDR_IN csinIp, SOCKADDR_IN csinPort)
    {
        cout << "Un client se connecte avec la socket " << csock << " avec l'ip " << inet_ntoa(csinIp.sin_addr) << " sur le port " << htons(csinPort.sin_port) << endl;
    };
};
int main()
{

   /* if(argc != 2)
    {
        printf("Usage : %s peripherique\n", argv[0]);
        printf("Exemple : %s /dev/ttyUSB0\n", argv[0]);
        return 1;
    }
    */

    //EnttecDMXUSB interfaceDMX(DMX_USB_PRO, argv[1]); // ou :
    EnttecDMXUSB interfaceDMX(DMX_USB_PRO, DMXDEVICE);
    string configurationDMX;

    /*if(interfaceDMX.IsAvailable())
    {
        configurationDMX = interfaceDMX.GetConfiguration();
        cout << "Interface " << interfaceDMX.GetNomInterface() << " detectee" << std::endl << configurationDMX << std::endl;

        interfaceDMX.ResetCanauxDMX();
        interfaceDMX.SendDMX();
        int canal  = 1;
        int valeur = 127;
        interfaceDMX.SetCanalDMX(canal, valeur);
        interfaceDMX.SendDMX();
    }
    else
        cout << "Interface non detectee !" << endl;
*/
    bool etat = false;

    myServerEventListener myEventListener;
    serverTCP  tcpServer;

    tcpServer.addListener(&myEventListener);

    if(tcpServer.createSocket() == true)
    {
        if(tcpServer.connectServer(9012) == true)
        {
            do
            {
                if ( tcpServer.acceptCom() == true)
                {
                    string readtcp = tcpServer.readBuffer();
                    std::vector<std::string> trame = serverTCP::explode(readtcp,';');
                    for(int i = 0; i < trame.size();i++){
        if (trame[i][0] == 'C' && trame[i][1] == 'V' )
        {
            string s = readtcp;
            int pos = s.find(':');
            string sud = s.substr(pos+1);
            std::vector<std::string> lines = serverTCP::explode(sud, ',');
            string configurationDMX;
            int canal  = atoi(lines[0].c_str());
            int valeur = atoi(lines[1].c_str());
            if(interfaceDMX.IsAvailable())
            {
                configurationDMX = interfaceDMX.GetConfiguration();
                cout << "Interface " << interfaceDMX.GetNomInterface() << " detectee" << std::endl << configurationDMX << std::endl;

            interfaceDMX.SetCanalDMX(canal, valeur);
            interfaceDMX.SendDMX();
            }
            else
                cout << "Interface non detectee !"<< endl;


        }else if(trame[i][0] == 'T' && trame[i][1] == 'E' )
        {
            string s = readtcp;
            int pos = s.find(':');
            string sud = s.substr(pos+1);

            sleep(atoi(sud.c_str()));
            if(interfaceDMX.IsAvailable())
            {
                configurationDMX = interfaceDMX.GetConfiguration();
                cout << "Interface " << interfaceDMX.GetNomInterface() << " detectee" << std::endl << configurationDMX << std::endl;

                interfaceDMX.ResetCanauxDMX();
                interfaceDMX.SendDMX();
            }
            else
                cout << "Interface non detectee !"<< endl;

        }else
        {
            if(interfaceDMX.IsAvailable())
            {
                configurationDMX = interfaceDMX.GetConfiguration();
                cout << "Interface " << interfaceDMX.GetNomInterface() << " detectee" << std::endl << configurationDMX << std::endl;

                interfaceDMX.ResetCanauxDMX();
                interfaceDMX.SendDMX();
            }
            else
                cout << "Interface non detectee !"<< endl;

        }
                }
                else
                {
                    cout << "Problème lorque le client essaie de se connecter" << endl;
                }
                }
                tcpServer.closeSocketClient();
            } while (etat != true);        }    }


    cout << "Hello world!" << endl;
    system("PAUSE");
    return 0;
}
