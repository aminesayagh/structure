#include <stdlib.h>
#include <stdio.h>
#include "tableau.h"

int chercherValue(int *tab, int tailleTab, int valueRechercher){
      int i = 0;
      for(i = 0; i < tailleTab; i++) {
            if(tab[i] == valueRechercher){
                  return i;
            }
      }
      return -1;
}