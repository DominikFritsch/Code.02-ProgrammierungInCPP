/* Projekt: Kontrollfrage1_1_9 */

/* Aufgabe:

    Schreiben Sie ein Programm, das die vier Jahreszeiten, jede in eine neue Zeile, auf dem
    Bildschirm ausgibt.

*/

#pragma region HEADER
#include <iostream>
#include <cstdlib>
#pragma endregion

#pragma region HAUPTPROGRAMM
int main(void)
{
    std::cout << "Winter";
    std::cout << std::endl;
    std::cout << "Fr\x81hling";
    std::cout << std::endl;
    std::cout << "Sommer";
    std::cout << std::endl;
    std::cout << "Herbst";
    std::cout << std::endl;
    std::cout << std::endl;

    std::system("pause");

    return(0);
}
#pragma endregion


