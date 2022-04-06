#include <stdlib.h>
#include <stdio.h>

#include "list.h"

Liste initialisationList(int premierCNE){
      Liste liste = malloc(sizeof(Liste));
      Etudiant etudiant = malloc(sizeof(etudiant));

      if(liste == NULL || etudiant == NULL) exit(EXIT_FAILURE);
      
      etudiant->suivant = NULL;
      etudiant->CNE = premierCNE;
      liste->premier = etudiant;

      return liste;
}


void insertion(Liste liste, int cneNouveauEtudiant){
      Etudiant nouveau = malloc(sizeof(Etudiant));
      if(liste == NULL || nouveau == NULL) exit(EXIT_FAILURE);

      nouveau->CNE = cneNouveauEtudiant;

      nouveau->suivant = liste->premier;
      liste->premier = nouveau;
}



void afficherEtudiant(Liste liste){
      if(liste == NULL) exit(EXIT_FAILURE);

      Etudiant actuel = malloc(sizeof(Etudiant));
      actuel = liste->premier;

      while(actuel != NULL){
            printf("%d -> ", actuel->CNE);
            actuel = actuel->suivant;
      }

      printf("NULL\n");
}

void suppressionPremierElement(Liste liste){
      if(liste == NULL) exit(EXIT_FAILURE);

      if(liste->premier == NULL) exit(EXIT_FAILURE);

      Etudiant etudiantSupprimer = liste->premier;
      liste->premier = etudiantSupprimer->suivant;
      free(etudiantSupprimer);
}

void suppressionElement(Liste liste, int cneEtudiant) {
      if(liste == NULL) exit(EXIT_FAILURE);

      if(liste->premier == NULL) exit(EXIT_FAILURE);

      Etudiant etudiant = malloc(sizeof(Etudiant));

      etudiant = liste->premier;
      do{
            if(etudiant->suivant->CNE == cneEtudiant){
                  Etudiant etudiantSupprimer = malloc(sizeof(Etudiant));
                  etudiantSupprimer = etudiant->suivant;
                  etudiant->suivant = etudiantSupprimer->suivant;
                  free(etudiantSupprimer);
            }
            etudiant = etudiant->suivant;
      }while(etudiant->suivant != NULL);
}

Etudiant localisationPremierOccurence(Liste liste, int cneEtudiant){
      if(liste == NULL) exit(EXIT_FAILURE);

      if(liste->premier == NULL) exit(EXIT_FAILURE);

      Etudiant etudiant = malloc(sizeof(Etudiant));

      etudiant = liste->premier;
      do{
            if(etudiant->CNE == cneEtudiant) return etudiant;
            etudiant = etudiant->suivant;
      }while(etudiant->suivant != NULL);
      return NULL;
}

Etudiant localisationDernierOccurence(Liste liste, int cneEtudiant) {
      if(liste == NULL) exit(EXIT_FAILURE);

      if(liste->premier == NULL) exit(EXIT_FAILURE);

      Etudiant etudiant = malloc(sizeof(Etudiant));

      Etudiant etudiantDernierOcc = malloc(sizeof(Etudiant));
      etudiantDernierOcc= NULL;

      etudiant = liste->premier;
      do{
            if(etudiant->CNE == cneEtudiant) etudiantDernierOcc = etudiant;

            etudiant = etudiant->suivant; 
      }while(etudiant->suivant != NULL);

      return etudiantDernierOcc;
}

Etudiant localisationNiemOccurence(Liste liste, int cneEtudiant, int numOcc){
      if(liste == NULL) exit(EXIT_FAILURE);
      if(liste->premier == NULL) exit(EXIT_FAILURE);

      int numEtudiantTrouver = 0;
      Etudiant etudiant = malloc(sizeof(Etudiant));

      etudiant = liste->premier;
      do{
            if(etudiant->CNE == cneEtudiant){
                  numEtudiantTrouver++;
                  if(numEtudiantTrouver == numOcc) return etudiant;
            }
            etudiant = etudiant->suivant;
      } while(etudiant->suivant != NULL);

      return NULL;
}

int longeurListe(Liste liste){
      if(liste == NULL) exit(EXIT_FAILURE);
      if(liste->premier == NULL) return 0;

      int tailleDuListe = 0;
      Etudiant etudiant = malloc(sizeof(Etudiant));
      etudiant = liste->premier;
      do{
            tailleDuListe++;
            etudiant = etudiant->suivant;
      }while(etudiant->suivant != NULL);

      return tailleDuListe;
}

