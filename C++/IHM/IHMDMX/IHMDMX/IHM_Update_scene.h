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
class IHM_Update_scene :
	public QWidget
{
	Q_OBJECT
public:
	IHM_Update_scene();                // Constructeur (forcément pubic)

public slots:               // Slots maison
	//void getAllScene();
	//void getDeleteScene();
private:

	QPushButton *supprimer;
	QGroupBox *groupBox;							// pointeur --> il faudra le construire dynamiquement (new)
	MYSQL *mysql;
	MYSQL_ROW row = NULL;
	MYSQL_RES *res = NULL;
	std::vector<QCheckBox*>e;
	QVBoxLayout *vbox;
	QGridLayout *grid;
};

