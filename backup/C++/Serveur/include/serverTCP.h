#ifndef SERVERTCP_H
#define SERVERTCP_H
#include <string.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

class serverTCP
{
    public:
        serverTCP();
        virtual ~serverTCP();
        int createSocket(int);
    protected:

    private:
        int listenfd;
        struct sockaddr_in servaddr;
};

#endif // SERVERTCP_H
