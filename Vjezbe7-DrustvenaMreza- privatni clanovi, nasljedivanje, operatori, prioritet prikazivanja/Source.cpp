#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <vector>
#include <cstring>
using namespace std;

class Sadrzaj {
private:
	string datum, vrijemeObjave, razinaPrivatnosti, korisnik;
public:
	Sadrzaj(string _datum, string _vrijemeObjave, string _razinaPrivatnosti, string _korisnik) : datum(_datum), vrijemeObjave(_vrijemeObjave), razinaPrivatnosti(_razinaPrivatnosti), korisnik(_korisnik) {}
	void setDatum(string _datum);
	void setVrijemeObjave(string _vrijemeObjave);
	void setRazinaPrivatnosti(string _razinaPrivatnosti);
	void setKorisnik(string _korisnik);
	string getDatum()const;
	string getVrijemeObjave()const;
	string getRazinaPrivatnosti()const;
	string getKorisnik()const;

	virtual void ispis() { 
		cout << getKorisnik() << "\t" << getDatum() << "\t" << getVrijemeObjave() << "\t" << getRazinaPrivatnosti() << "\n"; 
	}
	//tip sadrzaja
		//tip - video -> url videa
		//			  -> naslov videa
		//			  -> trajanje videa
	//datum i vrijeme objave
	//razina privatnosti
	//ime korisnika
};

class Video : public Sadrzaj {
private:
	string url, naslov, trajanje;
public:
	Video(string datum, string vrijemeObjave, string razinaPrivatnosti, string korisnik, string _url, string _naslov, string _trajanje) : Sadrzaj(datum, vrijemeObjave, razinaPrivatnosti, korisnik), url(_url), naslov(_naslov), trajanje(_trajanje) {}
	void setUrl(string _url);
	void setNaslov(string _naslov);
	void setTrajanje(string _trajanje);
	string getUrl()const;
	string getNaslov()const;
	string getTrajanje()const;

	void ispis() {
		cout << getKorisnik() << "\t" << getDatum() << "\t" << getVrijemeObjave() << "\t" << getRazinaPrivatnosti() << "\t" << getUrl() << "\t" << getNaslov() << "\t" << getTrajanje() << "\n";
	}
};

class Korisnik {
private:
	string Ime, Prezime, Mail;
	vector<Sadrzaj*> nizSadrzaja;
public:
	Korisnik(string _ime, string _prezime, string _mail) : Ime(_ime), Prezime(_prezime), Mail(_mail) {}

	void setIme(string _ime);
	void setPrezime(string _prezime);
	void setMail(string _mail);
	string getIme()const;
	string getPrezime()const;
	string getMail()const;

	void dodajSadrzaj(Sadrzaj* sadrzaj);
	void ispisSadrzaja();
	
	//omoguciti prikaz top N sadrzaja koje 
	//je korisnik objavio (za nekog 
	//korisnika), na nacin da je 
	//najsvjeziji sadrzaj na vrhu, iduci 
	//ispod, itd.
};

void Korisnik::setIme(string _ime) {
	Ime = _ime;
}
void Korisnik::setPrezime(string _prezime) {
	Prezime = _prezime;
}
void Korisnik::setMail(string _mail) {
	Mail = _mail;
}
string Korisnik::getIme()const {
	return Ime;
}
string Korisnik::getPrezime()const {
	return Prezime;
}
string Korisnik::getMail()const {
	return Mail;
}
void Sadrzaj::setDatum(string _datum) {
	datum = _datum;
}
void Sadrzaj::setVrijemeObjave(string _vrijemeObjave) {
	vrijemeObjave = _vrijemeObjave;
}
void Sadrzaj::setRazinaPrivatnosti(string _razinaPrivatnosti) {
	razinaPrivatnosti = _razinaPrivatnosti;
}
void Sadrzaj::setKorisnik(string _korisnik) {
	korisnik = _korisnik;
}
string Sadrzaj::getDatum()const {
	return datum;
}
string Sadrzaj::getVrijemeObjave()const {
	return vrijemeObjave;
}
string Sadrzaj::getRazinaPrivatnosti()const {
	return razinaPrivatnosti;
}
string Sadrzaj::getKorisnik()const {
	return korisnik;
}
void Video::setUrl(string _url){
	url = _url;
}
void Video::setNaslov(string _naslov){
	naslov = _naslov;
}
void Video::setTrajanje(string _trajanje){
	trajanje = _trajanje;
}
string Video::getUrl()const{
	return url;
}
string Video::getNaslov()const{
	return naslov;
}
string Video::getTrajanje()const{
	return trajanje;
}

void Korisnik::dodajSadrzaj(Sadrzaj* sadrzaj) {
	nizSadrzaja.push_back(sadrzaj);
}
void Korisnik::ispisSadrzaja() {
	for (int i = 0; i < nizSadrzaja.size(); i++) {
		nizSadrzaja[i]->ispis();
	}
}

int main() {
	Korisnik user1("Ante", "Anic", "a.anic@gmail.com");
	Sadrzaj objava1("20.7.2021.", "16:20", "javno", user1.getIme() + " " + user1.getPrezime());
	Video video1("19.7.2021.", "16:21", "privatno", user1.getIme() + " " + user1.getPrezime(), "https://www.tvz.hr/", "Nevjerojatan video", "3:45");
	Sadrzaj* ptrvideo1 = &video1;
	Sadrzaj* ptrobjava1 = &objava1;
	user1.dodajSadrzaj(ptrobjava1);
	user1.dodajSadrzaj(ptrvideo1);
	user1.ispisSadrzaja();
	
	return 0;
}