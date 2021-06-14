#pragma once
#include <iostream>
#include <vector>
#include "mysql.h"
class mysql_bdd
{

private:
	MYSQL * mysql;

public:

	mysql_bdd();

	int connectMYSQL();

	std::vector<MYSQL_ROW> getSelectrequet(std::string);
	
};

