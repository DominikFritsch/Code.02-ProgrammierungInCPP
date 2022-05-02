/* Projekt: Datentypen */
/* Projektbeschreibung:

    Ein einfaches Programm, um sich mit der Continue-Anweisung und dem Modulo-Operator vertraut zu machen.

*/

/* Aufgabe 1:

    Erstellen Sie eine Schleife, in welcher Sie alle Zahlen von 1 bis 100 ausgeben,
    welche durch die Zahl 2 teilbar sind.

    Verwenden Sie hierfür die continue-Anweisung, um die Zahlen zu überspringen, 
    welche nicht durch die Zahl 2 teilbar sind!

    Nähere Informationen zur continue-Anweisung finden Sie auf folgender Seite: 
    https://en.cppreference.com/w/cpp/language/continue

*/

#pragma region HEADER
#include <iostream>
#include <cstdlib>
#pragma endregion

#pragma region DEKLARATION
void printEvenNumbers(void);
#pragma endregion

#pragma region DEFINITION
/// <summary>
/// Funktion, welche die Zahlen von 1 bis 100 ausgibt, die durch 2 teilbar sind.
/// </summary>
/// <param name=""></param>
void printEvenNumbers(void)
{
    for (int i = 1; i <= 100; i++)
    {
        if (i % 2 != 0) continue;
        else
        {
            std::cout << "Zahl:\t" <<i;
            std::cout << std::endl;
        }
    }
}
/// <summary>
/// Funktion, welche die Zahlen von 1 bis 100 ausgibt, die nicht durch 2 teilbar sind.
/// </summary>
/// <param name=""></param>
void printOddNumbers(void)
{
    for (int i = 1; i <= 100; i++)
    {
        if (i % 2 == 0) continue;
        else
        {
            std::cout << "Zahl:\t" << i;
            std::cout << std::endl;
        }
    }
}
#pragma endregion

#pragma region HAUPTPROGRAMM
int main(void)
{
    std::cout << "---------- Gerade Zahlen ----------";
    std::cout << std::endl;
    std::cout << std::endl;
    printEvenNumbers();
    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << "---------- Ungerade Zahlen ----------";
    std::cout << std::endl;
    std::cout << std::endl;
    printOddNumbers();
    std::cout << std::endl;
    std::cout << std::endl;

    std::system("pause");

    return(0);
}
#pragma endregion