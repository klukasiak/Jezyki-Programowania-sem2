#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>
#include <fstream>
//deklaracja użycia przestrzeni nazw std
using namespace std;
class Wykladnicza {
public:
	double podstawa;
	double wykladnik;
	Wykladnicza(double P, double W) { //konstruktor
		podstawa = P;
		wykladnik = W;
	};
	Wykladnicza() {};
	~Wykladnicza() { //dekonstruktor
					 /*cout << endl;
					 cout << "Niszcze obiekt klasy 'Wykladnicza'" << endl;
					 cout << "Mial on pola:" << endl;
					 cout << " Podstawa:" << podstawa << endl;
					 cout << " Wykladnik:" << wykladnik << endl << endl; */
	};
	//metoda klasy Wykladnicza opisana wewnštrz klasy
	double scal()
	{
		return pow(podstawa, wykladnik);
	};
	//przecišżenie operatora * dla liczb "wykładniczych"
	//będšce metodš klasy Wykladnicza
	/*Wykladnicza operator * (Wykladnicza x) {
		if (podstawa == x.podstawa)
			return Wykladnicza(podstawa, wykladnik + x.wykladnik);
		else if (wykladnik == x.wykladnik)
			return Wykladnicza(podstawa*x.podstawa, wykladnik);
		else {
			return Wykladnicza(scal()*x.scal(), 1);
		}
	};*/
	//przecišżenie operatora / dla liczb "wykładniczych"
	//będšce metodš klasy Wykladnicza
	Wykladnicza operator / (Wykladnicza x) {
		if (podstawa == x.podstawa)
			return Wykladnicza(podstawa, wykladnik - x.wykladnik);
		else if (wykladnik == x.wykladnik)
			return Wykladnicza(podstawa / x.podstawa, wykladnik);
		else {
			return Wykladnicza(scal() / x.scal(), 1);
		}
	};
	//metoda klasy Wykladnicza odwracajšca podstawe i wykladnik
	void odwroc(void)
	{
		double temp = podstawa;
		podstawa = wykladnik;
		wykladnik = temp;
	}
	//metoda klasy wykladnicza tworzaca minimalna podstawe
	void minim() {
		for (int i = 1; i <= podstawa; i++) {
			for (int j = 1; j <= podstawa; j++) {
				if (pow(i, j) == podstawa) {
					podstawa = i;
					wykladnik *= j;
				}
				if (pow(i, j) > podstawa) break;
			}
		}
	}
};
//przecišżenie operatora wypisywania dla liczb "wykładniczych"
//będšce funkcjš
ostream& operator << (ostream& out, Wykladnicza &liczba) {
	if (liczba.wykladnik == 0) {
		if (liczba.podstawa != 0) out << 1 << " ";
		else out << "Symbol nieoznaczony";
	}
	else if (liczba.wykladnik == 1)
		out << liczba.podstawa << " ";
	else if (liczba.wykladnik > 0)
		out << liczba.podstawa << "^" << liczba.wykladnik << " ";
	else
		out << liczba.podstawa << "^(" << liczba.wykladnik << ") ";
	out << endl;
	return out;
}

istream& operator >> (istream& in, Wykladnicza &liczba) {
	in >> liczba.podstawa;
	in >> liczba.wykladnik;
	return in;
}

Wykladnicza operator * (Wykladnicza y, Wykladnicza x) {
	if (y.podstawa == x.podstawa)
		return Wykladnicza(y.podstawa, y.wykladnik + x.wykladnik);
	else if (y.wykladnik == x.wykladnik)
		return Wykladnicza(y.podstawa * x.podstawa, y.wykladnik);
	else {
		return Wykladnicza(y.scal()*x.scal(), 1);
	}
}

int main(int argc, char* argv[]) {
	Wykladnicza w1(2, 4);
	Wykladnicza w2(3, 4);
	Wykladnicza w3(5, 2);
	cout << "Wyswietlam trzy liczby \"wykladnicze\":" << endl << endl;
	cout << "a = " << w1;
	cout << "b = " << w2;
	cout << "c = " << w3;
	Wykladnicza iloczyn = w1 * w2;
	Wykladnicza iloczyn3 = iloczyn * w3;
	cout << endl << "Wynik mnozenia a*b:" << endl;
	cout << iloczyn << endl;
	cout << endl << "Wynik mnozenia a*b*c:" << endl;
	cout << iloczyn3 << endl;
	cout << endl << "Teraz w liczbie " << iloczyn << " zamienie podstawe z wykladnikiem" <<
		endl;
	iloczyn.odwroc();
	cout << iloczyn << endl;
	cout << endl << "Teraz oblicze wartosc powyzszej liczby" << endl;
	cout << iloczyn.scal() << endl << endl;
	Wykladnicza sprawdz(27, 3);
	cout << "Sprawdzenie funkcji minim dla 27^3" << endl;
	sprawdz.minim();
	cout << sprawdz<<endl<<endl;
	cout << "a/b" << endl << w1 / w2 << endl;

	cout << "Podaj jakas liczbe wykladnicza: " << endl;
	Wykladnicza wykladnicza;
	cin >> wykladnicza;
	cout << endl << wykladnicza;
	system("PAUSE");//cin.get();
	return 0;

	/*Wykladnicza w1, w2, w3;
	string nazwaPlikuIn = "TextFile1.txt";
	ifstream plik;
	plik.open(nazwaPlikuIn);
	if
		(!plik) cerr << "Blad";
	else
		plik >> w1 >> w2 >> w3;
	plik.close();

	string nazwaPlikuOut = "Liczby.txt";
	ofstream plik2;
	plik2.open(nazwaPlikuOut);
	plik2 << w1 << endl << w2 << endl << w3 << endl;
	plik2.close();

	ofstream plik3;
	plik3.open(nazwaPlikuOut, ios::app);
	if (!plik3)
		cerr << "Blad";
	else
		plik3 << w1 * w2;
		//plik3 << static_cast<Wykladnicza>(w1 * w2);
	plik3.close();
	system("PAUSE");*/
	/* bool p = true;
	double a = 0.5555555;
	double b = 10.333333;
	int c = 15;

	cout << boolalpha << p << endl;
	cout << hex << c << endl;
	cout << uppercase << hex << c << endl;
	cout << setprecision(3) << a << endl;

	string ala = "Ala ma kota";
	cout << ala << endl;

	cout.write(ala.c_str(), ala.length());

	string czytamy;
	cout << endl << "Jak sie nazywasz? " << endl;
	//cin >> czytamy;
	getline(cin, czytamy);
	cout << "Czesc " << czytamy << endl;
	
	system("PAUSE");*/
}
