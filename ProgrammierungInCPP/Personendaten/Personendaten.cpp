/* Projekt: Personendaten */
/* Projektbeschreibung: Ein einfaches Programm, um Personendaten zu manipulieren. */

/* Aufgabe 1:

    Erstellen Sie ein Programm, welches folgende Ausgabe erzeuegen soll:

    Vorname: Max
    Nachname: Mustermann
    Alter: 21

    Vorname, Nachname und Alter soll jeweils durch eine eigenen Anweisung ausgegeben werden.



    Erstellen Sie zusätzlich folgende Ausgabe:

    Vorname: Erika
    Nachname: Engel
    Alter: 18

    Diese Ausgabe soll in einer einzigen Anweisung erzeugt werden.
*/

#include <iostream> //Header-Datei: std::cout, std::endl
#include <cstdlib>  //Header-Datei: std::system(const char*)

int main(void)
{
    std::cout << "Vorname:" << "\t" << "Max";
    std::cout << std::endl;
    std::cout << "Nachname:" << "\t" << "Mustermann";
    std::cout << std::endl;
    std::cout << "Alter:" << "\t\t" << "21";
    std::cout << std::endl;
    std::cout << std::endl;

    std::cout << "-----------------------------";
    std::cout << std::endl;
    std::cout << std::endl;

    std::cout << "Vorname:\tErika\nNachname:\tEngel\nAlter:\t\t21\n\n";

    std::cout << "-----------------------------";
    std::cout << std::endl;
    std::cout << std::endl;

    std::system("pause");

    return(0);
}