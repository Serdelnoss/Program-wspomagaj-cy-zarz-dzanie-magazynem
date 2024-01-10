#include <iostream>
#include <fstream>
#include <conio.h>

void wypisaniePracownikow() {
    struct pracownik {
        char login[20];
        char haslo[30];
    };
    fstream plik;
    pracownik p;
    plik.open("pracownicy.dat", ios::in);
    if(plik.is_open()) {
        for(int i=1;;i++) {
            plik.read(reinterpret_cast<char*>(&p),sizeof(p));
            if (plik.eof()) break;
            cout<<i<<". "<<"login: "<<p.login<<", "<<"haslo: "<<p.haslo<<endl;
        }
        plik.close();
    } else cerr<<"B³¹d otwarcia pliku z pracownikami."<<endl;
}
