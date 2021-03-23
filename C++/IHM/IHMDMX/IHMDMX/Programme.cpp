#include "Programme.h"

void Programme::setId(int)
{
}

int Programme::getId()
{
	return this->id;
}

void Programme::setName(char *)
{
}

char * Programme::getName()
{
	return this->nom;
}

void Programme::setNbScene(int)
{
}

int Programme::getNbScene()
{
	return this->nbScene;
}

void Programme::setScene(std::vector<Scene*>)
{
}

std::vector<Scene*> Programme::getScene()
{
	return this->scene;
}
