#include <stdio.h>
#define MAX 100

typedef struct {
    int id;
    char nom[50];
    char prenom[50];
    int numeroMaillot;
    char poste[20];
    int age;
    int buts;
} Joueur;

Joueur joueurs[MAX];
int countJoueurs = 0;


// ajouter un joueur
void ajouterUnJoueur(){

    joueurs[countJoueurs].id = countJoueurs + 1;

    printf("Entrer le nom de joueur :\n");
    fgets(joueurs[countJoueurs].nom,sizeof(joueurs[countJoueurs].nom),stdin);

    printf("Entrer le prenom de joueur :\n");
    fgets(joueurs[countJoueurs].prenom,sizeof(joueurs[countJoueurs].prenom),stdin);

    printf("Entrer le numero Maillot de joueur :\n");
    scanf("%d",&joueurs[countJoueurs].numeroMaillot);
    getchar();

    printf("Entrer le poste de joueur (Gardien, Défenseur, Milieu, Attaquant)) :\n");
    fgets(joueurs[countJoueurs].poste,sizeof(joueurs[countJoueurs].poste),stdin);

    printf("Entrer l'age de joueur :\n");
    scanf("%d",&joueurs[countJoueurs].age);
    getchar();

    printf("Entrer le nombre de buts de joueur :\n");
    scanf("%d",&joueurs[countJoueurs].buts);
    getchar();

   
    countJoueurs++;
}




int main(){
ajouterUnJoueur();

      int choix;
    do{
        printf("\n--- Gestion Equipe de Football ---\n");
        printf("1 - Ajouter joueur\n");
        printf("2 - Modifier joueur\n");
        printf("3 - Supprimer joueur\n");
        printf("4 - Afficher joueurs\n");
        printf("5 - Trier joueurs\n");
        printf("6 - Rechercher joueur\n");
        printf("7 - Statistiques\n");
        printf("8 - Quitter\n");
        printf("Entrez votre choix : ");
        scanf("%d",&choix);
        getchar();

         switch(choix){
            case 1:  break;
            case 2:  break;
            case 3:  break;
            case 4:  break;
            case 5:  break;
            case 6:  break;
            case 7:  break;
            case 8: printf("Au revoir !!\n"); break;
            default: printf("Choix invalide !\n");
        }
    }while(choix!=8);
    
}