void Tri_liste(Element** Entete)
{
  Element *courant;
  courant=*Entete;
 
  if (courant->suivant==NULL)
    return;
 
  Element *ptr,*tmp;
 
  courant=courant->suivant;
  while(courant!=NULL)
    {
      ptr=courant;
      tmp=courant->precedent;
      courant=courant->suivant;
      while (tmp!=NULL && tmp->prix>ptr->prix)
        {
          tmp=tmp->precedent;
        }
      ptr->precedent->suivant=ptr->suivant;
      if (ptr->suivant!=NULL)
        {
          ptr->suivant->precedent=ptr->precedent;
          if (tmp==NULL)
            {
              tmp=*Entete;
              ptr->precedent=NULL;
              ptr->suivant=tmp;
              ptr->suivant->precedent=ptr;
              *Entete=ptr->precedent;
            }
          else
            {
              tmp=tmp->suivant;
              tmp->precedent->suivant=ptr;
              ptr->precedent=tmp->precedent;
              tmp->precedent=ptr;
              ptr->suivant=tmp;
            }
        }
    }
}


#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
typedef struct{
	char nom[32];
	char tel[16];
}personne;
typedef struct{
	personne pers[20];
	int cpt;
}carnet;
personne creer_Personne(char nom[32],char tel[16]){
	personne Per;
	strcpy(Per.nom,nom);
	strcpy(Per.tel,tel);
	return Per;
}
void show_personne(personne Per){
	printf("le nom : %s	\nle numero : %s  \n",Per.nom,Per.tel);
}
void add_personne_in_carnet(carnet *liste,personne Per){
	liste->pers[liste->cpt]=Per;
	liste->cpt++;
}
void show_carnet(carnet liste){
	for(int i=0;i<liste.cpt;i++){
		show_personne(liste.pers[i]);
	}
}
void delete_contact(carnet *liste,char nom[36]){
	int i=0;
	while(i<liste->cpt && strcmp(liste->pers[i].nom,nom)!=0)
		 i++;
 if(i<liste->cpt){
 	for(int j=i;j<liste->cpt-1;j++)
 	liste->pers[j]=liste->pers[j+1];
 	liste->cpt--;
 	printf("le contact %s  est suprimer... \n",nom);
 }
 else{
 	printf("le contact n`exisre pas \n");
 }
}
int search_contact(carnet liste,char nom[36]){
    for(int i=0;i<liste.cpt;i++){
	 if(!strcmp(liste.pers[i].nom,nom))
	 return i;
}
return -1;
}
int main(int argc, char *argv[]) {
carnet liste;
liste.cpt=0;
personne Per;
char nom[36];
char tel[16];
int choix,index;
do{
    printf("1 : pour ajouter un contact \n 2 : pour supprimer un contact \n 3 : pour afficher la liste des contacts  \n 4 : pour rechercher un contact par nom \n 5 : pour quitter le programme \n Entrez votre choix [1-5] : \n");
   scanf("%d",&choix);
   switch(choix){
   case 1 :
   	printf("saisir le nom  ");
	scanf("%s",&nom);
	printf("saisir le numero de telephone  ");
	scanf("%s",&tel);
    Per=creer_Personne(nom,tel);
    add_personne_in_carnet(&liste,Per);
    break;
    case 2:
    printf("enter name ... ");
	scanf("%s",&nom);
    delete_contact(&liste,nom);
    break;
    case 3:
    show_carnet(liste);
    break;
    case 4:
    printf("enter name ... ");
	scanf("%s",&nom); 
    index=search_contact(liste,nom);
    if(index==-1)
    printf("contact n`existe pas dans la liste \n");
    else
    show_personne(liste.pers[index]);
    break;   
    default :
    	printf("you are out of programme...");
        break;
    }
}while(choix>0 && choix<5);
	return 0;
}