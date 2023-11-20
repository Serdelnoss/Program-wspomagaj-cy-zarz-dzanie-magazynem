#include <iostream>
#include <fstream>
#include <conio.h>

using namespace std;

void komunikat();

bool sprawdzPoprawnoscWpisanejLiczby(string liczba) {
    bool czyPoprawne;
     for(int i = 0; i < liczba.length(); i++) {
        if(liczba[i] < '1' || liczba[i] > '9') return false;
        return true;
    }
}

int zliczIloscRegalow() {
    ifstream plik;
    plik.open("regaly.txt", ios::in);
    if(plik.is_open()) {
        string linia;
        int ile = 0;
        while(getline(plik, linia)) {
            ile++;
        }
        plik.close();
        return ile / 3;
    } else {
        cerr<<"B³¹d otwarcia pliku!"<<endl;
        return 0;
    }
}

void dodanieRegalu() {
    string nazwaRegalu = "";
    string iloscMiejsc;
    cin.ignore();
    cout<<"Podaj nazwê rega³u: "; getline(cin,  nazwaRegalu);
    cout<<"Podaj iloœæ miejsc na regale: "; cin>>iloscMiejsc;
    bool czyPoprawne = sprawdzPoprawnoscWpisanejLiczby(iloscMiejsc);
    if(!czyPoprawne) {
        cerr<<"Bl¹d wprowadzonej iloœci miejsc!"<<endl;
        komunikat();
    } else {
        ofstream plik;
        plik.open("regaly.txt", ios::out | ios::app);
        int iloscRegalow = zliczIloscRegalow();
        if(plik.is_open()) {
            plik<<iloscRegalow + 1<<endl<<nazwaRegalu<<endl<<iloscMiejsc<<endl<<iloscMiejsc<<endl;
            plik.close();
            cout<<"Rega³ poprawnie dodany."<<endl;
            komunikat();
        } else cerr<<"Blad otwarcia pliku!"<<endl;
    }
}


