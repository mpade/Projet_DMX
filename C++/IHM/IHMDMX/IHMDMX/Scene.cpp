#include "Scene.h"

int Scene::getId()
{
	return this->id;
}

char * Scene::getName()
{
	return this->nom;
}

void Scene::setTime(int)
{
}

int Scene::getTime()
{
	return this->tpsPause;
}

char * Scene::setName(char *)
{
	return nullptr;
}

void Scene::setNbSeq(int)
{
}

int Scene::getNbSeq()
{
	return NULL;
}

void Scene::setSequences(std::map<std::string, Sequence*>)
{
}

std::map<std::string, Sequence*> Scene::getSequences()
{
	return this->seq;
}
