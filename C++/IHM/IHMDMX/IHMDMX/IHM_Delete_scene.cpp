#include "IHM_Delete_scene.h"
IHM_Delete_scene::IHM_Delete_scene() {
	
	tcp = new Client();
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
		m_scene = new QLabel("Scene");
		
		getAllScene();
		supprimer = new QPushButton("Supprimer", this);
		jouer = new QPushButton("jouer", this);
		grid->addWidget(m_scene, 0, 0);
		grid->addWidget(listScene, 1, 0);
		grid->addWidget(jouer, 2, 0);
		grid->addWidget(supprimer, 3, 0);
		QObject::connect(supprimer, SIGNAL(clicked()), this, SLOT(getDeleteScene()));
		QObject::connect(jouer, SIGNAL(clicked()), this, SLOT(gettcptest()));

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

void IHM_Delete_scene::gettcptest()
{

	if (tcp->connectToHost("192.168.1.101"))
	{
		tcp->writeData("t");
		tcp->closeToHost();
	}

	if (listScene->selectedItems().count() == 1) {
		QListWidgetItem *item = listScene->currentItem();
		std::string names = item->text().toStdString();
		std::vector<std::string> trame = bdd->getValueScene(names);
		std::string sendtrame;
		for (int i = 0; i < trame.size(); i++)
		{
			sendtrame += trame[i];
		}

		QString tradata = sendtrame.c_str();
		if (tcp->connectToHost("192.168.1.101"))
		{
			tcp->writeData(tradata.toUtf8());
			tcp->closeToHost();
		}

	}
}
