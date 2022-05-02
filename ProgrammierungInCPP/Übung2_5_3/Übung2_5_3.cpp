/* Projekt: Übung2_5_3 */

/* Aufgabe:

    Erweitern Sie nachfolgendes Programm um folgendes:

    Objekte (Instanzen) der Klasse Fahrzeug sollen in einer verketteten Liste verwaltet werden.
    Es soll möglich sein, neue Elemente anzulegen und das letzte Element der Liste zu löschen.

*/

#include <iostream>
#include <cstdlib>

using namespace std;

class Fahrzeug
{
protected:
    int Anzahl;
public:
    Fahrzeug()
    {
        this->Anzahl = 0;
    }
    Fahrzeug(int anz) : Anzahl(anz) {}; //Konstruktor mit Elementinitialisierungsliste
    int getAnzahl() const { return Anzahl; }
};

class Auto : public Fahrzeug
{
    // friend Declaration
    friend class Autoliste;
    // Attribute
private:
    int AutoNr;
    float Gewicht;
    Auto* Nachfolger; // Verkettungszeiger zum Nachfolger
// Methoden
public:
    // Konstructor
    Auto(int az = 0, int nr = 0, float gew = 0.0) : Fahrzeug(az), AutoNr(nr), Gewicht(gew), Nachfolger(0) {}
    int getAutoNr() const { return AutoNr; }
    float getGewicht() const { return Gewicht; }
    void print() { cout << "Auto-Nr: " << AutoNr << ", Anzahl Passagiere: " << Anzahl << ", Gewicht: " << Gewicht << endl; }
    Auto* next() { return Nachfolger; }
};

class Autoliste // Liste von Autos
{
private:
    // Kopfzeiger
    Auto* Head;
public:
    // Konstruktor für leere Liste
    Autoliste() : Head(0) { }
    // Einfügen eines Autos an den Anfang der Liste
    void insert(Auto* kp)
    {
        kp->Nachfolger = Head;
        Head = kp;
        cout << "Auto eingef\x81gt." << endl;
    }

    // Entfernen eines Autos vom Anfang der Liste
    Auto* removeFirst()
    {
        Auto* kp = Head;
        if (kp != 0)
        {
            Head = kp->Nachfolger;
            kp->Nachfolger = 0;	// Ist das gleiche wie NULL bzw. null
            cout << "Auto gel\x94scht." << endl;
        }
        return kp;
    }

    // Entfernen eines Autos vom Ende der Liste
    Auto* removeLast()
    {
        Auto* kp = Head;
        if (Head != NULL) // Falls Head nicht null ist (also Liste ist nicht leer)
        {
            //  Falls es keinen Nachfolger gibt, dann Head auf NULL setzen
            if (Head->Nachfolger == NULL)
            {
                Head = NULL;
            }
            else
            {
                // Ansonsten durch die Liste gehen und den letzten Eintrag holen
                Auto* temp = Head;
                while (temp->Nachfolger->Nachfolger != NULL)
                    temp = temp->Nachfolger;

                // Ändere den "Nachfolger" vom vorletzten Node, indem dieser auf null gesetzt wird.
            // Mit free(lastNode); wird der Speicherplatz freigegeben
                Auto* lastNode = temp->Nachfolger;
                temp->Nachfolger = NULL;
                free(lastNode);
            }
        }
        return kp;
    }

    Auto* find(int nr)
    {
        Auto* ap;
        for (ap = begin(); ap != 0; ap = ap->next())
            if (ap->getAutoNr() == nr)
                break;
        return ap;
    }

    // Anfang der Liste (Kopf)
    Auto* begin() const { return Head; }

    // Ist die Liste leer
    bool empty() const { return Head == 0; }
};

int main()

{
    int auswahl = 1;
    Autoliste list;
    int kNr, az;
    float gew;
    Auto* kp;

    do
    {
        system("cls");
        cout << endl << "---- Auto-VERWALTUNG ----" << endl;
        cout << "1. Neues Auto anlegen" << endl;
        cout << "2. Auto l\x94schen" << endl;
        cout << "3. Liste ausgeben" << endl;
        cout << "4. Datensatz suchen" << endl;
        cout << "0. Programm beenden" << endl;
        cout << "Auswahl: ";
        cin >> auswahl;
        cout << endl;

        switch (auswahl)
        {
        case 0: // Ende
            cout << "Bye Bye" << endl;
            break;
        case 1: // Anlegen
            cout << "AutoNr: ";
            cin >> kNr;
            cout << "Anzahl Passagiere: ";
            cin >> az;
            cout << "Gewicht: ";
            cin >> gew;
            list.insert(new Auto(az, kNr, gew));
            system("pause");
            break;
        case 2: // Löschen
            cout << "1. Am Anfang l\x94schen" << endl;
            cout << "2. Am Ende l\x94schen" << endl;
            cout << "Auswahl: ";
            cin >> auswahl;
            if (auswahl == 1)
                list.removeFirst();
            else
                list.removeLast();
            system("pause");
            break;
        case 3: // Liste aller Autos
            for (kp = list.begin(); kp != 0; kp = kp->next())
                kp->print();
            system("pause");
            break;
        case 4: // Auto anhand AutoNr suchen und falls gefunden, dann Anzahl Passagiere/Gewicht ausgeben
            Auto * objekt;
            cout << "Zu suchende AutoNr: ";
            cin >> kNr;
            objekt = list.find(kNr);
            if (objekt == 0)
                cout << "Auto nicht gefunden" << endl;
            else
                cout << "Anzahl Passagiere: " << objekt->getAnzahl() << endl << "Gewicht vom Auto: " << objekt->getGewicht() << endl;
            system("pause");
            break;
        default: // Falsche Auswahl
            cerr << "ERROR: falsche Auswahl" << endl;
            system("pause");
            break;
        }
    } while (auswahl != 0);

    //Alle Elemente in der Liste löschen
    while (!list.empty())
        list.removeFirst();
    system("pause");
    return 0;
}
