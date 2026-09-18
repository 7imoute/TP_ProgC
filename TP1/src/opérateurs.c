#include <stdio.h>

int main() {
    int a = 16;
    int b = 3;

    printf("a = %d, b = %d\n\n", a, b);

    printf("a + b = %d\n", a + b);        // 19
    printf("a - b = %d\n", a - b);        // 13
    printf("a * b = %d\n", a * b);        // 48
    printf("a / b = %d\n", a / b);        // 5  (division entière)
    printf("a %% b = %d\n", a % b);       // 1  (reste)

    printf("(a == b) = %d\n", a == b);    // 0  (faux)
    printf("(a > b)  = %d\n", a > b);     // 1  (vrai)

    return 0;
}   

