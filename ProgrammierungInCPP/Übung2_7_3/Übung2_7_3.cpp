/* Projekt: Übung2_7_3 */

/* Aufgabe:

	Erstellen Sie eine Klasse Datum, welches als Attribute Tag, Monat und Jahr hat.

	Überladen Sie den Eingabeoperator. Die Eingabe soll die drei Attribute füllen.
	Überprüfen Sie hierbei folgendes:
	-	Der Monat muss zwischen 1 und 12 liegen
	-	Der Tag muss muss größer gleich 1 sein
	-	Das Maximum vom Tag ist vom Monat abhängig:
		-	Januar, März, Mai, Juli, August, Oktober, Dezember haben max. 31 Tage
		-	April, Juni, September, November haben max. 30 Tage
		-	Februar hat max. 28 Tage (Schaltjahr wird nicht überprüft)
	-	Das Jahr darf nicht negativ sein
	Die Eingabe soll solange erfolgen, bis ein korrekter Wert eingegeben wurde.

	Überladen Sie den Ausgabeoperator. Geben sie das Datum in der Form TT.MM.JJJJ aus.

*/

#pragma region HEADER
#include <iostream>
#include <cstdlib>
#pragma endregion

/* KLASSE: Datum*/
#pragma region DEKLARATION
class Datum
{
public:
    int tag, monat, jahr;
public:
    friend std::istream& operator>>(std::istream&, const Datum&);
    friend std::ostream& operator<<(std::ostream&, const Datum&);
};
#pragma endregion

/* OPERANTENÜBERLADUNG: Friend class*/
#pragma region DEFINITION
std::istream& operator>>(std::istream& is, Datum& dt)
{
    std::cout << "Monat: ";
    do
    {
        is >> dt.monat;
    } while (dt.monat < 1 || dt.monat>12);

    std::cout << "Tag: ";

    int tmp = 0;

    do
    {
        is >> dt.tag;
        if (dt.tag >= 1)
        {
            if (dt.monat == 1 || dt.monat == 3 || dt.monat == 5 || dt.monat == 7 || dt.monat == 8 || dt.monat == 10 || dt.monat == 12)
            {
                if (dt.tag <= 31)
                {
                    tmp = 1;
                }
            }
            else if (dt.monat == 2 && dt.tag <= 28)
            {
                tmp = 1;
            }
            else if (dt.monat != 2 && dt.tag <= 30)
            {
                tmp = 1;
            }
        }
    } while (tmp == 0);

    std::cout << "Jahr: ";

    do
    {
        is >> dt.jahr;
    } while (dt.jahr < 0);

    return(is);
}

std::ostream& operator<<(std::ostream& os, const Datum& dt)
{
    os << dt.tag << '.' << dt.monat << '.' << dt.jahr;
    return(os);
}
#pragma endregion

#pragma region HAUPTPROGRAMM
int main(void)
{
    Datum dt;
    std::cin >> dt;
    std::cout << std::endl;
    std::cout << dt;

    std::cout << std::endl;
    std::cout << std::endl;
    std::system("pause");
    return 0;
}
#pragma endregion




