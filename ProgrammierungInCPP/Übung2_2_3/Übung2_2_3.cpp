/* Projekt: Übung2_2_3 */

/* Aufgabe:

    Gegeben ist folgendes Array:

    int numbers[] = {10,20,30};

    Übergeben Sie den Anfang und das Ende vom Array als Pointer einer Funktion.
    Erhöhen Sie dort solange jeden Wert um 1, bis das Ende erreicht wurde.
    
    Geben Sie anschließend die neuen Werte (11,21,31) in der main-Funktion aus.
    Die Ausgabe erfolgt wieder anhand des Anfangs und dem Ende des Arrays.

    Tipp: Arrays werden wie folgt als Pointer übergeben:

    meineFunktion(numbers+2);

*/

#pragma region HEADER
#include <iostream>
#include <cstdlib>
#include <cstddef>
#pragma endregion

#pragma region DEKLARATION: FUNKTION
void increaseValue(int*,int*);
#pragma endregion

#pragma region HAUPTPROGRAMM
int main(void)
{
    int numbers[] = { 10,20,30 };
    increaseValue(numbers, numbers + 2);

    for (int i = 0; i < 3; i++)
    {
        std::cout << "Wert " << i + 1 << ":\t = " << numbers[i];
        std::cout << std::endl;
    }

    std::cout << std::endl;
    std::cout << std::endl;
    std::system("pause");
    return(0);
}
#pragma endregion

#pragma region DEFINITION: FUNKTION
/// <summary>
/// Funktion, welche ein übergebenes Array durchläuft und die Werte erhöht.
/// </summary>
/// <param name="start"></param>
/// <param name="end"></param>
void increaseValue(int* start, int* end)
{
    std::size_t i = 0;

    while ((start +i) < end +1)
    {
        *(start + i) += 1;
        ++i;
    }
}
#pragma endregion


