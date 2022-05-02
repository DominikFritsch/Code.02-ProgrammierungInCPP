/* Projekt: Einkaufsliste */

/* Projektbeschreibung:
    Aufgabe 2:  Beispielanwendung prozedurale Programmierung
    Ziel:       Gegenseitige Beurteilung
    Status:     Abgeschlossen
*/

/* Aufgabe:
    Erstellen Sie eine Einkaufsliste für maximal 10 Produkte.
    Hierfür soll der Produktname und Preis eingegeben werden und anschließend in einem Feld abgespeichert werden.
    Erstellen Sie ein Menü, was folgende Funktionen hat:

    -	Positionen anzeigen
    -	Positionen sortieren
    -	Beenden

    Im Menü soll außerdem die aktuelle Anzahl an Positionen angezeigt werden.
    Die Sortierung erfolgt anhand des Preises (der Name soll dementsprechend mitsortiert werden).
*/

/* Erläuterung:
    Menü                                void userMenu(void);
    Position erfassen                   int capturePosition(std::string[], float[], int);
    Positionen anzeigen                 void showPositions(std::string[], float[], int);
    Positionen sortieren                void sortPositions(std::string[], float[], int);
    Überwachung Benutzereingabe 1       int userInputAsInteger(std::string);
    Überwachung Benutzereingabe 2       float userInputAsFloat(std::string);
*/

#pragma region HEADER
#include <iostream>
#include <cstdlib> //void srand (unsigned int seed); int rand (void); int system( const char *command );
#include <string> //int stoi(const std::string& str);
#include <ctime> //time_t time (time_t* timer);
#include <iosfwd> //typedef streamsize;
#include <iomanip> //setprecision(int);
#pragma endregion

#pragma region KONSTANTEN
const int MAX = 10;
#pragma endregion

#pragma region DEKLARATION
void userMenu(void);
int capturePosition(std::string[], float[], int);
void showPositions(std::string[], float[], int);
void sortPositions(std::string[], float[], int);
int userInputAsInteger(std::string);
float userInputAsFloat(std::string);
#pragma endregion

#pragma region HAUPTPROGRAMM
/// <summary>
/// Funktion, welche den Einstiegspunkt in das Programm darstellt.
/// </summary>
/// <param name=""></param>
/// <returns></returns>
int main(void)
{
    //Benutzeroberfläche aufrufen
    userMenu();

    //Auf Benutzereingabe warten, bevor Programm beendet wird
    std::system("pause");

    //Programm beenden
    return(0);
}
#pragma endregion

#pragma region DEFINITION
/// <summary>
/// Funktion, welche die Benutzeroberfläche implementiert.
/// </summary>
/// <param name=""></param>
void userMenu(void)
{
    //Lokale Variablen
    std::string selectionAsString;
    std::string names[MAX] = {" "};

    int selection = -1;
    int currentPositions = 0;
    int remainingPositions;

    float prices[MAX] = {0.0f};


    //Implementierung Benutzeroberfläche
    do
    {
        remainingPositions = MAX - currentPositions;

        //Auswahlmöglichkeiten und Anzeige der verbleibenden Positionen
        std::cout << "-------------------- Willkommen --------------------";
        std::cout << std::endl;
        std::cout << std::endl;
        std::cout << "Positionen:";
        std::cout << std::endl;
        std::cout << "Maximum: " << MAX << " | " << "Belegt: " << currentPositions << " | " << "Verbleibend: " << remainingPositions;
        std::cout << std::endl;
        std::cout << std::endl;
        std::cout << std::endl;
        std::cout << "Auswahlm\x94glichkeiten:";
        std::cout << std::endl;
        std::cout << std::endl;
        //Auswahlmöglichkeit nur vorhanden, wenn die Einkaufsliste nicht gefüllt ist --> Nur Anzeige!
        if (currentPositions != MAX)
        {
            std::cout << "[1] Position erfassen";
            std::cout << std::endl;
        }
        else
        {
            std::cout << "[ ]";
            std::cout << std::endl;
        }
        //Auswahlmöglichkeit nur vorhanden, wenn bereits Positionen erfasst wurden --> Nur Anzeige!
        if (currentPositions > 0)
        {
            std::cout << "[2] Positionen anzeigen";
            std::cout << std::endl;
            std::cout << "[3] Positionen sortieren";
            std::cout << std::endl;
        }
        else
        {
            std::cout << "[ ]";
            std::cout << std::endl;
            std::cout << "[ ]";
            std::cout << std::endl;
        }
        std::cout << "[0] Programm beenden";
        std::cout << std::endl;
        std::cout << std::endl;

        //Benutzereingabe
        std::cout << "Auswahl: ";
        std::cin >> selectionAsString;

        std::cout << std::endl;

        //Ist die Benutzereingabe eine Ganzzahl?
        //Wenn ja, weiße die entsprechende Ganzzahl der Variable selection zu
        //Wenn nein, weiße -1 der Variable selection zu
        selection = userInputAsInteger(selectionAsString);

        //Wurden bereits eine oder mehrere Positionen erfasst oder ist die Einkaufliste voll?
        //Es soll nicht möglich sein Positionen anzuzeigen oder zu sortieren, wenn keine Positionen erfasst wurden
        //Es soll nicht möglich sein eine Position zu erfassen, wenn die Einkaufsliste bereits voll ist
        if (selection != -1)
        {
            if ((currentPositions == 0 && (selection == 2 || selection == 3)) || (currentPositions == MAX && (selection == 1)))
            {
                selection = -1;
            }
        }

        //Aufruf der Funktionen anhand der Benutzereingabe
        switch (selection)
        {
        case 1:
            currentPositions = capturePosition(names, prices, currentPositions);
            break;
        case 2:
            showPositions(names,prices,currentPositions);
            break;
        case 3:
            sortPositions(names, prices, currentPositions);
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

        //Nach Ausführung einer Funktion wird auf eine Benutzereingabe gewartet und anschließend die Konsole gelöscht --> Übersichtlichkeit
        if (selection != 0)
        {
            std::system("pause");
            std::system("cls");
        }

    } while (selection != 0);
}
/// <summary>
/// Funktion, welche eine benutzerdefinierte Position erfasst.
/// </summary>
/// <param name="productNames">Zeiger auf das erste Element eines string-Feldes</param>
/// <param name="prices">Zeiger auf das erste Element eines float-Feldes</param>
/// <param name="numberOfPositions">Temporäre Anzahl der Elemente innerhalb der Felder</param>
/// <returns>Veränderte temporäre Anzahl der Elemente innerhalb der Felder</returns>
int capturePosition(std::string names[], float prices[], int numberOfPositions)
{
    std::string tempUserInputAsString;
    float tempUserInput;

    std::cout << "Eingabe Produktname: ";
    std::cin >> names[numberOfPositions];
    do
    {
        std::cin.ignore();
        std::cout << "Eingabe Preis in EUR: ";
        std::cin >> tempUserInputAsString;

        tempUserInput = userInputAsFloat(tempUserInputAsString);

        if (tempUserInput == -1.0f)
        {
            std::cout << "Falsche Eingabe!";
            std::cout << std::endl;
        }
        else prices[numberOfPositions] = tempUserInput;

    } while (tempUserInput == -1.0f);

    ++numberOfPositions;

    return(numberOfPositions);
}
/// <summary>
/// Funktion, welche die eingegebenen Positionen anzeigt.
/// </summary>
/// <param name="productNames">Zeiger auf das erste Element eines string-Feldes</param>
/// <param name="prices">Zeiger auf das erste Element eines float-Feldes</param>
/// <param name="numberOfPositions">Temporäre Anzahl der Elemente innerhalb der Felder</param>
void showPositions(std::string names[], float prices[], int numberOfPositions)
{
    //Lokale Variablen
    float sum = 0.0f;

    std::streamsize streamSize = std::cout.precision(); //Standardgenauigkeit speichern
    std::cout << std::fixed; //Genauigkeit für Nachkommastellen
    std::cout << std::setprecision(2); //Anzahl der Nachkommastellen

    for (int i = 0; i < numberOfPositions; i++)
    {
        std::cout << "Preis in EUR: " << prices[i] << " | " << "Name: " << names[i];
        std::cout << std::endl;
        sum += prices[i];
    }

    std::cout << std::endl;
    std::cout << "Gesamtpreis in EUR: " << sum;

    std::cout.precision(streamSize); //Auf Standardgenauigkeit zurückstellen
}
/// <summary>
/// Funktion, welche die Positionen anhand des Preises aufsteigend sortiert.
/// </summary>
/// <param name="productNames">Zeiger auf das erste Element eines string-Feldes</param>
/// <param name="prices">Zeiger auf das erste Element eines float-Feldes</param>
/// <param name="numberOfPositions">Temporäre Anzahl der Elemente innerhalb der Felder</param>
void sortPositions(std::string names[], float prices[], int numberOfPositions)
{
    //Lokale Variablen
    float tempPrice;
    std::string tempName;

    for (int i1 = 0; i1 < numberOfPositions-1; i1++)
    {
        for (int i2 = 0; i2 < numberOfPositions - 1 - i1; i2++)
        {
            if (prices[i2] > prices[i2 + 1])
            {
                tempPrice = prices[i2 + 1];
                tempName = names[i2 + 1];

                prices[i2 + 1] = prices[i2];
                names[i2 + 1] = names[i2];

                prices[i2] = tempPrice;
                names[i2] = tempName;
            }
        }
    }

    std::cout << "Einkaufsliste aufsteigend sortiert.";
}
/// <summary>
/// Funktion die überprüft, ob die übergebene Zeichenkette (std::string) eine Ganzzahl ist.
/// </summary>
/// <param name="a">Übergebene Zeichenkette</param>
/// <returns>-1 = keine Ganzzahl, tempResult = Ganzzahl</returns>
int userInputAsInteger(std::string a)
{
    //Lokale Variablen
    int tempResult;

    if (a.length() > 1) return (-1);

    try
    {
        tempResult = std::stoi(a);
        return (tempResult);
    }
    catch (const std::exception&)
    {
        return (-1);
    }
}
/// <summary>
/// Funktion die überprüft, ob die übergebene Zeichenkeitte (std::string) eine positive Zahl ist.
/// </summary>
/// <param name="a">Übergebene Zeichenkette</param>
/// <returns>-1.0 = keine oder negative Zahl, tempResult = postivie Zahl</returns>
float userInputAsFloat(std::string a)
{
    float tempResult;
    int pointCounter = 0;
    int decimalPlacesCounter = 0;
    bool decimalPlacesReached = false;

    for (std::size_t i = 0; i < a.length(); i++)
    {
        if (a[i] == '.')
        {
            ++pointCounter;
            decimalPlacesReached = true;
            continue;
        }

        if (decimalPlacesReached) ++decimalPlacesCounter;

        if (a[i] < '0' || a[i] > '9') return(-1.0f);
    }

    if (pointCounter == 2 || (pointCounter == 1 && a.length() < 2) || (decimalPlacesCounter > 2)) return (-1.0f);

    try
    {
        tempResult = std::stof(a);
        return (tempResult);
    }
    catch (const std::exception&)
    {
        return (-1.0f);
    }

}
#pragma endregion