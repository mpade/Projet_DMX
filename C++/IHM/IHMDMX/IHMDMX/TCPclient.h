#pragma once

#include <winsock2.h> 
#include <stdio.h>
#pragma comment(lib,  "ws2_32.lib")

class TCPclient
{
	private:
		SOCKET sock;
		struct hostent *hostinfo;
		char *buffer;

	public:
		TCPclient();
		bool TCPconnexion(const char *hostname, int PORT);
		bool TCPsend(char *buffer, int len);
		bool TCPrecv(char *buffer, int len);
		bool TCPclose();

};

