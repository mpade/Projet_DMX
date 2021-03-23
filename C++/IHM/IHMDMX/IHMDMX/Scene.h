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
	int getId();													// Récupérer l'id d'une scène

	char* getName();												// Récupérer le nom d'une scène

	void setTime(int);												// Donner le temps que dure une scène *--------------------* valeur attendu : tpsPause

	int getTime();													// Récupérer le temps que dure une scène 

	char* setName(char*);											// Donner le nom d'une scène *-----------------------------* valeur attendu : name

	void setNbSeq(int);												// Donner le nombre de séquence qu'attend la scène *-------* valeur attendu : seq

	int getNbSeq();													// Récupérer le nombre de séquence qu'attend la scène

	void setSequences(std::map < std::string, Sequence* >);			// Donner une séquence 

	std::map < std::string, Sequence* > getSequences();				// Récupérer une séquence
};

