#ifndef MYWINDOW_H
#define MYWINDOW_H

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
#include "IHM_Create_Equipement.h"
#include "IHM_Modifier_Equipement.h"



class IHMDMX : public QWidget   // On hérite de QWidget (IMPORTANT)
{
	Q_OBJECT                    // Nécessaire pour créer un slot maison

public:
	IHMDMX();					// Constructeur (forcément pubic)

public slots:					// Slots maison
	void ConnexionBdd();
	//void AfficherEquipement();
	void creat_equipement();
	void modifier_equipement();
	void supprimer_equipement();

private:
	//QPushButton *m_BConnexionBdd;
	QPushButton *equipement_creat;
	QPushButton *equipement_modifier;
	QPushButton *equipement_delete;
	QLabel *m_LConnexionBdd;
	QLabel *m_SAfficherEquipement;
	MYSQL *mySQL;
	MYSQL_ROW row = NULL;
	MYSQL_RES *result = NULL;
	QString MaRequete;
	
};

#endif // MYWINDOW_H