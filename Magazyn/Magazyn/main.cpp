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

int main()
{
    system("chcp 1250>>null");
    wypiszPolecenia();
    char wybranePolecenie = wybor();
    polecenie(wybranePolecenie);
    return 0;
}
