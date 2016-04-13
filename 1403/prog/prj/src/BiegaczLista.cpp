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

 tablica_dyn=new string[rozmiar_docelowy];
 
 //wypelnianie tablicy losowymi liczbami
 for(int i=0; i<rozmiar_docelowy;i++)
   {
     int n =uni(rng);  //rzutowanie na string
     std::ostringstream ss;
     ss << n;
     string str = ss.str();
     tablica_dyn[i]=str;
   }
 size_tab=rozmiar_docelowy;
}


bool BiegaczLista::run()
{
  mergesort(0,size_tab-1); 
  //quicksort(0,Size()-1);
  return true;
}


/************MERGESORT NA TABLICY*************/
void BiegaczLista::merge(int l,int s, int p)
{
  if(l==p) 
    return;

  string* tab=new string[p+1];
  
  int i=l;
  int j=s+1;
  int k=l; //licznik listy tmp
 
  for(int n=l;n<=p;n++) //Kopiuje do nowej tablicy.
    {
      tab[n]=tablica_dyn[n];
    } 

  while(i <= s && j <= p)
    {
      if(atoi(tab[i].c_str()) < atoi(tab[j].c_str())) 
	{
	  tablica_dyn[k]=tab[i];
	  i++;
	}
      else
	{
	  tablica_dyn[k]=tab[j];
	  j++;
	}
      k++;
    }

  if(j == p+1) //jezeli j wyszlo poza tablice a i jeszcze w swojej polowie
    {
      for(i;i<=s;i++)
	{
	  this->tablica_dyn[k]=tab[i];
	  k++;
	}
      return;
    } 
  
  if(i == s+1) //jezeli s wyszlo poza swoja polowe
    {
      for(j;j<p;j++)
	{
	  this->tablica_dyn[k]=tab[j];
	  k++;
	}
      return;
    }
  delete tab; //zwolnienie pamieci
}

void BiegaczLista::mergesort(int l, int p)
{
  int sr;
  sr=(l+p)/2;
  
  if(l<p)
     {    
      mergesort(l,sr);
      mergesort(sr+1,p);
      merge(l,sr,p);
    }
}

//*************END****************//
