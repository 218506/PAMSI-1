#include <cstdlib>
#include <iostream>
#include <string>
#include <fstream>
#include <time.h>

using namespace std;

class Tablica {
private:
    int *tablica; //tablica

public:
    int dodajElementy(int n){  //funkcja zwiekszajaca ilosc elementow i wypelniajaca tablice
        tablica= new int [n];{
        for (int i=0;i<n;i++);
        tablica[n]=rand();
    }
 }
    void zwolnijPamiec(){ //zwolnienie pamieci
        delete [] tablica;
        }

};

clock_t start, stop; //zmienne potrzebne do licznei aczasu
double czas;

int main()
{
/*
n[5]={10^1,10^3,10^5,10^6,10^9};
*/
start=(clock()/CLOCKS_PER_SEC)*1000;  //czas poczatkowy
for (int i=0;i<ile;i++); //zwiekszanie tablicy o ilosc elementow podanych od uzytkownika
Tablica tablica;
int ile;
cout<<"Podaj ile elementow wczytac"<<endl;
cin>>ile;
tablica.dodajElementy(ile);
tablica.zwolnijPamiec();

stop=(clock()/CLOCKS_PER_SEC)*1000; //czas koncowy
czas= (double)(stop-start); //roznica koncowego czasu od czasu poczatkowego.
cout<<"Czas zapisu(przy zwiekszaniu o jeden) :"<<czas<<endl;
return 0;

}
