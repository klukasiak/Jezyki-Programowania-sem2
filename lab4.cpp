#include <iostream>
#include <string>

using namespace std;


class Student {
protected:
	string imie;
	string nazwisko;
	int semestr;
	string numerIndeksu;
	int idKlasy;
public:
	Student(string imie, string nazwisko, int semestr, string numerIndeksu) {
		this->imie = imie;
		this->nazwisko = nazwisko;
		this->semestr = semestr;
		this->numerIndeksu = numerIndeksu;
		idKlasy = 0;
	}

	//Student() {}

	string getImie() {
		return imie;
	}
	void setImie(string imie) {
		this->imie = imie;
	}
	string getNazwisko() {
		return nazwisko;
	}
	void setNazwisko(string nazwisko) {
		this->nazwisko = nazwisko;
	}
	int getSemestr() {
		return semestr;
	}
	void setSemestr(int semestr) {
		this->semestr = semestr;
	}
	string getNumerIndeksu() {
		return numerIndeksu;
	}
	void setNumerIndeksu(string numerIndeksu) {
		this->numerIndeksu = numerIndeksu;
	}
	int getIdKlasy() {
		return idKlasy;
	}
};


ostream& operator << (ostream& out, Student & s) {
	out << "Dane studenta: " << endl;
	out << "Imie: " << s.getImie() << endl;
	out << "Nazwisko: " << s.getNazwisko() << endl;
	out << "Semestr: " << s.getSemestr() << endl;
	out << "Numer indeksu: " << s.getNumerIndeksu() << endl;
	return out;
}class GeniuszMatematyczny {
protected:
	int iq = 0;
	int liczbaWygranychOlimpiad = 0;
	int wynikMaturalnyZMatematyki = 0;
public:
	int getIq() {
		return iq;
	}
	void setIq(int iq) {
		this->iq = iq;
	}
	int getLiczbaWygranychOlimpiad() {
		return liczbaWygranychOlimpiad;
	}
	void setLiczbaWygranychOlimpiad(int liczbaWygranychOlimpiad) {
		this->liczbaWygranychOlimpiad = liczbaWygranychOlimpiad;
	}
	int getWynikMaturalnyZMatematyki() {
		return wynikMaturalnyZMatematyki;
	}
	void setWynikMaturalnyZMatematyki(int wynikMaturalnyZMatematyki) {
		this->wynikMaturalnyZMatematyki = wynikMaturalnyZMatematyki;
	}
	friend ostream& operator << (ostream& out, GeniuszMatematyczny & gm) {
		if (gm.iq) out << "IQ studenta wynosi: " << gm.iq << endl;
		if (gm.liczbaWygranychOlimpiad) out << "Wygral " << gm.liczbaWygranychOlimpiad
			<< " olimpiad matematycznych" << endl;
		if (gm.wynikMaturalnyZMatematyki) out << "Na maturze uzyskal wynik" <<
			gm.wynikMaturalnyZMatematyki << "%" << endl;
		return out;
	}
};class PrzyjacielZwierzat {protected:	bool maPsaLubKota;	int liczbaZnanychGatunkow;	double wydatkiNaPokarm;public:	bool isMaPsaLubKota() {		return maPsaLubKota;	}	void setMaPsaLubKota(bool maPsaLubKota) {		this->maPsaLubKota = maPsaLubKota;	}	int getLiczbaZnanychGatunkow() {		return liczbaZnanychGatunkow;	}	void setLiczbaZnanychGatunkow(int liczbaZnanychGatunkow) {		this->liczbaZnanychGatunkow = liczbaZnanychGatunkow;	}	double getWydatkiNaPokarm() {		return wydatkiNaPokarm;	}	void setWydatkiNaPokarm(double wydatkiNaPokarm) {		this->wydatkiNaPokarm = wydatkiNaPokarm;	}	friend ostream& operator << (ostream& out, PrzyjacielZwierzat &pz){
		if (pz.maPsaLubKota) out << "Ma kotka albo pieska :)" << endl;
		else out << "Nie ma ani kotka ani pieska :(" << endl;
		out << "Liczba znanych gatunkow: " << pz.liczbaZnanychGatunkow << endl;
		out << "Wydatki na pokarm: " << pz.wydatkiNaPokarm << endl;
		return out;
	}};class StudentBiologii : public Student, public PrzyjacielZwierzat {public:	StudentBiologii(string imie, string nazwisko, int semestr, string numerIndeksu, bool maPsaLubKota, int liczbaZnanychGatunkow, double wydatkiNaPokarm) :		Student(imie, nazwisko, semestr, numerIndeksu) {		this->maPsaLubKota = maPsaLubKota;		this->liczbaZnanychGatunkow = liczbaZnanychGatunkow;		this->wydatkiNaPokarm = wydatkiNaPokarm;		idKlasy = 3;	}	friend ostream& operator << (ostream& out, StudentBiologii & s) {		Student a = s;		PrzyjacielZwierzat pz = s;		out << a;		out << s;		return out;	}};class StudentInformatyki : public Student, public GeniuszMatematyczny {
private:
	bool znaCpp;;
public:
	StudentInformatyki(string imie, string nazwisko, int semestr, string numerIndeksu,
		bool znaCpp) :
		Student(imie, nazwisko, semestr, numerIndeksu) {
		this->znaCpp = znaCpp;
		modyfikujNumerIndeksu();
		idKlasy = 1;
	}

	//StudentInformatyki() {}

	bool isZnaCpp() {
		return znaCpp;
	}
	void setZnaCpp(bool znaCpp) {
		this->znaCpp = znaCpp;
	}
	friend ostream& operator << (ostream& out, StudentInformatyki & s) {
		Student a = s;
		GeniuszMatematyczny gm = s;
		out << a;
		if (s.znaCpp) out << "Zna C++";
		else out << "Dopiero uczy sie C++";
		out << endl;
		out << gm;
		return out;
	}	void modyfikujNumerIndeksu() {
		if (numerIndeksu[0] != 'I') numerIndeksu = 'I' + numerIndeksu;
	}
};class StudentPolonistyki : public Student {
private:
	int liczbaPrzeczytanychKsiazek;
public:
	StudentPolonistyki(string imie, string nazwisko, int semestr, string numerIndeksu,
		int liczbaPrzeczytanychKsiazek) :
		Student(imie, nazwisko, semestr, numerIndeksu) {
		this->liczbaPrzeczytanychKsiazek = liczbaPrzeczytanychKsiazek;
		modyfikujNumerIndeksu();
		idKlasy = 2;
	}
	//StudentPolonistyki() {}
	int getLiczbaPrzeczytanychKsiazek() {
		return liczbaPrzeczytanychKsiazek;
	}
	void setLiczbaPrzeczytanychKsiazek(int liczbaPrzeczytanychKsiazek) {
		this->liczbaPrzeczytanychKsiazek = liczbaPrzeczytanychKsiazek;
	}
	void modyfikujNumerIndeksu() {
		if (numerIndeksu[0] != 'M') numerIndeksu = 'M' + numerIndeksu;
	}
	friend ostream& operator << (ostream& out, StudentPolonistyki & s) {
		Student a = s;
		out << a;
		if (s.liczbaPrzeczytanychKsiazek > 100) out << "Przeczytal kilka ksiazek";
		else out << "Slaby czytelnik - chyba nie skonczy studiow";
		out << endl;
		return out;
	}
};
class Uczelnia {
protected:
	string nazwa;
	Student *listaStudentow[100];
	int liczbaStudentow;
public:
	Uczelnia(string nazwa) {
		this->nazwa = nazwa;
		this->liczbaStudentow = 0;
		cout << "Utworzono uczelnie " << nazwa << endl;
	}

	void dodajStudenta(Student *s) {
		listaStudentow[liczbaStudentow] = s;
		liczbaStudentow++;
	}

	void wypiszStudentow() {
		for (int i = 0; i < liczbaStudentow; i++) {
			switch (listaStudentow[i]->getIdKlasy()) {
			case 0:
				cout << *listaStudentow[i];
				break;
			case 1:
				cout << *static_cast<StudentInformatyki *>(listaStudentow[i]);
				break;
			case 2:
				cout << *static_cast<StudentPolonistyki *>(listaStudentow[i]);
				break;
			case 3:
				cout << *static_cast<StudentBiologii *>(listaStudentow[i]);
			default:
				cout << "Obiekt nieznanej klasy" << endl;
				break;
			}
		}
	}
};

int main() {
	Student s1("Jan", "Kowalski", 3 , "123456");
	StudentInformatyki si2("Tomasz", "Nowak" , 1 , "431235" ,1);
	StudentInformatyki si3("Tadeusz", "Kowalski", 4, "839207", 0);
	StudentPolonistyki sp4("Zenon", "Mederski", 2, "917432", 12);
	StudentPolonistyki sp5("Olek", "Szewczak", 4, "246987", 2);
	StudentBiologii sb6("Tomasz", "Legowski" , 2, "291340", 1, 12, 22.42);
	Student * s[] = { &s1, &si2, &si3, &sp4, &sp5 };
	Uczelnia UG("Uniwersytet Gdañski");
	/*
	for (int i = 0; i < 5; i++) {
		cout << *s[i];
	}	cout << endl << endl;	for (int i = 0; i < 5; i++) {
		switch (s[i]->getIdKlasy()) {
		case 0:
			cout << *s[i];
			break;
		case 1:
			cout << *static_cast<StudentInformatyki *>(s[i]);
			break;
		case 2:
			cout << *static_cast<StudentPolonistyki *>(s[i]);
			break;
		default:
			cout << "Obiekt nieznanej klasy" << endl;
			break;
		}
	}	for (int i = 0; i < 5; i++) {
		UG.dodajStudenta(s[i]);
	}	for (int i = 0; i < 5; i++) {
		cout<<UG.
	}*/	/*for (int i = 0; i < 5; i++) {
		UG.dodajStudenta(s[i]);
	}	UG.wypiszStudentow();*/	cout << sb6;	system("PAUSE");
}