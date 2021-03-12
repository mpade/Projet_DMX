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
	void setId(int);
	int getId() {
		return this->id;
	}
	void setName(char*);
	char* getName() {
		return this->nom;
	}
	void setNbScene(int);
	int getNbScene() {
		return this->nbScene;
	}
	void setScene(std::vector<Scene*>);
	std::vector<Scene*> getScene() {
		return this->scene;
	}
};

