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
	void creat_equipement();
	void modifier_equipement();
	void supprimer_equipement();
	void getAllEquipement();
	void Refresh();

private:

	QPushButton *equipement_creat;
	QPushButton *equipement_modifier;
	QPushButton *equipement_delete;
	QPushButton *refresh;

	QLabel *m_LConnexionBdd;
	QLabel *m_SAfficherEquipement;

	QListWidget *ListAfficherEquipement;
	QListWidget *listWidgetSequenceScene;

	QGridLayout *grid1;

	MYSQL *mySQL;
	MYSQL_ROW row = NULL;
	MYSQL_ROW rows = NULL;
	MYSQL_RES *result = NULL;
	MYSQL_RES *results = NULL;

	std::vector<QListWidgetItem*>e;
	
};

#endif // MYWINDOW_H