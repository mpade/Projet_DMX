#pragma once
#include "Property.h"
#include <map>
#include <string>
class Equipement
{

private:
	int id;
	char* name;
	std::map<std::string, Property*> properties;

public:
	Equipement(int, char*, std::map<std::string, Property*>);		// Constructeur

	std::map<std::string, Property*> getProperties;					// Récupérer les propriétées de l'équipement

	int  getNbVoies();												// Récupérer le nombre de canaux de l'équipement

	bool verifOrder(Property* order);								// Vérifier si un équipement n'a pas 2 fois le même order

	void setId(int);												// Donner l'id de l'équipement

	int getId();													// Récupérer l'id de l'équipement

	void setName(char*);											// Donner le nom de l'équipement

	char* getName();												// Récupérer le nom de l'équipement

};

