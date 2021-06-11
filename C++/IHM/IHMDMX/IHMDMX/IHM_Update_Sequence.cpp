#include "IHM_Update_Sequence.h"

IHM_Update_Sequence::IHM_Update_Sequence(){

	bdd = new mysql_bdd();
	tcp = new Client();
	if (bdd->connectmysql() == 0)
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
		m_sequence = new QLabel;
		nameSequence = new QLabel();
		supequipment = new QPushButton();
		jouer = new QPushButton();
		supequipment->setText("Supprimer");
		modifier = new QPushButton();
		modifier->setText("Quitter");
		jouer->setText("Jouer");
		getAllSequence();
		m_sequence->setText("Sequence ");
		grid->addWidget(m_sequence, 0, 0);
		grid->addWidget(nameSequence,0,1,1,3);
		grid->addWidget(listSequence,1,0);
		grid->addWidget(listSequencequipement, 1, 1);
		grid->addWidget(supequipment, 2,1);
		grid->addWidget(jouer, 2,0);
		grid->addWidget(modifier, 3, 0, 1, 3);
		setLayout(grid);
		QObject::connect(listSequence, SIGNAL(itemDoubleClicked(QListWidgetItem *)), this, SLOT(getSelectidSequence()));
		QObject::connect(supequipment, SIGNAL(clicked()), this, SLOT(getDeletequipementsequence()));
		QObject::connect(modifier, SIGNAL(clicked()), this, SLOT(close()));
		QObject::connect(jouer, SIGNAL(clicked()), this, SLOT(getTCPtest()));
	}
}
void IHM_Update_Sequence::getAllSequence() 
{

	std::vector<std::string> s = bdd->getAllSequence();
	for(int i = 0; i < s.size(); i++){
		QListWidgetItem *item = new QListWidgetItem();
		item->setText(s[i].c_str());
		listSequence->addItem(item);
	}

}

void IHM_Update_Sequence::getSelectidSequence()
{

	if (listSequence->selectedItems().count() == 1) {
		QListWidgetItem *item = listSequence->currentItem();
		nameSequence->setText("Equipement Sequence : "+item->text());
		listSequence->clearSelection();
		getequipement(item->text().toStdString());
	}

}

void IHM_Update_Sequence::getequipement(std::string name)
{

	listSequencequipement->clear();
	std::vector<std::string> EquipementSequence = bdd->getEquipementForSequence(name);
	for (int i = 0; i < EquipementSequence.size(); i++) {
		QListWidgetItem * item = new QListWidgetItem();
		item->setText(EquipementSequence[i].c_str());
		listSequencequipement->addItem(item);
	}
}
void IHM_Update_Sequence::getDeletequipementsequence() 
{

	if (listSequencequipement->selectedItems().count() == 1) 
	{
		
		QListWidgetItem * item = listSequencequipement->takeItem(listSequencequipement->currentRow());
		std::string names = item->text().toStdString();
		if (bdd->deleteEquipementforsequence(names) == 0) {
			QMessageBox msgBox;
			msgBox.setText("probleme lors du delete");
			msgBox.exec();
		}
	}

}

void IHM_Update_Sequence::getTCPtest()
{

	std::vector<std::string>trame;
	std::string sendtrame;
	
	if (tcp->connectToHost("192.168.1.101"))
	{

		tcp->writeData("t");
		tcp->closeToHost();
	}
	
	if(nameSequence->text() != ""){
		std::string s = nameSequence->text().toStdString();
		int pos = s.find(": ");
		std::string name = s.substr(pos + 2);


		trame = bdd->getValueSequence(name);
		for (int i = 0; i < trame.size(); i++)
		{
			sendtrame += trame[i];
		}
	}

	QString tradata = sendtrame.c_str();
	if (tcp->connectToHost("192.168.1.101"))
	{
		tcp->writeData(tradata.toUtf8());
		tcp->closeToHost();
	}


}
