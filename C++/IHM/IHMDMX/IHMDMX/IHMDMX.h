#ifndef MYWINDOW_H
#define MYWINDOW_H

#include <QWidget>
#include <QObject>
#include <QPushButton>
#include <QMessageBox>
#include "BDD.h"
#include "mysql.h"


class IHMDMX : public QWidget // On hérite de QWidget (IMPORTANT)
{
	Q_OBJECT                    // Nécessaire pour créer un slot maison

public:
	IHMDMX();                // Constructeur (forcément pubic)

public slots:               // Slots maison

	void ConnexionBdd();

private:
	QPushButton *m_bouton;      // Attribut (forcément privé)
								// pointeur --> il faudra le construire dynamiquement (new)
	MYSQL *mysql;
	MYSQL_ROW row = NULL;
	MYSQL_RES *res = NULL;

};

#endif // MYWINDOW_H