#include <iostream>
#include <fstream>

using namespace std;

void wyswietlInformacjeOZamowieniach(string linia, int nrLinii) {
    switch(nrLinii % 7) {
        case 1: {
            cout<<"Imi�: "<<linia<<endl; break;
        }
        case 2: {
            cout<<"Nazwisko: "<<linia<<endl; break;
        }
        case 3: {
            cout<<"Adres e-mail: "<<linia<<endl; break;
        }
        case 4: {
            cout<<"Numer telefonu: "<<linia<<endl; break;
        }
        case 5: {
            cout<<"Nazwa towaru: "<<linia<<endl; break;
        }
        case 6: {
            cout<<"Sztuk: "<<linia<<endl; break;
        }
        case 0: {
            cout<<"Numer zam�wienia: "<<linia<<endl<<endl; break;
        }
    }
}

void informacjeOZamowieniach() {
    fstream plik;
    plik.open("zamowienia.txt", ios::in);
    if(plik.is_open()) {
        string linia;
        int nrLinii = 1;
        while(getline(plik, linia)) {
            wyswietlInformacjeOZamowieniach(linia, nrLinii);
            nrLinii++;
        }
        plik.close();
    } else cerr<<"B��d otwarcia pliku z zam�wieniami."<<endl;
}
