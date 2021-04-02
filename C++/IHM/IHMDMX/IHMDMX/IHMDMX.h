#ifndef MYWINDOW_H
#define MYWINDOW_H

#include <stdio.h>
#include <stdlib.h>
#include <QWidget>
#include <QObject>
#include <QPushButton>
#include <QMessageBox>
#include <QScrollBar>
#include <mysql.h>
#include <QtGui>



class IHMDMX : public QWidget   // On h�rite de QWidget (IMPORTANT)
{
	Q_OBJECT                    // N�cessaire pour cr�er un slot maison

public:
	IHMDMX();					// Constructeur (forc�ment pubic)

public slots:					// Slots maison
	void ConnexionBdd();
	void AfficherEquipement();

private:
	//QPushButton *m_BConnexionBdd;
	QLabel *m_LConnexionBdd;
	QLabel *m_SAfficherEquipement;
	MYSQL *mySQL;
	MYSQL_ROW row = NULL;
	MYSQL_RES *result = NULL;
	QString MaRequete;
	
};

#endif // MYWINDOW_H