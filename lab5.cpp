#include <iostream>
#include <string>
#include <fstream>

namespace Studenci{
	class Student {
	protected:
		std::string imie;
		std::string nazwisko;
		int semestr;
		std::string numerIndeksu;
		int idKlasy;
	public:
		Student(std::string imie, std::string nazwisko, int semestr, std::string numerIndeksu) {
			this->imie = imie;
			this->nazwisko = nazwisko;
			this->semestr = semestr;
			this->numerIndeksu = numerIndeksu;
			idKlasy = 0;
		}

		Student() {
			idKlasy = 0;
		}
		std::string getImie() {
			return imie;
		}
		void setImie(std::string imie) {
			this->imie = imie;
		}
		std::string getNazwisko() {
			return nazwisko;
		}
		void setNazwisko(std::string nazwisko) {
			this->nazwisko = nazwisko;
		}
		int getSemestr() {
			return semestr;
		}
		void setSemestr(int semestr) {
			this->semestr = semestr;
		}
		std::string getNumerIndeksu() {
			return numerIndeksu;
		}
		void setNumerIndeksu(std::string numerIndeksu) {
			this->numerIndeksu = numerIndeksu;
		}
		int getIdKlasy() {
			return idKlasy;
		}
		virtual std::string info() {
			return "Student nie jest przypisany do zadnego kierunku";
		}

		virtual int daneDodatkowe() = 0;
	};

	std::ostream& operator << (std::ostream& out, Student & s) {
		out << "Dane studenta: " << std::endl;
		out << "Imie: " << s.getImie() << std::endl;
		out << "Nazwisko: " << s.getNazwisko() << std::endl;
		out << "Semestr: " << s.getSemestr() << std::endl;
		out << "Numer indeksu: " << s.getNumerIndeksu() << std::endl;
		out << s.info() << std::endl;
		return out;
	}

	class StudentBiologii : public Student{
	public:
		StudentBiologii(std::string imie, std::string nazwisko, int semestr, std::string numerIndeksu, bool maPsaLubKota, int liczbaZnanychGatunkow, double wydatkiNaPokarm) :
			Student(imie, nazwisko, semestr, numerIndeksu) {
			idKlasy = 3;
		}

		StudentBiologii() {
			idKlasy = 3;
		}
		friend std::ostream& operator << (std::ostream& out, StudentBiologii & sb) {
			out << "Dane studenta: " << std::endl;
			out << "Imie: " << sb.getImie() << std::endl;
			out << "Nazwisko: " << sb.getNazwisko() << std::endl;
			out << "Semestr: " << sb.getSemestr() << std::endl;
			out << "Numer indeksu: " << sb.getNumerIndeksu() << std::endl;
			out << sb.info() << std::endl;
			return out;
		}
	};

	class StudentInformatyki : public Student{
	private:
		bool znaCpp;;
	public:
		StudentInformatyki(std::string imie, std::string nazwisko, int semestr, std::string numerIndeksu,
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
		friend std::ostream& operator << (std::ostream& out, StudentInformatyki & si) {
			out << "Dane studenta: " << std::endl;
			out << "Imie: " << si.getImie() << std::endl;
			out << "Nazwisko: " << si.getNazwisko() << std::endl;
			out << "Semestr: " << si.getSemestr() << std::endl;
			out << "Numer indeksu: " << si.getNumerIndeksu() << std::endl;
			out << si.info() << std::endl;
			out << "Czy zna Cpp? " << si.daneDodatkowe();
			out << std::endl;
			return out;
		}

		void modyfikujNumerIndeksu() {
			if (numerIndeksu[0] != 'I') numerIndeksu = 'I' + numerIndeksu;
		}
		std::string info() {
			return "Student kierunku Informatyka";
		}

		int daneDodatkowe() {
			return znaCpp;
		}
	};

	class StudentPolonistyki : public Student {
	private:
		int liczbaPrzeczytanychKsiazek;
	public:
		StudentPolonistyki(std::string imie, std::string nazwisko, int semestr, std::string numerIndeksu,
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
		friend std::ostream& operator << (std::ostream& out, StudentPolonistyki & sp) {
			out << "Dane studenta: " << std::endl;
			out << "Imie: " << sp.getImie() << std::endl;
			out << "Nazwisko: " << sp.getNazwisko() << std::endl;
			out << "Semestr: " << sp.getSemestr() << std::endl;
			out << "Numer indeksu: " << sp.getNumerIndeksu() << std::endl;
			out << sp.info() << std::endl;
			if (sp.liczbaPrzeczytanychKsiazek > 100) out << "Przeczytal kilka ksiazek";
			else out << "Slaby czytelnik - chyba nie skonczy studiow";
			out << std::endl;
			out << "Liczba przeczytanych ksiazek: " << sp.daneDodatkowe() << std::endl;
			return out;
		}

		std::string info() {
			return "Student kierunku Polonistyka";
		}

		int daneDodatkowe() {
			return liczbaPrzeczytanychKsiazek;
		}
	};
}

class ZlyUlamek {
public:
	ZlyUlamek() {}
	friend std::ostream& operator << (std::ostream& out, ZlyUlamek &zu);
};

class DzieleniePrzezZero {
public:
	DzieleniePrzezZero() {}
	friend std::ostream& operator << (std::ostream& out, DzieleniePrzezZero &dpz);
};

class PierwiastekUjemny {
public:
	PierwiastekUjemny() {}
	friend std::ostream& operator << (std::ostream& out, PierwiastekUjemny &pu);
};

std::ostream& operator << (std::ostream& out, ZlyUlamek &zu) {
	out << "WYJATEK: zly ulamek - w mianowniku nie moze byc zera" << std::endl;
	return out;
}
std::ostream& operator << (std::ostream& out, DzieleniePrzezZero &dpz) {
	out << "WYJATEK: proba dzielenia przez 0" << std::endl;
	return out;
}

std::ostream& operator << (std::ostream& out, PierwiastekUjemny &pu) {
	out << "WYJATEK: proba obliczenia pierwiastka kwadratowego z liczby ujemnej";
	return out;
}

class Ulamek {
private:
	double licznik;
	double mianownik;
public:
	Ulamek(double licznik, double mianownik) {
		this->licznik = licznik;
		if (mianownik == 0) throw ZlyUlamek();
		this->mianownik = mianownik;
	}

	double getLicznik() {
		return licznik;
	}

	void setLicznik(double licznik) {
		this->licznik = licznik;
	}

	double getMianownik() {
		return mianownik;
	}

	void setMianownik(double mianownik) {
		this->mianownik = mianownik;
	}

	friend std::ostream& operator << (std::ostream& out, Ulamek &u) {
		out << u.licznik << "/" << u.mianownik;
		return out;
	}

	Ulamek operator / (Ulamek a) {
		if (a.licznik == 0) throw DzieleniePrzezZero();
		Ulamek wynik(licznik*a.mianownik, mianownik*a.licznik);
		return wynik;
	}


};

void obliczanie(double x, double y) {
	if (x < 0 || y < 0) throw PierwiastekUjemny();
	std::cout << (sqrt(x) + sqrt(y)) / sqrt(x + y) << std::endl;
}

int main() {
	/*try {
		Ulamek u1(3, 5);
		std::cout << u1 << std::endl;
		Ulamek u2(0, 6);
		std::cout << u2 << std::endl;
		Ulamek dzielenie = u1 / u2;
		std::cout << dzielenie;
	}
	catch (ZlyUlamek zu) {
		std::cout << zu;
	}
	catch (DzieleniePrzezZero dpz) {
		std::cout << dpz;
	}

	Studenci::Student s("Jan", "Kowalski", 3, "123123");
	Studenci::StudentInformatyki si("Jan", "Iks", 2, "12344", true);
	Studenci::StudentPolonistyki sp("Adam", "Adamski", 4, "12321", 99);
	Studenci::Student *studenci[] = { &s, &si, &sp };
	std::cout << *studenci[0];
	std::cout << *studenci[1];
	std::cout << *studenci[2];
	*/

	double x, y;
	std::cin >> x >> y;
	try {
		obliczanie(x, y);
	}
	catch (PierwiastekUjemny pu){
		std::cout << pu << std::endl;
	}
	Studenci::StudentInformatyki si("Tasd", "fdgd", 4, "134531", 1);
	Studenci::StudentPolonistyki sp("Ksdf", "Psdg", 3, "654243", 34);

	std::cout << si << sp;

	system("PAUSE");
	return 0;
}