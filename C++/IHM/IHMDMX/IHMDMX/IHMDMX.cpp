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
	this->close();

	// faire l'IHM cr�ation �quipement avec tous les champs 
}

//============= Ouverture fen�tre de modification d'�quipement====================================================

void IHMDMX::modifier_equipement()
{
	IHM_Modifier_Equipement *t = new IHM_Modifier_Equipement;
	t->show();
	this->close();
	// r�cup�rer toutes les personnalisations de l'�quipement surpprimer puis pouvoir les modifier
}

//============== Ouverture fen�tre de suppression d'�quipement ===================================================

void IHMDMX::supprimer_equipement()
{
	// faire la requ�te pour supprimer l'�quipement s�lectionner et toute se qui lui est li�
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
