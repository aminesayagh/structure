#include <stdio.h>
#include <stdlib.h>
#include "tableau.c"

#define MAX_TAILLE 100

int main(){
      int tabBase[MAX_TAILLE], tabTrier[MAX_TAILLE];
      int tailleTabBase = 0, tailleTabTrier = 0;
      int i = 0;

      do{
            printf("Definisser la taille de votre tableau: ");
            scanf("%d", &tailleTabBase);
      }while(tailleTabBase < 0 || tailleTabBase > MAX_TAILLE);

      for(i = 0; i < tailleTabBase; i++){
            printf("Remplisser la case num %d du tableau: ", i + 1);
            scanf("%d", &tabBase[i]);

            if(chercherValue(tabTrier, tailleTabTrier, tabBase[i]) < 0){
                  tabTrier[tailleTabTrier] = tabBase[i];
                  tailleTabTrier++;
            }
      }

      printf("\n");

      for(i = 0; i < tailleTabTrier; i++){
            printf("Value de la case %d du tableau est %d\n",i , tabTrier[i]);
      }
      return 0;
}