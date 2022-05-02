/* Projekt: Mitarbeiterverwaltung */
/* Projektbeschreibung:

    Aufgabe:    Sie sollen ein Programm zur Urlaubsverwaltung in C++ realisieren

    Ziel:       Leistungsnachweis Teil 1

    Status:     Abgeschlossen

*/

/* Aufgabe:

    Schreiben Sie ein C++-Programm nach objektorientierten Grundsätzen und muss mindestens folgende Anforderungen erfüllen:

    Ausgangssituation:

        Sie wollen ein Programm zur Verwaltung des Urlaubs der Mitarbeiter an Ihrer
        Hochschule erstellen.

        Jeder/jede Mitarbeiter/Mitarbeiterin (kurz: Mitarbeiter) hat 30 Tage.

        Mitarbeiter, die zum 01.01. des laufenden Kalenderjahrs das 50 Lebensjahr bereits vollendet haben, erhalten 32 Tage Urlaub.

        Von jedem Mitarbeiter wird gespeichert:

        Name
        Vorname
        Geburtsdatum
        Bereits in Anspruch genommener Urlaub

    Bei Programmstart ist die „Datenbank“ der Urlaubsverwaltung leer, die Daten müssen erst eingegeben werden. Die Daten müssen nur während der Laufzeit verfügbar sein (keine permanente Speicherung nötig!).

    Das Programm muss folgendes leisten:

        Verwaltung von maximal 500 Mitarbeiter                                                          --> Makro: #define MAX_ELEMENTS 100 Abgeändert wegen der stacksize
        Anlegen und Löschen eines Mitarbeiters                                                          --> Implementiert und getestet
        Eingabe der Tage, wenn der Mitarbeiter Urlaub nehmen möchte (muss mehrfach möglich sein)        --> Implementiert und getestet
        Suche eines Mitarbeiters mit Ausgabe seiner Daten und wie viel Resturlaub er noch hat           --> Implementiert und getestet
        Auflistung aller gespeicherten Mitarbeiterdaten                                                 --> Implementiert und getestet

        Dokumentieren Sie Ihr Programm durch Kommentare im Quelltext.                                   --> Dauerhaft

*/

#pragma region HEADER
#include <iostream>
#include <cstdlib> //void srand (unsigned int seed); int rand (void); int system( const char *command );
#include <string> //int stoi(const std::string& str);
#include <ctime> //time_t time (time_t* timer);
#pragma endregion

#pragma region MAKROS
#define MAX_ELEMENTS 100 //Abgeändert auf 100 wegen Überschreitung der stacksize
#define AGE_LIMIT 50
#define FIRST_YEAR 1900
#pragma endregion

#pragma region KONSTANTEN
const unsigned char AE = static_cast<unsigned char>(142);
const unsigned char ae = static_cast<unsigned char>(132);
const unsigned char OE = static_cast<unsigned char>(153);
const unsigned char oe = static_cast<unsigned char>(148);
const unsigned char UE = static_cast<unsigned char>(154);
const unsigned char ue = static_cast<unsigned char>(129);
const unsigned char ss = static_cast<unsigned char>(225);
#pragma endregion

#pragma region DEKLARATION: KLASSE DateOfBirth
class DateOfBirth
{
public:
    //Konstruktoren
    DateOfBirth();

    //Dekonstruktoren
    ~DateOfBirth();

    //Deklaration: Getter-Methoden
    short getDay(void);
    short getMonth(void);
    short getYear(void);

    //Methoden
    void changeDateOfBirth(void);
    void printDateOfBirth(void);
    short readCurrentYear(void);

private:
    //Attribute
    short day;
    short month;
    short year;
};
#pragma endregion

#pragma region DEFINITION: KLASSE DateOfBirth
/* KONSTRUKTOR */
DateOfBirth::DateOfBirth()
{
    this->day = 0;
    this->month = 0;
    this->year = 0;
}

/* DEKONSTRUKTOR */
DateOfBirth::~DateOfBirth(){}

/* GETTER-METHODEN */
short DateOfBirth::getDay(void) { return(this->day); }
short DateOfBirth::getMonth(void) { return(this->month); }
short DateOfBirth::getYear(void) { return(this->year); }

/* METHODEN */

/// <summary>
/// Methode zum Ändern eines Geburtsdatums (Objekt).
/// </summary>
/// <param name=""></param>
void DateOfBirth::changeDateOfBirth(void)
{
    std::string tempDayAsString = "";
    std::string tempMonthAsString = "";
    std::string tempYearAsString = "";

    short tempDay = 0;
    short tempMonth = 0;
    short tempYear = 0;
    
    std::cout << std::endl;

    do
    {
        std::cout << "Eingabe Tag:\t\t";
        std::cin >> tempDayAsString;

        //Kann der eingegebene String in eine Ganzzahl umgewandelt werden?
        //Vermeidung von falschen Benutzereingaben.
        try
        {
            tempDay = std::stoi(tempDayAsString);
        }
        catch (const std::exception&)
        {
            continue;
        }

    } while (tempDay > 31 || tempDay < 1);

    do
    {
        std::cout << "Eingabe Monat:\t\t";
        std::cin >> tempMonthAsString;

        //Kann der eingegebene String in eine Ganzzahl umgewandelt werden?
        //Vermeidung von falschen Benutzereingaben.
        try
        {
            tempMonth = std::stoi(tempMonthAsString);
        }
        catch (const std::exception&)
        {
            continue;
        }

    } while (tempMonth > 12 || tempMonth < 1);

    do 
    {
        std::cout << "Eingabe Jahr:\t\t";
        std::cin >> tempYearAsString;

        //Kann der eingegebene String in eine Ganzzahl umgewandelt werden?
        //Vermeidung von falschen Benutzereingaben.
        try
        {
            tempYear = std::stoi(tempYearAsString);
        }
        catch (const std::exception&)
        {
            continue;
        }

    } while (tempYear < FIRST_YEAR || tempYear > this->readCurrentYear());

    this->day = tempDay;
    this->month = tempMonth;
    this->year = tempYear;
}
/// <summary>
/// Methode zum Ausgeben der Daten eines Geburtsdatums.
/// </summary>
/// <param name=""></param>
void DateOfBirth::printDateOfBirth(void)
{
    std::cout << "Geburtsdatum:\t" << this->day << "." << this->month << "." << this->year;
}
/// <summary>
/// Methode zum Bestimmen des aktuellen Jahres.
/// </summary>
/// <param name=""></param>
/// <returns></returns>
short DateOfBirth::readCurrentYear(void)
{
    short currentYear = 0;

    struct tm newtime;
    time_t now = time(0);
    localtime_s(&newtime, &now);
    currentYear = (short)newtime.tm_year + FIRST_YEAR; //Addition von 1900, da newtime.tm_year die vergangenen Jahre ab dem Jahr 1900 zurückgibt.

    return(currentYear);
}
#pragma endregion

#pragma region DEKLARATION: KLASSE Employee
class Employee
{
public:
    //Deklaration: Klassenvariablen
    static int numberOfEmployees;

    //Deklaration: Konstruktoren
    Employee();

    //Deklaration: Dekonstruktor
    ~Employee();

    //Deklaration: Setter-Methoden
    void setFirstName(std::string);
    void setLastName(std::string);
    void setDateOfBirth(DateOfBirth);
    void setNumberOfHolidayDaysTaken(short);
    void setNumberOfHolidayDays(short);

    //Deklaration: Getter-Methoden
    std::string getFirstName(void);
    std::string getLastName(void);
    DateOfBirth getDateOfBirth(void);
    short getNumberOfHolidayDaysTaken(void);
    short getNumberOfHolidayDays(void);

    //Deklaration: Methoden
    void changeEmployee(void);
    void printData(void);

private:
    //Deklaration: Attribute
    std::string firstName;
    std::string lastName;
    short numberOfHolidayDaysTaken;
    short numberOfHolidayDays;
    DateOfBirth date;

    //Deklaration: Methoden
    short calculateRemainingHoliday(DateOfBirth);
    short calculateHoliday(DateOfBirth);
};
#pragma endregion

#pragma region DEFINITION: KLASSE Employee
/* KLASSENVARIABLE */
int Employee::numberOfEmployees = 0;

/* KONSTRUKTOR */
Employee::Employee()
{
    this->firstName = "";
    this->lastName = "";
    this->numberOfHolidayDays = 0;
    this->numberOfHolidayDaysTaken = 0;

    std::cout << "Mitarbeiter erstellt.";
    std::cout << std::endl;

    ++Employee::numberOfEmployees;
}

/* DEKONSTRUKTOR */
Employee::~Employee()
{
    std::cout << "Mitarbeiter gel" << oe << "scht.";
    std::cout << std::endl;

    --Employee::numberOfEmployees;
}

/* SETTER-METHODEN */
void Employee::setFirstName(std::string firstName){this->firstName = firstName;}
void Employee::setLastName(std::string lastName){this->lastName = lastName;}
void Employee::setDateOfBirth(DateOfBirth date)
{ 
    this->date = date;

    //Anpassung der Urlaubstage, falls durch Änderung des Geburtsdatums das alter von 50 Jahren überschritten wird.
    this->numberOfHolidayDays = this->calculateHoliday(date);
}
void Employee::setNumberOfHolidayDaysTaken(short numberOfHolidayDaysTaken) { this->numberOfHolidayDaysTaken = numberOfHolidayDaysTaken; }
void Employee::setNumberOfHolidayDays(short numberOfHolidayDays) { this->numberOfHolidayDays = numberOfHolidayDays; }

/* GETTER-METHODEN */
std::string Employee::getFirstName(void){return(this->firstName);}
std::string Employee::getLastName(void){return(this->lastName);}
DateOfBirth Employee::getDateOfBirth(void){return(this->date);}
short Employee::getNumberOfHolidayDaysTaken(void) { return(this->numberOfHolidayDaysTaken); }
short Employee::getNumberOfHolidayDays(void) { return(this->numberOfHolidayDays); }

/* METHODEN */

/// <summary>
/// Methode zum Ändern eines Mitarbeiters (Objekt).
/// </summary>
/// <param name=""></param>
void Employee::changeEmployee(void)
{
    std::cout << "Eingabe Vorname:\t";
    std::cin >> this->firstName;
    std::cout << "Eingabe Nachname:\t";
    std::cin >> this->lastName;
    std::cout << "Geburtsdatum";
    this->date.changeDateOfBirth();

    this->numberOfHolidayDays = this->calculateHoliday(this->date);
    this->numberOfHolidayDaysTaken = 0;
}
/// <summary>
/// Methode zum Ausgeben der Daten eines Mitarbeiters.
/// </summary>
/// <param name=""></param>
void Employee::printData(void)
{
    std::cout << "Vorname:\t" << this->firstName;
    std::cout << std::endl;
    std::cout << "Nachname:\t" << this->lastName;
    std::cout << std::endl;
    this->date.printDateOfBirth();
    std::cout << std::endl;
    std::cout << "Resturlaub:\t" << this->calculateRemainingHoliday(this->date);
    std::cout << std::endl;
}
/// <summary>
/// Methode zur Berechnung der verbleibenden Urlaubstage.
/// </summary>
/// <param name="date"></param>
/// <returns></returns>
short Employee::calculateRemainingHoliday(DateOfBirth date)
{
    return(calculateHoliday(date) - this->numberOfHolidayDaysTaken);
}
/// <summary>
/// Methode zur Berechnung der initialen Urlaubstage.
/// </summary>
/// <param name="date"></param>
/// <returns></returns>
short Employee::calculateHoliday(DateOfBirth date)
{
    short tempResultHoliday = 0;

    //Mitarbeiter, die zum 01.01.des laufenden Kalenderjahrs das 50 Lebensjahr bereits vollendet haben, erhalten 32 Tage Urlaub.
    // --> 2020 wurde der Mitarbeiter er 50 Jahre entspricht: Aktuelles Jahr - 1 >= 50

    if ((this->date.readCurrentYear() - 1 - date.getYear()) >= 50) tempResultHoliday = 32;
    else tempResultHoliday = 30;

    return(tempResultHoliday);
}
#pragma endregion

#pragma region DEKLARATION: FUNKTIONEN
bool isInteger(std::string);
int addEmployee(Employee[], int);
int printEmployee(Employee[], int, std::string, std::string);
void deleteEmployee(Employee[], int, std::string, std::string, int, int);
void changeEmployee(Employee[], int, std::string, std::string, int, int);
void enterHoliday(Employee[], int, std::string, std::string, int);
void printEmployees(Employee[], int);
#pragma endregion

#pragma region HAUPTPROGRAMM
int main(void)
{
	std::string selectionAsString;
    int selection;
    int indexCounter = 0;

    Employee employees[MAX_ELEMENTS]; //Erzeugung von <MAX_ELEMENTS> Mitarbeitern mit default-Werten --> Konstruktoraufruf Klasse Employee
    std::cout << std::endl;

    std::cout << "Anzahl der Mitarbeiter: " << Employee::numberOfEmployees;
    std::cout << std::endl;
    std::cout << std::endl;

	std::system("pause");

	do
	{
		std::system("cls");

		std::cout << "-------------------- MEN" << UE << " --------------------";
        std::cout << std::endl;
		std::cout << std::endl;
        std::cout << "MITARBEITER";
        std::cout << std::endl;
		std::cout << "\t[1] Hinzuf" << ue <<"gen";
		std::cout << std::endl;
		std::cout << "\t[2] Anzeigen";
		std::cout << std::endl;
		std::cout << "\t[3] L" << oe << "schen";
		std::cout << std::endl;
		std::cout << "\t[4] " << AE << "ndern";
		std::cout << std::endl;
		std::cout << "\t[5] Urlaub eintragen";
        std::cout << std::endl;
		std::cout << std::endl;
        std::cout << "BELEGSCHAFT";
        std::cout << std::endl;
        std::cout << "\t[6] Anzeigen";
        std::cout << std::endl;
        std::cout << std::endl;
        std::cout << "PROGRAMM";
        std::cout << std::endl;
		std::cout << "\t[0] Beenden";
		std::cout << std::endl;
        std::cout << std::endl;
        std::cout << "----------------------------------------------";
        std::cout << std::endl;
        std::cout << std::endl;

		std::cout << "Auswahl: ";
		std::cin >> selectionAsString;
        std::cout << std::endl;

        //Prüfung, ob der eingegebene String als Ganzzahl darstellbar ist.
        //Vermeidung von falschen Benutzereingaben.
        if (isInteger(selectionAsString)) selection = std::stoi(selectionAsString);
        else selection = -1; //Selection wird auf -1 gesetzt, um den default-Case auszuführen --> Falsche Benutzereingabe

        switch (selection)
        {
        case 1:
            //Mitarbeiter Hinzufügen
            if (indexCounter < MAX_ELEMENTS) indexCounter = addEmployee(employees, indexCounter);
            else std::cout << "Es k" << oe << "nnen keine weiteren Mitarbeiter angelegt werden.";

            break;

        case 2:
            //Mitarbeiter Anzeigen
            if (indexCounter > 0)
            {
                std::string tempFirstName;
                std::string tempLastName;

                //Festlegung: Mitarbeiter werden anhand Vor- und Nachname bestimmt.
                std::cout << "Welchen Mitarbeiter m" << oe << "chten Sie anzeigen? ";
                std::cout << std::endl;
                std::cout << std::endl;
                std::cout << "Eingabe Vorname:\t";
                std::cin >> tempFirstName;
                std::cout << "Eingabe Nachname:\t";
                std::cin >> tempLastName;

                int counter = printEmployee(employees, indexCounter, tempFirstName, tempLastName);

                //An dieser Stelle könnte auf eine Switch-Case-Anweisung verzichtet werden.
                //Diese wurde aufgrund der Übersichtlichkeit (gleicher Aufbau der Cases) hinzugefügt.
                switch (counter)
                {
                case 0://Kein Mitarbeiter

                    std::cout << std::endl;
                    std::cout << "Es existiert kein Mitarbeitender mit dem Namen " << tempFirstName << ", " << tempLastName << ".";

                    break;
                }

            }
            else std::cout << "Es sind aktuell keine Mitarbeiter angelegt.";

            break;

        case 3:
            //Mitarbeiter Löschen
            if (indexCounter > 0)
            {
                std::string tempFirstName;
                std::string tempLastName;
                char selection;
                int positionToDelete;

                //Festlegung: Mitarbeiter werden anhand Vor- und Nachname bestimmt.
                std::cout << "Welchen Mitarbeiter m" << oe << "chten Sie l" << oe <<"schen?";
                std::cout << std::endl;
                std::cout << std::endl;
                std::cout << "Eingabe Vorname:\t";
                std::cin >> tempFirstName;
                std::cout << "Eingabe Nachname:\t";
                std::cin >> tempLastName;

                int counter = printEmployee(employees, indexCounter, tempFirstName, tempLastName);

                switch (counter)
                {
                case 0://Kein Mitarbeiter

                    std::cout << std::endl;
                    std::cout << "Es existiert kein Mitarbeitender mit dem Namen " << tempFirstName << ", " << tempLastName << ".";

                    break;

                case 1://Ein Mitarbeiter

                    deleteEmployee(employees, indexCounter, tempFirstName, tempLastName, 1, -1);

                    std::cout << std::endl;
                    std::cout << "Der Mitarbeiter " << tempFirstName << ", " << tempLastName << " wurde gel" << oe << "scht.";

                    --indexCounter;

                    break;

                default://Mehrere Mitarbeiter

                    bool tempTrigger = false;

                    std::cout << std::endl;
                    std::cout << "---------------------------------------------------------";
                    std::cout << std::endl;
                    std::cout << std::endl;
                    std::cout << "Mehrere Eintr" << ae << "ge gefunden!";
                    std::cout << std::endl;
                    std::cout << std::endl;
                    std::cout << "L"<<OE << "SCHEN";
                    std::cout << std::endl;
                    std::cout << "\t[A] Alle";
                    std::cout << std::endl;
                    std::cout << "\t[E] Einzeln";
                    std::cout << std::endl;
                    std::cout << "\t[ ] Abbrechen";
                    std::cout << std::endl;
                    std::cout << std::endl;

                    std::cout << "Auswahl: ";
                    std::cin >> selection;

                    std::cout << std::endl;

                    switch ((int)selection)
                    {
                    case 65://A

                        deleteEmployee(employees, indexCounter, tempFirstName, tempLastName, counter, -1);

                        std::cout << "Es wurden alle Mitarbeiter mit dem Namen " << tempFirstName << ", " << tempLastName << " gel" << oe << "scht.";
                        std::cout << std::endl;

                        indexCounter -= counter;

                        break;

                    case 69://E

                        std::cout << "Welcher Mitarbeiter? [";

                        //Anzeige der Mitarbeiterpositionen
                        for (int i = 0; i < indexCounter; i++)
                        {
                            if (employees[i].getFirstName() == tempFirstName && employees[i].getLastName() == tempLastName)
                            {
                                std::cout << i + 1 << ", ";
                            }
                        }

                        std::cout << "\b\b]: ";
                        std::cin >> positionToDelete;

                        //Ist die vom Benutzer gewählte Mitarbeiterposition korrekt?
                        //Wenn ja, setze Variable <tempTrigger> auf true.
                        for (int i = 0; i < indexCounter; i++)
                        {
                            if (employees[i].getFirstName() == tempFirstName && employees[i].getLastName() == tempLastName && (i+1) == positionToDelete)
                            {
                                tempTrigger = true;
                                break;
                            }
                        }

                        //Code ausführen, wenn Benutzer die korrekte Mitarbeiterposition eingegeben hat (Variable <tempTrigger> ist wahr).
                        if (tempTrigger)
                        {
                            deleteEmployee(employees, indexCounter, tempFirstName, tempLastName, 1, positionToDelete);

                            std::cout << "Der Mitarbeiter " << tempFirstName << ", " << tempLastName << " auf Position " << positionToDelete << " wurde gel" << oe << "scht.";
                            std::cout << std::endl;

                            --indexCounter;
                        }
                        else
                        {
                            std::cout << "Es wurde kein Mitarbeiter gel" << oe << "scht.";
                            std::cout << std::endl;
                        }
                                           
                        break;

                    default:

                        std::cout << "Es wurde kein Mitarbeiter gel" << oe << "scht.";
                        std::cout << std::endl;

                        break;
                    }
                    break;
                }
            }
            else std::cout << "Es sind aktuell keine Mitarbeiter angelegt.";    
            
            break;

        case 4:
            //Mitarbeiter Ändern
            if (indexCounter > 0)
            {
                
                std::string tempFirstName;
                std::string tempLastName;
                char selection;
                int positionToChange;

                //Festlegung: Mitarbeiter werden anhand Vor- und Nachname bestimmt.
                std::cout << "Welchen Mitarbeiter m" << oe << "chten Sie ver" << ae << "ndern?";
                std::cout << std::endl;
                std::cout << std::endl;
                std::cout << "Eingabe Vorname:\t";
                std::cin >> tempFirstName;
                std::cout << "Eingabe Nachname:\t";
                std::cin >> tempLastName;

                int counter = printEmployee(employees, indexCounter, tempFirstName, tempLastName);


                switch (counter)
                {
                case 0://Kein Mitarbeiter

                    std::cout << std::endl;
                    std::cout << "Es existiert kein Mitarbeitender mit dem Namen " << tempFirstName << ", " << tempLastName << ".";

                    break;

                case 1://Ein Mitarbeiter

                    std::cout << std::endl;
                    std::cout << "---------------------------------------------------------";
                    std::cout << std::endl;
                    std::cout << std::endl;
                    std::cout << "Was m" << oe <<"chten Sie " << ae <<"ndern?";
                    std::cout << std::endl;
                    std::cout << std::endl;
                    std::cout << AE << "NDERN";
                    std::cout << std::endl;
                    std::cout << "\t[V] Vorname";
                    std::cout << std::endl;
                    std::cout << "\t[N] Nachname";
                    std::cout << std::endl;
                    std::cout << "\t[G] Geburtsdatum";
                    std::cout << std::endl;
                    std::cout << "\t[ ] Abbrechen";
                    std::cout << std::endl;
                    std::cout << std::endl;

                    std::cout << "Auswahl: ";
                    std::cin >> selection;

                    changeEmployee(employees,indexCounter,tempFirstName,tempLastName,(int)selection,-1);

                    break;

                default://Mehrere Mitarbeiter

                    bool tempTrigger = false;

                    std::cout << std::endl;
                    std::cout << "---------------------------------------------------------";
                    std::cout << std::endl;
                    std::cout << std::endl;
                    std::cout << "Mehrere Eintr" << ae << "ge gefunden!";
                    std::cout << std::endl;
                    std::cout << std::endl;
                    std::cout << "Welcher Mitarbeiter? [";

                    //Anzeige der Mitarbeiterpositionen
                    for (int i = 0; i < indexCounter; i++)
                    {
                        if (employees[i].getFirstName() == tempFirstName && employees[i].getLastName() == tempLastName)
                        {
                            std::cout << i + 1 << ", ";
                        }
                    }

                    std::cout << "\b\b]: ";
                    std::cin >> positionToChange;

                    //Ist die vom Benutzer gewählte Mitarbeiterposition korrekt?
                    //Wenn ja, setze Variable <tempTrigger> auf true.
                    for (int i = 0; i < indexCounter; i++)
                    {
                        if (employees[i].getFirstName() == tempFirstName && employees[i].getLastName() == tempLastName && (i + 1) == positionToChange)
                        {
                            tempTrigger = true;
                            break;
                        }
                    }

                    //Code ausführen, wenn Benutzer die korrekte Mitarbeiterposition eingegeben hat (Variable <tempTrigger> ist wahr).
                    if (tempTrigger)
                    {

                        std::cout << std::endl;
                        std::cout << "---------------------------------------------------------";
                        std::cout << std::endl;
                        std::cout << std::endl;
                        std::cout << "Was m" << oe << "chten Sie " << ae << "ndern?";
                        std::cout << std::endl;
                        std::cout << std::endl;
                        std::cout << AE << "NDERN";
                        std::cout << std::endl;
                        std::cout << "\t[V] Vorname";
                        std::cout << std::endl;
                        std::cout << "\t[N] Nachname";
                        std::cout << std::endl;
                        std::cout << "\t[G] Geburtsdatum";
                        std::cout << std::endl;
                        std::cout << "\t[ ] Abbrechen";
                        std::cout << std::endl;
                        std::cout << std::endl;

                        std::cout << "Auswahl: ";
                        std::cin >> selection;

                        changeEmployee(employees, indexCounter, tempFirstName, tempLastName, (int)selection, positionToChange);
                    }
                    else
                    {
                        std::cout << "Es wurde kein Mitarbeiter ge" << ae << "ndert.";
                        std::cout << std::endl;
                    }
                
                    break;
                }

            }
            else std::cout << "Es sind aktuell keine Mitarbeiter angelegt.";
                         
            break;

        case 5:
            //Mitarbeiter Urlaub eintragen
            if (indexCounter > 0)
            {
                std::string tempFirstName;
                std::string tempLastName;
                int position;

                //Festlegung: Mitarbeiter werden anhand Vor- und Nachname bestimmt.
                std::cout << "Welcher Mitarbeiter m" << oe << "chte Urlaub eintragen?";
                std::cout << std::endl;
                std::cout << std::endl;
                std::cout << "Eingabe Vorname:\t";
                std::cin >> tempFirstName;
                std::cout << "Eingabe Nachname:\t";
                std::cin >> tempLastName;

                int counter = printEmployee(employees, indexCounter, tempFirstName, tempLastName);

                switch (counter)
                {
                case 0://Kein Mitarbeiter

                    std::cout << std::endl;
                    std::cout << "Es existiert kein Mitarbeitender mit dem Namen " << tempFirstName << ", " << tempLastName << ".";

                    break;

                case 1://Ein Mitarbeiter

                    enterHoliday(employees, indexCounter, tempFirstName, tempLastName,-1);

                    break;

                default://Mehrere Mitarbeiter

                    bool tempTrigger = false;

                    std::cout << std::endl;
                    std::cout << "---------------------------------------------------------";
                    std::cout << std::endl;
                    std::cout << std::endl;
                    std::cout << "Mehrere Eintr" << ae << "ge gefunden!";
                    std::cout << std::endl;
                    std::cout << std::endl;
                    std::cout << "Welcher Mitarbeiter? [";

                    //Anzeige der Mitarbeiterpositionen
                    for (int i = 0; i < indexCounter; i++)
                    {
                        if (employees[i].getFirstName() == tempFirstName && employees[i].getLastName() == tempLastName)
                        {
                            std::cout << i + 1 << ", ";
                        }
                    }

                    std::cout << "\b\b]: ";
                    std::cin >> position;

                    //Ist die vom Benutzer gewählte Mitarbeiterposition korrekt?
                    //Wenn ja, setze Variable <tempTrigger> auf true.
                    for (int i = 0; i < indexCounter; i++)
                    {
                        if (employees[i].getFirstName() == tempFirstName && employees[i].getLastName() == tempLastName && (i + 1) == position)
                        {
                            tempTrigger = true;
                            break;
                        }
                    }

                    //Code ausführen, wenn Benutzer die korrekte Mitarbeiterposition eingegeben hat (Variable <tempTrigger> ist wahr).
                    if (tempTrigger)
                    {
                        enterHoliday(employees, indexCounter, tempFirstName, tempLastName, position);
                    }
                    else
                    {
                        std::cout << "Es wurde f" << ue << "r keinen Mitarbeiter Urlaub eingetragen.";
                        std::cout << std::endl;
                    }

                    break;

                }

            }
            else std::cout << "Es sind aktuell keine Mitarbeiter angelegt.";
                          
            break;

        case 6:
            //Belegschaft Anzeigen
            if (indexCounter > 0) printEmployees(employees, indexCounter);
            else std::cout << "Es sind aktuell keine Mitarbeiter angelegt.";

            break;

        case 0:
            //Programm beenden
            std::cout << "Programm beendet. Auf Wiedersehen!";

            break;

        default:
            //Falsche Benutzereingabe
            std::cout << "Falsche Eingabe!";

            break;

        }

        std::cout << std::endl;
        std::cout << std::endl;
        std::system("pause");
        std::cout << std::endl;

	} while (selection != 0);

    std::system("cls");

    return(0);
}
#pragma endregion

#pragma region DEFINITION: FUNKTIONEN
/// <summary>
/// Funktion die überprüft, ob die übergebene Zeichenkette (std::string) eine Ganzzahl ist.
/// </summary>
/// <param name="a"></param>
/// <returns></returns>
bool isInteger(std::string a)
{
    
    if (a.length() > 1) return (false); //Werden zwei Zeichen im String a übergeben kann dieser keine Ganzzahl sein.

    //Vermeidung von falschen Benutzereingaben.
    try
    {
        int temp = std::stoi(a); //Versuche den String in einen Integer umzuwandeln
        return (true);
    }
    catch (const std::exception&)
    {
        return (false);
    }
}
/// <summary>
/// Funktion, welche es ermöglicht einen neuen Mitarbeiter anzulegen.
/// </summary>
/// <param name="employees"></param>
/// <param name="index"></param>
/// <returns></returns>
int addEmployee(Employee employees[],int index)
{
    //Das Mitarbeiterobjekt wird nicht wirklich hinzugefügt, sondern die bestehenden Objekte (erzeugt beim Anlegen des Arrays) geändert.
    employees[index].changeEmployee();
    return(++index);
}
/// <summary>
/// Funktion, welche alle Mitarbeiter durchsucht und den passenden Mitarbeiter ausgibt.
/// </summary>
/// <param name="employees"></param>
/// <param name="size"></param>
/// <param name="firstName"></param>
/// <param name="lastName"></param>
/// <returns></returns>
int printEmployee(Employee employees[], int size, std::string firstName, std::string lastName)
{
    int counter = 0;

    for (int i = 0; i < size; i++)
    {
        //Gebe die Mitarbeiter aus, welche dem übergebenen Vor- und Nachnamen entsprechen.
        if (employees[i].getFirstName() == firstName && employees[i].getLastName() == lastName)
        {
            std::cout << std::endl;
            std::cout << "Mitarbeiter " << i + 1;
            std::cout << std::endl;
            employees[i].printData();

            ++counter;
        }
    }

    return(counter);
}
/// <summary>
/// Funktion, welche in Abhängigkeit von der getätigten Auswahl die Mitarbeiter löscht.
/// </summary>
/// <param name="employees"></param>
/// <param name="size"></param>
/// <param name="firstName"></param>
/// <param name="lastName"></param>
/// <param name="numberOfEntries"></param>
/// <param name="positionToDelete"></param>
void deleteEmployee(Employee employees[], int size, std::string firstName, std::string lastName, int numberOfEntries, int positionToDelete)
{
    //Das Mitarbeiterobjekt wird nicht wirklich gelöscht, sondern den Daten der nachfolgenden Objekte (erzeugt beim Anlegen des Arrays) überschrieben.

    bool trigger = false;
    int i;

    for (int j = 0; j < numberOfEntries; j++)//Falls mehrere Mitarbeiter mit gleichem Vor- und Nachnamen gibt führe nachstehend Code mehrfach aus.
    {
        trigger = false;

        for (i = 0; i < size; i++)
        {
            if (trigger)
            {
                //Verschiebe die Daten der Mitarbeiterobjekte nach vorne.
                employees[i - 1].setFirstName(employees[i].getFirstName());
                employees[i - 1].setLastName(employees[i].getLastName());
                employees[i - 1].setDateOfBirth(employees[i].getDateOfBirth());
                employees[i - 1].setNumberOfHolidayDaysTaken(employees[i].getNumberOfHolidayDaysTaken());
                employees[i - 1].setNumberOfHolidayDays(employees[i].getNumberOfHolidayDays());
            }
            else
            {
                if (employees[i].getFirstName() == firstName && employees[i].getLastName() == lastName && (-1 == positionToDelete || (i+1) == positionToDelete))
                {
                    //Zu modifizierendes Mitarbeiterobjekt wurde gefunden.
                    trigger = true;
                    continue;
                }
            }
        }

        //Nachdem die Objektdaten verschoben worden sind, wird das letzte geschriebene Element des Arrays mit initialen Daten gefüllt.
        employees[i - 1].setFirstName("");
        employees[i - 1].setLastName("");
        employees[i - 1].setDateOfBirth(DateOfBirth::DateOfBirth());
        employees[i - 1].setNumberOfHolidayDaysTaken(0);
        employees[i - 1].setNumberOfHolidayDays(0);
    }
}
/// <summary>
/// Funktion, welche es ermöglicht die Daten eines Mitarbeiters zu verändern.
/// </summary>
/// <param name="employees"></param>
/// <param name="size"></param>
/// <param name="firstName"></param>
/// <param name="lastName"></param>
void changeEmployee(Employee employees[], int size, std::string firstName, std::string lastName, int selection, int positionToChange)
{
    std::string tempFirstName;
    std::string tempLastName;
    DateOfBirth tempDateOfBirth = DateOfBirth::DateOfBirth();

    for (int i = 0; i < size; i++)
    {
        if (employees[i].getFirstName() == firstName && employees[i].getLastName() == lastName && (-1 == positionToChange || (i + 1) == positionToChange))
        {
            //Zu modifizierendes Mitarbeiterobjekt wurde gefunden.
            switch ((int)selection)
            {
            case 86://V --> Vorname ändern
                std::cout << "Eingabe neuer Vorname: ";
                std::cin >> tempFirstName;

                employees[i].setFirstName(tempFirstName);

                std::cout << std::endl;
                std::cout << "Neuer Vorname: " << employees[i].getFirstName();

                break;

            case 78://N --> Nachname ändern

                std::cout << "Eingabe neuer Nachname: ";
                std::cin >> tempLastName;

                employees[i].setLastName(tempLastName);

                std::cout << std::endl;
                std::cout << "Neuer Nachname: " << employees[i].getLastName();

                break;

            case 71://G --> Geburtsdatum ändern

                std::cout << "Eingabe neues Geburtsdatum";
                tempDateOfBirth = employees[i].getDateOfBirth();
                tempDateOfBirth.changeDateOfBirth();
                employees[i].setDateOfBirth(tempDateOfBirth);

                std::cout << std::endl;
                std::cout << "Neues ";
                employees[i].getDateOfBirth().printDateOfBirth();

                break;

            default:

                //Falls andere (von V, N, G verschieden) Benutzereingabe.
                std::cout << "Es wurde kein Mitarbeiter ge" << ae << "ndert.";
                std::cout << std::endl;

                break;
            }
        }
    }
}
/// <summary>
/// Funktion, welche es ermöglicht Urlaub für einen Mitarbeiter einzutragen.
/// </summary>
/// <param name="employees"></param>
/// <param name="size"></param>
/// <param name="firstName"></param>
/// <param name="lastName"></param>
void enterHoliday(Employee employees[], int size, std::string firstName, std::string lastName,int position)
{
    int tempHolidayDays = 0;

    for (int i = 0; i < size; i++)
    {
        if (employees[i].getFirstName() == firstName && employees[i].getLastName() == lastName && (-1 == position || (i + 1) == position))
        {
            //Zu modifizierendes Mitarbeiterobjekt wurde gefunden.
            
            //Stehen dem Mitarbeiter noch Urlaubstage zur Verfügung?
            if (employees[i].getNumberOfHolidayDays() - employees[i].getNumberOfHolidayDaysTaken() == 0)
            {
                //Nein
                std::cout << std::endl;
                std::cout << "Mitarbeiter hat keinen Urlaub mehr.";
                std::cout << std::endl;

                break;
            }
            else
            {
                //Ja
                do
                {
                    std::cout << std::endl;
                    std::cout << "Eingabe Urlaubstage: ";
                    std::cin >> tempHolidayDays;

                    if (tempHolidayDays >= 1 && tempHolidayDays > (employees[i].getNumberOfHolidayDays() - employees[i].getNumberOfHolidayDaysTaken()))
                    {
                        //Falsche Benuztereingabe: Möglichkeit 1
                        std::cout << "Mitarbeiter hat zu wenig Urlaubstage.";
                        std::cout << std::endl;
                    }
                    else if (tempHolidayDays < 1)
                    {
                        //Falsche Benutzereingabe: Möglichkeit 2
                        std::cout << "Falsche Eingabe.";
                        std::cout << std::endl;
                    }

                } while (tempHolidayDays < 1 || (tempHolidayDays >= 1 && tempHolidayDays > (employees[i].getNumberOfHolidayDays() - employees[i].getNumberOfHolidayDaysTaken())));

                employees[i].setNumberOfHolidayDaysTaken(employees[i].getNumberOfHolidayDaysTaken() + tempHolidayDays);

                std::cout << "Der Mitarbeiter " << firstName << ", " << lastName << " hat noch " << employees[i].getNumberOfHolidayDays() - employees[i].getNumberOfHolidayDaysTaken() << " Tage Urlaub zur Verf" << ue << "gung.";
                std::cout << std::endl;
            }
        }
    }
}
/// <summary>
/// Funktion, welche alle Mitarbeiter der Belegschaft ausgibt.
/// </summary>
/// <param name="employees"></param>
/// <param name="size"></param>
void printEmployees(Employee employees[],int size)
{
    for (int i = 0; i < size; i++)
    {
        std::cout << "Mitarbeiter " << i + 1;
        std::cout << std::endl;
        employees[i].printData();
        std::cout << std::endl;
    }
}
#pragma endregion