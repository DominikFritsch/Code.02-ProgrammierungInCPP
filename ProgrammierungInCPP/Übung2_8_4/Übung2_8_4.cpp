/* Projekt Übung2_8_4 */

/* Aufgabe:

    Erstellen Sie eine Template-Klasse calc, welches zwei Attributa hat.
    Erstellen Sie einen geeigneten Konstruktor, der die Attribute befüllt.

    Eine Methode "add" und "multiply" soll die beiden Attribute addieren bzw. multiplizieren und den Wert zurückgeben.
    Sollte bei der Addition ein String übergeben werden, dann soll der String spezialisiert werden.
    Hierbei soll ein Leerzeichen zwischen den beiden Zeichenketten eingefügt werden.

*/

#pragma region HEADER
#include <iostream>
#include <cstdlib>
#include <string>
#pragma endregion

/* TEMPLATE: Klasse calc*/
#pragma region DEKLARATION
template <class A_Type> class calc
{
private:
    A_Type var1, var2;
public:
    calc(A_Type v1, A_Type v2) : var1(v1), var2(v2) {};
    A_Type multiply();
    A_Type add();
};
#pragma endregion

#pragma region DEFINITION
template <class A_Type> A_Type calc<A_Type>::multiply()
{
    return (var1 * var2);
}
template <class A_Type> A_Type calc<A_Type>::add()
{
    return (var1 + var2);
}

template <>std::string calc<std::string>::add()
{
    return (var1 + " " + var2);
}
#pragma endregion

#pragma region HAUPTPROGRAMM
int main(void)
{
    calc <double> double_var(10.5, 14.5);
    std::cout << "Addition: " << double_var.add();
    std::cout << std::endl;
    std::cout << "Multiplikation: " << double_var.multiply();
    std::cout << std::endl;
    calc <int> int_var(5, 9);
    std::cout << "Addition: " << int_var.add();
    std::cout << std::endl << "Multiplikation: " << int_var.multiply();
    std::cout << std::endl;
    calc <std::string> string_var("Hallo", "Welt");
    std::cout << "Stringverkn\x81pfung: " << string_var.add();
    std::cout << std::endl;

    std::cout << std::endl;
    std::system("pause");
    return 0;
}
#pragma endregion