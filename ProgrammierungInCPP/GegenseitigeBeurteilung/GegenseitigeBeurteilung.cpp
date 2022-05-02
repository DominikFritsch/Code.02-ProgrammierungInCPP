/* Projekt: GegenseitigeBeurteilung */
/* Projektbeschreibung: Vorlage, um die geschriebenen Programme der Kursteilnehmer zu beurteilen. */

#pragma region HEADER
#include <iostream>
#pragma endregion


#pragma region HAUPTPROGRAMM
int main(void)
{

	std::cout << "GEGENSEITIGE BEURTEILUNG";
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << "Programme anderer Teilnehmer liegen als Kommentar vor.";
	std::cout << std::endl;
	std::cout << std::endl;
	std::system("pause");

	return(0);
}


#pragma endregion



/**************************************************************

		TEILNEHMER 1

***************************************************************/

/*
#include <iostream>
#include <cstdlib>

using namespace std;
//Funktionen
int anzahlpositionen(string[]);       //Funktion mit Rückgabewert
void arraysbefuellen(string[], float[]);
void sortieren(string[], float[]);


int main() {
	string produktname[10];  //Array für 10 Produktnamen, unbefüllt
	float preis[10] = { 0,0,0,0,0,0,0,0,0,0 };        //Array für 10 Preise als Dezimalzahlen, Standard 0
	int eingabe = 1;             //Eingabe zur Menüsteuerung

	while (eingabe != 0)     //while-Schleife in Verbindung mit switch-case zur Menüsteuerung
	{
		system("cls");
		cout << "[1] Position erfassen" << endl;
		cout << "[2] Positionen anzeigen" << endl;
		cout << "[3] Positionen sortieren" << endl;
		cout << "[0] Beenden" << endl << endl;
		//Anzahl der Positionen in Einkaufsliste wird in Funktion herausgefunden
		cout << "Die aktuelle Anzahl an Positionen betraegt: " << anzahlpositionen(produktname) << endl << endl;

		cout << "Treffen Sie Ihre Auswahl: ";

		cin >> eingabe;     //Benutzereingabe zur Menüsteuerung

		switch (eingabe)
		{
		case 1:         //1 = Position erfassen
		{
			system("cls");

			arraysbefuellen(produktname, preis);  //Funktionsaufruf

			system("pause");
			break;
		}
		case 2:         //2 = Positionen anzeigen
		{
			system("cls");

			for (int i = 0; i < 10; i++)     //for-Schleife gibt alle Produktnamen und Preise in Arrays aus
			{
				cout << "[" << i + 1 << "] " << produktname[i] << "\t" << preis[i] << endl;
			}

			system("pause");
			break;
		}
		case 3:         //3 = Positionen sortieren
		{
			system("cls");

			sortieren(produktname, preis);

			system("pause");
			break;
		}
		case 0:         //0 = Beenden des Programms
		{
			cout << endl << "Auf Wiedersehen!" << endl;
			break;
		}
		default:        //alternativ bei Eingabe keiner Zahl von 0 bis 3
		{
			cout << endl << "Falsche Eingabe!" << endl << endl;
			system("pause");
		}
		}
	}
	return 0;
}

int anzahlpositionen(string produktname[])      //Übergabeparameter an Funktion ist Produktname-Array
{
	int anzahl = 0;
	for (int i = 0; i < 10; i++)         //for-Schleife prüft für jede Stelle des Arrays, ob Stelle nicht leer ist
	{
		if (produktname[i] != "")
		{
			anzahl++;                   //wenn Stelle im Array nicht leer ist, dann wird Anzahl um 1 erhöht
		}
	}
	return anzahl;              //Rückgabe der Anzahl der besetzten Felder im Array
}

void arraysbefuellen(string produktname[], float preis[])       //Übergabe beider Arrays
{
	string eingabe_produktname;       //Variablen zur Benutzer-Eingabe deklarieren
	float eingabe_preis;

	int freie_Stelle = -1;          //Hilfsvariable

	for (int i = 0; i < 10; i++)       //mit for-Schleife prüfen, ob im gesamten Array noch Platz für weiteren Artikel ist
	{
		if (produktname[i] == "")      //wenn noch eine Stelle leer
		{
			freie_Stelle = i;         //freie Stelle gefunden, 1. gefundene soll verwendet werden
			break;                    //verlasse for-Schleife, da freie Stelle im Array gefunden
		}
	}
	if (freie_Stelle < 0)        //wenn keine Stelle im Array leer und Variable noch auf -1, dann Fehlermeldung
	{
		cerr << endl << "Liste ist bereits voll" << endl << endl;
		return;         //Funktion vorzeitig verlassen
	}
	//Ausführung, wenn freie Stelle vorhanden ist
	cout << "Welchen Artikel wollen Sie zur Liste hinzufuegen? " << endl;
	cin >> eingabe_produktname;
	cout << "Welchen Preis hat der Artikel? " << endl;
	cin >> eingabe_preis;

	produktname[freie_Stelle] = eingabe_produktname;    //Übergabe der Eingaben an Arrays
	preis[freie_Stelle] = eingabe_preis;
	//Kontroll-Zeile für getätigte Eingaben
	cout << endl << "Produkt: " << produktname[freie_Stelle] << " erfasst zum Preis: " << preis[freie_Stelle] << endl << endl;
}

void sortieren(string produktname[], float preis[])      //Übergabe beider Arrays
{
	string tmp_produktname;     //temporäre Variablen für Bubblesort
	float tmp_preis;

	for (int i = 0; i < 10; i++)     //klassischer Bubblesort
	{
		for (int j = (i + 1); j < 10; j++)
		{
			if (preis[i] < preis[j])    //größte Preise stehen allerdings links, damit Liste von vorne befüllt wird
			{
				tmp_produktname = produktname[i];       //Vertauschung Produktname
				produktname[i] = produktname[j];
				produktname[j] = tmp_produktname;

				tmp_preis = preis[i];              //Vertauschung Preis
				preis[i] = preis[j];
				preis[j] = tmp_preis;
			}
		}
	}

	cout << "Einkaufsliste wurde anhand des Preises sortiert:" << endl << endl;

	for (int i = 0; i < 10; i++)   //Ausgabe sortierte Liste
	{
		cout << "[" << i + 1 << "] " << produktname[i] << "\t" << preis[i] << endl;
	}
	cout << endl;
}
*/

/**************************************************************

		TEILNEHMER 2

***************************************************************/

/*
#include <iostream>
#include <string>
using namespace std;

string name[9];
int price[9];

string product;
int productprice;
int yesno = 1;
string yesno_alt;
int count;


int control;

int main() {

	while (control != 4) {

		cout << endl;
		cout << endl;
		cout << "1 () Position erfassen" << endl;
		cout << "2 () Positionen anzeigen" << endl;
		cout << "3 () Positionen sortieren" << endl;
		cout << "4 () Beenden" << endl;

		cin >> control;
		yesno = 1;

		switch (control) {

		case 1: {

			bool check = true;

			cout << "Position erfassen" << endl;
			cout << "_______________________" << endl;
			cout << endl;


			while (yesno == 1) {


				cout << "Bitte geben Sie den Namen des zu erfassenden Produkts ein" << endl;
				cin >> product;
				cout << "Bitte geben Sie den Preis von " << product << " ein." << endl;
				cin >> productprice;



				for (int i = 0; i <= 9; i++) {

					if (name[i].empty()) {
						name[i] = product;
						price[i] = productprice;

						break;

					}

					if (i == 9) {
						cout << "Die maximale Anzahl von Positionen ist erreicht. Es können keine weiteren mehr hinzugefügt werden" << endl;
						check = false;
						yesno = 2;
					}


				}

				if (check) {

					cout << "Wollen Sie ein weiteres Produkt erfassen?" << endl;
					cout << "Ja (1)" << endl;
					cout << "Nein (2)" << endl;
					cin >> yesno;



				}



			}




			break;
		}


		case 2: {



			cout << "Position anzeigen" << endl;
			cout << "_______________________" << endl;
			cout << endl;
			int count = 0;

			for (int i = 0; i <= 9; i++) {

				if (!name[i].empty()) {

					count++;

					cout << count << ". Position: " << name[i] << "--- Preis: " << price[i] << " Euro." << endl;
				}

				else {
					cout << " ";
				}
			}

			break;
		}


		case 3: {

			int zwischenspeicher_preis;
			string zwischenspeicher_produkt;
			int change;
			int counter = 0;

			while (counter < 10) {

				for (int i = 0; i <= 9; i++) {
					if (price[i] > price[i + 1]) {

						zwischenspeicher_preis = price[i];
						zwischenspeicher_produkt = name[i];

						price[i] = price[i + 1];
						name[i] = name[i + 1];


						price[i + 1] = zwischenspeicher_preis;
						name[i + 1] = zwischenspeicher_produkt;
					}
				}

				counter++;
			}


			//		    	      }
			//		    	    }
			//		    	  }



			for (int i = 0; i <= 9; i++) {

				if (!name[i].empty()) {
					cout << price[i] << "  " << name[i] << endl;
				}
			}

			break;
		}


		case 4: {

			cout << "Vielen Dank für Ihren Besuch!!" << endl;

			break;
		}




		}


	}

}
*/


/**************************************************************

		TEILNEHMER 3

***************************************************************/

/*
#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

void erfassen(int, string[], float[]);
void anzeigen(int, string[], float[]);
void sortieren(int, string[], float[]);

int main()
{

	int wahl;
	int i = 0;
	string name[10];
	float preis[10];

	do
	{
		system("cls");
		cout << "Einkaufsliste" << endl;
		cout << "Position erfassen" << "\t" << "[1]" << endl;
		cout << "Position anzeigen" << "\t" << "[2]" << endl;
		cout << "Position sortieren" << "\t" << "[3]" << endl;
		cout << "Beenden" << "\t" << "\t" << "\t" << "[0]" << endl << endl;

		cout << "Aktuelle Anzahl Positionen: " << "\t" << i << endl;

		cin >> wahl;  //Auswahl des Menüpunkts
		cout << endl;

		system("cls");

		switch (wahl) {

		case 1: {
			if (i < 10)
			{
				erfassen(i, name, preis);
				i++;
			}
			if (i >= 10)
			{
				cout << "Einkaufsliste voll" << endl; //Für den Fall das die Einkaufsliste bereits 10 Punkte hat
			}
			system("pause");
			break;
		}
		case 2: {
			anzeigen(i, name, preis);
			system("pause");
			break;
		}
		case 3: {
			sortieren(i, name, preis);
			system("pause");
			break;
		}
		case 0: {
			break;
		}
		default: {
			cout << "Fehlerhafte Eingabe" << endl;  //Falls eine falsche Eingabe erfolgt
			system("pause");
		}
		}
	} while (wahl != 0);
	cout << "Auf Wiedersehen" << endl;

	system("pause");
	return 0;
}

void erfassen(int i, string name[], float preis[])
{
	cout << "Produktname" << endl;
	cin >> name[i];
	cout << endl;
	cout << "Preis" << endl;
	cin >> preis[i];
	cout << endl;
}

void anzeigen(int j, string name[], float preis[])
{
	int t = 0;
	while (t < j)
	{
		cout << "Produktname: " << name[t] << "\t" << "Preis: " << preis[t] << " Euro" << endl;   //Ausgabe der Felder
		t++;
	}
}

void sortieren(int k, string name[], float preis[])
{
	string tmp_name;
	float tmp_preis;
	//Bubblesort
	for (int i = 0; i < k; i++)
	{
		for (int j = (i + 1); j < k; j++)
		{
			if (preis[i] > preis[j])
			{
				tmp_name = name[i];
				name[i] = name[j];
				name[j] = tmp_name;

				tmp_preis = preis[i];
				preis[i] = preis[j];
				preis[j] = tmp_preis;
			}
		}
	}
	cout << "Einkaufsliste sortiert" << endl;
}
*/



/**************************************************************

		TEILNEHMER 4

***************************************************************/

/*
#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

string produkte;
int preis = 0;
int eingabe = 1;
int pre = 0;

int main(int argc, char** argv) {

	while (eingabe != 0)
	{
		system("cls");
		cout << "Willkommen zur virtuellen Einkaufsliste" << endl;

		cout << "[1] Position erfassen (Texteingabe)" << endl;
		cout << "[2] Position anzeigen (Auswahl)" << endl;
		cout << "[3] Position sortieren" << endl;
		cout << "[4] Beenden" << endl;
		cout << "Treffen Sie Ihre Auswahl: ";

		cin >> eingabe;

		switch (eingabe)
		{
		case 1:
		{
			system("cls");
			const int SIZE = 10; //Array deklariert - 10 Speicherplätze
			string produkte[10];

			string liste = produkte[1] + produkte[2];
			int weiteres_Produkt = 0;

			for (int i = 0; i < 1; i++)
			{
				std::cin >> produkte[i];
				break;

				cout << "Möchten sie ein weiteres Produkt erfassen? [1] Ja  [Nein]" << endl;
				cin >> weiteres_Produkt;

				int(weiteres_Produkt);
				{
		case 1:
			for (int i = 0; i < 1; i++)
			{
				std::cin >> produkte[i];
				break;
			}



		case 2:
			cout << "Alle Produkte" << endl;

			for (int i = 0; i < 10; i++)
			{
				std::cout << produkte[i] << endl;
			}

				}

				system("pause");

			}

		case 2:
		{

		}

		case 3:
		{

		}

		case 4:
		{
			system("cls");

			cout << endl << "Auf Wiedersehen!" << endl;
			break;
		}


		}
		return 0;
		}

	}
	*/