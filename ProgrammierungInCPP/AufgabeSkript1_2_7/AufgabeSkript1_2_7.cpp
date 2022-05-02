/* Projekt: AufgabeSkript1_2_7 */

/* Aufgabe:

    Es sei folgendes C++-Programm gegeben.

    Bestimmen Sie die Werte folgender Ausgabeanweisungen und überprüfen Sie ihre Lösung mit dem Ergebnis
    der Konsolenausgabe:

    int x=10;
    std::cout << "x = " << x++ << std::endl;
    std::cout << "x = " << x << std::endl;
    std::cout << "x = " << ++x << std::endl;
    std::cout << "x = " << x << std::endl;

*/

/* Antwort:

    x = 10; --> 11
    x = 11;
    x = 12;
    x = 12;

*/

#pragma region HEADER
#include <iostream>
#include <cstdlib>
#pragma endregion

#pragma region HAUPTPROGRAMM
int main(void)
{
    int x = 10;
    std::cout << "x = " << x++ << std::endl;
    std::cout << "x = " << x << std::endl;
    std::cout << "x = " << ++x << std::endl;
    std::cout << "x = " << x << std::endl;
    std::cout << std::endl;

    std::system("pause");

    return(0);
}
#pragma endregion
