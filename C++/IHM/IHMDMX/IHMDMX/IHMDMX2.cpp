#include "IHMDMX2.h"
#include "iostream"
#include <QLabel>

IHMDMX2::IHMDMX2() : QWidget()																								// spécification du constructeur
{
	setGeometry(100, 100, 500, 500);																						// place la fenêtre aux coordonnés : 100px,100px
				

	/* Construction du bouton */
	m_bouton = new QPushButton("ConnexionBdd", this);																		// this = pointeur vers le widget parent																							
	m_label = new QLabel("ConnexionBdd", this);
	m_bouton->move(100, 100);
	/* Connexions Signal - Slot */
	QObject::connect(m_bouton, SIGNAL(clicked()), this, SLOT(ConnexionBdd()));												// this = SLOT de IHMDMX (SLOT MAISON)
}
//==========================================================================================

void IHMDMX2::ConnexionBdd()
{
	mysql = mysql_init(NULL);

	if (mysql) {
		m_label->setText( "Mysql Initialise");
	}
	else
	{
		 m_label->setText("Impossible d'Initialise Mysql");
	}
}
//==========================================================================================