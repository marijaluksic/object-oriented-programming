#define _CRT_SECURE_NO_WARNINGS
#include<iostream>

#include<map>
#include<iterator>

#include<string>
using namespace std;

int main() {
	map<string, int> ime;
	int N;

	cout << "Unesi broj imena (N): ";
	cin >> N;

	for (int i = 0; i < N; i++) {
		string unesenoIme;
		cout << "Unesi ime: ";
		cin >> unesenoIme;
		ime[unesenoIme]++;
	}
	// ::iterator je pokazivac
	// najprije smo pokazivac "pozicijaNajcescegImena" stavili na 
	//prvo ime te smo vrijednost (odnosno broj ponavljanja imena)
	//postavili na broj ponavljanja prvog imena : to smo
	// ucinili koristenjem pokazivaca "second" koji pokazuje na
	// int "map<string, int> pozicijaNajcesegImena"
	// "->first" pokazuje na index (odnosno na string)
	// "->second" pokazuje na vrijednost
	map<string, int> ::iterator pozicijaNajcescegImena = ime.begin();
	int vrijednostNajcesceg = ime.begin()->second;

	for (map<string, int> ::iterator it = ime.begin(); it != ime.end(); it++) {
		if (it->second > vrijednostNajcesceg) {
			vrijednostNajcesceg = it->second;
			pozicijaNajcescegImena = it;
		}
	}
	cout << "Najcesce ime: " << pozicijaNajcescegImena->first << " (" << pozicijaNajcescegImena->second << " puta)" << endl;
	return 0;
}