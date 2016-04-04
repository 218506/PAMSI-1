#include "BiegaczLista.h"
#include <sstream>
#include <time.h>

void quicksort(int lewy, int prawy, int rozmiar_docelowy)
{
  std::random_device rd;
  std::mt19937 rng(rd());
  std::uniform_int_distribution<int> uni(0,rozmiar_docelowy);

  int v=Lista::Get(uni(rng));
  int i,j,x;
  i=lewy;
  j=prawy;
    
  /*
  while(tablica[i]<v) 
    i++;
  while(tablica[j]>v) 
    j--;
  if
    (i<=j){
    x=tablica[i];
    tablica[i]=tablica[j];
    tablica[j]=x;
    i++; j--;
  }
  while (i<=j);
  if (j>lewy) 
    quicksort(tablica,lewy, j);
  if (i<prawy) 
    quicksort(tablica, i, prawy);
  */
}


bool BiegaczLista::prepare(int rozmiar_docelowy)
{
while(Lista::Size() !=0) ///sprztanie po poprzedniej liscie.
Lista::Remove(0);
 

 std::random_device rd;
 std::mt19937 rng(rd());
 std::uniform_int_distribution<int> uni(0,rozmiar_docelowy);

 for(int i=0; i<(rozmiar_docelowy-1);i++)
   {
     int n = uni(rng);  //rzutowanie na string
     std::ostringstream ss;
     ss << n;
     string str = ss.str();
     Lista::Add(str,i); ///wypelnienie listy losowymi liczbami
   }
 
}

bool BiegaczLista::run()
{
///przeszukuje liste by znalezc slowo podane nizej.
  for (int i = 0; i < Lista::Size()+1; i++)


    return true;
    
  return false;
}
