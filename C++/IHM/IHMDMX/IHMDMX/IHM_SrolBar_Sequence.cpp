#include "IHM_SrolBar_Sequence.h"
IHM_SrolBar_Sequence::IHM_SrolBar_Sequence(int t) : QWidget()																								// spécification du constructeur
{
	int x = 65, y = 20;
	
	for (int i = 0; i < t; i++) {
		e.push_back(new QSlider(Qt::Vertical, this));
		a.push_back(new QLCDNumber(this));
	}

	for (int i = 0; i < e.size(); i++) {
		e[i]->setMaximum(255);
		e[i]->move(x, y);
		x += 75;
	}
	 x = 40, y = 120;
	for (int i = 0; i < a.size(); i++) {
		a[i]->move(x, y);
		x += 75;
	}
	for (int i = 0; i < a.size(); i++) {
		QObject::connect(e[i], SIGNAL(valueChanged(int)), a[i], SLOT(display(int)));
	}
	
}