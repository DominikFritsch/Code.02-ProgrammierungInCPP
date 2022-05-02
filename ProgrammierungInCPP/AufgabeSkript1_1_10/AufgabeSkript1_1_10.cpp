/* Projekt: AufgabeSkript1_1_10 */

/* Aufgabe:

    Schreiben Sie ein Programm, das den Namen und die Anschrift wie folgt auf der Konsole ausgibt:

    Moritz Mustermann
    Am Stadtplatz 1

    94469 Deggendorf

    Das Fenster soll nach einem Tastendruck geschlossen werden.
    Kommentieren Sie jede Zeile.
*/

//Einbindung Header-Datei --> std::system(const char*)
#include <cstdlib>
//Einbindung Header-Datei --> std::cout, std::endl
#include <iostream>

//Einstiegspunkt in das C++-Programm
int main(void)
//Anfang Anweisungsblock
{
    //Textausgabe mit Zeilenumbruch
    std::cout << "Moritz Mustermann" << std::endl;
    std::cout << "Am Stadtplatz 1" << std::endl;
    //Reiner Zeilenumbruch
    std::cout << std::endl;
    //Textausgabe mit Zeilenumbruch
    std::cout << "94469 Deggendorf" << std::endl;
    //Reiner Zeilenumbruch
    std::cout << std::endl;
    //Schließen der Konsole erst nach Tasteneingabe
    std::system("pause");
    //Rückgabewert
    return(0);

    //Ende Anweisungsblock
}
