#include <stdio.h>

#define NB_PHRASES 10

int main() {
    char *phrases[NB_PHRASES] = {
        "Bonjour, comment ça va ?",
        "Le temps est magnifique aujourd'hui.",
        "C'est une belle journée.",
        "La programmation en C est amusante.",
        "Les tableaux en C sont puissants.",
        "Les pointeurs en C peuvent être déroutants.",
        "Il fait beau dehors.",
        "La recherche dans un tableau est intéressante.",
        "Les structures de données sont importantes.",
        "Programmer en C, c'est génial."
    };
    char *recherches[2] = {
        "La programmation en C est amusante.",
        "Je préfère le Python."
    };

    for (int r = 0; r < 2; r++) {
        char *cherchee = recherches[r];
        int trouvee = 0;

        for (int i = 0; i < NB_PHRASES && !trouvee; i++) {
            int k = 0;
            /* Comparaison caractere par caractere */
            while (phrases[i][k] != '\0' && cherchee[k] != '\0' &&
                   phrases[i][k] == cherchee[k]) {
                k++;
            }
            /* Correspondance parfaite si les deux chaines se terminent ensemble */
            if (phrases[i][k] == '\0' && cherchee[k] == '\0') {
                trouvee = 1;
            }
        }

        printf("Recherche de \"%s\" : ", cherchee);
        if (trouvee) {
            printf("Phrase trouvée\n");
        } else {
            printf("Phrase non trouvée\n");
        }
    }
    return 0;
}
