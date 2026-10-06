/*
 * Exercice 4.6 : recherche d'une phrase dans un fichier
 * Utilisation : ./chercherfichier fichier.txt   (ou sans argument : le nom est demande)
 */
#include <stdio.h>
#include <string.h>

#define TAILLE_LIGNE 1024

/* Compte le nombre d'occurrences (sans chevauchement) de phrase dans ligne */
int compter_occurrences(const char *ligne, const char *phrase) {
    int compteur = 0;
    size_t longueur = strlen(phrase);
    const char *p = ligne;

    if (longueur == 0) {
        return 0;
    }
    while ((p = strstr(p, phrase)) != NULL) {
        compteur++;
        p += longueur;
    }
    return compteur;
}

int main(int argc, char *argv[]) {
    char nom_fichier[256];
    char phrase[256];
    char ligne[TAILLE_LIGNE];
    int numero_ligne = 0;
    int total = 0;
    FILE *f;

    if (argc >= 2) {
        strncpy(nom_fichier, argv[1], sizeof(nom_fichier) - 1);
        nom_fichier[sizeof(nom_fichier) - 1] = '\0';
    } else {
        printf("Entrez le nom du fichier : ");
        if (scanf("%255s", nom_fichier) != 1) {
            return 1;
        }
    }

    printf("Entrez la phrase que vous souhaitez rechercher : ");
    if (scanf(" %255[^\n]", phrase) != 1) {
        return 1;
    }

    f = fopen(nom_fichier, "r");
    if (f == NULL) {
        printf("Erreur : impossible d'ouvrir le fichier %s\n", nom_fichier);
        return 1;
    }

    printf("\nRésultats de la recherche :\n");
    while (fgets(ligne, sizeof(ligne), f) != NULL) {
        int n;
        numero_ligne++;
        ligne[strcspn(ligne, "\n")] = '\0'; /* retire le retour a la ligne */
        n = compter_occurrences(ligne, phrase);
        if (n > 0) {
            printf("Ligne %d, %d fois\n", numero_ligne, n);
            total += n;
        }
    }
    fclose(f);

    if (total == 0) {
        printf("Phrase non trouvée dans le fichier.\n");
    }
    return 0;
}
