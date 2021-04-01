#pragma once
#include <QWidget>
#include <QObject>
#include <QPushButton>
#include <QMessageBox>
#include "mysql.h"


class IHMDMX2 : public QWidget // On hérite de QWidget (IMPORTANT)
{
	Q_OBJECT                    // Nécessaire pour créer un slot maison

public:
	IHMDMX2();                // Constructeur (forcément pubic)

public slots:               // Slots maison

	void ConnexionBdd();

private:
	QPushButton *m_bouton;      // Attribut (forcément privé)
								// pointeur --> il faudra le construire dynamiquement (new)
	QLabel *m_label;
	MYSQL *mysql;
	MYSQL_ROW row = NULL;
	MYSQL_RES *res = NULL;

};
