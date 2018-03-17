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

	Student() {
		idKlasy = 0;
	}

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
	friend istream& operator >> (istream& in, Student & s);
};


ostream& operator << (ostream& out, Student & s) {
	out << "Dane studenta: " << endl;
	out << "Imie: " << s.getImie() << endl;
	out << "Nazwisko: " << s.getNazwisko() << endl;
	out << "Semestr: " << s.getSemestr() << endl;
	out << "Numer indeksu: " << s.getNumerIndeksu() << endl;
	return out;
}

istream& operator >> (istream& in, Student & s) {
	cout << "Podaj imie studenta: " << endl;
	in >> s.imie;
	cout << "Podaj nazwisko studenta: " << endl;
	in >> s.nazwisko;
	cout << "Podaj semestr studenta: " << endl;
	in >> s.semestr;
	cout << "Podaj numer indeksu studenta: " << endl;
	in >> s.numerIndeksu;
	return in;
}

class GeniuszMatematyczny {
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
	/*friend istream& operator >> (istream& in, GeniuszMatematyczny & gm) {
		cout << "Podaj IQ studenta: " << endl;
		in >> gm.iq;
		cout << "Podaj liczbe wygranych olimpiad przez studenta: " << endl;
		in >> gm.liczbaWygranychOlimpiad;
		cout << "Podaj wynik maturalny studenta z matematyki: " << endl;
		in >> gm.wynikMaturalnyZMatematyki;
		return in;
	}*/
};

class PrzyjacielZwierzat {
protected:
	bool maPsaLubKota;
	int liczbaZnanychGatunkow;
	double wydatkiNaPokarm;
public:
	bool isMaPsaLubKota() {
		return maPsaLubKota;
	}
	void setMaPsaLubKota(bool maPsaLubKota) {
		this->maPsaLubKota = maPsaLubKota;
	}
	int getLiczbaZnanychGatunkow() {
		return liczbaZnanychGatunkow;
	}
	void setLiczbaZnanychGatunkow(int liczbaZnanychGatunkow) {
		this->liczbaZnanychGatunkow = liczbaZnanychGatunkow;
	}
	double getWydatkiNaPokarm() {
		return wydatkiNaPokarm;
	}
	void setWydatkiNaPokarm(double wydatkiNaPokarm) {
		this->wydatkiNaPokarm = wydatkiNaPokarm;
	}
	friend ostream& operator << (ostream& out, PrzyjacielZwierzat & pz) {
		if (pz.maPsaLubKota) out << "Ma kotka albo pieska :)" << endl;
		else out << "Nie ma ani kotka ani pieska :(" << endl;
		out << "Liczba znanych gatunkow: " << pz.liczbaZnanychGatunkow << endl;
		out << "Wydatki na pokarm: " << pz.wydatkiNaPokarm << endl;
		return out;
	}
	/*friend istream& operator >> (istream& in, PrzyjacielZwierzat & pz) {
		cout << "Czy student ma kota lub psa (1,0): " << endl;
		in >> pz.maPsaLubKota;
		cout << "Podaj liczbe znanych gatunkow przez studenta: " << endl;
		in >> pz.liczbaZnanychGatunkow;
		cout << "Podaj wydatki studenta na pokarm: " << endl;
		in >> pz.wydatkiNaPokarm;
		return in;
	}*/
};

class StudentBiologii : public Student, public PrzyjacielZwierzat {
public:
	StudentBiologii(string imie, string nazwisko, int semestr, string numerIndeksu, bool maPsaLubKota, int liczbaZnanychGatunkow, double wydatkiNaPokarm) :
		Student(imie, nazwisko, semestr, numerIndeksu) {
		this->maPsaLubKota = maPsaLubKota;
		this->liczbaZnanychGatunkow = liczbaZnanychGatunkow;
		this->wydatkiNaPokarm = wydatkiNaPokarm;
		idKlasy = 3;
	}

	StudentBiologii() {
		idKlasy = 3;
		maPsaLubKota = false;
		liczbaZnanychGatunkow = 0;
		wydatkiNaPokarm = 0;
	}
	friend ostream& operator << (ostream& out, StudentBiologii & sb) {
		Student a = sb;
		PrzyjacielZwierzat pz = sb;
		out << a;
		out << pz;
		return out;
	}
	friend istream& operator >>(istream& in, StudentBiologii & sb) {
		Student a = sb;
		in >> a;
		return in;
	}
};

class StudentInformatyki : public Student, public GeniuszMatematyczny {
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

	StudentInformatyki() {
		idKlasy = 1;
		znaCpp = false;
	}

	bool isZnaCpp() {
		return znaCpp;
	}
	void setZnaCpp(bool znaCpp) {
		this->znaCpp = znaCpp;
	}
	friend ostream& operator << (ostream& out, StudentInformatyki & si) {
		Student a = si;
		GeniuszMatematyczny gm = si;
		out << a;
		if (si.znaCpp) out << "Zna C++";
		else out << "Dopiero uczy sie C++";
		out << endl;
		out << gm;
		return out;
	}
	friend istream& operator >>(istream& in, StudentInformatyki & si) {
		Student a = si;
		in >> a;
		cout << "Czy zna CPP? (1,0)" << endl;
		in >> si.znaCpp;
		return in;
	}

	void modyfikujNumerIndeksu() {
		if (numerIndeksu[0] != 'I') numerIndeksu = 'I' + numerIndeksu;
	}


};

class StudentPolonistyki : public Student {
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
	StudentPolonistyki() {
		idKlasy = 2;
		liczbaPrzeczytanychKsiazek = 0;
	}
	int getLiczbaPrzeczytanychKsiazek() {
		return liczbaPrzeczytanychKsiazek;
	}
	void setLiczbaPrzeczytanychKsiazek(int liczbaPrzeczytanychKsiazek) {
		this->liczbaPrzeczytanychKsiazek = liczbaPrzeczytanychKsiazek;
	}
	void modyfikujNumerIndeksu() {
		if (numerIndeksu[0] != 'M') numerIndeksu = 'M' + numerIndeksu;
	}
	friend ostream& operator << (ostream& out, StudentPolonistyki & sp) {
		Student a = sp;
		out << a;
		if (sp.liczbaPrzeczytanychKsiazek > 100) out << "Przeczytal kilka ksiazek";
		else out << "Slaby czytelnik - chyba nie skonczy studiow";
		out << endl;
		return out;
	}
	/*friend istream& operator >>(istream& in, StudentPolonistyki & sp) {
		Student a = sp;
		in >> a;
		cout << "Podaj liczbe ksiazek przeczytanych przez studenta: " << endl;
		in >> sp.liczbaPrzeczytanychKsiazek;
		return in;
	}*/
};

class Uczelnia {
private:
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
		if (liczbaStudentow < 100) {
			listaStudentow[liczbaStudentow] = s;
			liczbaStudentow++;
		}
		else cerr << "Przekroczono rozmiar tablicy" << endl;
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

void wypiszMenu() {
	cout << "0 - koniec dzialania programu" << endl;
	cout << "1 - dopisz studenta" << endl;
	cout << "2 - wypisz liste studentow" << endl;
	cout << "Podaj swoj wybor: " << endl;
}

void wyborStudenta() {
	cout << "Jakiego studenta chcesz dopisac?" << endl;
	cout << "1 - student informatyki" << endl;
	cout << "2 - student polonistyki" << endl;
	cout << "3 - student biologii" << endl;
	cout << "Podaj wybor: " << endl;
}

void dodawanieStudenta(int n, Uczelnia & UG) {
	StudentInformatyki si;
	StudentPolonistyki sp;
	StudentBiologii sb;
	Student * s[] = { &si, &sp, &sb };
	switch (n) {
	case 1:
		cin >> si;
		*s[0] = si;
		UG.dodajStudenta(s[0]);
		break;
	case 2:
		cin >> *static_cast<StudentPolonistyki *>(s[1]);
		UG.dodajStudenta(s[1]);
		break;
	case 3:
		cin >> *static_cast<StudentBiologii *>(s[2]);
		UG.dodajStudenta(s[2]);
		break;
	default:
		cout << "Zly wybor" << endl;
		break;
	}
}

int main() {
	/*Student s1("Jan", "Kowalski", 3, "123456");
	StudentInformatyki si2("Tomasz", "Nowak", 1, "431235", 1);
	StudentInformatyki si3("Tadeusz", "Kowalski", 4, "839207", 0);
	StudentPolonistyki sp4("Zenon", "Mederski", 2, "917432", 12);
	StudentPolonistyki sp5("Olek", "Szewczak", 4, "246987", 2);
	StudentBiologii sb6("Tomasz", "Legowski", 2, "291340", 1, 12, 22.42);
	Student * s[] = { &s1, &si2, &si3, &sp4, &sp5 };
	Uczelnia UG("Uniwersytet Gdanski");
	
	for (int i = 0; i < 5; i++) {
	cout << *s[i];
	}
	cout << endl << endl;

	for (int i = 0; i < 5; i++) {
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
	}

	for (int i = 0; i < 5; i++) {
		UG.dodajStudenta(s[i]);
	}
	UG.wypiszStudentow();*/
	Uczelnia UG("Uniwersytet Gdanski");
	StudentInformatyki si;
	StudentPolonistyki sp;
	StudentBiologii sb;
	Student * s[] = { &si, &sp, &sb };
	bool end = false;
	int n, z;
	while (!end) {
		wypiszMenu();
		cin.clear();
		cin >> n;
		switch (n)
		{
		case 0:
			cout << "Zakonczono dzialanie programu." << endl;
			end = true;
			break;
		case 1:
			wyborStudenta();
			cin >> z;
			if (z == 1) {
				cin >> *s[0];
				UG.dodajStudenta(s[0]);
			} else if (z == 2) {
				cin >> *s[1];
				UG.dodajStudenta(s[1]);
			} else if (z == 3) {
				cin >> *s[2];
				UG.dodajStudenta(s[2]);
			}
			else cout << "Zły wybor" << endl;
			break;
		case 2:
			UG.wypiszStudentow();
			break;
		default:
			cout << "Zły wybor" << endl;
			break;
		}
	}
	system("PAUSE");
	return 0;
}

