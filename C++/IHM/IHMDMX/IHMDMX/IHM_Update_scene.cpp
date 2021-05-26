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
		getAllScene();
		grid->addWidget(nameScene,0,1,1,3);
		grid->addWidget(listScene,1,0);
		grid->addWidget(listSceneSequence, 1, 1);
		grid->addWidget(supSequence, 2,1);
		grid->addWidget(modifier, 2,0);
		setLayout(grid);
		listSceneSequence->setSelectionMode(QAbstractItemView::SingleSelection);
		listSceneSequence->setDragEnabled(true);
		listSceneSequence->setAcceptDrops(true);
		listSceneSequence->setDropIndicatorShown(true);
		listSceneSequence->setDragDropMode(QAbstractItemView::InternalMove);
		QObject::connect(listScene, SIGNAL(itemDoubleClicked(QListWidgetItem *)), this, SLOT(getSelectidScene()));
	}

}
void IHM_Update_scene::getAllScene() 
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
void IHM_Update_scene::getSelectidScene()
{

	if (listScene->selectedItems().count() == 1) {
		QListWidgetItem *item = listScene->currentItem();
		nameScene->setText(item->text());
		listScene->clearSelection();
		getSequence(item->text().toStdString());
	}

}
void IHM_Update_scene::getSequence(std::string name) 
{

	listSceneSequence->clear();

	std::string request = "SELECT `Id_Scene` FROM `scene` WHERE `Nom` ='" + name + "'";
	mysql_query(mysql, request.c_str());
	MYSQL_RES *result = NULL;
	MYSQL_ROW row;

	result = mysql_store_result(mysql);
	row = mysql_fetch_row(result);
	result = NULL;

	request = "SELECT `Id_Sequence`, `Order` FROM `sequencescene` WHERE `Id_Scene` = " + std::to_string(atoi(row[0]));
	mysql_query(mysql, request.c_str());
	result = mysql_store_result(mysql);
	while (row = mysql_fetch_row(result))
	{
		MYSQL_RES *results = NULL;
		MYSQL_ROW rows;
		request = "SELECT `Id_Sequence`, `Duree`, `name` FROM `sequence` WHERE `Id_Sequence` = '" + std::to_string(atoi(row[0])) +"'";
		mysql_query(mysql, request.c_str());
		results = mysql_store_result(mysql);
		rows = mysql_fetch_row(results);
		QListWidgetItem * item = new QListWidgetItem();
		item->setText(rows[2]);
		listSceneSequence->addItem(item);
	}

}