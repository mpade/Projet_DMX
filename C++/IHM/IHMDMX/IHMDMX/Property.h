#pragma once
class Property
{

private:
	int id;
	char* description;
	int order;

public:
	Property(int, char*, int);			// Constructeur

	void setId(int);					// Donner l'id d'une propri�t�

	int getId();						// R�cup�rer l'id d'une propri�t�

	void setDescription(char*);			// Donner la description d'un order 

	char* getDescription();				// R�cup�rer la description d'un order

	void setOrder(int);					// Donner un order

	int getOrder(int);					// R�cup�rer un order

};

