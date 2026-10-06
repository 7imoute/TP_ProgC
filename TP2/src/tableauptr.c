#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAILLE 11

int main() {
    int entiers[TAILLE];
    float flottants[TAILLE];
    int *pi;
    float *pf;

    srand(time(NULL));

    /* Remplissage avec des valeurs aleatoires (sans notation indicielle) */
    for (pi = entiers, pf = flottants; pi < entiers + TAILLE; pi++, pf++) {
        *pi = rand() % 200;
        *pf = (float)rand() / RAND_MAX * 10.0f;
    }

    printf("Tableau d'entiers (avant la multiplication par 3) :\n");
    for (pi = entiers; pi < entiers + TAILLE; pi++) {
        printf("%d%s", *pi, (pi < entiers + TAILLE - 1) ? ", " : "\n");
    }
    printf("Tableau de nombres a virgule flottante (avant la multiplication par 3) :\n");
    for (pf = flottants; pf < flottants + TAILLE; pf++) {
        printf("%.2f%s", *pf, (pf < flottants + TAILLE - 1) ? ", " : "\n");
    }

    /* Multiplication par 3 des valeurs dont l'indice est divisible par 2 */
    for (pi = entiers, pf = flottants; pi < entiers + TAILLE; pi++, pf++) {
        if ((pi - entiers) % 2 == 0) {
            *pi = *pi * 3;
            *pf = *pf * 3;
        }
    }

    printf("\nTableau d'entiers (apres la multiplication par 3) :\n");
    for (pi = entiers; pi < entiers + TAILLE; pi++) {
        printf("%d%s", *pi, (pi < entiers + TAILLE - 1) ? ", " : "\n");
    }
    printf("Tableau de nombres a virgule flottante (apres la multiplication par 3) :\n");
    for (pf = flottants; pf < flottants + TAILLE; pf++) {
        printf("%.2f%s", *pf, (pf < flottants + TAILLE - 1) ? ", " : "\n");
    }

    return 0;
}
