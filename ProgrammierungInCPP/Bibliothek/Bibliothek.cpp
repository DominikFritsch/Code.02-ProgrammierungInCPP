/* Projekt: Bibliothek */
/* Projektbeschreibung:

    Aufgabe:  Beispielanwendung objektorientierte Programmierung

    Ziel:       Vorbereitung Leistungsnachweis Teil 1

    Status:     Abgeschlossen

*/

/* Aufgabe:

	Es soll ein Programm zur Bibliotheksverwaltung geschrieben werden, wo die Daten eines
	Benutzers am Anfang des Programmstars abgefragt werden. Anschließend soll ein Menü
	erscheinen, wo der Benutzer navigieren kann. Es können folgendes funktionieren:

		- Personendaten erfassen
		- Buch ausleihen
		- Ausleihe verlängern
		- Alle Daten ausgeben
		- Buch zurückgeben
		- Beenden

	Die Personendaten werden komplett neu erfasst.
	Die nachfolgenden Funktionalitäten können nur genutzt werden, wenn der Ausleiher noch kein
	Buch hat, ansonsten erscheint eine Meldung, dass der Ausleiher bereits ein Buch hat.

		- Die Person hat die Möglichkeit, maximal eines von 3 Büchern auszuleihen. Bei
		  den Büchern sind nur der Titel und der Autor hinterlegt. Beim Ausleihen wird ein
	      Rückgabedatum angegeben, bis wann der Ausleiher das Buch zurückgeben soll
	      (Falsches Datum wird nicht abgefragt).
		- Die Ausleihe kann um 1 Monat verlängert werden. Beginnt die Ausleihe am
		  Monatsende, so wird das jeweilige Monat ebenfalls auf das Monatsende gesetzt.
			• Beispiel 1: Ausleihe ist 31.03.16 ? Verlängerung ? Neues Rückgabedatum: 30.04.16
			• Beispiel 2: Ausleihe ist 30.01.16 ? Verlängerung ? Neues Rückgabedatum: 28.02.16
			• Beispiel 3: Ausleihe ist 20.12.16 ? Verlängerung ? Neues Datum ist 20.01.17
		- Bei der Datenausgabe werden alle Daten von der Ausleihe (Person, Buch, Rückgabedatum) ausgegeben.
		- Wenn das Buch zurückgegeben wird, kann der Ausleiher wieder ein neues Buch ausleihen.

	Beim Beenden des Programms soll der Benutzer verabschiedet werden.

*/

#pragma region HEADER
#include <iostream>
#include <cstdlib>
#include <string>
#pragma endregion

#pragma region DEKLARATION: KLASSEN
class Person {
private:
	std::string vorname;
	std::string name;
	std::string strasse;
	unsigned int hausnr;
	std::string ort;
	unsigned int plz;
public:
	Person();
	void datenErfassen();
	void datenAusgeben();
};

class Buch {
private:
	std::string titel;
	std::string autor;
public:
	Buch();
	Buch(std::string, std::string);
	void datenAusgeben();
};

class Datum {
private:
	short tag;
	short monat;
	unsigned int jahr;
public:
	void datumErfassen();
	void datenAusgeben();
	void umEinenMonatErhoehen();
};

class Ausleihe {
private:
	Person ausleiher;
	Buch ausgeliehenesBuch;
	Datum rueckgabe;
	bool hat_buch;
public:
	Ausleihe();
	void datenErfassen(Person, Buch, Datum);
	void datenAusgeben();
	void verlaengere();
	void zurueckgeben();
	bool get_hat_buch();
};
#pragma endregion

#pragma region DEFINITION: KONSTRUKTOREN KLASSE PERSON
/// <summary>
/// Standardkonstruktor.
/// </summary>
Person::Person()
{
	vorname = " ";
	name = " ";
	strasse = " ";
	hausnr = 0;
	ort = " ";
	plz = 0;
}
#pragma endregion

#pragma region DEFINITION: METHODEN KLASSE PERSON
/// <summary>
/// Methode, die die Daten einer Person erfasst.
/// </summary>
void Person::datenErfassen()
{
	std::cout << "--Datenerfassung--" << std::endl;
	std::cout << "Vorname: ";
	std::cin >> vorname;
	std::cout << "Nachname: ";
	std::cin >> name;
	std::cout << "Strasse: ";
	std::cin >> strasse;
	std::cout << "Hausnummer: ";
	std::cin >> hausnr;
	std::cout << "PLZ: ";
	std::cin >> plz;
	std::cout << "Ort: ";
	std::cin >> ort;
	std::cout << std::endl << "Person erfasst." << std::endl;
}
/// <summary>
/// Methode, die die Daten einer Person ausgibt.
/// </summary>
void Person::datenAusgeben()
{
	std::cout << vorname << " " << name << std::endl;
	std::cout << strasse << " " << hausnr << std::endl;
	std::cout << plz << " " << ort << std::endl;
}
#pragma endregion

#pragma region DEFINITION: KONSTRUKTOREN KLASSE BUCH
/// <summary>
/// Standardkonstruktor.
/// </summary>
Buch::Buch()
{
	Buch::titel = " ";
	Buch::autor = " ";
}
/// <summary>
/// Parameterkonstruktor.
/// </summary>
/// <param name="t"></param>
/// <param name="a"></param>
Buch::Buch(std::string t, std::string a)
{
	Buch::titel = t;
	Buch::autor = a;
}
#pragma endregion

#pragma region DEFINITION: METHODEN KLASSE BUCH
/// <summary>
/// Methode, welche die Daten eines Buchs ausgibt.
/// </summary>
void Buch::datenAusgeben()
{
	std::cout << Buch::titel << " (von " << Buch::autor << ")";
}
#pragma endregion

#pragma region DEFINITION: METHODEN KLASSE DATUM
/// <summary>
/// Methode, welche ein Datum erfasst.
/// </summary>
void Datum::datumErfassen()
{
	std::cout << "Tag: ";
	std::cin >> Datum::tag;
	std::cout << "Monat: ";
	std::cin >> Datum::monat;
	std::cout << "Jahr: ";
	std::cin >> Datum::jahr;
}
/// <summary>
/// Methode, welche das erfasste Datum ausgibt.
/// </summary>
void Datum::datenAusgeben()
{
	std::cout << Datum::tag << "." << Datum::monat << "." << Datum::jahr << std::endl;
}
/// <summary>
/// Methode, welche das Ausleihdatum um einen Monat erhöht.
/// </summary>
void Datum::umEinenMonatErhoehen()
{
	if (Datum::monat == 12)
	{
		Datum::jahr += 1;
		Datum::monat = (Datum::monat % 12) + 1;
	}
	else if (Datum::tag == 28 && Datum::monat == 2)
	{
		Datum::tag = 31;
		Datum::monat += 1;
	}
	else if (Datum::tag <= 28)
	{
		Datum::monat += 1;
	}
	else if (Datum::tag > 28 && Datum::tag <= 31 && Datum::monat == 1)
	{
		Datum::tag = 28;
		Datum::monat += 1;
	}
	else if (Datum::tag == 31 && Datum::monat != 7)
	{
		switch (Datum::monat)
		{
		case 3:
		case 5:
		case 8:
		case 10:
		{
			Datum::tag = 30;
			Datum::monat += 1;
			break;
		}
		}
	}
	else if (Datum::tag == 30)
	{
		switch (Datum::monat)
		{
		case 4:
		case 6:
		case 9:
		case 11:
		{
			Datum::tag = 31;
			Datum::monat += 1;
			break;
		}
		}
	}
	else
		Datum::monat += 1;
}
#pragma endregion

#pragma region DEFINITION: KONSTRUKTOREN DER KLASSE AUSLEIHE
/// <summary>
/// Standardkonstruktor.
/// </summary>
Ausleihe::Ausleihe()
{
	Ausleihe::ausleiher = Person::Person();
	Ausleihe::ausgeliehenesBuch = Buch::Buch();
	Ausleihe::rueckgabe = Datum::Datum();
	Ausleihe::hat_buch = false;
}
#pragma endregion

#pragma region DEFINITION: METHODEN DER KLASSE AUSLEIHE
/// <summary>
/// Methode, welche die Daten eines ausgeliehenen Buchs erfasst.
/// </summary>
/// <param name="p"></param>
/// <param name="b"></param>
/// <param name="d"></param>
void Ausleihe::datenErfassen(Person p, Buch b, Datum d)
{
	Ausleihe::ausleiher = p;
	Ausleihe::ausgeliehenesBuch = b;
	Ausleihe::rueckgabe = d;
	Ausleihe::hat_buch = true;
}
/// <summary>
/// Methode, welche die Daten bezüglich eines ausgeliehenen Buchs wiedergibt.
/// </summary>
void Ausleihe::datenAusgeben()
{
	Ausleihe::ausleiher.datenAusgeben();
	std::cout << std::endl << "Ausgeliehenes Buch: ";
	Ausleihe::ausgeliehenesBuch.datenAusgeben();
	std::cout << std::endl << "Rueckgabe bis: ";
	Ausleihe::rueckgabe.datenAusgeben();
}
/// <summary>
/// Methode, welche es ermöglicht das Buch um einen weiteren Monat zu verlängern.
/// </summary>
void Ausleihe::verlaengere()
{
	Ausleihe::rueckgabe.umEinenMonatErhoehen();
	std::cout << "Ausleihe um 1 Monat verlaengert." << std::endl;
}
/// <summary>
/// Methode, welche es ermöglicht ein Buch zurückzugeben.
/// </summary>
void Ausleihe::zurueckgeben()
{
	std::cout << "Buch ";
	Ausleihe::ausgeliehenesBuch.datenAusgeben();
	std::cout << " wurde zuruckgegeben." << std::endl;
	Ausleihe::hat_buch = false;
}
/// <summary>
/// Methode, welche Zugriff auf die private Variable hat_buch ermöglicht.
/// </summary>
/// <returns></returns>
bool Ausleihe::get_hat_buch()
{
	return Ausleihe::hat_buch;
}
#pragma endregion

#pragma region HAUPTPROGRAMM
int main(void)
{
	Person p;
	int auswahl;
	Buch b[3] = { {"Titel 1", "Autor a"},{"Titel 2", "Autor b"},{"Titel 2", "Autor c"} };
	Ausleihe a;
	Datum d;

	p.datenErfassen();
	std::system("pause");

	do
	{
		std::system("cls");
		std::cout << "--MENUE--" << std::endl;
		std::cout << "[1] Personendaten erfassen" << std::endl;
		std::cout << "[2] Buch ausleihen" << std::endl;
		std::cout << "[3] Ausleihe verlaengern" << std::endl;
		std::cout << "[4] Daten ausgeben" << std::endl;
		std::cout << "[5] Buch zurueckgeben" << std::endl;
		std::cout << "[0] Beenden" << std::endl;
		std::cout << std::endl << "Auswahl: ";
		std::cin >> auswahl;

		switch (auswahl)
		{
		case 1:
		{
			std::system("cls");
			p.datenErfassen();
			std::system("pause");
			std::system("cls");
			break;
		}
		case 2:
		{
			std::system("cls");
			if (a.get_hat_buch() == true)
			{
				std::cout << "Ausleihe nicht moeglich. Person hat bereits ein Buch ausgeliehen" << std::endl;
			}
			else
			{
				std::cout << "Welches Buch soll ausgeliehen werden?" << std::endl;
				for (int i = 0; i < 3; i++)
				{
					std::cout << "[" << i + 1 << "] ";
					b[i].datenAusgeben();
					std::cout << std::endl;
				}
				std::cout << std::endl << "Auswahl: ";
				std::cin >> auswahl;

				std::system("cls");
				std::cout << "Bis wann soll das Buch zurueckgegeben werden?" << std::endl;
				d.datumErfassen();

				a.datenErfassen(p, b[auswahl - 1], d);
			}

			std::system("pause");
			std::system("cls");
			break;
		}
		case 3:
		{
			std::system("cls");
			if (a.get_hat_buch() == true)
				a.verlaengere();
			else std::cout << "Person hat kein Buch ausgeliehen." << std::endl;
			std::system("pause");
			std::system("cls");
			break;
		}
		case 4:
		{
			std::system("cls");
			if (a.get_hat_buch() == true)
				a.datenAusgeben();
			else std::cout << "Person hat kein Buch ausgeliehen." << std::endl;
			std::system("pause");
			std::system("cls");
			break;
		}
		case 5:
		{
			std::system("cls");
			if (a.get_hat_buch() == true)
				a.zurueckgeben();
			else std::cout << "Person hat kein Buch ausgeliehen." << std::endl;
			std::system("pause");
			std::system("cls");
			break;
		}
		case 0:
		{
			std::cout << std::endl << "Auf Wiedersehen" << std::endl;
			return 0;
		}
		default:
		{
			std::cout << std::endl << "Falsche Eingabe!" << std::endl;
			std::system("pause");
		}
		}
	} while (auswahl != 0);

	std::system("pause");

	return(0);
}
#pragma endregion




