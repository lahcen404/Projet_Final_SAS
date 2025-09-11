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
    int posChoice;
    do
    {
        printf("\nSelect position:\n");
        printf("1 - gardien\n");
        printf("2 - defenseur\n");
        printf("3 - millieu\n");
        printf("4 - attaquant\n");
        printf("Enter choice (1-4): ");
        scanf("%d", &posChoice);
        getchar();

        switch (posChoice)
        {
        case 1:
            strcpy(joueurs[countJoueurs].poste, "gardien");
            break;
        case 2:
            strcpy(joueurs[countJoueurs].poste, "defenseur");
            break;
        case 3:
            strcpy(joueurs[countJoueurs].poste, "millieu");
            break;
        case 4:
            strcpy(joueurs[countJoueurs].poste, "attaquant");
            break;
        default:
            printf("Invalid choice! Try again.\n");
            posChoice = 0;
            break;
        }
    } while (posChoice == 0);

    printf("Entrer l'age de joueur :\n");
    scanf("%d", &joueurs[countJoueurs].age);
    getchar();

    printf("Entrer le nombre de buts de joueur :\n");
    scanf("%d", &joueurs[countJoueurs].buts);
    getchar();

    if (joueurs[countJoueurs].buts >= 20)
    {
        printf("---------------------------STAR d'equipe----------------------\n");
        printf("\n| %s %s est le STAR de l'equipe avec %d buts !!!|\n",
               joueurs[countJoueurs].nom, joueurs[countJoueurs].prenom, joueurs[countJoueurs].buts);
        printf("-------------------------------------------------------------\n");
    }

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
void modifierPoste(int idJoueur)
{
    int nvPoste;
    int index = 0;

    printf("\n Entrer l'ID du joueur pour modifier le poste :\n");
    scanf("%d", &idJoueur);
    getchar();

    index = rechercherJoueurId(idJoueur);

    if (index == -1)
    {
        printf("\n Aucun joueur trouvé !!\n");
    }
    else
    {
        do
        {
            printf("\nSelect position:\n");
            printf("1 - gardien\n");
            printf("2 - defenseur\n");
            printf("3 - millieu\n");
            printf("4 - attaquant\n");
            printf("Enter choice (1-4): ");
            scanf("%d", &nvPoste);

            switch (nvPoste)
            {
            case 1:
                strcpy(joueurs[index].poste, "gardien");
                break;
            case 2:
                strcpy(joueurs[index].poste, "defenseur");
                break;
            case 3:
                strcpy(joueurs[index].poste, "millieu");
                break;
            case 4:
                strcpy(joueurs[index].poste, "attaquant");
                break;
            default:
                printf("Invalid choice! Try again.\n");
                nvPoste = 0;
                break;
            }
        } while (nvPoste == 0);

        printf("Poste modifié avec succès !!\n");
    }
}

// modifier l'age
void modifierAge(int idJoueur)
{

    int nvAge;
    int index = 0;

    printf("\n Enter l' ID de Joueur pour modifier l'Age :\n");
    scanf("%d", &idJoueur);
    getchar();

    index = rechercherJoueurId(idJoueur);

    // printf("id index Age modiify est %d\n", index);

    if (index == -1)
    {
        printf("\n Aucun joueur !!\n");
    }
    else
    {
        printf("Entrer le nouveau Age :\n");
        scanf("%d", &nvAge);
        getchar();

        joueurs[index].age = nvAge;

        printf("l'Age modifier avec success !!\n");
    }
}

// modifier nombre de buts
void modifierNbrButs(int idJoueur)
{

    int nvNbrButs;
    int index = 0;

    printf("\n Enter l' ID de Joueur pour modifier le nombre de buts :\n");
    scanf("%d", &idJoueur);
    getchar();

    index = rechercherJoueurId(idJoueur);

    // printf("id index joueur modiify est %d\n", index);

    if (index == -1)
    {
        printf("\n Aucun joueur !!\n");
    }
    else
    {
        printf("Entrer le nouveau nombre de buts :\n");
        scanf("%d", &nvNbrButs);
        getchar();

        joueurs[index].buts = nvNbrButs;

        if (joueurs[index].buts >= 20)
    {
        printf("---------------------------STAR d'equipe----------------------\n");
        printf("\n| %s %s est le STAR de l'equipe avec %d buts !!!|\n",
               joueurs[index].nom, joueurs[index].prenom, joueurs[index].buts);
        printf("-------------------------------------------------------------\n");
    }

        printf("Nombre de buts modifier avec success !!\n");
    }
}

// modifier joueur
void modifierJoueur()
{

    int idJoueur;
    int choix;

    if (countJoueurs == 0)
    {
        printf("\n Aucun joueur !!\n");
        return;
    }

    do
    {
        printf("1 - Modifier Poste\n");
        printf("2 - Modifier l'Age\n");
        printf("3 - Modifier nomber de buts\n");
        printf("4 - Quiit !!\n");

        scanf("%d", &choix);
        getchar();

        switch (choix)
        {
        case 1:
            modifierPoste(idJoueur);
            break;

        case 2:
            modifierAge(idJoueur);
            break;

        case 3:
            modifierNbrButs(idJoueur);
            break;

        case 4:
            printf("Quit !!");
            break;
        default:
            printf("Choix invalide !\n");
        }
    } while (choix != 4);
}

// supprimer un joueur
void supprimerJoueur(int idJoueur)
{

    int index = 0;

    printf("\n Enter l' ID de Joueur pour supprimer :\n");
    scanf("%d", &idJoueur);
    getchar();

    index = rechercherJoueurId(idJoueur);

    if (index == -1)
    {
        printf("\n Aucun joueur !!\n");
    }
    else
    {
        for (int i = 0; i < countJoueurs - 1; i++)
        {
            strcpy(joueurs[index].nom, joueurs[index + 1].nom);
            strcpy(joueurs[index].nom, joueurs[index + 1].nom);
            joueurs[index].numeroMaillot = joueurs[index + 1].numeroMaillot;
            strcpy(joueurs[index].nom, joueurs[index + 1].nom);
            joueurs[index].age = joueurs[index + 1].age;
            joueurs[index].buts = joueurs[index + 1].buts;
        }
        countJoueurs--;
        printf("-------- Joueur supprimer avec success !! --------");
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
                Joueur temp = joueurs[j];
                joueurs[j] = joueurs[j + 1];
                joueurs[j + 1] = temp;
            }
        }
    }

    printf("\n-----------------------------------\n");
    printf("\n--- Liste Joueurs Triée Par Age ---\n");
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

    for (int i = 0; i < countJoueurs - 1; i++)
    {
        for (int j = 0; j < countJoueurs - i - 1; j++)
        {
            if (_stricmp(joueurs[j].nom, joueurs[j + 1].nom) > 0)
            {
                Joueur temp = joueurs[j];
                joueurs[j] = joueurs[j + 1];
                joueurs[j + 1] = temp;
            }
        }
    }

    printf("\n-----------------------------------\n");
    printf("\n--- Liste Joueurs Triée Par Nom ---\n");
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
            if (_stricmp(joueurs[j].poste, "attaquant") != 0 && _stricmp(joueurs[j + 1].poste, "attaquant") == 0)
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

// afficher les joueurs
void afficherJoueursTrier()
{

    if (countJoueurs == 0)
    {
        printf("\n Aucun joueur !!\n");
        return;
    }
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

// afficher age moyenne
void ageMoyenne()
{

    int sum = 0;
    int ageMoyenne = 0;

    for (int i = 0; i < countJoueurs; i++)
    {
        sum += joueurs[i].age;
    }
    // printf("sum est %d",sum);
    ageMoyenne = sum / countJoueurs;
    printf("--------------------------------------------\n");
    printf("------------Age moyenne des joueurs est : %d-----------\n", ageMoyenne);
    printf("--------------------------------------------\n");
}

// afficher Marquer plus but
void marquerPlus(int nbrButs)
{

    printf("Entrer nombre de buts :");
    scanf("%d", &nbrButs);
    getchar();

    printf("\n========== Liste des Joueurs plus de %d buts ==========\n", nbrButs);

    for (int i = 0; i < countJoueurs; i++)
    {
        if (joueurs[i].buts > nbrButs)
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
    }
}

// afficher meilleur buteur
void afficherMeilleurButeur()
{

    int maxButs = joueurs[0].buts;
    printf("\n========== Liste des meilleurs Joueurs Marquer  ==========\n");

    for (int i = 1; i < countJoueurs; i++)
    {
        if (maxButs < joueurs[i].buts)
        {
            maxButs = joueurs[i].buts;
        }
    }
    // printf("%d",maxButs);

    for (int i = 0; i < countJoueurs; i++)
    {
        if (joueurs[i].buts == maxButs)
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
    }
}

// afficher joueur plus jeune/agé
void afficherJoueurPlusJeuneAge()
{
    int jeune = joueurs[0].age;
    int age = joueurs[0].age;

    for (int i = 1; i < countJoueurs; i++)
    {
        if (age < joueurs[i].age)
        {
            age = joueurs[i].age;
        }
    }
    // printf("big age is : %d\n",age);

    printf("\n========== Liste de Joueur plus agé  ==========\n");

    for (int i = 0; i < countJoueurs; i++)
    {
        if (joueurs[i].age == age)
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
    }

    for (int i = 1; i < countJoueurs; i++)
    {
        if (jeune > joueurs[i].age)
        {
            jeune = joueurs[i].age;
        }
    }

    // printf("small age is : %d\n",jeune);

    printf("\n========== Liste de Joueur plus Jeune  ==========\n");

    for (int i = 0; i < countJoueurs; i++)
    {
        if (joueurs[i].age == jeune)
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
    }
}

//  Statistiques
void statistiques()
{

    int choix;
    int nbrButs = 0;
    if (countJoueurs == 0)
    {
        printf("\n Aucun joueur !!\n");
        return;
    }

    do
    {
        printf("\n------------------------------------\n");
        printf("\n------ Statistiques :--------\n");
        printf("\n------------------------------------\n");

        printf("1 - Afficher nombre total joueurs\n");
        printf("2 - Afficher Age Moyenne des joueurs\n");
        printf("3 - Afiicher joueurs marquer plus buts\n");
        printf("4 - Afficher le meilleur buteur\n");
        printf("5 - Afiicher joueur plus jeune et plus agé\n");
        printf("6 - Quit\n");
        scanf("%d", &choix);
        getchar();
        switch (choix)
        {
        case 1:
            totalJoueurs();
            break;

        case 2:
            ageMoyenne();
            break;

        case 3:
            marquerPlus(nbrButs);
            break;

        case 4:
            afficherMeilleurButeur();
            break;

        case 5:
            afficherJoueurPlusJeuneAge();
            break;

        case 6:
            printf("Quit !!");

        default:
            printf("Choix invalide !\n");
        }

    } while (choix != 6);
}
int main()
{
    int idJoueur;
    int choix;

    Joueur fakePlayers[] = {
        {1, "Ronaldo", "Cristiano", 7, "Attaquant", 39, 850},
        {2, "Messi", "Lionel", 10, "Attaquant", 37, 900},
        {3, "Neuer", "Manuel", 1, "Gardien", 38, 0},
        {4, "Ramos", "Sergio", 4, "Defenseur", 39, 120},
        {5, "Modric", "Luka", 10, "Millieu", 38, 150},
        {6, "Mbappe", "Kylian", 9, "Attaquant", 26, 850},
        {7, "Kante", "N'Golo", 6, "Millieu", 33, 40},
        {8, "VanDijk", "Virgil", 5, "Defenseur", 34, 50}};

    int n = sizeof(fakePlayers) / sizeof(fakePlayers[0]);

    for (int i = 0; i < n; i++)
    {
        joueurs[countJoueurs++] = fakePlayers[i];
    }

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
            modifierJoueur();
            break;

        case 3:
            supprimerJoueur(idJoueur);
            break;

        case 4:
            afficherJoueursTrier();
            break;

        case 5:
            rechercheFunction();
            break;

        case 6:
            statistiques();
            break;

        case 7:
            printf("Au revoir !!\n");
            break;
        default:
            printf("Choix invalide !\n");
        }
    } while (choix != 7);
}