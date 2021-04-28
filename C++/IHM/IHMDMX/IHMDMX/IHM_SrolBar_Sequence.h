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

class IHM_SrolBar_Sequence :
	public QWidget
{
	Q_OBJECT                    // N�cessaire pour cr�er un slot maison

public:
	IHM_SrolBar_Sequence(int);                // Constructeur (forc�ment pubic)

public slots:               // Slots maison

private:

	
	std::vector<QSlider*>e;
	std::vector< QLCDNumber*>a;
};

