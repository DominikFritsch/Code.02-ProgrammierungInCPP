/* Projekt Übung2_8_1 */

/* Aufgabe:

    Erstellen Sie eine Template-Funktion, welche zwei Variablen vom gleichen Datentypen addiert bzw. Strings verknüpft.
    Der Benutzer hat folgende Auswahlmöglichkeiten:

    [1] Ganzzahl addieren
    [2] Gleitkommazahl addieren
    [3] Zeichekette verknüpfen

    Nach der Auswahl gibt der Benutzer die beiden Werte ein und die Funktion gibt die Addition/Verknüpfung zurück.
    Anschließend wird das Ergebnis ausgegeben.

*/

#pragma region HEADER
#include <iostream>
#include <cstdlib>
#include <string>
#pragma endregion

/* TEMPLATE: Funktion*/
#pragma region DEKLARATION
template <class T> T add(T, T);
#pragma endregion

#pragma region DEFINITION
template <class T> T add(T a, T b)
{
    return(a + b);
}
#pragma endregion

#pragma region HAUPTPROGRAMM
int main(void)
{
    int selection;
    int tempInput1;
    int tempInput2;
    float tempInput3;
    float tempInput4;
    std::string tempInput5;
    std::string tempInput6;

    do
    {
        std::cout << "[1] Ganzzahl addieren";
        std::cout << std::endl;
        std::cout << "[2] Gleitkommazahl addieren";
        std::cout << std::endl;
        std::cout << "[3] Zeichenkette addieren";
        std::cout << std::endl;
        std::cout << "[4] Beenden";
        std::cout << std::endl;
        std::cout << std::endl;
        std::cout << "Auswahl: ";
        std::cin >> selection;
        std::cout << std::endl;

        switch (selection)
        {
        case 1:
            std::cout << "Eingabe Ganzzahl 1: ";
            std::cin >> tempInput1;
            std::cout << "Eingabe Ganzzahl 2: ";
            std::cin >> tempInput2;

            std::cout << "Ergebnis = " << add(tempInput1, tempInput2);

            break;
        case 2:
            std::cout << "Eingabe Gleitkommazahl 1: ";
            std::cin >> tempInput3;
            std::cout << "Eingabe Gleitkommazahl 2: ";
            std::cin >> tempInput4;

            std::cout << "Ergebnis = " << add(tempInput3, tempInput4);

            break;
        case 3:
            std::cout << "Eingabe Zeichenkette 1: ";
            std::cin >> tempInput5;
            std::cout << "Eingabe Zeichenkette 2: ";
            std::cin >> tempInput6;

            std::cout << "Ergebnis = " << add(tempInput5, tempInput6);
            break;
        case 4:
            std::cout << "Programm beendet.";
            break;
        default:
            std::cout << "Falsche Eingabe.";
            break;
        }

        std::cout << std::endl;
        std::cout << std::endl;
        std::system("pause");
        std::system("cls");


    } while (selection != 4);

    return(0);
}
#pragma endregion
