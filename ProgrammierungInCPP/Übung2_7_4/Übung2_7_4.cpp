/* Projekt: Übung2_7_4 */

/* Aufgabe:

    Erstellen Sie ein Programm "Schere, Stein, Papier", wo der Benutzer gegen den Computer spielen kann.

    Die Klasse "Spieler" soll folgendes enthalten:

    - Spielername, z.B. "Spieler", "Computer"
    - Auswahl (0, 1 oder 2)
    - Anzahl Gewinn
    - Anzahl Unentschieden

    Beim Programmstart kommt folgende Ausgabe:


    [0] Schere
    [1] Stein
    [2] Papier
    Auswahl Spieler: ...


    Der Benutzer kann anschließend auswählen, welche Form er auswählen will.
    Dem Computer wird anschließend zufällig eine der drei Auswahlmöglichkeiten zugewiesen.

    Anschließend soll folgendes verglichen werden:

    Sollte der Spieler die gleiche Auswahl wie der Computer getroffen haben (übleraden Sie hier den == Operator),
    dann erhöht sich das Attribute "Unentschieden" bei beiden Spielern um 1 (überladen Sie hier den Präfix Operator).
    Sollte der Spieler gewonnen haben (überladen Sie hier den > Operator),
    dann erhöht sich das Attribut "Gewinn" beim Spieler, ansonsten beim Computer (überladen Sie hier den Postfix Operator).

    Die Ein-/Ausgabenoperatoren sollen ebenfalls überladen werden
    Eingabe überladen: Auswahlmöglichkeit wird ausgegeben und die Auswahl wird beim Spieler hinterlegt
    Ausgabe überladen: Anzahl der Gewinne vom Spieler bzw. Computer werden ausgegeben

    Es erfolgen insgesamt 5 Spielzüge. Zum Schluss werden die Anzahl an Gewinne bzw. Unentschiede ausgegeben und
    es wird ausgegeben, wer gewonnen hat bzw. ob es ein Unentschieden ist (überladen Sie hier den >= Operator und überprüfen Sie, 
    wer mehr Gewinne hat)

*/

#pragma region HEADER
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#pragma endregion

#pragma region GLOBALE VARIABLEN
std::string form[3] = { "Schere","Stein","Papier" };
#pragma endregion

/* KLASSE: Spieler */
#pragma region DEKLARATION
class Spieler
{
private:
    std::string name;
    int auswahl;
    int gewinn;
    int unentschieden;
public:
    Spieler(std::string);
    void set_auswahl(int a) { auswahl = a; };
    int get_unentschieden() { return unentschieden; };
    friend bool operator==(const Spieler& s1, const Spieler& s2);
    friend bool operator>(const Spieler& s1, const Spieler& s2);
    friend bool operator>=(const Spieler& s1, const Spieler& s2);
    Spieler operator++(); // Prefix-Operator
    Spieler operator++(int); // Postfix-Operator
    friend std::istream& operator>>(std::istream& input, Spieler& s);
    friend std::ostream& operator<<(std::ostream& output, Spieler& s);
};
#pragma endregion
#pragma region DEFINITION
Spieler::Spieler(std::string n)
{
    gewinn = 0;
    unentschieden = 0;
    name = n;
}
Spieler Spieler::operator++ ()
{
    this->unentschieden++;
    return (*this);
}

Spieler Spieler::operator++ (int a)
{
    this->gewinn++;
    return (*this);
}
#pragma endregion

/* OPERANTENÜBERLADUNG: friend */
#pragma region DEFINITION
bool operator==(const Spieler& s1, const Spieler& s2)
{
    if (s1.auswahl == 0 && s2.auswahl == 0)
    {
        std::cout << form[0] << " gegen " << form[0];
        return (true);
    }
    else if (s1.auswahl == 1 && s2.auswahl == 1)
    {
        std::cout << form[1] << " gegen " << form[1];
        return (true);
    }
    else if (s1.auswahl == 2 && s2.auswahl == 2)
    {
        std::cout << form[2] << " gegen " << form[2];
        return (true);
    }
    return (false);
}

bool operator>(const Spieler& s1, const Spieler& s2)
{
    if (s1.auswahl == 0 && s2.auswahl == 1)
    {
        return(false);
    }
    else if (s1.auswahl == 1 && s2.auswahl == 0)
    {
        std::cout << form[1] << " schl\x84gt " << form[0];
        return(true);
    }
    else if (s1.auswahl == 2 && s2.auswahl == 0)
    {
        return (false);
    }
    else if (s1.auswahl == 0 && s2.auswahl == 2)
    {
        std::cout << form[0] << " schl\x84gt " << form[2];
        return (true);
    }
    else if (s1.auswahl == 1 && s2.auswahl == 2)
    {
        return (false);
    }
    else if (s1.auswahl == 2 && s2.auswahl == 1)
    {
        std::cout << form[2] << " schl\x84gt " << form[1];
        return (true);
    }
    return (false);
}

bool operator>=(const Spieler& s1, const Spieler& s2)
{
    if (s1.gewinn > s2.gewinn)
    {
        std::cout << std::endl;
        std::cout << std::endl;
        std::cout << s1.name << " gewinnt!";
        return (true);
    }
    else if (s2.gewinn > s1.gewinn)
    {
        std::cout << std::endl;
        std::cout << std::endl;
        std::cout << s2.name << " gewinnt!";
        return (true);
    }
    else
    {
        std::cout << std::endl;
        std::cout << std::endl;
        std::cout << "Unentschieden! Es gibt keinen Gewinner.";
    }
    return (false);
}

std::istream& operator>>(std::istream& input, Spieler& s)
{
    std::cout << "Auswahl " << s.name;
    std::cout << std::endl;
    std::cout << "[0] Schere";
    std::cout << std::endl;
    std::cout << "[1] Stein";
    std::cout << std::endl;
    std::cout << "[2] Papier";
    std::cout << std::endl;
    std::cout << "Auswahl: ";

    input >> s.auswahl;

    return(input);
}

std::ostream& operator<<(std::ostream& output, Spieler& s)
{
    output << std::endl;
    output << s.name << ":";
    output << std::endl;
    output << "Gewinn: " << s.gewinn;

    return (output);
}
#pragma endregion

#pragma region HAUPTPROGRAMM
int main(void)
{
    Spieler sp("Spieler");
    Spieler pc("Computer");

    int anzahl = 0;

    do
    {
        std::system("cls");
        std::cout << "*****SPIEL*****";
        std::cout << std::endl;
        std::cout << std::endl;
        std::cin >> sp;
        std::cout << std::endl;

        std::srand((unsigned int)std::time(NULL)); //Zufällige Zahlen anhand der Uhrzeit neu generieren
        pc.set_auswahl(std::rand() % 3); //Zufällige Zahl zwischen 0 und 2

        if (sp == pc)
        {
            ++sp;
            ++pc;
        }
        else if (sp > pc)
        {
            sp++;
        }
        else if (pc > sp)
        {
            pc++;
        }

        anzahl++;

        std::cout << std::endl;
        std::cout << std::endl;

        std::system("pause");
    } while (anzahl < 5);

    std::cout << sp;
    std::cout << std::endl;
    std::cout << pc;
    std::cout << std::endl;
    std::cout << std::endl << "Unentschieden: " << sp.get_unentschieden();

    sp >= pc;

    return(0);
}
#pragma endregion