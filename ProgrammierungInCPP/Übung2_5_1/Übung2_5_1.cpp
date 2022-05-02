/* Projekt: Übung2_5_1 */

/* Aufgabe:

    Erstellen Sie eine Klasse "Element", welches als public die Attribute
    einen Integer namens "Value" und einen Pointer namens "Next", welcher vom selben Datentyp wie die Klasse ist.

    Erstellen Sie in der main ein Objekt, welches am Anfang NULL ist.
    Geben Sie solange einen Wert ein, bis 0 eingegeben wird. Dies soll das Ender der Liste kennzeichnen.
    Für jeden eingegeben Wert soll ein neues Element erstellt werden. Der eingegebene Wert wird im Attribut "value" hinterlegt.
    Verketten Sie diese Elemente, indem Sie das Anfangsobjekt und das Next-Objekt richtig setzen.

    Geben Sie anschließend die Liste mit den Werten der erstellten Objekte aus.

    Tipp:

    Beim Einfügen eines neuen Elements wird dessen Nachfolger der Anfang der Liste.
    Das neue Element ist anschließend der neue Anfang der Liste.

*/
#pragma region HEADER
#include <iostream>
#include <cstdlib>
#pragma endregion

#pragma region DEKLARATION: KLASSE Element
class Element
{
public:
	int value;
	Element* next;
};
#pragma endregion

#pragma region HAUPTPROGRAMM
int main(void)
{
	int input = 1;
	Element* head = NULL;

	while (input) // solange nicht 0 eingegeben wird
	{
		std::cout << "Wert eingeben: ";
		std::cin >> input;

		Element* objekt = new Element();

		objekt->value = input;
		objekt->next = head;
		head = objekt;
	}

	while (head != NULL)
	{
		std::cout << head->value;
		std::cout << std::endl;
		head = head->next;
	}

	std::cout << std::endl;
	std::cout << std::endl;
	system("pause");
	return 0;
}
#pragma endregion






