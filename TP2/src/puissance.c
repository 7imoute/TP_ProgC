#include <stdio.h>

int main(void) {
    int a = 2;          /* base */
    int b = 3;          /* exposant */
    long long resultat = 1;   /* element neutre de la multiplication */

    for (int i = 0; i < b; i++) {
        resultat *= a;  /* on multiplie a par lui-meme b fois */
    }

    printf("%d^%d = %lld\n", a, b, resultat);
    return 0;
}
