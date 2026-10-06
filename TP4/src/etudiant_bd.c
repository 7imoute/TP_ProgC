/*
 * Exercice 4.3 : base de donnees etudiante
 * Compilation : gcc -Wall -o etudiant_bd etudiant_bd.c fichier.c
 */
#include <stdio.h>
#include "fichier.h"

#define NB_ETUDIANTS 5
#define NOM_FICHIER "etudiant.txt"

struct Etudiant {
    char nom[30];
    char prenom[30];
    char adresse[100];
    float note1;
    float note2;
};

int main(void) {
    struct Etudiant etudiants[NB_ETUDIANTS];
    char ligne[256];
    FILE *f;

    /* On repart d'un fichier vide a chaque execution */
    f = fopen(NOM_FICHIER, "w");
    if (f == NULL) {
        printf("Erreur : impossible de creer %s\n", NOM_FICHIER);
        return 1;
    }
    fclose(f);

    for (int i = 0; i < NB_ETUDIANTS; i++) {
        printf("Entrez les détails de l'étudiant.e %d :\n", i + 1);
        printf("Nom : ");
        scanf(" %29[^\n]", etudiants[i].nom);
        printf("Prénom : ");
        scanf(" %29[^\n]", etudiants[i].prenom);
        printf("Adresse : ");
        scanf(" %99[^\n]", etudiants[i].adresse);
        printf("Note 1 : ");
        scanf("%f", &etudiants[i].note1);
        printf("Note 2 : ");
        scanf("%f", &etudiants[i].note2);
        printf("\n");

        /* Une ligne par etudiant.e : nom;prenom;adresse;note1;note2 */
        snprintf(ligne, sizeof(ligne), "%s;%s;%s;%.2f;%.2f",
                 etudiants[i].nom, etudiants[i].prenom, etudiants[i].adresse,
                 etudiants[i].note1, etudiants[i].note2);
        if (ecrire_dans_fichier(NOM_FICHIER, ligne) != 0) {
            return 1;
        }
    }

    printf("Les détails des étudiants ont été enregistrés dans le fichier %s.\n", NOM_FICHIER);
    return 0;
}
