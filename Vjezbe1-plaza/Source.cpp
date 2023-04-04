#include<iostream>
#include<vector>
#include<string>
using namespace std;

class Predmet {
public:
	string opis;
	int kolicina;

	Predmet() {}
	Predmet(string _opis, int _kolicina) : opis(_opis), kolicina(_kolicina) {}
};

class Plaza{
public:
	int velicina;
	double X;
	double Y;
	vector<Predmet> nizpredmeta;
	Plaza() {}
	Plaza(int _velicina, double _X, double _Y) : velicina(_velicina), X(_X), Y(_Y) {}
};

int main() {
	int N;
	int M;
	int rednibroj;
	vector<Plaza> plaza;
	Plaza plazatmp;
	Predmet predmettmp;
	cout << "Unesite broj plaza (N):";
	cin >> N;
	for (int i = 0; i < N; i++) {
		cout << "Unesite velicinu i lokaciju za " << i + 1 << ". plazu:\n";
		cin >> plazatmp.velicina;
		cin >> plazatmp.X >> plazatmp.Y;
		plaza.push_back(plazatmp);
	}
	cout << "Unesite broj predmeta(M): ";
	cin >> M;
	if (M > 0) {
		for (int i = 0; i < M; i++) {
			cout << "Unesite redni broj plaze kojoj pripada " << i + 1 << ". predmet: ";
			cin >> rednibroj;
			cout << "Unesite kolicinu i opis predmeta: ";
			cin >> predmettmp.kolicina >> predmettmp.opis;
			plaza[rednibroj-1].nizpredmeta.push_back(predmettmp);
		}
	}
	cout << "Ispis plaza i predmeta :";
	for (int i = 0; i < N; i++) {
		cout << "\n" << i+1 << ". " << plaza[i].X << " " << plaza[i].Y << " " << " D=" << plaza[i].velicina << " - predmeti:";
		if (M > 0) {
			for (int j = 0; j < plaza[i].nizpredmeta.size(); j++) {
				cout << " " << plaza[i].nizpredmeta[j].kolicina << " ";
				cout << plaza[i].nizpredmeta[j].opis;
			}
		}
	}
	return 0;
}