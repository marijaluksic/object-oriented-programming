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
#include <tuple>
#include <functional>
using namespace std;

class Kosulja {
public:
	string oznakaProizvodaca;
	string duljinaRukava;
	bool dugiKratki;
	static int brojDugih;
	Kosulja(string _oznakaProizvodaca, string _duljinaRukava): oznakaProizvodaca(_oznakaProizvodaca), duljinaRukava(_duljinaRukava){
		if (_duljinaRukava == "dugi") {
			dugiKratki = true;
			brojDugih++;
		}
		else if (_duljinaRukava == "kratki") {
			dugiKratki = false;
		}
	}
	int static getZimskeKosulje();
	bool getdugiKratki() const{
		return dugiKratki;
	}
	string getoznakaProizvodaca()const {
		return oznakaProizvodaca;
	}
};
namespace Namjestaj {
	class Ormar {
	public:
		vector<Kosulja> niz;
		Ormar() {}
		template<class ...T>
		Ormar(T ...argumenti) :niz({ argumenti... }) {}
		Ormar(initializer_list<Kosulja> _argumenti): niz(_argumenti){}
		virtual string getIzvedba() {
			return "Ormar";
		}
	};
}
int Kosulja::getZimskeKosulje() {
	return brojDugih;
}
Namjestaj::Ormar operator + (Namjestaj::Ormar o1, Namjestaj::Ormar o2) {
	Namjestaj::Ormar novi;
	for (int i = 0; i < o1.niz.size(); i++)
	{
		novi.niz.push_back(o1.niz[i]);
	}
	for (int i = 0; i < o2.niz.size(); i++)
	{
		novi.niz.push_back(o2.niz[i]);
	}
	return novi;
}
namespace Namjestaj {
	class Ugradbeni : public Namjestaj::Ormar {
	public:
		template<class ...T>
		Ugradbeni(T ...argumenti) : Namjestaj::Ormar({ argumenti... }) {}
		Ugradbeni(initializer_list<Kosulja> _argumenti) : Namjestaj::Ormar(_argumenti) {}
		string getIzvedba() {
			return "Ugradbeni ormar";
		}
	};
	class Samostojeci : public Namjestaj::Ormar {
	public:
		template<class ...T>
		Samostojeci(T ...argumenti) : Namjestaj::Ormar({ argumenti... }) {}
		Samostojeci(initializer_list<Kosulja> _argumenti) : Namjestaj::Ormar(_argumenti) {}
		string getIzvedba() {
			return "Samostojeci ormar";
		}
	};
}
bool usporediKosulje(Kosulja& pocetak,Kosulja& kraj)
{
	if ( pocetak.dugiKratki != kraj.dugiKratki)
		return pocetak.dugiKratki < kraj.dugiKratki;
	else
		return pocetak.oznakaProizvodaca < kraj.oznakaProizvodaca;
}
class Usporedba {
public:
	bool operator()(Kosulja& pocetak,Kosulja& kraj)
	{
		if (pocetak.dugiKratki != kraj.dugiKratki)
			return pocetak.dugiKratki < kraj.dugiKratki;
		else
			return pocetak.oznakaProizvodaca < kraj.oznakaProizvodaca;
	}
};
class Soba {
public: 
	Namjestaj::Ormar* ptrOrmar;
	Soba() {}
	Soba(Namjestaj::Ormar* _ptrOrmar) {
		ptrOrmar = new Namjestaj::Ormar();
		*ptrOrmar = *_ptrOrmar;
	}
	~Soba() {
		if (ptrOrmar != nullptr) { // destruktor
			delete ptrOrmar;
		}
	}

	//semantika kopiranja
	Soba(const Soba& s) {
		ptrOrmar = new Namjestaj::Ormar();
		*ptrOrmar = *s.ptrOrmar;
	}
	Soba& operator = (const Soba& s) { // OPERATOR PRIDRUZIVANJA SA SEMANTIKOM KOPIRANJA
		if (this != &s)
		{
			delete ptrOrmar;
			ptrOrmar = new Namjestaj::Ormar();
			*ptrOrmar = *s.ptrOrmar;
		}

		return *this;
	}

	//semantika prijenosa
	Soba(Soba&& s) { // PRIJENOSNI KONSTRUKTOR; 2 reference s = parametar je privremeni objekt
		*ptrOrmar = *s.ptrOrmar;
		s.ptrOrmar = nullptr;
	}
};

int Kosulja::brojDugih = 0;

int main() {
	Kosulja a("jpofwejiijewf", "dugi");
	Kosulja b("klndcncl", "kratki");
	Kosulja c("ijdcijwijowe", "dugi");
	Kosulja d("jdjdj", "dugi");
	Kosulja e("j45jdj", "kratki");
	cout << a.getZimskeKosulje() << endl;
	//b) i c) razlika u zagradama!!!
	Namjestaj::Ormar ormar1(a, b);
	Namjestaj::Ormar ormar2{ c, d, e };
	Namjestaj::Ormar ormar3 = ormar1 + ormar2;
	for (int i =0;i<ormar3.niz.size();i++){
		cout << ormar3.niz[i].oznakaProizvodaca << "\t" << ormar3.niz[i].duljinaRukava << endl;
	}
	Namjestaj::Ormar* ptrOrmar;
	Namjestaj::Ugradbeni ugradbeni;
	Namjestaj::Samostojeci samostojeci;
	ptrOrmar = &ugradbeni;
	cout << ptrOrmar->getIzvedba() << endl;
	ptrOrmar = &samostojeci;
	cout << ptrOrmar->getIzvedba() << endl;
	
	{
		Namjestaj::Ormar ormar4(Kosulja("Akropola", "dugi"), Kosulja( "Bjelovar23", "kratki" ), Kosulja( "Antioksidans", "dugi" ), Kosulja( "Bjelovar86", "kratki" ));

		{ // f) pod a
			sort(ormar4.niz.begin(), ormar4.niz.end(), usporediKosulje);
			cout << "\nsorted s globalnom funkcijom: " << endl;
			for (int i = 0; i < ormar4.niz.size(); i++) {
				cout << ormar4.niz[i].oznakaProizvodaca << "\t" << ormar4.niz[i].duljinaRukava << endl;
			}
		}

		{ // f) pod b
			sort(ormar4.niz.begin(), ormar4.niz.end(), Usporedba());
			cout << "\nsorted s funkcijskim objektom: " << endl;
			for (int i = 0; i < ormar4.niz.size(); i++) {
				cout << ormar4.niz[i].oznakaProizvodaca << "\t" << ormar4.niz[i].duljinaRukava << endl;
			}
		}

		{ // f) pod c
			sort(ormar4.niz.begin(), ormar4.niz.end(), [](Kosulja& pocetak, Kosulja& kraj)
				{
					if (pocetak.dugiKratki != kraj.dugiKratki)
						return pocetak.dugiKratki < kraj.dugiKratki;
					else
						return pocetak.oznakaProizvodaca < kraj.oznakaProizvodaca;
				});
			cout << "\nsorted s lambda funkcijom: " << endl;
			for (int i = 0; i < ormar4.niz.size(); i++) {
				cout << ormar4.niz[i].oznakaProizvodaca << "\t" << ormar4.niz[i].duljinaRukava << endl;
			}
		}
	}
	Soba s1 = Soba(new Namjestaj::Ormar(Kosulja("Akropola", "dugi"), Kosulja("Bjelovar23", "kratki")));
	Soba s2;
	s2 = s1;
	s1 = Soba(new Namjestaj::Ormar(Kosulja("Malazija", "dugi"), Kosulja("Bukurest", "kratki")));
	cout << "\n\n";
	for (int i = 0; i < s1.ptrOrmar->niz.size(); i++) {
		cout << s1.ptrOrmar->niz[i].oznakaProizvodaca << endl;
	}
	cout << "\n\n";
	for (int i = 0; i < s2.ptrOrmar->niz.size(); i++) {
		cout << s2.ptrOrmar->niz[i].oznakaProizvodaca << endl;
	}
	return 0;
}
