#include <iostream>
#include <fstream>
#include <conio.h>

using namespace std;

void informacjeORegalach();
bool sprawdzPoprawnoscWpisanejLiczby(string liczba);
void komunikat();

int sprawdzIleRegalow() {
    fstream plik;
    plik.open("regaly.txt", ios::in);
    if(plik.is_open()) {
        string linia;
        int ileLinii = 1;
        while(getline(plik, linia)) {
            ileLinii++;
        }
        return ileLinii / 3;
        plik.close();
    } else {
        cerr<<"B³¹d otwarcia pliku z rega³ami."<<endl;
        return 0;
    }
}

void komunikatDodaniaTowaru(bool czyPoprawne) {
    if(czyPoprawne == true) {
        remove("regaly.txt");
        rename("regaly1.txt", "regaly.txt");
    } else {
        cerr<<"B³¹d! Nie uda³o sie dodaæ towaru!"<<endl;
    }
}

string dzialanieNaMiejscachWRegale(string ilosc, string linia) {
    int ileMiejscNaRegale = atoi(linia.c_str());
    if(ileMiejscNaRegale < atoi(ilosc.c_str())) {
        cout<<"Brak miejsc na regale!"<<endl;
        return "";
    } else {
        ileMiejscNaRegale -= atoi(ilosc.c_str());
        linia = to_string(ileMiejscNaRegale);
        return linia;
    }
}

bool zapisDoPlikuRegalow(fstream &plik, fstream &plikZapis, string regal, string ilosc) {
    string linia;
    int nrLinii = 1;
    bool czyPoprawne = true;
    while(getline(plik, linia)) {
        if(nrLinii == atoi(regal.c_str()) * 4 - 1) {
            linia = dzialanieNaMiejscachWRegale(ilosc, linia);
            if(linia == "") {
                czyPoprawne = false;
            }
        }
        plikZapis<<linia<<endl;
        nrLinii++;
    }
    plikZapis.close();
    return czyPoprawne;
}

bool zmienPlikZRegalami(string ilosc, string regal) {
    bool czyPoprawne = true;
    fstream plik, plikZapis;
    plik.open("regaly.txt", ios::in);
    if(plik.is_open()) {
        plikZapis.open("regaly1.txt", ios::out);
        if(plik.is_open()) {
            bool czyPoprawne = zapisDoPlikuRegalow(plik, plikZapis, regal, ilosc);
        } else {
            cerr<<"B³¹d otwarcia pliku z rega³ami."<<endl;
            czyPoprawne = false;
        }
        plik.close();
    } else {
        cerr<<"B³¹d otwarcia pliku z rega³ami."<<endl;
        czyPoprawne = false;
    }
    komunikatDodaniaTowaru(czyPoprawne);
    return czyPoprawne;
}

string ktoryRegal(string regal) {
    fstream plik;
    plik.open("regaly.txt", ios::in);
    string linia;
    int nrLinii = 1;
    while(getline(plik, linia)) {
        if(nrLinii == atoi(regal.c_str())  * 4 - 2) {
            return linia;
        }
        nrLinii++;
    }
    plik.close();
}

void zapisDoPlikuTowarow(string nazwa, string ilosc, string regal) {
    ofstream plik;
    plik.open("towary.txt", ios::out | ios::app);
    if(plik.is_open()) {
        bool czyPoprawne = zmienPlikZRegalami(ilosc, regal);
        if(czyPoprawne) {
            plik<<nazwa<<endl;
            plik<<ilosc<<endl;
            string naKtorymRegale = ktoryRegal(regal);
            plik<<naKtorymRegale<<endl;
        }
        plik.close();
    } else {
        cerr<<"B³¹d otwarcia pliku z towarami."<<endl;
    }
}

void dodanieTowaru() {
    string nazwa;
    string ilosc;
    string doKtoregoRegalu;
    cin.ignore();
    cout<<"Podaj nazwe towaru: "; getline(cin, nazwa);
    cout<<"Podaj iloœæ towaru: "; cin>>ilosc;
    if(sprawdzPoprawnoscWpisanejLiczby(ilosc)) {
        informacjeORegalach();
        cout<<endl<<"Do ktorego rega³u dodac towar: "; cin>>doKtoregoRegalu;
        if(sprawdzPoprawnoscWpisanejLiczby(doKtoregoRegalu) && atoi(doKtoregoRegalu.c_str()) <= sprawdzIleRegalow()) {
            zapisDoPlikuTowarow(nazwa, ilosc, doKtoregoRegalu);
        } else cout<<"B³¹d wprowadzonych danych."<<endl;
    } else cout<<"B³¹d wprowadzonych danych."<<endl;
    komunikat();
}
