#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstring>
#include<vector>
#include<string>
#include<algorithm>
#include<cctype>
#include<ctype.h>
using namespace std;

class StringProcessUnit {
public:
	string unos;
	StringProcessUnit(string _unos) : unos(_unos){}
	virtual string processString(string x) = 0;
};
class StringProcessMachine {
public:
	vector<StringProcessUnit*> processingUnits;
	StringProcessMachine(){}
	string processData(string s) {
		string novi = s;
		for (int i=0;i<processingUnits.size();i++){
			novi=processingUnits[i]->processString(novi);
		}	
		return novi;
	}
};
class CapitalizerUnit : public StringProcessUnit {
public:
	CapitalizerUnit(string unos) : StringProcessUnit(unos){}
	string processString(string x) {
		for (int i = 0; i < x.length(); i++) {
			if (islower(x[i])) {
				x[i] = toupper(x[i]);
			}
			else if (isupper(x[i])) {
				x[i] = tolower(x[i]);
			}
		}
		return x;
	}
};
class DuplicatorUnit : public StringProcessUnit {
public:
	DuplicatorUnit(string unos) : StringProcessUnit(unos) {}
	string processString(string x) {
		string noviX;
		for (int i = 0; i < x.length(); i++) {
			if ((x[i]) == 'A' || (x[i]) == 'a' || (x[i]) == 'E' || (x[i]) == 'e' || (x[i]) == 'i' || (x[i]) == 'I' || (x[i]) == 'O' || (x[i]) == 'o' || (x[i]) == 'U' || (x[i]) == 'u' ) {
				noviX += x[i];
			}
			noviX += x[i];
		}
		return noviX;
	}
};
class SplitterUnit : public StringProcessUnit {
public:
	SplitterUnit(string unos) : StringProcessUnit(unos) {}
	string processString(string x) {
		string noviX;
		string razmak = " ";
		for (int i = 0; i < x.length(); i++) {
			noviX += x[i];
			if (i>0 && (i%4 ==0 || i%7==0)) {
				noviX += razmak;
			}
		}
		return noviX;
	}
};
int main() {
	StringProcessMachine ulaz;
	StringProcessUnit* unit;
	int brojTransformacija = 0;
	string s;
	string transformacija;
	cout << "Unesite broj zeljenih transformacija stringa: ";
	cin >> brojTransformacija;
	cout << "\nUnesite zeljene transformacije stringa: ";
	cin >> transformacija;
	cout << "\nUnesite string kojeg zelite transformirati: ";
	cin >> s;
	for (int i = 0; i < brojTransformacija; i++) {
		if (transformacija[i] == 'C') {
			//unit = &(CapitalizerUnit(s));
			ulaz.processingUnits.push_back(&(CapitalizerUnit(s)));
		}
		if (transformacija[i] == 'D') {
			//unit = &(DuplicatorUnit(s));
			ulaz.processingUnits.push_back(&(DuplicatorUnit(s)));
		}
		if (transformacija[i] == 'S') {
			//unit = &(SplitterUnit(s));
			ulaz.processingUnits.push_back(&(SplitterUnit(s)));
		}
	}
	cout << ulaz.processData(s);
	return 0;
}