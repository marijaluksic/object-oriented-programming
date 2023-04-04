#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <vector>
#include <cstring>
using namespace std;

class NeispravanOblikMatrice {
public:
	int ocekivaniStupci;
	int greskaStupac;
	NeispravanOblikMatrice(int x, int y) : ocekivaniStupci(x), greskaStupac(y) {}
	void ispis() {
		cout << "NeispravanOblikMatrice\nOcekivani broj stupaca u svakom retku: " << ocekivaniStupci <<
			"\nRedak u kojem se nalazi neispravan stupac: " << greskaStupac + 1 << "\n";
		exit(-1);
	}
};

class Matrica {
public:
	vector <vector<int>> unos;
	vector<int> redak;
	int brojRedaka = 0;
	vector <int> brojStupaca;
	int Stupci = 0;
	Matrica() {}
	Matrica(vector <vector<int>> _unos) {
			brojRedaka = _unos.size();
			for (int i = 0; i < _unos[0].size(); i++) {
				Stupci++;
			}
			for (int i = 0; i < _unos.size(); i++) {
				int j = 0;
				for (j = 0; j < _unos[i].size(); j++) {
				}
				brojStupaca.push_back(j);
			}
			try {
				for (int i = 0; i < brojRedaka; i++) {
					if (Stupci != brojStupaca[i]) {
						throw NeispravanOblikMatrice(Stupci, i);
					}
				}
			}
			catch (NeispravanOblikMatrice(iznimka)) {
				iznimka.ispis();
			}
			for (int i = 0; i < _unos.size(); i++) {
				for (int j = 0; j < _unos[0].size(); j++) {
					redak.push_back(0);
				}
				unos.push_back(redak);
			}
			for (int i = 0; i < _unos.size(); i++) {
				for (int j = 0; j < _unos[0].size(); j++) {
					unos[i][j] = _unos[i][j];
				}
			}
	}
	Matrica operator + (const Matrica& m1) {
		Matrica novaMatrica;
		vector<int> noviNiz;
		for (int i = 0; i < unos.size(); i++) {
			for (int j = 0; j < unos[0].size(); j++) {
				noviNiz.push_back(0);
			}
			novaMatrica.unos.push_back(noviNiz);
		}
		for (int i = 0; i < unos.size(); i++) {
			for (int j = 0; j < unos[0].size(); j++) {
				novaMatrica.unos[i][j] = (unos[i][j] + m1.unos[i][j]);
			}
		}
		return novaMatrica;
	}

	void ispisMatrice();
};
Matrica operator * (const Matrica& m1, int broj) {
	Matrica novaMatrica;
	vector<int> noviNiz;
	for (int i = 0; i < m1.unos.size(); i++) {
		for (int j = 0; j < m1.unos[0].size(); j++) {
			noviNiz.push_back(0);
		}
		novaMatrica.unos.push_back(noviNiz);
	}
	for (int i = 0; i < m1.unos.size(); i++) {
		for (int j = 0; j < m1.unos[0].size(); j++) {
			novaMatrica.unos[i][j]= (m1.unos[i][j] * broj);
		}
	}
	return novaMatrica;
}
Matrica operator * (int broj, const Matrica& m1) {
	Matrica novaMatrica;
	vector<int> noviNiz;
	for (int i = 0; i < m1.unos.size(); i++) {
		for (int j = 0; j < m1.unos[0].size(); j++) {
			noviNiz.push_back(0);
		}
		novaMatrica.unos.push_back(noviNiz);
	}
	for (int i = 0; i < m1.unos.size(); i++) {
		for (int j = 0; j < m1.unos[0].size(); j++) {
			novaMatrica.unos[i][j] = (m1.unos[i][j] * broj);
		}
	}
	return novaMatrica;
}
Matrica operator - (const Matrica& m1) {
	Matrica novaMatrica;
	vector<int> noviNiz;
	for (int i = 0; i < m1.unos.size(); i++) {
		for (int j = 0; j < m1.unos[0].size(); j++) {
			noviNiz.push_back(0);
		}
		novaMatrica.unos.push_back(noviNiz);
	}
	for (int i = 0; i < m1.unos.size(); i++) {
		for (int j = 0; j < m1.unos[0].size(); j++) {
			novaMatrica.unos[i][j] = ((-1) * m1.unos[i][j]);
		}
	}
	return novaMatrica;
}

void Matrica::ispisMatrice() {
	for (int i = 0; i < unos.size(); i++) {
		for (int j = 0; j < unos[0].size(); j++) {
			cout << unos[i][j] << "\t";
		}
		cout << endl;
	}
	cout << endl;
}

int main() {
	Matrica m({ { 2, 1, 4 }, { 3, 3, 8 }, { 1, 1, 5 } });  // neograniceni broj parametara
	Matrica x = m * 5;  // m se ne mijenja
	cout << "x:\n";
	x.ispisMatrice();
	Matrica y = 2 * m;  // m se ne mijenja
	Matrica z = x + y;  // x i y se ne mijenjaju
	x = -m;  // m se ne mijenja
	cout << "m:\n";
	m.ispisMatrice();
	cout << "x:\n";
	x.ispisMatrice();
	cout << "y:\n";
	y.ispisMatrice();
	cout << "z:\n";
	z.ispisMatrice();
	return 0;
}