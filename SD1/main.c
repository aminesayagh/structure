#include <stdio.h>
#include <stdlib.h>
#include "classe.c"

#define NOTE_MAX 20
#define MAX_ETUDIANT 100

int main(){
    int nombreEtudiants = 0;
    int i= 0;
    Etudiant etudiants[MAX_ETUDIANT];
    
    do{
        printf("definiser nombre d'etudiants: ");
        scanf("%d", &nombreEtudiants);
    }while(nombreEtudiants > MAX_ETUDIANT || nombreEtudiants <= 0);
    
    for(i=0; i< nombreEtudiants; i++){
        printf("rempliser les donees du %d etudiant.\n", i + 1);

        printf("CNE: ");
        scanf("%d", &etudiants[i].CNE);

        do{
            printf("Moyenne En Math: ");
            scanf("%d", &etudiants[i].MoyenneEnMath);
        }while(etudiants[i].MoyenneEnMath < 0 || etudiants[i].MoyenneEnMath > NOTE_MAX);

        do{
            printf("Moyenne En Physique ");
            scanf("%d", &etudiants[i].MoyenneEnPhysique);
        }while(etudiants[i].MoyenneEnPhysique < 0 || etudiants[i].MoyenneEnPhysique > NOTE_MAX);

        printf("\n");
    }

    printf("Moyenne En Math %f\n", moyMath(etudiants, nombreEtudiants));
    printf("Moyenne En Physique %f\n", moyPhys(etudiants, nombreEtudiants));

    return 0;
}