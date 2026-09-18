#include <stdio.h>

int main() {
    int nombres[] = {0, 4096, 65536, 65535, 1024};
    int taille = 5;

    for (int k = 0; k < taille; k++) {      // boucle sur les 5 nombres
        int n = nombres[k];
        printf("%6d = ", n);

        // Parcours des 32 bits, du plus fort (bit 31) au plus faible (bit 0)
        for (int i = 31; i >= 0; i--) {
            int bit = (n >> i) & 1;         // isole le bit numero i
            printf("%d", bit);
            if (i % 4 == 0)                 // un espace tous les 4 bits (lisibilite)
                printf(" ");
        }
        printf("\n");
    }

    return 0;
}