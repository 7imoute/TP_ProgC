/*
 * SPDX-FileCopyrightText: 2021 John Samuel
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 *
 */

#ifndef __SERVER_H__
#define __SERVER_H__

#define PORT 8089

/* accepter la nouvelle connection d'un client et lire les données
 * envoyées par le client. En suite, le serveur envoie un message
 * en retour
 */
int renvoie_message(int, char *);

/* Exercice 5.4 : affiche le message reçu, demande une réponse
 * à l'utilisateur du serveur et l'envoie au client
 */
int recois_envoie_message(int client_socket_fd, char *data);

/* Exercice 5.5 : reçoit "calcule : <op> <num1> [<num2>]",
 * effectue le calcul et renvoie "calcule : <resultat>" au client
 */
int recois_numeros_calcule(int client_socket_fd, char *data);

#endif
