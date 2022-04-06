
typedef struct Etudiant *Etudiant;
struct Etudiant {
      int CNE;
      Etudiant suivant;
};

typedef struct ListeSchema {
      Etudiant premier;
} *Liste;

// creation
Liste initialisationList(int premierCNE);
void insertion(Liste liste, int cneNouveauEtudiant);

// affichage
void afficherEtudiant(Liste liste);

// suppression
void suppressionPremierElement(Liste liste);
void suppressionElement(Liste liste, int cneEtudiant);

// localisation
Etudiant localisationPremierOccurence(Liste liste, int cneEtudiant);
Etudiant localisationDernierOccurence(Liste liste, int cneEtudiant);
Etudiant localisationNiemOccurence(Liste liste, int cneEtudiant, int numOcc);


int longeurListe(Liste liste);

