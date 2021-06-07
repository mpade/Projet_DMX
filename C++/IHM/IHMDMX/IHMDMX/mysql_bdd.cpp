#include "mysql_bdd.h"

mysql_bdd::mysql_bdd()
{
}

int mysql_bdd::connectmysql()
{
	if (!mysql_real_connect(mysql, "192.168.64.102", "DMX", "dmx", "Projet_DMX", 0, NULL, 0))
		return 0;
	else
		return 1;
}

std::vector<std::string> mysql_bdd::getAllEquipement()
{
	std::vector<std::string> Equipement;
	mysql_query(mysql, "SELECT  `Name` FROM `equipement` WHERE 1");

	MYSQL_RES *result = NULL;
	MYSQL_ROW row;

	result = mysql_store_result(mysql);

	while ((row = mysql_fetch_row(result)))
	{
		Equipement.push_back(row[0]);
	}

	return Equipement;
}

std::vector<std::string> mysql_bdd::getAllSequence()
{
	std::vector<std::string>Sequence;
	std::string requet = "SELECT `name` FROM `sequence` WHERE 1";
	mysql_query(mysql, requet.c_str());

	MYSQL_RES *result = NULL;
	MYSQL_ROW row;

	result = mysql_store_result(mysql);

	while ((row = mysql_fetch_row(result)))
	{
		Sequence.push_back(row[0]);
	}

	return Sequence;
}

std::vector<std::string> mysql_bdd::getAllScene()
{
	std::vector<std::string> Scene;

	std::string requet = "SELECT `Nom` FROM `scene` WHERE 1";
	mysql_query(mysql, requet.c_str());

	MYSQL_RES *result = NULL;
	MYSQL_ROW row;

	result = mysql_store_result(mysql);

	while ((row = mysql_fetch_row(result)))
	{
		Scene.push_back(row[0]);
	}

	return Scene;
}
