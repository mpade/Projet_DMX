#pragma on#ce
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
	AdressEquipement(int, std::map<Property*, int>);
	std::map<Property*, int> getValues(){
		return this->values;
	}
	int getAdress() {
		return this->adresse;
	}
	void setValues(std::map<Property*, int>);
	void setAdresse(int);

};

