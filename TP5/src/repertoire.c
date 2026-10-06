/*
 * Exercices 5.1, 5.2 et 5.3
 * Utilisation :
 *   ./repertoire <nom_du_repertoire>       -> 5.1 (contenu du dossier)
 *   ./repertoire -r <nom_du_repertoire>    -> 5.2 (parcours recursif)
 *   ./repertoire -i <nom_du_repertoire>    -> 5.3 (parcours iteratif)
 */
#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>

#include "repertoire.h"

#define TAILLE_CHEMIN 4096

/* Renvoie 1 si l'entree doit etre ignoree ("." et "..") */
static int est_point_ou_point_point(const char *nom)
{
    return strcmp(nom, ".") == 0 || strcmp(nom, "..") == 0;
}

/* Renvoie 1 si le chemin est un repertoire (les liens symboliques ne sont pas suivis) */
static int est_repertoire(const char *chemin)
{
    struct stat infos;

    if (lstat(chemin, &infos) != 0)
    {
        return 0;
    }
    return S_ISDIR(infos.st_mode);
}

/* ---------- Exercice 5.1 ---------- */
void lire_dossier(char *nom_repertoire)
{
    DIR *dossier = opendir(nom_repertoire);
    struct dirent *entree;
    char chemin[TAILLE_CHEMIN];

    if (dossier == NULL)
    {
        perror(nom_repertoire);
        return;
    }

    printf("Contenu de %s :\n", nom_repertoire);
    while ((entree = readdir(dossier)) != NULL)
    {
        if (est_point_ou_point_point(entree->d_name))
        {
            continue;
        }
        snprintf(chemin, sizeof(chemin), "%s/%s", nom_repertoire, entree->d_name);
        if (est_repertoire(chemin))
        {
            printf("  [REP]     %s\n", entree->d_name);
        }
        else
        {
            printf("  [FICHIER] %s\n", entree->d_name);
        }
    }

    closedir(dossier);
}

/* ---------- Exercice 5.2 ---------- */
void lire_dossier_recursif(char *nom_repertoire)
{
    DIR *dossier = opendir(nom_repertoire);
    struct dirent *entree;
    char chemin[TAILLE_CHEMIN];

    if (dossier == NULL)
    {
        perror(nom_repertoire);
        return;
    }

    while ((entree = readdir(dossier)) != NULL)
    {
        if (est_point_ou_point_point(entree->d_name))
        {
            continue;
        }
        snprintf(chemin, sizeof(chemin), "%s/%s", nom_repertoire, entree->d_name);
        printf("%s\n", chemin);

        /* Appel recursif sur chaque sous-repertoire.
           La recursion s'arrete quand un dossier ne contient plus de sous-dossier. */
        if (est_repertoire(chemin))
        {
            lire_dossier_recursif(chemin);
        }
    }

    closedir(dossier);
}

/* ---------- Exercice 5.3 ---------- */
void lire_dossier_iteratif(char *nom_repertoire)
{
    /* Pile des repertoires restant a parcourir */
    int capacite = 16;
    int nb = 0;
    char **pile = malloc(capacite * sizeof(char *));

    if (pile == NULL)
    {
        perror("malloc");
        return;
    }
    pile[nb++] = strdup(nom_repertoire);

    while (nb > 0)
    {
        char *courant = pile[--nb]; /* on depile un repertoire */
        DIR *dossier = opendir(courant);
        struct dirent *entree;
        char chemin[TAILLE_CHEMIN];

        if (dossier == NULL)
        {
            perror(courant);
            free(courant);
            continue;
        }

        while ((entree = readdir(dossier)) != NULL)
        {
            if (est_point_ou_point_point(entree->d_name))
            {
                continue;
            }
            snprintf(chemin, sizeof(chemin), "%s/%s", courant, entree->d_name);
            printf("%s\n", chemin);

            /* Un sous-repertoire est empile pour etre parcouru plus tard */
            if (est_repertoire(chemin))
            {
                if (nb == capacite)
                {
                    char **nouvelle;
                    capacite *= 2;
                    nouvelle = realloc(pile, capacite * sizeof(char *));
                    if (nouvelle == NULL)
                    {
                        perror("realloc");
                        break;
                    }
                    pile = nouvelle;
                }
                pile[nb++] = strdup(chemin);
            }
        }

        closedir(dossier);
        free(courant);
    }

    free(pile);
}

int main(int argc, char *argv[])
{
    if (argc == 2)
    {
        lire_dossier(argv[1]);
    }
    else if (argc == 3 && strcmp(argv[1], "-r") == 0)
    {
        lire_dossier_recursif(argv[2]);
    }
    else if (argc == 3 && strcmp(argv[1], "-i") == 0)
    {
        lire_dossier_iteratif(argv[2]);
    }
    else
    {
        printf("Utilisation : %s [-r | -i] <nom_du_repertoire>\n", argv[0]);
        printf("  sans option : contenu du repertoire (5.1)\n");
        printf("  -r          : parcours recursif (5.2)\n");
        printf("  -i          : parcours iteratif (5.3)\n");
        return 1;
    }

    return 0;
}
