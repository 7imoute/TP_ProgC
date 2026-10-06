#include <stdio.h>
#include <stdlib.h>
#include "liste.h"

void init_liste(struct liste_couleurs *liste) {
    liste->tete = NULL;
    liste->taille = 0;
}

/* Insere une copie de la couleur a la fin de la liste */
void insertion(struct couleur *c, struct liste_couleurs *liste) {
    struct element *nouveau = malloc(sizeof(struct element));
    struct element *courant;

    if (nouveau == NULL) {
        printf("Erreur : allocation memoire impossible\n");
        return;
    }
    nouveau->couleur = *c;
    nouveau->suivant = NULL;

    if (liste->tete == NULL) {
        liste->tete = nouveau;
    } else {
        courant = liste->tete;
        while (courant->suivant != NULL) {
            courant = courant->suivant;
        }
        courant->suivant = nouveau;
    }
    liste->taille++;
}

void parcours(struct liste_couleurs *liste) {
    struct element *courant = liste->tete;
    int i = 1;

    while (courant != NULL) {
        printf("Couleur %d : R=0x%02x G=0x%02x B=0x%02x A=0x%02x\n", i,
               courant->couleur.r, courant->couleur.g,
               courant->couleur.b, courant->couleur.a);
        courant = courant->suivant;
        i++;
    }
}

void liberer_liste(struct liste_couleurs *liste) {
    struct element *courant = liste->tete;
    struct element *suivant;

    while (courant != NULL) {
        suivant = courant->suivant;
        free(courant);
        courant = suivant;
    }
    liste->tete = NULL;
    liste->taille = 0;
}
