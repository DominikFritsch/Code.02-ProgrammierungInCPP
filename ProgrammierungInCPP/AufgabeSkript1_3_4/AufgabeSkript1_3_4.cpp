/* Projekt: AufgabeSkript1_3_4 */

/* Aufgabe:

    Ergänzen Sie den folgenden Quelltextauszug zu einem lauffähigen Programm und experimentieren Sie
    damit.

	switch (UeberGeschwindigkeitsbegrenzung)
	{
	case 0:
		Strafe = 0;
		break;
	case 10:
		Strafe = 20;
		break;
	case 15:
		Strafe = 30;
		break;
	case 20:
	case 25:
	case 30:
		Strafe = UeberGeschwindigkeitsbegrenzung * 10;
		break;
	default:
		Strafe = Berechnung();
		break;
	}

*/

#pragma region HEADER
#include <iostream>
#include <cstdlib>
#pragma endregion

#pragma region DEKLARATION
int Berechnung(int);
#pragma endregion

#pragma region DEFINITION
int Berechnung(int UeberGeschwindigkeitsbegrenzung)
{
	if (UeberGeschwindigkeitsbegrenzung < 0) return(0);
	else return(UeberGeschwindigkeitsbegrenzung * 2);
}
#pragma endregion


#pragma region HAUPTPROGRAMM
int main(void)
{
	int UeberGeschwindigkeitsbegrenzung;
	int Strafe;

	std::cout << "Eingabe Geschwindigkeits\x81 \bberschreitung: ";
	std::cin >> UeberGeschwindigkeitsbegrenzung;

	switch (UeberGeschwindigkeitsbegrenzung)
	{
	case 0:
		Strafe = 0;
		break;
	case 10:
		Strafe = 20;
		break;
	case 15:
		Strafe = 30;
		break;
	case 20:
		Strafe = 40;
		break;
	case 25:
		Strafe = 50;
		break;
	case 30:
		Strafe = UeberGeschwindigkeitsbegrenzung * 10;
		break;
	default:
		Strafe = Berechnung(UeberGeschwindigkeitsbegrenzung);
		break;
	}

	std::cout << "Festgelegte Strafe: " << Strafe;

	std::cout << std::endl;
	std::cout << std::endl;

	std::system("pause");

	return(0);
}
#pragma endregion



