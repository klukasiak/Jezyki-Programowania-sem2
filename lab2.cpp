#include <iostream>
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
    //metoda klasy Wykladnicza opisana wewnątrz klasy
    double scal()
    {
        return pow(podstawa, wykladnik);
    };
    //przeciążenie operatora * dla liczb "wykładniczych"
    //będące metodą klasy Wykladnicza
    Wykladnicza operator * (Wykladnicza x) {
        if (podstawa == x.podstawa)
            return Wykladnicza(podstawa, wykladnik + x.wykladnik);
        else if (wykladnik == x.wykladnik)
            return Wykladnicza(podstawa*x.podstawa, wykladnik);
        else {
            return Wykladnicza(scal()*x.scal(), 1);
        }
    };
    //metoda klasy Wykladnicza odwracająca podstawe i wykladnik
    void odwroc(void)
    {
        double temp = podstawa;
        podstawa = wykladnik;
        wykladnik = temp;
    }
};
 
//przeciążenie operatora wypisywania dla liczb "wykładniczych"
//będące funkcją
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
 
int main(int argc, char* argv[]) {
    Wykladnicza w1;
    Wykladnicza w2;
    Wykladnicza w3;
    /*char nazwaPliku[] = "liczby.txt";
    ifstream plik;
    plik.open(nazwaPliku);
    if (!plik)
        cerr << "Nie otworzona lub nie znaleziono pliku";
    else {
        plik >> w1 >> w2 >> w3;
    }
    plik.close();*/
 
 
/*  cout << "Wyswietlam trzy liczby \"wykladnicze\":" << endl << endl;
    cout << "a = " << w1;
    cout << "b = " << w2;
    cout << "c = " << w3;*/
    Wykladnicza iloczyn = w1 * w2;
    Wykladnicza iloczyn3 = iloczyn * w3;
    /*cout << endl << "Wynik mnozenia a*b:" << endl;
    cout << iloczyn << endl;
    cout << endl << "Wynik mnozenia a*b*c:" << endl;
    cout << iloczyn3 << endl;
    cout << endl << "Teraz w liczbie " << iloczyn << " zamienie podstawe z wykladnikiem" <<
        endl;
    iloczyn.odwroc();
    cout << iloczyn << endl;
    cout << endl << "Teraz oblicze wartosc powyzszej liczby" << endl;
    cout << iloczyn.scal() << endl << endl;*/
 
    /*char nazwaPlikuWyjsciowego[] = "nowe_liczby.txt";
    ofstream plik2;
    plik2.open(nazwaPlikuWyjsciowego);
    if (!plik2)
        cerr << "Nie otworzno lub nie znaleziono pliku" << endl;
    else {
        plik2 << iloczyn;
    }
    plik2.close();
   
    ofstream plik3;
    plik3.open(nazwaPlikuWyjsciowego, ios::app);
    if (!plik3)
        cerr << "Nie otworzno lub nie znaleziono pliku" << endl;
    else {
        plik3 << iloczyn;
    }
    plik3.close();*/
 
    char nazwaPlikuWyjsciowego[] = "moje_dane.txt";
    ofstream plik;
    plik.open(nazwaPlikuWyjsciowego);
    if (!plik) {
        cerr << "Nie otworzno lub nie znaleziono pliku" << endl;
        return 0;
    }
    for (int i = 1; i <= 20; i++) {
        cout << "Podaj " << i << " liczbe wykladnicza: " << endl;
        cin >> w1;
        plik << w1;
    }
    plik.close();
 
    char input[] = "dane.txt";
    char output[] = "podstawy_ujemne.txt";
    char output2[] = "podstawy_nieujemne.txt";
 
    ifstream dane;
    ofstream ujemne;
    ofstream nieujemne;
 
    dane.open(input);
    ujemne.open(output);
    nieujemne.open(output2);
 
    while (dane >> w1) {
        if (w1.podstawa < 0) {
            ujemne << w1;
        }
        else {
            nieujemne << w1;
        }
    }
   
    dane.close();
    ujemne.close();
    nieujemne.close();
    return 0;
}
