#include "IHM_SrolBar_Sequence.h"
IHM_SrolBar_Sequence::IHM_SrolBar_Sequence(const QString name,int voie, int adresse,int id_sequence) : QWidget()																								// spécification du constructeur
{
	idsequence = id_sequence;
	adress = adresse;
	tcp = new QTcpSocket();
	mysql = mysql_init(NULL);
	int adressmodifi = adresse;
	if (!mysql_real_connect(mysql, "192.168.64.102", "DMX", "dmx", "Projet_DMX", 0, NULL, 0))
	{
		QMessageBox msgBox;
		msgBox.setText("Eror de connection a la BDD");
		msgBox.exec();
	}
	else
	{
		int x = 65, y = 20;
		QWidget::setWindowTitle(name);

		for (int i = 0; i < voie; i++) {
			e.push_back(new QSlider(Qt::Vertical, this));
			a.push_back(new QLCDNumber(this));
		}

		for (int i = 0; i < e.size(); i++) {
			e[i]->setObjectName(QString::number(adressmodifi));
			adressmodifi++;
		}

		for (int i = 0; i < e.size(); i++) {
			e[i]->setMaximum(255);
			e[i]->move(x, y);
			x += 75;
		}
		x = 40, y = 120;
		for (int i = 0; i < a.size(); i++) {
			a[i]->move(x, y);
			x += 75;
		}
		for (int i = 0; i < a.size(); i++) {
			QObject::connect(e[i], SIGNAL(valueChanged(int)), a[i], SLOT(display(int)));
			QObject::connect(e[i], SIGNAL(valueChanged(int)), this, SLOT(getTcpTest()));
		}
		Valid = new QPushButton("Valider", this);
		Valid->move(x, 150);
		QObject::connect(Valid, SIGNAL(clicked()), this, SLOT(getValide()));
	}
}
void IHM_SrolBar_Sequence::getValide() {


	std::string requetes = "SELECT `Id_AdressEquipement`, adressequipement.Id_Equipement FROM `adressequipement`, equipement WHERE adressequipement.Id_Equipement = equipement.Id_Equipement and equipement.Name = '" + QWidget::windowTitle().toStdString() + "'";
	mysql_query(mysql, requetes.c_str());
	MYSQL_RES *results = NULL;
	MYSQL_ROW rows;
	results = mysql_store_result(mysql);
	while ((rows = mysql_fetch_row(results)))
	{
		std::string requetes = "INSERT INTO `sequenceusedequipement`(`Id_SequenceUsedEquipement`,`Id_AdressEquipement`, `Id_Sequence`) VALUES (NULL," + std::to_string(atoi(rows[0])) + "," + std::to_string(idsequence) + ")";
		mysql_query(mysql, requetes.c_str());
		std::string requetproper = "SELECT `Id_Property` FROM `property` WHERE `Id_Equipement` = " + std::to_string(atoi(rows[1]));
		mysql_query(mysql, requetproper.c_str());
		MYSQL_RES *resultss = NULL;
		MYSQL_ROW rowss;
		resultss = mysql_store_result(mysql);
		int i = 0;

		while (rowss = mysql_fetch_row(resultss)) {

			requetes = "INSERT INTO `valueproper`(`value`, `id_property`,`Id_Sequence`) VALUES ('" + std::to_string(a[i]->value()) + "','" + std::to_string(atoi(rowss[0])) + "','" + std::to_string(idsequence) + "')";
			mysql_query(mysql, requetes.c_str());
			i++;

		}
	}
	tcp->connectToHost("192.168.65.67", 9012);
	tcp->write("t");
	tcp->close();
	tramemou.clear();
	this->close();
	
}
void IHM_SrolBar_Sequence::getTcpTest() {
	
	std::vector<std::string> trame;
	for (int i = 0; i < e.size(); i++) {
		trame.push_back("CV:" + e[i]->objectName().toStdString() + "," + std::to_string(e[i]->value()));
	}
	if (tramemou.size() == 0) {
		for(int x = 0; x < trame.size(); x++){
		tcp->connectToHost("192.168.65.67", 9012);
		tcp->write(trame[x].c_str());
		tcp->close();
		tramemou.push_back(trame[x]);}
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