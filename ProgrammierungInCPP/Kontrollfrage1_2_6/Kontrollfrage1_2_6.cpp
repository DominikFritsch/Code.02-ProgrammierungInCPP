/* Projekt: Kontrollfrage1_2_6 */

/* Aufgabe:

    Schreiben Sie ein Programm, das den Variablen x und y die Werte 25 und -25 zuweist und diese dann ausgibt!

*/

#pragma region HEADER
#include <iostream>
#include <cstdlib>
#pragma endregion

#pragma region HAUPTPROGRAMM
int main(void)
{
    int x = 25;
    int y = -25;
    std::cout << "x-Wert = " << x << " und y-Wert = " << y;

    std::cout << std::endl;
    std::cout << std::endl;

    std::system("pause");

    return(0);
}
#pragma endregion
