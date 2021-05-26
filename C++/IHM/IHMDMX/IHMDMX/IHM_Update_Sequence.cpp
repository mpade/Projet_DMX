#include "IHM_Update_Sequence.h"

IHM_Update_Sequence::IHM_Update_Sequence(){

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
		listSequence = new QListWidget();
		listSequencequipement = new QListWidget();
		nameSequence = new QLabel();
		supequipment = new QPushButton();
		supequipment->setText("Supprimer");
		modifier = new QPushButton();
		modifier->setText("Ereghistre");
		getAllSequence();
		grid->addWidget(nameSequence,0,1,1,3);
		grid->addWidget(listSequence,1,0);
		grid->addWidget(listSequencequipement, 1, 1);
		grid->addWidget(supequipment, 2,1);
		grid->addWidget(modifier, 2,0);
		setLayout(grid);
		//QObject::connect(listSequence, SIGNAL(itemDoubleClicked(QListWidgetItem *)), this, SLOT(getSelectidSequence()));
	}
}
void IHM_Update_Sequence::getAllSequence() 
{

	mysql_query(mysql, "SELECT `name` FROM `sequence` WHERE 1");

	MYSQL_RES *result = NULL;
	MYSQL_ROW row;

	result = mysql_store_result(mysql);

	while ((row = mysql_fetch_row(result)))
	{
		QListWidgetItem *item = new QListWidgetItem();
		item->setText(row[0]);
		listSequence->addItem(item);

	}

}