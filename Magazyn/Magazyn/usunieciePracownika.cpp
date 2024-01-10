#include <iostream>
#include <fstream>

namespace usuwaniePracownika {
    struct pracownik {
        char login[20];
        char haslo[30];
    };

    void zczytanieZPliku(int nrPracownika) {
        pracownik p;
        fstream plikOdczyt, plikZapis;
        plikOdczyt.open("pracownicy.dat", ios::in);
        if(plikOdczyt.is_open()) {
            plikZapis.open("pracownicy1.dat", ios::out);
            if(plikZapis.is_open()) {
                 for(int i=1;;i++) {
                    plikOdczyt.read(reinterpret_cast<char*>(&p),sizeof(p));
                    if (plikOdczyt.eof()) break;
                    if(nrPracownika != i) plikZapis.write(reinterpret_cast<char*>(&p), sizeof(p));
                }
                plikOdczyt.close();
                plikZapis.close();
                remove("pracownicy.dat");
                rename("pracownicy1.dat", "pracownicy.dat");
            } else cerr<<"B��d otwarcia pliku z pracownikami."<<endl;
        } else cerr<<"B��d otwarcia pliku z pracownikami."<<endl;
    }
}

void wypisaniePracownikow();

using namespace usuwaniePracownika;

void usunieciePracownika() {
    wypisaniePracownikow();
    string nrPracownika;
    cout<<"Podaj numer pracownika, kt�ry ma zostac usuni�ty: "; cin>>nrPracownika;
    zczytanieZPliku(atoi(nrPracownika.c_str()));
}
