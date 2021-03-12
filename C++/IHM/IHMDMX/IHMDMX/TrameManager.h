#pragma once
#include "AdressEquipement.h"
#include <vector>
class TrameManager
{

private: 
	std::vector<AdressEquipement*> trame;
	char* dmx[512];
public:
	void insertEquipement(Equipement*, int);
	void removeEquipement(int);
	bool checkConflict();
	char* getTrame();
	std::vector<AdressEquipement*> getAdressEquipement();
};

