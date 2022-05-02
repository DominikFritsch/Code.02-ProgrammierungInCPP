/* Projekt: Zahlenraten */
/* Projektbeschreibung:

    Zahlenraten ist ein Spiel, bei dem der Computer eine Zusfallszahl zwischen 1 und 100 erstellt, die durch den
    Spieler erraten werden muss.

    Es wird bei jedem Durchgang mitgeteilt, ob die eingegebene Zahl zu groﬂ oder zu klein war.

*/

/* Aufgabe 1:

    Implementieren Sie das Spiel.

    Tipp:   Zufallszahlen werden wie folgt generiert:
            Ein einmaliger Aufruf srand(time(NULL)) initialisiert den Zufallszahlengenerator.
            Anschlieﬂend liefert jeder Aufruf von rand()%100 eine Zufallszahl zwischen 0 und 99.
            Die Funktionen sind in <ctime> und <cstdlib> deklariert.

*/

#pragma region HEADER
#include <iostream>
#include <cstdlib> //void srand (unsigned int seed); int rand (void);
#include <ctime> //time_t time (time_t* timer);
#pragma endregion

#pragma region DEKLARATION
int generateRandomNumber(void);
#pragma endregion

#pragma region DEFINITION
int generateRandomNumber(void)
{
    std::srand((unsigned int)std::time(NULL));

    return(std::rand() % 100 + 1);
}
#pragma endregion

#pragma region HAUPTPROGRAMM
int main(void)
{
    int input;
    int randomNumber;

    std::cout << "---------- Willkommen beim Spiel Zahlenraten ----------";
    std::cout << std::endl;
    std::cout << std::endl;


    randomNumber = generateRandomNumber();

    do
    {
        std::cout << "Eingabe Ganzzahl: ";
        std::cin >> input;

        if (input < randomNumber) std::cout << "Die eingegebene Zahl war zu klein.";
        else if (input > randomNumber) std::cout << "Die eingegebene Zahl war zu gro\xE1.";
        else std::cout << "Sie haben die per Zufall generierte Zahl " << randomNumber << " erraten.";

        std::cout << std::endl;
        std::cout << std::endl;

    } while (input != randomNumber);

    std::system("pause");
    
    return(0);
}
#pragma endregion



