#include <iostream>
#include <string>
#include <fstream>
 
using namespace std;
 
class Student {
private:
    string imie;
    string nazwisko;
    int semestr;
    string numerIndeksu;
public:
    Student(string imie, string nazwisko, int semestr, string numerIndeksu) {
        this->imie = imie;
        this->nazwisko = nazwisko;
        this->semestr = semestr;
        this->numerIndeksu = numerIndeksu;
    }
 
    Student() {}
 
    /*friend ostream& operator << (ostream& out, Student & s) {
        out << "Dane studenta: " << endl;
        out << "Imie: " << s.imie << endl;
        out << "Nazwisko: " << s.nazwisko << endl;
        out << "Semestr: " << s.semestr << endl;
        out << "Numer indeksu: " << s.numerIndeksu << endl;
        return out;
    }*/
 
    friend ostream& operator << (ostream& out, Student &s) {
        out << " student: " << s.imie << " " << s.nazwisko << " " << s.semestr << " " << s.numerIndeksu << endl;
        return out;
    }
 
    friend istream& operator >> (istream& in, Student &s) {
        in >> s.imie >> s.nazwisko >> s.semestr >> s.numerIndeksu;
        return in;
    }
 
 
    string getImie() {
        return imie;
    }
    void setImie(string imie) {
        this->imie = imie;
    }
    string getNazwisko() {
        return imie;
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
 
};
 
class StudentInformatyki : public Student {
private:
    bool znaCpp;;
public:
    StudentInformatyki(string imie, string nazwisko, int semestr, string numerIndeksu,
        bool znaCpp) :
        Student(imie, nazwisko, semestr, numerIndeksu) {
        this->znaCpp = znaCpp;
    }
 
    StudentInformatyki() {}
 
    bool isZnaCpp() {
        return znaCpp;
    }
    void setZnaCpp(bool znaCpp) {
        this->znaCpp = znaCpp;
    }
    friend ostream& operator << (ostream& out, StudentInformatyki & s) {
        Student a = s;
        out << a;
        if (s.znaCpp) out << "Zna C++";
        else out << "Dopiero uczy sie C++";
        out << endl;
        return out;
    }
 
    friend istream& operator >> (istream& in, StudentInformatyki &s1) {
        Student s = s1;
        in >> s;
        in >> s1.znaCpp;
        return in;
    }
};
 
 
int main() {
    /*Student s1;
    cout << "Podaj imie, nazwisko, semestr i numer indeksu studenta: " << endl;
    cin >> s1;
    cout << s1;*/
 
    StudentInformatyki s2;
    int i = 0;
    ifstream plikIn;
    plikIn.open("StudInf.txt");
    if (!plikIn) {
        cerr << "Nie otworzono pliku! :(" << endl;
        system("PAUSE");
        return 0;
    }
    else {
        while (plikIn >> s2) {
            if (s2.isZnaCpp() == true) i++;
        }
    }
    cout << i << " studentow informatyki zna cpp. :)" << endl << endl;
    plikIn.close();
 
    Student s3;
    ofstream plik;
    plik.open("Studenci.txt");
    for (int i = 1; i <= 10; i++) {
        cout << "Podaj dane " << i << " studenta: " << endl;
        cin >> s3;
        plik << i << s3;
    }
    plik.close();
    system("PAUSE");
    return 0;
}
