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
	int getId();									// Récupérer l'id d'un programme

	void setName(char*);							// Donner le nom d'un programme

	char* getName();								// Récupérer le nom d'un programme

	void setNbScene(int);							// Donner le nombre de scène qu'attend un programme

	int getNbScene();								// Récupérer le nombre de scène qu'attend un programme

	void setScene(std::vector<Scene*>);				// Donner les scènes qui composent le programme

	std::vector<Scene*> getScene();					// Récupérer les scènes qui composent le programme

};

