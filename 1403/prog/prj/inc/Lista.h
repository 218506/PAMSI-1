#pragma once
#include <string>
#include <iostream>

#include "ILista.h"

using namespace std;
struct Node ///pojedynczy element
{
Node* wskaznik;
std::string wartosc;

};
/*!
*\brief Deklaruje funkcje listy.
*/
class Lista : public ILista
{
public:


  //*********QUICKSORT***************//

  // zamienia miejscami liste z indeksami i oraz j
  void swap(int i,int j);

  // dzieli na partycje na zakresie <l,p>
  int partition(int l, int p); 

  //quicksortuje jako l-0, p-rozmiar-1
  void quicksort(int l, int p); 


  //*************END****************//





/*!
*Funkcja Add dodaje kolejny element listy.
*Jesli rozmiar listy jest za maly w stosunku do podawanego indexu to wyswietla komunikat.
*Funkcja dziala w taki sposob, ze tworzy nowy "Node" do tablicy, wskaznik z wczesniejszego elementu wskazuje na nowy Node
*nastepnie z Node wskazujemy na kolejny element tablicy, aby byla ciaglosc w liscie.
*W tej funkcji rozpatrujemy 3 przypadki zwieksznaia listy, dostawianie elementu na pocz,koniec lub gdzies pomiedzy w liscie.
*Jesli dostawiamy na poczatek tworzymy nowy element i wskazujemy na niego wskaznikiem poczatkowym i koncowym.
*Jesli tworzymy ostatni element, to dodajemy nowego Noda, i wskazujemy na niego wskaznikiemKONcowym.
*Osttanim przypadkiem jest elementu gdzies pomiedzy POCZ i KON listy.
*Tutaj musimy pamietac ze lista liczy swojem miejsca od 0, wiec w petli for mamy index-1.
*Tworzymy tymczasowy wskaznik i ustawiamy go na pierwszy element.
*nastepnie w petli przesówamy o tyle elementów ile zadamy-1. Przesuwamy ten wskaznik na kolejny element, tworzymy pomocniczy wskaznik
*ktory ma wskazywac na nowo utworzony element. W nowo utworzonym elemencie dodajemy wskaznik ktory wskazuje na nastepny element
*ktory byl stworzony przed naszym nowym Nodem.Wszystko po to by zachowac ciaglosc listy i wskazywanie na kolejne elementy.
*/
    void Add(std::string item, int index) ; //dodawanie elemntow


/*!
*Remove dziala w podobny sposob. Jesli zadamy usuniecie 1 elementu, to zapamietujemy cos na co wskazuje 1 element. Usuwamy to,
*by nastepnie ustawic wskaznik poczatkowy na cos, na co wskazywal pierwszy element.
*Jesli usuwamy ostatni element to tworzymy wskaznik tymczasowy na pierwszy element, przesuwamy do ostatniego, gdzie index zmniejszamy -2,
*poniewaz indexujemy liste od zera, oraz interesuje nas wczesniejszy element ktory wskazuje na ostatni. Gdy osiegniey przedostatni element wskazujemy
*jego wskaznikiem na null pointer oraz usuwamy wczesniejszy osttni element z listy na ktorego nic nie wskazuje.
*W ostatnim przypadku tworzymy tymczasowy nastepnik , ktory jest wskaznikiem na wskaznik. Przesukujemy liste od poczatku, usuwamy element
*i nasz wskaznik dalej wskazuje na kolejny element dzieki nastepnikowi. Zachowana jest ciaglosc wskazywania na siebie elementow z listy.
*/
    void Remove(int index);  //usuwanie elementow

/*!
*Zwraca true jesli lista jest pusta lub false jesli nie jest.
*/
    bool IsEmpty(); //sprawdzanie czy pusta

/*!
*W tej funkcji tworzymy wskaznik tymczasowy na 1 element listy, przesuwamy o index-1 , po znalezieniu interesujacego nas elementu zwracamy jego wartosc.
*/
    std::string Get(int index) ; //pobiera elemento z listy
/*!
*Size zwraca nam zmienna rozmiar.
*/
    int Size(); //wyswietla rozmiar listy
    Lista() : wskaznikPOCZ(nullptr) , wskaznikKON(nullptr) , rozmiar(0){}
private:
    int rozmiar;
    Node* wskaznikPOCZ;//wsk.na pierwzy element listy
    Node* wskaznikKON; //wskaznik na ostati el listy





};

