#include "IHMDMX.h"
#include "iostream"

IHMDMX::IHMDMX() : QWidget()																								// spécification du constructeur
{
	/* Construction du bouton */
	m_bouton = new QPushButton("ConnexionBdd", this);																		// this = pointeur vers le widget parent, pointeur vers 'moi'																							// RePositionnement Absolu

	/* Connexions Signal - Slot */
	QObject::connect(m_bouton, SIGNAL(clicked()), this, SLOT(ConnexionBdd()));												// this = SLOT de MyWindow (SLOT MAISON)
}
//==========================================================================================

void IHMDMX::ConnexionBdd()
{
	mysql = mysql_init(NULL);

	if (mysql) {
		std::cout << "mySql initialisee !" << std::endl;
	}
	else
	{
		std::cout << "Impossible d'initialisee !" << std::endl;
	}
}
//==========================================================================================