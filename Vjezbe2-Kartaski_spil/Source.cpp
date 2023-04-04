#include <string>
#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <ctime>
using namespace std;

class Igrac {
public:
	string imeIgraca;
	vector<int> podijeljeneKarte;
	Igrac(){}
	Igrac(string imeIgraca): imeIgraca(imeIgraca){}
};

class Spil {
public:
	vector<int> Karta;
	Spil(bool izmijesane);
	void Podijeli4Karte(Igrac *igrac);
};
void Spil::Podijeli4Karte(Igrac *igrac) {
	for (int i = 0; i < 4; i++) {
		igrac->podijeljeneKarte.push_back(Karta[0]);
		Karta.erase(Karta.begin());
	}
}
Spil::Spil(bool izmijesane):Karta(vector<int>(52)) {
	for (int i = 0; i < 52; i++) {
		Karta[i] = i + 1;
	}
	if (izmijesane == true) {
		srand((unsigned)time(NULL));
		random_shuffle(Karta.begin(), Karta.end());
	}
}
int main() {
	int n;
	vector<Igrac> igrac;
	Spil Djelitelj(false);
	cout << "Unesi broj igraca : ";
	cin >> n;
	if (n > 13) {
		cout << "Previse igraca!";
		return -1;
	}
	for (int i = 0; i < n; i++) {
		string ime;
		cout << "\nUnesi ime " << i + 1 << ".igraca: ";
		cin >> ime;
		igrac.push_back(Igrac(ime));//privremeni objekt
	}
	cout << "\nKarte u spilu(" << Djelitelj.Karta.size() << "(:\n";
	for (int i = 0; i < Djelitelj.Karta.size(); i++) {
		cout << Djelitelj.Karta[i] << "\t";
	}
	cout << "\n\n";
	for (int i = 0; i < igrac.size(); i++) {
		Djelitelj.Podijeli4Karte(&igrac[i]);
		cout << igrac[i].imeIgraca << " je dobio sljedece karte: ";
		for (int j = 0; j < igrac[i].podijeljeneKarte.size(); j++) {
			cout << igrac[i].podijeljeneKarte[j] << "\t";
		}
		cout << endl;
	}
	cout << endl;
	cout << "Preostale karte u spilu (" << Djelitelj.Karta.size() << "):\n";
	for (int i = 0; i < Djelitelj.Karta.size(); i++) {
		cout << Djelitelj.Karta[i] << "\t";
	}
	cout << endl;
	return 0;
}