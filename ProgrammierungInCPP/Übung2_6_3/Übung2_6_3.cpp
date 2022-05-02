/* Projekt: Übung2_6_2 */

/* Aufgabe:

    Erstellen Sie eine Abstrakte Basisklasse "Tier", welche als Attribut einen Namen hat.
    Ein geeigner Konstruktor soll das Attribut befüllen.

    Eine rein virtuelle Methode "machLaut" gibt den Laut des Tieres aus.
    Die Unterklassen Kuh und Hund sollen diese Methode implementieren und geben die Laute "Muuh" und "Wuff" aus.

    Erstellen Sie in Ihrer Main-Funktion jeweils eine Instanz von der Klasse Kuh und Hund.
    Vergeben Sie den Tieren einen Namen. Geben Sie den Namen und dessen Laut aus.

*/

#pragma region HEADER
#include <iostream>
#include <cstdlib>
#include <string>
#pragma endregion

/* KLASSE: Tier */
#pragma region DEFINITION
class Tier
{
public:
    Tier(std::string name)
    {
        this->name = name;
        std::cout << "Tier erstellt.";
        std::cout << std::endl;
    }
    ~Tier()
    {
        std::cout << "Tier gel\x94scht.";
        std::cout << std::endl;
    }
    std::string getName(void)
    {
        return(this->name);
    }
protected:
    std::string name;
    virtual void machLaut(void) = 0;
};
#pragma endregion

/* KLASSE: Kuh */
#pragma region DEFINITION
class Kuh : public Tier
{
public:
    Kuh(std::string name): Tier(name){}

    void machLaut(void)
    {
        std::cout << " Muuh";
        std::cout << std::endl;
    }
};
#pragma endregion

/* KLASSE: Hund*/
#pragma region DEFINITION
class Hund : public Tier
{
public:
    Hund(std::string name) : Tier(name) {}

    void machLaut(void)
    {
        std::cout << " Wuff";
        std::cout << std::endl;
    }
};
#pragma endregion

#pragma region HAUPTPROGRAMM
int main(void)
{
    Kuh k1 = Kuh("Kuh");
    Hund h1 = Hund("Hund");

    std::cout << std::endl;

    std::cout << k1.getName();
    k1.machLaut();

    std::cout << h1.getName();
    h1.machLaut();

    std::cout << std::endl;
    std::system("pause");
    std::cout << std::endl;
    return(0);
}
#pragma endregion