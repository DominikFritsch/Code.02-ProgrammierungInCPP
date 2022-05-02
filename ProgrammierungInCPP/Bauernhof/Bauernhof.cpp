/* Projekt: Bauernhof */
/* Projektbeschreibung: Bauer Max hat einen Bauernhof mit Enten und Schweinen. Diese will er verkaufen. */

/* Aufgabe 1:  Schreiben Sie ein C++-Programm, das den Nutzer am Bauernhof begrüßt. */

/* Aufgabe 2:

    Ergänzen Sie das Programm um folgende Variablen:

    -	Gewicht
    -	Tagespreis
    -	Einnahme

    In der Variablen Gewicht (Ganzzahl) soll das Gewicht des zu verkaufenden Schweins gespeichert werden.
    In der Variable Tagespreis (Dezimalzahl) soll der Tagespreis für das Schwein gespeichert werden.
    Beide Variablen werden im Dialog vom Nutzer über die Konsole eingegeben.
    Die Einnahme errechnet sich dann aus Gewicht * Tagespreis.

    Geben Sie die Höhe der Einnahme auf dem Bildschirm aus.
*/

/* Aufgabe 3:

    Ergänzen Sie das Programm um folgende zwei Funktionen:

    1. Daten_erfassen() -> Für die Eingabe des Gewichts und des Preises
    2. Einnahme_berechnen() -> Berechnet die Einnahme und gibt diese aus

    Die Variablen können global definiert werden.
    Rufen Sie die beiden Funktionen auf.

*/

/* Aufgabe 4:

    Ergänzen Sie das Programm um folgendes:

    Erstellen Sie mit Hilfe einer switch-Anweisung ein Benutzermenü,
    welches folgende 3 Funktionen aufruft:

    -	1: Tier anlegen ()
    -	2: Tier anzeigen ()
    -	3: Tier verkaufen (Tiernummer)
    -	0: Programm beenden

    Das Menü soll solange wiedererscheinen, bis der Nutzer die Zahl für „Programm beenden“ eingibt (Do-While-Schleife).

    Beim Anlegen sollen folgende Daten gespeichert werden:
    -	Tierart
    -	Tiernummer
    -	Gewicht

    Beim Anzeigen sollen folgende Daten angezeigt werden:
    -	Tierart
    -	Tiernummer
    -	Gewicht
    -	ob das Tier noch im Bestand ist

    Beim Verkauf soll geprüft werden, ob das Tier noch im Bestand ist und ob die gespeicherte Tiernummer mit der eingegebenen Tiernummer übereinstimmt. 
    Es soll folgendes funktionieren:

    -	Eingabe des Tagespreises
    -	Einnahmen erhöhen sich (Gewicht * Tagespreis)
    -	Ausgabe der Gesamteinnahmen
    -	Tier ist anschließend nicht mehr im Bestand

*/

/* Aufgabe 5:

    Auf dem Bauernhof können maximal 50 Tiere leben.
    Legen Sie ein Feld an, dass 50 Tiernummern aufnehmen kann und 
    schreiben Sie eine For-Schleife, welches die Nummern 1-50 im Feld ablegt.

    Geben Sie anschließend die eingegeben Nummern und ihre Position im Feld in einer For-Schleife aus.

*/

/* Aufgabe 6:

    Wandeln Sie den Quellcode in ein objektorientiertes Programm um.
    Erzeugen Sie in main ein Tierobjekt und rufen Sie für dieses Objekt die Methoden auf.
    
    void TierAnlegen(void);
    void TierAnzeigen(void);
    void TierVerkaufen(int);
    float Einnahme_berechnen(float);

*/

/* Aufgabe 7:

    Legen Sie 2 Instanzen der Klasse Tier als Array an.
    Belegen Sie jede Instanz mit Daten und geben Sie anschließend die Daten von allen Instanzen auf dem Bildschirm aus.

*/

/* Aufgabe 8:

    Verwenden Sie zur Initialisierung der Instanzen einen Konstruktor mit Elementinitialisierungsliste
    und einen Standardkonstruktor, welcher die Daten abfragt.

    Erstellen Sie dann in der main-Funktion zwei Objekte. Verwenden Sie hier die beiden Konstruktoren.
    Rufen Sie anschließend die Methode Einnahme_berechnen auf.

*/

#pragma region HEADER
#include <iostream> //Header-Datei: std::cout, std::endl
#include <cstdlib>  //Header-Datei: std::system(const char*)
#include <string>
#pragma endregion

#pragma region DEKLARATION: KLASSE
class Tier
{
private:
    std::string Tierart = " ";
    int Tiernummer = 0;
    int Gewicht = 0;
    bool ImBestand = false;

public:
    Tier();
    Tier(std::string a, int b, int c, bool d);
    void TierAnlegen(void);
    void TierAnzeigen(void);
    void TierVerkaufen(int);
    float Einnahme_berechnen(float);

};
#pragma endregion

#pragma region DEFINITION: KONSTRUKTOREN
/// <summary>
/// Standardkonstruktor
/// </summary>
Tier::Tier()
{
    Tierart = " ";
    Tiernummer = 0;
    Gewicht = 0;
    ImBestand = false;

    std::cout << "Standardkonstruktor: Tier erstellt.";
    std::cout << std::endl;
}
Tier::Tier(std::string Tierart, int Tiernummer, int Gewicht, bool ImBestand) : Tierart(Tierart), Tiernummer(Tiernummer), Gewicht(Gewicht),ImBestand(ImBestand)
{
    std::cout << "Parameterkonstruktor: Tier erstellt.";
    std::cout << std::endl;
}
#pragma endregion



#pragma region DEFINITION: METHODEN
/// <summary>
/// Methode, welche die Daten eines Tiers erfasst.
/// </summary>
/// <param name=""></param>
void Tier::TierAnlegen(void)
{
    std::cout << "Eingabe Tierart:\t";
    std::cin >> Tierart;
    std::cout << "Eingabe Tiernummer:\t";
    std::cin >> Tiernummer;
    std::cout << "Eingabe Gewicht in kg:\t";
    std::cin >> Gewicht;

    ImBestand = true;
}
/// <summary>
/// Methode, welche die Daten eines erfassten Tiers anzeigt.
/// </summary>
/// <param name=""></param>
void Tier::TierAnzeigen(void)
{
    std::cout << "Tierart:\t" << Tierart;
    std::cout << std::endl;
    std::cout << "Tiernummer:\t" << Tiernummer;
    std::cout << std::endl;
    std::cout << "Gewicht:\t" << Gewicht;
    std::cout << std::endl;
    std::cout << "Im Bestand:\t" << (ImBestand ? "Ja" : "Nein");
    std::cout << std::endl;
}
/// <summary>
/// Methode, welche es dem Benutzer ermöglicht ein Tier zu verkaufen.
/// </summary>
/// <param name="tempTiernummer"></param>
void Tier::TierVerkaufen(int tempTiernummer)
{
    float Tagespreis = 0.0f;

    if (Tiernummer == tempTiernummer)
    {
        if (ImBestand)
        {
            std::cout << "Eingabe Tagespreis in EUR/kg:\t";
            std::cin >> Tagespreis;
            std::cout << std::endl;
            std::cout << "H\x94he der Einnahme in EUR:\t" << Einnahme_berechnen(Tagespreis);
            ImBestand = false;
        }
        else
        {
            std::cout << std::endl;
            std::cout << "Das angegebene Tier ist nicht mehr im Bestand.";
        }
    }
    else
    {
        std::cout << std::endl;
        std::cout << "Die eingegebene Tiernummer existiert nicht.";
    }

}
/// <summary>
/// Methode, welche den Verkaufspreis eines Tiers berechnet und ausgibt.
/// </summary>
/// <param name=""></param>
float Tier::Einnahme_berechnen(float Tagespreis)
{
    return ( (float)Gewicht * Tagespreis );
}
#pragma endregion

#pragma region DEKLARATION: FUNKTIONEN
void BenutzerEingabe(Tier);
#pragma endregion

#pragma region DEFINITION: FUNKTIONEN
/// <summary>
/// Funktion, welche als Hauptmenü dient.
/// </summary>
/// <param name=""></param>
void BenutzerEingabe(Tier obj)
{
    int input;
    do
    {
        std::cout << "-------------------- Hauptmen\x81 --------------------";
        std::cout << std::endl;
        std::cout << std::endl;
        std::cout << "1:\tTier anlegen";
        std::cout << std::endl;
        std::cout << "2:\tTier anzeigen";
        std::cout << std::endl;
        std::cout << "3:\tTier verkaufen";
        std::cout << std::endl;
        std::cout << "0:\tProgramm beenden";
        std::cout << std::endl;
        std::cout << std::endl;

        std::cout << "Auswahl: ";
        std::cin >> input;
        std::cout << std::endl;

        switch (input)
        {
        case 1:
            std::cout << "-------------------- Tier anlegen --------------------";
            std::cout << std::endl;
            std::cout << std::endl;
            obj.TierAnlegen();
            break;
        case 2:
            std::cout << "-------------------- Tier anzeigen --------------------";
            std::cout << std::endl;
            std::cout << std::endl;
            obj.TierAnzeigen();
            break;
        case 3:
            std::cout << "-------------------- Tier verkaufen --------------------";
            std::cout << std::endl;
            std::cout << std::endl;
            int tempTiernummer;
            std::cout << "Eingabe Tiernummer: ";
            std::cin >> tempTiernummer;
            obj.TierVerkaufen(tempTiernummer);
            break;
        case 0:
            std::cout << "Programm beendet.";;
            break;
        default:
            std::cout << "Falsche Auswahl.";
            break;
        }
        std::cout << std::endl;
        std::cout << std::endl;
    } while (input != 0);

}
#pragma endregion

#pragma region HAUPTPROGRAMM
int main(void)
{
    std::cout << "Willkommen am Bauernhof von Bauer Max";
    std::cout << std::endl;
    std::cout << std::endl;

    Tier t1 = Tier::Tier();
    Tier t2 = Tier::Tier();
    Tier t3 = Tier::Tier("Schwein", 100, 20, true);

    t1.TierAnlegen();
    std::cout << std::endl;

    t1.TierAnzeigen();
    std::cout << std::endl;
    t3.TierAnzeigen();
    std::cout << std::endl;

    BenutzerEingabe(t2);

    std::cout << std::endl;

    std::system("pause");

    return(0);
}
#pragma endregion
