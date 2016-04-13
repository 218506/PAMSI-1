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
 
   /*
 tablica_dyn[0]="1";
 tablica_dyn[1]="5";
 tablica_dyn[2]="8";
 //tablica_dyn[3]="11";
 //tablica_dyn[4]="15";
 tablica_dyn[3]="4";
 tablica_dyn[4]="6";
 tablica_dyn[5]="8";
 tablica_dyn[6]="13";
 //tablica_dyn[9]="20";
 
 */
  cerr << "przed "<< endl; 
 for(int i=0;i<rozmiar_docelowy;i++) 
   cerr << tablica_dyn[i] << endl;


 mergesort(0,rozmiar_docelowy-1);


 cerr << "po "<< endl; 
  for(int i=0;i<rozmiar_docelowy;i++)
   cerr << tablica_dyn[i] << endl;

}


bool BiegaczLista::run()
{

  return true;
  
  //quicksort(0,Size()-1);

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
  cerr <<"p=  " <<p<< endl;
  cerr <<"i=  " <<i<< endl;
  cerr <<"j=  " <<j<< endl;
  cerr <<"k=  " <<k<< endl; 
  for(int n=l;n<=p;n++) //Kopiuje do nowej tablicy.
    {
      tab[n]=tablica_dyn[n];
      //cerr<<tab[n];
    } 
  while(i <= s && j <= p)
    {
      if(atoi(tab[i].c_str()) < atoi(tab[j].c_str())) 
	{
	  cerr << tab[i] <<" < " << tab[j] << endl;
	  cerr << "wpisuje: " << tab[i] << endl;
	  tablica_dyn[k]=tab[i];
	  i++;
	}
      else
	{
	  cerr << tab[i] <<" > " << tab[j] << endl;
	  cerr << "wpisuje: " << tab[j] << endl;
	  tablica_dyn[k]=tab[j];
	  j++;
	}
      k++;
    }

  cerr << "i=  " << i << endl;
  cerr << "j=  " << j << endl;

  if(j == p+1) //jezeli j wyszlo poza tablice a i jeszcze w swojej polowie
    {
      for(i;i<=s;i++)
	{
	  cerr << tab[i];
	  this->tablica_dyn[k]=tab[i];
	  k++;
	}
      //delete tab;
      return;
    } 

  if(i == s+1) //jezeli s wyszlo poza swoja polowe
    {
      for(j;j<p;j++)
	{
	  cerr << tab[i];
	  this->tablica_dyn[k]=tab[j];
	  k++;
	}
      // delete tab;
      return;
    }
}

void BiegaczLista::mergesort(int l, int p)
{
  int sr;
  sr=(l+p)/2;
  
  if(l<p)
     {    
      cerr << "sr= "<< sr << endl;
      mergesort(l,sr);
      mergesort(sr+1,p);
      merge(l,sr,p);
    }
}

//*************END****************//
