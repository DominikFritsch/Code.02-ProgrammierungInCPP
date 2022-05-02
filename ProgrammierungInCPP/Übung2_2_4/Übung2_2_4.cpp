/* Projekt: Übung2_2_4 */

/* Aufgabe:

    Schreiben Sie eine Funktion "stringlength", an die ein char-Array, welches 50 Zeichen aufnehmen kann,
    übergeben wird, und die Länge dieser Zeichenkette zurückliefert.
    
    Nach Eingabe der Zeichenkette soll die Anzahl an Zeichen ausgegeben werden.

    Tipp: Das Ende einer Zeichenkette wird mit \0 gekennzeichnet.

*/

#pragma region HEADER
#include <iostream>
#include <cstdlib>
#include <cstdlib>
#pragma endregion

#pragma region DEKLARATION: FUNKTION
int stringlength(char*);
#pragma endregion

#pragma region HAUPTPROGRAMM
int main(void)
{
    char word[50];

    std::cout << "Eingabe Zeichenkette: ";
    std::cin >> word;

    std::cout << "Die Eingabe " << word << " hat " << stringlength(word) << " Zeichen.";

    std::cout << std::endl;
    std::cout << std::endl;
    std::system("pause");
    return(0);
}
#pragma endregion

#pragma region DEFINITION: FUNKTION
int stringlength(char* a)
{
    std::size_t i = 0;

    while (*(a + i) != '\0')++i;
    return(i);
}
#pragma endregion


