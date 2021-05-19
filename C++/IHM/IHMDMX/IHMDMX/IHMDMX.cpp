#include "IHMDMX.h"
#include "iostream"
#include <QLabel>

IHMDMX::IHMDMX() : QWidget()																				// spécification du constructeur
{
	/* Position de la fenêtre */
	setGeometry(1000, 100, 500, 500);	

	/* Construction des Widgets */
	m_LConnexionBdd = new QLabel("Resultat Liaison BDD", this);
	equipement_creat = new QPushButton("Cree un equipement", this);
	equipement_modifier = new QPushButton("modifier un equipement", this);
	equipement_delete = new QPushButton("Suprimmer un equipement", this);
	grid1 = new QGridLayout;
	ListAfficherEquipement = new QListWidget();
	
	/* Position des Widgets */
	grid1->addWidget(m_LConnexionBdd, 0, 0, 1, 3);
	grid1->addWidget(ListAfficherEquipement, 1, 1);
	grid1->addWidget(equipement_creat, 2, 3, 3, 1);
	grid1->addWidget(equipement_modifier, 2, 2, 3, 1);
	grid1->addWidget(equipement_delete, 2, 1, 3, 1);
	// mieux arranger l'IHM
	

	setLayout(grid1);

	/* Connexions Signal - Slot */																
	QObject::connect(equipement_creat, SIGNAL(clicked()), this, SLOT(creat_equipement()));	
	QObject::connect(equipement_modifier, SIGNAL(clicked()), this, SLOT(modifier_equipement()));	
	QObject::connect(equipement_delete, SIGNAL(clicked()), this, SLOT(supprimer_equipement()));	
	// créer la connexion entre la liste déroulante et les bouttons 

	/* Méthode éxecutée au lancement de l'IHM */
	ConnexionBdd();
	getAllEquipement();
	
}

//============================= Connexion à la BDD =============================================================

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

//================= Ouverture fenêtre création d'équipement ======================================================

void IHMDMX::creat_equipement()
{
	IHM_Create_Equipement *t = new IHM_Create_Equipement;
	t->show();
	this->close();

	// faire l'IHM création équipement avec tous les champs 
}

//============= Ouverture fenêtre de modification d'équipement====================================================

void IHMDMX::modifier_equipement()
{
	IHM_Modifier_Equipement *t = new IHM_Modifier_Equipement;
	t->show();
	this->close();
	// récupérer toutes les personnalisations de l'équipement surpprimer puis pouvoir les modifier
}

//============== Ouverture fenêtre de suppression d'équipement ===================================================

void IHMDMX::supprimer_equipement()
{
	// faire la requête pour supprimer l'équipement sélectionner et toute se qui lui est lié
}

//======== Récupération des noms d'équipement dans une liste déroulante ==========================================

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
