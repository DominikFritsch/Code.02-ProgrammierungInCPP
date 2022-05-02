/* Projekt: Übung2_2_5 */

/* Aufgabe:

Gegeben ist folgendes Programm:

	#include <iostream>
	#include <cstdlib>

	using namespace std ;

	void sortiere (int);

	int main ( void )
	{
		int a [10], i;

		cout << "Unsortiertes Array : " << endl;

		for ( i =0; i <10; i ++)
		{
			a [i]= rand()%100;
			cout << a [i] << " ";
		}

		cout << endl;
	
		cout << "Sortiertes Array : " << endl;
		for ( i =0; i <10; i ++) cout << a [i] << " ";

		cout << endl;

		system("pause");
		return 0;
	}

	void sortiere(int x)
	{

	}

	Ändern und erweitern Sie das Programm so, dass die Funktion "sortiere" das übergebene Array sortiert.
	Geben Sie die sortierte Ausgabe in der main-Funktion aus.

*/

#include <iostream>
#include <cstdlib>

using namespace std;

void sortiere(int*);

int main(void)
{
	int a[10], i;

	cout << "Unsortiertes Array : " << endl;

	for (i = 0; i < 10; i++)
	{
		a[i] = rand() % 100;
		cout << a[i] << " ";
	}

	sortiere(a);

	cout << endl;

	cout << "Sortiertes Array : " << endl;
	for (i = 0; i < 10; i++) cout << a[i] << " ";

	cout << endl;

	system("pause");
	return 0;
}

void sortiere(int* x)
{
	for (std::size_t i1 = 0; i1 < 10-1; i1++)
	{
		for (std::size_t i2 = 0; i2 < 10-1-i1; i2++)
		{
			if (*(x+i2) > *(x+i2+1))
			{
				int tempValue = 0;

				tempValue = *(x + i2);
				*(x + i2) = *(x + i2 + 1);
				*(x + i2 + 1) = tempValue;
			}
		}
	}
}