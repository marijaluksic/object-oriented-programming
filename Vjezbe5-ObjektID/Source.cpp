#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

class Objekt {
public:
	int ID;
	static int brojInstanci;
	static int zadnjiID;
	Objekt() {
		ID = ++zadnjiID;
		brojInstanci++;
	}
	~Objekt() {
		brojInstanci--;
	}
	static int BrojInstanci(){
		return brojInstanci;
	}
};
int Objekt::brojInstanci = 0;
int Objekt::zadnjiID = 0;

int main() {
	Objekt obj1; // ID = 1, brojInstanci = 1
	Objekt niz[10]; // ID = 2..11, brojInstanci = 11
	Objekt* p = new Objekt[10]; // ID = 12..21, brojInstanci = 21
	delete[] p; // brojInstanci = 11!
	Objekt zadnji;
	cout << zadnji.ID << " " << Objekt::BrojInstanci() << endl; // 22 12
	return 0;
}