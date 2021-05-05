#include "IHMDMX.h"
#include "iostream"
#include <QLabel>

IHMDMX::IHMDMX() : QWidget()																				// spécification du constructeur
{
	/* Position de la fenêtre */
	setGeometry(1000, 100, 500, 500);	

	/* Construction des Widgets */
	m_LConnexionBdd = new QLabel("Resultat Liaison BDD", this);
	//m_SAfficherEquipement = new QLabel("Resultat Requete Equipement", this);
	equipement_creat = new QPushButton("Cree un equipement", this);
	equipement_modifier = new QPushButton("modifier un equipement", this);
	equipement_delete = new QPushButton("Suprimmer un equipement", this);
	

	/* Position des Widgets */
	m_LConnexionBdd->move(200, 10);
	//m_SAfficherEquipement->move(200, 125);
	equipement_creat->move(250, 100);
	equipement_modifier->move(250, 150);
	equipement_delete->move(250, 200);


	/* Connexions Signal - Slot */																
	QObject::connect(equipement_creat, SIGNAL(clicked()), this, SLOT(creat_equipement()));	// this = SLOT de IHMDMX (SLOT MAISON)
	QObject::connect(equipement_modifier, SIGNAL(clicked()), this, SLOT(modifier_equipement()));	// this = SLOT de IHMDMX (SLOT MAISON)
	QObject::connect(equipement_delete, SIGNAL(clicked()), this, SLOT(supprimer_equipement()));	// this = SLOT de IHMDMX (SLOT MAISON)

	/* Méthode éxecutée au lancement de l'IHM */
	ConnexionBdd();
	// AfficherEquipement();
}

//==========================================================================================

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

//==========================================================================================
/*
void IHMDMX::AfficherEquipement()
{		
	
	int MaRequete = mysql_query(mySQL, "SELECT `Name` FROM `Equipement` ;");			
	m_SAfficherEquipement->setText("MaRequete");
}
*/
//==========================================================================================

void IHMDMX::creat_equipement()
{
	IHM_Create_Equipement *t = new IHM_Create_Equipement;
	t->show();
	this->close();
}

//==========================================================================================

void IHMDMX::modifier_equipement()
{
	IHM_Modifier_Equipement *t = new IHM_Modifier_Equipement;
	t->show();
	this->close();
}

//==========================================================================================

void IHMDMX::supprimer_equipement()
{

}
