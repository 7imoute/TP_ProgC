#include <stdio.h>

int main() {
    int compteur = 5;   // taille du triangle, doit être < 10

    // ---------- Version avec des boucles for ----------
    printf("Version for :\n");
    for (int i = 1; i <= compteur; i++) {        // i = numéro de ligne
        for (int j = 1; j <= i; j++) {           // j = position sur la ligne
            if (i == compteur || j == 1 || j == i)
                printf("* ");                    // bord
            else
                printf("# ");                    // intérieur
        }
        printf("\n");                            // fin de ligne
    }

    // ---------- Version avec une boucle while ----------
    printf("\nVersion while :\n");
    int i = 1;
    while (i <= compteur) {
        int j = 1;
        while (j <= i) {
            if (i == compteur || j == 1 || j == i)
                printf("* ");
            else
                printf("# ");
            j++;                                 // ne pas oublier d'incrémenter !
        }
        printf("\n");
        i++;
    }

    return 0;
}