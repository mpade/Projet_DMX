#ifndef MYWINDOW_H
#define MYWINDOW_H

#include <stdio.h>
#include <stdlib.h>
#include <QWidget>
#include <QObject>
#include <QPushButton>
#include <QMessageBox>
#include "mysql.h"




class IHMDMX : public QWidget   // On hérite de QWidget (IMPORTANT)
{
	Q_OBJECT                    // Nécessaire pour créer un slot maison

public:
	IHMDMX();					// Constructeur (forcément pubic)

public slots:					// Slots maison
	void ConnexionBdd();

private:
	QPushButton *m_BConnexionBdd;
	QLabel *m_LConnexionBdd;
	MYSQL *mySQL;
	MYSQL_ROW row = NULL;
	MYSQL_RES *res = NULL;
	

};

#endif // MYWINDOW_H