#include <stdio.h>
#include "operator.h"

int somme(int num1, int num2) {
    return num1 + num2;
}

int difference(int num1, int num2) {
    return num1 - num2;
}

int produit(int num1, int num2) {
    return num1 * num2;
}

int quotient(int num1, int num2) {
    return num1 / num2;
}

int modulo(int num1, int num2) {
    return num1 % num2;
}

int et(int num1, int num2) {
    return num1 & num2;
}

int ou(int num1, int num2) {
    return num1 | num2;
}

int negation(int num1, int num2) {
    (void)num2; /* operateur unaire : num2 n'est pas utilise */
    return ~num1;
}

int calculer(char op, int num1, int num2, int *resultat) {
    switch (op) {
        case '+':
            *resultat = somme(num1, num2);
            break;
        case '-':
            *resultat = difference(num1, num2);
            break;
        case '*':
            *resultat = produit(num1, num2);
            break;
        case '/':
            if (num2 == 0) {
                printf("Erreur : division par zero\n");
                return -1;
            }
            *resultat = quotient(num1, num2);
            break;
        case '%':
            if (num2 == 0) {
                printf("Erreur : modulo par zero\n");
                return -1;
            }
            *resultat = modulo(num1, num2);
            break;
        case '&':
            *resultat = et(num1, num2);
            break;
        case '|':
            *resultat = ou(num1, num2);
            break;
        case '~':
            *resultat = negation(num1, num2);
            break;
        default:
            printf("Erreur : operateur '%c' inconnu\n", op);
            return -1;
    }
    return 0;
}
