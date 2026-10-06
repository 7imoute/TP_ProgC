#ifndef REPERTOIRE_H
#define REPERTOIRE_H

/* Exercice 5.1 : affiche les fichiers et repertoires d'un dossier */
void lire_dossier(char *nom_repertoire);

/* Exercice 5.2 : affiche recursivement le contenu d'un dossier et de ses sous-dossiers */
void lire_dossier_recursif(char *nom_repertoire);

/* Exercice 5.3 : meme resultat que 5.2 mais avec une boucle (sans recursion) */
void lire_dossier_iteratif(char *nom_repertoire);

#endif
