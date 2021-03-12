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
	Equipement(int, char*, std::map<std::string, Property*>);
	std::map<std::string, Property*> getProperties;
	int  getNbVoies();
	bool verifOrder(Property* order);
	void setId(int);
	int getId() {
		return this->id;
	}
	void setName(char*);
	char* getName() {
		return this->name;
	}

};

