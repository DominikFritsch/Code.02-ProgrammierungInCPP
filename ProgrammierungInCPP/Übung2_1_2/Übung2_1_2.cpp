/* Projekt: Übung2_1_2 */

/* Aufgabe:

    Schreiben Sie ein Programm, das einen Text aus einer Datei einliest.
    Anschließend soll der Benutzer einen Buchstaben eingeben können. 
    
    Das Programm soll ermitteln, wie oft der Buchstabe im Text vorkommt.

*/

#pragma region HEADER
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <cstddef>
#pragma endregion

#pragma region HAUPTPROGRAMM
int main(void)
{
    std::size_t counter = 0;
    char tempChar;
    char inputChar;
    std::ifstream inputFileStream;

    std::cout << "Buchstabe: ";
    std::cin >> inputChar;


    inputFileStream.open("Daten.txt");

    try
    {
        if (!inputFileStream.good()) throw(0);
        else
        {
            while (true)
            {
                if (!inputFileStream.good()) break;
                else
                {
                    inputFileStream.get(tempChar);
                    if (inputChar == tempChar) ++counter;
                }
            }
        }
    }
    catch (int i)
    {
        switch (i)
        {
        case 0:
            std::cout << "Fehler beim \x99 \bffnen der Datei.";
            break;
        default:
            std::cout << "Fehler";
            break;
        }
        std::cout << std::endl;
    }

    inputFileStream.close();

    std::cout << "Der Buchstabe " << inputChar << " kommt in der Datei Daten.txt " << counter << "x vor.";


    std::cout << std::endl;
    std::cout << std::endl;

    std::system("pause");
    return(0);
}
#pragma endregion