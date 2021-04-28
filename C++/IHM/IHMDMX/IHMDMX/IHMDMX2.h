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

class IHMDMX2 : public QWidget // On hérite de QWidget (IMPORTANT)
{
	Q_OBJECT                    // Nécessaire pour créer un slot maison

public:
	IHMDMX2();                // Constructeur (forcément pubic)

public slots:               // Slots maison
	void creat_sequence();
private:
	QPushButton *sequence_creat;      // Attribut (forcément privé)

}; 
