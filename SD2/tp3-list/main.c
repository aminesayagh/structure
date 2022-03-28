#include <stdio.h>
#include <stdlib.h>

#include "list.c"


int main() {
      Liste liste = initialisationList();
      insertion(liste, 25);
      insertion(liste, 26);
      insertion(liste, 27);
      insertion(liste, 28);
      insertion(liste, 29);
      insertion(liste, 30);
      insertion(liste, 31);

      afficherEtudiant(liste);

      suppressionPremierElement(liste);
      suppressionElement(liste, 30);
      suppressionElement(liste, 27);

      afficherEtudiant(liste);
      return 0;
}