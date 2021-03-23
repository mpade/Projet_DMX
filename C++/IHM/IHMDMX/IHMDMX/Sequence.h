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

	void setDuree(int);								// Donner la dur�e d'une s�quence

	int getDuree();									// R�cup�rer la dur�e d'une s�quence

	void setId(int);								// Donner l'id d'une s�quence

	int getId();									// R�cup�rer l'id d'une s�quence

};

