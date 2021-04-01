#pragma once
#include <QWidget>
#include <QObject>
#include <QPushButton>
#include <QMessageBox>
#include "mysql.h"


class IHMDMX2 : public QWidget // On h�rite de QWidget (IMPORTANT)
{
	Q_OBJECT                    // N�cessaire pour cr�er un slot maison

public:
	IHMDMX2();                // Constructeur (forc�ment pubic)

public slots:               // Slots maison

	void ConnexionBdd();

private:
	QPushButton *m_bouton;      // Attribut (forc�ment priv�)
								// pointeur --> il faudra le construire dynamiquement (new)
	QLabel *m_label;
	MYSQL *mysql;
	MYSQL_ROW row = NULL;
	MYSQL_RES *res = NULL;

};
