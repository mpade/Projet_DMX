#pragma once
#include <QtWidgets>
#include "main.h"
#include <QWidget>
#include <QObject>
#include <QPushButton>
#include <QMessageBox>
#include "mysql_bdd.h"
#include <QLineEdit>
#include <QLabel>
#include <Qcheckbox>
#include <QGroupBox>
#include <QVBoxLayout>
#include <vector>
#include <string>
#include <QtWidgets/QApplication>
#include <QSlider>
#include "Client.h"
class IHM_Update_Sequence :
	public QWidget
{
	Q_OBJECT
public:
	IHM_Update_Sequence();                // Constructeur (forcément pubic)
	void getAllSequence();
	void getequipement(std::string);
public slots:               // Slots maison
	
	void getSelectidSequence();
	void getDeletequipementsequence();
	void getTCPtest();

private:

	QPushButton *supequipment;
	QPushButton *modifier;
	QPushButton *jouer;
	QLabel * nameSequence;
	QGroupBox *groupBox;							// pointeur --> il faudra le construire dynamiquement (new)
	mysql_bdd * bdd;
	QLabel *m_sequence;
	QListWidget *listSequence;
	QListWidget * listSequencequipement;
	QGridLayout *grid;
	Client *tcp;
	int id_sequence = 0;
};

