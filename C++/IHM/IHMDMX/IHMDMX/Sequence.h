#pragma once
#include "TrameManager.h"
class Sequence
{

private:
	int id;
	int duree;
	TrameManager* trame;
	int nbSeqAdressEq;

public:
	Sequence(int, int, TrameManager*, int);
	void setDuree(int);
	int getDuree() {
		return this->duree;
	}
	void setId(int);
	int getId() {
		return this->id;
	}
};

