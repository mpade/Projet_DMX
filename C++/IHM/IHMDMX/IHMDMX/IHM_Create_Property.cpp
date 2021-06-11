#include "IHM_Create_Property.h"
#include "IHMDMX.h"
#include "iostream"
#include <QLabel>

IHM_Create_Property::IHM_Create_Property(int nb_voies, QString name) : QWidget()																				// spécification du constructeur
{
	NbVoies = nb_voies;
	Name = name;

	/* Position de la fenêtre */
	setGeometry(1000, 100, 350, 550);


	/* Construction des Widgets */
	valider = new QPushButton("Valider", this);
	L_Order = new QLabel("Order", this);
	L_Description = new QLabel("Description", this);



	/* Position des Widgets */
	valider->move(140, 0);
	L_Order->move(40,50);
	L_Description->move(220,50);


	/* Connexions Signal - Slot */
	QObject::connect(valider, SIGNAL(clicked()), this, SLOT(Validation2()));


	/* Méthode éxecutée au lancement de l'IHM */
	Connexionbdd();
	NbVoie();

}
//=========================== Connexion à la BDD ==========================================

void IHM_Create_Property::Connexionbdd()
{
	mySQL = mysql_init(NULL);

	if (!mysql_real_connect(mySQL, "localhost", "root", "", "Projet_DMX", 0, NULL, 0))
	{
		QMessageBox msgBox;
		msgBox.setText("Erreur de connection a la BDD");
		msgBox.exec();
	}
}


//========= Création des nouvelles propriétées de l'équipement et envoie en base ==================

void IHM_Create_Property::Validation2()
{


	std::string requet_id = "SELECT * FROM `equipement` WHERE `Name`= '" + Name.toStdString() + "'";
	mysql_query(mySQL, requet_id.c_str());

	result2 = mysql_store_result(mySQL);
	row2 = mysql_fetch_row(result2);

	for (int i = 0; i < NbVoies; i++) {
		
			Order0 = a[i]->text();
			Description0 = b[i]->text();

			std::string insert_property = "INSERT INTO `property`(`id_property`, `Order`,`Description`,`Id_Equipement`) VALUES (NULL,'" + Order0.toStdString() + "','" + Description0.toStdString() + "','" + std::to_string(atoi(row2[0])) + "')";
			mysql_query(mySQL, insert_property.c_str());
		}


	this->close();
}

//=========== Récupération du nombre de voies et affichage des Line Edit =================

void IHM_Create_Property::NbVoie()
{
	int Order = 1;
	int x = 0, y = 75;

	for (int i = 0; i < NbVoies; i++) {
		a.push_back(new QLineEdit(this));
		b.push_back(new QLineEdit(this));
	}

	for (int i = 0; i < a.size(); i++) {
		a[i]->setObjectName(QString::number(Order));
		a[i]->setText(QString::number(Order));
		Order++;
	}

	for (int i = 0; i < b.size(); i++) {
		b[i]->setObjectName(QString::number(Description));
		Description++;
	}

	y = 75;

	for (int i = 0; i < a.size(); i++) {
		a[i]->move(20, y);
		y += 50;
	}

	y = 75;

	for (int i = 0; i < b.size(); i++) {
		b[i]->move(200, y);
		y += 50;
	}
}

//==============================================================================================================
