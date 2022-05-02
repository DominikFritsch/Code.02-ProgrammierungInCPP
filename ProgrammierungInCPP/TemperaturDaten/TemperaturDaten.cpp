/* Projekt: TemperaturDaten */
/* Projektbeschreibung:

    Aufgabe 1:  Beispielanwendung prozedurale Programmierung

    Ziel:       Gegenseitige Beurteilung

    Status:     Abgeschlossen

*/

/* Aufgabe:

    Während des Jahres haben Sie die Durchschnittstemperatur der einzelnen Monate erfasst.
    Sie wollen nun ein Programm schreiben, dass Ihnen dabei hilft, diese Daten auszugeben.
    Erstellen Sie ein Programm, das ein Menü ausgibt. Es soll folgende Auswahlmöglichkeiten geben:

    -	Bei Eingabe eines Monats soll die dementsprechende Durchschnittstemperatur ausgegeben werden
        -	Die Eingabe soll einmal als Texteingabe (z.B. Eingabe: „August“)
        -	und als Auswahl (z.B. Auswahl: 8 --> Temperatur von August) realisiert werden
    -	Es soll die Durchschnittstemperatur aller Monate berechnet werden
    -	Es soll der heißeste Monat im Jahr ausgegeben werden
    -	Es sollen alle Monate aufsteigend sortiert mit deren Temperaturen ausgegeben werden
    -	Bei Eingabe von 0 soll eine Verabschiedung ausgegeben werden und das Programm wird beendet
    -	Bei Falscheingabe im Menü soll eine Meldung erscheinen

    Sie können für die Temperaturen der einzelnen Monate fiktive Zahlen benutzen.

*/

#pragma region HEADER
#include <iostream>
#include <cstdlib> //void srand (unsigned int seed); int rand (void); int system( const char *command );
#include <string> //int stoi(const std::string& str);
#include <ctime> //time_t time (time_t* timer);
#pragma endregion

#pragma region DEKLARATION
void userMenu(std::string[], int[]);
int getTemperature(int[],std::string[], std::string);
int getTemperature(int[], int);
float calculateAverageTemperature(int[]);
std::string getHottestMonth(std::string[], int[]);
void sortMonths(std::string[],int[]);
#pragma endregion

#pragma region HAUPTPROGRAMM
int main(void)
{
    //Datensätze
    std::string months[] = { "Januar", "Februar", "M\x84rz", "April", "Mai", "Juni", "Juli", "August", "September", "Oktober", "November", "Dezember" };
    int temperatures[] = { -1, 0, 4, 8, 13, 17, 21, 24, 19, 11, 9, 5 };

    //Benutzeroberfläche
    userMenu(months,temperatures);

    return(0);
}
#pragma endregion

#pragma region DEFINITION
/// <summary>
/// Funktion, welche die Benutzeroberfläche implementiert.
/// </summary>
/// <param name="months"></param>
/// <param name="temperatures"></param>
void userMenu(std::string months[], int temperatures[])
{
    std::string inputAsString;
    std::string inputMonth;
    std::string tempHottestMonth;
    int input;
    int selection;
    int tempTemperature;
    float tempAverageTemperature;


    do
    {
        std::cout << "-------------------- Willkommen --------------------";
        std::cout << std::endl;
        std::cout << std::endl;
        std::cout << "Auswahlm\x94glichkeiten:";
        std::cout << std::endl;
        std::cout << std::endl;
        std::cout << "[1] Ausgabe Durchschnittstemperatur Texteingabe";
        std::cout << std::endl;
        std::cout << "[2] Ausgabe Durchschnittstemperatur Auswahl";
        std::cout << std::endl;
        std::cout << "[3] Ausgabe Durchschnittstemperatur aller Monate";
        std::cout << std::endl;
        std::cout << "[4] Ausgabe hei\xE1 \bester Monat im Jahr";
        std::cout << std::endl;
        std::cout << "[5] Ausgabe der Monate nach Temperatur";
        std::cout << std::endl;
        std::cout << "[0] Programm beenden";
        std::cout << std::endl;
        std::cout << std::endl;

        std::cout << "Auswahl: ";
        std::cin >> inputAsString;
        std::cout << std::endl;
        try
        {
            input = std::stoi(inputAsString);
        }
        catch (const std::exception&)
        {
            input = -1;
        }

        switch (input)
        {
        case 1:
            std::cout << "Eingabe Monat: ";
            std::cin >> inputMonth;

            std::cout << std::endl;

            tempTemperature = getTemperature(temperatures, months, inputMonth);

            if (tempTemperature != -1000) std::cout << "Im Monat " << inputMonth << " hatte es eine durchschnittliche Temperatur von " << tempTemperature << "\370C.";   
            else std::cout << "Falsche Eingabe!";

            break;
        case 2:
            std::cout << "Eingabe Montasauswahl: ";
            std::cin >> selection;

            std::cout << std::endl;

            tempTemperature = getTemperature(temperatures, selection);

            if (tempTemperature != -100) std::cout << "Im Monat " << months[selection-1] << " hatte es eine durchschnittliche Temperatur von " << tempTemperature << "\370C.";
            else std::cout << "Falsche Eingabe!";

            break;
        case 3:
            tempAverageTemperature = calculateAverageTemperature(temperatures);
            std::cout << "Die Durchschnittstemperatur aller Monate betr\x84gt " << tempAverageTemperature << "\370C.";
            break;
        case 4:
            tempHottestMonth = getHottestMonth(months, temperatures);
            std::cout << "Der hei\xE1 \beste Monat im Jahr war " << tempHottestMonth << " mit einer durchschnittlichen Temperatur von " << getTemperature(temperatures,months,tempHottestMonth) << "\370C.";
            break;
        case 5:
            sortMonths(months, temperatures);
            break;
        case 0:
            std::cout << "Programm beendet.";
            break;
        default:
            std::cout << "Falsche Eingabe!";
            break;
        }

        std::cout << std::endl;
        std::cout << std::endl;

        if (input != 0)
        {
            std::system("pause");
            std::system("cls");
        }
        else std::system("pause");

    } while (input !=0);

}
/// <summary>
/// Funktion, welche die Temperatur des übergebenen Monats zurückgibt.
/// </summary>
/// <param name="temperatures"></param>
/// <returns></returns>
int getTemperature(int temperatures[],std::string months[], std::string month)
{
    for (int i = 0; i < 12; i++)
    {
        if (months[i] == month) return(temperatures[i]);
    }

    return(-1000);
}
/// <summary>
/// Funktion, welche die Temperatur der übergebenen Auswahl zurückgibt.
/// </summary>
/// <param name="temperatures"></param>
/// <param name="selection"></param>
/// <returns></returns>
int getTemperature(int temperatures[], int selection)
{
    if (selection > 12 || selection < 1) return(-1000);
    else return(temperatures[selection - 1]);
}
/// <summary>
/// Funktion, welche die Durchschnittstemperatur aller Monate berechnet.
/// </summary>
/// <param name="temperatures"></param>
/// <returns></returns>
float calculateAverageTemperature(int temperatures[])
{
    float tempSum = 0.0f;

    for (int i = 0; i < 12; i++) tempSum += (float)temperatures[i];

    return(tempSum/12);
}
/// <summary>
/// Funktion, welche den Monat mit der heißesten Temperatur zurückgibt.
/// </summary>
/// <param name="months"></param>
/// <param name="temperatures"></param>
/// <returns></returns>
std::string getHottestMonth(std::string months[], int temperatures[])
{
    int hottestTemperature = 0;
    std::string tempHottestMonth;

    for (int i = 0; i < 12; i++)
    {
        if (hottestTemperature < temperatures[i])
        {
            hottestTemperature = temperatures[i];
            tempHottestMonth = months[i];
        }   
    }

    return(tempHottestMonth);
}
/// <summary>
/// Funktion, welche die Monate nach der Temperatur aufsteigend sortiert und ausgibt.
/// </summary>
/// <param name="months"></param>
/// <param name="temperatures"></param>
void sortMonths(std::string months[], int temperatures[])
{
    std::string tempMonth;
    int tempTemperature;

    for (int i1 = 0; i1 < 12 - 1; i1++)
    {
        for (int i2 = 0; i2 < 12 - 1 - i1; i2++)
        {
            if (temperatures[i2] > temperatures[i2 + 1])
            {
                tempTemperature = temperatures[i2 + 1];
                tempMonth = months[i2 + 1];

                temperatures[i2 + 1] = temperatures[i2];
                months[i2 + 1] = months[i2];

                temperatures[i2] = tempTemperature;  
                months[i2] = tempMonth;
            }
        }
    }

    std::cout << "----------------------------------------------------------";
    std::cout << std::endl;
    std::cout << std::endl;

    for (int i = 0; i < 12; i++)
    {
        std::cout << "Monat: " << months[i];
        if (months[i] == "September") std::cout << "\t|\t";
        else std::cout << "\t\t|\t";
        std::cout << "Temperatur: ";
        if (temperatures[i] < 0) std::cout << temperatures[i];
        else std::cout << " " << temperatures[i];
        std::cout << "\370C";
        std::cout << std::endl;
    }
    std::cout << std::endl;
    std::cout << "----------------------------------------------------------";
}
#pragma endregion