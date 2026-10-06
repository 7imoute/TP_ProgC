#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAILLE 100

int main() {
    int tableau[TAILLE];
    int recherche;
    int trouve = 0;

    srand(time(NULL));

    /* Valeurs aleatoires entre -100 et 100 */
    for (int i = 0; i < TAILLE; i++) {
        tableau[i] = rand() % 201 - 100;
    }

    printf("Tableau :\n");
    for (int i = 0; i < TAILLE; i++) {
        printf("%d ", tableau[i]);
    }
    printf("\n\n");

    printf("Entrez l'entier que vous souhaitez chercher : ");
    if (scanf("%d", &recherche) != 1) {
        printf("Saisie invalide\n");
        return 1;
    }

    /* Recherche sequentielle */
    for (int i = 0; i < TAILLE; i++) {
        if (tableau[i] == recherche) {
            trouve = 1;
            break;
        }
    }

    if (trouve) {
        printf("\nResultat : entier present\n");
    } else {
        printf("\nResultat : entier absent\n");
    }
    return 0;
}
