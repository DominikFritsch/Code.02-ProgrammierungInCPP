/* Projekt: Übung2_4_4 */

/* Aufgabe:

	Ein Spieler soll gegen insgesamt 3 Monster kämpfen, um zu einem Schatz zu gelangen.

	Erstellen Sie eine Klasse "Kreatur", welche die Attribute Lebenspunkte und Schadenspunkte hat.
	Erstellen Sie eine Unterklasse "Spieler", welche zusätzlich das Attribute Lebenstrank hat.

	Der Spieler hat am Anfang 100 Lebenspunkte und einen Trank, den er einsetzen kann.

	Es soll ein Menü erscheinen, welches immer die aktuelle Lebenspunkte des Spielers ausgibt.
	Es gibt folgende Auswahlmöglichkeiten:

	- Kämpfen
		Ein neues Monster (Kreatur) erscheint, wessens Lebenspunkte zufällig ist (zwischen 30 und 50)
			--> Erstellen Sie hierfür immer ein neues Objekt vom Typ "Kreatur" und weisen Sie es dem dynamischen Objekt zu.
		Es werden die Lebenspunkte vom Spieler und vom Monster ausgegeben.
		Der Angriffsschaden wird durch eine Zufallszahl ermittelt (zwischen 10 und 20).
		Der Spieler greift zuerst das Monster an.
		Hat das Monster weniger als 1 Lebenspunkt, dann erscheint die Meldung, dass es gestorben ist.
		Sollte das Monster nicht tot sein, greift das Monster anschließend den Spieler an.
		Hat der Spieler weniger als 1 Lebenspunkt, dann erscheint die Meldung, dass er gestorben ist
		und wie viele Kreaturen er bereits besiegt hat.
	- Lebenstrank trinken
		Die Lebenspunkte vom Spieler erhöhen sich (zufällig zwischen 20 und 30)!
		Der Trank kann nur einmal eingesetzt werden.
	- Fliehen
		Der Spieler läuft davon [Programmende]. Es wird die Anzahl an besiegten Kreaturen ausgegeben.

	Hat der Spieler 3 Kreaturen besiegt erscheint die Meldung, dass er den Schatz gefunden hat [Programmende].
	Wurde außerdem kein Lebenstrank eingesetzt, erscheint die Meldung, dass er ein "wahrer Held" ist.

	Tipp:

	Binden Sie die Bibliothek <ctime> ein.
	Eine Zufallszahl wird folgendermaßen erstellt:

	srand(time(NULL)); // Zufallszahl anhand der Uhrzeit neu initialisiert, damit nicht immer die gleichen Werte vorkommen
	int zufallszahl = rand() % (maxZahl - minZahl) + minZahl;
	Beispiel: maxZahl = 20, minZahl = 10 --> Zufallszahl zwischen 20 und 10

*/

#pragma region HEADER
#include <iostream> 
#include <cstdlib>
#include <ctime>
#pragma endregion

#pragma region DEKLARATION: KLASSE Kreatur
class Kreatur
{
protected:
	int leben;
	int schaden;
public:
	Kreatur();
	Kreatur(int);
	~Kreatur();
	void setLeben(int); 
	int getLeben(void);  
	void setSchaden(int); 
	int getSchaden(void);
	void attacke(Kreatur*);
};
#pragma endregion

#pragma region DEFINITION: KLASSE Kreatur
Kreatur::Kreatur()
{
	this->leben = 0;
	this->schaden = 0;

	std::cout << "Standardkonsturktor: Kreatur erstellt.";
	std::cout << std::endl;
}
Kreatur::Kreatur(int l) : leben(l) 
{
	std::cout << "Parameterkonstruktor: Kreatur erstellt.";
	std::cout << std::endl;
}
Kreatur::~Kreatur()
{
	std::cout << "Dekonstruktor: Kreatur gel\x94scht.";
	std::cout << std::endl;
}
void Kreatur::setLeben(int leben)
{
	this->leben = leben;
}
int Kreatur::getLeben(void)
{
	return (leben);
}
void Kreatur::setSchaden(int schaden)
{
	this->schaden = schaden;
}

int Kreatur::getSchaden(void)
{
	return (schaden);
}
void Kreatur::attacke(Kreatur* k)
{
	k->leben = k->leben - this->getSchaden();
}
#pragma endregion

#pragma region DEKLARATION: KLASSE Spieler
class Spieler : public Kreatur
{
private:
	bool lebenstrank;
public:
	Spieler();
	~Spieler();
	bool getLebenstrank(void); 
	void useLebenstrank(void);
};
#pragma endregion

#pragma region DEFINITION: KLASSE Spieler
Spieler::Spieler() : Kreatur(100)
{
	this->lebenstrank = true;

	std::cout << "Standardkonsturktor: Spieler erstellt.";
	std::cout << std::endl;
}
Spieler::~Spieler()
{
	std::cout << "Dekonsturktor: Spieler erstellt.";
	std::cout << std::endl;
}
bool Spieler::getLebenstrank()
{
	return (lebenstrank);
}
void Spieler::useLebenstrank(void)
{
	this->lebenstrank = false;
	std::srand((unsigned int)std::time(NULL)); 
	int randomLeben = rand() % (30 - 20) + 20; //Zufallszahl zwischen 20 und 30
	this->leben += randomLeben;
	std::cout << randomLeben << " Lebenpunkte erhalten!";
	std::cout << std::endl;
}
#pragma endregion

#pragma region HAUPTPROGRAMM
int main(void)
{
	bool davonlaufen = false;
	int besiegte_kreaturen = 0;
	int auswahl;
	int randomLeben;
	int randomSchaden;
	Kreatur* monster = new Kreatur();
	Spieler* spieler = new Spieler();

	do
	{
		std::system("cls");
		std::cout << "Lebenspunkte: " << spieler->getLeben();
		std::cout << std::endl;
		std::cout << std::endl;
		std::cout << "--AUSWAHL--";
		std::cout << std::endl;
		std::cout << "[1] K\x84mpfen";
		std::cout << std::endl;
		std::cout << "[2] Lebenstrank trinken";
		std::cout << std::endl;
		std::cout << "[3] Fliehen";
		std::cout << std::endl;

		std::cout << "Auswahl: ";
		std::cin >> auswahl;

		switch (auswahl)
		{
		case 1:
		{
			int tmp = 0;

			std::system("cls");
			monster = new Kreatur(); //Neue Kreatur taucht auf

			std::srand((unsigned int)std::time(NULL));

			randomLeben = rand() % (50 - 30) + 30; //Zufallszahl zwischen 50 und 30

			monster->setLeben(randomLeben);


			do
			{
				std::cout << "Der Spieler hat " << spieler->getLeben() << " Lebenspunkte.";
				std::cout << std::endl;

				std::cout << "Das Monster hat " << monster->getLeben() << " Lebenspunkte.";
				std::cout << std::endl;
				std::cout << std::endl;

				randomSchaden = rand() % (20 - 10) + 10; //Zufallszahl zwischen 20 und 10
				spieler->setSchaden(randomSchaden);  //Schadenspunkte für Spieler werden gesetzt  	

				randomSchaden = rand() % (20 - 10) + 10; //Zufallszahl zwischen 20 und 10
				monster->setSchaden(randomSchaden);  //Schadenspunkte für Monster werden gesetzt  	

				spieler->attacke(monster);

				std::cout << "Spieler hat " << spieler->getSchaden() << " Schaden zugef\x81gt.";
				std::cout << std::endl;

				//Sollte das Monster weniger als 1 Lebenspunkt haben, stirbt es
				if (monster->getLeben() <= 0) 
				{
					std::cout << "Monster ist gestorben!";
					std::cout << std::endl;

					besiegte_kreaturen++;

					if (besiegte_kreaturen == 3)
					{
						std::cout << std::endl;
						std::cout << "Gewonnen! Sie haben den Schatz erreicht!";
						std::cout << std::endl;

						if (spieler->getLebenstrank())
						{
							std::cout << " ...und das ohne einen Lebenstrank einzusetzen! Sie sind ein wahrer Held!";
						}

						std::cout << std::endl;
						std::cout << "Anzahl besiegter Kreaturen: " << besiegte_kreaturen;
						std::cout << std::endl;

						auswahl = 3;
					}
					break;
				}
				else
				{
					monster->attacke(spieler);
				}

				std::cout << "Monster hat " << monster->getSchaden() << " Schaden zugef\x81gt.";
				std::cout << std::endl;
				std::cout << std::endl;
				
				if (spieler->getLeben() <= 0)
				{
					std::cout << "Leider gestorben!";
					std::cout << std::endl;
					std::cout << "Anzahl besiegter Kreaturen: " << besiegte_kreaturen;
					std::cout << std::endl;

					auswahl = 3;

					return (0);
				}

			} while (true);


			std::system("pause");

			break;
		}
		case 2:
		{
			std::system("cls");

			if (spieler->getLebenstrank()) spieler->useLebenstrank();
			else
			{
				std::cout << "Kein Lebenstrank vorhanden.";
				std::cout << std::endl;
			}

			std::system("pause");

			break;
		}
		case 3:
		{
			std::cout << std::endl;
			std::cout << "Sie sind geflohen!";
			std::cout << std::endl;

			std::cout << "Anzahl besiegter Kreaturen: " << besiegte_kreaturen;
			std::cout << std::endl;

			break;
		}
		default:
		{
			std::cout << std::endl;
			std::cout << "Falsche Auswahl!";
			std::cout << std::endl;

			std::system("pause");

			break;
		}
		}
	} while (auswahl != 3);

	delete monster;
	delete spieler;

	return 0;
}
#pragma endregion















