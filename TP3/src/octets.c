#include <stdio.h>

int main() {
    short s = 0x0302;
    int i = 0x04030201;
    long int l = 0x0807060504030201L;
    float f = 5.0f;
    double d = 1.0;
    long double ld;
    unsigned char *p;

    /* Mise a zero des octets de remplissage du long double avant l'affectation */
    p = (unsigned char *)&ld;
    for (unsigned long k = 0; k < sizeof(ld); k++) {
        *(p + k) = 0;
    }
    ld = 1.0L;

    printf("Octets de short :\n");
    p = (unsigned char *)&s;
    for (unsigned long k = 0; k < sizeof(s); k++) {
        printf(" %02x", *(p + k));
    }

    printf("\n\nOctets de int :\n");
    p = (unsigned char *)&i;
    for (unsigned long k = 0; k < sizeof(i); k++) {
        printf(" %02x", *(p + k));
    }

    printf("\n\nOctets de long int :\n");
    p = (unsigned char *)&l;
    for (unsigned long k = 0; k < sizeof(l); k++) {
        printf(" %02x", *(p + k));
    }

    printf("\n\nOctets de float :\n");
    p = (unsigned char *)&f;
    for (unsigned long k = 0; k < sizeof(f); k++) {
        printf(" %02x", *(p + k));
    }

    printf("\n\nOctets de double :\n");
    p = (unsigned char *)&d;
    for (unsigned long k = 0; k < sizeof(d); k++) {
        printf(" %02x", *(p + k));
    }

    printf("\n\nOctets de long double :\n");
    p = (unsigned char *)&ld;
    for (unsigned long k = 0; k < sizeof(ld); k++) {
        printf(" %02x", *(p + k));
    }
    printf("\n");

    /* Detection de l'ordre des octets */
    p = (unsigned char *)&i;
    if (*p == 0x01) {
        printf("\nMachine petit-boutiste (little-endian)\n");
    } else {
        printf("\nMachine gros-boutiste (big-endian)\n");
    }
    return 0;
}
