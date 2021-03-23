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

	std::map<std::string, Property*> getProperties;					// R�cup�rer les propri�t�es de l'�quipement

	int  getNbVoies();												// R�cup�rer le nombre de canaux de l'�quipement

	bool verifOrder(Property* order);								// V�rifier si un �quipement n'a pas 2 fois le m�me order

	void setId(int);												// Donner l'id de l'�quipement

	int getId();													// R�cup�rer l'id de l'�quipement

	void setName(char*);											// Donner le nom de l'�quipement

	char* getName();												// R�cup�rer le nom de l'�quipement

};

