#include "IHMDMX.h"
#include "iostream"
#include <QLabel>

IHMDMX::IHMDMX() : QWidget()																				// sp�cification du constructeur
{
	/* Position de la fen�tre */
	setGeometry(1000, 100, 500, 500);


	/* Construction des Widgets */
	m_LConnexionBdd = new QLabel("Resultat Liaison BDD", this);
	equipement_creat = new QPushButton("Cree un equipement", this);
	equipement_modifier = new QPushButton("modifier un equipement", this);
	equipement_delete = new QPushButton("Supprimer un equipement", this);
	refresh = new QPushButton("Actualiser", this);
	grid1 = new QGridLayout;
	ListAfficherEquipement = new QListWidget();
	Test_en_directe = new QPushButton("Test", this);



	/* Position des Widgets */
	grid1->addWidget(m_LConnexionBdd, 0, 0, 1, 3);
	grid1->addWidget(ListAfficherEquipement, 1, 1);
	grid1->addWidget(equipement_creat, 2, 3, 3, 1);
	grid1->addWidget(equipement_modifier, 2, 2, 3, 1);
	grid1->addWidget(equipement_delete, 2, 1, 3, 1);
	grid1->addWidget(refresh, 0, 3, 1, 3);
	grid1->addWidget(Test_en_directe, 2, 4, 3, 1);
	// mieux arranger l'IHM


	setLayout(grid1);

	/* Connexions Signal - Slot */
	QObject::connect(equipement_creat, SIGNAL(clicked()), this, SLOT(creat_equipement()));
	QObject::connect(equipement_modifier, SIGNAL(clicked()), this, SLOT(modifier_equipement()));
	QObject::connect(equipement_delete, SIGNAL(clicked()), this, SLOT(supprimer_equipement()));
	QObject::connect(Test_en_directe, SIGNAL(clicked()), this, SLOT(test_en_directe()));
	QObject::connect(refresh, SIGNAL(clicked()), this, SLOT(Refresh()));


	// cr�er la connexion entre la liste d�roulante et les bouttons 

	/* M�thode �xecut�e au lancement de l'IHM */
	ConnexionBdd();
	getAllEquipement();

}

//============================= Connexion � la BDD =============================================================

void IHMDMX::ConnexionBdd()
{
	mySQL = mysql_init(NULL);

	if (!mysql_real_connect(mySQL, "192.168.64.102", "DMX", "dmx", "Projet_DMX", 0, NULL, 0))
	{
		m_LConnexionBdd->setText("Erreur de connexion a la base");
	}
	else
	{
		m_LConnexionBdd->setText("Connexion a la bdd reussi");
	}

}

//================= Ouverture fen�tre cr�ation d'�quipement ======================================================

void IHMDMX::creat_equipement()
{
	IHM_Create_Equipement *t = new IHM_Create_Equipement;
	t->show();


	// faire l'IHM cr�ation �quipement avec tous les champs 
}

//============= Ouverture fen�tre de modification d'�quipement====================================================

void IHMDMX::modifier_equipement()
{

	IHM_Modifier_Equipement *t = new IHM_Modifier_Equipement;
	t->show();

	// r�cup�rer toutes les personnalisations de l'�quipement puis pouvoir les modifier
}
//============== Suppression d'un �quipement et de ces composants ==============================================

void IHMDMX::supprimer_equipement()
{
	if (ListAfficherEquipement->selectedItems().count() == 1) {
		QListWidgetItem *item = ListAfficherEquipement->takeItem(ListAfficherEquipement->currentRow());

		std::string Name = item->text().toStdString();
		std::string requetId_equipement = "SELECT * FROM `equipement` WHERE `Name` ='" + Name + "'";
		mysql_query(mySQL, requetId_equipement.c_str());

		result = mysql_store_result(mySQL);

		while ((row = mysql_fetch_row(result)))
		{

			std::string requetId_adressequipement = "SELECT * FROM `adressequipement` WHERE `Id_Equipement` ='" + std::to_string(atoi(row[0])) + "'";
			mysql_query(mySQL, requetId_adressequipement.c_str());

			result1 = mysql_store_result(mySQL);

			while ((row1 = mysql_fetch_row(result1))) {

				std::string requetDelete = "DELETE FROM `sequenceusedequipement` WHERE `Id_AdressEquipement` = '" + std::to_string(atoi(row1[0])) + "'";
				mysql_query(mySQL, requetDelete.c_str());

			}

			std::string requetDelete2 = "DELETE FROM `adressequipement` WHERE `Id_Equipement` = '" + std::to_string(atoi(row[0])) + "'";
			mysql_query(mySQL, requetDelete2.c_str());

			std::string requetDelete3 = "DELETE FROM `equipement` WHERE `Id_Equipement` = '" + std::to_string(atoi(row[0])) + "'";
			mysql_query(mySQL, requetDelete3.c_str());
		}

	}


}

//======== R�cup�ration des noms d'�quipement dans une liste d�roulante ==========================================

void IHMDMX::getAllEquipement()
{
	std::string requet = "SELECT `Name` FROM `equipement`";
	mysql_query(mySQL, requet.c_str());
	int x = 0;

	result = mysql_store_result(mySQL);

	while ((row = mysql_fetch_row(result)))
	{
		e.push_back(new QListWidgetItem);
		e[x]->setText(row[0]);
		e[x]->setSelected(false);
		ListAfficherEquipement->insertItem(x, e[x]);
		x++;
	}

}

//======================= Actualiser la liste d'�quipement =======================================================

void IHMDMX::Refresh()
{
	getAllEquipement();
}

void IHMDMX::test_en_directe()
{
	if (ListAfficherEquipement->selectedItems().count() == 1) {
		QListWidgetItem *item = ListAfficherEquipement->takeItem(ListAfficherEquipement->currentRow());
		std::string Name = item->text().toStdString();

		std::string requetId_equipement = "SELECT * FROM `equipement` WHERE `Name` ='" + Name + "'";
		mysql_query(mySQL, requetId_equipement.c_str());

		result = mysql_store_result(mySQL);
		row = mysql_fetch_row(result);

		std::string requetId_adressequipement = "SELECT * FROM `adressequipement` WHERE `Id_Equipement` ='" + std::to_string(atoi(row[0])) + "'";
		mysql_query(mySQL, requetId_adressequipement.c_str());

		result1 = mysql_store_result(mySQL);
		row1 = mysql_fetch_row(result1);

		Voies = atoi(row[2]);
		Adresse = atoi(row1[1]);
		Id_Equipement = atoi(row[0]);

		IHM_Test_En_Directe * t = new IHM_Test_En_Directe(Voies, Adresse, Id_Equipement);
		t->show();
	}

}