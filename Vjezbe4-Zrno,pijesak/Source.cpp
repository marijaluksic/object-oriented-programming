#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Zrno {

public:

    string boja;

    float promjer;

};

class Pijesak {

public:

    int kolicina;

    Zrno* zrno;
    Pijesak (){}
    Pijesak(int _kolicina) : kolicina(_kolicina) {

        // dinamicki alocirajte polje 'zrno'
        zrno = new Zrno[_kolicina];

    }
    //KOPIRNI KONSTRUKTOR
    Pijesak(const Pijesak& p) {
        zrno = new Zrno[p.kolicina];
        for (int i = 0; i < p.kolicina; i++) {
            zrno[i] = p.zrno[i];
        }
        kolicina = p.kolicina;
    }

    //OPERATOR PRIDRUZIVANJA SA SEMANTIKOM KOPIRANJA
    Pijesak& operator = (const Pijesak& P) {
        if (this != &P) {
            delete[] zrno;
            zrno = new Zrno[P.kolicina];
            for (int i = 0; i < P.kolicina; i++) {
                zrno[i] = P.zrno[i];
            }
            kolicina = P.kolicina;
        }
        return *this;
    }

    //KOPIRNI KONSTUKTOR SA SEMANTIKOM PRIJENOSA
    Pijesak(Pijesak&& priv) {
        zrno = priv.zrno;
        priv.zrno = NULL;
        kolicina = priv.kolicina;
    }

    //OPERATOR PRIDRUZIVANJA SA SEMANTIKOM PRIJENOSA
    Pijesak& operator = (Pijesak&& privremeno) {
        if (this != &privremeno) {
            delete[] zrno;
            zrno = privremeno.zrno;
            privremeno.zrno = NULL;
            kolicina = privremeno.kolicina;
        }
        return *this;
    }


    ~Pijesak() {

        // ?
        delete[] zrno;

    }

};

int main() {

    Pijesak igraliste(40);

    cout << "Na igralistu ima " << igraliste.kolicina << " zrna pijeska!\n";



    // Demonstrirajte pozive oba konstruktora i oba operatora pridruzivanja

    //semantika kopiranja
        Pijesak hrvatska = igraliste;

        // drugi nacin za napisat isto sto i ovo ispod: Pijesak sahara(igraliste);
        Pijesak sahara;
        sahara = igraliste; 

    //semantika prijenosa
        Pijesak indija = Pijesak(60);

        // drugi nacin za napisat isto sto i ovo ispod: Pijesak bugarska(Pijesak(20));
        Pijesak bugarska;
        bugarska = Pijesak(20);

    cout << "U Hrvatskoj ima " << hrvatska.kolicina << " zrna pijeska!\n";
    cout << "U Sahari ima " << sahara.kolicina << " zrna pijeska!\n";
    cout << "U Indiji ima " << indija.kolicina << " zrna pijeska!\n";
    cout << "U Bugarskoj ima " << bugarska.kolicina << " zrna pijeska!\n";
    return 0;

}