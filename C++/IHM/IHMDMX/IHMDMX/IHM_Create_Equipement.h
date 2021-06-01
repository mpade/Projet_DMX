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
#include <QGroupBox>
#include <QVBoxLayout>
#include <vector>
#include <string>
#include "IHM_Create_Property.h"
#include <QtWidgets/QApplication>


class IHM_Create_Equipement : public QWidget
{
	Q_OBJECT                    // Nécessaire pour créer un slot maison

public:
	IHM_Create_Equipement();

public slots:					// Slots maison

	void Connexionbdd();
	void Validation();


private:

	QLineEdit *LE_Name;
	QLineEdit *LE_Voies;
	QLineEdit *LE_AdressEquipement;

	QLabel *L_Name;
	QLabel *L_Voies;
	QLabel *L_AdressEquipement;
	QLabel *Text1;
	QLabel *test;

	QString Name;
	QString Voies;
	QString AdressEquipement;

	QPushButton * B_Valider;

	QGridLayout *grid2;

	MYSQL *mySQL;
	MYSQL_ROW row = NULL;
	MYSQL_ROW row1 = NULL;
	MYSQL_RES *result = NULL;
	MYSQL_RES *result1 = NULL;

};
