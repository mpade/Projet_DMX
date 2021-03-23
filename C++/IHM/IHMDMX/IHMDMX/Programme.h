#pragma once
#include "Scene.h"
#include <vector>
class Programme
{
private:
	int id;
	char* nom;
	int nbScene;
	std::vector<Scene*> scene;

public:
	int getId();									// R�cup�rer l'id d'un programme

	void setName(char*);							// Donner le nom d'un programme

	char* getName();								// R�cup�rer le nom d'un programme

	void setNbScene(int);							// Donner le nombre de sc�ne qu'attend un programme

	int getNbScene();								// R�cup�rer le nombre de sc�ne qu'attend un programme

	void setScene(std::vector<Scene*>);				// Donner les sc�nes qui composent le programme

	std::vector<Scene*> getScene();					// R�cup�rer les sc�nes qui composent le programme

};

