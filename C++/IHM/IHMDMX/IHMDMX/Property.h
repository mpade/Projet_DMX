#pragma once
class Property
{

private:
	int id;
	char* description;
	int order;

public:
	Property(int, char*, int);			// Constructeur

	int getId();						// Récupérer l'id d'une propriété

	void setDescription(char*);			// Donner la description d'un order *-------------------* valeur attendu : description (char*)

	char* getDescription();				// Récupérer la description d'un order

	void setOrder(int);					// Donner un order *------------------------------------* valeur attendu : order (int)

	int getOrder(int);					// Récupérer un order

};

