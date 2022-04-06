#include <stdio.h>
#include <stdlib.h>

#include "list.h"

Liste initialisationList(int premierValeur){
      Liste liste = malloc(sizeof(Liste));
      Element element = malloc(sizeof(element));

      if(liste == NULL || element == NULL) exit(EXIT_FAILURE);
      
      element->suivant = NULL;
      element->valeur = premierValeur;
      element->occ = 1;

      liste->premier = element;
      if(element->suivant == NULL) return liste;
      return liste;
}


Element localisationPremierOccurence(Liste liste, int val){
      if(liste == NULL) exit(EXIT_FAILURE);
      if(liste->premier == NULL) exit(EXIT_FAILURE);

      Element elementExist = malloc(sizeof(elementExist));
      elementExist = NULL;

      Element element = malloc(sizeof(element));
      element = liste->premier;
      if(element->valeur == val) {
                  elementExist = element;
                  return elementExist;
            }
      while(element->suivant != NULL){
            printf("element to check %d and to find %d\n", element->valeur, val);
            element = element->suivant;
            if(element->valeur == val) {
                  elementExist = element;
                  return elementExist;
            }
      }
      // do{
      // }while(element->suivant != NULL);
      return elementExist;
}

void insertionEnDernierDeLaListe(Liste liste, int value) {
      Element nouveau = malloc(sizeof(Element));
      if(nouveau == NULL || liste == NULL) exit(EXIT_FAILURE);

      nouveau->valeur = value;
      nouveau->occ = 1;

      Element element = malloc(sizeof(Element));
      element = liste->premier;
      do{
            element = element->suivant;
      }while(element->suivant != NULL);
      element->suivant = nouveau;
}

Liste genererListeValeurOcc(int tableau[],int tailleTableau) {
      Liste liste = initialisationList(tableau[0]);
      int i = 0;
      for(i = 0; i < tailleTableau; i++){
            Element elementExist = malloc(sizeof(Element));
            int value = tableau[i];
            
            elementExist = localisationPremierOccurence(liste, value);
            if(elementExist != NULL){
                  afficherListe(liste);
                  int numberOcc = elementExist->occ;
                  printf("element exist %d, occ %d\n", elementExist->valeur, elementExist->occ);
                  elementExist->occ = numberOcc+1;
            } else {
                  insertionEnDernierDeLaListe(liste, value);
            }
      }
      return liste;
}

void afficherListe(Liste liste){
      printf("afficher liste\n");
      if(liste == NULL) exit(EXIT_FAILURE);

      Element actuel = malloc(sizeof(Element));
      actuel = liste->premier;

      while(actuel != NULL){
            printf("%d , %d -> ", actuel->valeur, actuel->occ);
            actuel = actuel->suivant;
      }

      printf("NULL\n");
}