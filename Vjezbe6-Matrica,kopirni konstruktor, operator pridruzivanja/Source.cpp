#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <vector>
#include <cstring>
using namespace std;

class Matrica {
public:
	vector<int*> redak;
	vector<int> stupac;

	void dodaj(int brStupaca, int* _redak);
	Matrica() {}
	Matrica(const Matrica& m); //kopirni konstruktor (ima const i 1 referencu)
	Matrica& operator = (const Matrica& m); // operator pridruzivanja sa semantikom kopiranja (ima 1 referencu i const)
	Matrica(Matrica&& m); //konstruktor prijenosa (nema const i ima dvostruku referencu)
	void ispis();
	~Matrica();
};
void Matrica::dodaj(int brStupaca, int* _redak) {
	redak.push_back(_redak);
	stupac.push_back(brStupaca);
}
Matrica::Matrica(const Matrica& m) {
	for (int i = 0; i < m.redak.size(); i++) {
		redak.push_back(new int[m.stupac[i]]);
		stupac.push_back(m.stupac[i]);
		for (int j = 0; j < stupac[i]; j++) {
			redak[i][j] = m.redak[i][j];
		}
	}
}
Matrica& Matrica::operator = (const Matrica& m) {
	if (this != &m) {
		for (int i = 0; i < redak.size(); i++) {
			delete[] redak[i];
		}
		redak.clear();
		stupac.clear();
		for (int i = 0; i < m.redak.size(); i++) {
			redak.push_back(new int[m.stupac[i]]);
			stupac.push_back(m.stupac[i]);
			for (int j = 0; j < stupac[i]; j++) {
				redak[i][j] = m.redak[i][j];
			}
		}
	}
	return *this;
}
Matrica::Matrica(Matrica&& m) {
	for (int i = 0; i < m.redak.size(); i++) {
		redak.push_back(m.redak[i]);
		m.redak[i] = NULL; // -preusmjerili smo pokazivace priveremnog 
//objekta na NULL tako da destruktor tog privremenog objekta nebi te 
//retke dealocirao
		stupac.push_back(m.stupac[i]);
	}
}
void Matrica::ispis() {
	for (int i = 0; i < redak.size(); i++) {
		for (int j = 0; j < stupac[i]; j++) {
			cout << redak[i][j] << " ";
		}
		cout << endl;
	}
}
Matrica::~Matrica() {
	for (int i = 0; i < redak.size(); i++) {
		delete[] redak[i];
	}
}
int main() {
	Matrica m;
	m.dodaj(3, new int[3]{ 1, 6, 2 });
	m.dodaj(5, new int[5]{ 5, 3, 4, 7, 0 });
	m.dodaj(4, new int[4]{ 6, 2, 6, 5 });
	m.ispis();

	Matrica m2 = m; // - poziv kopirnog konstuktora

	Matrica m3; // - poziv operatora pridruzivanja sa
	m3 = m2; // semantikom kopiranja

	cout << "Druga matrica:\n";
	m2.ispis();
	cout << "Treca matrica:\n";
	m3.ispis();

	return 0;
}