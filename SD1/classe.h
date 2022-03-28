typedef struct EtudiantSchema {
    int CNE;
    int MoyenneEnMath;
    int MoyenneEnPhysique;
} Etudiant;

float moyMath(Etudiant Etudiants[], int nombreEtudiants);

float moyPhys(Etudiant Etudiants[], int nombreEtudiants);