/*
 * Exercice 4.4 : calculatrice en ligne de commande
 * Compilation : gcc -Wall -o calcule calcule.c operator.c
 * Utilisation : ./calcule + 10 5     ./calcule '*' 7 8     ./calcule '~' 5
 */
#include <stdio.h>
#include <stdlib.h>
#include "operator.h"

int main(int argc, char *argv[]) {
    char op;
    int num1, num2 = 0, resultat;

    if (argc < 3 || argc > 4 || argv[1][0] == '\0' || argv[1][1] != '\0') {
        printf("Utilisation : %s <operateur> <num1> <num2>\n", argv[0]);
        printf("Operateurs : + - '*' / %% '&' '|' '~' (pour ~, num2 est facultatif)\n");
        return 1;
    }

    op = argv[1][0];
    num1 = atoi(argv[2]);
    if (argc == 4) {
        num2 = atoi(argv[3]);
    } else if (op != '~') {
        printf("Erreur : l'operateur %c necessite deux nombres\n", op);
        return 1;
    }

    if (calculer(op, num1, num2, &resultat) != 0) {
        return 1;
    }
    printf("Résultat : %d\n", resultat);
    return 0;
}
