#pragma once
#include"Sequence.h"
#include<map>
class Scene
{
private:
	int id;
	char* nom;
	int tpsPause;
	std::map < std::string, Sequence* > seq;

public:
	int getId();													// R�cup�rer l'id d'une sc�ne

	char* getName();												// R�cup�rer le nom d'une sc�ne

	void setTime(int);												// Donner le temps que dure une sc�ne *--------------------* valeur attendu : tpsPause

	int getTime();													// R�cup�rer le temps que dure une sc�ne 

	char* setName(char*);											// Donner le nom d'une sc�ne *-----------------------------* valeur attendu : name

	void setNbSeq(int);												// Donner le nombre de s�quence qu'attend la sc�ne *-------* valeur attendu : seq

	int getNbSeq();													// R�cup�rer le nombre de s�quence qu'attend la sc�ne

	void setSequences(std::map < std::string, Sequence* >);			// Donner une s�quence 

	std::map < std::string, Sequence* > getSequences();				// R�cup�rer une s�quence
};

