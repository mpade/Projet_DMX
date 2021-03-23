#pragma once
#include "AdressEquipement.h"
#include <vector>
class TrameManager
{

private: 
	std::vector<AdressEquipement*> trame;
	char* dmx[512];

public:
	void insertEquipement(Equipement*, int);					// Ins�rer un �quipement sur la trame DMX

	void removeEquipement(int);									// Changer de position un �quipement sur la trame DMX

	bool checkConflict();										// V�rifier que deux �quipements ne se chevauche pas sur la trame DMX

	char* getTrame();											// R�cup�rer la trame DMX

	std::vector<AdressEquipement*> getAdressEquipement();		// R�cup�rer l'AdresseEquipement, l'Equipement, La Property
};

