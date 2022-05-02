/* Projekt: Mitarbeiterverwaltung */

/* Projektbeschreibung:

    Aufgabe:    Sie sollen ein Programm zur Verwaltung von Motorrädern in C++ realisieren.

    Ziel:       Leistungsnachweis Teil 2

    Status:     Abgeschlossen

*/

/* Aufgabenbeschreibung:

    Motorradvermietung

    Die Mitarbeiterin soll die Möglichkeit haben, die Kunden zu verwalten und Reservierungen der Motorräder vorzunehmen.
    Der Kunde kann nur jeweils ein Motorrad reservieren.
    Es gibt insgesamt 4 Motorräder zur Auswahl: „Suzuki Bandit“, „Honda TransAlp“, „BMW F650GS“ und „Kawasaki ZZR1400“.
    Stellen Sie sicher, dass ein Motorrad nicht doppelt reserviert wird.

    Bei der Reservierung muss der Kunde: Name, Vorname, Adresse (Straße, Nr. PLZ, Ort), Geburtsjahr, Telefonnummer und
    ob er Führerschein der Klasse A besitzt, angeben.

    Besitzt er kein Führerschein der Klasse A, so kann kein Motorrad für ihn reserviert werden.

    Sobald die Übergabe des Motorrads erfolgt ist, wird die Reservierung für diesen Kunden storniert.

    Der Datensatz wird aus der verketteten Liste rausgenommen.

    Jedes mal, wenn ein Motorrad gebucht oder storniert wird, dann soll die Datei geschrieben werden.


    Verwaltung der Reservierungen:

    Reservierung vornehmen
    Motorrad herausgeben (mit der Abfrage des Kundenvor- und nachnamens)


    Dateiverwaltung:

    Die Datensätze sollen in einer verketteten Liste gespeichert werden.
    Der aktuelle Stand der Reservierungen soll in die Datei „reservierungen.txt“ geschrieben werden.
    Falls die Datei noch nicht existiert, soll sie angelegt werden. Ansonsten sollen die Daten überschrieben werden.
    Beim Starten des Programms soll die Datei gelesen und die verkettete Liste (sofern Datensätze vorhanden sind) mit den Daten befüllt werden.


    Die Verwaltung der Kunden soll dynamisch erfolgen.
    Bei Bedarf sollen entsprechende (Fehler-) Meldungen ausgegeben werden.

*/

/* Vorüberlegung Motorradzustände:

    isBooked 	isAvailable     Zustand
    false	    false			Herausgegeben
    false       true			Standard
    true 	    false			Existiert nicht
    true	    true			Reserviert

    false	    true			Reservierung möglich
    true	    true			Stonierung möglich
    -	        true			Herausgabe möglich
    -	        false			Zurücknahme möglich

    Festlegung: Ein Kunde kann nur jeweils ein Motorrad reservieren aber mehrere im Besitz haben.

*/

#pragma region HEADER
#include <iostream>//std::cout, std::cin
#include <cstdlib>//std::system()
#include <string>//std::string
#include <fstream>
#include <cstddef>//std::size_t
#include <vector>//std::vector
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

/* KLASSE: Customer */
#pragma region DEKLARATION
class Customer
{
    friend std::istream& operator>> (std::istream&, Customer*);
    friend std::ostream& operator<< (std::ostream&, Customer*);

private:
    std::string firstName;
    std::string lastName;
    std::string address;
    int yearOfBirth;
    std::string phoneNumber;
    char drivingLicenceClass;
    Customer* next;

protected:

public:   
    //Statische Attribute
    static int numberOfCustomers;
    //Konstruktor
    Customer();
    //Dekonstruktor
    ~Customer();
    //Getter
    std::string getFirstName(void);
    std::string getLastName(void);
    std::string getAddress(void);
    int getYearOfBirth(void);
    std::string getPhoneNumber(void);
    char getDrivingLicenceClass(void);
    Customer* getNext(void);
    //Setter
    void setFirstName(std::string);
    void setLastName(std::string);
    void setAddress(std::string);
    void setYearOfBirth(int);
    void setPhoneNumber(std::string);
    void setDrivingLicenceClass(char);
    void setNext(Customer*);

};
#pragma endregion

#pragma region STATISCHE ATTRIBUTE
int Customer::numberOfCustomers = 0;
#pragma endregion

#pragma region OVERLOAD
std::istream& operator>> (std::istream& istream, Customer* tempObject)
{
    std::string tempStreet;
    int tempHouseNumber;
    int tempPostCode;
    std::string tempCity;

    std::cout << std::endl;
    std::cout << "Eingabe Vorname:\t";
    std::cin >> tempObject->firstName;
    std::cout << "Eingabe Nachname:\t";
    std::cin >> tempObject->lastName;
    std::cout << std::endl;
    std::cout << "Wohnort:";
    std::cout << std::endl;
    std::cout << "----------------------------------------------------------------------";
    std::cout << std::endl;
    std::cout << "Eingabe Stra" << ss << "e:\t\t";
    std::cin >> tempStreet;
    std::cout << "Eingabe Hausnummer:\t";
    std::cin >> tempHouseNumber;
    std::cout << "Eingabe Postleitzahl:\t";
    std::cin >> tempPostCode;
    std::cout << "Eingabe Stadt:\t\t";
    std::cin >> tempCity;
    std::cout << "----------------------------------------------------------------------";
    std::cout << std::endl;
    tempObject->address = tempStreet + " " + std::to_string(tempHouseNumber) + " | " + std::to_string(tempPostCode) + " " + tempCity;
    std::cout << std::endl;
    std::cout << "Eingabe Geburtsjahr:\t";
    std::cin >> tempObject->yearOfBirth;
    std::cout << "Eingabe Telefonnummer:\t";
    std::cin >> tempObject->phoneNumber;
    std::cout << "F" << ue << "hrerscheinklasse:\t";
    std::cin >> tempObject->drivingLicenceClass;

    return(istream);
}
std::ostream& operator<<(std::ostream& ostream, Customer* tempObject)
{
    if (tempObject != NULL)
    {
        std::cout << "Vorname:\t\t" << tempObject->firstName;
        std::cout << std::endl;
        std::cout << "Nachname:\t\t" << tempObject->lastName;
        std::cout << std::endl;
        std::cout << "Adresse:\t\t" << tempObject->address;
        std::cout << std::endl;
        std::cout << "Geburtsjahr:\t\t" << tempObject->yearOfBirth;
        std::cout << std::endl;
        std::cout << "Telefonnummer:\t\t" << tempObject->phoneNumber;
        std::cout << std::endl;
        std::cout << "F" << ue << "hrerscheinklasse:\t" << tempObject->drivingLicenceClass;
        std::cout << std::endl;
        std::cout << std::endl;
    }

    return(ostream);
}
#pragma endregion

#pragma region DEFINITION
//Konstruktor
Customer::Customer()
{
    this->firstName = "";
    this->lastName = "";
    this->address = "";
    this->yearOfBirth = 0;
    this->phoneNumber = "";
    this->drivingLicenceClass = ' ';
    this->next = NULL;

    std::cout << "Standardkonstruktor: Kunde erstellt.";
    std::cout << std::endl;

    ++numberOfCustomers;
}
//Dekonstruktor
Customer::~Customer()
{
    std::cout << "Dekonstruktor: Kunde gel" << oe << "scht.";
    std::cout << std::endl;
    --numberOfCustomers;
}
//Getter
std::string Customer::getFirstName(void)
{
    return(this->firstName);
}
std::string Customer::getLastName(void)
{
    return(this->lastName);
}
std::string Customer::getAddress(void)
{
    return(this->address);
}
int Customer::getYearOfBirth(void)
{
    return(this->yearOfBirth);
}
std::string Customer::getPhoneNumber(void)
{
    return(this->phoneNumber);
}
char Customer::getDrivingLicenceClass(void)
{
    return(this->drivingLicenceClass);
}
Customer* Customer::getNext(void)
{
    return(this->next);
}
//Setter
void Customer::setFirstName(std::string firstName)
{
    this->firstName = firstName;
}
void Customer::setLastName(std::string lastName)
{
    this->lastName = lastName;
}
void Customer::setAddress(std::string address)
{
    this->address = address;
}
void Customer::setYearOfBirth(int yearOfBirth)
{
    this->yearOfBirth = yearOfBirth;
}
void Customer::setPhoneNumber(std::string phoneNumber)
{
    this->phoneNumber = phoneNumber;
}
void Customer::setDrivingLicenceClass(char drivingLicenceClass)
{
    this->drivingLicenceClass = drivingLicenceClass;
}
void Customer::setNext(Customer* tempCustomer)
{
    this->next = tempCustomer;
}
#pragma endregion

/* KLASSE: Motorbike */
#pragma region DEKLARATION
class Motorbike
{
    friend std::ostream& operator<< (std::ostream&, Motorbike*);

private:
    std::string brand;
    bool isBooked;
    bool isAvailable;//False = reserviert oder herausgegeben, True = vorhanden
    Customer* current;
    Motorbike* next;

protected:

public:
    //Statische Attribute
    static int numberOfMotorbikes;
    //Konstruktor
    Motorbike();
    //Dekonstruktor
    ~Motorbike();
    //Getter
    std::string getBrand(void);
    bool getIsBooked(void);
    bool getIsAvailable(void);
    Customer* getCurrent(void);
    Motorbike* getNext(void);
    //Setter
    void setBrand(std::string);
    void setIsBooked(bool);
    void setIsAvailable(bool);
    void setCurrent(Customer*);
    void setNext(Motorbike*);
};
#pragma endregion

#pragma region STATISCHE ATTRIBUTE
int Motorbike::numberOfMotorbikes = 0;
#pragma endregion

#pragma region OVERLOAD
std::ostream& operator<<(std::ostream& ostream, Motorbike* tempObject)
{
    std::cout << std::endl;
    std::cout << "Marke:\t\t\t" << tempObject->brand;
    std::cout << std::endl;
    std::cout << "Status Reservierung:\t" << tempObject->isBooked;
    std::cout << std::endl;
    std::cout << "Status Verf"<<ue<<"gbarkeit:\t" << tempObject->isAvailable;
    std::cout << std::endl;
    std::cout << std::endl;
    if(tempObject != NULL) std::cout << tempObject->current;

    return(ostream);
}
#pragma endregion

#pragma region DEFINITION
//Konstruktor
Motorbike::Motorbike()
{
    this->brand = "";
    this->isBooked = false;
    this->isAvailable = true;
    this->current = NULL;

    std::cout << "Standardkonstruktor: Motorrad erstellt.";
    std::cout << std::endl;

    ++numberOfMotorbikes;
}
//Dekonstruktor
Motorbike::~Motorbike()
{
    std::cout << "Dekonstruktor: Motorrad gel" << oe << "scht.";
    std::cout << std::endl;

    --numberOfMotorbikes;
}
//Getter
std::string Motorbike::getBrand(void)
{
    return(this->brand);
}
bool Motorbike::getIsBooked(void)
{
    return(this->isBooked);
}
bool Motorbike::getIsAvailable(void)
{
    return(this->isAvailable);
}
Customer* Motorbike::getCurrent(void)
{
    return(this->current);
}
Motorbike* Motorbike::getNext(void)
{
    return(this->next);
}
//Setter
void Motorbike::setBrand(std::string brand)
{
    this->brand = brand;
}
void Motorbike::setIsBooked(bool isBooked)
{
    this->isBooked = isBooked;
}
void Motorbike::setIsAvailable(bool isAvailable)
{
    this->isAvailable = isAvailable;
}
void Motorbike::setCurrent(Customer* current)
{
    this->current = current;
}
void Motorbike::setNext(Motorbike* next)
{
    this->next = next;
}
#pragma endregion

/* TEMPLATE: List */
#pragma region DEKLARATION
template<class T> class List
{
private:
    //Attribute
    T head;
    //Methoden
    void removeFirst(void);
    T previous(T);

protected:

public:
    //Konstruktor
    List();
    //Dekonstruktor
    ~List();
    //Getter
    T getFirst(void);
    T getAt(int);
    //Setter
    void setFirst(T);
    //Methoden
    void add(T);
    T search(std::string, std::string);
    T search(std::string);
    void destroy(std::string, std::string);
    void print(void);
    void clear(void);
    bool empty(void);
};
#pragma endregion

#pragma region DEFINITION
//Konstruktor
template<class T> List<T>::List()
{
    this->head = NULL;

    std::cout << "Standardkonstruktor: Liste erstellt.";
    std::cout << std::endl;
}
//Dekonstruktor
template<class T> List<T>::~List()
{
    std::cout << "Dekonstruktor: Liste gel" << oe << "scht.";
    std::cout << std::endl;
}
//Getter
template<class T> T List<T>::getFirst(void)
{
    return(this->head);
}
template<class T> T List<T>::getAt(int index)
{
    int counter = 0;

    for (T i = this->head; i != NULL; i = i->getNext())
    {
        if (counter == index) return(i);
        ++counter;
    }
    return(NULL);
}
//Setter
template<class T> void List<T>::setFirst(T tempCustomer)
{
    this->head = tempCustomer;
}
//Methoden
template<class T> void List<T>::add(T tempObject)
{
    tempObject->setNext(this->head);
    this->head = tempObject;
}
template<class T> bool List<T>::empty(void)
{
    return(this->head == NULL);
}
template<class T> void List<T>::print(void)
{
    for (T i = this->head; i != NULL; i = i->getNext()) std::cout << i;
}
template<class T> void List<T>::removeFirst(void)
{
    if (!this->empty())
    {
        T tempObject = this->head;
        this->head = tempObject->getNext();
        tempObject->setNext(NULL);
        delete tempObject;
    }
}
template<class T> void List<T>::clear(void)
{
    while (!this->empty())
    {
        this->removeFirst();
    }
}
template<class T> T List<T>::search(std::string firstName, std::string lastName)
{
    for (T i = this->head; i != NULL; i = i->getNext()) if (i->getFirstName() == firstName && i->getLastName() == lastName) return(i);
    return(NULL);
}
template<class T> T List<T>::search(std::string brand)
{
    for (T i = this->head; i != NULL; i = i->getNext()) if (i->getBrand() == brand) return(i);
    return(NULL);
}
template<class T> T List<T>::previous(T tempObject)
{
    for (T i = this->head; i != NULL; i = i->getNext()) if (i->getNext() == tempObject) return(i);
    return(NULL);
}
template<class T> void List<T>::destroy(std::string firstName, std::string lastName)
{
    if (this->empty())
    {
        std::cout << std::endl;
        std::cout << "Keine Kundendaten vorhanden";
        std::cout << std::endl;
    }
    else
    {
        T tempObject = this->search(firstName, lastName);

        if (tempObject == NULL)
        {
            std::cout << std::endl;
            std::cout << "Kunde nicht gefunden";
            std::cout << std::endl;
        }
        else
        {
            if (tempObject == this->head) this->removeFirst();//Erste Positon ist gesuchter Kunde
            else
            {
                this->previous(tempObject)->setNext(tempObject->getNext());
                tempObject->setNext(NULL);
                delete tempObject;
            }
        }
    }
}
#pragma endregion

/* FUNKTION */
#pragma region DEKLARATION
void userInterfaceHomePage(List<Customer*>*, List<Motorbike*>*);
void userInterfaceCustomerPage(List<Customer*>*, List<Motorbike*>*);
void userInterfaceBookingPage(List<Customer*>*, List<Motorbike*>*);
void publishMotorbike(List<Customer*>*, List<Motorbike*>*);
void returnMotorbike(List<Motorbike*>*);
bool readCustomerFile(List<Customer*>*, std::string);
bool writeCustomerFile(List<Customer*>*, std::string);
bool readBookingFile(List<Motorbike*>*, std::string);
bool writeBookingFile(List<Motorbike*>*, std::string);
std::vector<std::string> split(std::string, char);
bool isInteger(std::string);
#pragma endregion

#pragma region DEFINITION
/// <summary>
/// Funktion, welche die Startseite der Benutzeroberfläche repräsentiert.
/// </summary>
/// <param name="customerList"></param>
void userInterfaceHomePage(List<Customer*>* customerList, List<Motorbike*>* motorbikeList)
{
    char selection;

    do
    {
        try
        {
            std::cout << "--------------------Startseite--------------------";
            std::cout << std::endl;
            std::cout << std::endl;
            std::cout << "[K] Kundenverwaltung";
            std::cout << std::endl;
            std::cout << "[R] Reservierung";
            std::cout << std::endl;
            std::cout << "[H] Motorrad: Herausgabe";
            std::cout << std::endl;
            std::cout << "[Z] Motorrad: Zur" << ue << "ckgabe";
            std::cout << std::endl;
            std::cout << std::endl;
            std::cout << "[B] Beenden";
            std::cout << std::endl;
            std::cout << std::endl;

            std::cout << "Was m" << oe << "chten Sie tun? ";
            std::cin >> selection;

            //Fehler 0: Falsche Eingabe
            if (!(selection == 'K' || selection == 'R' || selection == 'H' || selection == 'Z' || selection == 'B')) throw(0);
            else
            {
                switch ((int)selection)
                {
                case 75://Kundenverwaltung
                    userInterfaceCustomerPage(customerList,motorbikeList);
                    break;
                case 82://Reservierung
                    userInterfaceBookingPage(customerList, motorbikeList);
                    break;
                case 72://Motorrad: Herausgabe
                    publishMotorbike(customerList, motorbikeList);
                    break;
                case 90://Motorrad: Zurückgabe
                    returnMotorbike(motorbikeList);
                    break;
                }
            }
        }
        catch (int errorNumber)
        {
            switch (errorNumber)
            {
            case 0:
                std::cout << "Falsche Eingabe.";
                break;
            }
        }
        catch (...)
        {
            std::cout << "Unbekannter Fehler.";
        }

        std::cout << std::endl;
        std::cout << std::endl;
        std::system("pause");
        std::system("cls");

    } while (selection != 'B');
}
/// <summary>
/// Funktion, welche die Kunderverwaltungseite der Benutzeroberfläche repräsentiert.
/// </summary>
/// <param name="customerList"></param>
void userInterfaceCustomerPage(List<Customer*>* customerList ,List<Motorbike*>* motorbikeList)
{
    char selection;

    std::system("cls");

    do
    {
        std::cout << "--------------------Kunderverwaltung--------------------";
        std::cout << std::endl;
        std::cout << std::endl;
        std::cout << "Kunde";
        std::cout << std::endl;
        std::cout << "\t[0] Hinzuf" << ue << "gen";
        std::cout << std::endl;
        std::cout << "\t[1] Suchen";
        std::cout << std::endl;
        std::cout << "\t[2] L" << oe << "schen";
        std::cout << std::endl;

        std::cout << std::endl;
        std::cout << "Kundenstamm";
        std::cout << std::endl;
        std::cout << "\t[3] Ausgabe";
        std::cout << std::endl;
        std::cout << "\t[4] Leeren";
        std::cout << std::endl;

        std::cout << std::endl;
        std::cout << "Sonstiges";
        std::cout << std::endl;
        std::cout << "\t[A] Abbrechen";
        std::cout << std::endl;
        std::cout << std::endl;

        std::cout << "Was m" << oe << "chten Sie tun? ";
        std::cin >> selection;

        try
        {
            char question;
            Customer* tempCustomer;
            std::string tempFirstName;
            std::string tempLastName;
            bool customerHasBooked = false;

            if (!(selection == '0' || selection == '1' || selection == '2' || selection == '3' || selection == '4' || selection == 'A')) throw(0);
            else
            {
                tempCustomer = NULL;

                switch ((int)selection)
                {
                case 48://Kunde: Hinzufügen

                    tempCustomer = new Customer();
                    std::cin >> tempCustomer;
                    customerList->add(tempCustomer);
                    writeCustomerFile(customerList, "customerData.txt");

                    break;

                case 49://Kunde: Suchen

                    if (customerList->empty()) throw(3);
                    else
                    {
                        std::cout << "Eingabe Vorname:\t";
                        std::cin >> tempFirstName;
                        std::cout << "Eingabe Nachname:\t";
                        std::cin >> tempLastName;

                        tempCustomer = customerList->search(tempFirstName, tempLastName);

                        if (tempCustomer != NULL)
                        {
                            std::cout << std::endl;
                            std::cout << tempCustomer;
                        }
                        else throw(1);
                    }

                    break;

                case 50://Kunde: Löschen

                    if (customerList->empty()) throw(3);
                    else
                    {
                        std::cout << "Eingabe Vorname:\t";
                        std::cin >> tempFirstName;
                        std::cout << "Eingabe Nachname:\t";
                        std::cin >> tempLastName;


                        for (int i = 0; i < Motorbike::numberOfMotorbikes; i++)
                        {
                            tempCustomer = motorbikeList->getAt(i)->getCurrent();

                            if (tempCustomer != NULL && (tempCustomer->getFirstName() == tempFirstName && tempCustomer->getLastName() == tempLastName)) customerHasBooked = true;
                        }


                        if (customerHasBooked) throw(2);
                        else
                        {
                            //Es liegt keine Reservierung vor
                            customerList->destroy(tempFirstName, tempLastName);
                            writeCustomerFile(customerList, "customerData.txt");
                        }
                    }

                    break;

                case 51://Kundestamm: Ausgabe   

                    if (customerList->empty()) throw(3);
                    else
                    {
                        std::cout << "----------------------------------------";
                        std::cout << std::endl;
                        std::cout << std::endl;
                        customerList->print();
                        std::cout << "----------------------------------------";
                        std::cout << std::endl;
                    }

                    break;

                case 52://Kundestamm: Leeren

                    if (customerList->empty()) throw(3);
                    else
                    {
                        bool isPossible = true;

                        std::cout << "Sind Sie sicher?";
                        std::cout << std::endl;
                        std::cout << std::endl;

                        std::cout << "[A] Abbrechen [J] Ja     Auswahl: ";
                        std::cin >> question;

                        for (int i = 0; i < Motorbike::numberOfMotorbikes; i++)
                        {
                            tempCustomer = motorbikeList->getAt(i)->getCurrent();

                            if (tempCustomer != NULL)
                            {
                                isPossible = false;
                                break;
                            }
                        }


                        if (question == 'J' )
                        {
                            if (isPossible)
                            {
                                customerList->clear();
                                writeCustomerFile(customerList, "customerData.txt");
                            }
                            else throw(4);
                        }
                        else throw(5);
                      
                    }

                    break;

                }
            }
        }
        catch (int errorNumber)
        {
            std::cout << std::endl;

            switch (errorNumber)
            {
            case 0:
                std::cout << "Falsche Eingabe.";
                break;
            case 1:
                std::cout << "Kunde nicht gefunden.";
                break;
            case 2:
                std::cout << "Kunde wurde nicht gel" << oe << "scht, da er ein Motorrad reserviert oder im Besitz hat.";
                break;
            case 3:
                std::cout << "Keine Kundendaten vorhanden.";
                break;
            case 4:
                std::cout << "Ausf" << ue << "hrung nicht m" << oe << "glich, da ein Kunde ein Motorrad reserviert oder im Besitz hat.";
                break;
            case 5:
                std::cout << "Ausf" << ue << "hrung abgebrochen.";
                break;
            }

            std::cout << std::endl;
        }
        catch (...)
        {
            std::cout << std::endl;
            std::cout << "Unbekannter Fehler.";
            std::cout << std::endl;
        }

        if (selection != 'A')
        {
            std::cout << std::endl;
            std::system("pause");
            std::system("cls");
        }

    } while (selection != 'A');
}
/// <summary>
/// Funktion, welche die Reservierungseite der Benutzeroberfläche repräsentiert.
/// </summary>
/// <param name=""></param>
void userInterfaceBookingPage(List<Customer*>* customerList, List<Motorbike*>* motorbikeList)
{
    char selection;

    std::system("cls");

    do
    {
        std::cout << "--------------------Reservierungsverwaltung--------------------";
        std::cout << std::endl;
        std::cout << std::endl;
        std::cout << "Motorrad";
        std::cout << std::endl;
        std::cout << "\t[0] Reservieren";
        std::cout << std::endl;
        std::cout << "\t[1] Stonieren";
        std::cout << std::endl;

        std::cout << std::endl;
        std::cout << "Ausgabe";
        std::cout << std::endl;
        std::cout << "\t[2] Vollst" << ae << "ndiger Bestand";
        std::cout << std::endl;
        std::cout << "\t[3] Aktueller Bestand";
        std::cout << std::endl;

        std::cout << std::endl;
        std::cout << "Sonstiges";
        std::cout << std::endl;
        std::cout << "\t[A] Abbrechen";
        std::cout << std::endl;
        std::cout << std::endl;

        std::cout << "Was m" << oe << "chten Sie tun? ";
        std::cin >> selection;


        try
        {
            if (!(selection == '0' || selection == '1' || selection == '2' || selection == '3' ||  selection == 'A')) throw(0);
            else
            {

                int counter = 0;
                int input;
                std::string inputAsString;
                std::string tempFirstName;
                std::string tempLastName;
                bool availableNumbers[4] ={false};
                bool customerHasBooked = false;
                char question;

                Customer* tempCustomer = NULL;
                Customer* tempCurrentCustomer = NULL;
                Motorbike* tempMotorbike = NULL;

                switch ((int)selection)
                {
                case 48://Motorrad: Reservieren

                    //Welche Motorräder können aktuell reserviert werden?
                    std::cout << "----------------------------------------";
                    std::cout << std::endl;
                    for (int i = 0; i < Motorbike::numberOfMotorbikes; i++)
                    {
                        if (motorbikeList->getAt(i)->getIsBooked() == false && motorbikeList->getAt(i)->getIsAvailable() == true)
                        {
                            std::cout << "[" << i << "] ";
                            std::cout << motorbikeList->getAt(i)->getBrand();
                            std::cout << std::endl;
                            ++counter;
                            availableNumbers[i] = true;
                        }
                    }
                    std::cout << "----------------------------------------";
                    std::cout << std::endl;


                    if (counter == 0) throw(1); //Aktuell sind alle Motorräder reserviert
                    else
                    {
                        do
                        {

                            std::cout << "Welches Motorrad soll reserviert werden? ";
                            std::cin >> inputAsString;

                            if (!isInteger(inputAsString)) continue;
                            else
                            {
                                input = std::stoi(inputAsString);

                                if (input < 0 || input > 3) continue;
                                if (availableNumbers[input]) break;
                            }

                        } while (true);

                        std::cout << std::endl;
                        std::cout << "Auf welchen Namen soll reserviert werden? ";
                        std::cout << std::endl;

                        std::cout << "Vorname:\t";
                        std::cin >> tempFirstName;
                        std::cout << "Nachname:\t";
                        std::cin >> tempLastName;
                        std::cout << std::endl;

                        //Stammmkunde
                        tempCustomer = customerList->search(tempFirstName, tempLastName);
                        
                        //Neukunde
                        if (tempCustomer == NULL)
                        {
                            std::cout << "Kunde nicht gelistet. Soll er angelegt werden? ";
                            std::cout << std::endl;
                            std::cout << std::endl;
                            std::cout << "[A] Abbrechen [J] Ja     Auswahl: ";
                            std::cin >> question;

                            if (question == 'J')
                            {
                                // Kunde anlegen
                                tempCustomer = new Customer();
                                std::cin >> tempCustomer;
                                customerList->add(tempCustomer);
                                writeCustomerFile(customerList, "customerData.txt");
                            }
                            else throw(2);
                        }

                        //Hat Kunde bereits reserviert oder gebucht?
                        for (int i = 0; i < Motorbike::numberOfMotorbikes; i++)
                        {
                            tempCurrentCustomer = motorbikeList->getAt(i)->getCurrent();

                            if (tempCurrentCustomer != NULL && (tempCurrentCustomer->getFirstName() == tempFirstName && tempCurrentCustomer->getLastName() == tempLastName)) customerHasBooked = true;
                        }


                        if (customerHasBooked) throw(5);//Reservierung oder Buchung vorhanden
                        else
                        {
                            //Führerscheinklasse überprüfen
                            if (tempCustomer->getDrivingLicenceClass() == 'A')
                            {
                                //Reservierung vornehmen
                                tempMotorbike = motorbikeList->getAt(input);
                                tempMotorbike->setCurrent(tempCustomer);
                                tempMotorbike->setIsBooked(true);
                                tempMotorbike->setIsAvailable(true);

                                //Daten schreiben
                                writeBookingFile(motorbikeList, "bookingData.txt");
                            }
                            else throw(3);
                        }
                    }

                    break;

                case 49://Motorrad: Stonieren

                    //Gibt es Reservierung, die stoniert werden können?
                    for (int i = 0; i < Motorbike::numberOfMotorbikes; i++)
                    {
                        if (motorbikeList->getAt(i)->getIsBooked() == true && motorbikeList->getAt(i)->getIsAvailable() == true)
                        {
                            std::cout << "[" << i << "] ";
                            std::cout << motorbikeList->getAt(i)->getBrand();
                            std::cout << std::endl;
                            ++counter;
                            availableNumbers[i] = true;
                        }
                    }


                    if (counter == 0) throw(4);//Keine Stonierung möglich
                    else
                    {
                        do
                        {
                            std::cout << "Welches Motorrad soll stoniert werden? ";
                            std::cin >> inputAsString;

                            if (!isInteger(inputAsString)) continue;
                            else
                            {
                                input = std::stoi(inputAsString);

                                if (input < 0 || input > 3) continue;
                                if (availableNumbers[input]) break;
                            }
                        } while (true);


                        //Stonierung vornehmen
                        tempMotorbike = motorbikeList->getAt(input);
                        tempMotorbike->setCurrent(NULL);
                        tempMotorbike->setIsBooked(false);
                        tempMotorbike->setIsAvailable(true);

                        //Daten schreiben
                        writeBookingFile(motorbikeList, "bookingData.txt");
                    }

                    break;

                case 50://Ausgabe: Vollständiger Bestand

                    motorbikeList->print();

                    break;

                case 51://Ausgabe: Aktueller Bestand      

                    std::cout << std::endl;

                    for (int i = 0; i < Motorbike::numberOfMotorbikes; i++)
                    {
                        if (motorbikeList->getAt(i)->getIsBooked() == false && motorbikeList->getAt(i)->getIsAvailable() == true)
                        {
                            std::cout << motorbikeList->getAt(i)->getBrand();
                            std::cout << std::endl;
                        }
                    }

                    break;

                }
            }
        }
        catch (int errorNumber)
        {
            std::cout << std::endl;

            switch (errorNumber)
            {
            case 0:
                std::cout << "Falsche Eingabe.";
                break;
            case 1:
                std::cout << "Es stehen aktuell keine Motorr" << ae << "der zur Verf" << ue << "gung.";
                break;
            case 2:
                std::cout << "Vorgang abgebrochen. Es soll kein neuer Kunde angelegt werden.";
                break;
            case 3:
                std::cout << "Vorgang abgebrochen. F"<<ue<<"hrerscheinklasse ist nicht korrekt.";
                break;
            case 4:
                std::cout << "Es sind keine Motorr" << ae << "der reserviert.";
                break;
            case 5:
                std::cout << "Kunde hat bereits ein Motorrad reserviert oder im Besitz.";
                break;
            }

            std::cout << std::endl;
        }
        catch (...)
        {
            std::cout << std::endl;
            std::cout << "Unbekannter Fehler.";
            std::cout << std::endl;
        }

        if (selection != 'A')
        {
            std::cout << std::endl;
            std::system("pause");
            std::system("cls");
        }

    } while (selection != 'A');
}
/// <summary>
/// Funktion, welche es ermöglicht ein Motorrad herauszugeben.
/// </summary>
/// <param name="customerList"></param>
/// <param name="motorbikeList"></param>
/// <returns></returns>
void publishMotorbike(List<Customer*>* customerList, List<Motorbike*>* motorbikeList)
{
    try
    {
        int counter = 0;
        int input;
        std::string inputAsString;
        std::string tempFirstName;
        std::string tempLastName;
        bool availableNumbers[4] = { false };
        char question;

        Customer* tempCustomer = NULL;
        Motorbike* tempMotorbike = NULL;

        std::cout << "----------------------------------------";
        std::cout << std::endl;
        for (int i = 0; i < Motorbike::numberOfMotorbikes; i++)
        {
            if (motorbikeList->getAt(i)->getIsAvailable() == true)
            {
                std::cout << "[" << i << "] ";
                std::cout << motorbikeList->getAt(i)->getBrand();
                std::cout << std::endl;
                ++counter;
                availableNumbers[i] = true;
            }
        }
        std::cout << "----------------------------------------";
        std::cout << std::endl;


        if (counter == 0) throw(0);
        else
        {
            do
            {
                std::cout << "Welches Motorrad soll herausgegeben werden? ";
                std::cin >> inputAsString;

                if (!isInteger(inputAsString)) continue;
                else
                {
                    input = std::stoi(inputAsString);

                    if (input < 0 || input > 3) continue;
                    if (availableNumbers[input]) break;
                }
            } while (true);
        }

        std::cout << std::endl;
        std::cout << "Welcher Kunde? ";
        std::cout << std::endl;

        std::cout << "Vorname:\t";
        std::cin >> tempFirstName;
        std::cout << "Nachname:\t";
        std::cin >> tempLastName;
        std::cout << std::endl;

        tempCustomer = customerList->search(tempFirstName, tempLastName);

        if (tempCustomer == NULL)
        {
            std::cout << "Kunde nicht gelistet. Soll er angelegt werden? ";
            std::cout << std::endl;
            std::cout << std::endl;
            std::cout << "[A] Abbrechen [J] Ja     Auswahl: ";
            std::cin >> question;

            if (question == 'J')
            {
                // Kunde anlegen
                tempCustomer = new Customer();
                std::cin >> tempCustomer;
                customerList->add(tempCustomer);
                writeCustomerFile(customerList, "customerData.txt");
            }
            else throw(1);
        }

        //Führerscheinklasse überprüfen
        if (tempCustomer->getDrivingLicenceClass() == 'A')
        {
            //Herausgabe
            tempMotorbike = motorbikeList->getAt(input);
            tempMotorbike->setCurrent(tempCustomer);
            tempMotorbike->setIsBooked(false);
            tempMotorbike->setIsAvailable(false);

            //Daten schreiben
            writeBookingFile(motorbikeList, "bookingData.txt");
        }
        else throw(2);

    }
    catch (int errorNumber)
    {
        std::cout << std::endl;

        switch (errorNumber)
        {
        case 0:
            std::cout << "Es stehen aktuell keine Motorr" << ae << "der zur Verf" << ue << "gung.";
            break;
        case 1:
            std::cout << "Vorgang abgebrochen. Es soll kein neuer Kunde angelegt werden.";
            break;
        case 2:
            std::cout << "Vorgang abgebrochen. F" << ue << "hrerscheinklasse ist nicht korrekt.";
            break;
        }

        std::cout << std::endl;
    }
    catch (...)
    {
        std::cout << std::endl;
        std::cout << "Unbekannter Fehler.";
        std::cout << std::endl;
    }
}
/// <summary>
/// Funktion, welche es ermöglicht ein Motorrad zurückzunehmen.
/// </summary>
/// <param name="motorbikeList"></param>
/// <returns></returns>
void returnMotorbike(List<Motorbike*>* motorbikeList)
{
    try
    {
        int counter = 0;
        int input;
        std::string inputAsString;
        bool availableNumbers[4] = { false };

        Motorbike* tempMotorbike = NULL;

        std::cout << "----------------------------------------";
        std::cout << std::endl;
        for (int i = 0; i < Motorbike::numberOfMotorbikes; i++)
        {
            if (motorbikeList->getAt(i)->getIsAvailable() == false)
            {
                std::cout << "[" << i << "] ";
                std::cout << motorbikeList->getAt(i)->getBrand();
                std::cout << std::endl;
                ++counter;
                availableNumbers[i] = true;
            }
        }
        std::cout << "----------------------------------------";
        std::cout << std::endl;

        if (counter == 0) throw(0);
        else
        {
            do
            {
                std::cout << "Welches Motorrad soll zur"<<ue<<"ckgenommen werden? ";
                std::cin >> inputAsString;

                if (!isInteger(inputAsString)) continue;
                else
                {
                    input = std::stoi(inputAsString);

                    if (input < 0 || input > 3) continue;
                    if (availableNumbers[input]) break;
                }
            } while (true);
        }

        //Zurücknahme vornehmen
        tempMotorbike = motorbikeList->getAt(input);
        tempMotorbike->setCurrent(NULL);
        tempMotorbike->setIsBooked(false);
        tempMotorbike->setIsAvailable(true);

        //Daten schreiben
        writeBookingFile(motorbikeList, "bookingData.txt");
    }
    catch (int errorNumber)
    {
        std::cout << std::endl;

        switch (errorNumber)
        {
        case 0:
            std::cout << "Es k"<<oe<<"nnen aktuell keine Motorr" << ae << "der zur"<<ue<<"ckgenommen werden.";
            break;
        }

        std::cout << std::endl;
    }
    catch (...)
    {
        std::cout << std::endl;
        std::cout << "Unbekannter Fehler.";
        std::cout << std::endl;
    }
}
/// <summary>
/// Funktion, welche es ermöglicht die Kundendaten auszulesen.
/// </summary>
/// <param name="list"></param>
/// <param name="fileName"></param>
/// <returns></returns>
bool readCustomerFile(List<Customer*>* list, std::string fileName)
{
    std::ifstream inputFileStream;
    bool result = false;

    try
    {
        inputFileStream.open(fileName, std::ios::in);//std::ios::in --> Zum Lesen

        if (!inputFileStream.good()) throw(0);
        else
        {
            std::string tempFirstName;
            std::string tempLastName;
            std::string tempStreet;
            int tempHouseNumber;
            int tempPostCode;
            std::string tempCity;
            int tempYearOfBirth;
            std::string tempPhoneNumber;
            char tempDrivingLicenceClass;

            while
                (
                    inputFileStream >>
                    tempFirstName >>
                    tempLastName >>
                    tempStreet >>
                    tempHouseNumber >>
                    tempPostCode >>
                    tempCity >>
                    tempYearOfBirth >>
                    tempPhoneNumber >>
                    tempDrivingLicenceClass
                    )
            {
                //Datensatz vorhanden

                Customer* tempCustomer = new Customer();

                tempCustomer->setFirstName(tempFirstName);
                tempCustomer->setLastName(tempLastName);
                std::string tempAddress = tempStreet + " " + std::to_string(tempHouseNumber) + " | " + std::to_string(tempPostCode) + " " + tempCity;
                tempCustomer->setAddress(tempAddress);
                tempCustomer->setYearOfBirth(tempYearOfBirth);
                tempCustomer->setPhoneNumber(tempPhoneNumber);
                tempCustomer->setDrivingLicenceClass(tempDrivingLicenceClass);

                list->add(tempCustomer);
            }
            result = true;
        }

    }
    catch (int errorNumber)
    {
        switch (errorNumber)
        {
        case 0:
            std::cout << "Keine Kundendaten vorhanden (Datei " << fileName << " konnte nicht ge" << oe << "ffnet werden.)";
            std::cout << std::endl;
            break;
        }

        result = false;
    }
    catch (...)
    {
        std::cout << "Unbekannter Fehler.";
        std::cout << std::endl;

        result = false;
    }

    inputFileStream.close();

    return(result);
}
/// <summary>
/// Funktion, welche es ermöglicht die Kundendaten einzulesen.
/// </summary>
/// <param name="list"></param>
/// <param name="fileName"></param>
/// <returns></returns>
bool writeCustomerFile(List<Customer*>* customerList, std::string fileName)
{
    std::ofstream outputFileStream;
    bool result = false;

    try
    {
        outputFileStream.open(fileName, std::ios::out);//std::ios::out --> Zum Schreiben

        if (!outputFileStream.good()) throw(0);
        else
        {
            for (int i = 0; i < Customer::numberOfCustomers; i++)
            {
                Customer* tempObject = customerList->getAt(i);

                std::string tempFirstName = tempObject->getFirstName();
                std::string tempLastName = tempObject->getLastName();
                std::string tempAddress = tempObject->getAddress();

                std::vector<std::string> tempVector = split(tempAddress, ' ');

                std::string tempStreet;
                std::string tempHouseNumber;
                std::string tempPostCode;
                std::string tempCity;

                for (size_t i = 0; i < tempVector.size(); i++)
                {
                    switch (i)
                    {
                    case 0:
                        tempStreet = tempVector.at(i);
                        break;
                    case 1:
                        tempHouseNumber = tempVector.at(i);
                        break;
                    case 2:
                        continue;
                    case 3:
                        tempPostCode = tempVector.at(i);
                        break;
                    case 4:
                        tempCity = tempVector.at(i);
                        break;
                    }
                }

                std::string tempYearOfBirth = std::to_string(tempObject->getYearOfBirth());
                std::string tempPhoneNumber = tempObject->getPhoneNumber();
                char tempDrivingLicenceClass = tempObject->getDrivingLicenceClass();

                std::string tempOutput = 
                    tempFirstName + " " +
                    tempLastName + " " +
                    tempStreet + " " +
                    tempHouseNumber + " " +
                    tempPostCode + " " +
                    tempCity + " " +
                    tempYearOfBirth + " " +
                    tempPhoneNumber + " " +
                    tempDrivingLicenceClass + "\n";

                outputFileStream.write(tempOutput.data(), tempOutput.size());

            }

            result = true;
        }
    }
    catch (int errorNumber)
    {
        switch (errorNumber)
        {
        case 0:
            std::cout << "Datei " << fileName << " konnte nicht ge" << oe << "ffnet werden.";
            std::cout << std::endl;
            break;
        }

        result = false;
    }
    catch (...)
    {
        std::cout << "Unbekannter Fehler.";
        std::cout << std::endl;

        result = false;
    }

    outputFileStream.close();

    return(result);
}
/// <summary>
/// Funktion, welche es ermöglicht die Reservierungsdaten auszulesen.
/// </summary>
/// <param name="list"></param>
/// <param name="fileName"></param>
/// <returns></returns>
bool readBookingFile(List<Motorbike*>* motorbikeList, List<Customer*>* customerList, std::string fileName)
{
    std::ifstream inputFileStream;
    bool result = false;

    try
    {
        inputFileStream.open(fileName, std::ios::in);//std::ios::in --> Zum Lesen

        if (!inputFileStream.good()) throw(0);
        else
        {
            std::string tempBrandFirst;
            std::string tempBrandLast;
            bool tempIsBooked;
            bool tempIsAvailable;
            std::string tempFirstName;
            std::string tempLastName;
 
            while
                (
                    inputFileStream >> 
                    tempBrandFirst >> 
                    tempBrandLast >> 
                    tempIsBooked >> 
                    tempIsAvailable >> 
                    tempFirstName >> 
                    tempLastName
                )
            {
                //Datensatz vorhanden

                Motorbike* tempMotorbike = motorbikeList->search(tempBrandFirst + " " + tempBrandLast);

                if (tempMotorbike != NULL)
                {
                    tempMotorbike->setIsBooked(tempIsBooked);
                    tempMotorbike->setIsAvailable(tempIsAvailable);
                    tempMotorbike->setCurrent(customerList->search(tempFirstName, tempLastName));
                }
                else throw(1);
            }
            result = true;
        }
    }
    catch (int errorNumber)
    {
        switch (errorNumber)
        {
        case 0:
            std::cout << "Keine Reservierungen vorhanden (Datei " << fileName << " konnte nicht ge" << oe << "ffnet werden.)";
            std::cout << std::endl;
            break;
        case 1:
            std::cout << "Motorrad exisitiert nicht.";
            std::cout << std::endl;
        }

        result = false;
    }
    catch (...)
    {
        std::cout << "Unbekannter Fehler.";
        std::cout << std::endl;

        result = false;
    }

    inputFileStream.close();

    return(result);
}
/// <summary>
/// Funktion, welche es ermöglicht die Reservierungsdaten einzulesen.
/// </summary>
/// <param name="list"></param>
/// <param name="fileName"></param>
/// <returns></returns>
bool writeBookingFile(List<Motorbike*>* motorbikeList, std::string fileName)
{
    std::ofstream outputFileStream;
    bool result = false;

    try
    {
        outputFileStream.open(fileName, std::ios::out);//std::ios::out --> Zum Schreiben

        if (!outputFileStream.good()) throw(0);
        else
        {
            for (int i = 0; i < Motorbike::numberOfMotorbikes; i++)
            {
                Motorbike* tempObject = motorbikeList->getAt(i);
                Customer* tempCustomer = tempObject->getCurrent();

                if (tempCustomer == NULL)
                {
                    //Es liegt keine Reservierung oder Herausgabe vor
                    continue;
                }
                else
                {
                    std::string tempFirstBrand;
                    std::string tempLastBrand;
                    std::string tempIsBooked = std::to_string(tempObject->getIsBooked());
                    std::string tempIsAvailable = std::to_string(tempObject->getIsAvailable());
                    std::string tempFirstName = tempCustomer->getFirstName();
                    std::string tempLastName = tempCustomer->getLastName();

                    std::vector<std::string> tempVector = split(tempObject->getBrand(), ' ');

                    for (size_t i = 0; i < tempVector.size(); i++)
                    {
                        switch (i)
                        {
                        case 0:
                            tempFirstBrand = tempVector.at(i);
                            break;
                        case 1:
                            tempLastBrand = tempVector.at(i);
                            break;
                        }
                    }

                    std::string tempOutput =
                        tempFirstBrand + " " +
                        tempLastBrand + " " +
                        tempIsBooked + " " +
                        tempIsAvailable + " " +
                        tempFirstName + " " +
                        tempLastName + "\n";

                    outputFileStream.write(tempOutput.data(), tempOutput.size());

                }
            }

            result = true;
        }
    }
    catch (int errorNumber)
    {
        switch (errorNumber)
        {
        case 0:
            std::cout << "Datei " << fileName << " konnte nicht ge" << oe << "ffnet werden.";
            std::cout << std::endl;
            break;
        }

        result = false;
    }
    catch (...)
    {
        std::cout << "Unbekannter Fehler.";
        std::cout << std::endl;

        result = false;
    }

    outputFileStream.close();

    return(result);
}
/// <summary>
/// Funktion, die einen übergebene Zeichenkette anhand eines Delimiters teilt.
/// </summary>
/// <param name="x"></param>
/// <param name="delim"></param>
/// <returns></returns>
std::vector<std::string> split(std::string x, char delim)
{
    x += delim;

    std::vector<std::string> splitted;

    std::string temp = "";

    for (size_t i = 0; i < x.length(); i++)
    {
        if (x[i] == delim)
        {
            splitted.push_back(temp);
            temp = "";
            i++;
        }
        temp += x[i];
    }
    return (splitted);
}
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
#pragma endregion

/* HAUPTPROGRAMM */
int main(void)
{
    //Einstellungen
    std::cout << std::boolalpha;//Ausgabe von "false" und "true" statt "0" und "1"

    //Listen
    List<Customer*>* customerList = new List<Customer*>();
    List<Motorbike*>* motorbikeList = new List<Motorbike*>();
   
    //Listenelemente
    Motorbike b1 = Motorbike();
    Motorbike b2 = Motorbike();
    Motorbike b3 = Motorbike();
    Motorbike b4 = Motorbike();

    b1.setBrand("Suzuki Bandit");
    b2.setBrand("Honda TransAlp");
    b3.setBrand("BMW F650GS");
    b4.setBrand("Kawasaki ZZR1400");

    motorbikeList->add(&b1);
    motorbikeList->add(&b2);
    motorbikeList->add(&b3);
    motorbikeList->add(&b4);

    //Dateien auslesen
    readCustomerFile(customerList, "customerData.txt");
    readBookingFile(motorbikeList, customerList, "bookingData.txt");

    writeBookingFile(motorbikeList, "bookingData.txt");

    //Ausgabe Anzahl von Objekten
    std::cout << std::endl;
    std::cout << "Anzahl bekannter Kunden: " << Customer::numberOfCustomers;
    std::cout << std::endl;
    std::cout << "Anzahl bekannter Motorr"<<ae<<"der: " << Motorbike::numberOfMotorbikes;
    std::cout << std::endl;

    //Warte auf Benutzereingabe
    std::cout << std::endl;
    std::system("pause");
    std::system("cls");

    //Benutzeroberfläche
    userInterfaceHomePage(customerList,motorbikeList);

    //Freigabe Speicherplatz
    delete customerList;
    delete motorbikeList;

    //Programm beenden
    std::cout << std::endl;
    std::cout << "Programm beendet.";
    std::cout << std::endl;
    std::cout << std::endl;

    return(0);
}
