#include <iostream>
#include <fstream>

using namespace std;

void wyswietlInformacjeOTowarach(int nrLinii, string linia) {
    switch(nrLinii % 3) {
        case 1: {
            cout<<"LP. "<<(nrLinii + 2) / 3<<endl;
            cout<<"Nazwa: "<<linia<<endl;
            break;
        } case 2: {
            cout<<"Iloœæ sztuk: "<<linia<<endl;
            break;
        } case 0: {
            cout<<"Na regale: "<<linia<<endl;
            cout<<endl;
            break;
        }
    }
}

void informacjeOTowarach() {
    system("cls");
    ifstream plik;
    plik.open("towary.txt", ios::in);
    if(plik.is_open()) {
        string linia;
        int nrLinii = 1;
        cout<<endl;
        while(getline(plik, linia)) {
            wyswietlInformacjeOTowarach(nrLinii, linia);
            nrLinii++;
        }
        plik.close();
    } else {
        cerr<<"B³¹d otwarcia pliku z towarami"<<endl;
    }
}
