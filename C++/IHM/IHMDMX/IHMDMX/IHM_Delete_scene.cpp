#include "IHM_Delete_scene.h"
IHM_Delete_scene::IHM_Delete_scene() {
	
	mysql = mysql_init(NULL);

	if (!mysql_real_connect(mysql, "127.0.0.1", "root", "", "Projet_DMX", 0, NULL, 0))
	{
		QMessageBox msgBox;
		msgBox.setText("Eror de connection a la BDD");
		msgBox.exec();
	}
	else
	{
		grid = new QGridLayout;
		listScene = new QListWidget();
		getAllScene();
		supprimer = new QPushButton("Supprimer", this);
		grid->addWidget(listScene, 0, 0);
		grid->addWidget(supprimer, 1, 0);
		QObject::connect(supprimer, SIGNAL(clicked()), this, SLOT(getDeleteScene()));
		setLayout(grid);
	}
}
void IHM_Delete_scene::getAllScene()
{
	std::string requet = "SELECT `Nom` FROM `scene` WHERE 1";
	mysql_query(mysql, requet.c_str());
	
	MYSQL_RES *result = NULL;
	MYSQL_ROW row;

	result = mysql_store_result(mysql);

	while ((row = mysql_fetch_row(result)))
	{
		QListWidgetItem *item = new QListWidgetItem();
		item->setText(row[0]);
		listScene->addItem(item);
		
	}

}
void IHM_Delete_scene::getDeleteScene()
{

	if (listScene->selectedItems().count() == 1) {
		QListWidgetItem *item = listScene->takeItem(listScene->currentRow());
		//requete delete vu ecrie

	}

}