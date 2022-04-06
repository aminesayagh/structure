#include <stdio.h>
#include <stdlib.h>

typedef struct ProduitSchema *Produit;


struct ProduitSchema {
      Produit precedent;
      char code[100];
      char nom[100];
      int prixUnit;
      int quatiterAchete;
      Produit suivant;
};

typedef struct PanierSchema{
      Produit premier;
} *Panier;

void ajouterPanier(Panier panier); // q2
Panier fusionerPanier(Panier panier1, Panier panier2); // q3
int trierPanier(Panier panier); // q4
int calculerPrixTotal(Panier panier); // q5
void afficherPanier(Panier panier); // q6
Produit rechercherProduit(Panier panier, char nomProduitRechercher[]);
Produit rechercherProduitLePlusCherDuPanier(Panier panier); // q7
Produit supprimerProduit(Panier panier, char nomProduitSupprimer[]); // q8
void enregistrementPanier(Panier panier); // q8-2
void menu(); // q9

void ajouterPanier(Panier panier){
      if(panier == NULL) exit(EXIT_FAILURE);

      Produit produit = malloc(sizeof(produit));
      produit->precedent = NULL;

      char code[20];
      printf("Definir le code du produit : ");
      scanf("%s", code);
      strcpy(produit->code, code);

      char nom[20];
      printf("Definir le non du produit : ");
      scanf("%s", nom);
      strcpy(produit->nom, nom);

      printf("Definir le prix d'uniter du produit : ");
      scanf("%d", &produit->prixUnit);
      
      printf("Definir le qualiter acheter du produit : ");
      scanf("%d", &produit->quatiterAchete);
      printf("\n");

      produit->suivant = panier->premier; 
      panier->premier = produit;
}

Panier fusionerPanier(Panier panier1, Panier panier2){
      if(panier1 == NULL || panier2 == NULL) exit(EXIT_FAILURE);

      Panier panierFusion = malloc(sizeof(panierFusion));
      panierFusion->premier = panier1->premier;

      Produit produit = malloc(sizeof(produit));
      
      produit = panier1->premier;

      while(produit->suivant != NULL){
            produit = produit->suivant;
      }

      produit->suivant = panier2->premier;
      afficherPanierPourTest(panierFusion);
      return panierFusion;
}

int trierPanier(Panier panier){
      if(panier == NULL) exit(EXIT_FAILURE);
      
      Produit produitCourant = malloc(sizeof(produitCourant));
      produitCourant = panier->premier;

      // 0 trie invalid, 1 trie valid
      if(produitCourant->suivant != NULL) return 0;

      Produit actualSave = malloc(sizeof(actualSave));
      Produit precedentSave = malloc(sizeof(precedentSave));
      while(produitCourant != NULL){
            actualSave = courant; // ptr
            precedentSave = courant->precedent; // tmp
            produitCourant = produitCourant->suivant;
            while(precedentSave != NULL && precedentSave->prixUnit > actualSave->prixUnit){
                  precedentSave= precedentSave->precedent;
            }
            actualSave->precedent->suivant = actualSave->suivant;
            if(actualSave->suivant == NULL){
                  actualSave->suivant->precedent = actualSave->precedent;
                  if(precedentSave== NULL){
                        precedentSave = panier->premier;
                        actualSave->precedent = NULL;
                        actualSave->suivant = precedentSave;
                        actualSave->suivant->precedent = actualSave;
                        panier->premier = actualSave->precedent;
                  }else{
                        precedentSave = precedentSave->suivant;
                        precedentSave->precedent->suivant = actualSave;
                        actualSave->precedent = precedentSave->precedent;
                        precedentSave->precedent = actualSave;
                        actualSave->suivant = precedentSave;
                  }
            }
      }
      return 1;
}

int calculerPrixTotal(Panier panier){
      if(panier == NULL) exit(EXIT_FAILURE);

      int prixTotal = 0;

      Produit produitcourant = malloc(sizeof(produitCourant));
      produitCourant = panier->premier;

      while(produitCourant != NULL){
            prixTotal = produitcourant->prixUnit * produitcourant->quatiterAchete + prixTotal;
      }
      return prixTotal;
}

void afficherPanier(Panier panier){
      if(panier == NULL) exit(EXIT_FAILURE);

      Produit produitActual = malloc(sizeof(produitActual));
      produitActual = panier->premier;

      printf("Code\tNom\tQuantite X Prix Unitaire");
      while(produitActual != NULL){
            printf("%s\t%s\t%d", produitActual->code, produitActual->name, produitActual->prixUnit);
      }
      printf("Prix total \t%d", calculerPrixTotal(panier));
}

Produit rechercherProduit(Panier panier, char nomProduitRechercher[]){
      if(panier == NULL) exit(EXIT_FAILURE);

      Produit produitTrouver = malloc(sizeof(produitTrouver));

      Produit produitCourant = malloc(sizeof(produitCourant));
      produitCourant = panier->premier;


      while(produitCourant != NULL){
            if(produitCourant->nom == nomProduitRechercher){
                  produitTrouver = produitCourant;
                  return produitTrouver;
            }
            produitCourant = produitCourant->suivant;
      }
      return produitTrouver;
}

Produit rechercherProduitLePlusCherDuPanier(Panier panier){
      if(panier == NULL) exit(EXIT_FAILURE);

      Produit produitLePlusCher = malloc(sizeof(Produit));

      Produit produitCourant = malloc(sizeof(produitCourant));
      produitCourant = panier->premier;

      produitTrouver = produitCourant;
      while(produitCourant != NULL){
            if(produitCourant->prixUnit > produitLePlusCher->prixUnit) produitLePlusCher = produitCourant;
            produitCourant = produitCourant->suivant;
      }
      return produitLePlusCher;
}

Produit supprimerProduit(Panier panier, char nomProduitASupprimer[]) {
      if(panier == NULL) exit(EXIT_FAILURE);

      Produit produitSupprimer = malloc(sizeof(produitSupprimer)); // reste null si produit non trouver

      Produit produitCourant = malloc(sizeof(produitCourant));
      produitCourant = panier->premier;

      produit precedentSave = malloc(sizeof(precedentSave));
      produit suivantSave = malloc(sizeof(suivantSave));
      while(produitCourant != NULL){
            precedentSave = produitCourant->precedent;
            suivantSave = produitCourant->suivant;

            // verification du premier element
            if(precedentSave == NULL && produitCourant->nom == nomProduitASupprimer){
                  panier->premier = suivantSave;
                  suivantSave->precedent = NULL;
                  return produitCourant;
            }

            // verification d'element en millieu
            if(produitCourant->nom == nomProduitASupprimer){
                  suivantSave->precedent = precedentSave;
                  precedentSave->suivant = suivantSave;
                  return produitCourant;
            }

            // verification du dernier elementExist
            if(suivantSave == NULL && produitCourant->nom == nomProduitASupprimer){
                  precedentSave->suivant = NULL;
                  return produitCourant;
            }

            produitCourant = produitCourant->suivant;
      }
      return produitSupprimer;

}

void enregistrementPanier(Panier panier) {
      FILE *fichier = NULL;

      Produit produitActual = malloc(sizeof(produitActual));
      produitActual = panier->premier;

      fichier = fopen("panier", "w");

      if(fichier == NULL) exit(EXIT_FAILURE);

      fprintf(fichier, "Code\tNom\tQuantite X Prix Unitaire");
      while(produitActual != NULL){
            printf("%s\t%s\t%d", produitActual->code, produitActual->name, produitActual->prixUnit);
      }

      fclose(ficher);
}

int menu(){
      int numChoisie = 0;

      printf("    Menu general      ");

      printf("Remplir le premier panier\t taper 1");
      printf("Remplir le dexieme panier\t taper 2");
      printf("Fusionner les deux panier\t taper 3");
      printf("trier les deux panier\t taper 4");
      printf("chercher le produit le plus cher\t taper 5");
      printf("Supprimer le produit le plus cher\t taper 6");
      printf("Afficher le panier\n taper 7");
      printf("Enregistrer le panier\t taper 8");
      printf("Quitter\t taper 0");

      scanf("%d", &numChoisie);

      return numChoisie;
}

int main(){
      int quitter = 0;

      // q1
      Panier panier1 = malloc(sizeof(panier1)); // allocation dynamic n'est pas necessaire pour examen
      Panier panier2 = malloc(sizeof(panier2));

      Produit produitLePlusCher = malloc(sizeof(produitLePlusCher));

      do{
            int tache = menu();
            switch(tache){
                  case 0: 
                        quitter = 1; 
                        break;
                  case 1:
                        ajouterPanier(panier1);
                        break;
                  case 2:
                        ajouterPanier(panier2);
                        break;
                  case 3:
                        if(panier1 == NULL || panier2 == NULL){
                              printf("Un des deux panier n'est toujour pas remplit");
                        }else{
                              fusionerPanier(panier1, panier2);
                        }
                        break;
                  case 4:
                        if(panier1 != NULL) {
                              int triePanier1Valider = trierPanier(panier1);
                        }
                        if(panier2 != NULL) {
                              int triePanier2Valider = trierPanier(panier2);
                        }
                        break;
                  case 5:
                        if(panier1 != NULL) {
                              Produit produitLePlusCherDuPanier1 = rechercherProduitLePlusCherDuPanier(panier1);
                        }
                        if(panier2 != NULL) {
                              Produit produitLePlusCherDuPanier2 = rechercherProduitLePlusCherDuPanier(panier2);
                        }
                        produitLePlusCherDuPanier1->prixUnit > produitLePlusCherDuPanier2->prixUnit ? produitLePlusCher = produitLePlusCherDuPanier1 : produitLePlusCher = produitLePlusCherDuPanier1;
                        break;
                  case 6:
                        supprimerProduit(panier, produitLePlusCher->nom);
                        break;
                  case 7:
                        afficherPanier(panier);
                        break;
                  case 8:
                        enregistrementPanier(panier);
                        break;
                  default:
                        printf("Tache non identifier");
                        break;
            }
      }while(!quitter);
      return 0;
}