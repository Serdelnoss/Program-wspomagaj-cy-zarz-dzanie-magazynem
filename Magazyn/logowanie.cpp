#include <iostream>
#include <fstream>
#include <cstring>

void wyborDzialania();

namespace logowanie {
    struct daneLogowania {
        char login[20];
        char haslo[30];
    };

    bool czyPoprawneDane(char login[20], char haslo[30]) {
        daneLogowania dl;
        fstream plik;
        plik.open("pracownicy.dat", ios::in);
        if(plik.is_open()) {
            for(int i=1;;i++) {
                plik.read(reinterpret_cast<char*>(&dl),sizeof(dl));
                if (plik.eof()) break;
                if(strcmp(login, dl.login) == 0 && strcmp(haslo, dl.haslo) == 0) {
                    return true;
                }
            }
            plik.close();
            return false;
        } else cerr<<"B³¹d otwarcia pliku z pracownikami"<<endl;
    }
}

using namespace logowanie;

void komunikat();

void zaloguj() {
    daneLogowania dl;
    std::cin.ignore();
    std::cout<<"Podaj login: ";
    std::cin.getline(dl.login, 20, '\n');
    std::cout<<"Podaj has³o: ";
    std::cin.getline(dl.haslo, 30, '\n');
    if(czyPoprawneDane(dl.login, dl. haslo)) {
        wyborDzialaniaPoZalogowaniu();
    } else {
        std::cout<<"Niepoprawny login lub has³o"<<std::endl;
        komunikat();
    }
}
