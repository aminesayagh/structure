#include <stdlib.h>
#include <stdio.h>

#include "list.h"

Liste initialisationList(){
      Liste liste = malloc(sizeof(Liste));
      Etudiant etudiant = malloc(sizeof(etudiant));

      if(liste == NULL || etudiant == NULL) exit(EXIT_FAILURE);
      
      etudiant->suivant = NULL;
      
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
      if(liste == NULL) exit(1);

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

      if(liste->premier->CNE == cneEtudiant) suppressionPremierElement(liste);

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

