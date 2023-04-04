#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

class Kompleksni {
public:
	double re, im;
	Kompleksni(double _re, double _im): re(_re), im(_im){}
};
Kompleksni operator + (Kompleksni Z, double broj) {
	return Kompleksni(Z.re + broj, Z.im);
}
ostream& operator << (ostream& izlaz, Kompleksni Z) {
	izlaz << Z.re << "+" << Z.im << "i" << endl;
	return izlaz;
}

class Matematika {
public:
	template<class T1, class T2>
	// OPCIJA 1
	// typename common_type<T1, T2>::type
	// typename common_type<T1, T2>::type suma(T1 a, T2 b){
	//		return a+b;
	// }

	// OPCIJA 2
	auto suma(T1 a, T2 b)->decltype(a+b) {
		return a + b;
	}
};

int main() {
	Matematika Racun;
	cout << Racun.suma(2, 4.3) << endl; // 6.3
	cout << Racun.suma(2.3, 4) << endl; // 6.3
	cout << Racun.suma(Kompleksni(2.5, 1), 4) << endl; // 6.5 1i
	return 0;
}