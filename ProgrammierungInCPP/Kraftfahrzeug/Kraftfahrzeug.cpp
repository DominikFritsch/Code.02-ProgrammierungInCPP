/* Projekt: Kraftfahrzeug */
/* Projektbeschreibung: Ein einfaches Programm, um sich mit den Prinzipien der Vererbung vertraut zu machen. */

/* Aufgabe 1:

    Erstellen Sie eine Klasse KFZ mit den Attributen

        -	Marke

    Erstellen Sie die beiden abgeleitete Klassen Auto und LKW. Diese erben die Attribute von KFZ.


    Auto hat folgende Eigenschaften:

    Attribut:
        -	Anzahl_Passagiere

    Konstruktor:
        -	Standardkonstruktor -> Erfasst die Daten der Basis-/abgeleiteten Klasse

    Methode:
        -	Ausgabe() -> Gibt alle Daten aus
        -	Einsteigen() -> Erhöht die Anzahl der Passagiere

    LKW hat folgende Eigenschaften:

    Attribut:
        -	Tonnen

    Konstruktor:
        -	Standardkonstruktor -> Erfasst die Daten der Basis-/abgeleiteten Klasse

    Methode:
        -	Ausgabe() -> Gibt alle Daten aus
        -	Beladen() -> Einene Übergabeparameter, erhöht die Tonnen

    Erstellen Sie in der Main-Funktion 2 Felder.
    Das erste Feld kann 3 Autos aufnehmen, das zweite Feld kann 2 LKWs aufnehmen.
    Rufen Sie Anschließend die Methode einsteigen und beladen aller Instanzen auf,
    wobei die Eingabe der dafür nötigen Daten in der Main-Funktion abgefragt werden.
    Geben Sie zum Schluss nochmal alle Daten aus.

*/

#pragma region HEADER
#include <iostream>
#include <cstdlib>
#pragma endregion

#pragma region DEKLARATION: KLASSE KFZ
class KFZ
{
public:
    KFZ();
    ~KFZ();

protected:
    std::string Marke;
};
#pragma endregion

#pragma region DEFINITION: KONSTRUKTOREN KLASSE KFZ
/// <summary>
/// Standardkonstruktor.
/// </summary>
KFZ::KFZ()
{
    KFZ::Marke = " ";
}
#pragma endregion

#pragma region DEFINITION: DEKONSTRUKTOR KLASSE KFZ
/// <summary>
/// Dekonstruktor.
/// </summary>
KFZ::~KFZ(){}
#pragma endregion

#pragma region DEKLARATION: KLASSE AUTO
class AUTO : public KFZ
{
public:
    AUTO();
    ~AUTO();
    void Ausgabe(void);
    void Einsteigen(int);
private:
    int Anzahl_Passagiere;
};
#pragma endregion

#pragma region DEFINITION: KONSTRUKTOREN KLASSE AUTO
/// <summary>
/// Standardkonstruktor.
/// </summary>
AUTO::AUTO(): KFZ::KFZ()
{
    std::cout << "Eingabe Marke: ";
    std::cin >> KFZ::Marke;
    std::cout << "Eingabe Anzahl Passagiere: ";
    std::cin >> AUTO::Anzahl_Passagiere;
}
#pragma endregion

#pragma region DEFINITION: DEKONSTRUKTOR KLASSE AUTO
/// <summary>
/// Dekonstruktor.
/// </summary>
AUTO::~AUTO() {}
#pragma endregion

#pragma region DEFINITION: METHODEN KLASSE AUTO
/// <summary>
/// Methode, welche die Daten eines Autos ausgibt.
/// </summary>
/// <param name=""></param>
void AUTO::Ausgabe(void)
{
    std::cout << "Marke: " << KFZ::Marke;
    std::cout << std::endl;
    std::cout << "Aktuelle Passagiere: " << AUTO::Anzahl_Passagiere;
    std::cout << std::endl;
}
/// <summary>
/// Methode, welche die Anzahl der Passagiere erhöht.
/// </summary>
/// <param name="anzahl"></param>
void AUTO::Einsteigen(int anzahl)
{
    AUTO::Anzahl_Passagiere += anzahl;
}
#pragma endregion

#pragma region DEKLARATION: KLASSE LKW
class LKW : public KFZ
{
public:
    LKW();
    ~LKW();
    void Ausgabe(void);
    void Beladen(int);

private:
    int Tonnen;
};
#pragma endregion

#pragma region DEFINITION: KONSTRUKTOREN KLASSE LKW
/// <summary>
/// Standardkonstruktor.
/// </summary>
LKW::LKW() : KFZ::KFZ()
{
    std::cout << "Eingabe Marke: ";
    std::cin >> KFZ::Marke;
    std::cout << "Eingabe Anzahl Tonnen: ";
    std::cin >> LKW::Tonnen;
}
#pragma endregion

#pragma region DEFINITION: DEKONSTURKTOR KLASSE LKW
/// <summary>
/// Dekonstruktor.
/// </summary>
LKW::~LKW(){}
#pragma endregion

#pragma region DEFINITION: METHODEN KLASSE LKW
/// <summary>
/// Methode, welche die Daten eines LKWs ausgibt.
/// </summary>
/// <param name=""></param>
void LKW::Ausgabe(void)
{
    std::cout << "Marke: " << KFZ::Marke;
    std::cout << std::endl;
    std::cout << "Aktuelles Gewicht: " << LKW::Tonnen;
    std::cout << std::endl;
}
/// <summary>
/// Methode, welche das Beladungsgewicht des LKWs erhöht.
/// </summary>
/// <param name="gewicht"></param>
void LKW::Beladen(int gewicht)
{
    LKW::Tonnen += gewicht;
}
#pragma endregion

#pragma region HAUPTPROGRAMM
int main(void)
{
    std::cout << "---------- Datenerfassung: Autos ----------";
    std::cout << std::endl;
    std::cout << std::endl;

    AUTO autos[3];

    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << "---------- Datenerfassung: LKWs ----------";
    std::cout << std::endl;
    std::cout << std::endl;

    LKW lastkraftfahrzeuge[2];

    int tempPassagiere;
    int tempGewicht;

    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << "---------- Einsteigen Passagiere ----------";
    std::cout << std::endl;
    std::cout << std::endl;

    for (int i = 0; i < 3; i++)
    {
        std::cout << "Eingabe Passagiere: ";
        std::cin >> tempPassagiere;
        autos[i].Einsteigen(tempPassagiere);
    }

    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << "---------- Beladen Gewicht ----------";
    std::cout << std::endl;
    std::cout << std::endl;

    for (int i = 0; i < 2; i++)
    {
        std::cout << "Eingabe Gewicht: ";
        std::cin >> tempGewicht;
        lastkraftfahrzeuge[i].Beladen(tempGewicht);
    }

    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << "---------- Ausgabe: Autos ----------";
    std::cout << std::endl;
    std::cout << std::endl;

    for (int i = 0; i <3; i++)
    {
        autos[i].Ausgabe();
    }

    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << "---------- Ausgabe: LKWs ----------";
    std::cout << std::endl;
    std::cout << std::endl;

    for (int i = 0; i < 2; i++)
    {
        lastkraftfahrzeuge[i].Ausgabe();
    }


    std::cout << std::endl;
    std::cout << std::endl;

    std::system("pause");

    return(0);
}
#pragma endregion