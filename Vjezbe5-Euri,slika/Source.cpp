#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include<algorithm>
#include <vector>
using namespace std;

class Slika {
public:
	float cijena;
	static float ukupnaCijena;
	static float brojSlika;
	Slika(float _cijena): cijena(_cijena){
		ukupnaCijena += cijena;
		brojSlika++;
	}
	static float ProsjecnaCijena() {
		return (ukupnaCijena/brojSlika);
	}
};
float Slika::ukupnaCijena = 0;
float Slika::brojSlika = 0;

int main() {
	Slika Slika1(2000); // 2000 eura

	Slika Slika2(3000); // 3000 eura

	Slika Slika3(1800); // 1800 eura

	cout << Slika::ProsjecnaCijena() << " eura"; // 2266.67 eura
	return 0;
}