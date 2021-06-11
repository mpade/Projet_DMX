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

class IHM_Update_scene :
	public QWidget
{
	Q_OBJECT
public:
	IHM_Update_scene();                // Constructeur (forcément pubic)
    void getAllScene();
	void getSequence(std::string);
public slots:               // Slots maison
	void getSelectidScene();
	void getDeletesequencescene();
	void getUpdatescene();
	void getTCPtest();
private:
	Client * tcp;
	QPushButton *supSequence;
	QPushButton *modifier;
	QPushButton *jouer;
	QGroupBox *groupBox;							// pointeur --> il faudra le construire dynamiquement (new)
	mysql_bdd *bdd;
	QListWidget *listScene;
	QListWidget * listSceneSequence;	
	QLabel * nameScene;
	QLabel * scene;
	QGridLayout *grid;
};


