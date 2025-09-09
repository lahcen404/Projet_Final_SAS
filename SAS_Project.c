#include <stdio.h>


int main(){

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