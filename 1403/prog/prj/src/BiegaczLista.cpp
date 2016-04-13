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

 tablica_dyn=new string[4];//rozmiar_docelowy];
 /*
 //wypelnianie tablicy losowymi liczbami
 for(int i=0; i<rozmiar_docelowy;i++)
   {
     int n =i;//uni(rng);  //rzutowanie na string
     std::ostringstream ss;
     ss << n;
     string str = ss.str();
     tablica_dyn[i]=str;
   }
 */
 tablica_dyn[0]="3";
 tablica_dyn[1]="1";
 tablica_dyn[2]="2";
 //tablica_dyn[3]="4";
}
bool BiegaczLista::run()
{
  //quicksort(0,Size()-1);

  cerr << "przed "<< endl; 
 for(int i=0;i<2;i++) //rozmiar docelowy!!!
   cerr << tablica_dyn[i] << endl;


 mergesort(0,4);//Size()-1);


 cerr << "po "<< endl; 
  for(int i=0;i<3;i++) //rozmiar docelowy!!!
   cerr << tablica_dyn[i] << endl;
  return true;

}

/************MERGESORT NA TABLICY*************/
void BiegaczLista::merge(int l,int s, int p)
{
  string *tab=new string[p-l];
  int i=l;
  int j=s;
  int k=l; //licznik listy tmp

  for(int n=l;n<p;n++)
    {
      tab[n]=tablica_dyn[n];
      cerr<<tab[n];
    }
    
  while(1)
    {
      cerr <<"Porownuje: " << tab[i] << " z " <<  tab[j] <<endl; 
      if(i<s && j<p) //jezeli zaden z ineksow nie wypadl poza swoj zakres
	{
	  if(atoi(tab[i].c_str()) < atoi(tab[j].c_str())) 
	    {
	      cerr << tab[i] <<" < " << tab[j] << endl;
	      cerr << "wpisuje: " << tab[i] << endl;
	      this->tablica_dyn[k]=tab[i];
	      i++;
	    }
	  else
	    {
	      cerr << tab[i] <<" => " << tab[j] << endl;
	      cerr << "wpisuje: " << tab[j] << endl;
	      this->tablica_dyn[k]=tab[j];
	      j++;
	    }
	}
      else if( i==s && j<p )
	{
	  for(j;j<p;j++)
	    {
	      cerr << "przepis1" << endl;
	      this->tablica_dyn[k]=tab[j];
	      k++;
	    }
	  break;
	}
      else if( i<s && j==p)
	{
	  for(i;i<s;i++)
	    {
	      cerr << "przepis2" << endl;
	      this->tablica_dyn[k]=tab[i];
	      k++;
	    }
	  break;
	}
      k++;
      cerr << "STEP "<< endl; 
      for(int i=0;i<4;i++) //rozmiar docelowy!!!
	cerr << tablica_dyn[i] << endl;
    }
}

void BiegaczLista::mergesort(int l, int p)
{
  int sr;
  if((p-l) % 2==0)
    sr=(l+p)/2; //jako, ze p to indeks, aby dostac srodkowy indeks trzeba dodac 1
  //else
   
    
  cerr << "sr= "<< sr << endl;
  merge(l,sr,p);
}

//*************END****************//
