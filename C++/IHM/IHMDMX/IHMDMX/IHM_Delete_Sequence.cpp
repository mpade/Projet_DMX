#include "IHM_Delete_Sequence.h"
#include "synchapi.h"
IHM_Delete_Sequence::IHM_Delete_Sequence() : QWidget()																								// spécification du constructeur
{
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
		getAllSequence();
		supprimer = new QPushButton("Supprimer", this);
		grid->addWidget(listSequence, 0, 0);
		grid->addWidget(supprimer, 1, 0);
		QObject::connect(supprimer, SIGNAL(clicked()), this, SLOT(getDeleteSequence()));
		QObject::connect(listSequence, SIGNAL(itemClicked(QListWidgetItem *)), this, SLOT(gettcptest()));
		
		setLayout(grid);
	}
}
void IHM_Delete_Sequence::getAllSequence() {

	std::vector<std::string> s = bdd->getAllSequence();
	for (int i = 0; i < s.size(); i++) {
		QListWidgetItem *item = new QListWidgetItem();
		item->setText(s[i].c_str());
		listSequence->addItem(item);
	}
}

void IHM_Delete_Sequence::getDeleteSequence()
{

	if (listSequence->selectedItems().count() == 1) {
		QListWidgetItem *item = listSequence->takeItem(listSequence->currentRow());
		//requete delete vu ecrie
		std::string names = item->text().toStdString();
		if (bdd->deleteSequence(names) == 0) {
			QMessageBox msgBox;
			msgBox.setText("probleme lors du delete");
			msgBox.exec();
		}
	}
}

void IHM_Delete_Sequence::gettcptest()
{
	if (tcp->connectToHost("192.168.65.67"))
	{
		tcp->writeData("t");
		tcp->closeToHost();
	}

	if (listSequence->selectedItems().count() == 1) {
		QListWidgetItem *item = listSequence->currentItem();
		std::string names = item->text().toStdString();
		std::vector<std::string> trame = bdd->getValueSequence(names);
		std::string sendtrame;
		for (int i = 0; i < trame.size(); i++)
		{
			sendtrame += trame[i];
		}
		
		QString tradata = sendtrame.c_str();
		if (tcp->connectToHost("192.168.65.67"))
		{
			tcp->writeData(tradata.toUtf8());
			tcp->closeToHost();
		}

	}
}
