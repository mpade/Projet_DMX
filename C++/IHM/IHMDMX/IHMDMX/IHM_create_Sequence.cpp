#include "IHM_Create_Sequence.h"
#include "iostream"

IHM_Create_Sequence::IHM_Create_Sequence() : QWidget()																								// spécification du constructeur
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
	/* Connexions Signal - Slot */
		// this = SLOT de IHMDMX (SLOT MAISON)
	getAllEquipement();
	duree = new QLineEdit;
	duree->setPlaceholderText("Duree en seconde !");
	grid->addWidget(duree, 1, 1);
	cree = new QPushButton("Cree", this);
	grid->addWidget(cree, 1, 2);
	QObject::connect(cree, SIGNAL(clicked()), this, SLOT(slidergetEquipement()));

	}
}
//==========================================================================================


void IHM_Create_Sequence::getAllEquipement()
{

	mysql_query(mysql, "SELECT `Name` FROM `equipement` WHERE 1");

	//Déclaration des pointeurs de structure
	MYSQL_RES *result = NULL;
	MYSQL_ROW row;
	unsigned int i = 0, z =0;
	unsigned int num_champs = 0;
	
	//On met le jeu de résultat dans le pointeur result
	result = mysql_use_result(mysql);

	//On récupère le nombre de champs
	num_champs = mysql_num_fields(result);



	groupBox = new QGroupBox(tr("Equipement"));
	vbox = new QVBoxLayout;
	
	groupBox->setFlat(true);
	while ((row = mysql_fetch_row(result)))
	{

		//On déclare un pointeur long non signé pour y stocker la taille des valeurs
		unsigned long *lengths;

		//On stocke ces tailles dans le pointeur
		lengths = mysql_fetch_lengths(result);

		for (i = 0; i < num_champs; i++)
		{
			//On ecrit toutes les valeurs
			e.push_back(new QCheckBox(tr(row[i]), this));
			for (int x = z; x < e.size(); x++) {
				e[x]->setObjectName(row[i]);
				z++;
			}
		}
		
	}
	
	for (int i = 0; i < e.size(); i++) {
		
		vbox->addWidget(e[i]);
	}
	vbox->addStretch(1);
	groupBox->setLayout(vbox);
	grid->addWidget(groupBox, 0, 1);
	setLayout(grid);
}
void IHM_Create_Sequence::slidergetEquipement() {
	
	for (int d = 0; d < e.size(); d++) {
		if (e[d]->checkState()) {
			std::string name = e[d]->objectName().toStdString();
			std::string requete = "SELECT `Id_Equipement`, `Nb_voie` FROM `equipement` WHERE `Name` = '" + name + "'";
			
			mysql_query(mysql, requete.c_str());

			//Déclaration des pointeurs de structure
			MYSQL_RES *result = NULL;
			MYSQL_ROW row;
			

			//On met le jeu de résultat dans le pointeur result
			result = mysql_use_result(mysql);

			
			while ((row = mysql_fetch_row(result)))
			{
				
				std::string requetes = "SELECT `Adresse` FROM `adressequipement` WHERE `Id_Equipement` = " + std::to_string(atoi(row[0])) ;
				mysql_query(mysql, requetes.c_str());
				
				MYSQL_RES *results = mysql_use_result(mysql);
				MYSQL_ROW rows;
				while ((rows = mysql_fetch_row(results)))
				{
					//On ecrit toutes les valeurs
					IHM_SrolBar_Sequence *t = new IHM_SrolBar_Sequence(e[d]->objectName(), atoi(row[1]), atoi(rows[0]));
					t->show();
				}

			}

			
		}
			
	}

}

