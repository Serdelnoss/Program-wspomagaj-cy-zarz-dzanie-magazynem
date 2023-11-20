#include <iostream>
#include <fstream>
#include <conio.h>
#include <cstdlib>
#include <ctime>

using namespace std;

void zamienPlikZTowarami();
void usunTowarJesli0Sztuk();

namespace zamawianie {
    struct zamowienie {
        string imie;
        string nazwisko;
        string nrTelefonu;
        string email;
        string zamawianyTowar;
        string nazwaTowaru;
        string iloscSztuk;
        int nrZamowienia;
    };

    void zdejmijTowarZRegalu(zamowienie z) {
        fstream plikOdczyt, plikZapis;
        plikOdczyt.open("regaly.txt", ios::in);
        if(plikOdczyt.is_open()) {
            string linia;
            int nrLinii = 1;
            plikZapis.open("regaly1.txt", ios::out);
            if(plikZapis.is_open()) {
                 while(getline(plikOdczyt, linia)) {
                    if(nrLinii == atoi(z.zamawianyTowar.c_str()) * 4 - 1) {
                        int numer = atoi(linia.c_str());
                        numer += atoi(z.iloscSztuk.c_str());
                        linia = to_string(numer);
                    }
                    nrLinii++;
                    plikZapis<<linia<<endl;
                }
                plikOdczyt.close();
                plikZapis.close();
                remove("regaly.txt");
                rename("regaly1.txt", "regaly.txt");
                usunTowarJesli0Sztuk();
            } else cerr<<"B³¹d otwarcia pliku z rega³ami."<<endl;
        } else cerr<<"B³¹d otwarcia pliku z rega³ami."<<endl;
    }

    string wczytajNazweTowaru(string zamawianyTowar) {
        fstream plik;
        plik.open("towary.txt");
        if(plik.is_open()) {
            string linia;
            int nrLinii = 1;
            while(getline(plik, linia)) {
                if(nrLinii == atoi(zamawianyTowar.c_str()) * 3 - 2) {
                    return linia;
                }
                nrLinii++;
            }
            plik.close();
        } else cerr<<"B³¹d otwarcia pliku z towarami."<<endl;
    }

    bool czyNrZamowieniaJuzIstnieje(int nrZamowienia) {
        fstream plik;
        plik.open("zamowienia.txt", ios::in);
        if(plik.is_open()) {
            string linia;
            while(getline(plik, linia)) {
                if(nrZamowienia == atoi(linia.c_str())) return true;
            }
            plik.close();
            return false;
        } else cerr<<"B³¹d otwarcia pliku z zamówieniami."<<endl;
    }

    int losowanieNrZamowienia() {
        srand(time(NULL));
        int nrZamowienia = 100000 + rand()%(999999 - 100000 + 1);
        while(czyNrZamowieniaJuzIstnieje(nrZamowienia)) {
            nrZamowienia = 100000 + rand()%(999999 - 100000 + 1);
        }
        cout<<"Numer zamówienia: "<<nrZamowienia<<endl;
        return nrZamowienia;
    }

    zamowienie wczytajDane() {
        zamowienie z;
        cout<<"Podaj imiê: "; cin>>z.imie;
        cout<<"Podaj nazwisko: "; cin>>z.nazwisko;
        cout<<"Podaj adres e-mail: "; cin>>z.email;
        cout<<"Podaj numer telefonu: "; cin>>z.nrTelefonu;
        cout<<"Podaj numer towaru, który ma byc zamówiony: "; cin>>z.zamawianyTowar;
        cout<<"Ile sztuk towaru zamówic: "; cin>>z.iloscSztuk;
        z.nazwaTowaru = wczytajNazweTowaru(z.zamawianyTowar);
        z.nrZamowienia = losowanieNrZamowienia();
        return z;
    }

    bool sprawdzCzyTowaruJestWystarczajacoDuzo(zamowienie z) {
        ifstream plik;
        plik.open("towary.txt", ios::in);
        if(plik.is_open()) {
            int nrLinii = 1;
            string linia;
            while(getline(plik, linia)) {
                if(nrLinii == atoi(z.zamawianyTowar.c_str()) * 3 - 1) {
                    int numer = atoi(linia.c_str());
                    if(numer >= atoi(z.iloscSztuk.c_str())) {
                        return true;
                    } else return false;
                }
                nrLinii++;
            }
            plik.close();
        } else cerr<<"B³¹d otwarcia pliku z towarami."<<endl;
        return false;
    }

    void zapisDoPlikuZamowien(zamowienie z) {
        fstream plik;
        plik.open("zamowienia.txt", ios::out | ios::app);
        if(plik.is_open()) {
            plik<<z.imie<<endl;
            plik<<z.nazwisko<<endl;
            plik<<z.email<<endl;
            plik<<z.nrTelefonu<<endl;
            plik<<z.nazwaTowaru<<endl;
            plik<<z.iloscSztuk<<endl;
            plik<<z.nrZamowienia<<endl;
            plik.close();
        } else cerr<<"B³¹d otwarcia pliku z zamówieniami"<<endl;
    }

    void zdejmijTowarZTowarow(zamowienie z) {
        fstream plikOdczyt, plikZapis;
        plikOdczyt.open("towary.txt", ios::in);
        if(plikOdczyt.is_open()) {
            string linia;
            int nrLinii = 1;
            plikZapis.open("towary1.txt", ios::out);
            if(plikZapis.is_open()) {
                while(getline(plikOdczyt, linia)) {
                    if(nrLinii == atoi(z.zamawianyTowar.c_str()) * 3 - 1) {
                        int numer = atoi(linia.c_str());
                        numer -= atoi(z.iloscSztuk.c_str());
                        linia = to_string(numer);
                    }
                    nrLinii++;
                    plikZapis<<linia<<endl;
                }
                plikOdczyt.close();
                plikZapis.close();
                zamienPlikZTowarami();
            } else cerr<<"B³¹d otwarcia pliku z towarami"<<endl;
        } else cerr<<"B³¹d otwarcia pliku z towarami"<<endl;
    }

    int zliczIloscTowarow() {
        int iloscTowarow = 0;
        fstream plik;
        plik.open("towary.txt", ios::in);
        if(plik.is_open()) {
            int ileLinii = 0;
            string linia;
            while(getline(plik, linia)) {
                ileLinii++;
            }
            plik.close();
            return ileLinii / 3;
        } else {
            cerr<<"B³¹d otwarcia pliku z towarami."<<endl;
            return 0;
        }
    }
}

using namespace zamawianie;

void informacjeOTowarach();
void komunikat();
bool sprawdzPoprawnoscWpisanejLiczby(string liczba);

void skladanieZamowienia() {
    system("cls");
    cout<<"Dostêpne towary: "<<endl;
    informacjeOTowarach();
    zamowienie z = wczytajDane();
    int iloscTowarow = zliczIloscTowarow();
    if(sprawdzPoprawnoscWpisanejLiczby(z.iloscSztuk) && sprawdzPoprawnoscWpisanejLiczby(z.zamawianyTowar)) {
        if(atoi(z.zamawianyTowar.c_str()) <= iloscTowarow && atoi(z.zamawianyTowar.c_str()) > 0) {
            if(sprawdzCzyTowaruJestWystarczajacoDuzo(z)) {
                if(z.nrTelefonu.length() == 9) {
                    zapisDoPlikuZamowien(z);
                    zdejmijTowarZRegalu(z);
                    zdejmijTowarZTowarow(z);
                } else  cout<<"Niepoprawny numer telefonu."<<endl;
            } else cout<<"Zamówienie nie powiod³o siê - niewystarczaj¹ca iloœæ towaru w magazynie."<<endl;
        } else cout<<"Nie znaleziono towaru. Program zakonczy dzialanie."<<endl;
    } else cout<<"Wprowadzone dane s¹ nieprawid³owe. Program zakonczy dzialanie."<<endl;
    komunikat();
}
