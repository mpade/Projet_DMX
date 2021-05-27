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

class IHM_Update_Sequence :
	public QWidget
{
	Q_OBJECT
public:
	IHM_Update_Sequence();                // Constructeur (forc�ment pubic)
	void getAllSequence();
	void getequipement(std::string);
public slots:               // Slots maison
	
	void getSelectidSequence();
	void getDeletequipementsequence();
	//void getUpdatesequence();

private:

	QPushButton *supequipment;
	QPushButton *modifier;
	QLabel * nameSequence;
	QGroupBox *groupBox;							// pointeur --> il faudra le construire dynamiquement (new)
	MYSQL *mysql;
	MYSQL_ROW row = NULL;
	MYSQL_RES *res = NULL;
	QListWidget *listSequence;
	QListWidget * listSequencequipement;
	QGridLayout *grid;
	int id_sequence = 0;
};
