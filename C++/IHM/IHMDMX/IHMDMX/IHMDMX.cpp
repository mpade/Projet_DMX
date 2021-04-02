#include "IHMDMX.h"
#include "iostream"
#include <QLabel>

IHMDMX::IHMDMX() : QWidget()																				// spécification du constructeur
{
	
	/* Position de la fenêtre */
	setGeometry(1000, 100, 500, 500);	

	/* Construction des Widgets */
	m_LConnexionBdd = new QLabel("Resultat Liaison BDD", this);
	m_SAfficherEquipement = new QLabel("Resultat Requete Equipement", this);

	/* Position des Widgets */
	m_LConnexionBdd->move(200, 10);
	m_SAfficherEquipement->move(200, 125);
	
	/* Connexions Signal - Slot */																
	

	/* Méthode éxecutée au lancement de l'IHM */
	ConnexionBdd();
	AfficherEquipement();
}
//==========================================================================================

void IHMDMX::ConnexionBdd()
{
	mySQL = mysql_init(NULL);

	if (!mysql_real_connect(mySQL, "mysql-projet-dmx.alwaysdata.net", "231034_pade", "Projet_Dmx1234", "projet-dmx_dmx", 0, NULL, 0)) 
	{
		m_LConnexionBdd->setText("Erreur de connexion a la base");
	}
	else 
	{
		m_LConnexionBdd->setText("Connexion a la bdd reussi");
	}

}
//==========================================================================================

void IHMDMX::AfficherEquipement()
{		
	
	int MaRequete = mysql_query(mySQL, "SELECT `Name` FROM `Equipement` ;");			
	m_SAfficherEquipement->setText("MaRequete");
}
