#ifndef FICHIER_H
#define FICHIER_H

/* Affiche le contenu du fichier. Renvoie 0 si succes, -1 si erreur. */
int lire_fichier(char *nom_de_fichier);

/* Ajoute le message (suivi d'un retour a la ligne) a la fin du fichier.
   Renvoie 0 si succes, -1 si erreur. */
int ecrire_dans_fichier(char *nom_de_fichier, char *message);

#endif
