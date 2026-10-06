#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NB_COULEURS 100

struct Couleur {
    unsigned char r;
    unsigned char g;
    unsigned char b;
    unsigned char a;
};

struct CouleurDistincte {
    struct Couleur couleur;
    int occurrences;
};

int main() {
    struct Couleur couleurs[NB_COULEURS];
    struct CouleurDistincte distinctes[NB_COULEURS];
    int nb_distinctes = 0;

    /* Palette reduite pour avoir des doublons */
    struct Couleur palette[5] = {
        {0xff, 0x23, 0x23, 0x45},
        {0xff, 0x00, 0x23, 0x12},
        {0x00, 0xff, 0x00, 0xff},
        {0x12, 0x34, 0x56, 0x78},
        {0xef, 0x78, 0x12, 0xff}
    };

    srand(time(NULL));
    for (int i = 0; i < NB_COULEURS; i++) {
        couleurs[i] = palette[rand() % 5];
    }

    /* Comptage des couleurs distinctes */
    for (int i = 0; i < NB_COULEURS; i++) {
        int trouve = 0;
        for (int j = 0; j < nb_distinctes; j++) {
            if (distinctes[j].couleur.r == couleurs[i].r &&
                distinctes[j].couleur.g == couleurs[i].g &&
                distinctes[j].couleur.b == couleurs[i].b &&
                distinctes[j].couleur.a == couleurs[i].a) {
                distinctes[j].occurrences++;
                trouve = 1;
                break;
            }
        }
        if (!trouve) {
            distinctes[nb_distinctes].couleur = couleurs[i];
            distinctes[nb_distinctes].occurrences = 1;
            nb_distinctes++;
        }
    }

    for (int j = 0; j < nb_distinctes; j++) {
        printf("0x%02x 0x%02x 0x%02x 0x%02x : %d\n",
               distinctes[j].couleur.r, distinctes[j].couleur.g,
               distinctes[j].couleur.b, distinctes[j].couleur.a,
               distinctes[j].occurrences);
    }
    return 0;
}
