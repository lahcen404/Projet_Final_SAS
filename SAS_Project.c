#include <stdio.h>
#include <string.h>
#include <ctype.h>

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
void ajouterSeulJoueur()
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
        ajouterSeulJoueur();
    }
}

// function Main Ajouter
void ajouterJoueur()
{

    int ajoutChoix;

    printf("\n1 - Ajouter un nouveau joueur\n");
    printf("2 - Ajouter plusieur joueurs\n");
    printf("3 - Quit\n");

    scanf("%d", &ajoutChoix);
    getchar();
    switch (ajoutChoix)
    {
    case 1:
        ajouterSeulJoueur();
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

    // printf("Entrez l' ID du joueur : ");
    // scanf("%d", &idRecherche);
    // getchar();

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

// Recherche Main Function
void rechercheFunction()
{

    if (countJoueurs == 0)
    {
        printf("\n ---------- Aucun joueur--------- !!\n");
        return;
    }

    char nomRecherche[50];
    int idRecherche;
    int rechercheChoix;

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
}

// modifier le poste
void modifierPoste(int idPoste)
{

    char nvPoste[MAX];
    int index = 0;

    printf("\n Enter l' ID de poste pour modifier :\n");
    scanf("%d", &idPoste);
    getchar();

    index = rechercherJoueurId(idPoste);

    printf("id index poste modiify est %d\n", index);

    if (index == -1)
    {
        printf("\n Aucun joueur !!\n");
    }
    else
    {
        printf("Entrer le nouveau poste :\n");
        fgets(nvPoste, sizeof(nvPoste), stdin);
        nvPoste[strcspn(nvPoste, "\n")] = '\0';

        strcpy(joueurs[index].poste, nvPoste);

        printf("Poste modifier avec success !!");
    }
}

// modifier l'age
void modifierAge(int idAge)
{

    int nvAge;
    int index = 0;

    printf("\n Enter l' ID de l'Age pour modifier :\n");
    scanf("%d", &idAge);
    getchar();

    index = rechercherJoueurId(idAge);

    printf("id index Age modiify est %d\n", index);

    if (index == -1)
    {
        printf("\n Aucun joueur !!\n");
    }
    else
    {
        printf("Entrer le nouveau Age :\n");
        scanf("%d",&nvAge);
        getchar();

        joueurs[index].age = nvAge;

        printf("l'Age modifier avec success !!");
    }
}



// trier par age
void trierParAge()
{

    if (countJoueurs == 0)
    {
        printf("\n ---------- Aucun joueur--------- !!\n");
        return;
    }

    for (int i = 0; i < countJoueurs - 1; i++)
    {
        for (int j = 0; j < countJoueurs - i - 1; j++)
        {
            if (joueurs[j].age > joueurs[j + 1].age)
            {
                int temp = joueurs[j].age;
                joueurs[j].age = joueurs[j + 1].age;
                joueurs[j + 1].age = temp;
            }
        }
    }

    printf("\n-----------------------------------\n");
    printf("\n--- Listes Joueurs Trier Par Age ---\n");
    printf("\n-----------------------------------\n");

    afficherJoueurs();
}

// trier par nom
void trierParNom()
{

    if (countJoueurs == 0)
    {
        printf("\n ---------- Aucun joueur--------- !!\n");
        return;
    }

    char temp[MAX];
    for (int i = 0; i < countJoueurs - 1; i++)
    {
        for (int j = 0; j < countJoueurs - i - 1; j++)
        {
            if (_stricmp(joueurs[j].nom, joueurs[j + 1].nom) > 0)
            {
                strcpy(temp, joueurs[j].nom);
                strcpy(joueurs[j].nom, joueurs[j + 1].nom);
                strcpy(joueurs[j + 1].nom, temp);
            }
        }
    }

    printf("\n-----------------------------------\n");
    printf("\n--- Listes Joueurs Trier Par Nom ---\n");
    printf("\n-----------------------------------\n");

    afficherJoueurs();
}

// trier par Poste ( Gardien )
void trierParPosteGardien()
{

    if (countJoueurs == 0)
    {
        printf("\n ---------- Aucun joueur--------- !!\n");
        return;
    }

    for (int i = 0; i < countJoueurs - 1; i++)
    {
        for (int j = 0; j < countJoueurs - i - 1; j++)
        {
            if (_stricmp(joueurs[j].poste, "gardien") != 0 && _stricmp(joueurs[j + 1].poste, "gardien") == 0)
            {
                Joueur temp = joueurs[j];
                joueurs[j] = joueurs[j + 1];
                joueurs[j + 1] = temp;
            }
        }
    }

    printf("\n-------------------------------------------\n");
    printf("\n--- Listes Joueurs Trier Par Poste Gardien ---\n");
    printf("\n-------------------------------------------\n");

    afficherJoueurs();
}

// trier par Poste ( defenseur )
void trierParPosteDefenseur()
{

    if (countJoueurs == 0)
    {
        printf("\n ---------- Aucun joueur--------- !!\n");
        return;
    }

    for (int i = 0; i < countJoueurs - 1; i++)
    {
        for (int j = 0; j < countJoueurs - i - 1; j++)
        {
            if (_stricmp(joueurs[j].poste, "defenseur") != 0 && _stricmp(joueurs[j + 1].poste, "defenseur") == 0)
            {
                Joueur temp = joueurs[j];
                joueurs[j] = joueurs[j + 1];
                joueurs[j + 1] = temp;
            }
        }
    }

    printf("\n-------------------------------------------\n");
    printf("\n--- Listes Joueurs Trier Par Poste Defenseur ---\n");
    printf("\n-------------------------------------------\n");

    afficherJoueurs();
}

// trier par Poste ( Millieu )
void trierParPosteMillieu()
{

    if (countJoueurs == 0)
    {
        printf("\n ---------- Aucun joueur--------- !!\n");
        return;
    }

    for (int i = 0; i < countJoueurs - 1; i++)
    {
        for (int j = 0; j < countJoueurs - i - 1; j++)
        {
            if (_stricmp(joueurs[j].poste, "millieu") != 0 && _stricmp(joueurs[j + 1].poste, "millieu") == 0)
            {
                Joueur temp = joueurs[j];
                joueurs[j] = joueurs[j + 1];
                joueurs[j + 1] = temp;
            }
        }
    }

    printf("\n-------------------------------------------\n");
    printf("\n--- Listes Joueurs Trier Par Poste Millieu ---\n");
    printf("\n-------------------------------------------\n");

    afficherJoueurs();
}

// trier par Poste ( Attaquant )
void trierParPosteAttaquant()
{

    if (countJoueurs == 0)
    {
        printf("\n ---------- Aucun joueur--------- !!\n");
        return;
    }

    for (int i = 0; i < countJoueurs - 1; i++)
    {
        for (int j = 0; j < countJoueurs - i - 1; j++)
        {
            if (_stricmp(joueurs[j].poste, "attquant") != 0 && _stricmp(joueurs[j + 1].poste, "attaquant") == 0)
            {
                Joueur temp = joueurs[j];
                joueurs[j] = joueurs[j + 1];
                joueurs[j + 1] = temp;
            }
        }
    }

    printf("\n-------------------------------------------\n");
    printf("\n--- Listes Joueurs Trier Par Poste Attaquant ---\n");
    printf("\n-------------------------------------------\n");

    afficherJoueurs();
}

// main function Affichage par Poste
void affichageParPoste()
{

    int choixAffichage;
    do
    {
        printf("\n------------------------------------\n");
        printf("\nAffichage des joueurs par poste :\n");
        printf("\n------------------------------------\n");

        printf("1 - Gardien\n");
        printf("2 - Defenseur\n");
        printf("3 - Millieu\n");
        printf("4 - Attaquant\n");
        printf("5 - Quit\n");
        scanf("%d", &choixAffichage);
        getchar();

        switch (choixAffichage)
        {
        case 1:
            trierParPosteGardien();
            break;

        case 2:
            trierParPosteDefenseur();
            break;

        case 3:
            trierParPosteMillieu();
            break;

        case 4:
            trierParPosteAttaquant();
            break;

        case 5:
            printf("Quit !!");

        default:
            printf("Choix invalide !\n");
        }

    } while (choixAffichage != 5);
}

// afficher les joueur
void afficherJoueursTrier()
{

    int choixAffichage;
    do
    {
        printf("\n------------------------------------\n");
        printf("\n------Affichage des joueurs :--------\n");
        printf("\n------------------------------------\n");

        printf("1 - Trier les joueurs par ordre alphabétique (Nom)\n");
        printf("2 - Trier les joueurs par age\n");
        printf("3 - Afficher les joueurs par poste\n");
        printf("4 - Quit\n");
        scanf("%d", &choixAffichage);
        getchar();
        switch (choixAffichage)
        {
        case 1:
            trierParNom();
            break;

        case 2:
            trierParAge();
            break;

        case 3:
            affichageParPoste();
            break;

        case 4:
            printf("Quit !!");

        default:
            printf("Choix invalide !\n");
        }

    } while (choixAffichage != 4);
}

// afficher nombre total des joueurs
void totalJoueurs()
{
    printf("\n------------------------------\n");
    printf("\n--------Total Joueurs est %d ----------\n", countJoueurs);
    printf("\n------------------------------\n");
}

int main()
{

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
        printf("5 - Rechercher joueur\n");
        printf("6 - Statistiques\n");
        printf("7 - Quitter\n");
        printf("Entrez votre choix : \n");
        scanf("%d", &choix);
        getchar();

        switch (choix)
        {
        case 1:
            ajouterJoueur();
            break;

        case 2:
            int idPoste;
            modifierAge(idPoste);
            break;

        case 3:
            break;

        case 4:
            afficherJoueursTrier();
            break;

        case 5:
            rechercheFunction();
            break;

        case 6:
            totalJoueurs();
            break;

        case 7:
            printf("Au revoir !!\n");
            break;
        default:
            printf("Choix invalide !\n");
        }
    } while (choix != 7);
}