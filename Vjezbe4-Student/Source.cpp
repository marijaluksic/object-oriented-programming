#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<string>
#include<cstring>
using namespace std;

class Student {
private:
	char* JMBAG;
public:
	Student() {} //PODRAZUMIJEVANI KONSTRUKTOR
	Student(const char* jmbag); // konstruktor (alocira JMBAG duljine 11 znakova)
	~Student(); // destruktor (dealocira JMBAG)
	char* GetJMBAG() const;
	void SetJMBAG(const char* noviJMBAG);

	//semantika kopiranja
	Student(const Student& s); // DEEP COPY ZA POZIV KOPIRNOG KONSTRUKTORA
	Student& operator = (const Student& s); // DEEP COPY ZA OPERATOR PRIDRUZIVANJA

	//semantika prijenosa
	Student(Student&& s); // KOPIRNI KONSTUKTOR SA SEMANTIKOM PRIJENOSA; 2 reference s = parametar je privremeni objekt
	Student& operator = (Student&& s); // OPERATOR PRIDRUZIVANJA SA SEMANTIKOM PRIJENOSA
};

Student::Student(const char* jmbag) {
	JMBAG = new char[11]; // konstruktor (alocira JMBAG duljine 11 znakova)
	strcpy(JMBAG, jmbag);
}
Student::~Student() {
	delete[] JMBAG;
}
char* Student::GetJMBAG() const {
	return JMBAG; // ILI return &JMBAG[0];
}
void Student::SetJMBAG(const char* noviJMBAG) {
	strcpy(JMBAG, noviJMBAG);
}
Student::Student(const Student& s) {
	JMBAG = new char[11]; //KREIRA NOVU LOKACIJU ZA JMBAG
	strcpy(JMBAG, s.JMBAG);
}
Student& Student::operator = (const Student& s) {//POVRATNA VRIJEDNOST OPERATORA JE REFERENCA - ZBOG ULANCAVANJA OPERATORA
	if (this != &s) { // SPRJECAVANJE PRIDRUZIVANJA OBJEKTA SAMOME SEBI; this = objekt s lijeve strane; &s = objekt s desne strane
		delete[] JMBAG; // KADA DEKLARIRAMO BEZ INICIJALIZACIJE(odn. NAKNADNO INICIJALIZIRAMO), TREBAMO PRVO DEALOCIRATI (odn. OBRISATI) 
		JMBAG = new char[11]; //
		strcpy(JMBAG, s.JMBAG);
	}
	return *this;
}
Student::Student(Student&& s) {
	JMBAG = s.JMBAG;
	s.JMBAG = NULL; //sprjecavamo dealociranje JMBAG-a objekta Student("21312"), odn. omogucavamo da Student Ana koristi njegov JMBAG
}
Student& Student::operator = (Student&& s) {
	if (this != &s) {
		delete[] JMBAG;
		JMBAG = s.JMBAG;
		s.JMBAG = NULL;
	}
	return *this;
}

int main() {
	Student Ante("1122334455");
	Student Ivica = Ante; // POZIV KOPIRNOG KONSTRUKTORA (DEKLARACIJA I INICIJALIZACIJA ODJEDNOM) - PO DEFAULT-U SE DOGODI SHALLOW COPY, A POTREBAN JE DEEP COPY
	Ante.SetJMBAG("6677889900");
	cout << Ante.GetJMBAG() << endl; // 6677889900
	cout << Ivica.GetJMBAG() << endl; // 6677889900 ?!?!
	Student Marko;
	Marko = Ante; // OPERATOR PRIDRUZIVANJA - PO DEFAULT-U SE DOGODI SHALLOW COPY, A POTREBAN JE DEEP COPY
	Marko.SetJMBAG("1234567890");
	cout << Marko.GetJMBAG() << endl; // 1234567890
	cout << Ante.GetJMBAG() << endl; // 1234567890 ?!?!

	// SEMANTIKA PRIJENOSA
	//Student("21312") je PRIVREMENI OBJEKT
	//moramo napraviti KONSTRUKTOR SA SEMANTIKOM PRIJENOSA
	Student Ana = Student("21312");

	Student Tena;
	Tena = Student("34324"); //OPERATOR PRIDRUZIVANJA SA SEMANTIKOM PRIJENOSA
	return 0;
}