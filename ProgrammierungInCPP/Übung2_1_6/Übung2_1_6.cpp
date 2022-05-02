/* Projekt: Übung2_1_6 */

/* Aufgabe:

    Schreiben Sie ein Programm, wo der Benutzer solange einen Dividend und einen Divisor eingeben kann,
    bis er bei einer Abfrage (Ja/Nein) eingibt, dass er keine Berechnung mehr durchführen will.

    Bei jedem Schleifendurchlauf soll die Division stattfinden. Sollte der Divisor 0 sein,
    tritt eine Fehlermeldung auf.

    Außerdem soll jedes (gültige) Ergebnis mit Berechnung in eine Datei abgespeichert werden.

    Beispiel Inhalt der Datei:

    10/5=2
    40/10=4

    Wenn das Programm neu gestartet wird, werden die neuen Berechnungen in der Datei hinten angefügt.
    
    Sollte die Datei schreibgeschützt sein, wird eine Fehlermeldung geworfen.

    Beim Verlassen des Programms soll nochmal der Inhalt der Datei erscheinen.

*/

#pragma region HEADER
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#pragma endregion

#pragma region HAUPTPROGRAMM
int main(void)
{
    float dividend;
    float divisor;
    bool input;

    std::ofstream outputFileStream;

    outputFileStream.open("Results.txt", std::ios::app);

    try
    {
        if (!outputFileStream.good()) throw(0);
        else
        {
            do
            {
                try
                {
                    std::cout << "Eingabe Dividend: ";
                    std::cin >> dividend;

                    std::cout << "Eingabe Divisor: ";
                    std::cin >> divisor;

                    if (divisor == 0) throw(0);
                    else
                    {
                        float tempResult = dividend / divisor;

                        //Ausgabe Konsole
                        std::cout << dividend << "/" << divisor << " = " << tempResult;
                        //Schreibvorgang Datei
                        outputFileStream << dividend << "/" << divisor << " = " << tempResult << std::endl;
                    }
                }
                catch(int i)
                {
                    switch (i)
                    {
                    case 0:
                        std::cout << "Divisor 0 nicht erlaubt.";
                        break;
                    }
                }
                catch (...)
                {
                    std::cout << "Unbekannter Fehler.";
                }

                std::cout << std::endl;
                std::cout << "Weitere Berechnung? [0] Nein [1] Ja: ";
                std::cin >> input;
                std::cout << std::endl;

            } while (input == true);
        }
    }
    catch (...)
    {
        std::cout << "Fehler beim \x99 \bffnen der Datei.";
    }

    outputFileStream.close();


    try
    {
        std::string tempText;
        std::ifstream inputFileStream;

        inputFileStream.open("Results.txt");

        while (true)
        {
            if (!inputFileStream.good()) break;
            else
            {
                std::getline(inputFileStream, tempText);
                std::cout << tempText;
                std::cout << std::endl;
            }      
        }
    }
    catch (...)
    {
        std::cout << "Fehler beim \x99 \bffnen der Datei.";
    }

    std::cout << std::endl;
    std::system("pause");
    return(0);
}
#pragma endregion




