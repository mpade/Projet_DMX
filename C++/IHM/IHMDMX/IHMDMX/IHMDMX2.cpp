#include "IHMDMX2.h"
#include "iostream"

IHMDMX2::IHMDMX2() : QWidget()																								// spécification du constructeur
{
	setGeometry(100, 100, 400, 400);																						// place la fenêtre aux coordonnés : 100px,100px
				
	/* Construction du bouton */
	sequence_creat = new QPushButton("Cree une Sequence", this);																		// this = pointeur vers le widget parent																							
	sequence_creat->move(50, 100);

	sequence_modifier = new QPushButton("modifier une Sequence", this);
	sequence_modifier->move(50, 150);

	sequence_delete = new QPushButton("Suprimmer une Sequence", this);																		// this = pointeur vers le widget parent																							
	sequence_delete->move(50, 200);

	scene_creat = new QPushButton("Cree une scene", this);
	scene_creat->move(250, 100);

	scene_modifier = new QPushButton("modifier une scene", this);
	scene_modifier->move(250, 150);

	scene_delete = new QPushButton("Suprimmer une scene", this);
	scene_delete->move(250, 200);

	/* Connexions Signal - Slot */
	QObject::connect(sequence_creat, SIGNAL(clicked()), this, SLOT(creat_sequence()));	// this = SLOT de IHMDMX (SLOT MAISON)
	QObject::connect(sequence_modifier, SIGNAL(clicked()), this, SLOT(modifier_sequence()));	// this = SLOT de IHMDMX (SLOT MAISON)
	QObject::connect(sequence_delete, SIGNAL(clicked()), this, SLOT(supprimer_sequence()));	// this = SLOT de IHMDMX (SLOT MAISON)
	QObject::connect(scene_creat, SIGNAL(clicked()), this, SLOT(creat_scene()));	// this = SLOT de IHMDMX (SLOT MAISON)
	QObject::connect(scene_modifier, SIGNAL(clicked()), this, SLOT(modifier_scene()));	// this = SLOT de IHMDMX (SLOT MAISON)
	QObject::connect(scene_delete, SIGNAL(clicked()), this, SLOT(supprimer_scene()));	// this = SLOT de IHMDMX (SLOT MAISON)
}
//==========================================================================================

//==========================================================================================

void IHMDMX2::creat_sequence()
{
	IHM_Create_Sequence *t = new IHM_Create_Sequence;
	t->show();
	this->close();
}

void IHMDMX2::modifier_sequence()
{



}

void IHMDMX2::supprimer_sequence()
{
	IHM_Delete_Sequence *t = new IHM_Delete_Sequence;
	t->show();
	this->close();
}

void IHMDMX2::creat_scene()
{


}

void IHMDMX2::modifier_scene()
{


}

void IHMDMX2::supprimer_scene()
{


}
