#include "IHM_SrolBar_Sequence.h"
IHM_SrolBar_Sequence::IHM_SrolBar_Sequence(const QString name,int voie, int adresse,int id_sequence) : QWidget()																								// spécification du constructeur
{
	idsequence = id_sequence;
	adress = adresse;
	
	mysql = mysql_init(NULL);
	int adressmodifi = adresse;
	if (!mysql_real_connect(mysql, "127.0.0.1", "root", "", "Projet_DMX", 0, NULL, 0))
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
		}
		Valid = new QPushButton("Valider", this);
		Valid->move(x, 150);
		QObject::connect(Valid, SIGNAL(clicked()), this, SLOT(getValide()));
	}
}
void IHM_SrolBar_Sequence::getValide() {


	std::string requetes = "SELECT `Id_AdressEquipement` FROM `adressequipement`, equipement WHERE adressequipement.Id_Equipement = equipement.Id_Equipement and equipement.Name = '" + QWidget::windowTitle().toStdString() + "'";
	mysql_query(mysql, requetes.c_str());
	MYSQL_RES *results = NULL;
	MYSQL_ROW rows;
	results = mysql_store_result(mysql);
	while ((rows = mysql_fetch_row(results)))
	{

		for (int i = 0; i < a.size(); i++) {
		std::string requetes = "INSERT INTO `sequenceusedequipement`(`Id_SequenceUsedEquipement`, `Valeur`, `Id_AdressEquipement`, `Id_Sequence`, `adress`) VALUES (NULL,"+ std::to_string( a[i]->value())+","+rows[0]+","+std::to_string(idsequence)+","+std::to_string(adress)+")";
		mysql_query(mysql, requetes.c_str());
		MYSQL_RES *results = NULL;
		MYSQL_ROW rows;
		results = mysql_store_result(mysql);
		adress++;
	}
	}
	this->close();

}