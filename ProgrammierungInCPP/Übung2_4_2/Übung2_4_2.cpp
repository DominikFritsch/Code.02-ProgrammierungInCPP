/* Projekt: Übung2_4_2 */

/* Aufgabe:

    Erstellen Sie eine Klasse "Rechteck", welches als Attribute eine Länge und Breite hat.
    Erstellen Sie einen passenden Konstruktor, der die Attribute befüllt.

    In der main-Funktion soll ein dynamisches Objekt angelegt werden.

    Erstellen Sie solange ein neues Objekt, bis entweder die Länge oder die Breite gleich Null ist.
    
    Für jedes neu angelegte Objekt soll der Konstruktor aufgerufen,
    der Flächeninhalt berechnet und anschließend ausgegeben werden.

    Geben Sie zum Schluss den Speicher des Objekts frei.

*/

#pragma region HEADER
#include <iostream>
#include <cstdlib>
#include <cstddef>
#include <string>
#pragma endregion

#pragma region DEKLARATION: KLASSE Rechteck
class Rechteck
{
private:
    float length;
    float width;
    float calculateArea(float, float);
public:
    Rechteck();
    Rechteck(float, float);
    ~Rechteck();
    void setLength(float);
    void setWidth(float);
    float getLength(void);
    float getWidth(void);
    void printArea(void);
};
#pragma endregion

#pragma region DEFINITION: KLASSE Rechteck
Rechteck::Rechteck()
{
    this->length = 0.0f;
    this->width = 0.0f;

    std::cout << "Standardkonstruktor: Objekt erstellt.";
    std::cout << std::endl;
}
Rechteck::Rechteck(float length, float width) : length(length), width(width)
{
    //this->length = length;
    //this->width = width;

    std::cout << "Parameterkonstruktor: Objekt erstellt.";
    std::cout << std::endl;

    printArea();
}
Rechteck::~Rechteck()
{
    std::cout << "Dekonstruktor: Objekt gel\x94scht.";
    std::cout << std::endl;
}
void Rechteck::setLength(float length)
{
    this->length = length;
}
void Rechteck::setWidth(float width)
{
    this->width = width;
}
float Rechteck::getLength(void)
{
    return(this->length);
}
float Rechteck::getWidth(void)
{
    return(this->width);
}
float Rechteck::calculateArea(float length, float width)
{
    return(length * width);
}
void Rechteck::printArea(void)
{
    std::cout << "Fl\x84 \bcheninhalt: " << this->calculateArea(this->length, this->width);
    std::cout << std::endl;
    std::cout << std::endl;
}
#pragma endregion

#pragma region HAUPTPROGRAMM
int main(void)
{
    float tempLength;
    float tempWidth;

    Rechteck* pRectangle = new Rechteck();

    do
    {
        
        std::cout << "Eingabe L\x84nge: ";
        std::cin >> tempLength;
        std::cout << "Eingabe Breite: ";
        std::cin >> tempWidth;

        if (!(tempLength == 0.0f || tempWidth == 0.0f))
        {
            delete pRectangle;
            pRectangle = new Rechteck(tempLength, tempWidth);
        }

    } while (!(tempLength==0.0f || tempWidth == 0.0f));

    delete pRectangle;

    std::cout << std::endl;
    std::cout << std::endl;
    std::system("pause");
    return(0);
}


#pragma endregion
