#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<string>
#include<cstring>
using namespace std;

class Stan {
public:
	string vlasnik;
	int velicina;
	int brojSoba;
	Stan(string _vlasnik, int _velicina, int _brojSoba) : vlasnik(_vlasnik), velicina(_velicina), brojSoba(_brojSoba) {
		cout << "\nStan constructor called\n";
	}
	~Stan() {
		cout << "\nStan destructor called\n";
	}
};

class Zgrada {
private:
	string nazivFirme;
	int brojKatova;
	string adresa;
public:
	vector<Stan> stanovi;
	Zgrada(){}
	Zgrada(string nazivFirme, int brojKatova, string adresa) : nazivFirme(nazivFirme), brojKatova(brojKatova), adresa(adresa){}
	void SetNazivFirme(string noviNazivFirme) {
		if (noviNazivFirme.size() < 5)
		{
			cout << "Naziv firme treba imati najmanje 5 znakova!";
		}
		else {
			nazivFirme = noviNazivFirme;
		}
	}
	void SetBrojKatova(const int noviBrojKatova) {
		if (noviBrojKatova < 1)
		{
			cout << "Zgrada mora imati najmanje 1 kat!";
		}
		else {
			brojKatova = noviBrojKatova;
		}
	}
	void SetAdresa(const string novaAdresa) {
		adresa = novaAdresa;
	}

	string GetNazivFirme() const;
	int GetbrojKatova() const;
	string GetAdresa() const;

	void dodajStan1(Stan z);
	void dodajStan2(Stan& z);
	void dodajStan3(Stan* z);

	Stan nadjiStan1(string vlasnik);
	Stan* nadjiStan2(string vlasnik);
	Stan& nadjiStan3(string vlasnik);
	void ispisSvihStanova();
};
void Zgrada::dodajStan1(Stan z) {
	stanovi.push_back(z);
}
void Zgrada::dodajStan2(Stan& z) {
	stanovi.push_back(z);
}
void Zgrada::dodajStan3(Stan* z) {
	stanovi.push_back(*z);
}
void Zgrada::ispisSvihStanova() {
	for (int i = 0; i < stanovi.size(); i++) {
		cout << "\n" << i + 1 << ". stan\nVlasnik: " << stanovi[i].vlasnik << "\tVelicina: " << stanovi[i].velicina << "\tBroj soba: " << stanovi[i].brojSoba;
	}
}
Stan Zgrada::nadjiStan1(string vlasnik){
	Stan st1("Mateja", 150, 5);
	for (int i = 0; i < stanovi.size(); i++) {
		if (vlasnik == stanovi[i].vlasnik) {
			cout << i + 1 << ". stan\tVlasnik: " << stanovi[i].vlasnik;
			stanovi[i] = st1;
		}
	}
	return st1;
}
Stan* Zgrada::nadjiStan2(string vlasnik){
	Stan st2("Tihomir", 200, 6);
	for (int i = 0; i < stanovi.size(); i++) {
		if (vlasnik == stanovi[i].vlasnik) {
			cout << i + 1 << ". stan\tVlasnik: " << stanovi[i].vlasnik;
			stanovi[i] = st2;
			return &st2;
		}
	}
}
Stan& Zgrada::nadjiStan3(string vlasnik){
	Stan st3("Lukrecija", 25, 1);
	for (int i = 0; i < stanovi.size(); i++) {
		if (vlasnik == stanovi[i].vlasnik) {
			cout << i + 1 << ". stan\tVlasnik: " << stanovi[i].vlasnik;
			stanovi[i] = st3;
			return st3;
		}
	}
}
int main() {
	Zgrada zg;
	Stan s1("Tonka", 100, 3);
	Stan s2("Mirko", 70, 2);
	Stan s3("Lucija", 50, 1);
	string nazivFirmee;
	int brojKatovaa;
	string Adresa;
	cout << "Unesite naziv firme: ";
	cin >> nazivFirmee;
	zg.SetNazivFirme(nazivFirmee);
	cout << "\nUnesite broj katova: ";
	cin >> brojKatovaa;
	zg.SetBrojKatova(brojKatovaa);
	cout << "\nUnesite adresu zgrade: ";
	cin >> Adresa;
	zg.SetAdresa(Adresa);
	zg.dodajStan1(s1);
	zg.dodajStan2(s2);
	zg.dodajStan3(&s3);
	zg.ispisSvihStanova();
	zg.nadjiStan1(s1.vlasnik);
	zg.nadjiStan2(s2.vlasnik);
	zg.nadjiStan3(s3.vlasnik);
	//zg.GetNazivFirme();
	//zg.GetbrojKatova();
	//zg.GetAdresa();
	zg.ispisSvihStanova();
	return 0;
}