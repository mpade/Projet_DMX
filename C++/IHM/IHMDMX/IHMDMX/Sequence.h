#pragma once

class Sequence
{

private:
	int id;
	int duree;
	
	int nbSeqAdressEq;

public:
	Sequence(int, int, int);			// Constructeur

	void setDuree(int);								// Donner la dur�e d'une s�quence *-----------* valeur attendu : duree (int)

	int getDuree();									// R�cup�rer la dur�e d'une s�quence

	int getId();									// R�cup�rer l'id d'une s�quence

};

