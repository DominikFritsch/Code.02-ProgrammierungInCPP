/* Projekt: AufgabeSkript1_9_6 */

/* Aufgabe:

    Es sei folgendes C++-Programm gegeben:

    #include <iostream>
    #include <cstdlib>
    using namespace std;
    class Konto
    {
     private:
        int KtoNr;
        //...
     public:
        // Defaultkonstruktor
        Konto () : KtoNr(999)
        { cout << "1: Konto(), KtoNr: " << KtoNr << endl; }
        // Parameterkonstruktor
        Konto (int kNr) : KtoNr(kNr)
        { cout << "2: Konto(int), KtoNr: " << KtoNr << endl; }
        // Destruktor
        ~Konto()
        { cout << "3: ~Konto(), KtoNr: " << KtoNr << endl; }
    };

    class Girokonto : public Konto
    {
     private:
        float Dispo;
     public:
        Girokonto () : Dispo(2000)
        { cout << "4: - Girokonto(), Disp.: " << Dispo << endl; }
        Girokonto (float d) : Dispo(d)
        { cout << "5: - Girokonto(float), Disp.: " << Dispo << endl; }
        Girokonto (int kNr, float d) : Konto(kNr), Dispo(d)
        { cout << "6: - Girokonto(int,float), Disp.: " << Dispo << endl; }
        ~Girokonto ()
        { cout << "7: - ~Girokonto(), Disp.: " << Dispo << endl; }
    };

    int main()
    {
        Girokonto a, b(5500.0), c(123,1000.0);
        cout << "Weiter mit Taste ........." << endl;
        system("pause");
    }

    Was gibt das Programm auf dem Bildschirm aus?

*/

/* Antwort:

    1: Konto(), KtoNr: 999
    4: - Girokonto(), Disp.: 2000
    1: Konto(), KtoNr: 999
    5: - Girokonto(float), Disp.: 5500
    2: Konto(int), KtoNr: 123
    6: - Girokonto(int,float), Disp.: 1000
    Drücken Sie eine beliebige Taste . . .
    7: - ~Girokonto(), Disp.: 1000
    3: ~Konto(), KtoNr: 123
    7: - ~Girokonto(), Disp.: 5500
    3: ~Konto(), KtoNr: 999
    7: - ~Girokonto(), Disp.: 2000
    3: ~Konto(), KtoNr: 999

*/


#include <iostream>
#include <cstdlib>
using namespace std;
class Konto
{
private:
    int KtoNr;
    //...
public:
    // Defaultkonstruktor
    Konto() : KtoNr(999)
    {
        cout << "1: Konto(), KtoNr: " << KtoNr << endl;
    }
    // Parameterkonstruktor
    Konto(int kNr) : KtoNr(kNr)
    {
        cout << "2: Konto(int), KtoNr: " << KtoNr << endl;
    }
    // Destruktor
    ~Konto()
    {
        cout << "3: ~Konto(), KtoNr: " << KtoNr << endl;
    }
};

class Girokonto : public Konto
{
private:
    float Dispo;
public:
    Girokonto() : Dispo(2000)
    {
        cout << "4: - Girokonto(), Disp.: " << Dispo << endl;
    }
    Girokonto(float d) : Dispo(d)
    {
        cout << "5: - Girokonto(float), Disp.: " << Dispo << endl;
    }
    Girokonto(int kNr, float d) : Konto(kNr), Dispo(d)
    {
        cout << "6: - Girokonto(int,float), Disp.: " << Dispo << endl;
    }
    ~Girokonto()
    {
        cout << "7: - ~Girokonto(), Disp.: " << Dispo << endl;
    }
};

int main()
{
    Girokonto a, b(5500.0), c(123, 1000.0);
    system("pause");
}