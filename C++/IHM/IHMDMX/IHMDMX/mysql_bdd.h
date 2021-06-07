#pragma once
#include <vector>
#include <string>
#include "mysql.h"
class mysql_bdd
{

private :
	MYSQL *mysql;
public:
	mysql_bdd();

	int connectmysql();

	std::vector<std::string> getAllEquipement();
	std::vector<std::string> getAllSequence();
	std::vector<std::string> getAllScene();
};

