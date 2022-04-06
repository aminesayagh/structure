typedef struct ElementSchema *Element;
struct ElementSchema {
      int valeur;
      int occ;
      Element suivant;
};

typedef struct ListeSchema {
      Element premier;
} *Liste;

Liste initialisationList(int premierCNE);

Element localisationPremierOccurence(Liste liste, int val);

void insertionEnDernierDeLaListe(Liste liste, int value);

Liste genererListeValeurOcc(int *tableau,int tailleTableau);

void afficherListe(Liste liste);