#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAILLE 100

int main() {
    int tableau[TAILLE];
    int plus_grand, plus_petit;

    srand(time(NULL));

    /* Remplissage avec des valeurs aleatoires entre 1 et 1000 (inclus) */
    for (int i = 0; i < TAILLE; i++) {
        tableau[i] = rand() % 1000 + 1;
    }

    plus_grand = tableau[0];
    plus_petit = tableau[0];
    for (int i = 1; i < TAILLE; i++) {
        if (tableau[i] > plus_grand) {
            plus_grand = tableau[i];
        }
        if (tableau[i] < plus_petit) {
            plus_petit = tableau[i];
        }
    }

    printf("Le numero le plus grand est : %d\n", plus_grand);
    printf("Le numero le plus petit est : %d\n", plus_petit);
    return 0;
}
