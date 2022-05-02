/* Projekt: Sortieren */
/* Projektbeschreibung:

    Ein Programm, welches verschiedene Sortier-Algorithmen implementiert.

*/

/* Aufgabe 1:

    Folgendes Programm ist gegeben:

	#include <iostream>
	#include <cstdlib>

	using namespace std;

	int main(int argc, char *argv[])
	{
		string namen[5];
		cout << "Bitte geben Sie 5 Namen ein:" << endl;
		for (int i = 0; i < 5; i++) 
		{
			cout << "Name " << i+1 << ": ";
			cin >> namen[i];
		}

	system("PAUSE");
	return 0;
	}


	Bitte erweitern Sie das Programm:

	- 	Deklarieren und definieren Sie die Funktion sortiere mit 2 Übergabeparameter: 
		Array mit namen und size als integer. Wobei size die Anzahl der Namen repräsentiert. 
		Diese Funktion hat die Aufgabe, die Namen in alphabetischer Reihenfolge zu sortieren. 
	- 	Rufen Sie die Funktion im Programm auf 
	- 	Geben Sie die sortierte Liste mit Namen wieder aus.

*/

/* Aufgabe 2:

	Erweitern Sie das Programm um eine Funktion, die das Bubble-Sort-Verfahren nutzt.

	Sortieren Sie ein mit Zufallszahlen belegtes Array beliebiger Größe mit dem Bubble-Sort Verfahren.
	- Es soll zuerst die unsortierte Ausgabe erscheinen.
	- Geben Sie während dem sortieren immer den Zwischenschritt aus.
	- Zum Schluss soll die sortierte Ausgabe erscheinen.

*/

#pragma region HEADER
#include <iostream>
#include <cstdlib> //void srand (unsigned int seed); int rand (void);
#include <string>
#include <ctime> //time_t time (time_t* timer);
#pragma endregion

#pragma region DEKLARATION
void sortiere(std::string*, int);
void bubbleSort(void);
#pragma endregion


#pragma region HAUPTPROGRAMM
int main(int argc, char* argv[])
{
	std::string namen[5];
	std::cout << "Bitte geben Sie 5 Namen ein:" << std::endl;
	for (int i = 0; i < 5; i++)
	{
		std::cout << "Name " << i + 1 << ": ";
		std::cin >> namen[i];
	}

	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << "-------------------- Aufgabe 1 --------------------";
	std::cout << std::endl;
	std::cout << std::endl;

	sortiere(namen, 5);

	for (int i = 0; i < 5; i++)
	{
		std::cout << "Name: " << namen[i];
		std::cout << std::endl;
	}

	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << "-------------------- Aufgabe 2 --------------------";
	std::cout << std::endl;
	std::cout << std::endl;
	bubbleSort(); 
	std::cout << std::endl;
	std::cout << std::endl;

	std::system("PAUSE");
	return (0);
}
#pragma endregion

#pragma region DEFINITION
/// <summary>
/// Funktion, welche die Namen innerhalb eines Feldes nach dem Bubble-Sort-Verfahren sortiert.
/// </summary>
/// <param name="namen"></param>
/// <param name="size"></param>
void sortiere(std::string* namen, int size)
{
	std::string tempName;

	for (int i1 = 0; i1 < size-1; i1++)
	{
		for (int i2 = 0; i2 < size - 1 - i1; i2++)
		{
			if (namen[i2] > namen[i2 + 1])
			{
				tempName = namen[i2 + 1];
				namen[i2 + 1] = namen[i2];
				namen[i2] = tempName;
			}
		}
	}
}
/// <summary>
/// Funktion, welche ein durch Zufallszahlen initialisiertes Feld nach dem Bubble-Sort-Verfahren sortiert.
/// </summary>
/// <param name=""></param>
void bubbleSort(void)
{
	std::srand((unsigned int)std::time(NULL));

	int numbers[10];

	for (int i = 0; i < sizeof(numbers) / sizeof(int); i++)
	{
		numbers[i] = std::rand()%10 + 1;
	}

	std::cout << "---------- Unsortierte Ausgabe ----------";
	std::cout << std::endl;
	std::cout << std::endl;
	for (int i = 0; i < sizeof(numbers) / sizeof(int); i++)
	{
		std::cout << "Feld [" << i << "] = " << numbers[i];
		std::cout << std::endl;
	}

	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << "---------- Zwischenschritte ----------";
	std::cout << std::endl;
	std::cout << std::endl;

	int tempNumber;

	for (int i1 = 0; i1 < (sizeof(numbers) / sizeof(int))-1; i1++)
	{
		std::cout << "--------------------------------------------------";
		std::cout << std::endl;
		std::cout << "i1 = " << i1;
		std::cout << std::endl;
		std::cout << std::endl;

		for (int i2 = 0; i2 < (signed int)(sizeof(numbers) / sizeof(int)) - 1 - i1; i2++)
		{
			std::cout << "i2 = " << i2 << ": ";

			if (numbers[i2] > numbers[i2 + 1])
			{
				tempNumber = numbers[i2 + 1];
				numbers[i2 + 1] = numbers[i2];
				numbers[i2] = tempNumber;
			}

			for (int j = 0; j < sizeof(numbers) / sizeof(int); j++)
			{
				if (j == (sizeof(numbers) / sizeof(int)) - 1) std::cout << numbers[j];
				else std::cout << numbers[j] << ",";
			}

			std::cout << std::endl;
		}
	}

	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << "---------- Sortierte Ausgabe ----------";
	std::cout << std::endl;
	std::cout << std::endl;
	for (int i = 0; i < sizeof(numbers) / sizeof(int); i++)
	{
		std::cout << "Feld [" << i << "] = " << numbers[i];
		std::cout << std::endl;
	}
}
#pragma endregion