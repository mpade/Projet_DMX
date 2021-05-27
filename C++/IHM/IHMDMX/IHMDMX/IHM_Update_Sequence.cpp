#include "IHM_Update_Sequence.h"

IHM_Update_Sequence::IHM_Update_Sequence(){

	mysql = mysql_init(NULL);

	if (!mysql_real_connect(mysql, "192.168.64.102", "DMX", "dmx", "Projet_DMX", 0, NULL, 0))
	{
		QMessageBox msgBox;
		msgBox.setText("Eror de connection a la BDD");
		msgBox.exec();
	}
	else
	{
		grid = new QGridLayout;
		listSequence = new QListWidget();
		listSequencequipement = new QListWidget();
		nameSequence = new QLabel();
		supequipment = new QPushButton();
		supequipment->setText("Supprimer");
		modifier = new QPushButton();
		modifier->setText("Quitter");
		getAllSequence();
		grid->addWidget(nameSequence,0,1,1,3);
		grid->addWidget(listSequence,1,0);
		grid->addWidget(listSequencequipement, 1, 1);
		grid->addWidget(supequipment, 2,1);
		grid->addWidget(modifier, 2,0);
		setLayout(grid);
		QObject::connect(listSequence, SIGNAL(itemDoubleClicked(QListWidgetItem *)), this, SLOT(getSelectidSequence()));
		QObject::connect(supequipment, SIGNAL(clicked()), this, SLOT(getDeletequipementsequence()));
		QObject::connect(modifier, SIGNAL(clicked()), this, SLOT(close()));
	}
}
void IHM_Update_Sequence::getAllSequence() 
{

	mysql_query(mysql, "SELECT `name` FROM `sequence` WHERE 1");

	MYSQL_RES *result = NULL;
	MYSQL_ROW row;

	result = mysql_store_result(mysql);

	while ((row = mysql_fetch_row(result)))
	{
		QListWidgetItem *item = new QListWidgetItem();
		item->setText(row[0]);
		listSequence->addItem(item);

	}

}

void IHM_Update_Sequence::getSelectidSequence()
{

	if (listSequence->selectedItems().count() == 1) {
		QListWidgetItem *item = listSequence->currentItem();
		nameSequence->setText(item->text());
		listSequence->clearSelection();
		getequipement(item->text().toStdString());
	}

}

void IHM_Update_Sequence::getequipement(std::string name)
{

	listSequencequipement->clear();
	
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
		QListWidgetItem * item = new QListWidgetItem();
		item->setText(rows[1]);
		listSequencequipement->addItem(item);
	}

}
void IHM_Update_Sequence::getDeletequipementsequence() 
{

	if (listSequencequipement->selectedItems().count() == 1) 
	{
		int id_equipement = 0, id_addressequipement = 0, id_property = 0;
		QListWidgetItem * item = listSequencequipement->takeItem(listSequencequipement->currentRow());
		std::string request = "SELECT `Id_Equipement` FROM `equipement` WHERE `Name` = '"+ item->text().toStdString() +"'";
		mysql_query(mysql, request.c_str());
		MYSQL_RES *result = NULL;
		MYSQL_ROW row;

		result = mysql_store_result(mysql);
		row = mysql_fetch_row(result);
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
	}

}