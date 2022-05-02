/* Projekt: Übung2_1_5 */

/* Aufgabe:

    Berechnen Sie das Volumen eines Quaders in einer Funktionen.
    
    Sollte einer der eingegebenen Werte negativ oder Null sein,
    dann soll eine Fehlermeldung mit throw geworfen werden.
    
    Sind die Werte korrekt, dann wird das Ergebnis ausgegeben.

*/

#pragma region HEADER
#include <iostream>
#include <cstdlib>
#include <cstddef>
#include <cmath>
#pragma endregion

#pragma region DEKLARATION: FUNKTION
float calculateVolumeCuboid(float);
#pragma endregion

#pragma region HAUPTPROGRAMM
int main(void)
{
    float input;

    try
    {
        std::cout << "Kantenl\x84nge: ";
        std::cin >> input;

        if (input <= 0) throw(0);

        std::cout << "Volumen Quader: " << calculateVolumeCuboid(input);
    }
    catch (int i)
    {
        switch (i)
        {
        case 0:
            std::cout << "Falsche Eingabe.";
            break;
        default:
            std::cout << "Sonstiger Fehler.";
            break;
        }  
    }

    std::cout << std::endl;
    std::cout << std::endl;
    std::system("pause");
    return(0);
}
#pragma endregion

#pragma region DEFINITION: FUNKTION
float calculateVolumeCuboid(float edgeLength)
{
    return((float)std::pow(edgeLength,3));
}
#pragma endregion


