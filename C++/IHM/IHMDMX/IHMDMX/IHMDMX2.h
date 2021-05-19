#pragma once
#include "main.h"
#include <QWidget>
#include <QObject>
#include <QPushButton>
#include <QMessageBox>
#include "mysql.h"
#include <QLabel>
#include <Qcheckbox>
#include <QGroupBox>
#include <QVBoxLayout>
#include <vector>
#include <string>
#include <QtWidgets/QApplication>
#include "IHM_create_Sequence.h"
#include "IHM_Delete_Sequence.h"
#include "IHM_Create_Scene.h"

class IHMDMX2 : public QWidget // On h�rite de QWidget (IMPORTANT)
{
	Q_OBJECT                    // N�cessaire pour cr�er un slot maison

public:
	IHMDMX2();                // Constructeur (forc�ment pubic)

public slots:               // Slots maison
	void creat_sequence();
	void modifier_sequence();
	void supprimer_sequence();
	void creat_scene();
	void modifier_scene();
	void supprimer_scene();
private:
	QPushButton *sequence_creat;      // Attribut (forc�ment priv�)
	QPushButton *sequence_modifier;
	QPushButton *sequence_delete;
	QPushButton *scene_creat;
	QPushButton *scene_modifier;
	QPushButton *scene_delete;
}; 
