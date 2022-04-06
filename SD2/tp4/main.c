#include <stdio.h>
#include <stdlib.h>

#include "list.c"

#define TAB_TAILLE_MAX 100


int main() {
      int tailleTab = 0, i = 0;
      int tab[TAB_TAILLE_MAX];

      do{
            printf("taille de votre tableau est : ");
            scanf("%d", &tailleTab);
      }while(tailleTab <= 0 || tailleTab > TAB_TAILLE_MAX);

      for(i = 0; i < tailleTab; i++){
            printf("definiser la valeur de la case numero %d du tableau :", i+1);
            scanf("%d", &tab[i]);
      }
      Liste liste = genererListeValeurOcc(tab, tailleTab);

      afficherListe(liste);

      return 0;
}