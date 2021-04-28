#include "IHM_SrolBar_Sequence.h"
IHM_SrolBar_Sequence::IHM_SrolBar_Sequence(int t) : QWidget()																								// spécification du constructeur
{
	groupBox = new QGroupBox(tr("Slider"));
	vbox = new QVBoxLayout;

	groupBox->setFlat(true);
	for (int i = 0; i < t; i++) {
		e.push_back(new QSlider());
	}
	

}