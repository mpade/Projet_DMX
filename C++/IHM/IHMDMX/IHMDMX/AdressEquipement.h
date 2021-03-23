#pragma once
#include "Equipement.h"
#include "Property.h"
#include <map>
class AdressEquipement
{

private:
	Equipement equipement;
	int id;
	int adresse;
	std::map<Property*, int> values;

public:
	AdressEquipement(int, std::map<Property*, int>);    // ( adresse, map<Property*, values )

	std::map<Property*, int> getValues();				// Récupérer la valeur des canaux

	int getAdress();									// Récupérer l'adresse de début d'un équipement

	void setValues(std::map<Property*, int>);		    // Donner la valeur des cannaux

	void setAdresse(int);								// Donner l'adresse de début d'un équipement

};

