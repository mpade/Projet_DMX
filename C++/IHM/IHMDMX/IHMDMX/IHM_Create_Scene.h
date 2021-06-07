#pragma once
#include <QWidget>
#include <QListWidget> 
#include <vector>
#include <QVBoxLayout>
#include <QPushButton>
#include <QMessageBox>
#include "mysql.h"
#include <QLineEdit>
#include "Client.h"
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
private:
	QLineEdit *scene_name;
	QListWidget *listWidgetSequence;
	QListWidget *listWidgetSequenceScene;
	QLineEdit *name;
	std::vector<QListWidgetItem*>e;
	std::vector<QListWidgetItem*>a;
	QGridLayout *grid;
	QPushButton *creer_scene;
	MYSQL *mysql;
	MYSQL_ROW row = NULL;
	MYSQL_RES *res = NULL;
	Client *tcps;
	std::vector <std::string>trame;
};

