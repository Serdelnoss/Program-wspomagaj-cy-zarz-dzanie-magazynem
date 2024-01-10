#include <iostream>
#include <conio.h>

using namespace std;

void informacjeORegalach();
void informacjeOTowarach();
void informacjeOZamowieniach();
void komunikat();

void wyborInformacji(char wybor) {
    switch(wybor) {
            case '1': {
                informacjeOZamowieniach();
                komunikat();
                break;
            }
            case '2': {
                informacjeOTowarach();
                komunikat();
                break;
            }
            case '3': {
                informacjeORegalach();
                komunikat();
                break;
            }
    }
}

void wyswietlenieInformacji() {
    system("cls");
    char wybor;
    cout<<"1: Wy�wietl informacje dotycz�ce zam�wie�"<<endl;
    cout<<"2: Wy�wietl informacje dotycz�ce towar�w"<<endl;
    cout<<"3: Wy�wietl informacje dotycz�ce rega��w"<<endl;
    cin>>wybor;
    if(wybor < '1' || wybor > '3') {
        cerr<<"Niepoprawne polecenie."<<endl;
    } else {
        wyborInformacji(wybor);
    }
}
