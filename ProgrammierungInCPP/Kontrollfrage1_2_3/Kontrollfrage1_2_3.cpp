/* Projekt: Kontrollfrage1_2_3 */

/* Aufgabe:

    Erstellen Sie ein Programm, das Sie nach zwei Zahlen fragt (positiv oder negative Werte sollen möglich sein), 
    diese multipliziert und dann eine dritte Zahl, die auch eingegeben werden soll, addiert.

*/

#pragma region HEADER
#include <iostream>
#include <cstdlib>
#pragma endregion

#pragma region DEKLARATION
float multiply(float, float);
float add(float, float);
#pragma endregion

#pragma region HAUPTPROGRAMM
int main(void)
{
    float number1;
    float number2;
    float number3;
    float product;
    float sum;

    std::cout << "Eingabe Zahl 1: ";
    std::cin >> number1;
    std::cout << "Eingabe Zahl 2: ";
    std::cin >> number2;
    std::cout << "Eingabe Zahl 3: ";
    std::cin >> number3;
    product = multiply(number1, number2);
    sum = add(product, number3);
    std::cout << std::endl;

    std::cout << "N = (" << number1 << " * " << number2 << ") + " << number3 << " = " << sum;

    std::cout << std::endl;
    std::cout << std::endl;

    std::system("pause");

    return(0);
}
#pragma endregion

#pragma region DEFINITION
/// <summary>
/// Funktion, welche zwei übergebene Zahlen multipliziert.
/// </summary>
/// <param name="number1"></param>
/// <param name="number2"></param>
/// <returns></returns>
float multiply(float a, float b)
{
    return (a * b);
}
/// <summary>
/// Funktion, welche zwei übergebene Zahlen addiert.
/// </summary>
/// <param name="a"></param>
/// <param name="b"></param>
/// <returns></returns>
float add(float a, float b)
{
    return(a + b);
}
#pragma endregion
