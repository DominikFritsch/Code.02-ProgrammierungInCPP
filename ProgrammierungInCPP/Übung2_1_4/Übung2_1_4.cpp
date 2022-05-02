/* Projekt: Übung2_1_4 */

/* Aufgabe:

    Eine Personendatei enthält folgende vier Datensätze

    Persnr 	Name 	Stunden     Std.lohn
    100 	Meier 	152 	    9.20
    102 	Kunze 	165 	    11.05
    108 	Weber 	190 	    15.50
    111 	Berger 	80 	        14.20

    Definieren Sie eine dazu passende Klasse und lesen Sie diese vier Datensätze in ein Array ein.

    Anschließend sollen die Datensätze formatiert ausgegeben werden, wobei in der 5. Spalte der
    Bruttolohn (Stunden * Std.lohn) ausgewiesen werden soll.

*/

#pragma region HEADER
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <cstddef>
#pragma endregion

#pragma region MAKRO
#define NUMBER_OF_DATASETS 4
#pragma endregion

#pragma region DEKLARATION: KLASSE Person
class Person
{
private:
    int personenNummer;
    std::string name;
    int stunden;
    float stundenLohn;
    float calculateBruttoLohn(void);
public:
    Person();
    ~Person();
    int getPersonenNummer(void);
    std::string getName(void);
    int getStunden(void);
    float getStundenLohn(void);
    void setPersonenNummer(int);
    void setName(std::string);
    void setStunden(int);
    void setStundenLohn(float);
    void printData(void);
};
#pragma endregion

#pragma region DEFINITION: KLASSE Person
//private
float Person::calculateBruttoLohn(void)
{
    return(this->stunden * this->stundenLohn);
}
//public
Person::Person()
{
    this->personenNummer = 0;
    this->name = " ";
    this->stunden = 0;
    this->stundenLohn = 0.0f;
}
Person::~Person()
{
    std::cout << "Person gel\x94scht.";
    std::cout << std::endl;
}
int Person::getPersonenNummer(void) { return(this->personenNummer); }
std::string Person::getName(void) { return(this->name); }
int Person::getStunden(void) { return(this->stunden); }
float Person::getStundenLohn(void) { return(this->stundenLohn); }
void Person::setPersonenNummer(int personenNummer) { this->personenNummer = personenNummer; }
void Person::setName(std::string name) { this->name = name; }
void Person::setStunden(int stunden) { this->stunden = stunden; }
void Person::setStundenLohn(float stundenLohn) { this->stundenLohn = stundenLohn; }
void Person::printData(void)
{
    std::cout << this->personenNummer << " " << this->name << " " << this->stunden << " " << this->stundenLohn << " " << this->calculateBruttoLohn();
    std::cout << std::endl;
}
#pragma endregion

#pragma region HAUPTPROGRAMM
int main(void)
{
    Person persons[NUMBER_OF_DATASETS];
    std::ifstream inputFileStream;

    int counter = -1;
    int tempPersonenNummer;
    std::string tempName;
    int tempStunden;
    float tempStundenLohn;
    std::string headline;

    inputFileStream.open("Daten.txt");

    try
    {
        if (!inputFileStream.good()) throw(0);
        else
        {
            while (true)
            {
                if (counter == -1) std::getline(inputFileStream, headline);
                else
                {
                    inputFileStream >> tempPersonenNummer >> tempName >> tempStunden >> tempStundenLohn;

                    if (!inputFileStream.good()) break;
                    else
                    {
                        persons[counter].setPersonenNummer(tempPersonenNummer);
                        persons[counter].setName(tempName);
                        persons[counter].setStunden(tempStunden);
                        persons[counter].setStundenLohn(tempStundenLohn);
                    }
                }

                ++counter;
            }
        }
    }
    catch (int i)
    {
        switch (i)
        {
        case 0:
            std::cout << "Fehler beim \x99 \bffnen der Datei.";
            break;
        default:
            std::cout << "Fehler";
            break;
        }
        std::cout << std::endl;
    }

    inputFileStream.close();

    std::cout << headline << " Bruttolohn";
    std::cout << std::endl;

    for (counter = 0; counter < NUMBER_OF_DATASETS; counter++) persons[counter].printData();

    std::cout << std::endl;
    std::system("pause");
    return(0);
}
#pragma endregion



