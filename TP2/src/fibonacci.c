#include <stdio.h>

int main() {
    int n = 7;
    long long u0 = 0, u1 = 1, un;

    printf("Suite de Fibonacci jusqu'a U%d : ", n);
    for (int i = 0; i < n; i++) {
        if (i == 0) {
            un = u0;
        } else if (i == 1) {
            un = u1;
        } else {
            un = u0 + u1;
            u0 = u1;
            u1 = un;
        }
        printf("%lld", un);
        if (i < n - 1) {
            printf(", ");
        }
    }
    printf("\n");
    return 0;
}
