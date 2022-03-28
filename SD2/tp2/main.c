#include <stdio.h>
#include <stdlib.h>
#include "tableau.c"

#define MAX_TAILLE 100

int main() {
      int tabBase[MAX_TAILLE];
      Cellule tabTrier[MAX_TAILLE];
      int tailleTabBase = 0, tailleTabTrier = 0;
      int i = 0;

      do{
            printf("Definisser la taille de votre tableau: ");
            scanf("%d", &tailleTabBase);
      }while(tailleTabBase < 0 || tailleTabBase > MAX_TAILLE);

      for(i = 0; i < tailleTabBase; i++){
            printf("Remplisser la case num %d du tableau: ", i + 1);
            scanf("%d", &tabBase[i]);

            int valueExist = chercherValue(tabTrier, tailleTabTrier, tabBase[i]);
            if(valueExist < 0){
                  tabTrier[tailleTabTrier].value = tabBase[i];
                  tabTrier[tailleTabTrier].occ = 1;
                  tailleTabTrier++;
            } else {
                  tabTrier[valueExist].occ++;
            }
      }

      printf("\n");
      
      for(i = 0; i < tailleTabTrier; i++) {
            printf("Value de la case %d du tableau est %d, avec %d comme nombre d'occurence.\n", i,tabTrier[i].value, tabTrier[i].occ);
      }

}