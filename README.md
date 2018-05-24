# Jezyki-Programowania-sem2

## lab2.cpp

### Strumienie wejściowe/wyjściowe

**Zad1** *Wykonac zadania z instrukcji laboratoryjnej (na stronie domowej)*

**Zad2** *Utworzyć i uruchomić program, który wczytuje ciąg 20 par danych liczbowych i zapisuje ie do pliku moje_dane.txt w postaci 20 liczb wykładniczych.*

**Zad3** *Utworzyć przy użyciu dowolnego edytora plik tekstowy dane.txt zawierający 20 par danch liczbowych, a następnie utworzyć i uruchomic program, który utworzy 2 pliki: podstawy_ujemne.txt i podstawy_nieujemne.txt, na podstawie zawartości pliku dane.txt wypełni je odpowiednio liczbami wykładniczymi o podstawach ujemnych i liczbami wykładniczymi o podstawach nieujemnych.*

**Zad4** *Zmodyfikować program z zad3, tak aby mógł przetłumaczyć ciąg par danych o dowolnej(nieokreślonej) długości.
Wskazówka: zastosować funkcję o postaci: while(plik_dane>>w) { zapis do jednego lub drugiego pliku  (wg kryterium) }*

## lab3.cpp

### Przeciążanie operatorów i praca na plikach

**Zad1** *Wykonac zadania z instrukcji laboratoryjnej (na stronie domowej)*

**Zad2** *Do programu dopisać definicję funkcji  zaprzyjaźnionej przeciążającej operator >> i pozwalającej przy jego użyciu pobrać na zmienną dane studenta ze strumienia wejściowego. Wypróbować jego działanie w funkcji main() wczytując z klawiatury dane Student sn, a następnie wyświetlając je na ekranie.*

**Zad3** *Utworzyć plik tekstowy StuInf.txt i wpisać ręcznie do niego dane studentów informatyki. Napisać i uruchomić program, który na podstawie zawartości tego pliku wyświetli informację, ilu studentów już zna c++.*

**Uwaga:** *wartości logiczne zapisać w pliku jako liczby 0 i 1.*

**Zad4** *Przy użyciu przeciążeń operatorów << i >> wczytać z klawiatury dane 10 studentów i zapisać wierszami w pliku Studenci.txt, zaopatrując wiersze w numerację 1-10. Po wykonaniu programu obejrzeć zawartość utworzonego pliku.*

**Uwaga:** *zmodtfikować definicję przeciążeń operatora* 

## lab4.cpp

### Dziedziczenie wielokierunkowe

**Zad1** *Wykonac zadania z instrukcji laboratoryjnej (na stronie domowej).*

**Zad2** *Zaimplementować analogiczną do klasy GeniuszMatematyczny klasę "Przyjaciel zwierząt" o polach: bool maPsaLubKota; int liczbaZnanychGatunkow; double wydatkiNaPokarm.*

**Zad3** *Zaimplementować klasę StudentBiologii dziedziczącą po klasie Student oraz po klasie PrzyjacielZwierzą i posiadającą numer klasy 3. Odpowiednio uzupełnijć funkcję wpiszStudentow() w klasie Uczelnia i wywołać w funkcji main.*

**Zad4** *Zaprojektować i zaimplementować wszystkie potrzebne funkcji zaprzyjaźnione rpzeciążające operator >> i umożliwiające wczytywanie danych studentów ze strumienia wejściowego, a następnie przebudowaćfunkcję main() tak, aby powstała prosta aplikacja obsługująca  bazę danych studentów i udostępniająca w pętli następujące menu: 0-koniec działania programu 1-dopisz studenta 2- wypisz listę studentów
Przewidzieć komunikaty o błędach: -przekroczenia pojemności tablicy; -nie ma takiej opcji w menu.*

**Uwaga:** *Wybór opcji 1 powinien najpierw spowodować pobranie od użytkownika numery klasy (0,1,2,3)*

## lab5.cpp i lab5PD.cpp

### Wyjątki

**Zad1** *Wykonac zadania z instrukcji laboratoryjnej (na stronie domowej).*

**Zad2** *Zaimplementować obsługę wyjątku "próba obliczenia pierwiastka kwadratowego z liczby ujemnej". W funkcji main() wypróbować przechwytywanie powyższego wyjątku oraz wyjątku "próba dzielenia przez 0" przy obliczaniu wartości wyrażenia pierwiastek(x+y)i pierwiastek x – pierwiastek y. Wartości x i y są typu double i są podawane przez użytkownika.*

**Zad3** *W klasie Student dopisać drugą metodę wirtualną: virtual int dane dodatkowe()=0; której implementacja w klasie StudentInforamrtki zwraca wartość l lub 0 w zależności od tego, czy student zna C++, czy nie, zaś w klasie StudentPolonistyki zwraca liczbę przeczytanych książek przypadających na jesen semestr. Odpowiednio zmodyfikować definicje przeciążenia operatora <<  i wypróbować działanei w funkcji main().*

**PD** *Zdefiniować klasę abstrakcyjną Wyrażenie posiadającą dwa pola: int a, int b oraz metodę wirtualną double wartosc()=0. Utworzyć dwie klasy pochodne: Ulamek oraz Pierwiastek, implementujące wyrażenia odpowiednio jako a/b i pierwiastek z a. Zapewnić obsługę wszystkich wyjątków związanych z niemożliwością wykonania operacji arytmetycznej. Wypróboać działanie w funkcji main().*
