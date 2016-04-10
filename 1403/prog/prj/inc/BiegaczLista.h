#pragma once
#include "Lista.h"
#include "IRunnable.h"
#include <random>

/*!
*\brief Przygotowuje liste i definiuje przebieg jej uzupelniania.
*/

class BiegaczLista :public IRunnable,Lista {
 public:
/*!
* Klasa pomocnicza majaca na celu zdefiniowanie metod z tablicowego Biegacza, dla listy.
* Usuwa wczesniej modyfikowana liste.
* Funkcja prepare zwieksza rozmiar listy do rozmiaru docelowego, wypelnia ja losowymi slowami,
* oraz jednym slowem ktorego bedziemy szukac.
*/
  bool prepare(int rozmiar_docelowy);

/*!
*   Funkcja run wyszukuje slowo i zwraca prawde lub falsz w zaleznosci ,czy znalazlo czy nie.
*/
  bool run();
};
