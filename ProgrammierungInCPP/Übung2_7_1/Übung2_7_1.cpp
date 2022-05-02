/* Projekt: Übung2_7_1 */

/* Aufgabe:

	Überladen Sie den '+', den '-' und den '*' Operator so, dass das untenstehende Programm compiliert werden kann.

	Schreiben Sie außerdem eine Methode ausgabe(), welche den Betrag ausgibt.

	Der Cent-Betrag darf nicht negativ sein (falls doch, verringert sich dementsprechend der Euro-Betrag) und
	der Cent-Betrag darf nicht dreistellig sein (der Euro-Betrag erhöht sich solange, bis der Cent-Betrag zweistellig ist).
	Die Zinsen erhöhen den Euro-/Cent-Betrag um den jeweiligen Faktor

	#include <iostream>
	#include <cstdlib>

	using namespace std;

	class Euro
	{
	private:
		int euro;
		int cent;
	};

	int main()
	{
		Euro meinGeld(100,80), deinGeld(45,30), strafe(25,80), unserGeld;
		double zinsen = 3.5;
		unserGeld = meinGeld + deinGeld;
		unserGeld.ausgabe();
		unserGeld = unserGeld - strafe;
		unserGeld.ausgabe();
		unserGeld = unserGeld.operator*(zinsen);
		unserGeld.ausgabe();

		system("pause");
		return 0;
	}

*/

#include <iostream>
#include <cstdlib>

using namespace std;

class Euro
{
	friend Euro& operator+ (Euro& obj1, Euro& obj2);
	friend Euro& operator- (Euro& obj1, Euro& obj2);
	
private:
	int euro = 0;
	int cent = 0;
public:
	Euro() {};
	Euro(int euro, int cent) : euro(euro), cent(cent) {};
	void ausgabe(void)
	{
		std::cout << this->euro << "," << this->cent << " EUR.";
		std::cout << std::endl;
	}
	Euro& operator* (double);
};

Euro& operator+ (Euro& obj1, Euro& obj2)
{
	static Euro result;

	result.euro = obj1.euro + obj2.euro;
	result.cent = obj1.cent + obj2.cent;

	while (result.cent >= 100)
	{
		result.cent = result.cent - 100;
		result.euro++;
	}
	
	return(result);
}

Euro& operator- (Euro& obj1, Euro& obj2)
{
	static Euro result;

	result.euro = obj1.euro - obj2.euro;
	result.cent = obj1.cent - obj2.cent;
	while (result.cent < 0)
	{
		result.cent = 100 + result.cent;
		result.euro--;
	}

	return(result);
}

Euro& Euro::operator*(double zinsen)
{
	this->euro = (int)(this->euro * zinsen);
	this->cent = (int)(this->cent * zinsen);

	if (zinsen > 0)
	{
		while (this->cent >= 100)
		{
			this->cent = this->cent - 100;
			this->euro++;
		}
	}
	else if (zinsen < 0)
	{
		while (this->cent <= -100)
		{
			this->cent = this->cent + 100;
			this->euro--;
		}
	}

	return *this;
}


int main()
{
	Euro meinGeld(100, 80), deinGeld(45, 30), strafe(25, 80), unserGeld;
	double zinsen = 3.5;
	unserGeld = meinGeld + deinGeld;
	unserGeld.ausgabe();
	unserGeld = unserGeld - strafe;
	unserGeld.ausgabe();
	unserGeld = unserGeld.operator*(zinsen);
	unserGeld.ausgabe();

	system("pause");
	return 0;
}