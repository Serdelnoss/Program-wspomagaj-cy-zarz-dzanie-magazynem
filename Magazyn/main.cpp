#include <iostream>
#include "init.cpp"
#include "wyswietlenieInformacji.cpp"
#include "informacjeORegalach.cpp"
#include "informacjeOTowarach.cpp"
#include "informacjeOZamowieniach.cpp"
#include "wyborPolecenia.cpp"
#include "dodanieRegalu.cpp"
#include "usuniecieRegalu.cpp"
#include "usuniecieTowaru.cpp"
#include "dodanieTowaru.cpp"
#include "dodaniePracownika.cpp"
#include "logowanie.cpp"
#include "pokazaniePracownikow.cpp"
#include "usunieciePracownika.cpp"
#include "odbiorZamowienia.cpp"

using namespace std;

void polecenie(char wybor);
void wypiszPolecenia();
char wybor();
void zaloguj();

int main()
{
    system("chcp 1250>>null");
    char wybranePolecenie = '0';
    while(wybranePolecenie != '4') {
        wypiszPolecenia();
        wybranePolecenie = wybor();
        switch(wybranePolecenie) {
            case '1': {
                skladanieZamowienia();
                break;
            }
            case '2':  {
                odbiorZamowienia();
                break;
            }
            case '3': {
                zaloguj();
                break;
            }
        }
    }
    return 0;
}
