#include<iostream>
#include<vector>
#include<string>
using namespace std;

class Cipela {
public:
	int broj;
	string materijal;
	string boja;

	Cipela() {}
	Cipela(int _broj, string _materijal, string _boja) : broj(_broj), materijal(_materijal), boja(_boja) {}
};

class Narudzba {
public:
	string narucitelj;
    vector<Cipela> nizCipela;

	Narudzba(){}
	Narudzba(string _narucitelj) : narucitelj(_narucitelj), nizCipela(NULL) {}
    
    void dodajCipelu(Cipela cipela);
};

class Postolar {
public:
    vector<Narudzba> naruceno;
    double preuzmiNarudzbu(Narudzba narucitelj);
    void ispisiNarudzbe();
};
void Narudzba::dodajCipelu(Cipela cipela) {
    nizCipela.push_back(cipela);
}
double Postolar::preuzmiNarudzbu(Narudzba narucitelj) {
    double cijena = 0;
    for (int i = 0; i < narucitelj.nizCipela.size(); i++)
    {
        cijena += (narucitelj.nizCipela[i].broj * 10.5);
    }
    naruceno.push_back(narucitelj);
    return cijena;
}
void Postolar::ispisiNarudzbe() {
    for (int i = 0; i < naruceno.size(); i++)
    {
        cout << "\n" << i + 1 << ". narudzba\nNarucitelj: " << naruceno[i].narucitelj << "\nNaruceno:";
        for (int j = 0; j < naruceno[i].nizCipela.size(); j++) {
            cout << "\nBroj: " << naruceno[i].nizCipela[j].broj << "\tMaterijal: " << naruceno[i].nizCipela[j].materijal << "\t Boja: " << naruceno[i].nizCipela[j].boja;
        }
    }
}

int main() {
    Postolar p;

    Narudzba n1;

    n1.narucitelj = "Susjed Mirko";

    //Cipela ima broj (velicinu), materijal i boju

    n1.dodajCipelu(Cipela(47, "Sky", "plava"));

    n1.dodajCipelu(Cipela(44, "Platno", "zelena"));



    //Cijena izrade jedne cipele se racuna na nacin da se velicina (broj cipele) pomnozi sa 10.5

    double c1 = p.preuzmiNarudzbu(n1);

    cout << "Ukupna cijena 1. narudzbe je " << c1 << endl;



    Narudzba n2("Barica");

    n2.dodajCipelu(Cipela(43, "Koza", "crna"));

    double c2 = p.preuzmiNarudzbu(n2);

    cout << "Ukupna cijena 2. narudzbe je " << c2 << endl;



    //Ispisuje sve narudzbe

    //Za svaku narudzbu ispisuje tko je narucitelj, te popis svih cipela koje su narucene

    p.ispisiNarudzbe();
    return 0;
}
