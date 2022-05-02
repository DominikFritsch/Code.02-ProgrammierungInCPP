/* Projekt: AufgabeSkript1_8_6 */

/* Aufgabe:

    Es sei folgendes C++-Programm gegeben:

    #include <iostream>
    #include <cstdlib>
    using namespace std;

    void count();

    int main()
    {
        count();
        count();
        count();

        system("pause");
    }

    void count()
    {
        static int a = 1;

        cout << a << endl;
        a++;
    }

    Was gibt das Programm auf dem Bildschirm aus?

*/

/* Antwort:

    1
    2
    3

*/

#include <iostream>
#include <cstdlib>
using namespace std;

void count();

int main()
{
    count();
    count();
    count();

    system("pause");
}

void count()
{
    static int a = 1;

    cout << a << endl;
    a++;
}