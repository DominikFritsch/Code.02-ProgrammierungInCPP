/* Projekt Übung2_8_2 */

/* Aufgabe:

    Erstellen Sie eine inline Template-Funktion, welche das Minimum zweier Übergabeparameter zurückgibt.
    Testen Sie die Funktion mit zwei Integer-Variablen und zwei Char-Variablen.

*/

#pragma region HEADER
#include <iostream>
#include <cstdlib>
#include <string>
#pragma endregion

/* TEMPLATE: Funktion*/
#pragma region DEKLARATION
template<class T> inline T compare(T, T);
#pragma endregion

#pragma region DEFINITION
template<class T> inline T compare(T a, T b)
{
    if (a > b) return (b);
    else if (a < b) return (a);
    else return(0);
}
#pragma endregion

#pragma region HAUPTPROGRAMM
int main(void)
{
    int a = 2;
    int b = 3;
    int c = 2;

    char d = 'A';
    char e = 'B';
    char f = 'A';

    std::cout << "Minimum von " << a << " und " << b << " = " << compare(a, b);
    std::cout << std::endl;
    std::cout << "Minimum von " << b << " und " << a << " = " << compare(b, a);
    std::cout << std::endl;
    std::cout << "Minimum von " << a << " und " << c << " = " << compare(a, c);
    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << "Minimum von " << d << " und " << e << " = " << compare(d, e);
    std::cout << std::endl;
    std::cout << "Minimum von " << e << " und " << d << " = " << compare(e, d);
    std::cout << std::endl;
    std::cout << "Minimum von " << d << " und " << f << " = " << compare(d, f);

    std::cout << std::endl;
    std::cout << std::endl;
    std::system("pause");
    return(0);
}
#pragma endregion


