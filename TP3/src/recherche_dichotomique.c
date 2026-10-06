#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAILLE 100

int main() {
    int tableau[TAILLE];
    int recherche;
    int debut = 0, fin = TAILLE - 1, milieu;
    int trouve = 0;

    srand(time(NULL));

    /* Tableau trie par construction : chaque valeur = precedente + (0 a 4) */
    tableau[0] = rand() % 21 - 10;
    for (int i = 1; i < TAILLE; i++) {
        tableau[i] = tableau[i - 1] + rand() % 5;
    }

    printf("Tableau trie :\n");
    for (int i = 0; i < TAILLE; i++) {
        printf("%d ", tableau[i]);
    }
    printf("\n\n");

    printf("Entrez l'entier que vous souhaitez chercher : ");
    if (scanf("%d", &recherche) != 1) {
        printf("Saisie invalide\n");
        return 1;
    }

    /* Recherche dichotomique */
    while (debut <= fin) {
        milieu = (debut + fin) / 2;
        if (tableau[milieu] == recherche) {
            trouve = 1;
            break;
        } else if (tableau[milieu] < recherche) {
            debut = milieu + 1;
        } else {
            fin = milieu - 1;
        }
    }

    if (trouve) {
        printf("\nResultat : entier present\n");
    } else {
        printf("\nResultat : entier absent\n");
    }
    return 0;
}
