#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <vector>
#include <cstring>
using namespace std;

class Osoba {
public:
	string Prezime;
	string Ime;
	void RadniStatus();
	string OIB;
	Osoba(string oib) : OIB(oib) {}
};

class Student : public Osoba {
public:
	string NazivStudija;
	string Smjer;
	int Semestar;
	Student(string oib) : Osoba(oib) {}

	// OVERRIDE/PRIJEPISNE METODE = skrivanje metode bazne klase(bazna klasa -> Osoba)
	void RadniStatus();
};

void Osoba::RadniStatus() {
	cout << "Osoba nema radni status!\n";
}

void Student::RadniStatus() {// OVERRIDE/PRIJEPISNE METODE
	cout << "Redovni student\n";
}

int BrojStudenata(Student* p, int elem, int semestar) {
	int brojac = 0;
	for (int i = 0; i < elem; i++) {
		if (p[i].Semestar == semestar) {
			brojac++;
		}
	}
	return brojac;
}

int main() {
	Student Ante("1234");
	Ante.RadniStatus();
	Ante.Osoba::RadniStatus();

	// STATICKO POLJE
	Student GrupaA[3] = { Student("123"), Student("234"), Student("345") }; // 1.) nacin inicijalizacije
	//Student GrupaA[3] = { {"123"}, {"234"}, {"345"} }; // 2.) nacin inicijalizacije
	return 0;
}