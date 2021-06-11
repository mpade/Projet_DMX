#include "IHM_Create_Equipement.h"
#include "IHM_Create_Property.h"
#include "IHMDMX.h"
#include "iostream"
#include <QLabel>

IHM_Create_Equipement::IHM_Create_Equipement() : QWidget()																				// spécification du constructeur
{
	/* Position de la fenêtre */
	setGeometry(1000, 100, 500, 500);


	/* Construction des Widgets */
	LE_Name = new QLineEdit();
	LE_Voies = new QLineEdit();
	LE_AdressEquipement = new QLineEdit();
	L_Name = new QLabel("Nom de l'equipement :", this);
	L_Voies = new QLabel("Nombre de voies :", this);
	L_AdressEquipement = new QLabel("Position sur le bus DMX :", this);
	Text1 = new QLabel("Creation d'un equipement", this);
	grid2 = new QGridLayout;
	B_Valider = new QPushButton("Valider", this);


	/* Position des Widgets */
	grid2->addWidget(Text1, 0, 0, 3, 3);
	grid2->addWidget(LE_Name, 1, 2, 1, 1);
	grid2->addWidget(LE_Voies, 2, 2, 1, 1);
	grid2->addWidget(LE_AdressEquipement, 3, 2, 1, 1);
	grid2->addWidget(L_Name, 1, 1, 1, 1);
	grid2->addWidget(L_Voies, 2, 1, 1, 1);
	grid2->addWidget(L_AdressEquipement, 3, 1, 1, 1);
	grid2->addWidget(B_Valider, 3, 2, 2, 2);



	setLayout(grid2);

	/* Connexions Signal - Slot */
	QObject::connect(B_Valider, SIGNAL(clicked()), this, SLOT(Validation()));


	/* Méthode éxecutée au lancement de l'IHM */
	Connexionbdd();

}
//============================ Connexion à la BDD ===============================================

void IHM_Create_Equipement::Connexionbdd()
{
	mySQL = mysql_init(NULL);

	if (!mysql_real_connect(mySQL, "localhost", "root", "", "Projet_DMX", 0, NULL, 0))
	{
		QMessageBox msgBox;
		msgBox.setText("Erreur de connection a la BDD");
		msgBox.exec();
	}
}

//============== Création du nouvel équipement et envoie en base ===============

void IHM_Create_Equipement::Validation()
{
	Name = LE_Name->text();
	Voies = LE_Voies->text();
	AdressEquipement = LE_AdressEquipement->text();


	std::string InsertEquipement = "INSERT INTO `equipement`(`Id_Equipement`, `Name`, `Nb_voie`) VALUES (NULL,'" + Name.toStdString() + "','" + Voies.toStdString() + "')";
	mysql_query(mySQL, InsertEquipement.c_str());

	std::string requetId_equipement = "SELECT `Id_Equipement` FROM `equipement` WHERE `Name` ='" + Name.toStdString() + "'";
	mysql_query(mySQL, requetId_equipement.c_str());

	result = mysql_store_result(mySQL);

	row = mysql_fetch_row(result);

	std::string requetId_adressequipement = "INSERT INTO `adressequipement` (`Id_AdressEquipement`, `Adresse`, `Id_Equipement`) VALUES (NULL, '" + AdressEquipement.toStdString() + "' , '" + std::to_string(atoi(row[0])) + "')";
	mysql_query(mySQL, requetId_adressequipement.c_str());

	LE_Name->clear();
	LE_Voies->clear();
	LE_AdressEquipement->clear();

	std::string requet_nbvoies = "SELECT * FROM `equipement` WHERE `Name`= '" + Name.toStdString() + "'";
	mysql_query(mySQL, requet_nbvoies.c_str());

	result1 = mysql_store_result(mySQL);

	row1 = mysql_fetch_row(result1);

	AdressEquipement += Voies;
	

	

	IHM_Create_Property *t = new IHM_Create_Property((atoi(row1[2])), Name);
	t->show();

	this->close();
}