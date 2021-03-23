#pragma once
class Property
{

private:
	int id;
	char* description;
	int order;

public:
	Property(int, char*, int);			// Constructeur

	void setId(int);					// Donner l'id d'une propriété

	int getId();						// Récupérer l'id d'une propriété

	void setDescription(char*);			// Donner la description d'un order 

	char* getDescription();				// Récupérer la description d'un order

	void setOrder(int);					// Donner un order

	int getOrder(int);					// Récupérer un order

};

