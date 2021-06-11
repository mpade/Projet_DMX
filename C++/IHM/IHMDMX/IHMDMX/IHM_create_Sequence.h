#pragma once
#include "main.h"
#include "IHM_SrolBar_Sequence.h"
#include <QWidget>
#include <QObject>
#include <QPushButton>
#include <QMessageBox>
#include "mysql_bdd.h"
#include <QLineEdit>
#include <QLabel>
#include <Qcheckbox>
#include <QGroupBox>
#include <QVBoxLayout>
#include <vector>
#include <string>
#include <QtWidgets/QApplication>

class IHM_Create_Sequence : public QWidget // On hérite de QWidget (IMPORTANT)
{
	Q_OBJECT                    // Nécessaire pour créer un slot maison

public:
	IHM_Create_Sequence();                // Constructeur (forcément pubic)

public slots:               // Slots maison

	void getAlllistEquipemnt();
	void slidergetEquipement();
	void gettest();
private:
	mysql_bdd * bdd;
	QLineEdit *duree;
	QLineEdit *name;
	QListWidget *listequipement;
	QListWidget *listsequenceequipement;
	QPushButton *cree;
	QGroupBox *groupBox;							// pointeur --> il faudra le construire dynamiquement (new)
	QLabel *m_label;
	QVBoxLayout *vbox;
	QGridLayout *grid;
};
