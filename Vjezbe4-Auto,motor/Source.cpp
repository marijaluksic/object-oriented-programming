#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>
#include <ctime>
using namespace std;

class Guma {
public:
	int id; // (razlicit za svaku gumu) gume
	string tip; // (ljetne / zimske)
	Guma (){}
	Guma(int _id, string _tip): id(_id), tip(_tip){}
};

class Motor {
public:
	string naziv;
	int kubikaza;
	Motor() {}
	Motor(string _naziv, int _kubikaza): naziv(_naziv), kubikaza(_kubikaza){}
};
class Auto {
private:
	Motor* motor;
public:
	vector<Guma*> nizGuma;
	string Naziv;
	int brojVrata;

	void ugradiMotor(Motor* m);
	Motor* izvadiMotor();

	void staviGume(vector<Guma*> gume);
	vector<Guma*> skiniGume();
	void ispis(); //ispisati podatke o automobilu, motoru i gumama

	Auto() {}
	Auto(Motor* motor);
	//Kopirni konstruktor i operator pridruživanja
	Auto(const Auto& p);
	Auto& operator = (const Auto& s);
	//destruktor
	~Auto();
};

Auto::Auto(const Auto& p) {
	motor = new Motor(*(p.motor));
	for (int i = 0; i < 4; i++) {
		nizGuma.push_back(new Guma((i + 1), p.nizGuma[i]->tip));
	}
	Naziv = p.Naziv;
	brojVrata = p.brojVrata;
}
Auto& Auto::operator = (const Auto& s) {
	if (this != &s) {
		delete[] motor;
		motor = new Motor(*(s.motor));
		for (int i = 0; i < 4; i++) {
			nizGuma.push_back(new Guma((i + 1), s.nizGuma[i]->tip));
		}
		Naziv = s.Naziv;
		brojVrata = s.brojVrata;
	}
	return *this;
}
void Auto::ugradiMotor(Motor* m) {
	motor = m;
}
Motor* Auto::izvadiMotor() {
	motor = nullptr;
	return motor;
}

void Auto::staviGume(vector<Guma*> gume) {
	for (int i = 0; i < 4; i++) {
		nizGuma.push_back(new Guma((i + 1), gume[i]->tip));
	}
}
vector<Guma*> Auto::skiniGume() {
	nizGuma.clear();
	return nizGuma;
}
void Auto::ispis() {
	cout << "Naziv: " << Naziv << "\tBroj vrata: " << brojVrata << "\tMotor: " << motor->naziv << " (" << motor->kubikaza << ")\n";
	for (int i = 0; i < nizGuma.size(); i++) {
		cout << nizGuma[i]->id << ". guma\ttip: " << nizGuma[i]->tip << "\n";
	}
	cout << "\n";
}
Auto::Auto(Motor* motor) {
	motor = new Motor;
}
Auto::~Auto() {
	delete[] motor;
}

int main() {
	Motor m1("Ford", 500);
	vector<Guma*> gume;
	for (int i = 0; i < 4; i++) {
		gume.push_back(new Guma((i+1), "zimske"));
	}
	Auto *a1 = new Auto;
	a1->brojVrata = 4;
	a1->Naziv = "Fiesta";
	a1->ugradiMotor(&m1);
	a1->staviGume(gume);
	Auto* a2 = new Auto(*(a1));
	Auto* a3 = new Auto;
	*a3 = *a1;
	a1->ispis();
	a2->ispis();
	a3->ispis();
	Motor m2("Ford", 600);
	a2->izvadiMotor();
	a2->ugradiMotor(&m2);
	vector<Guma*> gume2;
	for (int i = 0; i < 4; i++) {
		gume2.push_back(new Guma((i + 1), "ljetne"));
	}
	a1->skiniGume();
	a1->staviGume(gume2);
	cout << "\n\n";
	a1->ispis();
	a2->ispis();
	a3->ispis();
	/*Kreirati jedan objekt tipa Motor(m1) i 4 zimske gume.
		Kreirati objekt tipa Auto(a1) i ugraditi mu motor m1 i 4 gume.Objekt a1 kreirati koristeci operator „new“.
		Iz objekta a1 kreirati objekt a2(odabrati jedan nacin) :
		Tako da koristite kopirni konstruktor
		Tako da koristite operator pridruzivanja
		Ispisati podatke o oba automobila
		„Pojacati“ motor automobila a2 tako da mu povecate kubikažu
		Pretvoriti gume automobila a1 iz zimskih u ljetne(ili obrnuto, ovisno sto ste izabrali)
		Ispisati podatke o oba automobila
		Osloboditi memoriju za Automobil a1
		Ispisati podatke o automobilu a2
		Pokrenuti program tako da zakomentirate kopirni konstruktor i operator pridruzivanja.Sto se moze uociti ?*/
	return 0;
}