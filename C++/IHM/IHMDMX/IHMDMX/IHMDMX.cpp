#include "IHMDMX.h"
#include "iostream"
#include <QLabel>

IHMDMX::IHMDMX() : QWidget()																				// sp�cification du constructeur
{
	/* Position de la fen�tre */
	setGeometry(1000, 100, 500, 500);	

	/* Construction des Widgets */
	//grid1 = new QGridLayout;
	m_LConnexionBdd = new QLabel("Resultat Liaison BDD", this);
	equipement_creat = new QPushButton("Cree un equipement", this);
	equipement_modifier = new QPushButton("modifier un equipement", this);
	equipement_delete = new QPushButton("Suprimmer un equipement", this);
	//ListAfficherEquipement = new QListWidget(this);
	

	/* Position des Widgets */
	//m_LConnexionBdd->move(200, 10);
	//equipement_creat->move(250, 100);
	//equipement_modifier->move(250, 150);
	//equipement_delete->move(250, 200);
	//grid1->addWidget(ListAfficherEquipement);





	// setLayout(grid1);

	/* TEST */
	grid1 = new QGridLayout;
	ListAfficherEquipement = new QListWidget();
	

	grid1->addWidget(ListAfficherEquipement, 1, 1);
	grid1->addWidget(equipement_creat, 2, 3, 3, 1);
	grid1->addWidget(equipement_modifier, 2, 2, 3, 1);
	grid1->addWidget(equipement_delete, 2, 1, 3, 1);
	grid1->addWidget(m_LConnexionBdd, 0, 0, 1, 3);

	setLayout(grid1);

	/* Connexions Signal - Slot */																
	QObject::connect(equipement_creat, SIGNAL(clicked()), this, SLOT(creat_equipement()));	
	QObject::connect(equipement_modifier, SIGNAL(clicked()), this, SLOT(modifier_equipement()));	
	QObject::connect(equipement_delete, SIGNAL(clicked()), this, SLOT(supprimer_equipement()));	

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
	this->close();
}

//============= Ouverture fen�tre de modification d'�quipement====================================================

void IHMDMX::modifier_equipement()
{
	IHM_Modifier_Equipement *t = new IHM_Modifier_Equipement;
	t->show();
	this->close();
}

//============== Ouverture fen�tre de suppression d'�quipement ===================================================

void IHMDMX::supprimer_equipement()
{

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

//==========================================================================================
