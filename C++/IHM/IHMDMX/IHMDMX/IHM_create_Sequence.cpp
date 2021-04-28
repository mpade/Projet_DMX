#include "IHM_Create_Sequence.h"
#include "iostream"

IHM_Create_Sequence::IHM_Create_Sequence() : QWidget()																								// spécification du constructeur
{	
	grid = new QGridLayout;
	/* Connexions Signal - Slot */
		// this = SLOT de IHMDMX (SLOT MAISON)
	getAllEquipement();
	duree = new QLineEdit;
	duree->setPlaceholderText("Placeholder Text");
	grid->addWidget(duree, 1, 1);
	cree = new QPushButton("Cree", this);
	grid->addWidget(cree, 1, 2);
	QObject::connect(cree, SIGNAL(clicked()), this, SLOT(slidergetEquipement()));
}
//==========================================================================================


void IHM_Create_Sequence::getAllEquipement()
{
	groupBox = new QGroupBox(tr("Equipement"));
	vbox = new QVBoxLayout;
	
	groupBox->setFlat(true);

	e.push_back(new QCheckBox(tr("1"),this));
	e.push_back(new QCheckBox(tr("2"), this));
	e.push_back(new QCheckBox(tr("3"), this));
	e.push_back(new QCheckBox(tr("4"), this));

	for (int i = 0; i < e.size(); i++) {
		vbox->addWidget(e[i]);
	}
	vbox->addStretch(1);
	groupBox->setLayout(vbox);
	grid->addWidget(groupBox, 0, 1);
	setLayout(grid);
}
void IHM_Create_Sequence::slidergetEquipement() {

	for (int i = 0; i < e.size(); i++) {
		if (e[i]->checkState()) {
			IHM_SrolBar_Sequence *t = new IHM_SrolBar_Sequence(3);
			t->show();
		}
			
	}

}

