#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>
#include <ctime>
using namespace std;
class Kompleksni {
private:
	double re;
	double im;
public:
	Kompleksni(double _re, double _im):re(_re), im(_im){}

	// CLANSKA OPERATORSKA FUNKCIJA = koristimo kada su lijevi i desni operand ISTOG TIPA
	//	-imaju samo 1 parametar -> LIJEVI parametar "Z1" je PODRAZUMIJEVANOG TIPA stoga pisemo samo parametar koji predstavlja desni operand
	// 1. primjer, ZBRAJANJE
	Kompleksni operator + (Kompleksni Z2){
		return Kompleksni(re + Z2.re, im + Z2.im);
	}
	// 2. primjer, MNOZENJE
	Kompleksni operator * (Kompleksni Z2) {
		// (Z1.re + Z1.im)(Z2.re + Z2.im) = 
		// (re * Z2.re) + (re * Z2.im) + (im * Z2.re) - (im * Z2.im) =
		// REALNI DIO: ((re * Z2.re) - (im * Z2.im))
		// IMAGINARNI DIO: ((re * Z2.im) + (im * Z2.re))
		return Kompleksni(((re * Z2.re) - (im * Z2.im)), ((re * Z2.im) + (im * Z2.re)));
	}
	// 6. primjer, PREFIKS (++Z)
	Kompleksni& operator ++() {
		++re;
		++im;
		return *this;
	}
	// 7. primjer, POSTFIKS (Z++)
	Kompleksni operator ++(int) { // (int) sluzi samo za razlikovanje od operatora prefiksa
		Kompleksni pomocni = *this; // prvo spremamo trenutnu vrijednost
		re++;
		im++;
		return pomocni;
	}

	// NE-CLANSKA OPERATORSKA FUNKCIJA
	// 5. primjer, ISPIS <<
	friend ostream& operator << (ostream& izlaz, Kompleksni Z);
	// 3. primjer, ODUZIMANJE
	friend Kompleksni operator - (Kompleksni Z1, double broj);
	// 4. primjer, ODUZIMANJE
	friend Kompleksni operator - (double re, Kompleksni Z);

	//// 1. primjer, ZBRAJANJE -> NE-CLANSKA OPERATORSKA FUNKCIJA
	//friend Kompleksni operator + (Kompleksni Z1, Kompleksni Z2);
};

// NE-CLANSKA OPERATORSKA FUNKCIJA
ostream& operator << (ostream& izlaz, Kompleksni Z) {
	izlaz << Z.re << ((Z.im >= 0) ? "+" : "") << Z.im << "i";
	return izlaz;
}

//// 1. primjer, ZBRAJANJE -> NE-CLANSKA OPERATORSKA FUNKCIJA
//Kompleksni operator + (Kompleksni Z1, Kompleksni Z2) {
//	return Kompleksni(Z1.re + Z2.re, Z1.im + Z2.im);
//}

// 3. primjer, ODUZIMANJE
Kompleksni operator - (Kompleksni Z, double re) {
	return Kompleksni(Z.re - re, Z.im);
}

// 4. primjer, ODUZIMANJE
Kompleksni operator - (double re, Kompleksni Z) {
	return Kompleksni(re - Z.re, Z.im);
}

int main() {
	// Z1 = 1, Z2 = 2 - i
	Kompleksni Z1(1, 0), Z2(2, -1);
	// clanska operatorska funkcija + (Kompleksni)
	Kompleksni Suma = Z1 + Z2;
	cout << Suma << endl; // 3 - 1i
	// clanska operatorska funkcija * (Kompleksni)
	Kompleksni Umnozak = Z1 * Z2;
	cout << Umnozak << endl; // 2 - 1i
	// ne-clanska operatorska funkcija - (Kompleksni, double)
	Kompleksni Razlika = Suma - 3;
	cout << Razlika << endl; // 0 - 1i
	// ne-clanska operatorska funkcija - (double, Kompleksni)
	Kompleksni Razlika2 = 3 - Suma;
	cout << Razlika2 << endl; // 0 - 1i


	Kompleksni Z5(0, 0);
	//prefiks ++
	cout << ++Z5 << endl; // 1 + 1i
	//postfiks ++
	cout << Z5++ << endl; // 1 + 1i
	cout << Z5 << endl; // 2 + 2i
	return 0;
}
