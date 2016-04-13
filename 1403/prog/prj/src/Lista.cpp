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




