#include <iostream>

using namespace std;

void wyborPolecenia(char wybor);
void zaloguj();
void skladanieZamowienia();
void odbiorZamowienia();
void wyborKomunikat() {
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
}

void wyborDzialaniaPoZalogowaniu() {
    system("cls");
    wyborKomunikat();
    char wybor = '0';
    while(wybor != '8' && wybor != '1') {
        cin>>wybor;
        while (wybor < '1' || wybor > '9')
        {
            cout<<"Nie znaleziono takiego polecenia."<<endl;
            cin>>wybor;
        }
        wyborPolecenia(wybor);
        system("cls");
        wyborKomunikat();
    }
}

void wypiszPolecenia() {
    cout<<"Wybierz dzia³anie wybieraj¹c odpowieni¹ cyfrê:"<<endl;
        cout<<"1: Sk³adanie zamówienia."<<endl;
        cout<<"2: Odbiór zamówienia."<<endl;
        cout<<"3: Logowanie (dla pracowników magazynu)"<<endl;
        cout<<"4: Koniec programu."<<endl;
}

char wybor() {
    char wybor = '1';
    cin>>wybor;
    while(wybor < '1' || wybor > '4') {
        cout<<"Nie znaleziono takiego polecenia."<<endl;
        cin>>wybor;
    }
    system("cls");
    return wybor;
}
