/* Projekt: Übung2_2_6 */

/* Aufgabe:

    Schreiben Sie ein Programm, das eine Funktion "prosumo" enthält. Dieser Funktion wird ein
    Array übergeben. Sie liefert die Summe und das Produkt der Arrayelemente zurück.

    Erstellen Sie die Funktion auf Basis von Zeigern. Die beiden Ergebnisse werden mittels Zeiger ermittelt.
    Bei der Übergabe darf ein fester Wert übergeben werden, welche die Anzahl an Elementen des Arrays angibt.

*/

#pragma region HEADER
#include <iostream>
#include <cstdlib>
#include <cstddef>
#pragma endregion

#pragma region MAKRO
#define MAX 5
#pragma endregion


#pragma region DEKLARATION:FUNKTION
void prosumo(int*,int*,int*, int);
#pragma endregion


#pragma region HAUPTPROGRAMM
int main(void)
{
    int numbers[MAX] = {1,2,3,4,5};
    int ergSum = 0;
    int ergProduct = 1;

    int* pSum = &ergSum;
    int* pProduct = &ergProduct;

    prosumo(numbers, pSum, pProduct, MAX);

    std::cout << "Summe: " << ergSum << "\t|\t" << "Produkt: " << ergProduct;

    std::cout << std::endl;
    std::cout << std::endl;
    std::system("pause");
    return(0);
}
#pragma endregion

#pragma region DEFINITION: FUNKTION
/// <summary>
/// Funktion, welche die Summe und das Produkt der Arrayelemente berechnet.
/// </summary>
/// <param name="a"></param>
/// <param name="size"></param>
void prosumo(int* pArray, int* pSum, int* pProduct, int size)
{
    for (int i = 0; i < size; i++)
    {
        *pSum += *(pArray + i);
        *pProduct *= *(pArray + i);
    }
}
#pragma endregion
