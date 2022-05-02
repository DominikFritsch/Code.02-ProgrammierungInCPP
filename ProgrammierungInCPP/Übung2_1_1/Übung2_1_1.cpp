/* Projekt: Übung2_1_1 */

/* Aufgabe:
    
    Erstellen Sie eine Textdatei mit beliebigem Inhalt.

    Lesen Sie anschließend den Inhalt der Datei aus und geben Sie in der Konsole
    die einzelnen Zeilen aus.

    Geben Sie zusätzlich zu jeder Ausgabe die Zeilennummer mit an.

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
    std::size_t i = 0;
    std::string tempText = "";
    std::ifstream inputFileStream;

    inputFileStream.open("Daten.txt", std::ios::out);

    try
    {
        if (!inputFileStream.good()) throw(0);
        else
        {
            while (!inputFileStream.eof())//Delimeter entspricht Leerzeichen
            {
                if (!inputFileStream.good()) throw(1);
                else
                {
                    ++i;
                    std::getline(inputFileStream, tempText);

                    std::cout << i << ". Zeile:\t" << tempText;
                    std::cout << std::endl;
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
        case 1:
            std::cout << "Fehler beim Lesen einer Zeile.";
            break;
        default:
            std::cout << "Fehler";
            break;
        }
        std::cout << std::endl;
    }

    inputFileStream.close();

    std::cout << std::endl;
    std::cout << std::endl;

    std::system("pause");
    return(0);
}
#pragma endregion



