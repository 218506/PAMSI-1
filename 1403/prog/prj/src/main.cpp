#include <iostream>


#include "Sedzia.h"
#include "BiegaczLista.h"
#include "Stoper.h"

using namespace std;

int main()
{
   BiegaczLista biegacz;
   Stoper stoper;
   Sedzia sedzia(biegacz, stoper);

   sedzia.release();
}
