/* Projekt: Übung2_7_1 */

/* Aufgabe:

	Überladen Sie den Vergleichsoperator, so dass er ausgibt, ob ein Fahrzeug gleich oder nicht gleich ist. 
	Ein Fahrzeug ist gleich, wenn seine Attributwerte übereinstimmen.

	Zusätzlich überladen Sie den größer / kleiner Operator, so dass er ausgibt, ob ein Fahrzeug "älter", "jünger" oder "gleich alt" 
	ist (Attributwert baujahr).

	Verwenden Sie folgendes Ausgangsprogramm:

	#include <iostream>
	#include <cstdlib>

	using namespace std;

	class Fahrzeug
	{
	private:
		string marke;
		string kennzeichen;
		int ps;
		int baujahr;

	public:
		void datenausgeben()
		{
			cout << "Marke: " << marke << endl;
			cout << "Kennzeichen: " << kennzeichen << endl;
			cout << "Anzahl PS: " << ps << endl;
			cout << "Baujahr: " << baujahr << endl;
		}
	};

	int main()
	{

	system("pause");
	return 0;
	};

*/

#pragma region HEADER
#include <iostream>
#include <cstdlib>
#include <string>
#pragma endregion

/* KLASSE: Fahrzeug */
#pragma region DEFINITION
class Fahrzeug
{
private:
	std::string marke;
	std::string kennzeichen;
	int ps;
	int baujahr;

public:

	Fahrzeug(std::string m, std::string k, int p, int bj) : marke(m), kennzeichen(k), ps(p), baujahr(bj) {}

	void datenausgeben() {
		std::cout << "Marke: " << marke;
		std::cout << std::endl;
		std::cout << "Kennzeichen: " << kennzeichen;
		std::cout << std::endl;
		std::cout << "Anzahl PS: " << ps;
		std::cout << std::endl;
		std::cout << "Baujahr: " << baujahr;
		std::cout << std::endl;
	}

	std::string getMarke() { return marke; }
	std::string getKennzeichen() { return kennzeichen; }
	int getPS() { return ps; }
	int getBaujahr() { return baujahr; }

	void operator<=(Fahrzeug f1) {
		if (this->baujahr < f1.baujahr) 
		{
			std::cout << "Fahrzug " << this->getMarke() << " ist \x84lter als " << f1.getMarke();
			std::cout << std::endl;
		}
		else if (this->baujahr > f1.baujahr) {
			std::cout << "Fahrzug " << this->getMarke() << " ist j\x81nger als " << f1.getMarke();
			std::cout << std::endl;
		}
		else {
			std::cout << "Beide Fahrzeuge sind gleich alt";
			std::cout << std::endl;
		}
	}

};
#pragma endregion

/* OPERATORÜBERLADUNG: Extern */
#pragma region DEFINITION
void operator==(Fahrzeug f1, Fahrzeug f2) {
	if (f1.getMarke() == f2.getMarke() && f1.getKennzeichen() == f2.getKennzeichen() && f1.getPS() == f2.getPS() && f1.getBaujahr() == f2.getBaujahr())
	{
		std::cout << "Fahrzeuge sind gleich";
		std::cout << std::endl;
	}
	else {
		std::cout << "Fahrzeuge sind nicht gleich";
		std::cout << std::endl;
	}
}
#pragma endregion

#pragma region HAUPTPROGRAMM
int main(void) {

	//Instanz anlegen
	Fahrzeug fz1("Opel", "PA AA 333", 66, 1999);
	Fahrzeug fz2("BMW", "DEG DD 222", 103, 2005);

	//Vergleichsoperator wird aufgerufen
	fz1 == fz2;

	//Größer / kleiner Operator
	fz1 <= fz2;

	std::cout << std::endl;
	std::system("pause");
	return 0;
};
#pragma endregion
