#pragma once
class SequenceUsedEquipement
{
private:
	int id;
	int value;

public:
	SequenceUsedEquipement(int, int);			// Constructeur

	int getId();								// Récupérer l'id d'une SequenceUsedEquipement

	int setId(int);								// Donner l'id d'une SequenceUsedEquipement

	int getSequenceValue();						// Récupérer la valeur d'un canal sur la trame DMX 

	int setSequenceValue(int);					// Donner la valeur d'un canal sur la trame DMX
};

