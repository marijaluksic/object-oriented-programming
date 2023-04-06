#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <iterator>
#include <map>
#include <functional>
#include<cctype>
#include<ctype.h>

using namespace std;

namespace Ducan {
    class NeispravanProizvod : public exception {
    public:
        NeispravanProizvod(const char* _poruka):exception(_poruka) {}
    };
    class Cijena {
    public: 
        int cijena=0;
        int uvecanaCijena=0;
        Cijena() {}
        Cijena(int _cijena) : cijena(_cijena) {}
        void dodaj(int n) {
            uvecanaCijena = n;
        }
        int ukupno() {
            return cijena + uvecanaCijena;
        }
    };
    class Artikl {
    public:
        virtual string tekstualno() = 0;
    };
    class Proizvod : public Artikl {
    private:
        string opis;
        int broj;
        Cijena* iznos;
    public:
        static int unisteno;
        Proizvod() {
            opis = "PRAZNO";
            broj = 0;
            iznos = new Cijena();
        }
        Proizvod(string _opis, int _broj){
                if (_opis == "")
                {
                    throw NeispravanProizvod("Neispravan proizvod!");
                }
                else {
                    opis = _opis;
                    broj = _broj;
                    iznos = new Cijena();
                }
        }
        operator string() {
            string pom;
            string str = to_string(broj);
            pom.append(opis);
            pom.append("-");
            pom.append(str);
            return pom;
        }
        void setOpis(string s) {
            opis = s;
        }
        void setBroj(int i) {
            broj = i;
        }
        string getOpis() {
            return opis;
        }
        int getBroj() {
            return broj;
        }
        Proizvod(const Proizvod& p) {
            iznos = new Cijena();
            *iznos = *p.iznos;
            opis = p.opis;
            broj = p.broj;
        }
        Proizvod& operator = (const Proizvod& p) { // OPERATOR PRIDRUZIVANJA SA SEMANTIKOM KOPIRANJA
            if (this != &p)
            {
               delete[] iznos;
               iznos = new Cijena();
               *iznos = *p.iznos;
                opis = p.opis;
                broj = p.broj;
                
            }

            return *this;
        }
        string tekstualno() {
            string ispis;
            string razmak = " ";
            ispis = getOpis() + razmak + to_string(getBroj());
            return ispis;
        }
        Proizvod(string _opis, int _broj, Cijena* _iznos) {
            if (_opis == "")
            {
                throw NeispravanProizvod("Neispravan proizvod!");
            }
            else {
                opis = _opis;
                broj = _broj;
                iznos = new Cijena();
                *iznos = *_iznos;
            }
        }
        Cijena* cijena() {
            return iznos;
        }
        ~Proizvod() {
                unisteno++;
                delete iznos;
        }
    };
    template <class T>
    class Cjenik {
    public:
        vector<T> input;
        Cjenik(){}
        template<class T1>
        void dodaj(T1& argument) {
            input.push_back(argument);
        }
        template<class T1, class ...T2>
        void dodaj(T1& argument, T2& ...argument2) {
            input.push_back(argument);
            dodaj(argument2...);
        }
        void ispisi() {
            for (int i = 0; i < input.size(); i++) {
                if ((i + 1) == input.size()) {
                    cout << input[i].getOpis() << " (br. proizvoda: " << input[i].getBroj() << ")" << endl;
                }
                else {
                    cout << input[i].getOpis() << " (br. proizvoda: " << input[i].getBroj() << ")," << endl; 
                }
            }
        }
    };
    ostream& operator << (ostream& izlaz, Proizvod p) {
        izlaz << p.getOpis() << " (br. proizvoda: " << p.getBroj() << ")" << endl;
        return izlaz;
    }
    void sort(vector<Proizvod>::iterator A, vector<Proizvod>::iterator B) {
        for (vector<Proizvod>::iterator i = A; i != B; ++i) {
            for (vector<Proizvod>::iterator j = A; j < i; ++j) {
            if ((i->getBroj() < j->getBroj()) || (i->getBroj() <= j->getBroj()) && (i->getOpis() < j->getOpis())) {
                iter_swap(i, j);
            }
            }
        }
    }

    void ispisi(vector<Proizvod> niz) {
        for (int i = 0; i < niz.size(); i++) {
            cout << niz[i].getOpis() << " " << niz[i].getBroj() << endl;
        }
        cout << endl;
    }
    int Proizvod::unisteno = 0;
}


int main() {

    //**************************************************************************

    // sav kod mora biti dio imenskog prostora Ducan
    using namespace Ducan;

    //**************************************************************************

    cout << "--- [2] ---\n";

    Proizvod d1("televizor", 200);
    Proizvod d2;  // postavlja opis na "PRAZNO" i broj na 0
    Proizvod d3("mobitel", 391);
    Proizvod d4("monitor", 1711);

    Proizvod d5("Z", 5);
    Proizvod d6("Z", 4);
    Proizvod d7("televizoa", 200);

    vector<Proizvod> proizvodi{ d1, d2, d3, d4, d5, d6, d7 };

    // * ispisuje se "neispravan proizvod" (klasa Proizvod treba provjeravati 
    // da li opis ima tekst (t.j. da nije prazan)
    // * klasa NeispravanProizvod mora imati samo konstruktor koji prima tekst
    // poruke (nema drugih funkcija) i naslje?ivati od klase "exception"
    try {
        Proizvod d("", 400);  // prazan opis - baca se iznimka
    }
    catch (NeispravanProizvod& e) {
        cout << e.what() << endl;
    }

    //**************************************************************************

    cout << "--- [3] ---\n";

    cout << (string)d1 << endl;  // ispisuje "televizor-200"
    cout << d1 << endl;  // ispisuje "televizor (br. prozivoda: 200)"

    //**************************************************************************

    cout << "--- [4] ---\n";

    // * ovdje upotrijebiti funkciju "sort" zaglavlja "algorithm"
    // * za Proizvod treba definirati i kopirni operator pridruzivanja
    sort(proizvodi.begin(), proizvodi.end());
    // ispisuje proizvode sortirane od najmanjeg prema najvecem tako da sortira
    // po broju proizvoda i opisu (na primjer, proizvod B,5 dolazi ispred A,7)
    ispisi(proizvodi);

    //**************************************************************************

    cout << "--- [5] ---\n";
    auto usporedba_proizvoda = [](Proizvod& A, Proizvod& B) {
        return ((A.getBroj() < B.getBroj()) || ((A.getBroj() <= B.getBroj()) && (A.getOpis() < B.getOpis())));
    };
    // * ovdje upotrijebiti funkciju "sort" zaglavlja "algorithm"
    // * varijabla usporedba_proizvoda mora sadrzavati lambda-izraz
    sort(proizvodi.begin(), proizvodi.end(), usporedba_proizvoda);
    // ispisuje proizvode sortirane od najveceg prema najmanjem tako da sortira
    // po broju proizvoda i opisu (na primjer, proizvod B,5 dolazi ispred A,7)
    ispisi(proizvodi);

    //**************************************************************************

    cout << "--- [6] ---\n";
    auto usporedba_elemenata = [](Artikl* A, Artikl* B) {
        string opis1, opis2;
        string broj1, broj2;
        string unos1 = A->tekstualno();
        string unos2 = B->tekstualno();
        char* token;
        token = strtok(&unos1[0], " ");
        opis1 = token;
        token = strtok(NULL, "\n");
        broj1 = token;
        token = strtok(&unos2[0], " ");
        opis2 = token;
        token = strtok(NULL, "\n");
        broj2 = token;
        return ((stoi(broj1) < stoi(broj2)) || ((stoi(broj1) <= stoi(broj2)) && (opis1<opis2)));
    };
    vector<Artikl*> kal{ &d1, &d2, &d3, &d4, &d5, &d6, &d7 };
    sort(kal.begin(), kal.end(), usporedba_elemenata);

    // Funkcijom "tekstualno" demonstrirati polimorfizam; klasa Artikl
    // mora biti apstraktna s jednom funkcijom "tekstualno"!

    // ispisuje proizvode sortirane od najmanjeg prema najvecem (sortirano po
    // broju proizvoda i opisu)
    for (vector<Artikl*>::const_iterator itr = kal.begin();
        itr != kal.end(); ++itr) {
        cout << (*itr)->tekstualno() << endl;
    }

    //**************************************************************************

    cout << "--- [7] ---\n";

    Proizvod x("kamera", 2443, new Cijena(15));
    Proizvod y = x;

    // dodaje vrijednost zadanu u argumentu poziva "dodaj" na cijenu zadanu u
    // konstruktru za x
    x.cijena()->dodaj(10);

    // ispisuje 25
    cout << x.cijena()->ukupno() << endl;

    // ispisuje 15
    cout << y.cijena()->ukupno() << endl;

    //**************************************************************************

    cout << "--- [8] ---\n";

    Cjenik<Proizvod> cjenik;
    // Funkcija "dodaj" mora biti napisana kao funkcija s neogranicenim brojem
    // parametara!
    cjenik.dodaj(d4, d1, d2);

    // ispisuje monitor (br. proizvoda: 1711), televizor (br. proizvoda: 200), 
    // PRAZNO (br. proizvoda: 0) (jedno ispod drugoga)
    cjenik.ispisi();

    //**************************************************************************
    cout << "--- [9] ---\n";

    // Na kraju se mora ispisati broj koliko je objekata tipa Proizvod unisteno!

    cout << Proizvod::unisteno << endl;
    //**************************************************************************

	return 0;
}

