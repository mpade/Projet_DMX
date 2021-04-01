#include "serverTCP.h"

serverTCP::serverTCP()
{
    //ctor
}
int serverTCP::createSocket(int Port)
{
    //TODO: creat listening socket TCP
    this->listenfd =  socket(AF_INET, SOCK_STREAM, 0);
    bzero(&this->servaddr, sizeof(this->servaddr));
    this->servaddr.sin_family = AF_INET;
    this->servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
    this->servaddr.sin_port = htons(Port);

    bind(this->listenfd, (struct this->servaddr*)&this->servaddr, sizeof(this->servaddr));
    listen(this->listenfd, 10);

    return this->listenfd;
}
serverTCP::~serverTCP()
{
    //dtor
}
