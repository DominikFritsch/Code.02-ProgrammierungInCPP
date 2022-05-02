/* Projekt: Übung2_4_1 */

/* Aufgabe:

    Legen Sie je 3 Instanzen der Klasse PKW und LKW an. (Programm: Kursteil 1: Vererbung)

    Die Instanzen sollen dynamisch (als Zeiger über new) angelegt werden.

    Die Daten sollen durch den Benuzter über die Konsole eingegeben werden.

    Tipp: Lösung über Schleife (for oder while oder do while).

    Geben Sie die Daten anschließend (über Schleife) von allen Instanzen auf dem Bildschirm aus.

*/

#include <cstddef>
#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

class Fahrzeug
{
protected:
    string marke = "";
    string kennzeichen = "";
    int ps = 0;
    int baujahr = 0;

public:

    //Standardkonstruktor
    Fahrzeug() {}

    //Konstruktor mit Elementinitialisierungsliste
    Fahrzeug(string mr, string kenn, int ps, int bj) : marke(mr), kennzeichen(kenn), ps(ps), baujahr(bj) {}

    void datenausgeben() {
        cout << "Marke: " << marke;
        cout << "Kennzeichen: " << kennzeichen << endl;
        cout << "Anzahl PS: " << ps << endl;
        cout << "Baujahr: " << baujahr << endl;
    }

    //damit abgeleitete Klasse Zugriff auf die privaten Elemente bekommt müssen diese entweder als protected definiert werden, oder wir wenden Datenkapselung an und definieren sog. getter Methoden
    string getMarke() { return marke; }
    string getKennzeichen() { return kennzeichen; }
    int getPS() { return ps; }
    int getBaujahr() { return baujahr; }
};

class PKW : public Fahrzeug {
private:
    float maxGeschwindigkeit = 0.0f;
public:
    PKW() 
    {
        std::cout << "Standardkonstruktor PKW";
        std::cout << std::endl;
    }
    ~PKW()
    {
        std::cout << "Dekonstruktor PKW";
        std::cout << std::endl;
    }
    PKW(string m, string kenn, int ps, int bj, float max) : Fahrzeug(m, kenn, ps, bj), maxGeschwindigkeit(max) 
    {
        std::cout << "Parameterkonstruktor PKW";
        std::cout << std::endl;
    }

    void datenausgeben() 
    {
        cout << "Marke: " << getMarke() << endl;
        cout << "Kennzeichen: " << getKennzeichen() << endl;
        cout << "Anzahl PS: " << getPS() << endl;
        cout << "Baujahr: " << getBaujahr() << endl;
        cout << "Maximale Geschwindigkeit: " << maxGeschwindigkeit << endl;
    }

    void dateneingeben() 
    {
        std::cout << "Eingabe Marke: ";
        std::cin >> (*this).marke;
        std::cout << "Eingabe Kennzeichen: ";
        std::cin >> this->kennzeichen;
        std::cout << "Eingabe PS: ";
        std::cin >> this->ps;
        std::cout << "Eingabe Baujahr: ";
        std::cin >> this->baujahr;
        std::cout << "Eingabe maximale Geschwindigkeit: ";
        std::cin >> this->maxGeschwindigkeit;
    }

};

class LKW : public Fahrzeug {
private:
    float maxLadung = 0.0f;
    int anzahlRaeder = 0;
public:
    LKW() 
    {
        std::cout << "Standardkonstruktor LKW";
        std::cout << std::endl;
    }
    ~LKW()
    {
        std::cout << "Dekonstruktor LKW";
        std::cout << std::endl;
    }
    LKW(string m, string kenn, int ps, int bj, float max, int anz) : Fahrzeug(m, kenn, ps, bj), maxLadung(max), anzahlRaeder(anz) 
    {
        std::cout << "Parameterkonstruktor LKW";
        std::cout << std::endl;
    }

    void datenausgeben() {
        cout << "Marke: " << getMarke() << endl;
        cout << "Kennzeichen: " << getKennzeichen() << endl;
        cout << "Anzahl PS: " << getPS() << endl;
        cout << "Baujahr: " << getBaujahr() << endl;
        cout << "Maximale Ladung: " << maxLadung << endl;
        cout << "Anzal Raeder: " << anzahlRaeder << endl;
    }
};

int main() {

    //Fahrzeug LKW
    PKW* pPKWs[3];
    LKW* pLKWs[3];

    for (std::size_t i = 0; i < 3; i++)
    {
        std::cout << "----------Eingabe PKW " << i + 1 << "----------";
        std::cout << std::endl;
        pPKWs[i] = new PKW();
        pPKWs[i]->dateneingeben();
    }

    for (std::size_t i = 0; i < 3; i++)
    {   
        std::string tempMarke = "";
        std::string tempKennzeichen = "";
        int tempPS = 0;
        int tempBaujahr = 0;
        float tempMaximaleLadung = 0.0f;
        int tempAnzahlRaeder = 0;

        std::cout << "----------Eingabe LKW " << i + 1 << "----------";
        std::cout << std::endl;

        std::cout << "Eingabe Marke: ";
        std::cin >> tempMarke;
        std::cout << "Eingabe Kennzeichen: ";
        std::cin >> tempKennzeichen;
        std::cout << "Eingabe PS: ";
        std::cin >> tempPS;
        std::cout << "Eingabe Baujahr: ";
        std::cin >> tempBaujahr;
        std::cout << "Eingabe maximale Ladung: ";
        std::cin >> tempMaximaleLadung;
        std::cout << "Eingabe Anzahl Raeder: ";
        std::cin >> tempAnzahlRaeder;

        pLKWs[i] = new LKW(tempMarke,tempKennzeichen,tempPS,tempBaujahr,tempMaximaleLadung,tempAnzahlRaeder);
    }


    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << "--------------------AUSGABE: PKW--------------------";
    std::cout << std::endl;
    std::cout << std::endl;

    for (int i = 0; i < 3; i++)
    {
        pPKWs[i]->datenausgeben();
    }

    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << "--------------------AUSGABE: LKW--------------------";
    std::cout << std::endl;
    std::cout << std::endl;

    for (int i = 0; i < 3; i++)
    {
        (*pLKWs[i]).datenausgeben();
    }

    std::cout << std::endl;
    std::cout << std::endl;

    for (size_t i = 0; i < 3; i++)
    {
        delete pPKWs[i];
        delete pLKWs[i];
    }

    std::cout << std::endl;
    system("pause");
    return 0;
};
