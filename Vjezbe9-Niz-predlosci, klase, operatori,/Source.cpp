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

template<class T>
class Niz {
public:
	vector<T> polje;
	Niz(vector<T> _polje);

	int manje_od(const Niz& _niz) {
		for (int i = 0; i < 3; i++) {
			if (polje[i] > _niz.polje[i]) {
				return false;
				break;
			}
		}
		return true;
	}
};

template <class T>
Niz<T>::Niz(vector<T> _polje) {
	polje = _polje;
	/*for (int i = 0; i < polje.size(); i++) {
		cout << polje[i] << "\t";
	}
	cout << endl;*/
}

template <class T>
bool operator < (T& niz1, T& niz2) {
	bool rezultat = niz1.manje_od(niz2);
	if (rezultat == false) {
		rezultat = (niz1 >= niz2);
	}
	return rezultat;
}
template<class T>
bool operator >= (T& niz1, T& niz2) {
	return true;
}

template<class T>
class Niz2 : public Niz<T> {
public:
	Niz2(vector<T> polje) : Niz<T>(polje){}

	template<class T>
	bool operator < (T& niz2) {
		bool rezultat = this->manje_od(niz2);
		return rezultat;
	}
};


int main() {
	vector<int> v1 = { 1, 2, 3 };

	vector<int> v2 = { 11, 0, 13 };

	Niz<int> p1(v1);

	Niz<int> p2(v2);

	cout << (p1 < p2) << endl;  // operator <
	
	Niz2<int> p3(v1);

	cout << (p3 < p2) << endl;

	return 0;
}