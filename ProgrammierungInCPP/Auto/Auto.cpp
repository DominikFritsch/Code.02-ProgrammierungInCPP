/* Projekt: Auto */
/* Projektbeschreibung: Es soll eine Software zur Überwachung der Anzahl der Fahrten eines Autos entwickelt werden. */

/* Aufgabe 1:

    Erstellen Sie eine Klasse Auto, welche folgende Eigenschaften und Methoden hat:

    Eigenschaften:
        -	Marke
        -	Kilometerstand

    Methode:

        -	fahren() -> Hat als Übergabeparameter eine Ganzzahl, welche den Kilometerstand erhöht

    Verwenden Sie zur Initialisierung der Instanzen einen Konstruktor mit Elementinitialisierungsliste, welche die zwei Attribute annimmt.

    Zusätzlich soll eine Klassenvariable deklariert werden, welche sich merkt, wie oft man gefahren ist.

    Es sollen drei Fahrten erfolgen. Nach jeder Fahrt sollen die Daten ausgegeben werden.

    Zuletzt soll ein Destruktor erstellt werden, welcher zum Schluss des Programms aufegrufen wird und ausgibt,
    dass das Objekt entfernt wurde.

*/

#pragma region HEADER
#include <iostream>
#include <cstdlib>
#pragma endregion

#pragma region DEKLARATION: KLASSEN
class Auto
{
private:
    std::string Marke;
    long Kilometerstand;
    static int AnzahlFahrten;
public:
    Auto(std::string, long);
    ~Auto();
    void fahren(int);
    void ausgabeDaten(void);
};
#pragma endregion

#pragma region DEFINITION: KLASSENVARIABLEN
int Auto::AnzahlFahrten = 0;
#pragma endregion

#pragma region DEFINITION: KONSTRUKTOR
/// <summary>
/// Parameterkontruktor.
/// </summary>
/// <param name="Marke"></param>
/// <param name="Kilometerstand"></param>
Auto::Auto(std::string Marke, long Kilometerstand) : Marke(Marke), Kilometerstand(Kilometerstand)
{
    std::cout << "Parameterkonstruktor: Auto erstellt.";
    std::cout << std::endl;
    std::cout << std::endl;
}
#pragma endregion

#pragma region DEFINITION: DEKONSTRUKTOR
/// <summary>
/// Dekonstruktor.
/// </summary>
Auto::~Auto()
{
    std::cout << std::endl;
    std::cout << "Dekonstruktor: Auto gel\x94scht.";
    std::cout << std::endl;
}
#pragma endregion

#pragma region DEFINITION: METHODEN
/// <summary>
/// Methode, welche den Kilometerstand anhand des Übergabeparameters ändert.
/// </summary>
/// <param name="a"></param>
void Auto::fahren(int a)
{
    if (a)
    {
        Auto::Kilometerstand += a;
        ++Auto::AnzahlFahrten;
    }
        
}
/// <summary>
/// Methode, welche die aktuellen Daten des jeweiligen Autos ausgibt.
/// </summary>
/// <param name=""></param>
void Auto::ausgabeDaten(void)
{
    std::cout << "Marke: " << Auto::Marke;
    std::cout << std::endl;
    std::cout << "Aktueller Kilometerstand: " << Auto::Kilometerstand;
    std::cout << std::endl;
    std::cout << "Anzahl der Fahrten: " << Auto::AnzahlFahrten;
    std::cout << std::endl;
    std::cout << std::endl;
}
#pragma endregion

#pragma region HAUPTPROGRAMM
int main(void)
{
    Auto obj = Auto::Auto("BMW", 0);

    obj.fahren(1000);
    obj.ausgabeDaten();
    obj.fahren(20);
    obj.ausgabeDaten();
    obj.fahren(80);
    obj.ausgabeDaten();

    std::system("pause");

    return(0);
}
#pragma endregion