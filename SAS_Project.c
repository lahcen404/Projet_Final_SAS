#include <stdio.h>
#include <string.h>

#define MAX 100

typedef struct
{
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
void ajouterUnJoueur()
{

    joueurs[countJoueurs].id = countJoueurs + 1;

    printf("Entrer le nom de joueur :\n");
    fgets(joueurs[countJoueurs].nom, sizeof(joueurs[countJoueurs].nom), stdin);
    joueurs[countJoueurs].nom[strcspn(joueurs[countJoueurs].nom, "\n")] = '\0'; // removee enter key from the end

    printf("Entrer le prenom de joueur :\n");
    fgets(joueurs[countJoueurs].prenom, sizeof(joueurs[countJoueurs].prenom), stdin);
    joueurs[countJoueurs].prenom[strcspn(joueurs[countJoueurs].prenom, "\n")] = '\0';

    printf("Entrer le numero Maillot de joueur :\n");
    scanf("%d", &joueurs[countJoueurs].numeroMaillot);
    getchar();

    printf("Entrer le poste de joueur ([G] = Gardien, [D] = Défenseur, [M] = Millieu,[G] = Attaquant)) :\n");
    fgets(joueurs[countJoueurs].poste, sizeof(joueurs[countJoueurs].poste), stdin);
    joueurs[countJoueurs].poste[strcspn(joueurs[countJoueurs].poste, "\n")] = '\0';

    printf("Entrer l'age de joueur :\n");
    scanf("%d", &joueurs[countJoueurs].age);
    getchar();

    printf("Entrer le nombre de buts de joueur :\n");
    scanf("%d", &joueurs[countJoueurs].buts);
    getchar();

    countJoueurs++;

    printf("\n------Ajout Successfully !!--------\n");
}

// ajouter plusieur joueurs
void ajouterPlusieurJoueurs()
{

    int n;

    printf("Entrer nombre joueurs :");
    scanf("%d", &n);
    getchar();

    for (int i = 0; i < n; i++)
    {
        printf("\n Joueur %d\n", i + 1);
        ajouterUnJoueur();
    }
}

// afficher joueurs
void afficherJoueurs()
{
    if (countJoueurs == 0)
    {
        printf("\n Aucun joueur !!\n");
        return;
    }

    printf("\n========== Liste des Joueurs ==========\n");

    for (int i = 0; i < countJoueurs; i++)
    {
        printf("\n[Joueur %d]\n", i + 1);
        printf("ID              : %d\n", joueurs[i].id);
        printf("Nom             : %s\n", joueurs[i].nom);
        printf("Prenom          : %s\n", joueurs[i].prenom);
        printf("Numero Maillot  : %d\n", joueurs[i].numeroMaillot);
        printf("Poste           : %s\n", joueurs[i].poste);
        printf("Age             : %d\n", joueurs[i].age);
        printf("Nombre de Buts  : %d\n", joueurs[i].buts);
        printf("---------------------------------------\n");
    }

    printf("=======================================\n");
}

// recherche par Nom
int rechercherJoueurNom(char nomRecherche[50])
{

    printf("Entrez le nom du joueur : ");
    fgets(nomRecherche, sizeof(nomRecherche), stdin);
    nomRecherche[strcspn(nomRecherche, "\n")] = '\0';

    printf("%s", nomRecherche);

    for (int i = 0; i < countJoueurs; i++)
    {
        if (strcasecmp(joueurs[i].nom, nomRecherche) == 0)
        {

            printf("\n[Joueur %d]\n", i + 1);
            printf("ID              : %d\n", joueurs[i].id);
            printf("Nom             : %s\n", joueurs[i].nom);
            printf("Prenom          : %s\n", joueurs[i].prenom);
            printf("Numero Maillot  : %d\n", joueurs[i].numeroMaillot);
            printf("Poste           : %s\n", joueurs[i].poste);
            printf("Age             : %d\n", joueurs[i].age);
            printf("Nombre de Buts  : %d\n", joueurs[i].buts);
            printf("---------------------------------------\n");

            return i;
        }
    }
    printf("Joueur non trouvé !\n");
    return -1;
}

// recherche par Nom
int rechercherJoueurId(int idRecherche)
{

    printf("Entrez l' ID du joueur : ");
    scanf("%d", &idRecherche);
    getchar();

   // printf("%d", idRecherche);

    for (int i = 0; i < countJoueurs; i++)
    {
        if (joueurs[i].id == idRecherche)
        {

            printf("\n[Joueur %d]\n", i + 1);
            printf("ID              : %d\n", joueurs[i].id);
            printf("Nom             : %s\n", joueurs[i].nom);
            printf("Prenom          : %s\n", joueurs[i].prenom);
            printf("Numero Maillot  : %d\n", joueurs[i].numeroMaillot);
            printf("Poste           : %s\n", joueurs[i].poste);
            printf("Age             : %d\n", joueurs[i].age);
            printf("Nombre de Buts  : %d\n", joueurs[i].buts);
            printf("---------------------------------------\n");

            return i;
        }
    }
    printf("\n-------- Joueur non trouvé !--------------\n");
    return -1;
}

// trier par age
void trierParAge(){

for (int i = 0; i < countJoueurs -1; i++)
{
    for (int j = 0; j < countJoueurs - i - 1; j++)
    {
       if (joueurs[j].age>joueurs[j+1].age)
       {
        int temp = joueurs[j].age;
        joueurs[j].age = joueurs[j+1].age;
        joueurs[j+1].age = temp;
       }
       
    }
    
}

afficherJoueurs();


}

// trier par nom
void trierParNom(){
char temp[MAX];
for (int i = 0; i < countJoueurs -1; i++)
{
    for (int j = 0; j < countJoueurs - i - 1; j++)
    {
       if (_stricmp(joueurs[j].nom,joueurs[j+1].nom) > 0)
       {
        strcpy(temp,joueurs[j].nom);
        strcpy(joueurs[j].nom, joueurs[j+1].nom);
        strcpy(joueurs[j+1].nom, temp);
       }
       
    }
    
}

afficherJoueurs();


}

int main()
{

    int ajoutChoix;

    char nomRecherche[50];
    int idRecherche;
    int rechercheChoix;

    int choix;
    do
    {
        printf("\n-----------------------------------\n");
        printf("\n--- Gestion Equipe de Football ---\n");
        printf("\n-----------------------------------\n");
        printf("1 - Ajouter joueur\n");
        printf("2 - Modifier joueur\n");
        printf("3 - Supprimer joueur\n");
        printf("4 - Afficher joueurs\n");
        printf("5 - Trier joueurs\n");
        printf("6 - Rechercher joueur\n");
        printf("7 - Statistiques\n");
        printf("8 - Quitter\n");
        printf("Entrez votre choix : \n");
        scanf("%d", &choix);
        getchar();

        switch (choix)
        {
        case 1:

            printf("\n1 - Ajouter un nouveau joueur\n");
            printf("2 - Ajouter plusieur joueurs\n");
            printf("3 - Quit\n");

            scanf("%d", &ajoutChoix);
            getchar();
            switch (ajoutChoix)
            {
            case 1:
                ajouterUnJoueur();
                break;

            case 2:
                ajouterPlusieurJoueurs();
                break;

            case 3:
                printf("Quit !\n");
                break;

            default:
                printf("Choix invalide !\n");
                break;
            }
            break;

        case 2:
            break;
        case 3:
            break;
        case 4:
            afficherJoueurs();
            break;
        case 5:
            trierParNom();
            break;

        case 6:

            printf("\n1 - Recherche par Nom\n");
            printf("2 - Recherche par ID\n");
            printf("3 - Quit\n");

            scanf("%d", &rechercheChoix);
            getchar();
            switch (rechercheChoix)
            {
            case 1:
                rechercherJoueurNom(nomRecherche);
                break;

            case 2:
                rechercherJoueurId(idRecherche);
                break;

            case 3:
                printf("Quit !\n");
                break;

            default:
                printf("Choix invalide !\n");
                break;
            }
            break;

        case 7:
            break;
        case 8:
            printf("Au revoir !!\n");
            break;
        default:
            printf("Choix invalide !\n");
        }
    } while (choix != 8);
}