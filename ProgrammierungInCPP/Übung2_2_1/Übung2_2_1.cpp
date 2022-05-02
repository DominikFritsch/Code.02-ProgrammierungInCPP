/* Projekt: Übung2_2_1 */

/* Aufgabe:

    Machen Sie sich mit Referenzen und Zeiger vertraut.

    Legen Sie je eine Instanz der Klasse PKW und LKW als Zeiger an (Kursteil 1: Vererbung).

    Verwenden Sie
        a) Zeiger
        b) Referenzen

    Geben Sie anschließend die Daten auf dem Bildschirm aus.

*/

#include "cstdlib"
#include "iostream" 

using namespace std;

class Fahrzeug
{
private:
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
    PKW() {}
    PKW(string m, string kenn, int ps, int bj, float max) : Fahrzeug(m, kenn, ps, bj), maxGeschwindigkeit(max) {}
    void datenausgeben() {
        cout << "Marke: " << getMarke() << endl;
        cout << "Kennzeichen: " << getKennzeichen() << endl;
        cout << "Anzahl PS: " << getPS() << endl;
        cout << "Baujahr: " << getBaujahr() << endl;
        cout << "Maximale Geschwindigkeit: " << maxGeschwindigkeit << endl;
    }

};

class LKW : public Fahrzeug {
private:
    float maxLadung = 0.0f;
    int anzahlRaeder = 0;
public:
    LKW() {}
    LKW(string m, string kenn, int ps, int bj, float max, int anz) : Fahrzeug(m, kenn, ps, bj), maxLadung(max), anzahlRaeder(anz) {}

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

    //Fahrzeug Objekt
    Fahrzeug f1("Audi", "AO RT 333", 110, 2010);
    //Fahrzeug Referenz
    Fahrzeug& f2 = f1;
    //Fahrzeug Zeiger
    Fahrzeug* f3 = &f1;
    
    std::cout << "--------------------OBJEKT--------------------";
    std::cout << std::endl;
    std::cout << std::endl;
    f1.datenausgeben();
    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << "--------------------REFERENZ--------------------";
    std::cout << std::endl;
    std::cout << std::endl;
    f2.datenausgeben();
    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << "--------------------ZEIGER--------------------";
    std::cout << std::endl;
    std::cout << std::endl;
    f3->datenausgeben();

    //PKW Objekt
    PKW p1("Opel", "KA WA 11", 78, 2004, 150);
    //PKW Referenz
    PKW& p2 = p1;
    //PKW Zeiger
    PKW* p3 = &p1;

    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << "--------------------OBJEKT--------------------";
    std::cout << std::endl;
    std::cout << std::endl;
    p1.datenausgeben();
    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << "--------------------REFERENZ--------------------";
    std::cout << std::endl;
    std::cout << std::endl;
    p2.datenausgeben();
    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << "--------------------ZEIGER--------------------";
    std::cout << std::endl;
    std::cout << std::endl;
    p3->datenausgeben();

    //LKW Objekt
    LKW l1("Mercedes", "WA SS 44", 99, 2007, 5.4f, 8);
    //LKW Referenz
    LKW& l2 = l1;
    //LKW Zeiger
    LKW* l3 = &l1;

    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << "--------------------OBJEKT--------------------";
    std::cout << std::endl;
    std::cout << std::endl;
    l1.datenausgeben();
    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << "--------------------REFERENZ--------------------";
    std::cout << std::endl;
    std::cout << std::endl;
    l2.datenausgeben();
    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << "--------------------ZEIGER--------------------";
    std::cout << std::endl;
    std::cout << std::endl;
    l3->datenausgeben();
    std::cout << std::endl;
    std::cout << std::endl;

    system("pause");
    return 0;
};