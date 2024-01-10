#include <iostream>
#include <fstream>

namespace dodawaniePracownika {
    struct pracownik {
        char login[20];
        char haslo[30];
    };

    void zapisDoPlikuPracownikow(pracownik p) {
        fstream plik;
        plik.open("pracownicy.dat", ios::out | ios::app);
        if(plik.is_open()) {
            plik.write(reinterpret_cast<char*>(&p),sizeof(p));
            plik.close();
        } else cerr<<"Blad otwarcia pliku z pracownikami."<<endl;
    }
}

using namespace dodawaniePracownika;

void dodaniePracownika() {
    pracownik p;
    cin.ignore();
    std::cout<<"Podaj login pracownika: "; std::cin.getline(p.login, 20, '\n');
    std::cout<<"Podaj has³o pracownika: "; std::cin.getline(p.haslo, 30, '\n');
    zapisDoPlikuPracownikow(p);
}
