#include "IHM_Create_Scene.h"

IHM_Create_Scene::IHM_Create_Scene() {

	
	tcp = new Client();
	bdd = new mysql_bdd();
	if (bdd->connectmysql() == 0){
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
		m_sequence = new QLabel;
		m_scenesequence = new QLabel;
		m_sequence->setText("sequence");
		m_scenesequence->setText("Sequence scene");
		grid->addWidget(m_sequence, 0, 0);
		grid->addWidget(m_scenesequence, 0, 1);
		grid->addWidget(listWidgetSequence, 1, 0);
		grid->addWidget(listWidgetSequenceScene, 1, 1);
		creer_scene = new QPushButton("Creer", this);
		jouer = new QPushButton("jouer", this);
		name = new QLineEdit;
		name->setPlaceholderText("entre un nom");
		grid->addWidget(name, 2, 0,1,3);
		grid->addWidget(creer_scene, 3, 0);
		grid->addWidget(jouer, 3, 1);
		//listWidgetSequence->setEditTriggers(QAbstractItemView::DoubleClicked);
		QObject::connect(listWidgetSequence, SIGNAL(itemDoubleClicked(QListWidgetItem *)), this, SLOT(gettest()));
		QObject::connect(listWidgetSequenceScene, SIGNAL(itemDoubleClicked(QListWidgetItem *)), this, SLOT(gettest()));
		QObject::connect(creer_scene, SIGNAL(clicked()), this, SLOT(test()));
		QObject::connect(jouer, SIGNAL(clicked()), this, SLOT(getTCPtest()));
		setLayout(grid);
	}
	
}
void IHM_Create_Scene::test() 
{

	 
	if (name->displayText() != ""){
		//requete insert name scene
		std::string requet = "INSERT INTO `scene`(`Id_Scene`, `Nom`) VALUES (NULL,'"+name->text().toStdString()+"')";
		mysql_query(bdd->getmysql(), requet.c_str());
		requet = "SELECT `Id_Scene` FROM `scene` WHERE `Nom` ='" + name->text().toStdString() + "'";
		mysql_query(bdd->getmysql(), requet.c_str());
		MYSQL_RES *result = NULL;
		MYSQL_ROW row;

		result = mysql_store_result(bdd->getmysql());

		row = mysql_fetch_row(result);
		int id_scene = atoi(row[0]);
			
	int x = listWidgetSequenceScene->count();
	int y = 1;
	for (int i = 0; i < x; i++) 
	{
		
		QListWidgetItem *item = listWidgetSequenceScene->takeItem(0);
		//SELECT `Id_Sequence` FROM `sequence` WHERE `name` = 

		requet = "SELECT `Id_Sequence` FROM `sequence` WHERE `name` = '"+item->text().toStdString()+"'";
		mysql_query(bdd->getmysql(), requet.c_str());
		MYSQL_RES *result = NULL;
		MYSQL_ROW row;

		result = mysql_store_result(bdd->getmysql());

		row = mysql_fetch_row(result);
		int id_sequence = atoi(row[0]);
		//INSERT INTO `sequencescene`(`Id_SequenceScene`, `Id_Sequence`, `Id_Scene`, `Order`) VALUES (NULL,'[value-2]','[value-3]','[value-4]')
		requet = "INSERT INTO `sequencescene`(`Id_SequenceScene`, `Id_Sequence`, `Id_Scene`, `Order`) VALUES (NULL,"+std::to_string(id_sequence)+","+ std::to_string(id_scene) +","+std::to_string(y)+")";
		mysql_query(bdd->getmysql(), requet.c_str());
		y++;
	}
	}

}
void IHM_Create_Scene::getTCPtest()
{
	trame.clear();std::string sendtrame;
	int x = listWidgetSequenceScene->count();
	if (tcp->connectToHost("192.168.65.67"))
		{

			tcp->writeData("t");
			tcp->closeToHost();
		}
	for (int i = 0; i < x; i++)
	{
		listWidgetSequenceScene->setCurrentRow(i);
		QListWidgetItem *item = listWidgetSequenceScene->currentItem();
		std::string name = item->text().toStdString();
		
		
		 trame = bdd->getValueSequence(name);
		for (int i = 0; i < trame.size(); i++)
		{
			sendtrame += trame[i];
		}
	}
	
		

		QString tradata = sendtrame.c_str();
		if (tcp->connectToHost("192.168.65.67"))
		{
			tcp->writeData(tradata.toUtf8());
			tcp->closeToHost();
		}

}
void IHM_Create_Scene::gettest() 
{
	int i = 0;
		if (listWidgetSequence->selectedItems().count() == 1) {
			i = listWidgetSequence->currentRow();
			QListWidgetItem *item= listWidgetSequence->takeItem(i);
			std::string name = item->text().toStdString();
			listWidgetSequenceScene->addItem(item);
			
			listWidgetSequence->clearSelection();
			
		}
		if (listWidgetSequenceScene->selectedItems().count() == 1) {
			QListWidgetItem *item = listWidgetSequenceScene->takeItem(listWidgetSequenceScene->currentRow());
			
			listWidgetSequence->addItem(item);
			
			listWidgetSequenceScene->clearSelection();
		}

}
void IHM_Create_Scene::getAllSequencelist() 
{

	std::string requet = "SELECT `name` FROM `sequence` WHERE 1";
	mysql_query(bdd->getmysql(), requet.c_str());
	int x = 0;
	MYSQL_RES *result = NULL;
	MYSQL_ROW row;

	result = mysql_store_result(bdd->getmysql());

	while ((row = mysql_fetch_row(result)))
	{
		e.push_back(new QListWidgetItem);
		e[x]->setText(row[0]);
		e[x]->setSelected(false);
		listWidgetSequence->insertItem(x, e[x]);
		x++;
	}

}