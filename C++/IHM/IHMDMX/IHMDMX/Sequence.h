#pragma once

class Sequence
{

private:
	int id;
	int duree;
	
	int nbSeqAdressEq;

public:
	Sequence(int, int, int);			// Constructeur

	void setDuree(int);								// Donner la durée d'une séquence *-----------* valeur attendu : duree (int)

	int getDuree();									// Récupérer la durée d'une séquence

	int getId();									// Récupérer l'id d'une séquence

};

