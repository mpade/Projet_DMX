#pragma once
#include <vector>
#include <string>
#include "mysql.h"
class mysql_bdd
{

private :
	MYSQL *mysql;
	int id_sequence = 0;
	int id_scene = 0;
public:
	mysql_bdd();

	int connectmysql();
	MYSQL * getmysql();

	std::vector<std::string> getAllEquipement();
	std::vector<std::string> getAllSequence();
	std::vector<std::string> getAllScene();

	int deleteEquipement(std::string);
	int deleteSequence(std::string);
	int deleteScene(std::string);
	int deleteEquipementforsequence(std::string);
	int deletesequencescene(std::string, std::string);
	int deletesupdatescene(std::string);


	std::vector<std::string> getValueSequence(std::string);
	std::vector<std::string> getEquipementForSequence(std::string);
	std::vector<std::string> getSequenceForScene(std::string);

	void getUpdateScene(std::string, int);

};

