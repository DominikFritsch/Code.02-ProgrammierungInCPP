/* Projekt: QuadrierenUndFläche */
/* Projektbeschreibung: Ein einfaches Programm, um sich mit mathematischen Funktionen vertraut zu machen. */

/* Aufgabe 1:

   Es soll folgendes Programm erstellt werden:

	-	Ausgabe eines Willkommensbildschirms
	-	Eingabeaufforderungen und Eingabe einer Dezimalzahl
	-	Quadrieren der Dezimalzahl (in einer Funktion, Rückgabe ist das Ergebnis 
		[produkt = zahl * zahl]) und Ausgabe des Ergebnisses in der Main-Funktion
	-	Eingabeaufforderungen und Eingabe eines Radius
	-	Berechnung der Kreisfläche (in einer Funktion, keine Rückgabe. 
		Das Ergebnis der Berechnung [flaeche = radius * radius * konstante_pi]) 
		soll in dieser Funktion ausgegeben werden.)
		Die Variable konstante_pi soll als Konstante deklariert und mit dem Wert
		3.14 initialisiert werden.
		Verwenden Sie für die Berechnung [radius * radius] die vorher erstellte Funktion.

*/

#pragma region HEADER
#include <iostream>
#include <cstdlib>
#pragma endregion

#pragma region KONSTANTE VARIABLEN
const float PI = 3.14f;
#pragma endregion

#pragma region DEKLARATION
float calculateSquare(float);
void calculateArea(float);
#pragma endregion

#pragma region DEFINITION
/// <summary>
/// Funktion, welche das Quadrat der übergebenen Zahl berechnet.
/// </summary>
/// <param name="zahl"></param>
/// <returns></returns>
float calculateSquare(float zahl)
{
	float produkt = zahl * zahl;
	return(produkt);
}
/// <summary>
/// Funktion, welche die Kreisfläche in Abhängigkeit des übergebenen Radius berechnet und ausgibt.
/// </summary>
/// <param name=""></param>
void calculateArea(float radius)
{
	float flaeche = calculateSquare(radius) * PI;

	std::cout << "A = r^2 * PI = (" << radius << ")^2 * " << PI << " = " << flaeche;
}
#pragma endregion


#pragma region HAUPTPROGRAMM
int main(void)
{
	float zahl;
	float radius;

	std::cout << "Willkommen!";
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << "Eingabe Dezimalzahl: ";
	std::cin >> zahl;
	std::cout << std::endl;
	std::cout << "Das Quadrat der Zahl " << zahl << " ist: " << calculateSquare(zahl);
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << "---------------------------------------";
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << "Eingabe Radius: ";
	std::cin >> radius;
	std::cout << std::endl;
	calculateArea(radius);
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << "---------------------------------------";
	std::cout << std::endl;
	std::cout << std::endl;

	std::system("pause");

	return(0);

}
#pragma endregion
