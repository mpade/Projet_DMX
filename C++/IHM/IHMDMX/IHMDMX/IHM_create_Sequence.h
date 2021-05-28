#pragma once
#include "main.h"
#include "IHM_SrolBar_Sequence.h"
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
#include "TCPclient.h"
class IHM_Create_Sequence : public QWidget // On hérite de QWidget (IMPORTANT)
{
	Q_OBJECT                    // Nécessaire pour créer un slot maison

public:
	IHM_Create_Sequence();                // Constructeur (forcément pubic)

public slots:               // Slots maison

	void getAllEquipement();
	void slidergetEquipement();
	void gettest();
private:
	QLineEdit *duree;
	QLineEdit *name;
	QListWidget *listequipement;
	QListWidget *listsequenceequipement;
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
