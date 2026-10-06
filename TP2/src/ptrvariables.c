#include <stdio.h>

int main() {
    char c = 'A';
    short s = 0x1234;
    int i = 0xa47865ff;
    long int l = 0x12345678L;
    long long int ll = 0x123456789abcdefLL;
    float f = 2.0f;
    double d = 3.5;
    long double ld = 4.25L;

    char *pc = &c;
    short *ps = &s;
    int *pi = &i;
    long int *pl = &l;
    long long int *pll = &ll;
    float *pf = &f;
    double *pd = &d;
    long double *pld = &ld;

    /* Pointeurs pour lire la representation binaire des flottants */
    unsigned int *bits_f = (unsigned int *)pf;
    unsigned long long *bits_d = (unsigned long long *)pd;
    unsigned long long *bits_ld = (unsigned long long *)pld; /* mantisse (64 bits de poids faible) */
    unsigned short *exp_ld = (unsigned short *)((char *)pld + 8); /* signe + exposant (x86) */

    printf("Avant la manipulation :\n");
    printf("Adresse de c : %p, Valeur de c : %hhx\n", (void *)pc, *pc);
    printf("Adresse de s : %p, Valeur de s : %hx\n", (void *)ps, *ps);
    printf("Adresse de i : %p, Valeur de i : %x\n", (void *)pi, *pi);
    printf("Adresse de l : %p, Valeur de l : %lx\n", (void *)pl, *pl);
    printf("Adresse de ll : %p, Valeur de ll : %llx\n", (void *)pll, *pll);
    printf("Adresse de f : %p, Valeur de f : %x\n", (void *)pf, *bits_f);
    printf("Adresse de d : %p, Valeur de d : %llx\n", (void *)pd, *bits_d);
    printf("Adresse de ld : %p, Valeur de ld : %hx%016llx\n", (void *)pld, *exp_ld, *bits_ld);

    /* Manipulation des variables via leurs pointeurs */
    *pc = 'B';
    *ps = *ps + 1;
    *pi = *pi - 1;
    *pl = *pl * 2;
    *pll = *pll + 0x10;
    *pf = 1.0f;
    *pd = *pd * 2;
    *pld = *pld / 2;

    printf("\nApres la manipulation :\n");
    printf("Adresse de c : %p, Valeur de c : %hhx\n", (void *)pc, *pc);
    printf("Adresse de s : %p, Valeur de s : %hx\n", (void *)ps, *ps);
    printf("Adresse de i : %p, Valeur de i : %x\n", (void *)pi, *pi);
    printf("Adresse de l : %p, Valeur de l : %lx\n", (void *)pl, *pl);
    printf("Adresse de ll : %p, Valeur de ll : %llx\n", (void *)pll, *pll);
    printf("Adresse de f : %p, Valeur de f : %x\n", (void *)pf, *bits_f);
    printf("Adresse de d : %p, Valeur de d : %llx\n", (void *)pd, *bits_d);
    printf("Adresse de ld : %p, Valeur de ld : %hx%016llx\n", (void *)pld, *exp_ld, *bits_ld);

    return 0;
}
