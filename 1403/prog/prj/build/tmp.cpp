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
