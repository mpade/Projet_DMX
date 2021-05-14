#include "IHM_Create_Scene.h"
IHM_Create_Scene::IHM_Create_Scene() {

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
		listWidgetSequence = new QListWidget();
		listWidgetSequenceScene = new QListWidget();
		getAllSequencelist();
		grid->addWidget(listWidgetSequence, 1, 1);
		grid->addWidget(listWidgetSequenceScene, 1, 2);
		creer_scene = new QPushButton("Creer", this);
		grid->addWidget(creer_scene, 2, 2);
		//listWidgetSequence->setEditTriggers(QAbstractItemView::DoubleClicked);
		QObject::connect(listWidgetSequence, SIGNAL(itemDoubleClicked(QListWidgetItem *)), this, SLOT(gettest()));
		QObject::connect(listWidgetSequenceScene, SIGNAL(itemDoubleClicked(QListWidgetItem *)), this, SLOT(gettest()));
		setLayout(grid);
	}
}
void IHM_Create_Scene::gettest() 
{
	int i = 0;
		if (listWidgetSequence->selectedItems().count() == 1) {
			i = listWidgetSequence->currentRow();
			QListWidgetItem *item= listWidgetSequence->takeItem(i);
			listWidgetSequenceScene->addItem(item);
			
			for (int x = 0; x < e.size(); x++)
				e[x]->setSelected(false);
			
		}
		if (listWidgetSequenceScene->selectedItems().count() == 1) {
			QListWidgetItem *item = listWidgetSequenceScene->takeItem(listWidgetSequenceScene->currentRow());
			listWidgetSequence->addItem(item);
		}

}
void IHM_Create_Scene::getAllSequencelist() 
{

	std::string requet = "SELECT `name` FROM `sequence` WHERE 1";
	mysql_query(mysql, requet.c_str());
	int x = 0;
	MYSQL_RES *result = NULL;
	MYSQL_ROW row;

	result = mysql_store_result(mysql);

	while ((row = mysql_fetch_row(result)))
	{
		e.push_back(new QListWidgetItem);
		e[x]->setText(row[0]);
		e[x]->setSelected(false);
		listWidgetSequence->insertItem(x, e[x]);
		x++;
	}

}