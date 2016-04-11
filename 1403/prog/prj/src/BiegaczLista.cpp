#include "BiegaczLista.h"
#include <sstream>
#include <time.h>
#include <cstdlib>


bool BiegaczLista::prepare(int rozmiar_docelowy)
{
while(Lista::Size() !=0) ///sprztanie po poprzedniej liscie.
Lista::Remove(0);
 

 std::random_device rd;
 std::mt19937 rng(rd());
 std::uniform_int_distribution<int> uni(0,rozmiar_docelowy);

 //wypelnianie tablicy losowymi liczbami
 for(int i=0; i<rozmiar_docelowy;i++)
   {
     int n =i;//uni(rng);  //rzutowanie na string
     std::ostringstream ss;
     ss << n;
     string str = ss.str();
     Lista::Add(str,i); ///wypelnienie listy losowymi liczbami
   }
}

bool BiegaczLista::run()
{
  quicksort(0,Size()-1);
  //mergesort(0,Size()-1);
  return true;
  return false;
}
