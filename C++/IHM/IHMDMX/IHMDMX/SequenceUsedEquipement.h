#pragma once
class SequenceUsedEquipement
{
private:
	int id;
	int value;

public:
	SequenceUsedEquipement(int, int);			// Constructeur

	int getId();								// R�cup�rer l'id d'une SequenceUsedEquipement

	int getSequenceValue();						// R�cup�rer la valeur d'un canal sur la trame DMX 

	int setSequenceValue(int);					// Donner la valeur d'un canal sur la trame DMX *----------------* valeur attendu : value
};

