#include <stdio.h>

int main() {
    int somme = 0;

    for (int i = 1; i <= 1000; i++) {

        // Règle prioritaire : divisible par 11 -> on saute ce nombre
        if (i % 11 == 0) {
            continue;   // passe directement à l'itération suivante
        }

        // Divisible par 5 OU par 7 -> on l'ajoute à la somme
        if (i % 5 == 0 || i % 7 == 0) {
            somme += i;
        }

        // Si la somme dépasse 5000 -> on arrête tout
        if (somme > 5000) {
            break;      // sort de la boucle immédiatement
        }
    }

    printf("Somme finale = %d\n", somme);

    return 0;
}