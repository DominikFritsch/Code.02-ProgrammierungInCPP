/* Projekt: Personenverwaltung */
/* Projektbeschreibung: Sie arbeiten für die Firma CodeGood und möchten ein Personenverwaltungsprogramm erstellen. */

/* Aufgabe 1:

    Erstellen Sie ein Programm mit einer Klasse namens Person, die einige Daten (Name,
    Vorname, Alter) einer Person speichert. Eine Methode namens einlesen in der Klasse die Attribute befüllen.

    Eine Methode in der Klasse namens vergleich soll erstellt werden.
    Eine Person ruft diese Methode auf und zusätzlich soll als Übergabeparameter
    eine weitere Person vorhanden sein.

    Dort soll überprüft und ausgegeben werden, welcher der beiden Personen älter ist.

*/
#pragma region HEADER
#include <iostream>
#include <cstdlib>
#include <string>
#pragma endregion

#pragma region DEKLARATION: KLASSEN
class Person
{
private:
    std::string name = " ";
    std::string vorname=" ";
    int alter = 0;
public:
    std::string getName(void);
    std::string getVorname(void);
    int getAlter(void);
    void setName(std::string);
    void setVorname(std::string);
    void setAlter(int);
    void datenEinlesen(void);
    void vergleich(Person);
};
#pragma endregion

#pragma region DEFINTION: METHODEN
std::string Person::getName(void)
{
    return(Person::name);
}
std::string Person::getVorname(void)
{
    return(Person::vorname);
}
int Person::getAlter(void)
{
    return(Person::alter);
}
void Person::setName(std::string name)
{
    Person::name = name;
}
void Person::setVorname(std::string vorname)
{
    Person::vorname = vorname;
}
void Person::setAlter(int alter)
{
    Person::alter = alter;
}
void Person::datenEinlesen(void)
{
    std::string tempName;
    std::string tempVorname;
    int tempAlter;

    std::cout << "Eingabe Name: ";
    std::cin >> tempName;
    std::cout << "Eingabe Vorname: ";
    std::cin >> tempVorname;
    std::cout << "Eingabe Alter: ";
    std::cin >> tempAlter;

    Person::setName(tempName);
    Person::setVorname(tempVorname);
    Person::setAlter(tempAlter);
}
void Person::vergleich(Person obj)
{
    if (Person::getAlter() < obj.getAlter())
    {
        std::cout << "Person " << obj.getVorname() << ", " << obj.getName() << " ist \x84lter.";
    }
    else if(Person::getAlter() > obj.getAlter())
    {
        std::cout << "Person " << Person::getVorname() << ", " << Person::getName() << " ist \x84lter.";
    }
    else
    {
        std::cout << "Person " << Person::getVorname() << ", " << Person::getName() << " und Person " << obj.getVorname() << ", " << obj.getName() << " sind gleich alt.";
    }
}
#pragma endregion

#pragma region HAUPTPROGRAMM
int main(void)
{
    Person personen[2];

    personen[0].datenEinlesen();
    std::cout << "-----------------------------------------------";
    std::cout << std::endl;
    personen[1].datenEinlesen();
    std::cout << "-----------------------------------------------";
    std::cout << std::endl;
    personen[0].vergleich(personen[1]);
    std::cout << std::endl;
    std::cout << std::endl;

    std::system("pause");

    return(0);
}
#pragma endregion
