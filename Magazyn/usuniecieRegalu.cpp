#include <iostream>
#include <fstream>

using namespace std;

void informacjeORegalach();
void komunikat();
bool sprawdzPoprawnoscWpisanejLiczby(string liczba);

struct regal {
    string nr;
    string nazwa;
    string ileWolnychMiejsc;
    string ileMaksymalnieMiejsc;
};

int ileRegalow() {
    fstream plik;
    plik.open("regaly.txt", ios::in);
    int ileRegalow = 0;
    if(plik.is_open()) {
        string linia;
        while(getline(plik, linia)) {
            ileRegalow++;
        }
        return ileRegalow;
    } else {
        cerr<<"Blad otwarcia pliku z regalami."<<endl;
        return 0;
    }
}

regal *zczytanieRegalow() {
    int iloscRegalow = ileRegalow() / 4;
    regal *r = new regal[iloscRegalow];
    fstream plik;
    plik.open("regaly.txt");
    if(plik.is_open()) {
        string linia;
        int nrLinii = 1;
        int index = 0;
        while(getline(plik, linia)) {
            if(nrLinii % 4 == 1) r[index].nr = linia;
            if(nrLinii % 4 == 2) r[index].nazwa = linia;
            if(nrLinii % 4 == 3) r[index].ileWolnychMiejsc = linia;
            if(nrLinii % 4 == 0) {
                r[index].ileMaksymalnieMiejsc = linia;
                index++;
            }
            nrLinii++;
        }
        plik.close();
        return r;
    } else {
        cerr<<"Blad otwarcia pliku z regalami."<<endl;
    }
}

bool sprawdzenieCzyRegalJestPusty(int indeks) {
    fstream plik;
    plik.open("regaly.txt", ios::in);
    string tmpLinia1, tmpLinia2;
    if(plik.is_open()) {
        int nrLinii = 0;
        string linia;
        while(getline(plik, linia)) {
            if(indeks * 4 - 2 == nrLinii || indeks * 4 - 1 == nrLinii) {
                if(nrLinii % 4 == 2) {
                    tmpLinia1 = linia;
                }
                if(nrLinii % 4 == 3) {
                    tmpLinia2 = linia;
                }
            }
            nrLinii++;
        }
        plik.close();
    }
    if(tmpLinia1 != tmpLinia2) {
        return false;
    } else return true;
}

void zapisRegalowDoPliku(regal *r, int wybor) {
    if(sprawdzenieCzyRegalJestPusty(wybor)) {
         fstream plikZapis;
        plikZapis.open("regaly1.txt", ios::out);
        if(plikZapis.is_open()) {
            int ileJestRegalow = ileRegalow() / 4;
            for(int i = 0; i < ileJestRegalow; i++) {
                if(i != wybor - 1) {
                    plikZapis<<r[i].nr<<endl<<r[i].nazwa<<endl<<r[i].ileWolnychMiejsc<<endl<<r[i].ileMaksymalnieMiejsc<<endl;
                }
            }
            plikZapis.close();
            remove("regaly.txt");
            rename("regaly1.txt", "regaly.txt");
        } else cerr<<"Blad otwarcia pliku."<<endl;
    } else {
        cout<<"Regal nie jest pusty, nie mozna go usunac."<<endl;
        cout<<"Wcisnij dowolny przycisk, aby kontynuowac."<<endl;
        getch();
    }
}

void usuniecieRegalu() {
    string wybor;
    informacjeORegalach();
    cout<<endl<<"Który rega³ usun¹c: ";
    cin>>wybor;
    if(sprawdzPoprawnoscWpisanejLiczby(wybor)) {
        regal *r = zczytanieRegalow();
        zapisRegalowDoPliku(r, stoi(wybor));
        delete [] r;
    } else {
        cout<<"Niepoprawnie wprowadzone dane."<<endl;
        komunikat();
    }
}
