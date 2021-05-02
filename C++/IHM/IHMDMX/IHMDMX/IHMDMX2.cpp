#include "IHMDMX2.h"
#include "iostream"

IHMDMX2::IHMDMX2() : QWidget()																								// spécification du constructeur
{
	setGeometry(100, 100, 500, 500);																						// place la fenêtre aux coordonnés : 100px,100px
				
	/* Construction du bouton */
	sequence_creat = new QPushButton("Cree une Sequence", this);																		// this = pointeur vers le widget parent																							
	sequence_creat->move(50, 100);

	sequence_delete = new QPushButton("Suprimmer une Sequence", this);																		// this = pointeur vers le widget parent																							
	sequence_delete->move(50, 200);
	/* Connexions Signal - Slot */
	QObject::connect(sequence_creat, SIGNAL(clicked()), this, SLOT(creat_sequence()));	// this = SLOT de IHMDMX (SLOT MAISON)
	
}
//==========================================================================================

//==========================================================================================

void IHMDMX2::creat_sequence()
{
	IHM_Create_Sequence *t = new IHM_Create_Sequence;
	t->show();
	this->close();
}
