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
     int n =uni(rng);  //rzutowanie na string
     std::ostringstream ss;
     ss << n;
     string str = ss.str();
     Lista::Add(str,i); ///wypelnienie listy losowymi liczbami
   }
 
 for(int k=0; k<Size() ; k++)
   cout << Get(k)<< "  ";
 cout << endl;

 quicksort(0,rozmiar_docelowy-1);

  for(int k=0; k<Size() ; k++)
    cout << Get(k)<< "  ";
  cout << endl;
}

bool BiegaczLista::run()
{
///przeszukuje liste by znalezc slowo podane nizej.
  for (int i = 0; i < Lista::Size()+1; i++)
    return true;
    
  return false;
}
