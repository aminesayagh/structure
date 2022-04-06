#include <stdio.h>
#include <stdlib.h>

#include "list.c"



int main() {
      Liste liste = initialisationList(24);
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

      
      Etudiant etudiant = malloc(sizeof(etudiant));
      etudiant = localisationPremierOccurence(liste, 25);
      if(etudiant != NULL ) printf("etudiant trouver %d\n", etudiant->CNE);
      else printf("NULL");

      insertion(liste, 30);
      insertion(liste, 30);
      etudiant = localisationDernierOccurence(liste, 30);
      if(etudiant != NULL ) printf("etudiant trouver a la dernier occurence %d\n", etudiant->CNE);
      else printf("NULL");
      
      etudiant = localisationNiemOccurence(liste, 30, 2);
      if(etudiant != NULL ) printf("etudiant trouver a la 2 occurence %d\n", etudiant->CNE);
      else printf("NULL");

      int longeurDuList = longeurListe(liste);
      printf("longeur list est %d\n", longeurDuList);

      return 0;
}