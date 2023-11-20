#include <iostream>

using namespace std;

void dodanieRegalu();
void usuniecieRegalu();
void wyswietlenieInformacji();
void dodanieTowaru();
void usuniecieTowaru();
void skladanieZamowienia();
void dodaniePracownika();
void wypisaniePracownikow();
void usunieciePracownika();

void komunikat() {
    cout<<"Wciœnij dowolny przycisk, aby kontynuowaæ..."<<endl;
    getch();
    system("cls");
}

void wyborPolecenia(char wybor) {
    system("cls");
    switch(wybor) {
        case '2':
            dodanieTowaru(); break;
        case '3':
            usuniecieTowaru(); break;
        case '4':
            dodanieRegalu(); break;
        case '5':
            usuniecieRegalu(); break;
        case '6':
            wyswietlenieInformacji(); break;
        case '7':
            dodaniePracownika();
            komunikat(); break;
        case '8':
            usunieciePracownika();
            komunikat(); break;
        case '9':
            wypisaniePracownikow();
            komunikat(); break;
    }
}

