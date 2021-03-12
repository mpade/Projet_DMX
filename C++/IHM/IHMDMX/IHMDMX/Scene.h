#pragma once
#include"Sequence.h"
#include<map>
class Scene
{
private:
	int id;
	char* nom;
	int pause;
	std::map < std::string, Sequence* > seq;

public:
	int getId() {
		return this->id;
	}
	char* getName() {
		return this->nom;
	}
	void setId(int);
	void setTime(int);
	int getTime() {
		return this->pause;
	}
	char* setName(char*);
	void setNbSeq(int);
	int getNbSeq() {
		return NULL;
	}
	void setSequences(std::map < std::string, Sequence* >);
	std::map < std::string, Sequence* > getSequences() {
		return this->seq;
	}
};

