#include "IHM_Delete_scene.h"
IHM_Delete_scene::IHM_Delete_scene() {
	
	
	bdd = new mysql_bdd();
	if (bdd->connectmysql() == 0)
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
	std::vector<std::string> Scene = bdd->getAllScene();

	for(int i = 0; i < Scene.size(); i++){
		QListWidgetItem *item = new QListWidgetItem();
		item->setText(Scene[i].c_str());
		listScene->addItem(item);
	}

}
void IHM_Delete_scene::getDeleteScene()
{

	if (listScene->selectedItems().count() == 1) {
		QListWidgetItem *item = listScene->takeItem(listScene->currentRow());
		//requete delete vu ecrie
		
		std::string names = item->text().toStdString();
		if (bdd->deleteScene(names) == 0)
		{
			QMessageBox msgBox;
			msgBox.setText("Probleme au niveau du delete");
			msgBox.exec();
		}

	}

}