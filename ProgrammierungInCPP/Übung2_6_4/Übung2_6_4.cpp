/* Projekt: Übung2_6_4 */

/* Aufgabe:

    Realisieren Sie die Berechnung des Flächeninhalts eines Rechtecks und eines Dreiecks
    durch eine Basisklasse namens "Polygon". Diese beinhaltet eine virtuelle Funktion namens "flaeche",
    welche 0 zurückgibt. 
    
    Die beiden Kindklassen sollen durch Nutzung dieser Methode deren Flächeninhalt zurückgeben.

    Rechteck: länge*breite
    Dreieck: länge*breite/2

    In der Main-Funktion soll jeweils eine Instanz von jeder Klasse erzeugt werden.
    Anschließend soll jede Instanz auf ein Polygon-Objekt (Zeiger) referenzieren.
    Setzen Sie die Länge und Breite durch Nutzung der jeweiligen Pointer und
    geben Sie deren Flächeninhalte aus.

    Zusatzaufgabe: Verwandeln Sie ihre virtuelle Methode in eine rein virtuelle Methode.
    Ändern Sie anschließend ihre Main-Funktion so ab, dass diese kompilierfähig ist.
    (Der Flächeninhalt von Polygon wird nicht ausgegeben)

*/

#pragma region HEADER
#include <iostream>
#include <cstdlib>
#include <string>
#pragma endregion

/* KLASSE: Polygon */
#pragma region DEFINITION
class Polygon
{
public:
    void setLength(float length)
    {
        this->length = length;
    }
    void setWidth(float width)
    {
        this->width = width;
    }
    /*
    virtual float flaeche(void)
    {
        return(0);
    }
    */
    virtual float flaeche(void) = 0;

protected:
    float length = 0.0f;
    float width = 0.0f;
};
#pragma endregion

/* KLASSE: Rechteck */
#pragma region DEFINITION
class Rechteck : public Polygon
{
public:
    float flaeche(void)
    {
        return(this->length * this->width);
    }
};
#pragma endregion

/* KLASSE: Dreieck */
#pragma region DEFINITION
class Dreieck : public Polygon
{
public:
    float flaeche(void)
    {
        return((this->length * this->width) / 2);
    }
};
#pragma endregion


#pragma region HAUPTPROGRAMM
int main(void)
{
    /*
    Polygon p;
    Rechteck r;
    Dreieck d;

    Polygon* p1;
    Polygon* p2;
    Polygon* p3;

    p1 = &p;
    p2 = &r;
    p3 = &d;

    //Das setzen der Länge und der Breite hat für das Polygon Objekt p1 bei der Ausgabe der Fläche kein Nutzen.
    p1->setLength(2.0f);
    p1->setWidth(3.2f);
    (*p2).setLength(4.3f);
    (*p2).setWidth(3.2f);
    p3->setLength(3.3f);
    p3->setWidth(2.0f);

    std::cout << "Fl\x84 \bcheninhalt Polygon: " << p.flaeche();
    std::cout << std::endl;

    std::cout << "Fl\x84 \bcheninhalt Rechteck: " << (*p2).flaeche();
    std::cout << std::endl;

    std::cout << "Fl\x84 \bcheninhalt Dreieck: " << p3->flaeche();
    std::cout << std::endl;
    */

    //Rein virtuelle Methode
    Rechteck r;
    Dreieck d;

    Polygon* p2;
    Polygon* p3;

    p2 = &r;
    p3 = &d;

    (*p2).setLength(4.3f);
    (*p2).setWidth(3.2f);
    p3->setLength(3.3f);
    p3->setWidth(2.0f);

    std::cout << "Fl\x84 \bcheninhalt Rechteck: " << (*p2).flaeche();
    std::cout << std::endl;

    std::cout << "Fl\x84 \bcheninhalt Dreieck: " << p3->flaeche();
    std::cout << std::endl;


    std::cout << std::endl;
    std::system("pause");
    return(0);
}
#pragma endregion
