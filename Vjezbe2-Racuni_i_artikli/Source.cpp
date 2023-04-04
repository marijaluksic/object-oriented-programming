#include<iostream>
#include<vector>
#include<string>
using namespace std;

class Artikl {
public:
	string naziv;
	int tezina;
	double cijena;
	Artikl () {} 
	Artikl (string _naziv, int _tezina, double _cijena) : naziv(_naziv), tezina(_tezina), cijena(_cijena) {}
};

class Racun {
public:
	int brojRacuna;
	double ukupnaCijena;
	vector<Artikl> artikli;
	Racun (){}
	Racun (int _brojRacuna) : brojRacuna(_brojRacuna), ukupnaCijena(0) {}
	void dodaj(Artikl artikl);
};

class Kupac {
public:
	Racun racun;
	Kupac (){}
	Kupac(Racun r) : racun(r) {}
};

void Racun::dodaj(Artikl artikl) {
	artikli.push_back(artikl);
	ukupnaCijena += (artikl.tezina * artikl.cijena);
}

int main() {
	Kupac Ante(Racun(1)); // Ante ima racun broj 1
	Ante.racun.dodaj(Artikl("Jabuka", 1, 6)); // 1 kg, 6 kn/kg
	Ante.racun.dodaj(Artikl("Banana", 2, 7.5)); // 2 kg, 7.5 kn/kg
	Ante.racun.dodaj(Artikl("Coca cola 2l", 2, 10)); // 2 boce, 10 kn/boca
	cout << "Ukupno: " << Ante.racun.ukupnaCijena << " kn" << endl; // 41 kn
	/* U nastavku ispisite koji je najskuplji artikl kojeg je Ante platio
	 (naziv i ukupna cijena). Npr.
	 Najskuplje placeni artikl je Coca cola 2l (20kn)
	*/
	int najskuplji = 0;
	double maxcijena = 0;
	for (int i = 0; i < Ante.racun.artikli.size(); i++) {
		if ((Ante.racun.artikli[i].tezina * Ante.racun.artikli[i].cijena) > maxcijena) {
			maxcijena = (Ante.racun.artikli[i].tezina * Ante.racun.artikli[i].cijena);
			najskuplji = i;
		}
	}
	cout << "Najskuplje placeni artikl je " << Ante.racun.artikli[najskuplji].naziv << " (" << maxcijena << "kn)";

	return 0;
}