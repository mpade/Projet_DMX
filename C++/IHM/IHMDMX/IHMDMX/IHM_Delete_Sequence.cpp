#include "IHM_Delete_Sequence.h"

IHM_Delete_Sequence::IHM_Delete_Sequence() : QWidget()																								// spécification du constructeur
{
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
		getAllSequence();
		supprimer = new QPushButton("Supprimer", this);
		grid->addWidget(listSequence, 0, 0);
		grid->addWidget(supprimer, 1, 0);
		QObject::connect(supprimer, SIGNAL(clicked()), this, SLOT(getDeleteSequence()));
		setLayout(grid);
	}
}
void IHM_Delete_Sequence::getAllSequence() {

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

void IHM_Delete_Sequence::getDeleteSequence()
{

	if (listSequence->selectedItems().count() == 1) {
		QListWidgetItem *item = listSequence->takeItem(listSequence->currentRow());
		//requete delete vu ecrie
		std::string names = item->text().toStdString();
		std::string requete = "SELECT `Id_Sequence` FROM `sequence` WHERE `name` = '" + names + "'";
		mysql_query(mysql, requete.c_str());

		MYSQL_RES *result = NULL;
		MYSQL_ROW row;

		result = mysql_store_result(mysql);

		while ((row = mysql_fetch_row(result)))
		{
			std::string requetes = "DELETE FROM `sequenceusedequipement` WHERE `Id_Sequence` = '" + std::to_string(atoi(row[0])) + "'";
			mysql_query(mysql, requetes.c_str());
			requetes = "DELETE FROM `sequencescene` WHERE `Id_Sequence` = '" + std::to_string(atoi(row[0])) + "'";
			mysql_query(mysql, requetes.c_str());
			requetes = "DELETE FROM `sequence` WHERE `Id_Sequence` =  '" + std::to_string(atoi(row[0])) + "'";
			mysql_query(mysql, requetes.c_str());
		}

	}
}
