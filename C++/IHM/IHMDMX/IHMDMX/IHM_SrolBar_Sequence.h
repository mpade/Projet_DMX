#pragma once
#include <QtWidgets>
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
#include <QSlider>
#include "mysql.h"
#include "TCPclient.h"

class IHM_SrolBar_Sequence :
	public QWidget
{
	Q_OBJECT                    // Nécessaire pour créer un slot maison

public:
	IHM_SrolBar_Sequence(const QString, int,int,int);                // Constructeur (forcément pubic)

public slots:               // Slots maison
	void getValide();
private:
	int idsequence;
	int adress;
	MYSQL *mysql;
	MYSQL_ROW row = NULL;
	MYSQL_RES *res = NULL;
	std::vector<QSlider*>e;
	std::vector< QLCDNumber*>a;
	QPushButton *Valid;
};

