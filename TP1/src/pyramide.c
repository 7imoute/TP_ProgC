#include <stdio.h>

int main() {
    int n = 5;   // hauteur de la pyramide
    int i, j;

    for (i = 1; i <= n; i++) {           // chaque niveau de la pyramide

        // 1) les espaces pour centrer : n - i espaces
        for (j = 1; j <= n - i; j++) {
            printf(" ");
        }

        // 2) partie montante : 1, 2, ..., i
        for (j = 1; j <= i; j++) {
            printf("%d", j);
        }

        // 3) partie descendante : i-1, i-2, ..., 1
        for (j = i - 1; j >= 1; j--) {
            printf("%d", j);
        }

        printf("\n");                    // passage a la ligne suivante
    }

    printf("Generation de la pyramide terminee.\n");

    return 0;
}
