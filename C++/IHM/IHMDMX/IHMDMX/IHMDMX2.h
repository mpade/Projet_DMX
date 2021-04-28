#pragma once
#include "main.h"
#include <QWidget>
#include <QObject>
#include <QPushButton>
#include <QMessageBox>
#include "mysql.h"
#include <QLabel>
#include <Qcheckbox>
#include <QGroupBox>
#include <QVBoxLayout>
#include <vector>
#include <string>
#include <QtWidgets/QApplication>
#include "IHM_create_Sequence.h"

class IHMDMX2 : public QWidget // On h�rite de QWidget (IMPORTANT)
{
	Q_OBJECT                    // N�cessaire pour cr�er un slot maison

public:
	IHMDMX2();                // Constructeur (forc�ment pubic)

public slots:               // Slots maison
	void creat_sequence();
private:
	QPushButton *sequence_creat;      // Attribut (forc�ment priv�)

}; 
