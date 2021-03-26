#include "IHMDMX.h"
#include "iostream"
#include <QLabel>

IHMDMX::IHMDMX() : QWidget()																								// spécification du constructeur
{
	/* Construction du bouton */
	m_bouton = new QPushButton("ConnexionBdd", this);																		// this = pointeur vers le widget parent																							
	m_label = new QLabel("ConnexionBdd", this);
	m_bouton->move(100, 100);
	/* Connexions Signal - Slot */
	QObject::connect(m_bouton, SIGNAL(clicked()), this, SLOT(ConnexionBdd()));												// this = SLOT de IHMDMX (SLOT MAISON)
}
//==========================================================================================

void IHMDMX::ConnexionBdd()
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