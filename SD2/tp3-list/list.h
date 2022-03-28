
typedef struct Etudiant *Etudiant;
struct Etudiant {
      int CNE;
      Etudiant suivant;
};

typedef struct ListeSchema {
      Etudiant premier;
} *Liste;


Liste initialisationList();
void insertion(Liste liste, int cneNouveauEtudiant);

void afficherEtudiant(Liste liste);

void suppressionPremierElement(Liste liste);
void suppressionElement(Liste liste, int cneEtudiant);