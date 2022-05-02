/* Projekt: Übung2_2_2 */

/* Aufgabe:

    Schreiben Sie eine Funktion "swap", die die Werte von zwei eingegebenen Integern-Zahlen vertauscht.

    Die Zahlen sollen als Referenz übergeben werden (die geänderten Werte in der Funktion werden
    somit auch in main abgeändert).

    Schreiben Sie eine einfache main-Funktion dazu, die swap testet.

*/

#pragma region HEADER
#include <iostream>
#include <cstdlib>
#include <cstddef>
#pragma endregion

#pragma region DEKLARATION: FUNKTION
void swapVariable(int, int);
void swapReference(int&, int&);
void swapPointer(int*, int*);
#pragma endregion


#pragma region HAUPTPROGRAMM
int main(void)
{
    int a = 10;
    int b = 100;

    swapVariable(a, b);//Erwartet: a=10 | b=100
    std::cout << "Variable a: " << a << "\t|\t" << "Variable b: " << b;
    std::cout << std::endl;
    std::cout << std::endl;

    swapReference(a, b);//Erwartet: a=100 | b=10
    std::cout << "Variable a: " << a << "\t|\t" << "Variable b: " << b;
    std::cout << std::endl;
    std::cout << std::endl;

    swapPointer(&a, &b);//Erwartet: a=10 | b=100
    std::cout << "Variable a: " << a << "\t|\t" << "Variable b: " << b;
    std::cout << std::endl;
    std::cout << std::endl;

    std::system("pause");
    return(0);
}
#pragma endregion

#pragma region DEFINITION: FUNKTION
/// <summary>
/// Funktion, welche die übergebenen Integer-Werte tauscht. (VARIABLE)
/// </summary>
/// <param name="a"></param>
/// <param name="b"></param>
void swapVariable(int a, int b)
{
    int temp = 0;

    temp = a;
    a = b;
    b = temp;

    // --> a und b werden nicht im Hauptprogramm geändert.
}
/// <summary>
/// Funktion, welche die übergebenen Integer-Werte tauscht. (REFERENZ)
/// </summary>
/// <param name="a"></param>
/// <param name="b"></param>
void swapReference(int& a , int& b)
{
    int temp = 0;

    temp = a;
    a = b;
    b = temp;

    // --> a und b werden im Hauptprogramm geändert.
}
/// <summary>
/// Funktion, welche die übergebenen Integer-Werte tauscht. (ZEIGER)
/// </summary>
/// <param name="a"></param>
/// <param name="b"></param>
void swapPointer(int*a, int*b)
{
    int temp = 0;

    temp = *a;
    *a = *b;
    *b = temp;

    // --> a und b werden im Hauptprogramm geändert.
}
#pragma endregion
