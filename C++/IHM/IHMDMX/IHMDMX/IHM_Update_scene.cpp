#include "IHM_Update_scene.h"

IHM_Update_scene::IHM_Update_scene() 
{
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
		listSceneSequence = new QListWidget();
		nameScene = new QLabel();
		scene = new QLabel("Scene");
		supSequence = new QPushButton();
		supSequence->setText("Supprimer");
		modifier = new QPushButton();
		jouer = new QPushButton();
		modifier->setText("Enregistre");
		jouer->setText("jouer");
		getAllScene();
		grid->addWidget(nameScene,0,1);
		grid->addWidget(scene,0,0);
		grid->addWidget(listScene,1,0);
		grid->addWidget(listSceneSequence, 1, 1);
		grid->addWidget(supSequence, 2,1);
		grid->addWidget(modifier, 2,0);
		grid->addWidget(jouer, 3,0,1,3);
		setLayout(grid);
		
		QObject::connect(listScene, SIGNAL(itemDoubleClicked(QListWidgetItem *)), this, SLOT(getSelectidScene()));
		QObject::connect(supSequence, SIGNAL(clicked()), this, SLOT(getDeletesequencescene()));
		QObject::connect(modifier, SIGNAL(clicked()), this, SLOT(getUpdatescene()));
		QObject::connect(jouer, SIGNAL(clicked()), this, SLOT(getTCPtest()));
		listSceneSequence->setSelectionMode(QAbstractItemView::SingleSelection);
		listSceneSequence->setDragEnabled(true);
		listSceneSequence->setAcceptDrops(true);
		listSceneSequence->setDropIndicatorShown(true);
		listSceneSequence->setDragDropMode(QAbstractItemView::InternalMove);
	}

}
void IHM_Update_scene::getAllScene() 
{

	std::vector<std::string> scene = bdd->getAllScene();
	for (int i = 0; i < scene.size(); i++) {
		QListWidgetItem *item = new QListWidgetItem();
		item->setText(scene[i].c_str());
		listScene->addItem(item);
	}
	

}
void IHM_Update_scene::getSelectidScene()
{

	if (listScene->selectedItems().count() == 1) {
		QListWidgetItem *item = listScene->currentItem();
		nameScene->setText("Scnene : " +item->text());
		listScene->clearSelection();
		getSequence(item->text().toStdString());
	}

}
void IHM_Update_scene::getSequence(std::string name) 
{

	listSceneSequence->clear();

	std::vector < std::string> sequence = bdd->getSequenceForScene(name);

	for (int i = 0; i < sequence.size(); i++) 
	{
		QListWidgetItem *item = new QListWidgetItem();
		item->setText(sequence[i].c_str());
		listSceneSequence->addItem(item);
	}
}
void IHM_Update_scene::getDeletesequencescene() 
{

	if (listSceneSequence->selectedItems().count() == 1)
	{

		QListWidgetItem *item = listSceneSequence->takeItem(listSceneSequence->currentRow());
		
	}

}
void IHM_Update_scene::getUpdatescene() 
{
	std::string name = nameScene->text().toStdString();
	if (bdd->deletesupdatescene(name) == 1) {



		int x = listSceneSequence->count(), y = 0;
		for (int i = 0; i < x; i++) {
			QListWidgetItem *item = listSceneSequence->takeItem(0);
			std::string name = item->text().toStdString();
			bdd->getUpdateScene(name, y);
			y++;

		}
	}

}

void IHM_Update_scene::getTCPtest()
{
	std::vector<std::string>trame;
	std::string sendtrame;
	int x = listSceneSequence->count();
	if (tcp->connectToHost("192.168.1.101"))
	{

		tcp->writeData("t");
		tcp->closeToHost();
	}

	if (nameScene->text() != "") {
		for (int i = 0; i < x; i++)
		{
			listSceneSequence->setCurrentRow(i);
			QListWidgetItem *item = listSceneSequence->currentItem();
			std::string name = item->text().toStdString();


			trame = bdd->getValueSequence(name);
			for (int i = 0; i < trame.size(); i++)
			{
				sendtrame += trame[i];
			}
		}
	}

	QString tradata = sendtrame.c_str();
	if (tcp->connectToHost("192.168.1.101"))
	{
		tcp->writeData(tradata.toUtf8());
		tcp->closeToHost();
	}
}
