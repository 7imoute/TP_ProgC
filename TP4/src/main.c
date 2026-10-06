/*
 * Programme commun aux exercices 4.1, 4.2 et 4.7
 * Compilation : gcc -Wall -o main main.c operator.c fichier.c liste.c
 */
#include <stdio.h>
#include "operator.h"
#include "fichier.h"
#include "liste.h"

/* Exercice 4.1 : calcul avec operateurs */
void exercice_operateurs(void) {
    int num1, num2, resultat;
    char op;

    printf("Entrez num1 : ");
    if (scanf("%d", &num1) != 1) {
        printf("Saisie invalide\n");
        return;
    }
    printf("Entrez num2 : ");
    if (scanf("%d", &num2) != 1) {
        printf("Saisie invalide\n");
        return;
    }
    printf("Entrez l'opérateur (+, -, *, /, %%, &, |, ~) : ");
    if (scanf(" %c", &op) != 1) {
        printf("Saisie invalide\n");
        return;
    }

    if (calculer(op, num1, num2, &resultat) == 0) {
        printf("Résultat : %d\n", resultat);
    }
}

/* Exercice 4.2 : gestion de fichiers */
void exercice_fichiers(void) {
    int choix;
    char nom_de_fichier[256];
    char message[1024];

    do {
        printf("\nQue souhaitez-vous faire ?\n");
        printf("1. Lire un fichier\n");
        printf("2. Écrire dans un fichier\n");
        printf("0. Retour\n");
        printf("Votre choix : ");
        if (scanf("%d", &choix) != 1) {
            printf("Saisie invalide\n");
            return;
        }

        switch (choix) {
            case 1:
                printf("\nEntrez le nom du fichier à lire : ");
                scanf("%255s", nom_de_fichier);
                lire_fichier(nom_de_fichier);
                break;
            case 2:
                printf("\nEntrez le nom du fichier dans lequel vous souhaitez écrire : ");
                scanf("%255s", nom_de_fichier);
                printf("Entrez le message à écrire : ");
                scanf(" %1023[^\n]", message);
                if (ecrire_dans_fichier(nom_de_fichier, message) == 0) {
                    printf("Le message a été écrit dans le fichier %s.\n", nom_de_fichier);
                }
                break;
            case 0:
                break;
            default:
                printf("Choix invalide\n");
        }
    } while (choix != 0);
}

/* Exercice 4.7 : liste de couleurs */
void exercice_liste(void) {
    struct liste_couleurs ma_liste;
    struct couleur couleurs[10] = {
        {0xFF, 0x00, 0x00, 0xFF}, /* rouge */
        {0x00, 0xFF, 0x00, 0xFF}, /* vert */
        {0x00, 0x00, 0xFF, 0xFF}, /* bleu */
        {0xFF, 0xFF, 0x00, 0xFF}, /* jaune */
        {0x00, 0xFF, 0xFF, 0xFF}, /* cyan */
        {0xFF, 0x00, 0xFF, 0xFF}, /* magenta */
        {0xFF, 0xFF, 0xFF, 0xFF}, /* blanc */
        {0x00, 0x00, 0x00, 0xFF}, /* noir */
        {0x80, 0x80, 0x80, 0xFF}, /* gris */
        {0xEF, 0x78, 0x12, 0x80}  /* orange semi-transparent */
    };

    init_liste(&ma_liste);
    for (int i = 0; i < 10; i++) {
        insertion(&couleurs[i], &ma_liste);
    }

    printf("Liste des couleurs :\n");
    parcours(&ma_liste);
    liberer_liste(&ma_liste);
}

int main(void) {
    int choix;

    do {
        printf("\n===== TP4 =====\n");
        printf("1. Exercice 4.1 : calcul avec opérateurs\n");
        printf("2. Exercice 4.2 : gestion de fichiers\n");
        printf("3. Exercice 4.7 : liste de couleurs\n");
        printf("0. Quitter\n");
        printf("Choisissez l'exercice : ");
        if (scanf("%d", &choix) != 1) {
            printf("Saisie invalide\n");
            return 1;
        }

        switch (choix) {
            case 1:
                exercice_operateurs();
                break;
            case 2:
                exercice_fichiers();
                break;
            case 3:
                exercice_liste();
                break;
            case 0:
                printf("Au revoir !\n");
                break;
            default:
                printf("Choix invalide\n");
        }
    } while (choix != 0);

    return 0;
}
