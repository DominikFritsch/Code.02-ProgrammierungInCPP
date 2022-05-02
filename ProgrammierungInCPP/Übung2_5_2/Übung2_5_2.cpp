/* Projekt: Übung2_5_2 */

/* Aufgabe:

	Erstellen Sie eine Klasse "Film", welche die Attribute Titel, Jahr und Genre beinhaltet.
	Außerdem soll das Attribute "Nachfolger" vorhanden sein, welches auf das nächste Film-Objekt in der Liste zeigt.
	Erstellen Sie einen entsprechenden Konstruktor, der die drei Attribute befüllt.

	Erstellen Sie außerdem eine Klasse "FilmListe", welches die Attribute "Anfang" und "Ende" hat. Beide sind vom Typ "Film".

	Erstellen Sie eine verkettete Liste mit folgenden Methoden in der Klasse Filmliste:

	- hinzufuegen
		Fügt einen Film am Ende der Liste hinzu
	- loeschen
		Löscht die komplette Liste (verwenden Sie hierbei delete, um die einzelnene Elemente vom Speicher zu entfernen)
	- elementeAnzeigen
		Gibt die Filme in der Liste aus (Titel, Jahr, Genre)

	In der Main-Funktion sollen 3 Film-Objekte in die Liste hinzugefügt werden. Geben Sie dann die Liste aus und löschen Sie diese.
	Zum Schluss soll die Filmliste durch einen Destruktor gelöscht werden.

*/

#pragma region HEADER
#include <iostream>
#include <cstdlib>
#include <string>
#pragma endregion

#pragma region DEKLARATION UND DEFINITION: KLASSE Film
class Film
{
	friend class List;

private:
	std::string titel;
	unsigned int year;
	std::string genre;
	Film* next;
public:
	Film() 
	{
		this->titel = "";
		this->year = 0;
		this->genre = "";
		this->next = NULL;
	}
	Film(std::string t, int j, std::string g) : titel(t), year(j), genre(g),next(NULL) {}
};
#pragma endregion

#pragma region DEKLARATION UND DEFINITION: KLASSE List
class List
{
	Film* head;
	Film* tail;

public:

	// Konstruktor
	List()
	{
		head = tail = NULL;
	}

	// Destruktor
	~List()
	{
		std::cout << "Liste gel\x94scht" << std::endl;
	}

	void add(Film film)
	{
		Film* temp = new Film(film);

		if (isEmpty()) tail = head = temp;
		else
		{
			tail->next = temp;
			tail = temp;
			tail->next = NULL;
		}
	}

	bool isEmpty()
	{
		return (head == NULL) ? true : false;
	}

	void remove()
	{
		if (isEmpty()) return;

		while (head->next != NULL)
		{
			Film* temp = head;
			while (temp->next != tail) temp = temp->next;

			delete tail;

			temp->next = NULL;
			tail = temp;
		}
		delete head;
	}

	void showElement()
	{
		Film* p = head;

		while (p != NULL)
		{
			std::cout << "Titel: " << p->titel << "\tJahr: " << p->year << "\tGenre: " << p->genre;
			std::cout << std::endl;
			p = p->next;
		}
	}
};
#pragma endregion

#pragma region HAUPTPROGRAMM
int main(void)
{
	Film film("Star Wars", 1977, "Science-Fiction"), film1("Iron Man 3", 2013, "Action"), film2("Toy Story", 1995, "Animation");

	List filme;
	filme.add(film);
	filme.add(film1);
	filme.add(film2);

	filme.showElement();

	filme.remove();

	std::cout << std::endl;
	std::cout << std::endl;
	std::system("pause");
	return 0;
}
#pragma endregion