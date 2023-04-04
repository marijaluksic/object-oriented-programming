#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <cstring>
using namespace std;

class Tekst {
private:
    char* SLOVA;
public:
    Tekst(const char* slova);
    
    Tekst(const Tekst& s);

    friend Tekst operator * (Tekst t1, int broj);
    friend Tekst operator * (int broj, Tekst t1);
    Tekst operator + (Tekst t1) {
        string prvi = SLOVA;
        string drugi = t1.SLOVA;
        string spojeni = prvi + drugi;
        return Tekst(spojeni.data());
    }
    friend Tekst operator - (Tekst t1, char slovoA);

    friend ostream& operator << (ostream& izlaz, Tekst p);
};

Tekst::Tekst(const char* slova) {
    int broj = strlen(slova);
    SLOVA = new char[broj];
    strcpy(SLOVA, slova);
}
Tekst::Tekst(const Tekst& s) {
    int broj = strlen(s.SLOVA);
    SLOVA = new char[broj];
    strcpy(SLOVA, s.SLOVA);
}

Tekst operator * (Tekst t1, int broj) {
    string duplikat = t1.SLOVA;
    for (int i = 0; i < broj - 1; i++) {
        duplikat += t1.SLOVA;
    }
    return Tekst(duplikat.data());
}
Tekst operator * (int broj, Tekst t1) {
    string duplikat = t1.SLOVA;
    for (int i = 0; i < broj - 1; i++) {
        duplikat += t1.SLOVA;
    }
    return Tekst(duplikat.data());
}
Tekst operator - (Tekst t1, char slovoA) {
    char * slovoA1 = &slovoA;
    char* token;
    string rezultat;
    token = strtok(t1.SLOVA, slovoA1);
    while (token != NULL)
    {
        rezultat += token;
        token = strtok(NULL, slovoA1);
    }
    return Tekst(rezultat.data());
}

ostream& operator << (ostream& izlaz, Tekst p) {
    int broj = strlen(p.SLOVA);
    for (int i = 0; i < broj; i++) {
        izlaz << p.SLOVA[i];
    }
    return izlaz;
}
int main() {
    Tekst t = "abc";
    Tekst p = t * 3;                // "umnozavanje" teksta
    cout << p << endl;                // ispisuje abcabcabc
    cout << 2 * t << endl;            // ispisuje abcabc

    // t mora ostati nepromijenjen!!!
    cout << t << endl;                // ispisuje abc

    cout << t + p << endl;            // ispisuje abcabcabcabc
    cout << t + p - 'a' << endl;    // ispisuje bcbcbcbc

    // p i t moraju ostati nepromijenjeni!!!
    cout << p << endl;                // ispisuje abcabcabc
    cout << t << endl;                // ispisuje abc
	return 0;
}