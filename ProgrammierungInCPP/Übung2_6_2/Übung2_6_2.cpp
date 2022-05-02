/* Projekt: Übung2_6_2 */

/* Aufgabe:

    Eine Klasse "Kunde" hat das Attribut Zahlung.
    Neben den Kunden gibt es außerdem Neukunden und Stammkunden.
   
    Jeder Kunde kann eine Zahlung durchführen.
    Sollte die Zahlung vom Neukunden kommen, wird ihm 10% Rabatt gewährt.
    Sollte die Zahlung vom Stammkunden kommen, wird ihm 20% Rabatt gewährt.

    Erstellen Sie 2 Instanzen vom Kunden und vom Stammkunden und eine Instanz vom Neukunden.

    Erstellen Sie eine Methode "Bezahlen", welche als Übergabeparameter eine Referenz vom Typ "Kunden" hat und 
    den zu bezahlenden Betrag.

    Rufen Sie darin die Methode "Zahlung" auf, welche den Zahlungsbetrag für den entsprechen Kunden setzt.
    Geben Sie dort außerdem den Kundentyp und dessen Zahlugsbetrag aus.

*/

#pragma region HEADER
#include <iostream>
#include <cstdlib>
#include <string>
#pragma endregion

#pragma region DEKLARATION: KLASSE Kunde
class Kunde
{
protected:
    float Zahlung = 0.0f;
public:
    virtual void setZahlung(float betrag)
    {
        this->Zahlung = betrag;
        std::cout << "Kunde: Betrag = " << this->Zahlung << " EUR.";
        std::cout << std::endl;
    }
};
#pragma endregion

#pragma region DEFINITION: KLASSE Neukunden
class Neukunden : public Kunde
{
public:
    void setZahlung(float betrag)
    {
        this->Zahlung = betrag * 0.9f;
        std::cout << "Neukunde: Betrag = " << this->Zahlung << " EUR.";
        std::cout << std::endl;
    }
};
#pragma endregion

#pragma region DEFINITION: KLASSE Stammkunden
class Stammkunden : public Kunde
{
public:
    void setZahlung(float betrag)
    {
        this->Zahlung = betrag * 0.8f;
        std::cout << "Stammkunde: Betrag = " << this->Zahlung << " EUR.";
        std::cout << std::endl;
    }
};
#pragma endregion


#pragma region DEKLARATION: Funktion
void Bezahlen(Kunde&, float);
#pragma endregion


#pragma region HAUPTPROGRAMM
int main(void)
{
    Kunde Hansen, Meier;
    Neukunden Mueller;
    Stammkunden Gaston, Baumann;

    Bezahlen(Hansen, 50);
    Bezahlen(Meier, 70);

    Bezahlen(Mueller, 100);

    Bezahlen(Gaston, 200);
    Bezahlen(Baumann, 300);

    std::cout << std::endl;
    std::system("pause");
    return(0);
}
#pragma endregion

#pragma region DEFINITION: Funktion
void Bezahlen(Kunde& kunde, float betrag)
{
    kunde.setZahlung(betrag);
}
#pragma endregion