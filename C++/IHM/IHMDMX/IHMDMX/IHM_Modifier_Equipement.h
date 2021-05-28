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


class IHM_Modifier_Equipement : public QWidget
{
	Q_OBJECT                    // Nécessaire pour créer un slot maison

public:
	IHM_Modifier_Equipement();

public slots:					// Slots maison

	void Connexionbdd();
	void Modif_Validation();
	void Placeholder();
	void getAllEquipement();
	void Refresh();


private:

	QLineEdit *LE_Modif_Name;
	QLineEdit *LE_Modif_Voies;
	QLineEdit *LE_Modif_AdressEquipement;

	QLabel *L_Name;
	QLabel *L_Voies;
	QLabel *L_AdressEquipement;
	QLabel *m_LConnexionBdd;

	QString Name;
	QString Voies;
	QString AdressEquipement;
	QString Old_Name;
	QString Old_Voies;
	QString Old_AdressEquipement;
	std::string id_AdressEquipement;

	QPushButton *B_Modif_Valider;
	QPushButton *refresh;

	QListWidget *ListAfficherEquipement;

	std::vector<QListWidgetItem*>e;

	QGridLayout *grid2;

	MYSQL *mySQL;

	MYSQL_ROW row = NULL;
	MYSQL_ROW rows = NULL;
	MYSQL_ROW row1 = NULL;
	MYSQL_ROW row2 = NULL;
	MYSQL_RES *result = NULL;
	MYSQL_RES *results = NULL;
	MYSQL_RES *result1 = NULL;
	MYSQL_RES *result2 = NULL;

};