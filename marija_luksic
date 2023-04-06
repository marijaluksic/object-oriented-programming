#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cctype>
#include <ctype.h>
#include <functional>
using namespace std;

class EPogresanBroj {
public:
    int greska;
    EPogresanBroj(int _greska) :greska(_greska) {}
    void ispis() {
        cout << "Broj " << greska << " nije ispravan maticni broj!\n";
    }
};

class Autor {
private:
    int maticniBroj;
public:
    string ime, prezime;
    Autor(string _ime, string _prezime) : ime(_ime), prezime(_prezime) {}
    void setMaticniBroj(int noviBroj) {
        if (noviBroj < 0) {
            throw EPogresanBroj(noviBroj);
        }
        else {
            maticniBroj = noviBroj;
        }
    }
    int getMaticniBroj() const {
        return maticniBroj;
    }
};

class Knjiga {
public:
    Autor* autor;
    string naslov, izdavac;
    Knjiga(string _naslov, string _izdavac) : naslov(_naslov), izdavac(_izdavac) {}
    Knjiga(const Knjiga& knjiga) {
        autor = new Autor(*knjiga.autor);
        naslov = knjiga.naslov;
        izdavac = knjiga.izdavac;
    }
    // -> prijenosni konstruktor (2 boda)
    Knjiga(Knjiga&& knjiga) {
        autor = knjiga.autor;
        knjiga.autor = NULL;
        naslov = knjiga.naslov;
        izdavac = knjiga.izdavac;
    }
    // -> operator = (semantika prijenosa) (2 boda)
    Knjiga& operator = (Knjiga&& knjiga) {
        if (this != &knjiga) {
            delete autor;
            autor = new Autor(*knjiga.autor);
            knjiga.autor = NULL;
            naslov = knjiga.naslov;
            izdavac = knjiga.izdavac;
        }
        return *this;
    }
    // -> destruktor (1 bod)
    ~Knjiga() {
        delete autor;
    }
    virtual string vrsta() {
        return "Knjiga";
    }
};

class Knjiznica {
public:
    vector<Knjiga*> knjiga;
    Knjiznica() {}
    // -> kopirni konstruktor (3 boda)
    Knjiznica(const Knjiznica& knjiznica) {
        for (int i = 0; i < knjiznica.knjiga.size(); i++) {
            knjiga.push_back(new Knjiga(*knjiznica.knjiga[i]));
        }
    }
    // -> operator = (semantika kopiranja) (3 boda)
    Knjiznica& operator =(const Knjiznica& knjiznica) {
        if (this != &knjiznica) {
            for (int i = 0; i < knjiga.size(); i++) {
                delete knjiga[i];
            }
            knjiga.clear();
            for (int i = 0; i < knjiznica.knjiga.size(); i++) {
                knjiga.push_back(new Knjiga(*knjiznica.knjiga[i]));
            }
        }
    }
    // -> destruktor (1 bod)  
    ~Knjiznica() {
        for (int i = 0; i < knjiga.size(); i++) {
            delete knjiga[i];
        }
        knjiga.clear();
    }
};
class Skripta : public Knjiga {
public:
    Skripta(string naslov, string izdavac) : Knjiga(naslov, izdavac) {}
    string vrsta() {
        return "Skripta";
    }
};
class Prirucnik : public Knjiga {
public:
    Prirucnik(string naslov, string izdavac) : Knjiga(naslov, izdavac) {}
    string vrsta() {
        return "Prirucnik";
    }
};
class Udzbenik : public Knjiga {
public:
    Udzbenik(string naslov, string izdavac) : Knjiga(naslov, izdavac) {}
    string vrsta() {
        return "Udzbenik";
    }
};

ostream& operator <<(ostream& izlaz, const Knjiznica& knjiznica) {
    for (int i = 0; i < knjiznica.knjiga.size(); i++) {
        izlaz << "Naslov: " << knjiznica.knjiga[i]->naslov << "\tAutor: " << knjiznica.knjiga[i]->autor->ime << " " << knjiznica.knjiga[i]->autor->prezime << "\tIzdavac: " << knjiznica.knjiga[i]->izdavac << endl;
    }
    return izlaz;
}

void ispisVrsteKnjige(vector<Knjiga*> knjige) {
    for (int i = 0; i < knjige.size(); i++) {
        cout << knjige[i]->vrsta() << endl;
    }
}

class Kompleksni {
public:
    double im, re;
    Kompleksni() {}
    Kompleksni(double _re, double _im) : re(_re), im(_im) {}
};
Kompleksni operator * (Kompleksni Z1, Kompleksni Z2) {
    return Kompleksni(((Z1.re * Z2.re) - (Z1.im * Z2.im)), ((Z1.im * Z2.re) + (Z1.re * Z2.im)));
}

class Grad {
public:
    string naziv;
    int brStan;
    Grad(string _naziv, int _brStan) :naziv(_naziv), brStan(_brStan) {}
};

class usporedba_gradova {
public:
    bool operator()(Grad grad1, Grad grad2) const{
        return grad1.brStan > grad2.brStan;
    }
};

template<class T1>
void mojPrint(T1 argument1) {
    cout << argument1;
}
template<class T1, class... T2>
void mojPrint(T1 argument1, T2... argument2) {
    mojPrint(argument2...);
    cout << argument1;
}


int main() {
    Autor a1("Marko", "Marulic");
    try {
        a1.setMaticniBroj(-2);
    }
    catch (EPogresanBroj e) {
        e.ispis();
    }
    cout << endl;

    Knjiznica knjiznica;
    Knjiga knjiga1("Alice in Wonderland", "Ljevak");
    knjiga1.autor = new Autor("Mimi", "Maradona");
    Knjiga knjiga2("Mi djeca s kolodora Zoo", "Skolska knjiga");
    knjiga2.autor = new Autor("Suki", "Suzuki");
    Knjiga knjiga3("Dnevnik Pauline P", "Svjetlost");
    knjiga3.autor = new Autor("Brigita", "Cosic");
    knjiznica.knjiga.push_back(&knjiga1);
    knjiznica.knjiga.push_back(&knjiga2);
    knjiznica.knjiga.push_back(&knjiga3);
    cout << knjiznica;

    cout << endl;
    Skripta skripta("naslov1", "izdavac1");
    Prirucnik prirucnik("naslov2", "izdavac2");
    Udzbenik udzbenik("naslov3", "izdavac3");
    Udzbenik udzbenik2("naslov4", "izdavac4");
    vector<Knjiga*> knjige = { &skripta, &prirucnik, &udzbenik, &udzbenik2 };
    ispisVrsteKnjige(knjige);

    cout << endl;
    Kompleksni Z1(0, 0), Z2(1, -1);
    Kompleksni Z3;
    Z3 = [](Kompleksni Z1, Kompleksni Z2) {
        return Z1 * Z2;
    }(Z1, Z2);
    [&]() {
        Z3 = Z1 * Z2;
    }();
    [&Z3](Kompleksni Z1, Kompleksni Z2) {
        Z3 = Z1 * Z2;
    }(Z1, Z2);

    cout << endl;
    vector<Grad> gradovi;
    int n;
    cout << "Unesite zeljeni broj gradova za usporedbu: ";
    cin >> n;
    for (int i = 0; i < n; i++) {
        string tempNaziv;
        int tempBroj;
        cout << "\nUnesite naziv " << i + 1 << ". grada: ";
        cin >> tempNaziv;
        cout << "\nUnesite broj stanovnika " << i + 1 << ". grada: ";
        cin >> tempBroj;
        gradovi.push_back(Grad(tempNaziv, tempBroj));
    }
    sort(gradovi.begin(), gradovi.end(), usporedba_gradova());
    for (int i = 0; i < n; i++) {
        cout << "Naziv grada: " << gradovi[i].naziv << "\tBroj stanovnika: " << gradovi[i].brStan << endl;
    }
    
    mojPrint(2); // 2
    cout << endl;
    mojPrint(2, 'D', 2.76); // 2.76D2
    cout << endl;
    mojPrint(-1, "niz", 0.547, 'X'); // X0.547niz-1
    return 0;
}
