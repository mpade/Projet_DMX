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
class IHM_Delete_Sequence : public QWidget
{
	Q_OBJECT                    // Nécessaire pour créer un slot maison

public:
	IHM_Delete_Sequence();                // Constructeur (forcément pubic)

public slots:               // Slots maison
	void getAllSequence();
	void getDeleteSequence();
	void gettcptest();
private:

	QPushButton *supprimer;
	QGroupBox *groupBox;							// pointeur --> il faudra le construire dynamiquement (new)
	mysql_bdd * bdd;
	QListWidget *listSequence;
	QVBoxLayout *vbox;
	QGridLayout *grid;
	Client *tcp;
};

