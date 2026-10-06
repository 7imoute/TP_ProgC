#ifndef LISTE_H
#define LISTE_H

struct couleur {
    unsigned char r;
    unsigned char g;
    unsigned char b;
    unsigned char a;
};

/* Element (noeud) de la liste simplement chainee */
struct element {
    struct couleur couleur;
    struct element *suivant;
};

struct liste_couleurs {
    struct element *tete;
    int taille;
};

void init_liste(struct liste_couleurs *liste);
void insertion(struct couleur *c, struct liste_couleurs *liste);
void parcours(struct liste_couleurs *liste);
void liberer_liste(struct liste_couleurs *liste);

#endif
