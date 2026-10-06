#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAILLE 100

int main() {
    int tableau[TAILLE];
    int temp;

    srand(time(NULL));

    /* Valeurs aleatoires entre -100 et 100 */
    for (int i = 0; i < TAILLE; i++) {
        tableau[i] = rand() % 201 - 100;
    }

    printf("Tableau non trie :\n");
    for (int i = 0; i < TAILLE; i++) {
        printf("%d ", tableau[i]);
    }
    printf("\n\n");

    /* Tri a bulles */
    for (int i = 0; i < TAILLE - 1; i++) {
        for (int j = 0; j < TAILLE - 1 - i; j++) {
            if (tableau[j] > tableau[j + 1]) {
                temp = tableau[j];
                tableau[j] = tableau[j + 1];
                tableau[j + 1] = temp;
            }
        }
    }

    printf("Tableau trie par ordre croissant :\n");
    for (int i = 0; i < TAILLE; i++) {
        printf("%d ", tableau[i]);
    }
    printf("\n");
    return 0;
}
