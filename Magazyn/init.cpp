#include <iostream>

using namespace std;

void wyborPolecenia(char wybor);
void zaloguj();
void skladanieZamowienia();
void odbiorZamowienia();

void wyborDzialaniaPoZalogowaniu() {
    char wybor = '0';
    while(wybor != '8' && wybor != '1') {
        cout <<"Wybierz dzialanie wybierajac odpowiednia cyfre:" << endl;
        cout<<"1: Wyloguj sie."<<endl;
        cout<<"2: Dodanie towaru do magazynu."<<endl;
        cout<<"3: Usuniecie towaru z magazynu."<<endl;
        cout<<"4: Dodanie regalu do magazynu."<<endl;
        cout<<"5: Usuniecie regalu z magazynu."<<endl;
        cout<<"6: Informacje dotyczace stanu magazynu."<<endl;
        cout<<"7: Dodanie pracownika."<<endl;
        cout<<"8: Usuniecie pracownika."<<endl;
        cout<<"9: Wyswietlenie pracownikow."<<endl;
        cin>>wybor;
        while (wybor < '1' || wybor > '9')
        {
            cout<<"Nie znaleziono takiego polecenia."<<endl;
            cin>>wybor;
        }
        wyborPolecenia(wybor);
    }
}

void polecenie(char wybor) {
    switch(wybor) {
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

void init() {
    char wybor = '1';
    while(wybor != '4') {
        cout<<"Wybierz dzia³anie wybieraj¹c odpowieni¹ cyfrê:"<<endl;
        cout<<"1: Sk³adanie zamówienia."<<endl;
        cout<<"2: Odbiór zamówienia."<<endl;
        cout<<"3: Logowanie (dla pracowników magazynu)"<<endl;
        cout<<"4: Koniec programu."<<endl;
        cin>>wybor;
        while(wybor < '1' || wybor > '4') {
            cout<<"Nie znaleziono takiego polecenia."<<endl;
            cin>>wybor;
        }
        system("cls");
        polecenie(wybor);
    }
}
