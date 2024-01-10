#include <iostream>
#include <fstream>

namespace odbieranieZamowienia {
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
}

using namespace odbieranieZamowienia;

void odczytajDane(fstream &plik, fstream &plikZapis, zamowienie &z, int nrZamowienia) {
    bool czyOdebranoZamowienie = false;
    string linia;
    int nrLinii = 1;
    while (getline(plik, linia)) {
        switch (nrLinii % 7) {
            case 1: z.imie = linia; break;
            case 2: z.nazwisko = linia; break;
            case 3: z.email = linia; break;
            case 4: z.nrTelefonu = linia; break;
            case 5: z.nazwaTowaru = linia; break;
            case 6: z.iloscSztuk = linia; break;
            case 0: z.nrZamowienia = atoi(linia.c_str()); break;
        }
        if (z.nrZamowienia != nrZamowienia) {
            if (nrLinii % 7 == 0) {
                plikZapis<<z.imie<<endl<<z.nazwisko<<endl<<z.email<<endl<<z.nrTelefonu<<endl<<z.nazwaTowaru<<endl<<z.iloscSztuk<<endl<<z.nrZamowienia<<endl;
            }
        } else czyOdebranoZamowienie = true;
        nrLinii++;
    }
    if(czyOdebranoZamowienie) cout<<"Poprawnie odebrano zamówienie."<<endl;
    else cout<<"Nie znaleziono takiego zamówienia."<<endl;
}

void komunikat();

void odczytZapisDoPliku(int nrZamowienia) {
    fstream plikOdczyt, plikZapis;
    plikOdczyt.open("zamowienia.txt", ios::in);
    if (plikOdczyt.is_open()) {
        plikZapis.open("zamowienia1.txt", ios::out);
        if (plikZapis.is_open()) {
            zamowienie z;
            int nrLinii = 1;
            odczytajDane(plikOdczyt, plikZapis, z, nrZamowienia);
            plikOdczyt.close();
            plikZapis.close();
            remove("zamowienia.txt");
            rename("zamowienia1.txt", "zamowienia.txt");
        } else {
            cerr << "B³¹d otwarcia pliku z zamówieniami." << endl;
        }
    } else {
        cerr << "B³¹d otwarcia pliku z zamówieniami." << endl;
    }
}

void odbiorZamowienia() {
    string nrZamowienia;
    cout<<"Podaj numer zamówienia: "; cin>>nrZamowienia;
    odczytZapisDoPliku(atoi(nrZamowienia.c_str()));
    komunikat();
}
