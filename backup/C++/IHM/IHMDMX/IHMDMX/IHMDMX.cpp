#include "IHMDMX.h"
#include "iostream"
#include <QLabel>

IHMDMX::IHMDMX() : QWidget()																						// spécification du constructeur
{
	/* Position de la fenêtre */
	setGeometry(1000, 100, 500, 500);	

	/* Construction du Widget */
	m_BConnexionBdd = new QPushButton("Liaison BDD", this);
	m_LConnexionBdd = new QLabel("Resultat Liaison BDD", this);

	/* Position des Widgets */
	m_BConnexionBdd->move(200, 100);
	m_LConnexionBdd->move(200, 75);
	
	/* Connexions Signal - Slot */											
	QObject::connect(m_BConnexionBdd, SIGNAL(clicked()), this, SLOT(ConnexionBdd()));//	this = SLOT de IHMDMX (SLOT MAISON)
}
//==========================================================================================

void IHMDMX::ConnexionBdd()
{
	mySQL = mysql_init(NULL);

	if (!mysql_real_connect(mySQL, "localhost", "root", "root", "DMX", 0, NULL, 0)) 
	{
		m_LConnexionBdd->setText("Erreur de connexion a la base");
	}
	else 
	{
		m_LConnexionBdd->setText("Connexion à la bdd reussi");
	}

}

