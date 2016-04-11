#include "Lista.h"


//*********QUICKSORT***************//

//Metoda zamienia miejscami wyrazy o indeksie i, j.
void Lista::swap(int i, int j)
{
  if(i > Size()-1 || j>Size()-1)
    {
      cerr << "Nieprawidlowe indeksowanie swapa" << endl;
      return;
    }
  if(i>=j) //gdy ten sam wyraz, lub i>j nie swapuje
    return;
  
  string tmp1=Get(i);
  string tmp2=Get(j);
  
  if(i>0) //if spowodowany dziwnym napisaniem metody remove.
    {    
      Remove(j+1);
      Remove(i+1);
      Add(tmp1,j-1);
      Add(tmp2,i);
    }
  else
    {
      Remove(j+1);      
      Remove(i);
      Add(tmp1,j-1);
      Add(tmp2,i);
    }
}


int Lista:: partition(int l, int p)
{
  int i=l;
  int j;
  int piv=0;
  
  //1 - losowanie pivota - najbardziej z lewej.
  piv=atoi(Lista::Get(l).c_str());
  
  for(int j=l+1;j<p;j++)
    {
      if( atoi(Lista::Get(j).c_str()) <= piv )
	{
	  i++;
	  swap(i,j);
	}
    }  
  swap(l,i);
  //<---zamiana pivotu z ostatnim zapamietanym wyrazem mniejszym od piv
  
  return i;
}

  
  
//Wszystko ladnie, oprocz ostatniego wyrazu !
  
void Lista::quicksort(int l, int p)
{
  if(l<p) // jeżeli l i p sie nie minely
    {
      int m;
      m=partition(l,p);
      quicksort(m+1,p);
      quicksort(l,m); //sortowanie lewej strony
    }
}
  

//*************END****************//


//*********MERGESORT***************//


void Lista::merge(int l,int s, int p)
{
  Lista tmp;
  int i=l;
  int j=s;
  int k=0; //licznik listy tmp
  while(1)
    {
      cerr << Get(i)<< endl;
      cerr << Get(s)<< endl;
      cerr << "petla" << endl;
      if(i<s && j<p) // jezeli zaden z indeksow nie wypadl poza swoj zakres
	{  
	  if ( atoi(Get(i).c_str()) < atoi(Get(j).c_str()))
	    {
	      cerr << "if1" << endl;
	      tmp.Add(Get(i),k);
	      i++;
	    }
	  else
	    {
	      cerr << "if2" << endl;
	      tmp.Add(Get(j),k);
	      j++;	
	    }
	}
      else if ( i==s && j<p ) //jezeli i dotarlo - kopiuje reszte tablicy drugiej,przerywam petle
	{
	  cerr <<"przepis1"<<endl;
	  for(j;j<p;j++)
	    {
	      tmp.Add(Get(j),k);
	      k++;
	    }
	  break;
	}
      else if ( i<s && j==p  )
	{
	  cerr <<"przepis2"<<endl;
	  for(i;i<s;i++)
	    {
	      tmp.Add(Get(i),k);
	      k++;
	    }
	  break;
	}
      cerr << "STEP: "<<endl;
      for(int i=0 ;i<=k;i++)
	cerr << tmp.Get(i) << "  ";
      cerr << endl;
      k++;
    }
  
  // przepisanie tablicy 
  
  for(int gg=l; gg<p-1; gg++)
    {
      cerr << "REMOVE" << endl;
      Remove(gg);
    }
  Remove(0);

cerr << "REMOVE4" << endl;

 for(int gg=l; gg<p-1; gg++)
   {
     cerr << "po ADD" << endl;
     Add(tmp.Get(gg),gg);
   }
 
 cerr <<"STAGE:  " << endl;
 for(int gg=l; gg-1<p; gg++)
   {
     cerr << Get(gg) << "  ";
   }
 cerr << endl;
   
}

void Lista:: mergesort(int l, int p)
{
  int srod;
  if(p<=l)
    return;
  srod=(l+p)/2;
  cerr << "sr=" << srod<< endl;
  mergesort(l, srod);    // Dzielenie lewej częsc
  mergesort(srod+1, p);   // Dzielenie prawej części
  merge(l,srod,p);
}

//*************END****************//


int Lista::Size()
{
return rozmiar;
}

bool Lista::IsEmpty(){
    return (rozmiar == 0);
}

void Lista::Add(std::string item , int index)
{
if (rozmiar < index)
cout<<"Lista jest za mala"<<endl;
    else if (index == 0){
    Node* nodetmp = new Node();
    nodetmp->wartosc = item;
    nodetmp->wskaznik = wskaznikPOCZ; ///dostawiam element na poczatku i wskazuje na wczesniejszy element
    wskaznikPOCZ = nodetmp; ///aktualizowanie poczatkowoego wskaznika na nowo dodany element
    wskaznikKON = nodetmp; ///aktualizowanie koncowego+ wskaznika na nowo dodany element
    rozmiar ++;}

    else if (index == rozmiar){
    Node* nodetmp = new Node();
    nodetmp->wartosc = item;
    wskaznikKON->wskaznik = nodetmp;///wskaznik koncowy wskazuje na podpiete nowe pole w liscie
    wskaznikKON = nodetmp;
    rozmiar ++;}

    else {
    Node* nodetmp = new Node();
    nodetmp->wartosc = item;
    Node* temp = wskaznikPOCZ; ///temp to tymczasowy wskaznik dodawanej listy
    for(int i=0; i < index-1 ; i++)
    temp = temp->wskaznik; /// przestawiamy sie na kolejny element
    Node* nastepny = temp->wskaznik; ///pomocniczy wskaznik
    temp->wskaznik = nodetmp; ///wskazuje na nowo stworzony element
    nodetmp->wskaznik = nastepny; ///w nowo dodanym elemencie ustawiamy wskaznik na wczesniejszy(ktory jest nastepnym) elementem.
    rozmiar ++;
    }
}
void Lista::Remove (int index){
if(index == 0)
{
Node* temp=wskaznikPOCZ->wskaznik; ///zapamietaj drugi element listy
delete wskaznikPOCZ; ///usun pierwszy element
wskaznikPOCZ = temp; ///przestaw drugi na pierwszy
rozmiar --;
}
else if (index == rozmiar){
Node* temp = wskaznikPOCZ; ///temp to tymczasowy wskaznik dodawanej listy
for(int i=0; i < index-2 ; i++)
    temp = temp->wskaznik; /// przestawiamy sie na kolejny element
temp->wskaznik = nullptr;
delete wskaznikKON;
wskaznikKON = temp;
rozmiar --;
}
else{
Node* temp = wskaznikPOCZ; ///temp to tymczasowy wskaznik dodawanej listy
for(int i=0; i < index-2 ; i++)
    temp = temp->wskaznik;
Node* nastepnik = temp->wskaznik->wskaznik;
delete temp->wskaznik;
temp->wskaznik = nastepnik;
rozmiar --;
}
}
std::string Lista::Get(int index){
Node* temp = wskaznikPOCZ; ///temp to tymczasowy wskaznik dodawanej listy
for(int i=0; i < index ; i++)
    temp = temp->wskaznik;
return temp->wartosc;
}




