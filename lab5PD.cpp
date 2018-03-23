#include <iostream>
#include <string>

class ZerowyMianownik {
public:
	ZerowyMianownik() {}
	friend std::ostream& operator << (std::ostream& out, ZerowyMianownik &zm);
};

std::ostream& operator << (std::ostream& out, ZerowyMianownik &zm) {
	out << "WYJATEK: Proba dzielenia przez 0." << std::endl;
	return out;
}

class UjemnaPodstawaParzystegoStopnia {
public:
	UjemnaPodstawaParzystegoStopnia() {}
	friend std::ostream& operator << (std::ostream& out, UjemnaPodstawaParzystegoStopnia &upps);
};

std::ostream& operator << (std::ostream& out, UjemnaPodstawaParzystegoStopnia &upps) {
	out << "WYJATEK: Ujemna podstawa pierwiastka parzystego stopnia." << std::endl;
	return out;
}

class Wyrazenie {
private:
	int a;
	int b;
public:

	Wyrazenie() {}

	Wyrazenie(int a, int b) {
		this->a = a;
		this->b = b;
	}
	
	int getA(){
		return a;
	}

	void setA(int a) {
		this->a = a;
	}

	int getB() {
		return b;
	}

	void setB(int b) {
		this->b = b;
	}

	virtual double wartosc() = 0;
};

class Ulamek : public Wyrazenie {
public:
	Ulamek(int a, int b) : Wyrazenie(a, b) {
		if (b == 0) throw ZerowyMianownik();
	};
	
	friend std::ostream& operator << (std::ostream& out, Ulamek &u) {
		out << u.getA() << "/" << u.getB();
		return out;
	}

	double wartosc() {
		return ((double)getA() / (double)getB());
	}
};

class Pierwiastek : public Wyrazenie {
public:
	Pierwiastek(int a, int b) : Wyrazenie(a,b) {
		if (b % 2 == 0) {
			if (a < 0) throw UjemnaPodstawaParzystegoStopnia();
		}
	};

	friend std::ostream& operator << (std::ostream& out, Pierwiastek &p) {
		out << "Pierwiastek " << p.getB() << " stopnia z " << p.getA();
		return out;
	}
	
	double wartosc() {
		return pow( (double)getA(), ( 1/(double)getB() ) );
	}
};

int main() {
	try {
		Ulamek u1(1, 2);
		std::cout << u1 << std::endl;
		std::cout << u1.wartosc() << std::endl;
		Pierwiastek p1(4, 2);
		std::cout << p1 << std::endl;
		std::cout << p1.wartosc() << std::endl;
		//Ulamek u2(2, 0);
		Pierwiastek p2(-2, 2);
	}
	catch (UjemnaPodstawaParzystegoStopnia upps) {
		std::cout << upps;
	}
	catch (ZerowyMianownik zm) {
		std::cout << zm;
	}

	system("PAUSE");
	return 0;
}
