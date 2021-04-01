#include "Programme.h"

int Programme::getId()
{
	return this->id;
}

void Programme::setName(char *)
{
}

char * Programme::getName()
{
	return this->name;
}

void Programme::setNbScene(int)
{
}

int Programme::getNbScene()
{
	return this->nbScene;
}

std::vector<Scene*> Programme::getScene()
{
	return this->scene;
}
