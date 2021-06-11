#include "mysql_bdd.h"

mysql_bdd::mysql_bdd()
{
	this->mysql = mysql_init(NULL);
}

int mysql_bdd::connectmysql()
{
	
	if (!mysql_real_connect(this->mysql, "localhost", "root", "", "Projet_DMX", 0, NULL, 0)){
		return 0;
	}
	else
		return 1;
}

MYSQL * mysql_bdd::getmysql()
{
	return mysql;
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

int mysql_bdd::deleteEquipement(std::string Name)
{
	MYSQL_ROW row = NULL;
	MYSQL_ROW row1 = NULL;
	
	MYSQL_RES *result = NULL;
	MYSQL_RES *result1 = NULL;
	
	std::string requetId_equipement = "SELECT * FROM `equipement` WHERE `Name` ='" + Name + "'";
	mysql_query(mysql, requetId_equipement.c_str());

	if (result = mysql_store_result(mysql)) {

		while ((row = mysql_fetch_row(result)))
		{

			std::string requetId_adressequipement = "SELECT * FROM `adressequipement` WHERE `Id_Equipement` ='" + std::to_string(atoi(row[0])) + "'";
			mysql_query(mysql, requetId_adressequipement.c_str());

			result1 = mysql_store_result(mysql);

			while ((row1 = mysql_fetch_row(result1))) {

				std::string requetDelete = "DELETE FROM `sequenceusedequipement` WHERE `Id_AdressEquipement` = '" + std::to_string(atoi(row1[0])) + "'";
				mysql_query(mysql, requetDelete.c_str());

			}

			std::string requetDelete2 = "DELETE FROM `adressequipement` WHERE `Id_Equipement` = '" + std::to_string(atoi(row[0])) + "'";
			mysql_query(mysql, requetDelete2.c_str());

			std::string requetDelete3 = "DELETE FROM `equipement` WHERE `Id_Equipement` = '" + std::to_string(atoi(row[0])) + "'";
			mysql_query(mysql, requetDelete3.c_str());

			std::string requetDelete4 = "DELETE FROM `property` WHERE `Id_Equipement` =  '" + std::to_string(atoi(row[0])) + "'";
			mysql_query(mysql, requetDelete4.c_str());
		}
		return 1;
	}
	return 0;
}

int mysql_bdd::deleteSequence(std::string names)
{
	std::string requete = "SELECT `Id_Sequence` FROM `sequence` WHERE `name` = '" + names + "'";
	mysql_query(mysql, requete.c_str());

	MYSQL_RES *result = NULL;
	MYSQL_ROW row;

	if (result = mysql_store_result(mysql)) {

		while ((row = mysql_fetch_row(result)))
		{
			std::string requetes = "DELETE FROM `sequenceusedequipement` WHERE `Id_Sequence` = '" + std::to_string(atoi(row[0])) + "'";
			mysql_query(mysql, requetes.c_str());
			requetes = "DELETE FROM `sequencescene` WHERE `Id_Sequence` = '" + std::to_string(atoi(row[0])) + "'";
			mysql_query(mysql, requetes.c_str());
			requetes = "DELETE FROM `valueproper` WHERE `id_sequence` = '" + std::to_string(atoi(row[0])) + "'";
			mysql_query(mysql, requetes.c_str());
			requetes = "DELETE FROM `sequence` WHERE `Id_Sequence` =  '" + std::to_string(atoi(row[0])) + "'";
			mysql_query(mysql, requetes.c_str());
		}
		return 1;
	}
	return 0;
}

int mysql_bdd::deleteScene(std::string names)
{
	std::string requete = "SELECT `Id_Scene` FROM `scene` WHERE `Nom` = '" + names + "'";
	mysql_query(mysql, requete.c_str());

	MYSQL_RES *result = NULL;
	MYSQL_ROW row;

	if (result = mysql_store_result(mysql)) {

		while ((row = mysql_fetch_row(result)))
		{
			std::string requetes = "DELETE FROM `sequencescene` WHERE `Id_Scene` = '" + std::to_string(atoi(row[0])) + "'";
			mysql_query(mysql, requetes.c_str());
			requetes = "DELETE FROM `sceneprogramme` WHERE `Id_Scene` ='" + std::to_string(atoi(row[0])) + "'";
			mysql_query(mysql, requetes.c_str());
			requetes = "DELETE FROM `scene` WHERE `Id_Scene` =  '" + std::to_string(atoi(row[0])) + "'";
			mysql_query(mysql, requetes.c_str());
		}
		return 1;
	}

	return 0;
}

int mysql_bdd::deleteEquipementforsequence(std::string names)
{
	int id_equipement = 0, id_addressequipement = 0, id_property = 0;
	std::string request = "SELECT `Id_Equipement` FROM `equipement` WHERE `Name` = '" + names + "'";
	mysql_query(mysql, request.c_str());
	MYSQL_RES *result = NULL;
	MYSQL_ROW row;

	result = mysql_store_result(mysql);
	if(row = mysql_fetch_row(result)){
	result = NULL;
	id_equipement = atoi(row[0]);
	request = "SELECT `Id_AdressEquipement` FROM `adressequipement` WHERE `Id_Equipement` = " + std::to_string(id_equipement);
	mysql_query(mysql, request.c_str());
	result = mysql_store_result(mysql);
	row = mysql_fetch_row(result);
	result = NULL;
	id_addressequipement = atoi(row[0]);
	request = "DELETE FROM `sequenceusedequipement` WHERE `Id_AdressEquipement` = " + std::to_string(id_addressequipement) + " and `Id_Sequence` = " + std::to_string(id_sequence);
	mysql_query(mysql, request.c_str());
	request = "SELECT `Id_Property` FROM `property` WHERE `Id_Equipement` =" + std::to_string(id_equipement);
	mysql_query(mysql, request.c_str());
	result = mysql_store_result(mysql);
	while (row = mysql_fetch_row(result))
	{

		std::string requetdelete = "DELETE FROM `valueproper` WHERE `id_property` = " + std::to_string(id_property) + "and `id_sequence` = " + std::to_string(id_sequence);
		mysql_query(mysql, requetdelete.c_str());
	}
	return 1;
	}
	return 0;
}

int mysql_bdd::deletesequencescene(std::string namescene, std::string namesequence)
{

	std::string requestt = "SELECT `Id_Scene` FROM `scene` WHERE `Nom` ='" + namescene + "'";
	std::string request = "SELECT `Id_Sequence` FROM `sequence` WHERE `name` = '" + namesequence + "'";
	mysql_query(mysql, request.c_str());
	mysql_query(mysql, requestt.c_str());
	MYSQL_RES *results = NULL;
	MYSQL_ROW rows;

	MYSQL_RES *result = NULL;
	MYSQL_ROW row;

	result = mysql_store_result(mysql);
	row = mysql_fetch_row(result);
	results = mysql_store_result(mysql);
	rows = mysql_fetch_row(results);

	request = "DELETE FROM `sequencescene` WHERE `Id_Sequence` =" + std::to_string(atoi(row[0])) + " and `Id_Scene` = " + std::to_string(atoi(rows[0]));
	return 0;
}

int mysql_bdd::deletesupdatescene(std::string names)
{
	std::string request = "SELECT `Id_Scene` FROM `scene` WHERE `Nom` ='" + names + "'";
	mysql_query(mysql, request.c_str());
	MYSQL_RES *results = NULL;
	MYSQL_ROW rows;
	results = mysql_store_result(mysql);
	if (rows = mysql_fetch_row(results)) {
		results = NULL;
		id_scene = atoi(rows[0]);
		std::string requet = "DELETE FROM `sequencescene` WHERE `Id_Scene` = " + std::to_string(atoi(rows[0]));
		mysql_query(mysql, requet.c_str());
		return 1;
	}
	return 0;
}

std::vector<std::string> mysql_bdd::getValueSequence(std::string names)
{
	std::vector<std::string> trame;
	std::string requete = "SELECT `Id_Sequence`, `Duree` FROM `sequence` WHERE `name` = '" + names + "'";
	mysql_query(mysql, requete.c_str());

	MYSQL_RES *result = NULL;
	MYSQL_ROW row;
	MYSQL_RES *results = NULL;
	MYSQL_ROW rows;
	MYSQL_RES *resultss = NULL;
	MYSQL_ROW rowss;
	MYSQL_RES *resultsss = NULL;
	MYSQL_ROW rowsss;
	result = mysql_store_result(mysql);
	
	row = mysql_fetch_row(result);
	int duree = atoi(row[1]);
	
	int idsequence = atoi(row[0]);
	requete = "SELECT `Id_AdressEquipement` FROM `sequenceusedequipement` WHERE `Id_Sequence` =  '" + std::to_string(idsequence) + "'";
	mysql_query(mysql, requete.c_str());
	result = mysql_store_result(mysql);

	while ((row = mysql_fetch_row(result)))
	{

		requete = "SELECT `Adresse`,`Id_Equipement` FROM `adressequipement` WHERE `Id_AdressEquipement` = '" + std::to_string(atoi(row[0])) + "'";
		mysql_query(mysql, requete.c_str());
		results = mysql_store_result(mysql);
		int addresss = 0;
		while ((rows = mysql_fetch_row(results)))
		{
			addresss = atoi(rows[0]);
			requete = "SELECT `Id_Property`,`Order` FROM `property` WHERE `Id_Equipement` = '" + std::to_string(atoi(rows[1])) + "' ORDER BY `property`.`Order` ASC ";
			mysql_query(mysql, requete.c_str());
			resultss = mysql_store_result(mysql);
			while ((rowss = mysql_fetch_row(resultss)))
			{
				requete = "SELECT `value` FROM `valueproper` WHERE `id_property` = '" + std::to_string(atoi(rowss[0])) + "' and `id_sequence` =  '" + std::to_string(idsequence) + "'";
				mysql_query(mysql, requete.c_str());
				resultsss = mysql_store_result(mysql);
				rowsss = mysql_fetch_row(resultsss);

				addresss += atoi(rowss[1]) - 1;
				std::string tramemou = "CV:" + std::to_string(addresss) + "," + std::to_string(atoi(rowsss[0]))+";";
				trame.push_back(tramemou);

				addresss = atoi(rows[0]);

			}
		}

	}
	trame.push_back("TE:" + std::to_string(duree) + ";");
	
	return trame;
}

std::vector<std::string> mysql_bdd::getValueScene(std::string name)
{
	std::vector<std::string> trame;
	std::string requete = "SELECT `Id_Scene` FROM `scene` WHERE `Nom` = '" + name + "'";
	mysql_query(mysql, requete.c_str());
	int duree = 0;
	MYSQL_RES *result = NULL;
	MYSQL_ROW row;
	MYSQL_RES *results = NULL;
	MYSQL_ROW rows;
	MYSQL_RES *resultss = NULL;
	MYSQL_ROW rowss;
	MYSQL_RES *resultsss = NULL;
	MYSQL_ROW rowsss;
	MYSQL_RES *resultssss = NULL;
	MYSQL_ROW rowssss;
	MYSQL_RES *resultsssss = NULL;
	MYSQL_ROW rowsssss;
	result = mysql_store_result(mysql);
	row = mysql_fetch_row(result);
	

		requete = "SELECT Id_Sequence FROM sequencescene WHERE Id_Scene = '" + std::to_string(atoi(row[0])) + "'";
		mysql_query(mysql, requete.c_str());
		resultssss = mysql_store_result(mysql);

		while ((rowssss = mysql_fetch_row(resultssss))) {
			int idsequence = atoi(rowssss[0]);
			requete = "SELECT `Id_AdressEquipement` FROM `sequenceusedequipement` WHERE `Id_Sequence` =  '" + std::to_string(idsequence) + "'";
			mysql_query(mysql, requete.c_str());
			result = mysql_store_result(mysql);

			while ((row = mysql_fetch_row(result)))
			{

				requete = "SELECT `Adresse`,`Id_Equipement` FROM `adressequipement` WHERE `Id_AdressEquipement` = '" + std::to_string(atoi(row[0])) + "'";
				mysql_query(mysql, requete.c_str());
				results = mysql_store_result(mysql);
				int addresss = 0;
				while ((rows = mysql_fetch_row(results)))
				{
					addresss = atoi(rows[0]);
					requete = "SELECT `Id_Property`,`Order` FROM `property` WHERE `Id_Equipement` = '" + std::to_string(atoi(rows[1])) + "' ORDER BY `property`.`Order` ASC ";
					mysql_query(mysql, requete.c_str());
					resultss = mysql_store_result(mysql);
					while ((rowss = mysql_fetch_row(resultss)))
					{
						requete = "SELECT `value` FROM `valueproper` WHERE `id_property` = '" + std::to_string(atoi(rowss[0])) + "' and `id_sequence` =  '" + std::to_string(idsequence) + "'";
						mysql_query(mysql, requete.c_str());
						resultsss = mysql_store_result(mysql);
						rowsss = mysql_fetch_row(resultsss);

						addresss += atoi(rowss[1]) - 1;
						std::string tramemou = "CV:" + std::to_string(addresss) + "," + std::to_string(atoi(rowsss[0])) + ";";
						trame.push_back(tramemou);

						addresss = atoi(rows[0]);

					}
				}

			}
			requete = "SELECT `Duree` FROM `sequence` WHERE `Id_Sequence` = '" + std::to_string(idsequence) + "'";
			mysql_query(mysql, requete.c_str());
			resultsssss = mysql_store_result(mysql);
			rowsssss = mysql_fetch_row(resultsssss);
			duree = atoi(rowsssss[0]);
			trame.push_back("TE:" + std::to_string(duree) + ";");
		}
	

	return trame;
}

std::vector<std::string> mysql_bdd::getEquipementForSequence(std::string name)
{
	
	std::vector<std::string> EquipementSequence;
	std::string request = "SELECT `Id_Sequence` FROM `sequence` WHERE `name` ='" + name + "'";
	mysql_query(mysql, request.c_str());
	MYSQL_RES *result = NULL;
	MYSQL_ROW row;

	result = mysql_store_result(mysql);
	row = mysql_fetch_row(result);
	result = NULL;
	id_sequence = atoi(row[0]);
	request = "SELECT `Id_AdressEquipement` FROM `sequenceusedequipement` WHERE `Id_Sequence` = " + std::to_string(id_sequence);
	mysql_query(mysql, request.c_str());
	result = mysql_store_result(mysql);
	while (row = mysql_fetch_row(result))
	{
		MYSQL_RES *results = NULL;
		MYSQL_ROW rows;
		request = "SELECT `Id_Equipement` FROM `adressequipement` WHERE `Id_AdressEquipement` = " + std::to_string(atoi(row[0]));
		mysql_query(mysql, request.c_str());
		results = mysql_store_result(mysql);
		rows = mysql_fetch_row(results);

		request = "SELECT `Id_Equipement`, `Name`, `Nb_voie` FROM `equipement` WHERE `Id_Equipement` = '" + std::to_string(atoi(rows[0])) + "'";
		results = NULL;
		mysql_query(mysql, request.c_str());
		results = mysql_store_result(mysql);
		rows = mysql_fetch_row(results);
		EquipementSequence.push_back(rows[1]);
	}

	return EquipementSequence;
}

std::vector<std::string> mysql_bdd::getSequenceForScene(std::string name)
{
	std::vector<std::string> sequence;
	std::string request = "SELECT `Id_Scene` FROM `scene` WHERE `Nom` ='" + name + "'";
	mysql_query(mysql, request.c_str());
	MYSQL_RES *result = NULL;
	MYSQL_ROW row;

	result = mysql_store_result(mysql);
	row = mysql_fetch_row(result);
	result = NULL;

	request = "SELECT `Id_Sequence`, `Order` FROM `sequencescene` WHERE `Id_Scene` = " + std::to_string(atoi(row[0]));
	mysql_query(mysql, request.c_str());
	result = mysql_store_result(mysql);
	while (row = mysql_fetch_row(result))
	{
		MYSQL_RES *results = NULL;
		MYSQL_ROW rows;
		request = "SELECT `Id_Sequence`, `Duree`, `name` FROM `sequence` WHERE `Id_Sequence` = '" + std::to_string(atoi(row[0])) + "'";
		mysql_query(mysql, request.c_str());
		results = mysql_store_result(mysql);
		rows = mysql_fetch_row(results);
		sequence.push_back(rows[2]);
	}
	return sequence;
}

void mysql_bdd::getUpdateScene(std::string name, int y)
{

	std::string requet = "SELECT `Id_Sequence` FROM `sequence` WHERE `name` = '" + name + "'";
	mysql_query(mysql, requet.c_str());
	MYSQL_RES *result = NULL;
	MYSQL_ROW row;

	result = mysql_store_result(mysql);

	row = mysql_fetch_row(result);
	int id_sequence = atoi(row[0]);

	requet = "INSERT INTO `sequencescene`(`Id_SequenceScene`, `Id_Sequence`, `Id_Scene`, `Order`) VALUES (NULL," + std::to_string(id_sequence) + "," + std::to_string(id_scene) + "," + std::to_string(y) + ")";
	mysql_query(mysql, requet.c_str());

}
