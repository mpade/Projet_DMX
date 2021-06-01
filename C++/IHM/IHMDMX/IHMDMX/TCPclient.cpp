#include "TCPclient.h"

using namespace std;

TCPclient::TCPclient() {
	WSADATA wsa;
	WSAStartup(MAKEWORD(2, 2), &wsa);
	sock = socket(AF_INET, SOCK_STREAM, 0);
	buffer = new char[1024];
}

bool TCPclient::TCPconnexion(const char *hostname, int PORT) {

	this->hostinfo = NULL;
	SOCKADDR_IN sin = { 0 }; /* initialise la structure avec des 0 */

	this->hostinfo = gethostbyname(hostname); /* on récupère les informations de l'hôte auquel on veut se connecter */
	if (this->hostinfo == NULL) /* l'hôte n'existe pas */
	{
		return false;
	}

	sin.sin_addr = *(IN_ADDR *)this->hostinfo->h_addr; /* l'adresse se trouve dans le champ h_addr de la structure hostinfo */
	sin.sin_port = htons(PORT); /* on utilise htons pour le port */
	sin.sin_family = AF_INET;

	if (connect(this->sock, (SOCKADDR *)&sin, sizeof(SOCKADDR)) != SOCKET_ERROR)
	{
		return true;
	}
	return false;
	
}
bool TCPclient::TCPsend(char *buffer, int len) {
	
	
	if (send(this->sock, buffer, len, 0) < 0)
	{
		return false;
	}
	return true;
}

bool TCPclient::TCPrecv(char *buffer, int len) {

	int n = 0;

	if ((n = recv(this->sock, buffer, len, 0)) < 0)
	{
		return false;
	}

	buffer[n] = '\0';
	return true;
}
bool TCPclient::TCPclose() {

	closesocket(this->sock);
	return true;
}