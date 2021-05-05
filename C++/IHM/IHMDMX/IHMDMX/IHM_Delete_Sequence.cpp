#include "IHM_Delete_Sequence.h"

IHM_Delete_Sequence::IHM_Delete_Sequence() : QWidget()																								// spécification du constructeur
{
	grid = new QGridLayout;
	getAllSequence();
	supprimer = new QPushButton("Supprimer", this);
	grid->addWidget(supprimer, 1, 2);
	QObject::connect(supprimer, SIGNAL(clicked()), this, SLOT(getDeleteSequence()));
}
void IHM_Delete_Sequence::getAllSequence() {

	groupBox = new QGroupBox(tr("Sequence"));
	vbox = new QVBoxLayout;

	groupBox->setFlat(true);

	e.push_back(new QCheckBox(tr("1"), this));
	e.push_back(new QCheckBox(tr("2"), this));
	e.push_back(new QCheckBox(tr("3"), this));
	e.push_back(new QCheckBox(tr("4"), this));
	//e[i]->setObjectName();
	for (int i = 0; i < e.size(); i++) {

		vbox->addWidget(e[i]);
	}
	vbox->addStretch(1);
	groupBox->setLayout(vbox);
	grid->addWidget(groupBox, 0, 1);
	setLayout(grid);

}

void IHM_Delete_Sequence::getDeleteSequence()
{
	for (int i = 0; i < e.size(); i++) {
		if (e[i]->checkState()) {
			//requete pour delete la sequence !!
		}

	}
}
