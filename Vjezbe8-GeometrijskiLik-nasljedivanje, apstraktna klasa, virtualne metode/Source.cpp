#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include<iostream>
#include<math.h>
#include<string>
using namespace std;

class GeometrijskiLik {
public:
	string Naziv;
	GeometrijskiLik(string _naziv) : Naziv(_naziv){}
	virtual double Opseg() = 0;
	virtual double Povrsina() = 0;
};

class Kvadrat : public GeometrijskiLik{
public:
	double a;
	Kvadrat(double _a) : a(_a), GeometrijskiLik("Kvadrat") {}
	double Opseg() {
		return a * 4;
	}
	double Povrsina() {
		return a * a;
	}
};

class Pravokutnik : public GeometrijskiLik {
public:
	double a, b;
	Pravokutnik(double _a, double _b) : GeometrijskiLik("Pravokutnik"), a(_a), b(_b) {}
	double Opseg() {
		return ((2 * a) + (2 * b));
	}
	double Povrsina() {
		return a * b;
	}
};

class Krug : public GeometrijskiLik {
public:
	double radijus;
	Krug(double _radijus) : GeometrijskiLik("Krug"), radijus(_radijus) {}
	double Opseg() {
		return 2 * radijus * M_PI;
	}
	double Povrsina() {
		return radijus * radijus * M_PI;
	}
};

int main() {
	GeometrijskiLik* Lik[3];
	Kvadrat Kvadrat1(1); // kvadrat sa stranicama duljine 1
	Pravokutnik Pravokutnik1(1, 2); // pravokutnik sa stranicama duljine 1 i 2
	Krug Krug1(1); // krug sa radijusom 1
	Lik[0] = &Kvadrat1;
	Lik[1] = &Pravokutnik1;
	Lik[2] = &Krug1;
	for (int i = 0; i < 3; i++)
		cout << Lik[i]->Naziv << " O=" << Lik[i]->Opseg()
		<< " P=" << Lik[i]->Povrsina() << endl;

	return 0;
}