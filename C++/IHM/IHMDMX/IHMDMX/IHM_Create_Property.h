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
#include <QtWidgets/QApplication>


class IHM_Create_Property : public QWidget
{
	Q_OBJECT                    // Nécessaire pour créer un slot maison

public:
	IHM_Create_Property(int, QString);

public slots:					// Slots maison

	void Connexionbdd();
	void Validation2();
	void NbVoie();

private:

	int NbVoies;
	int Order;
	int Description;
	int Voies;

	QLabel *L_Order;
	QLabel *L_Description;

	QString NOrder;
	QString Name;
	QString Order0;
	QString Description0;

	std::vector<QLineEdit*>a;
	std::vector<QLineEdit*>b;

	MYSQL *mySQL;
	MYSQL_ROW row2 = NULL;
	MYSQL_RES *result2 = NULL;

	QPushButton *valider;

};
