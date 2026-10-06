#include <stdio.h>
#include "fichier.h"

int lire_fichier(char *nom_de_fichier) {
    FILE *f = fopen(nom_de_fichier, "r");
    char ligne[1024];

    if (f == NULL) {
        printf("Erreur : impossible d'ouvrir le fichier %s\n", nom_de_fichier);
        return -1;
    }

    printf("Contenu du fichier %s :\n", nom_de_fichier);
    while (fgets(ligne, sizeof(ligne), f) != NULL) {
        printf("%s", ligne);
    }

    fclose(f);
    return 0;
}

int ecrire_dans_fichier(char *nom_de_fichier, char *message) {
    FILE *f = fopen(nom_de_fichier, "a");

    if (f == NULL) {
        printf("Erreur : impossible d'ouvrir le fichier %s en ecriture\n", nom_de_fichier);
        return -1;
    }

    fprintf(f, "%s\n", message);
    fclose(f);
    return 0;
}
