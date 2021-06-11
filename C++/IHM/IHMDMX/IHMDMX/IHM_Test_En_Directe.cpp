#include "IHM_Test_En_Directe.h"
#include "IHMDMX.h"
#include "iostream"
#include <QLabel>
#include <string>
IHM_Test_En_Directe::IHM_Test_En_Directe(int voies, int adresse, int Id_Equipement) : QWidget()																				// spécification du constructeur
{
	NbVoies = voies;
	Adresse = adresse;
	Id_Eq = Id_Equipement;

	

	/* Position de la fenêtre */
	setGeometry(600, 100, 950, 200);


	/* Construction des Widgets */



	/* Position des Widgets */



	/* Connexions Signal - Slot */


	/* Méthode éxecutée au lancement de l'IHM */
	ConnexionBdd();
	TestDirecte();

}
//=================================== Connexion à la bdd ====================================================

void IHM_Test_En_Directe::ConnexionBdd() 
{
	mySQL = mysql_init(NULL);

	if (!mysql_real_connect(mySQL, "192.168.64.102", "DMX", "dmx", "Projet_DMX", 0, NULL, 0))
	{
		QMessageBox msgBox;
		msgBox.setText("Erreur de connection a la BDD");
		msgBox.exec();
	}
}

//==================== création des scrollbars en fonction du nombre de voie ==================================

void IHM_Test_En_Directe::TestDirecte()
{
	std::string requId_equipement = "SELECT * FROM `property` WHERE `Id_Equipement` ='" + std::to_string(Id_Eq) + "'";
	mysql_query(mySQL, requId_equipement.c_str());

	result = mysql_store_result(mySQL);

	std::vector<QString> names;

	while (row = mysql_fetch_row(result))
	{
		names.push_back(row[2]);
	}

	int x = 65, y = 20;

	for (int i = 0; i < NbVoies; i++) {
		e.push_back(new QSlider(Qt::Vertical, this));
		a.push_back(new QLCDNumber(this));
		b.push_back(new QLabel(names[i], this));
	}

	for (int i = 0; i < e.size(); i++) {
		e[i]->setObjectName(QString::number(Adresse));
		Adresse++;
	}

	for (int i = 0; i < e.size(); i++) {
		e[i]->setMaximum(255);
		e[i]->move(x, y);
		x += 100;
	}
	x = 40, y = 150;
	for (int i = 0; i < b.size(); i++) {
		b[i]->move(x, y);
		x += 100;
	}

	x = 40, y = 120;
	for (int i = 0; i < a.size(); i++) {
		a[i]->move(x, y);
		x += 100;
	}
	for (int i = 0; i < a.size(); i++) {
		QObject::connect(e[i], SIGNAL(valueChanged(int)), a[i], SLOT(display(int)));
		QObject::connect(e[i], SIGNAL(valueChanged(int)), this, SLOT(getTcpTest()));
	}
}

//==================================== Test en directe =====================================================

void IHM_Test_En_Directe::getTcpTest() {
	tcp = new QTcpSocket();
	std::vector<std::string> trame;
	for (int i = 0; i < e.size(); i++) {
		trame.push_back("CV:" + e[i]->objectName().toStdString() + "," + std::to_string(e[i]->value()));
	}
	if (tramemou.size() == 0) {
		for (int x = 0; x < trame.size(); x++) {
			tcp->connectToHost("192.168.65.67", 9012);
			tcp->write(trame[x].c_str());
			tcp->close();
			tramemou.push_back(trame[x]);
		}
	}
	for (int i = 0; i < tramemou.size(); i++) {

		if (tramemou[i] != trame[i]) {
			tcp->connectToHost("192.168.65.67", 9012);
			tcp->write(trame[i].c_str());
			tcp->close();
			tramemou[i] = trame[i];
		}

	}
}