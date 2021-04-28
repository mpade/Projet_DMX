#pragma once
#include "main.h"

#include <QWidget>
#include <QObject>
#include <QPushButton>
#include <QMessageBox>
#include "mysql.h"
#include <QLineEdit>
#include <QLabel>
#include <Qcheckbox>
#include <QGroupBox>
#include <QVBoxLayout>
#include <vector>
#include <string>
#include <QtWidgets/QApplication>

class IHM_Create_Sequence : public QWidget // On h�rite de QWidget (IMPORTANT)
{
	Q_OBJECT                    // N�cessaire pour cr�er un slot maison

public:
	IHM_Create_Sequence();                // Constructeur (forc�ment pubic)

public slots:               // Slots maison

	void getAllEquipement();
	void slidergetEquipement();
private:
	QLineEdit *duree;
	QPushButton *cree;
	QGroupBox *groupBox;							// pointeur --> il faudra le construire dynamiquement (new)
	QLabel *m_label;
	MYSQL *mysql;
	MYSQL_ROW row = NULL;
	MYSQL_RES *res = NULL;
	std::vector<QCheckBox*>e;
	QVBoxLayout *vbox;
	QGridLayout *grid;
};
