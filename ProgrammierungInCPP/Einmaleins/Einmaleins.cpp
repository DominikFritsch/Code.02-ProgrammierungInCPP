/* Projekt: Bauernhof */
/* Projektbeschreibung: Ein einfaches Programm, um das Einmaleins in Tabellenform wiederzugeben. */

/* Aufgabe 1:

    Erstellen Sie ein Tableau, welches das kleine „Einmaleins“ ausgibt.
    Das Tableu soll in der Funktion void printTableFor() ausgegeben werden.

    Ausgabe:

    1	2	3	4	5	6	7	8	9	10
    2	4	6	8	10	12	14	16	18	20
    3	6	9	12	15	18	21	24	27	30
    4	8	12	16	20	24	28	32	36	40
    5	10	15	20	25	30	35	40	45	50
    6	12	18	24	30	36	42	48	54	60
    7	14	21	28	35	42	49	56	63	70
    8	16	24	32	40	48	56	64	72	80
    9	18	27	36	45	54	63	72	81	90
    10	20	30	40	50	60	70	80	90	100
 

    Tipp: 
    -	Rufen Sie die printTableFor()-Methode in der main()-Methode auf
    -	Für diese Aufgabe benötigt man eine verschachtelte for-Schleife.
    -	Den Tabulator erzeugt man mit „\t“.

    Realisieren Sie anschließend die gleiche Ausgabe mit einer while 
    und einer do-while Schleife, welche jeweils in einer neuen Methode aufgerufen wird.

*/

#pragma region HEADER
#include <iostream>
#include <cstdlib>
#pragma endregion

#pragma region DEKLARATION
void printTableFor(void);
void printTableWhile(void);
void printTableDoWhile(void);
#pragma endregion

#pragma region DEFINITION
/// <summary>
/// Funktion, welche das Einmaleins mit einer verschachtelten for-Schleife ausgibt.
/// </summary>
/// <param name=""></param>
void printTableFor(void)
{
    for (int i = 1; i <= 10; i++)
    {
        std::cout << i << "\t";

        for (int j = 2; j <= 10; j++)
        {
            std::cout << (j * i) << "\t";
        }

        std::cout << std::endl;
    }
}
/// <summary>
/// Funktion, welche das Einmaleins mit einer verschachtelten while-Schleife ausgibt.
/// </summary>
/// <param name=""></param>
void printTableWhile(void)
{
    int i = 1;

    while (i <= 10)
    {
        std::cout << i << "\t";
        int j = 2;

        while (j <= 10)
        {
            std::cout << (j * i) << "\t";
            ++j;
        }

        std::cout << std::endl;
        ++i;
    }
}
/// <summary>
/// Funktion, welche das Einmaleins mit einer do-while-Schleife ausgibt.
/// </summary>
/// <param name=""></param>
void printTableDoWhile(void)
{
    int i = 1;

    do
    {
        std::cout << i << "\t";
        int j = 2;

        do
        {
            std::cout << (j * i) << "\t";
            ++j;
        } while (j <=10);

        std::cout << std::endl;
        ++i;

    } while (i <= 10);
}
#pragma endregion

#pragma region HAUPTPROGRAMM
int main(void)
{
    std::cout << "----------------------------------- for-Schleife -----------------------------------";
    std::cout << std::endl;
    std::cout << std::endl;
    printTableFor();
    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << "----------------------------------- while-Schleife -----------------------------------";
    std::cout << std::endl;
    std::cout << std::endl;
    printTableWhile();
    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << "----------------------------------- do-while-Schleife -----------------------------------";
    std::cout << std::endl;
    std::cout << std::endl;
    printTableDoWhile();
    std::cout << std::endl;
    std::cout << std::endl;

    std::system("pause");

    return(0);

}
#pragma endregion
