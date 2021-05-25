#include "IHM_Create_Sequence.h"
#include "iostream"

IHM_Create_Sequence::IHM_Create_Sequence() : QWidget()																								// spécification du constructeur
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
	duree = new QLineEdit;
	duree->setPlaceholderText("Duree en seconde !");
	listequipement = new QListWidget();
	listsequenceequipement = new QListWidget();
	getAllEquipement();
	
	grid->addWidget(listequipement, 0, 0);
	grid->addWidget(listsequenceequipement, 0, 1);
	grid->addWidget(duree, 1, 0);
	cree = new QPushButton("Cree", this);
	grid->addWidget(cree, 2, 0, 1, 3);
	name = new QLineEdit;
	name->setPlaceholderText("entre un nom");
	grid->addWidget(name, 1, 1);
	QObject::connect(cree, SIGNAL(clicked()), this, SLOT(slidergetEquipement()));
	QObject::connect(listequipement, SIGNAL(itemDoubleClicked(QListWidgetItem *)), this, SLOT(gettest()));
	QObject::connect(listsequenceequipement, SIGNAL(itemDoubleClicked(QListWidgetItem *)), this, SLOT(gettest()));
	setLayout(grid);
	}
}
//==========================================================================================


void IHM_Create_Sequence::getAllEquipement()
{
	mysql_query(mysql, "SELECT  `Name` FROM `equipement` WHERE 1");

	MYSQL_RES *result = NULL;
	MYSQL_ROW row;

	result = mysql_store_result(mysql);

	while ((row = mysql_fetch_row(result)))
	{
		QListWidgetItem *item = new QListWidgetItem();
		item->setText(row[0]);
		listequipement->addItem(item);

	}
}

void IHM_Create_Sequence::gettest()
{
	int i = 0;
	if (listequipement->selectedItems().count() == 1) {
		i = listequipement->currentRow();
		QListWidgetItem *item = listequipement->takeItem(i);
		listsequenceequipement->addItem(item);
		listequipement->clearSelection();
	}
	if (listsequenceequipement->selectedItems().count() == 1) {
		QListWidgetItem *item = listsequenceequipement->takeItem(listsequenceequipement->currentRow());
		listequipement->addItem(item);
		listsequenceequipement->clearSelection();
	}

}

void IHM_Create_Sequence::slidergetEquipement() {
	if (name->displayText() != "" || duree->displayText() != "") {
		
		std::string requete = "INSERT INTO `sequence`(`Id_Sequence`, `Duree`, `name`) VALUES (NULL,'"+ duree->displayText().toStdString() +"','"+ name->displayText().toStdString() +"')";
		mysql_query(mysql, requete.c_str());
		int x = listsequenceequipement->count();
		for (int i = 0; i < x; i++)
		{

			QListWidgetItem *item = listsequenceequipement->takeItem(0);
				std::string names = item->text().toStdString();
				std::string requete = "SELECT `Id_Equipement`, `Nb_voie` FROM `equipement` WHERE `Name` = '" + names + "'";

				mysql_query(mysql, requete.c_str());

				//Déclaration des pointeurs de structure
				MYSQL_RES *result = NULL;
				MYSQL_ROW row;


				//On met le jeu de résultat dans le pointeur result
				result = mysql_store_result(mysql);

				while ((row = mysql_fetch_row(result)))
				{

					std::string requetes = "SELECT `Adresse` FROM `adressequipement` WHERE `Id_Equipement` = " + std::to_string(atoi(row[0]));
					mysql_query(mysql, requetes.c_str());
					MYSQL_RES *results = NULL;
					MYSQL_ROW rows;
					results = mysql_store_result(mysql);
					while ((rows = mysql_fetch_row(results)))
					{
						std::string requetesd = "SELECT `Id_Sequence` FROM `sequence` WHERE name = '"+ name->displayText().toStdString()+"'";
						mysql_query(mysql, requetesd.c_str());
						MYSQL_RES *resultsd = NULL;
						MYSQL_ROW rowsd;
						resultsd = mysql_store_result(mysql);
						while ((rowsd = mysql_fetch_row(resultsd)))
						{
							//On ecrit toutes les valeurs
							IHM_SrolBar_Sequence *t = new IHM_SrolBar_Sequence(item->text(), atoi(row[1]), atoi(rows[0]), atoi(rowsd[0]));
							t->show();
						}
					}

				}





			}

		}
	}



