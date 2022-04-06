#include <stdio.h>
#include <stdlib.h>

void InitialiseBoard(int Tableau[3][3]){
    for(int i=0 ; i<3 ; i++){
        for(int j=0 ; j<3 ; j++){
            Tableau[i][j]=-1;
        }
    }
}

void AffichageDuTableau(int taille,int Tableau[taille][taille]){
    printf("\n");
    for(int i = 0 ; i < taille ; i++){
        for(int j = 0 ; j < taille ; j++){
            switch(Tableau[i][j]){
                case-1:{
                printf("|  %d  |",j+i*taille+1);
                break;
                };
                case 1:{
                printf("| #X# |");
                break;
                };
                case 0:{
                printf("| #O# |");
                break;
                };
            }
        }
            printf("\n");
    }
}

typedef int *Case;

int LigneGagnante(int *a,int *b,int *c){
    int i=*a;
    if(*b==i&&*c==i&&i!=-1)return 1;
    else return 0;
}

int Winner(Case Lignes[8][3],int Tableau[3][3]){
    for(int i=0 ; i<8 ; i++){
        if(LigneGagnante(Lignes[i][0],Lignes[i][1],Lignes[i][2])){
            AffichageDuTableau(3,Tableau);
            if(*(Lignes[i][0]) == 1)printf("\nGAME OVER !! YOU WON !!!");
            else printf("\nGAME OVER !! YOU LOST !!");
            return 1;
        }
    }
    return 0;
}

void Input(int Tableau[3][3]){
    int N;
    do{
    printf("\nQuelle case veut tu remplir ?\n");
    scanf("%d",&N);
    N--;
    }while(Tableau[N/3][N%3]!=-1);
    Tableau[N/3][N%3]=1;
}

int BlockLossLigne(Case a , Case b , Case c){
    if(*a == 1 && *b == 1 && *c == -1){
        *c = 0 ;
        return 1;
    }
    if(*b == 1 && *c == 1 && *a == -1){
        *a = 0;
        return 1;
    }
    if(*a == 1 && *c == 1 && *b == -1){
        *b = 0;
        return 1;
    }
    return 0;
}

int BlockLossLignes(Case Lignes[8][3]){
    for(int i=0 ; i<8 ; i++){
        if(BlockLossLigne(Lignes[i][0],Lignes[i][1],Lignes[i][2])){
            return 1;
        }
    }
    return 0;
}

int Win(Case a , Case b , Case c){
    if(*a == 0 && *b == 0 && *c == -1){
        *c = 0 ;
        return 1;
    }
    if(*b == 0 && *c == 0 && *a == -1){
        *a = 0;
        return 1;
    }
    if(*a == 0 && *c == 0 && *b == -1){
        *b = 0;
        return 1;
    }
    return 0;
}

int CheckAllWin(Case Lignes[8][3]){
    for(int i=0 ; i<8 ; i++){
    if(Win(Lignes[i][0],Lignes[i][1],Lignes[i][2]))return 1;
    }
    return 0;
}

int CreateWinningLigne(int Tableau[3][3] ,Case a , Case b , Case c){
    if(*a == 0 && *b == -1 && *c ==-1){
        if(b == &Tableau[1][1])*b = 0 ;
        else *c = 0;
        return 1;
    }
    if(*a == -1 && *b == 0 && *c ==-1){
        *a = 0 ;
        return 1;
    }
    if(*a == -1 && *b == -1 && *c ==0){
        if(b == &Tableau[1][1])*b = 0 ;
        else *a = 0;
        return 1;
    }
    return 0;
}

int SearchForWinningLines(int Tableau[3][3] ,Case Lignes[8][3]){
    for(int i=0 ; i<8 ; i++){
        if(CreateWinningLigne(Tableau ,Lignes[i][0],Lignes[i][1],Lignes[i][2]))return 1;
    }
    return 0;
}

int Answer(int Tableau[3][3]){
    if(Tableau[1][1] == -1){
            Tableau[1][1]=0;
            return 1 ;
    }else{
        for(int i=0 ; i<3 ;i++){
            for(int j=0 ; j<3 ; j++){
                if((i+j)%2 == 0 && Tableau[i][j] == -1){
                        Tableau[i][j]=0;
                        return 1;
                }
            }
        }
    }
    for(int i=0 ; i<3 ;i++){
            for(int j=0 ; j<3 ; j++){
                if((i+j)%2 != 0 && Tableau[i][j] == -1){
                        Tableau[i][j]=0;
                        return 1;
                }
            }
    }
}

void React(int Tableau[3][3] , Case Lignes[8][3]){
    if(!CheckAllWin(Lignes)){
        if(!BlockLossLignes(Lignes)){
            if(!SearchForWinningLines(Tableau , Lignes)){
                Answer(Tableau);
            }
        }
    }
}

int Draw(int Tableau[3][3]){
    for(int i=0 ; i<3 ; i++){
        for(int j=0 ; j<3 ; j++){
        if(Tableau[i][j] == -1) return 0;
    }
    }
    AffichageDuTableau(3 ,Tableau);
    printf("\nDRAW !!");
    return 1;
}

void GameON(int Tableau[3][3] , Case Lignes[8][3]){
    while(!Winner(Lignes,Tableau)&&!Draw(Tableau)){
        AffichageDuTableau(3,Tableau);
        Input(Tableau);
        if(!Winner(Lignes,Tableau))React(Tableau,Lignes);
    }
}

int main(){
    int Tableau[3][3];
    InitialiseBoard(Tableau);
    Case    a=&Tableau[0][0],
            b=&Tableau[0][1],
            c=&Tableau[0][2],
            d=&Tableau[1][0],
            e=&Tableau[1][1],
            f=&Tableau[1][2],
            g=&Tableau[2][0],
            h=&Tableau[2][1],
            i=&Tableau[2][2];
    Case Lignes[8][3]={{a,e,i},{g,e,c},{a,b,c},{a,d,g},{d,e,f},{g,h,i},{b,e,h},{c,f,i}};
    GameON(Tableau,Lignes);
    return 0;
}