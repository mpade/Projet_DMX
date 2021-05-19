#include "AdressEquipement.h"
#include "IHMDMX.h"


std::map<Property*, int> AdressEquipement::getValues()
{
	return this->values;
}

int AdressEquipement::getAdress()
{
	return this->adresse;
}

void AdressEquipement::setValues(std::map<Property*, int> v)
{
	this->values = v;
}

void AdressEquipement::setAdresse(int)
{

}
