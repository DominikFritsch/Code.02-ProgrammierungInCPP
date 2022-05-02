/* Projekt: Kontrollfrage1_3_5 */

/* Aufgabe:

    Erstellen Sie ein Programm, das die Fakult�t einer Zahl berechnet. 
    Bei ung�ltiger Eingabe (negative Werte oder Bereichs�berschreitung) soll der Fehlerwert 0 zur�ckgegeben werden. 
    
    Hinweis: die Fakult�t von 0 ist 1

*/

#pragma region HEADER
#include <iostream>
#include <cstdlib>
#pragma endregion

#pragma region DEKLARATION
int fac(int);
#pragma endregion

#pragma region HAUPTPROGRAMM
int main(void)
{
    int input;
    int result;

    std::cout << "Eingabe Zahl: ";
    std::cin >> input;
    std::cout << std::endl;
    result = fac(input);

    if (result == 0) std::cout << "Negative Zahl wurde eingegeben oder der zul\x84ssige Bereich \x81 \bberschritten.";
    else std::cout << "Die Fakult\x84t der Zahl " << input << " betr\x84gt: " << result;

    std::cout << std::endl;
    std::cout << std::endl;

    std::system("pause");

    return(0);
}
#pragma endregion

#pragma region DEFINITION
/// <summary>
/// Funktion, welche die Fakult�t des �bergebenen Parameters bestimmt.
/// </summary>
/// <param name="n"></param>
/// <returns></returns>
int fac(int n)
{
    int i1 = 1;
    double i2 = 1.0;

    if (n < 0) return(0);
    else
    {
        while (n > 1)
        {
            i1 *= n;
            i2 *= (double)n;

            if (i1 != i2) return(0);

            --n;
        }

        return(i1);
    }
}
#pragma endregion



