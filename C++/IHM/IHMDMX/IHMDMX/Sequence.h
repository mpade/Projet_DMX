#pragma once
#include "TrameManager.h"
class Sequence
{

private:
	int id;
	int duree;
	TrameManager* trame;
	int nbSeqAdressEq;

public:
	Sequence(int, int, TrameManager*, int);			// Constructeur

	void setDuree(int);								// Donner la durée d'une séquence

	int getDuree();									// Récupérer la durée d'une séquence

	void setId(int);								// Donner l'id d'une séquence

	int getId();									// Récupérer l'id d'une séquence

};

