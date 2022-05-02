/* Projekt: Datentypen */
/* Projektbeschreibung: Ein einfaches Programm, um sich mit den einzelnen Datentypen vertraut zu machen. */

/* Aufgabe 1:

    Erstellen Sie für jeden Punkt eine Variable mit dem passenden Datentyp:

    -	Ganzzahl
    -	Dezimalzahl
    -	Zeichenkette bzw. Text
    -	Zeichen bzw. Buchstabe
    -	Wahrheitswert

    Weisen Sie Ihnen einen Wert zu und geben sie anschließend diese Werte auf dem Bildschirm aus.

*/

#pragma region HEADER
#include <iostream>
#include <cstdlib>
#include <string>
#include <limits>
#pragma endregion

#pragma region DEKLARATION
void printValues(void);
void printExtendedValues(void);
#pragma endregion

#pragma region DEFINITION
/// <summary>
/// Funktion, welche Datentypen entsprechend der Aufgabenbeschreibung auf der Konsole ausgibt.
/// </summary>
/// <param name=""></param>
void printValues(void)
{
    //Lokale Variablen
    int integerValue;
    float floatValue;
    double doubleValue;
    bool boolValue;
    char charValue;
    std::string stringValue;

    integerValue = 1;
    floatValue = 2.0f;
    doubleValue = 3.0;
    boolValue = true;
    charValue = 'a';
    stringValue = "4.0";

    std::cout << "Integer-Wert: \t" << integerValue << std::endl;
    std::cout << "Float-Wert: \t" << floatValue << std::endl;
    std::cout << "Double-Wert: \t" << doubleValue << std::endl;
    std::cout << "Bool-Wert: \t" << boolValue << std::endl;
    std::cout << "Char-Wert: \t" << charValue << std::endl;
    std::cout << "String-Wert: \t" << stringValue << std::endl;

}
/// <summary>
/// Funktion, welche alle elementaren Datentypen mit exakten Informationen auf der Konsole ausgibt.
/// Benötigt überwiegend die HEADER-Datei <limits>.
/// </summary>
/// <param name=""></param>
void printExtendedValues(void)
{
    std::cout << "Size of size_t = " << sizeof(std::size_t) << std::endl << std::endl;

    std::cout << "Datentyp bool min. Wert: " << std::numeric_limits<bool>::min() << std::endl;
    std::cout << "Datentyp bool max. Wert: " << std::numeric_limits<bool>::max() << std::endl;
    std::cout << "Vorzeichenbehaftet: " << std::numeric_limits<bool>::is_signed << std::endl;
    std::cout << "Nicht vorzeichenbehaftete Bits: " << std::numeric_limits<bool>::digits << std::endl;
    std::cout << "Hat Unendlichkeit: " << std::numeric_limits<bool>::has_infinity << std::endl << std::endl;

    std::cout << "Datentyp char min. Wert: " << std::numeric_limits<char>::min() << std::endl;
    std::cout << "Datentyp char max. Wert: " << std::numeric_limits<char>::max() << std::endl;
    std::cout << "Vorzeichenbehaftet: " << std::numeric_limits<char>::is_signed << std::endl;
    std::cout << "Nicht vorzeichenbehaftete Bits: " << std::numeric_limits<char>::digits << std::endl;
    std::cout << "Hat Unendlichkeit: " << std::numeric_limits<char>::has_infinity << std::endl << std::endl;

    std::cout << "Datentyp unsigned char min. Wert: " << std::numeric_limits<unsigned char>::min() << std::endl;
    std::cout << "Datentyp unsigned char max. Wert: " << std::numeric_limits<unsigned char>::max() << std::endl;
    std::cout << "Vorzeichenbehaftet: " << std::numeric_limits<unsigned char>::is_signed << std::endl;
    std::cout << "Nicht vorzeichenbehaftete Bits: " << std::numeric_limits<unsigned char>::digits << std::endl;
    std::cout << "Hat Unendlichkeit: " << std::numeric_limits<unsigned char>::has_infinity << std::endl << std::endl;

    std::cout << "Datentyp int min. Wert: " << std::numeric_limits<int>::min() << std::endl;
    std::cout << "Datentyp int min. Wert: " << INT_MIN << std::endl;
    std::cout << "Datentyp int max. Wert: " << std::numeric_limits<int>::max() << std::endl;
    std::cout << "Datentyp int max. Wert: " << INT_MAX << std::endl;
    std::cout << "Vorzeichenbehaftet: " << std::numeric_limits<int>::is_signed << std::endl;
    std::cout << "Nicht vorzeichenbehaftete Bits: " << std::numeric_limits<int>::digits << std::endl;
    std::cout << "Hat Unendlichkeit: " << std::numeric_limits<int>::has_infinity << std::endl << std::endl;

    std::cout << "Datentyp unsigned int min. Wert: " << std::numeric_limits<unsigned int>::min() << std::endl;
    std::cout << "Datentyp unsigned int max. Wert: " << std::numeric_limits<unsigned int>::max() << std::endl;
    std::cout << "Datentyp unsigned int max. Wert: " << UINT_MAX << std::endl;
    std::cout << "Vorzeichenbehaftet: " << std::numeric_limits<unsigned int>::is_signed << std::endl;
    std::cout << "Nicht vorzeichenbehaftete Bits: " << std::numeric_limits<unsigned int>::digits << std::endl;
    std::cout << "Hat Unendlichkeit: " << std::numeric_limits<unsigned int>::has_infinity << std::endl << std::endl;

    std::cout << "Datentyp short min. Wert: " << std::numeric_limits<short>::min() << std::endl;
    std::cout << "Datentyp short min. Wert: " << SHRT_MIN << std::endl;
    std::cout << "Datentyp short max. Wert: " << std::numeric_limits<short>::max() << std::endl;
    std::cout << "Datentyp short max. Wert: " << SHRT_MAX << std::endl;
    std::cout << "Vorzeichenbehaftet: " << std::numeric_limits<short>::is_signed << std::endl;
    std::cout << "Nicht vorzeichenbehaftete Bits: " << std::numeric_limits<short>::digits << std::endl;
    std::cout << "Hat Unendlichkeit: " << std::numeric_limits<short>::has_infinity << std::endl << std::endl;
    
    std::cout << "Datentyp unsigned short min. Wert: " << std::numeric_limits<unsigned short>::min() << std::endl;
    std::cout << "Datentyp unsigned short max. Wert: " << std::numeric_limits<unsigned short>::max() << std::endl;
    std::cout << "Datentyp unsigned short max. Wert: " << USHRT_MAX << std::endl;
    std::cout << "Vorzeichenbehaftet: " << std::numeric_limits<unsigned short>::is_signed << std::endl;
    std::cout << "Nicht vorzeichenbehaftete Bits: " << std::numeric_limits<unsigned short>::digits << std::endl;
    std::cout << "Hat Unendlichkeit: " << std::numeric_limits<unsigned short>::has_infinity << std::endl << std::endl;

    std::cout << "Datentyp long min. Wert: " << std::numeric_limits<long>::min() << std::endl;
    std::cout << "Datentyp long min. Wert: " << LONG_MIN << std::endl;
    std::cout << "Datentyp long max. Wert: " << std::numeric_limits<long>::max() << std::endl;
    std::cout << "Datentyp long max. Wert: " << LONG_MAX << std::endl;
    std::cout << "Vorzeichenbehaftet: " << std::numeric_limits<long>::is_signed << std::endl;
    std::cout << "Nicht vorzeichenbehaftete Bits: " << std::numeric_limits<long>::digits << std::endl;
    std::cout << "Hat Unendlichkeit: " << std::numeric_limits<long>::has_infinity << std::endl << std::endl;

    std::cout << "Datentyp unsigned long min. Wert: " << std::numeric_limits<unsigned long>::min() << std::endl;
    std::cout << "Datentyp unsigned long max. Wert: " << std::numeric_limits<unsigned long>::max() << std::endl;
    std::cout << "Datentyp unsigned long max. Wert: " << ULONG_MAX << std::endl;
    std::cout << "Vorzeichenbehaftet: " << std::numeric_limits<unsigned long>::is_signed << std::endl;
    std::cout << "Nicht vorzeichenbehaftete Bits: " << std::numeric_limits<unsigned long>::digits << std::endl;
    std::cout << "Hat Unendlichkeit: " << std::numeric_limits<unsigned long>::has_infinity << std::endl << std::endl;

    std::cout << "Datentyp float min. Wert: " << std::numeric_limits<float>::min() << std::endl;
    std::cout << "Datentyp float min. Wert: " << FLT_MIN << std::endl;
    std::cout << "Datentyp float max. Wert: " << std::numeric_limits<float>::max() << std::endl;
    std::cout << "Datentyp float max. Wert: " << FLT_MAX << std::endl;
    std::cout << "Vorzeichenbehaftet: " << std::numeric_limits<float>::is_signed << std::endl;
    std::cout << "Nicht vorzeichenbehaftete Bits: " << std::numeric_limits<float>::digits << std::endl;
    std::cout << "Hat Unendlichkeit: " << std::numeric_limits<float>::has_infinity << std::endl << std::endl;

    std::cout << "Datentyp double min. Wert: " << std::numeric_limits<double>::min() << std::endl;
    std::cout << "Datentyp double min. Wert: " << DBL_MIN << std::endl;
    std::cout << "Datentyp double max. Wert: " << std::numeric_limits<double>::max() << std::endl;
    std::cout << "Datentyp double max. Wert: " << DBL_MAX << std::endl;
    std::cout << "Vorzeichenbehaftet: " << std::numeric_limits<double>::is_signed << std::endl;
    std::cout << "Nicht vorzeichenbehaftete Bits: " << std::numeric_limits<double>::digits << std::endl;
    std::cout << "Hat Unendlichkeit: " << std::numeric_limits<double>::has_infinity << std::endl << std::endl;

    std::cout << "Datentyp long double min. Wert: " << std::numeric_limits<long double>::min() << std::endl;
    std::cout << "Datentyp long double min. Wert: " << LDBL_MIN << std::endl;
    std::cout << "Datentyp long double max. Wert: " << std::numeric_limits<long double>::max() << std::endl;
    std::cout << "Datentyp long double max. Wert: " << LDBL_MAX << std::endl;
    std::cout << "Vorzeichenbehaftet: " << std::numeric_limits<long double>::is_signed << std::endl;
    std::cout << "Nicht vorzeichenbehaftete Bits: " << std::numeric_limits<long double>::digits << std::endl;
    std::cout << "Hat Unendlichkeit: " << std::numeric_limits<long double>::has_infinity << std::endl << std::endl;

}
#pragma endregion


#pragma region HAUPTPROGRAMM
int main(void)
{
    printValues();
    std::cout << std::endl;
    std::cout << "------------------------------------------------" << std::endl;
    std::cout << std::endl;
    printExtendedValues();

    std::system("pause");

    return(0);
}
#pragma endregion

