#include <iostream>
#include <fstream>

using namespace std;

void informacjeORegalach();
void komunikat();
bool sprawdzPoprawnoscWpisanejLiczby(string liczba);

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

void zapisDoRegalow(fstream &plikOdczyt, fstream &plikZapis, string linia, int nrLinii, bool usunieta, int wybor) {
    plikZapis.open("regaly1.txt", ios::out);
    while(getline(plikOdczyt, linia)) {
        if(usunieta && nrLinii % 4 == 1) {
            int liczba = atoi(linia.c_str()) - 1;
            linia = to_string(liczba);
        }
        if(nrLinii != wybor && nrLinii != wybor +1 && nrLinii != wybor + 2 && nrLinii != wybor + 3) {
            plikZapis<<linia<<endl;
            usunieta = true;
        }
        nrLinii++;
    }
    plikOdczyt.close();
    plikZapis.close();
    remove("regaly.txt");
    rename("regaly1.txt", "regaly.txt");
}

void usuniecieRegalu() {
    string wybor;
    informacjeORegalach();
    cout<<endl<<"Który rega³ usun¹c: ";
    cin>>wybor;
    if(sprawdzPoprawnoscWpisanejLiczby(wybor)) {
        fstream plikOdczyt, plikZapis;
        plikOdczyt.open("regaly.txt", ios::in);
        if(plikOdczyt.is_open()) {
            string linia;
            int nrLinii = 1;
            cout<<endl;
            bool usunieta = false;
            if(sprawdzenieCzyRegalJestPusty(atoi(wybor.c_str()))) {
                zapisDoRegalow(plikOdczyt, plikZapis, linia, nrLinii, usunieta, atoi(wybor.c_str()));
            } else cout<<"Rega³ nie jest pusty. Nie uda³o siê go usun¹æ."<<endl;
            cout<<"Wciœnij dowolny przycisk, aby kontynuowaæ..."<<endl;
            getch();
            system("cls");
        } else cerr<<"B³¹d otwarcia pliku z rega³ami."<<endl;
    } else {
        cout<<"Niepoprawnie wprowadzone dane."<<endl;
        komunikat();
    }
}
