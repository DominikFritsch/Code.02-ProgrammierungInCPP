/* Projekt: Übung2_6_1 */

/* Aufgabe:

    Eine Klasse "Telefon" hat eine Rufnummer und eine Farbe, welche an die Unterklasse vererbt werden.
    Außerdem gibt es die Unterklasssen "MobilTelefon" und "KabelTelefon".
    Mobiltelefone haben zusätzlich ein Netz, Kabeltelefone eine Kabellänge.

    Erstellen Sie für jede Klasse eine Methode "datenausgeben", welche alle Attribute (der Ober-/Unerklasse) ausgibt.

    Erstellen Sie für jede Klasse ein dynamisches Objekt.
    Weisen Sie die Instanzen von MobilTelefon und KabelTelefon der Instanz von Telefon zu.
    Rufen Sie NUR von der Telefon-Instanz die Methode datenausgeben auf.

    Was wird ausgegeben?

    Wandeln Sie die Methode datenausgeben in der Klasse Telefon in eine virtuelle Methode um.

    Was wird jetzt ausgegeben?

*/

/* Antwort:

    Methode nicht virtuell:
    Die Methode des Zeigertyps "Telefon" wird 2x aufgerufen.
    Es werden die Attribute des Objekttyps verwendet.

    Methode virtuell:
    Die Methode des Objekttyps "Mobiltelefon" wird aufgerufen.
    Die Methode des Objekttyps "Kabeltelefon" wird aufgerufen.
    Es werden weiterhin die Attribute des Objekttyps verwendet.

*/

#pragma region HEADER
#include <iostream>
#include <cstdlib>
#include <string>
#pragma endregion

#pragma region DEKLARATION: KLASSE Telefon
class Telefon
{
protected:
    std::string rufNummer;
    std::string farbe;
public:
    //Konstruktor
    Telefon(std::string rufNummer, std::string farbe): rufNummer(rufNummer), farbe(farbe){}
    //Methoden
    virtual void datenausgeben(void)
    {
        std::cout << "Ich bin ein Telefon.";
        std::cout << std::endl;
        std::cout << std::endl;
        std::cout << "Ausgabe Rufnummer: " << this->rufNummer;
        std::cout << std::endl;
        std::cout << "Ausgabe Farbe: " << this->farbe;
        std::cout << std::endl;
    }
};
#pragma endregion

#pragma region DEFINITION: KLASSE Mobiltelefon
class Mobiltelefon : public Telefon
{
private:
    std::string netz;
public:
    //Konstruktor
    Mobiltelefon(std::string rufNummer, std::string farbe, std::string netz) : Telefon(rufNummer, farbe), netz(netz) {}
    //Methoden
    void datenausgeben(void)
    {
        std::cout << "Ich bin ein Mobiltelefon.";
        std::cout << std::endl;
        std::cout << std::endl;
        std::cout << "Ausgabe Rufnummer: " << this->rufNummer;
        std::cout << std::endl;
        std::cout << "Ausgabe Farbe: " << this->farbe;
        std::cout << std::endl;
        std::cout << "Ausgabe Netz: " << this->netz;
        std::cout << std::endl;
    }
};
#pragma endregion

#pragma region DEFINITION: KLASSE Kabeltelefon
class Kabeltelefon : public Telefon
{
private:
    int kabelLaenge;
public:
    //Konstruktor
    Kabeltelefon(std::string rufNummer, std::string farbe, int kabelLaenge) : Telefon(rufNummer, farbe), kabelLaenge(kabelLaenge) {}
    //Methoden
    void datenausgeben(void)
    {
        std::cout << "Ich bin ein Kabeltelefon.";
        std::cout << std::endl;
        std::cout << std::endl;
        std::cout << "Ausgabe Rufnummer: " << this->rufNummer;
        std::cout << std::endl;
        std::cout << "Ausgabe Farbe: " << this->farbe;
        std::cout << std::endl;
        std::cout << "Ausgabe Kabell\x84nge: " << this->kabelLaenge;
        std::cout << std::endl;
    }
};
#pragma endregion


#pragma region HAUPTPROGRAMM
int main(void)
{
    Telefon* t = new Telefon("0123-45678", "Blau");
    Mobiltelefon* mT = new Mobiltelefon("0123-45678", "Schwarz", "Telekom");
    Kabeltelefon* kT = new Kabeltelefon("0123-45678", "Gelb", 2);

    t = mT;
    t->datenausgeben();
    std::cout << std::endl;
    std::cout << std::endl;
    t = kT;
    t->datenausgeben();

    std::cout << std::endl;
    std::system("pause");
    return(0);
}
#pragma endregion