#include <stdlib.h>
#include <stdio.h>
#include "classe.h"



float moyMath(Etudiant *etudiants, int nombreEtudiants) {
    int i = 0;
    int resultMoyMath = 0;
    for(i = 0; i < nombreEtudiants; i++){
        resultMoyMath += etudiants[i].MoyenneEnMath;
    }
    return resultMoyMath / nombreEtudiants;
}

float moyPhys(Etudiant *etudiants, int nombreEtudiants) {
    int i = 0;
    int resultMoyPhys = 0;
    for(i = 0; i < nombreEtudiants; i++){
        resultMoyPhys += etudiants[i].MoyenneEnPhysique;
    }
    return resultMoyPhys / nombreEtudiants;
}