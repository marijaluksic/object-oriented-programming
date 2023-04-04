#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <functional>
using namespace std;

vector<int> izdvoji(vector<int>& vbrojevi, function<bool(int i)> kriterij) {
	vector<int> pomocniVektor;
	for (int i = 0; i < vbrojevi.size(); i++) {
		if (kriterij(i)) {
			pomocniVektor.push_back(vbrojevi[i]);
		}
	}
	return pomocniVektor;
}

int main()
{
	vector<int> brojevi = { 4, 43, 62, 38, 48, 33, 12, 4, 87, 50, 96, 81, 87, 35, 52, 26, 74, 56, 30, 3, 67 };

	vector<int> rez = izdvoji(brojevi, [](int i) {return ( i % 4 == 1); } );

	for (int i = 0; i < rez.size(); i++)
		cout << rez[i] << " ";
	//ispis: 43 33 50 35 56
	return 0;
}