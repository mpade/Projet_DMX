#pragma once
#include <QWidget>
#include <QListWidget> 
#include <vector>
#include <QVBoxLayout>
#include <QPushButton>
#include <QMessageBox>
#include "mysql_bdd.h"
#include <QLineEdit>
#include "Client.h"
#include <qlabel.h>
class IHM_Create_Scene :
	public QWidget
{
	Q_OBJECT                    // Nécessaire pour créer un slot maison

public:
	IHM_Create_Scene();                // Constructeur (forcément pubic)

public slots:               // Slots maison
	void getAllSequencelist();
	void gettest();
	void test();
	void getTCPtest();
private:
	mysql_bdd * bdd;
	QLineEdit *scene_name;
	QListWidget *listWidgetSequence;
	QListWidget *listWidgetSequenceScene;
	QLineEdit *name;
	QLabel *m_sequence;
	QLabel * m_scenesequence;
	std::vector<QListWidgetItem*>e;
	std::vector<QListWidgetItem*>a;
	QGridLayout *grid;
	QPushButton *creer_scene;
	QPushButton *jouer;
	
	Client *tcp;
	std::vector <std::string>trame;
};

