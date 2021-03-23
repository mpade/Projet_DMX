#include "Equipement.h"

Equipement::Equipement(int, char *, std::map<std::string, Property*>)
{
}

int Equipement::getNbVoies()
{
	return 0;
}

bool Equipement::verifOrder(Property * order)
{
	return false;
}

void Equipement::setId(int)
{
}

int Equipement::getId()
{
	return this->id;
}

void Equipement::setName(char *)
{
}

char * Equipement::getName()
{
	return this->name;
}
