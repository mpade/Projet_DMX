#include "IHM_Modifier_Equipement.h"
#include "IHMDMX.h"
#include "iostream"
#include <QLabel>

IHM_Modifier_Equipement::IHM_Modifier_Equipement() : QWidget()																				// spécification du constructeur
{
	/* Position de la fenêtre */
	setGeometry(1000, 100, 500, 500);


	/* Construction des Widgets */
	LE_Modif_Name = new QLineEdit();
	LE_Modif_Voies = new QLineEdit();
	LE_Modif_AdressEquipement = new QLineEdit();
	L_Name = new QLabel("Nom de l'equipement :", this);
	L_Voies = new QLabel("Nombre de voies :", this);
	L_AdressEquipement = new QLabel("Position sur le bus DMX :", this);
	grid2 = new QGridLayout;
	B_Modif_Valider = new QPushButton("Valider", this);
	ListAfficherEquipement = new QListWidget();
	refresh = new QPushButton("Actualiser", this);
	m_LConnexionBdd = new QLabel("Resultat Liaison BDD", this);



	/* Position des Widgets */
	grid2->addWidget(ListAfficherEquipement, 1, 1, 1, 1);
	grid2->addWidget(LE_Modif_Name, 2, 2, 1, 1);
	grid2->addWidget(LE_Modif_Voies, 3, 2, 1, 1);
	grid2->addWidget(LE_Modif_AdressEquipement, 4, 2, 1, 1);
	grid2->addWidget(L_Name, 2, 1, 1, 1);
	grid2->addWidget(L_Voies, 3, 1, 1, 1);
	grid2->addWidget(L_AdressEquipement, 4, 1, 1, 1);
	grid2->addWidget(B_Modif_Valider, 5, 2, 2, 2);
	grid2->addWidget(refresh, 0, 3, 1, 3);
	grid2->addWidget(m_LConnexionBdd, 6, 2, 2, 2);


	setLayout(grid2);


	/* Connexions Signal - Slot */
	QObject::connect(B_Modif_Valider, SIGNAL(clicked()), this, SLOT(Modif_Validation()));
	QObject::connect(ListAfficherEquipement, SIGNAL(itemDoubleClicked(QListWidgetItem *)), this, SLOT(Placeholder()));


	/* Méthode éxecutée au lancement de l'IHM */
	Connexionbdd();
	getAllEquipement();

}
//==============================================================================================================

void IHM_Modifier_Equipement::Connexionbdd()
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

//==============================================================================================================

void IHM_Modifier_Equipement::getAllEquipement()
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

//==============================================================================================================

void IHM_Modifier_Equipement::Refresh()
{
	getAllEquipement();
}

//==============================================================================================================

void IHM_Modifier_Equipement::Placeholder()
{

	if (ListAfficherEquipement->selectedItems().count() == 1) {
		QListWidgetItem *item = ListAfficherEquipement->takeItem(ListAfficherEquipement->currentRow());
		std::string Name = item->text().toStdString();

		std::string RequetEquipement = "SELECT * FROM `equipement` WHERE `Name` = '" + Name + "'";
		mysql_query(mySQL, RequetEquipement.c_str());

		result = mysql_store_result(mySQL);
		row = mysql_fetch_row(result);

		Old_Name = Name.c_str();
		LE_Modif_Name->setPlaceholderText(Old_Name);

		std::string A_Voies = std::to_string(atoi(row[2]));
		Old_Voies = A_Voies.c_str();
		LE_Modif_Voies->setPlaceholderText(Old_Voies);

		std::string RequetAdressequipement = "SELECT * FROM `adressequipement` WHERE `Id_Equipement` = '" + std::to_string(atoi(row[0])) + "'";
		mysql_query(mySQL, RequetAdressequipement.c_str());

		results = mysql_store_result(mySQL);

		while ((rows = mysql_fetch_row(results))) {

			std::string A_AdressEquipement = std::to_string(atoi(rows[1]));
			Old_AdressEquipement = A_AdressEquipement.c_str();

			LE_Modif_AdressEquipement->setPlaceholderText(Old_AdressEquipement);
		};

		std::string RequetProperty = "SELECT * FROM `property` WHERE `Id_Equipement` = '" + std::to_string(atoi(row[0])) + "'";
		mysql_query(mySQL, RequetProperty.c_str());

		/*
		result1 = mysql_store_result(mySQL);

		while ((row1 = mysql_fetch_row(result1))) {

		};
		*/
	}

	mysql_close(mySQL);
}


//==============================================================================================================

void IHM_Modifier_Equipement::Modif_Validation()
{
	mySQL = mysql_init(NULL);

	(!mysql_real_connect(mySQL, "192.168.64.102", "DMX", "dmx", "Projet_DMX", 0, NULL, 0));


	Name = LE_Modif_Name->text();
	Voies = LE_Modif_Voies->text();
	AdressEquipement = LE_Modif_AdressEquipement->text();
	/*
		// UPDATE `equipement` SET `Id_Equipement`='[value-1]',`Name`='[value-2]',`Nb_voie`='[value-3]' WHERE 1
		std::string Select_equipement = "SELECT `Id_Equipement` FROM `equipement` WHERE `Name` ='" + Old_Name.toStdString() + "'";
		mysql_query(mySQL, Select_equipement.c_str());
		result = mysql_store_result(mySQL);

		row = mysql_fetch_row(result);

		std::string Update_equipement = "UPDATE `equipement` SET `Name` = '" + Name.toStdString() + "', `Nb_voie` = '" + Voies.toStdString() + "' WHERE `Id_Equipement`= '" + std::to_string(atoi(row[0])) + "'";
		mysql_query(mySQL, Update_equipement.c_str());

		std::string Select_adressequipement = "SELECT `Id_AdressEquipement` FROM `adressequipement` WHERE `Id_Equipement` ='" + std::to_string(atoi(row[0])) + "'";
		mysql_query(mySQL, Select_adressequipement.c_str());
		results = mysql_store_result(mySQL);

		rows = mysql_fetch_row(results);

		//std::string Update_adressequipement = "UPDATE `adressequipement` SET `Adresse` = '" + AdressEquipement.toStdString() + "'  WHERE `Id_Equipement` = '" + std::to_string(atoi(row[0]))"' AND `Id_AdressEquipement` '" + std::to_string(atoi(row[0])) + "'";
		//mysql_query(mySQL, Update_adressequipement.c_str());
	*/

	std::string update_equipement = "UPDATE `equipement` SET `Name`= '" + Name.toStdString() + "', `Nb_voie` = '" + Voies.toStdString() + "' WHERE `Id_Equipement` = '" + std::to_string(atoi(row[0])) + "'";
	mysql_query(mySQL, update_equipement.c_str());
	result1 = mysql_store_result(mySQL);

	std::string update_adressequipement = "UPDATE `adressequipement` SET `Adresse` = '" + AdressEquipement.toStdString() + "' WHERE `Id_Equipement` = '" + std::to_string(atoi(row[0])) + "'";
	mysql_query(mySQL, update_adressequipement.c_str());
	result2 = mysql_store_result(mySQL);


	LE_Modif_Name->clear();
	LE_Modif_Voies->clear();
	LE_Modif_AdressEquipement->clear();
	mysql_close(mySQL);
};