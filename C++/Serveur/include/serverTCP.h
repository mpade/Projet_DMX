
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <unistd.h>
#include <iostream>
#include <vector>
#include <thread>

#ifndef SERVERTCP_H
#define SERVERTCP_H

#define INVALID_SOCKET -1
#define SOCKET_ERROR -1
#define TRUE 1
#define FALSE 0
#include "enttecdmxusb.h"
#define DMXDEVICE "/dev/ttyUSB0"
using namespace std;

typedef int SOCKET;
typedef struct sockaddr_in SOCKADDR_IN;
typedef struct sockaddr SOCKADDR;

class TCPServerEventListener
{
public:
    virtual void onClientConnected(SOCKET csock, SOCKADDR_IN csinIp, SOCKADDR_IN csinPort) = 0;
};
class serverTCP
{
    public:
        serverTCP(EnttecDMXUSB);
        virtual ~serverTCP();
        bool createSocket();
        bool connectServer(int port);
        bool acceptCom();
        int readBuffer();
        bool sendBufferToClient(const char *bufferSendToClient);
        bool closeSocketClient();
        bool closeListenSocket();
        void addListener(TCPServerEventListener *);
    protected:

    private:
        static const std::vector<std::string> explode(const std::string& s, const char& c);
        EnttecDMXUSB interfaceDMX;
        SOCKET sock;
        SOCKADDR_IN sin;
        SOCKET csock;
        SOCKADDR_IN csin;
        socklen_t recsize = sizeof(csin);
        std::vector<TCPServerEventListener *> listeners;
        void notifyClientConnected(SOCKET csock, SOCKADDR_IN csinIp, SOCKADDR_IN csinPort);
};

#endif // SERVERTCP_H
