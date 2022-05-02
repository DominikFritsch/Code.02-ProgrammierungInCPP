/* Projekt: Temperatur */
/* Projektbeschreibung:

    Es ist eine Amerikareise geplant. Jedoch sind dort Temperatur, Entfernung und Währung anders als in Deutschland.
    Um die Planung zu erleichtern, soll ein Programm geschrieben werden,
    welches die Temperatur von Fahrenheit in Celsius umrechnet.

*/

/* Aufgabe 1:

    Die Formel für die Umrechnung lautet: Celsius = ((temperatur_fahrenheit -  32)*5)/9

    Es gilt folgende Anforderungen umzusetzen:

    1.	Begrüßung und Eingabe der Temperatur in Fahrenheit
    2.	Ausgabe der eingegebenen Temperatur in Fahrenheit
    3.	Umrechnung, wobei die 32 aus der Formel als Konstante deklariert wird und mit
        dieser Konstanten die Umrechnung erfolgen soll. 5/9 soll in der Formel stehen bleiben.
    4.	Ausgabe der Temperatur in Celsius

*/

/* Aufgabe 2:

    Schreiben Sie ein Programm, dass die Berechnung von Fahrenheit nach Celsius ausgibt.

    Hierbei soll der Wert von Fahrenheit eingegeben werden können.
    Die Eingabe darf nicht negativ sein und soll solange erfolgen, bis ein Wert größer gleich Null eingegeben wurde.

    Legen Sie anschließend eine Schrittweite und einen Maximalwert fest.

    Anhand einer Schleife soll der Wert von Fahrenheit und der dazugehörige Celsiuswert ausgegeben werden.

    Beispiel

    Eingabe:

        Fahrenheit = 50
        Schrittweite = 5
        Maximalwert = 75

    Ausgabe:

        Fahrenheit: 50	| Celsius: 10
        Fahrenheit: 55	| Celsius: 12.7778
        Fahrenheit: 60	| Celsius: 15.5556
        Fahrenheit: 65	| Celsius: 18.3333
        Fahrenheit: 70	| Celsius: 21.1111
        Fahrenheit: 75	| Celsius: 23.88889

    Erstellen Sie nun eine weitere Schleife (verwenden Sie nun aber aber einen anderen Schleifentyp).
    Geben Sie den Celsiuswert und noch folgenden Text aus:

    -	Wenn es kleiner gleich 10 Grad hat, dann kommt der Text "Prognose: Es wird kalt."
    -	Wenn es kleiner gleich 20 Grad hat, dann kommt der Text "Prognose: Es wird angenehm."
    -	Wenn es größer als 20 Grad hat, dann kommt der Text "Prognose: Es wird heiss."

*/

/* Aufgabe 3:

    Ändern Sie das Programm wie folgt ab:

    Sie möchten nun die Celsiuswerte in einem Feld hinterlegen.
    Legen Sie ein Feld an, dass 10 Celsiuswerte aufnehmen kann.
    Hierbei wird der eingegebene Fahrenheitswerte jeweils in 10er Schritten erhöht.

    Realisieren Sie dies mit einer for-Schleife.

    Geben Sie anschließend die berechneten Celsiuswerte mit dem dazugehörigen Fahrenheitswert
    und der Position im Feld in einer while-Schleife aus.

*/

#pragma region HEADER
#include <iostream>
#include <cstdlib>
#pragma endregion

#pragma region KONSTANTEN
const float FACTOR = 32.0;
#pragma endregion

#pragma region MAKROS
//#define FACTOR 32.0
#pragma endregion


#pragma region DEKLARATION
float calculateTemperatureInCelcius(float);
float getTemperature(void);
void printTable(float);
#pragma endregion

#pragma region DEFINITION
/// <summary>
/// Funktion, welche die Temperatur von Fahrenheit nach Celcius berechnet.
/// </summary>
/// <param name="temperature"></param>
/// <returns></returns>
float calculateTemperatureInCelcius(float temperature)
{
    return(((temperature - FACTOR) * 5.0f) / 9.0f);
}
/// <summary>
/// Funktion, welche die Temperatur in Fahrenheit vom Benutzer abfragt.
/// </summary>
/// <param name=""></param>
/// <returns></returns>
float getTemperature(void)
{
    float temperature;

    do
    {
        std::cout << "Eingabe Temperatur in \370F:\t";
        std::cin >> temperature;
        std::cout << std::endl;

    } while (temperature <= 0.0f);

    return temperature;
}
/// <summary>
/// Funktion, welche die Temperatur in Celsius und eine Prognose ausgibt.
/// </summary>
/// <param name="temperature"></param>
void printTable(float temperature)
{
    const int fieldNumbers = 10;
    float celsiusNumbers[fieldNumbers];

    for (int i = 0; i < sizeof(celsiusNumbers)/sizeof(float); i++)
    {
        celsiusNumbers[i] = calculateTemperatureInCelcius(temperature + (i * 10));
    }

    int i = 0;

    while (i < sizeof(celsiusNumbers) / sizeof(float))
    {
        std::cout << "Fahrenheit: " << temperature + (i * 10) << "\t| " << "Feld [" << i << "] | Celsius: " << celsiusNumbers[i] << std::endl;
        ++i;
    }
}
#pragma endregion


#pragma region HAUPTPROGRAMM
int main(void)
{
    float input;

    std::cout << "Willkommen beim Reiseplaner f\x81r Amerika!";
    std::cout << std::endl;
    std::cout << std::endl;
    input=getTemperature();
    printTable(input);
    std::cout << std::endl;
    std::cout << std::endl;

    std::system("pause");

    return(0);
}
#pragma endregion




