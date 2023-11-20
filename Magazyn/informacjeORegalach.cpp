#include <iostream>
#include <fstream>

using namespace std;

void wyswietl(int nrLinii, string linia) {
    switch(nrLinii % 4) {
        case 1: {
            cout<<"LP: "<<linia<<endl;
            break;
        } case 2: {
            cout<<"Nazwa: "<<linia<<endl;
            break;
        } case 3: {
            cout<<"Ilo�� miejsc: "<<linia<<"/";
            break;
        } case 0: {
            cout<<linia<<endl;
            cout<<endl;
            break;
        }
    }
}

void informacjeORegalach() {
    system("cls");
    ifstream plik;
    plik.open("regaly.txt", ios::in);
    if(plik.is_open()) {
        string linia;
        int nrLinii = 1;
        cout<<endl;
        while(getline(plik, linia)) {
            wyswietl(nrLinii, linia);
            nrLinii++;
        }
        plik.close();
    } else {
        cerr<<"B��d otwarcia pliku z rega�ami."<<endl;
        getch();
    }
}
