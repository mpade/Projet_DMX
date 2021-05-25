#include "IHM_Update_scene.h"

IHM_Update_scene::IHM_Update_scene() 
{

	mysql = mysql_init(NULL);

	if (!mysql_real_connect(mysql, "192.168.64.102", "DMX", "dmx", "Projet_DMX", 0, NULL, 0))
	{
		QMessageBox msgBox;
		msgBox.setText("Eror de connection a la BDD");
		msgBox.exec();
	}
	else
	{
		grid = new QGridLayout;
		listScene = new QListWidget();
		listSceneSequence = new QListWidget();
		nameScene = new QLabel();
		supSequence = new QPushButton();
		supSequence->setText("Supprimer");
		modifier = new QPushButton();
		modifier->setText("Ereghistre");
		grid->addWidget(nameScene,0,0,1,3);
		grid->addWidget(listScene,1,0);
		grid->addWidget(listSceneSequence, 1, 1);
		grid->addWidget(supSequence, 2,1);
		grid->addWidget(modifier, 2,0);
		setLayout(grid);
	}

}