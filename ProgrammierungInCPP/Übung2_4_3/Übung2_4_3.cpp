/* Projekt: Übung2_4_3 */

/* Aufgabe:

    Erstellen Sie ein Array mit einem vom Benutzer eingegebenen Speicherbereich.
    Der Benutzer soll dann solange beliebige Zahlen eingeben können, welche im Array abgespeichert werden.

    Geben Sie die hinterlegten Zahlen nochmal aus.
    Geben Sie zum Schluss den Speicher vom Array frei.

*/

#pragma region HEADER
#include <iostream>
#include <cstdlib>
#include <cstddef>
#pragma endregion

#pragma region HAUPTPROGRAMM

#pragma endregion


int main(void)
{
    int n;

    std::cout << "Gr\x94\xE1 \be Array: ";
    std::cin >> n;
    std::cout << std::endl;

    float* pArray = new float[n];

    for (int i = 0; i < n; i++)
    {
        std::cout << "Eingabe Zahl " << i + 1 << ": ";
        std::cin >> *(pArray + i);
    }

    std::cout << std::endl;
    std::cout << "----------AUSGABE----------";
    std::cout << std::endl;
    std::cout << std::endl;

    for (int i = 0; i < n; i++)
    {
        std::cout << "Zahl " << i + 1 << " = " << *(pArray + i);
        std::cout << std::endl;
    }

    delete[] pArray;

    std::cout << std::endl;
    std::system("pause");
    return(0);
}
