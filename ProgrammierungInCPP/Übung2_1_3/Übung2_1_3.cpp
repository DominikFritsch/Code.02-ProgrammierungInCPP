/* Projekt: Übung2_1_3 */

/* Aufgabe:

    Schreiben Sie ein Programm, das aus einem Text in einer Datei alle mehrfach vorkommenden
    Leerzeichen entfernt und den Text auf dem Bildschirm ausgibt.

    Die neue Ausgabe soll nun in einer extra Datei gespeichert werden.

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
    char previousChar = 'a';
    char tempChar;

    std::ifstream inputFileStream;
    std::ofstream outputFileStream;

    inputFileStream.open("Eingangsdaten.txt");
    outputFileStream.open("Ausgangsdaten.txt");

    try
    {
        if (!inputFileStream.good()) throw(0);
        else
        {
            while (true)
            {
                inputFileStream.get(tempChar);

                if (!inputFileStream.good()) break;//Konnte Zeichen gelesen werden? Falls nein --> Auslesevorgang beenden
                else
                {
                    if (!(previousChar == ' ' && tempChar == ' '))
                    {
                        //Bildschirmausgabe
                        std::cout << tempChar;
                        //Schreibvorgang
                        outputFileStream.put(tempChar);//Alternativ outputFileStream << tempChar;
                    }
                    previousChar = tempChar;
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
    outputFileStream.close();

    std::cout << std::endl;
    std::cout << std::endl;

    std::system("pause");
    return(0);
}
#pragma endregion
