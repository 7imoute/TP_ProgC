#include <stdio.h>

int main() {
    int num1 = 16;
    int num2 = 3;
    char op = '+';   // change cette valeur pour tester : '-', '*', '/', '%', '&', '|', '~'

    printf("num1 = %d, num2 = %d, op = '%c'\n", num1, num2, op);

    switch (op) {
        case '+':
            printf("Resultat = %d\n", num1 + num2);
            break;
        case '-':
            printf("Resultat = %d\n", num1 - num2);
            break;
        case '*':
            printf("Resultat = %d\n", num1 * num2);
            break;
        case '/':
            if (num2 != 0)
                printf("Resultat = %d\n", num1 / num2);
            else
                printf("Erreur : division par zero\n");
            break;
        case '%':
            if (num2 != 0)
                printf("Resultat = %d\n", num1 % num2);
            else
                printf("Erreur : modulo par zero\n");
            break;
        case '&':
            printf("Resultat = %d\n", num1 & num2);   // ET bit a bit
            break;
        case '|':
            printf("Resultat = %d\n", num1 | num2);   // OU bit a bit
            break;
        case '~':
            printf("Resultat = %d\n", ~num1);         // NON bit a bit (unaire, sur num1)
            break;
        default:
            printf("Operateur inconnu : '%c'\n", op);
            break;
    }

    return 0;
}
