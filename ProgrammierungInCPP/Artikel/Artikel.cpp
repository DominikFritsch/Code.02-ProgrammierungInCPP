/* Projekt: Artikel */
/* Projektbeschreibung: Sie arbeiten im Einzelhandel und m�chten Artikel verwalten. */

/* Aufgabe 1:

	Erstellen Sie eine Klasse namens Artikel. Diese soll folgende Eigenschaften haben:

		-	Bezeichnung
		-	Preis

	Die Klasse soll folgende Methoden beinhalten:

		-	get_Bezeichnung() -> gibt die Artikelbezeichnung zur�ck
		-	get_Preis() -> gibt den Artikelpreis zur�ck
		-	set_Bezeichnung() -> setzt die Bezeichnung f�r den Artikel
		-	set_Preis() -> setzt den Preis f�r den Artikel
		-	Daten_erfassen() -> setzt die Bezeichnung und den Preis mit Hilfe der Setter-Methoden
		-	Daten_ausgeben() -> gibt die Bezeichnung und den Preis f�r den Artikel mit Hilfe der Getter-Methoden aus
		-	Gesamtpreis_berechnen() -> Es wird eine St�ckzahl �bergeben. Der Gesamtpreis (St�ckzahl*Preis) wird ermittelt und ausgegeben

	Erstellen Sie im Hauptprogramm ein Objekt vom Typ Artikel.
	Erfassen Sie die Daten und geben sie anschlie�end diese nochmal aus.
	Der Benutzer soll anschlie�end eine St�ckzahl eingeben k�nnen, wodurch dann der Gesamtpreis ermittelt wird.

*/

#pragma region HEADER
#include <iostream>
#include <cstdlib>
#include <string>
#pragma endregion

#pragma region DEKLARATION: KLASSEN
class Artikel
{
private:
	std::string Bezeichnung = " ";
	float Preis = 0.0f;
public:
	std::string get_Bezeichnung(void);
	float get_Preis(void);
	void set_Bezeichnung(std::string);
	void set_Preis(float);
	void Daten_erfassen(void);
	void Daten_ausgeben(void);
	void Gesamtpreis_berechnen(int);
};
#pragma endregion

#pragma region DEFINITION: METHODEN
/// <summary>
/// Methode zur Erfassung der Artikelbezeichnung.
/// </summary>
/// <param name=""></param>
/// <returns></returns>
std::string Artikel::get_Bezeichnung(void)
{
	return(Artikel::Bezeichnung);
}
/// <summary>
/// Methode zur Erfassung des Artikelpreises.
/// </summary>
/// <param name=""></param>
/// <returns></returns>
float Artikel::get_Preis(void)
{
	return(Artikel::Preis);
}
/// <summary>
/// Methode zur Ver�nderung der Artikelbezeichnung.
/// </summary>
/// <param name=""></param>
void Artikel::set_Bezeichnung(std::string a)
{
	Artikel::Bezeichnung = a;
}
/// <summary>
/// Methode zur Ver�nderung des Artikelpreises.
/// </summary>
/// <param name="a"></param>
void Artikel::set_Preis(float a)
{
	Artikel::Preis = a;
}
/// <summary>
/// Methode zum Erfassen der Artikeldaten.
/// </summary>
/// <param name=""></param>
void Artikel::Daten_erfassen(void)
{
	std::string tempBezeichnung;
	float tempPreis;

	std::cout << "Eingabe Artikelbezeichnung: ";
	std::cin >> tempBezeichnung;
	std::cout << "Eingabe Preis: ";
	std::cin >> tempPreis;

	Artikel::set_Bezeichnung(tempBezeichnung);
	Artikel::set_Preis(tempPreis);
}
/// <summary>
/// Methode zur Ausgabe der Artikeldaten.
/// </summary>
/// <param name=""></param>
void Artikel::Daten_ausgeben(void)
{
	std::cout << "Artikel: ";
	std::cout << std::endl;
	std::cout << "Bezeichnung: " << Artikel::get_Bezeichnung() << "\t|\t" << "Preis: " << Artikel::get_Preis() << " EUR";
}
/// <summary>
/// Methode zur Berechnung des Gesamtpreises.
/// </summary>
/// <param name="anzahl"></param>
/// <returns></returns>
void Artikel::Gesamtpreis_berechnen(int anzahl)
{
	if(anzahl == 1) std::cout << "Gesamtpreis: " << (anzahl * Artikel::get_Preis()) << " EUR.";
	else std::cout << "Gesamtpreis bei " << anzahl << " gekauften Artikeln: " << (anzahl * Artikel::get_Preis()) <<" EUR.";
}

#pragma endregion

#pragma region HAUPTPROGRAMM
int main(void)
{
	Artikel objArt;
	int anzahl;

	std::cout << "------------------------------------------------------------";
	std::cout << std::endl;
	objArt.Daten_erfassen();
	std::cout << "------------------------------------------------------------";
	std::cout << std::endl;
	objArt.Daten_ausgeben();
	std::cout << std::endl;
	std::cout << "------------------------------------------------------------";
	std::cout << std::endl;
	std::cout << "Eingabe Anzahl der Artikel: ";
	std::cin >> anzahl;
	std::cout << std::endl;
	objArt.Gesamtpreis_berechnen(anzahl);
	std::cout << std::endl;
	std::cout << std::endl;

	std::system("pause");

	return(0);
}
#pragma endregion
