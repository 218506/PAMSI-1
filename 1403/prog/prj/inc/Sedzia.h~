#pragma once

#include "IRunnable.h"
#include "IStoper.h"

#include <fstream>
#include <string>
#include <iostream>

const std::string NAZWA_PLIKU_Z_ILOSCIA_ELEMENTOW = "dystans.txt";

/*!
*\brief Jest to klasa nadrzedna , ktora struje klasami Stoper i Biegacz poprzez odwolanie sie do interfejsow.
*/

class Sedzia
{
  IRunnable & _biegacz;
  IStoper & _stoper;
public:
Sedzia(IRunnable & biegacz, IStoper & stoper) :_biegacz(biegacz), _stoper(stoper) {}

 /*!
*Przez funkcje release wywolujemy kolejno funkcje biegacz prepare->Start->run->Stop->getElapsedTime->dumpToFile
*ktore sa zdefiniowane w klasach Stoper i Biegacz. Mamy taka mozliwosc poprzez interfejsy.
*/
  void release();
};
