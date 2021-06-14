// ConsoleThomas.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include <iostream>
#include <string>
#include "mysql_bdd.h"
#include "Rs232.h"
//#include "TCPclient.h"
const std::vector<std::string> explode(const std::string& msg, const char& c);
int main()
{
	char buffer[1024];
	mysql_bdd * bdd;
	Rs232 * serie;
	//TCPclient * tcp;
	serie = new Rs232();
	bdd = new mysql_bdd();
	bdd->connectMYSQL();
	std::vector<std::string> trame;
	std::vector<MYSQL_ROW> addressEquipement;
	std::vector<MYSQL_ROW> equipement = bdd->getSelectrequet("SELECT * FROM `equipement` WHERE 1");
	std::string nbEquipement = std::to_string( equipement.size());
	serie->OpenPort();
	serie->WritePort((char*)nbEquipement.c_str());

	for (int i = 0; i < equipement.size(); i++) 
	{
		std::string nbVoie = equipement[i][2];
		std::vector<MYSQL_ROW> addressEquipement = bdd->getSelectrequet("SELECT * FROM `adressequipement` WHERE `Id_Equipement` = " + std::to_string(atoi(equipement[i][0])));
		std::string adress = addressEquipement[0][1];
		std::string t = ":" + adress + "-" + nbVoie + "\n";
		trame.push_back(t);
		char * test = (char*)t.c_str();
		serie->WritePort(test);
		std::cout << t << std::endl;
		
	}

	
	
	do {

		serie->ReadPort(buffer);
		std::string trameArduino = buffer;

		std::vector<std::string> tramearduinopass = explode(trameArduino, ':');
		std::string trame;
		for (int i = 0; i < tramearduinopass.size(); i++) 
		{
			if (tramearduinopass[i + 1] == "") i = tramearduinopass.size();
			trame += "CV" + tramearduinopass[i] + "," + tramearduinopass[i++]+";";
		}

		



	} while (1);
}
const std::vector<std::string> explode(const std::string& msg, const char& c)
{
	std::string buff = "";
	std::vector<std::string> v;
	for (int i = 0; i < msg.length(); i++)
	{
		char compare = msg[i];
		if (compare != c) buff += compare;
		else if (compare == c && buff != "")
		{
			v.push_back(buff);
			buff = "";
		}
	}
	if (buff != "")
		v.push_back(buff);

	return v;
}

// Exécuter le programme : Ctrl+F5 ou menu Déboguer > Exécuter sans débogage
// Déboguer le programme : F5 ou menu Déboguer > Démarrer le débogage

// Astuces pour bien démarrer : 
//   1. Utilisez la fenêtre Explorateur de solutions pour ajouter des fichiers et les gérer.
//   2. Utilisez la fenêtre Team Explorer pour vous connecter au contrôle de code source.
//   3. Utilisez la fenêtre Sortie pour voir la sortie de la génération et d'autres messages.
//   4. Utilisez la fenêtre Liste d'erreurs pour voir les erreurs.
//   5. Accédez à Projet > Ajouter un nouvel élément pour créer des fichiers de code, ou à Projet > Ajouter un élément existant pour ajouter des fichiers de code existants au projet.
//   6. Pour rouvrir ce projet plus tard, accédez à Fichier > Ouvrir > Projet et sélectionnez le fichier .sln.
