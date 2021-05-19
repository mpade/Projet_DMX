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
		getAllSequence();
		supprimer = new QPushButton("Supprimer", this);
		grid->addWidget(supprimer, 1, 2);
		QObject::connect(supprimer, SIGNAL(clicked()), this, SLOT(getDeleteSequence()));
	}
}
void IHM_Delete_Sequence::getAllSequence() {

	mysql_query(mysql, "SELECT `name` FROM `sequence` WHERE 1");

	//Déclaration des pointeurs de structure
	MYSQL_RES *result = NULL;
	MYSQL_ROW row;
	unsigned int i = 0, z = 0;
	unsigned int num_champs = 0;

	//On met le jeu de résultat dans le pointeur result
	result = mysql_use_result(mysql);

	//On récupère le nombre de champs
	num_champs = mysql_num_fields(result);
	groupBox = new QGroupBox(tr("Sequence"));
	vbox = new QVBoxLayout;

	groupBox->setFlat(true);

	while ((row = mysql_fetch_row(result)))
	{
			//On ecrit toutes les valeurs
			e.push_back(new QCheckBox(tr(row[0]), this));
			for (int x = z; x < e.size(); x++) {
				e[x]->setObjectName(row[0]);
				z++;
			
		}

	}
	//e[i]->setObjectName();
	for (int i = 0; i < e.size(); i++) {

		vbox->addWidget(e[i]);
	}
	vbox->addStretch(1);
	groupBox->setLayout(vbox);
	grid->addWidget(groupBox, 0, 1);
	setLayout(grid);

}

void IHM_Delete_Sequence::getDeleteSequence()
{
	for (int i = 0; i < e.size(); i++) {
		if (e[i]->checkState()) {
			//requete pour delete la sequence !!

			std::string names = e[i]->objectName().toStdString();
			std::string requete = "SELECT `Id_Sequence` FROM `sequence` WHERE `name` = '" + names + "'";
			mysql_query(mysql, requete.c_str());

			//Déclaration des pointeurs de structure
			MYSQL_RES *result = NULL;
			MYSQL_ROW row;


			//On met le jeu de résultat dans le pointeur result
			result = mysql_store_result(mysql);

			while ((row = mysql_fetch_row(result)))
			{
				std::string requetes = "DELETE FROM `sequenceusedequipement` WHERE `Id_Sequence` = '" + std::to_string(atoi(row[0])) + "'";
				mysql_query(mysql, requetes.c_str());
				 requetes = "DELETE FROM `sequence` WHERE `Id_Sequence` =  '" + std::to_string(atoi(row[0])) + "'";
				mysql_query(mysql, requetes.c_str());
			}
		}
	}
	IHM_Delete_Sequence *t = new IHM_Delete_Sequence;
	t->show();
	this->close();

}
