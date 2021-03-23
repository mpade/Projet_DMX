#pragma once
#include "AdressEquipement.h"
#include <vector>
class TrameManager
{

private: 
	std::vector<AdressEquipement*> trame;
	char* dmx[512];

public:
	void insertEquipement(Equipement*, int);					// Insérer un équipement sur la trame DMX

	void removeEquipement(int);									// Changer de position un équipement sur la trame DMX

	bool checkConflict();										// Vérifier que deux équipements ne se chevauche pas sur la trame DMX

	char* getTrame();											// Récupérer la trame DMX

	std::vector<AdressEquipement*> getAdressEquipement();		// Récupérer l'AdresseEquipement, l'Equipement, La Property
};

