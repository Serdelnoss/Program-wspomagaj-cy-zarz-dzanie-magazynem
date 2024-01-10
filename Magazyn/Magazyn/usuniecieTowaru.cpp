#include <iostream>
#include <fstream>

void informacjeOTowarach();
bool sprawdzPoprawnoscWpisanejLiczby(string liczba);

string ktoryTowarUsunac() {
    string ktoryTowar;
    cout<<"Który towar usun¹c: "; cin>>ktoryTowar;
    return ktoryTowar;
}

string ileSztukUsunac() {
    string ileSztuk;
    cout<<"Ile sztuk usun¹c: "; cin>>ileSztuk;
    return ileSztuk;
}

void zwolnijMiejsceZRegalu(int ile, string nazwaRegalu) {
    fstream plikOdczyt, plikZapis;
    plikOdczyt.open("regaly.txt", ios::in);
    string linia;
    int nrLinii;
    bool czyZmienic = false;
    if(plikOdczyt.is_open()) {
        plikZapis.open("regaly1.txt", ios::out);
        if(plikZapis.is_open()) {
            while(getline(plikOdczyt, linia)) {
                if(linia == nazwaRegalu) {
                    czyZmienic = true;
                }
                if(czyZmienic && nrLinii % 4 == 2) {
                    czyZmienic = false;
                    int liczba = atoi(linia.c_str());
                    liczba += ile;
                    linia = to_string(liczba);
                }
                nrLinii++;
                plikZapis<<linia<<endl;
            }
            plikZapis.close();
        } else cerr<<"B³¹d otwarcia pliku z rega³ami."<<endl;
        plikOdczyt.close();
        remove("regaly.txt");
        rename("regaly1.txt", "regaly.txt");
    } else cerr<<"B³¹d otwarcia pliku z rega³ami."<<endl;
}

string pobierzNazweRegalu(int ktory) {
    fstream plik;
    string linia;
    int nrLinii = 1;
    plik.open("towary.txt", ios::in);
    if(plik.is_open()) {
        while(getline(plik, linia)) {
            if(ktory * 3 == nrLinii) {
                return linia;
            }
            nrLinii++;
        }
        plik.close();
    } else cerr<<"B³¹d otwarcia pliku z towarami/";
}

void zapisDoPlikuTowarow(string linia) {
    fstream plik;
    plik.open("towary1.txt", ios::out | ios::app);
    if(plik.is_open()) {
        plik<<linia<<endl;
        plik.close();
    } else {
        cerr<<"B³¹d otwarcia pliku z towarami."<<endl;
    }
}

void zamienPlikZTowarami() {
    remove("towary.txt");
    rename("towary1.txt", "towary.txt");
}

void zczytajTowary(int ktoryTowar, int ileSztuk) {
    fstream plik;
    plik.open("towary.txt", ios::in);
    int nrLinii = 1;
    string linia;
    if(plik.is_open()) {
        while(getline(plik, linia)) {
            if(nrLinii == ktoryTowar * 2 || nrLinii == ktoryTowar * 2 + 1 || nrLinii == ktoryTowar * 2 + 2) {
                if(nrLinii % 3 == 2) {
                    int ileTowarow = atoi(linia.c_str());
                    if(ileTowarow > ileSztuk) {
                        linia = to_string(ileTowarow - ileSztuk);
                    } else if (ileTowarow == ileSztuk) {
                        linia = to_string(ileTowarow - ileSztuk);
                    } else if (ileTowarow < ileSztuk) {
                        cout<<"Podana iloœæ towarów do usuniêcia jest wiêksza ni¿ iloœæ dostêpnych towarów w magazynie."<<endl;
                    }
                }
            }
            zapisDoPlikuTowarow(linia);
            nrLinii++;
        }
        plik.close();
        zamienPlikZTowarami();
    } else cerr<<"B³¹d otwarcia pliku z towarami."<<endl;
}

void usunTowarJesli0Sztuk() {
    fstream plikOdczyt, plikZapis;
    plikOdczyt.open("towary.txt", ios::in);
    if(plikOdczyt.is_open()) {
        plikZapis.open("towary1.txt", ios::out);
        if(plikZapis.is_open()) {
            string linia, tmp1, tmp2, tmp3;
            int nrLinii = 1;
            while(getline(plikOdczyt, linia)) {
                switch(nrLinii % 3) {
                    case 1:
                        tmp1 = linia; break;
                    case 2:
                        tmp2 = linia; break;
                    case 0:
                        tmp3 = linia; break;
                }
                if(tmp2 != "0" && nrLinii % 3 == 0) plikZapis<<tmp1<<endl<<tmp2<<endl<<tmp3<<endl;
                nrLinii++;
            }
            plikZapis.close();
        } else cerr<<"B³¹d otwarcia pliku z towarami."<<endl;
        plikOdczyt.close();
        zamienPlikZTowarami();
    } else cerr<<"B³¹d otwarcia pliku z towarami."<<endl;
}

void usuniecieTowaru() {
    informacjeOTowarach();
    string ktoryTowar = ktoryTowarUsunac();
    if(sprawdzPoprawnoscWpisanejLiczby(ktoryTowar)) {
        string ileSztuk = ileSztukUsunac();
        if(sprawdzPoprawnoscWpisanejLiczby(ileSztuk)) {
            zczytajTowary(atoi(ktoryTowar.c_str()), atoi(ileSztuk.c_str()));
            string nazwaRegalu = pobierzNazweRegalu(atoi(ktoryTowar.c_str()));
            zwolnijMiejsceZRegalu(atoi(ileSztuk.c_str()), nazwaRegalu);
            usunTowarJesli0Sztuk();
        } else cout<<"B³¹d wprowadzenia danych."<<endl;
    } else cout<<"B³¹d wprowadzenia danych."<<endl;
}
