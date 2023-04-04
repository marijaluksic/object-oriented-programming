#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <iostream>
#include <vector>
#include <string>
#include <math.h>
#include <cstring>
#include <algorithm>
#include <ctime>
#include <cctype>
#include <ctype.h>
#include <map>
#include <iterator>
using namespace std;

class Datum {
public:
	int dan, mjesec, godina;
	Datum(int _dan, int _mjesec, int _godina) : dan(_dan), mjesec(_mjesec), godina(_godina) {}
	
	bool operator >(Datum d) {
		if (godina > d.godina) {
			return true;
		}
		if (mjesec > d.mjesec) {
			return true;
		}
		if (dan > d.dan) {
			return true;
		}
		return false;
	}
};

ostream& operator << (ostream& izlaz, Datum d) {
	izlaz << d.dan << "." << d.mjesec << "." << d.godina << "." << endl;
	return izlaz;
}

Datum najveci_dan(map<string, vector<Datum>> m) {
	//2 OPCIJE DEKLARACIJE "::iterator"

	// OPCIJA 1:
	// map<string, vector<Datum>> ::iterator itMax = m.begin();
	// int maxIndex = 0; 
	
	// OPCIJA 2:
	auto itMax = m.begin();
	int maxIndex = 0;
	
	// ovime smo pretpostavili da je najveci datum u
	//prvoj mapi ("mapa a") te da je najveci datum
	//upravo prvi datum mape "a"
	for (auto it = m.begin(); it != m.end(); ++it) { // vanjska
		//"'for' petlja" sluzi za prelazenje iz mape a u mapu b u mapu c
		for (int i = 0; i < it->second.size(); i++) { // unutarnja mapa sluzi za prelazenje s 
			//datuma na datum unutar pojedine mape
			if (it->second[i] > itMax->second[maxIndex]) { // moramo definirati 
				//nacin usporedbe najveceg datuma-> "bool operator > (Datum d);"
				itMax = it;
				maxIndex = i;
			}
		}
	}
	return itMax->second[maxIndex];
}

void test2() {
	map<string, vector<Datum>> mapa; 
	//"->first" predstavlja index (odnosno nazive mapa koje su: "a", "b", "c")
	//"->second" predstavlja vrijednosti (odnosno datume unutar mapa)
	mapa["a"] = { Datum(4, 7, 2013), Datum(18, 6, 2015), Datum(20, 7, 2016),
	 Datum(20, 7, 2014), Datum(1, 7, 2015) };
	mapa["b"] = { Datum(11, 9, 2016), Datum(3, 10, 2016), Datum(4, 10, 2016),
	 Datum(30, 10, 2016) };
	mapa["c"] = { Datum(1, 2, 2012), Datum(7, 2, 2013), Datum(12, 1, 2014),
	 Datum(11, 1, 2015) };
	// mogu postojati i drugi kljucevi ...
	cout << "Najveci: " << najveci_dan(mapa); // ispisuje 30.10.2016.
}

int main() {
	test2();
	return 0;
}