/* Projekt: Tierverwaltung */
/* Projektbeschreibung: Ein einfaches Programm, um sich mit den Prinzipien der Vererbung vertraut zu machen. */

/* Augabe 1:

	Gegeben ist folgendes Programm:

	#include <iostream>
	#include <cstdlib>

	using namespace std;

	class Tier
	{
	 public:
		int Anzahl;
		float Gewicht;

		void datenausgeben()
		{
			cout <<"Es sind "<<Anzahl << " Tiere mit je " <<Gewicht <<" kg vorhanden"<<endl;
		}
	};

	int main()
	{
		Tier Schwein;
		Schwein.Anzahl=50;
		Schwein.Gewicht=20;
		Schwein.datenausgeben();

		system("PAUSE");
		return 0;
	};

	Ändern Sie das Programm wie folgt ab:

	Im Programm soll es nun 3 Klassen geben:

		-	Die Oberklasse „Tier“ (hier soll nur noch die Anzahl der Tiere verwaltet werden)
		-	Die Unterklasse „Schlachtvieh“ (mit dem Attribut Gewicht)
		-	Die Unterklasse „Milchvieh“ (mit dem Attribut Milchleistung)

	Verwenden Sie einen Konstruktor mit Elementinitialisierungsliste, welche die Attribute befüllt.
	Erzeugen Sie je eine Instanz der Klasse Schlachtvieh und Milchvieh und geben Sie die Daten auf dem Bildschirm aus.

*/

#pragma region HEADER
#include <iostream>
#include <cstdlib>
#pragma endregion

#pragma region DEKLARATION: KLASSEN
class Tier
{
public:
	Tier(int);
protected:
	int Anzahl;
};

class Schlachtvieh : public Tier
{
public:
	Schlachtvieh(int,float);
	~Schlachtvieh();
	void datenausgeben();

private:
	float Gewicht;
};

class Milchvieh : public Tier
{
public:
	Milchvieh(int,float);
	~Milchvieh();
	void datenausgeben();

private:
	float Milchleistung;
};

#pragma endregion

#pragma region DEFINITION: KONSTRUKTOR KLASSE TIER
Tier::Tier(int anzahl)
{
	Tier::Anzahl = anzahl;
}
#pragma endregion


#pragma region DEFINITION: KONSTRUKTOREN KLASSE SCHLACHTVIEH
/// <summary>
/// Parameterkonstruktor.
/// </summary>
Schlachtvieh::Schlachtvieh(int anzahl, float gewicht) : Tier(anzahl)
{
	Schlachtvieh::Gewicht = gewicht;
}
#pragma endregion

#pragma region DEFINITION: DEKONSTRUKTOR KLASSE SCHLACHTVIEH
/// <summary>
/// Dekonstruktor.
/// </summary>
Schlachtvieh::~Schlachtvieh(){}
#pragma endregion

#pragma region DEFINITON: KONSTRUKTOREN KLASSE MILCHVIEH
/// <summary>
/// Parameterkonstruktor.
/// </summary>
Milchvieh::Milchvieh(int anzahl, float milchleistung) : Tier(anzahl)
{
	Milchvieh::Milchleistung = milchleistung;
}
#pragma endregion

#pragma region DEFINITION: DEKONSTRUKTOR KLASSE MILCHVIEH
/// <summary>
/// Dekonstruktor.
/// </summary>
Milchvieh::~Milchvieh(){}
#pragma endregion

#pragma region DEFINITION: METHODEN DER KLASSE SCHLACHTVIEH
/// <summary>
/// Methode, welche die Daten des Schlachtviehs ausgibt.
/// </summary>
void Schlachtvieh::datenausgeben()
{
	std::cout << "Es sind " << Tier::Anzahl << " Tiere mit je " << Schlachtvieh::Gewicht << " kg vorhanden." << std::endl;
}
#pragma endregion

#pragma region DEFINITION: METHODEN DER KLASSE MILCHVIEH
void Milchvieh::datenausgeben()
{
	std::cout << "Es sind " << Tier::Anzahl << " Tiere mit je einer Milchleistung von " << Milchvieh::Milchleistung << " l vorhanden." << std::endl;
}
#pragma endregion


#pragma region HAUPTPROGRAMM
int main()
{
	Schlachtvieh obj1 = Schlachtvieh::Schlachtvieh(50,200);
	Milchvieh obj2 = Milchvieh::Milchvieh(20, 2);

	obj1.datenausgeben();
	obj2.datenausgeben();

	std::system("PAUSE");

	return(0);
};
#pragma endregion