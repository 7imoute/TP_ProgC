#include <stdio.h>

int main() {
    unsigned int d = 0x10001000; /* 4e et 20e bits (en partant de la gauche) a 1 */
    int taille = sizeof(d) * 8;  /* 32 bits */

    /* Le n-ieme bit en partant de la gauche est a la position (taille - n) en partant de la droite */
    unsigned int bit4 = (d >> (taille - 4)) & 1;
    unsigned int bit20 = (d >> (taille - 20)) & 1;

    if (bit4 == 1 && bit20 == 1) {
        printf("1\n");
    } else {
        printf("0\n");
    }
    return 0;
}
