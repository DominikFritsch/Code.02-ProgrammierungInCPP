/* Projekt: Kontrollfrage1_3_3 */

/* Aufgabe:

    Schreiben Sie ein Programm, das von 1 bis 100 zählt. 
    Die Zahlen sollen durch Kommas getrennt auf dem Bildschirm ausgegeben werden. 
    Vermeiden Sie, dass hinter der letzten und vor der ersten Zahl ein Komma steht.

*/

#pragma region HEADER
#include <iostream>
#include <cstdlib>
#pragma endregion

#pragma region HAUPTPROGRAMM
int main(void)
{
    int i = 1;

    while (i <=100)
    {
        if (i != 100) std::cout << i << ", ";
        else std::cout << i;

        ++i;
    }

    std::cout << std::endl;
    std::cout << std::endl;

    std::system("pause");

    return(0);
}
#pragma endregion