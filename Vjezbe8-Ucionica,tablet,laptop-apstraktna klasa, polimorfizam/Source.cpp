#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<string>
using namespace std;

class Racunalo {
public:
    string naziv;
    Racunalo(string _naziv): naziv(_naziv){}
};

class Tablet : public Racunalo {
public:
    static int brojTableta;
    Tablet(string naziv):Racunalo(naziv){
        brojTableta++;
    }
};

class Laptop : public Racunalo {
public:
    static int brojLaptopa;
    Laptop(string naziv) : Racunalo(naziv) {
        brojLaptopa++;
    }
};

void AnalizaUcionice(vector<Racunalo*> ucionica1, int* brTableta, int* brLaptopa, int* brAndroida, int* brWindowsa, int* brLinuxa) {
    int brojAndroida = 0;
    int brojWindowsa = 0;
    int brojLinuxa = 0;
    for (int i = 0; i < ucionica1.size(); i++) {
        if (ucionica1[i]->naziv == "Android") {
            brojAndroida++;
        }
        if (ucionica1[i]->naziv == "Windows") {
            brojWindowsa++;
        }
        if (ucionica1[i]->naziv == "Linux"){
            brojLinuxa++;
        }
    }
    *brTableta = Tablet::brojTableta;
    *brLaptopa = Laptop::brojLaptopa;
    *brLinuxa = brojLinuxa;
    *brAndroida = brojAndroida;
    *brWindowsa = brojWindowsa;
}
int Tablet::brojTableta = 0;
int Laptop::brojLaptopa = 0;
int main() {
    int brTableta, brLaptopa;
    int brAndroida, brWindowsa, brLinuxa;

    Tablet Acer("Android"), Prestigio("Windows");
    Laptop Dell("Linux"), IBM("Windows"), Toshiba("Windows");

    vector<Racunalo*> Ucionica1 = { &Acer, &Prestigio, &Dell, &IBM, &Toshiba };
    AnalizaUcionice(Ucionica1, &brTableta, &brLaptopa, &brAndroida, &brWindowsa, &brLinuxa);


    /* u nastavku ispisite dobivenu analizu ucionice u sljedecem obliku:

    U ucionici se nalazi 5 racunala
    Broj tablet racunala : 2
    Broj laptop racunala : 3
    Android OS : 1
    Windows OS : 3
    Linux OS : 1
    */
    cout << "U ucionici se nalazi " << Ucionica1.size() << " racunala\nBroj tablet racunala : " << brTableta << "\nBroj laptop racunala : " << brLaptopa << "\nAndroid OS : " << brAndroida << "\nWindows OS : " << brWindowsa << "\nLinux OS : " << brLinuxa << "\n";
    return 0;
}