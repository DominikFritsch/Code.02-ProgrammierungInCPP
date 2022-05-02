/* Projekt Übung2_8_3 */

/* Aufgabe:

    Erstellen Sie eine Template-Funktion. Der erste Übergabeparameter ist ein Array (beliebiger Datentyp) und
    der zweite beinhaltet die Anzahl an Elementen vom Array.

    Berechnen Sie in der Funktion den Durchschnitt, geben Sie diesen zurück und anschließend aus.
    Das Ergebnis soll immer eine Gleitkommazahl sein!

    Testen Sie die Funktion mit einem Int-Array und einem Float-Array.

*/

#pragma region HEADER
#include <iostream>
#include <cstdlib>
#pragma endregion

/* TEMPLATE: Funktion */
#pragma region DEFINITION
template<class T> double Durchschnitt(T tArray[], int nElements)
{
    T tSum = NULL;

    for (int index = 0; index < nElements; ++index)
    {
        tSum += tArray[index];
    }

    // Egal welcher Datentyp tSum ist, konvertiere es zu double
    return (double(tSum) / nElements);
}
#pragma endregion

#pragma region HAUPTPROGRAMM
int main(void)
{
    int  IntArray[5] = { 100, 200, 400, 500, 1000 };
    double FloatArray[3] = { 1.55f, 5.44f, 12.36f };

    std::cout << Durchschnitt(IntArray, 5);
    std::cout << std::endl;
    std::cout << Durchschnitt(FloatArray, 3);
    std::cout << std::endl;

    std::cout << std::endl;
    std::system("pause");
    return(0);
}
#pragma endregion
