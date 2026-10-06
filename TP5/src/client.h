/*
 * SPDX-FileCopyrightText: 2021 John Samuel
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 *
 */

#ifndef __CLIENT_H__
#define __CLIENT_H__

/*
 * port d'ordinateur pour envoyer et recevoir des messages
 */
#define PORT 8089

/*
 * Fonction d'envoi et de réception de messages
 * Il faut un argument : l'identifiant de la socket
 */
int envoie_recois_message(int socketfd);

/*
 * Exercice 5.5 : envoie "calcule : <op> <num1> [<num2>]" au serveur,
 * lit la réponse "calcule : <resultat>" et renvoie le résultat dans *resultat.
 * nb_numeros vaut 1 (ex : ~) ou 2.
 * Renvoie 0 en cas de succès, -1 en cas d'erreur.
 */
int envoie_operateur_numeros(int socketfd, char op, double num1, double num2,
                             int nb_numeros, double *resultat);

/*
 * Exercice 5.6 : lit les notes des étudiants dans le dossier
 * <dossier>/<1..5>/note<1..5>.txt et demande au serveur de calculer
 * la somme et la moyenne de chaque étudiant ainsi que la moyenne de la classe.
 */
int calcule_notes(int socketfd, const char *dossier);

#endif
