#pragma once
#include "main.h"
#include "IHM_SrolBar_Sequence.h"
#include <QtWidgets>
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
#include <QSlider>
#include <qtcpsocket.h>
#include "IHM_Create_Property.h"



class IHM_Test_En_Directe : public QWidget
{
	Q_OBJECT                    // Nécessaire pour créer un slot maison

public:
	IHM_Test_En_Directe(int, int, int);


public slots:					// Slots maison

	void ConnexionBdd();
	void TestDirecte();
	void getTcpTest();


private:

	QPushButton *Valid;

	int NbVoies;
	int Adresse;
	QString Id_Eq;

	std::vector<QSlider*>e;
	std::vector< QLCDNumber*>a;
	std::vector <std::string> tramemou;

	MYSQL *mySQL;
	MYSQL_ROW row = NULL;
	MYSQL_RES *result = NULL;

	QTcpSocket *tcp;
};
