#include <stdio.h>

#define NB_COULEURS 10

struct Couleur {
    unsigned char rouge;
    unsigned char vert;
    unsigned char bleu;
    unsigned char alpha;
};

int main() {
    struct Couleur couleurs[NB_COULEURS] = {
        {0xef, 0x78, 0x12, 0xff},
        {0x2c, 0xc8, 0x64, 0xff},
        {0xff, 0x00, 0x00, 0xff},
        {0x00, 0xff, 0x00, 0xff},
        {0x00, 0x00, 0xff, 0xff},
        {0xff, 0xff, 0x00, 0x80},
        {0x00, 0xff, 0xff, 0xc0},
        {0xff, 0x00, 0xff, 0x40},
        {0x80, 0x80, 0x80, 0xff},
        {0x12, 0x34, 0x56, 0x78}
    };

    for (int i = 0; i < NB_COULEURS; i++) {
        printf("Couleur %d :\n", i + 1);
        printf("Rouge : %d\n", couleurs[i].rouge);
        printf("Vert : %d\n", couleurs[i].vert);
        printf("Bleu : %d\n", couleurs[i].bleu);
        printf("Alpha : %d\n\n", couleurs[i].alpha);
    }
    return 0;
}
