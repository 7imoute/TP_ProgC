#include <stdio.h>

int main() {
    char chaine1[100] = "Hello";
    char chaine2[] = " World!";
    char copie[100];
    int longueur = 0;
    int i, j;

    /* 1. Longueur de la chaine */
    while (chaine1[longueur] != '\0') {
        longueur++;
    }
    printf("Longueur de \"%s\" : %d\n", chaine1, longueur);

    /* 2. Copie de chaine1 dans copie */
    i = 0;
    while (chaine1[i] != '\0') {
        copie[i] = chaine1[i];
        i++;
    }
    copie[i] = '\0';
    printf("Copie : \"%s\"\n", copie);

    /* 3. Concatenation de chaine2 a la fin de chaine1 */
    i = 0;
    while (chaine1[i] != '\0') {
        i++;
    }
    j = 0;
    while (chaine2[j] != '\0') {
        chaine1[i] = chaine2[j];
        i++;
        j++;
    }
    chaine1[i] = '\0';
    printf("Concatenation : \"%s\"\n", chaine1);

    /* Longueur totale */
    longueur = 0;
    while (chaine1[longueur] != '\0') {
        longueur++;
    }
    printf("Longueur totale : %d\n", longueur);

    return 0;
}
