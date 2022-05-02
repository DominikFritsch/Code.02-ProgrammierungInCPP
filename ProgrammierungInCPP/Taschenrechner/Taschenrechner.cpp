/* Projekt: Taschenrechner */
/* Projektbeschreibung: Ein einfaches Programm, welches einen Taschenrechner implementiert. */

/* Aufgabe 1:

    Programmieren Sie mithilfe der switch-case Anweisung einen Mini-Taschenrechner, der zwei
    Zahlen und einen Operator (+, -, *, /) einliest und das Ergebnis ausgibt.

    Die Eingabe soll direkt in einer Zeile erfolgen, z.B. 5+4
    Tipp: Sie können bei cin mehrere Variablen verwenden, z.B. cin >> var1 << var2;

    Eine eventuelle Division durch 0 soll abgefangen werden.
 
    Bei Eingabe eines falschen Operators soll eine Fehlermeldung erscheinen.

*/

#pragma region HEADER
#include <iostream>
#include <cstdlib>
#pragma endregion

#pragma region HAUPTPROGRAMM
int main(void)
{
    float operand1;
    float operand2;
    char mathOperator;
    float result = 0.0;
    bool resultExists = true;

    std::cout << "---------- Willkommen beim Taschenrechner ----------";
    std::cout << std::endl;
    std::cout << std::endl;

    std::cout << "M\x94gliche mathematische Operatoren: ";
    std::cout << std::endl;
    std::cout << "+\n-\n*\n/\n";
    std::cout << std::endl;

    std::cout << "Eingabe: ";
    std::cin >> operand1 >> mathOperator >> operand2;

    switch ((int)mathOperator)
    {
    case 43:
        result = operand1 + operand2;
        break;
    case 45:
        result = operand1 - operand2;
        break;
    case 42:
        result = operand1 * operand2;
        break;
    case 47:
        if (operand2 != 0) result = operand1 / operand2;
        else 
        {
            resultExists = false;
            std::cout << std::endl;
            std::cout << "Division durch 0 nicht m\x94glich.";
        }   
        break;
    default:
        resultExists = false;
        std::cout << std::endl;
        std::cout << "Nicht unterst\x81tzter mathematischer Operator.";
        break;
    }

    std::cout << std::endl;
    
    if (resultExists)
    {
        std::cout << "Ergebnis von " << operand1 << " " << mathOperator << " " << operand2 << " = " << result;
    }


    std::cout << std::endl;
    std::cout << std::endl;

    std::system("pause");

    return(0);
}
#pragma endregion

