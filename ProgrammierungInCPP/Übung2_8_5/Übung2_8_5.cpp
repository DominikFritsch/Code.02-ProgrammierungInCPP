/* Projekt Übung2_8_5 */

/* Aufgabe:

    Es sollen drei Template-Funktionen erstellt werden.

    Die erste Template Funktion soll den Inhalt eines Array ausgeben.
    Die zweite Template Funktion sortiert das Array.
    Die dritte Template Funktion tauscht (für das Sortieren) die jeweiligen Werte. Verwenden Sie hier die Methode Call-By-Reference.

    Es soll zuerst die Ausgabe, dann wird das Array sortiert und anschließend erfolgt die sortierte Ausgabe.
    Testen Sie Ihr Programm anhand eines Integer-Arrays und einem String-Array.

    Es sollen 5 Zufallszahlen generiert, im Array hinterlegt, dann ausgegeben, dann sortiert und zum Schluss die sortierte Ausgabe ausgegeben.

    Beim String-Array können Sie z.B. 3 Zeichenketten im Array direkt hinterlegen.

    Tipp:
    Der Template-Funktion "Sortieren" und "Ausgeben" müssen Sie ein Array und dessen Anzahl an Elemente übergeben.
    Der Template-Funktion "Tausche" werden die Adressen der zu vertauschten Variablen übergeben. 
    In der Funktion wird mit Pointer gearbeitet.

*/

#pragma region HEADER
#include <iostream>
#include <cstdlib>
#include <ctime>
#pragma endregion

/* TEMPLATE: Funktion */
#pragma region DEKLARATION
template <class Item> void bubble_sort(Item a[], int laenge);
template <class Item> void swap(Item* a, Item* b);
template <class Item> void display_array(Item randVar, int laenge);
#pragma endregion

#pragma region DEFINITION
template <class Item> void bubble_sort(Item a[], int laenge)
{
    int i, j;
    for (i = 1; i < laenge; i++)
    {
        for (j = 0; j < laenge - 1; j++)
        {
            if (a[j] > a[j + 1])
                swap(&a[j], &a[j + 1]);
        }
    }

}

template <class Item> void swap(Item* a, Item* b)
{
    Item temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

template <class Item> void display_array(Item randVar, int laenge)
{
    for (int j = 0; j < laenge; j++)
    {
        std::cout << randVar[j] << " ";
    }
}
#pragma endregion

#pragma region HAUPTPROGRAMM

#pragma endregion


int main(void)
{
    const int size = 5;

    std::srand((unsigned)std::time(NULL));

    int randNum[size];
    

    for (int i = 0; i < size; i++)
    {
        randNum[i] = 1 + std::rand() % 10;
    }

    display_array(randNum, size);

    std::cout << std::endl;
    std::cout << "sortiert...";
    std::cout << std::endl;

    bubble_sort(randNum, size);

    display_array(randNum, size);

    std::cout << std::endl;
    std::cout << std::endl;

    std::string randString[3] = { "Text2","Text3","Text1" };

    display_array(randString, 3);

    std::cout << std::endl;
    std::cout << "sortiert...";
    std::cout << std::endl;

    bubble_sort(randString, 3);

    display_array(randString, 3);

    std::cout << std::endl;
    std::cout << std::endl;

    system("pause");
    return 0;

}

