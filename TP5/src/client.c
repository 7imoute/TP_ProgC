/*
 * SPDX-FileCopyrightText: 2021 John Samuel
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 *
 */

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

#include "client.h"

#define NB_ETUDIANTS 5
#define NB_NOTES 5

/**
 * Envoie une chaîne au serveur puis lit sa réponse dans reponse.
 * @return 0 en cas de succès, -1 en cas d'erreur.
 */
static int envoie_et_lit(int socketfd, const char *data, char *reponse, size_t taille)
{
    int write_status = write(socketfd, data, strlen(data));
    if (write_status < 0)
    {
        perror("Erreur d'écriture");
        return -1;
    }

    memset(reponse, 0, taille);
    int read_status = read(socketfd, reponse, taille - 1);
    if (read_status < 0)
    {
        perror("Erreur de lecture");
        return -1;
    }
    if (read_status == 0)
    {
        printf("Le serveur a fermé la connexion.\n");
        return -1;
    }
    return 0;
}

/**
 * Exercice 5.5 : envoie une opération de calcul au serveur.
 * Format envoyé : "calcule : + 23 45" (ou "calcule : ~ 5" pour un seul numéro)
 * Format reçu   : "calcule : 68"
 */
int envoie_operateur_numeros(int socketfd, char op, double num1, double num2,
                             int nb_numeros, double *resultat)
{
    char data[1024];
    char reponse[1024];

    if (nb_numeros == 1)
    {
        snprintf(data, sizeof(data), "calcule : %c %g", op, num1);
    }
    else
    {
        snprintf(data, sizeof(data), "calcule : %c %g %g", op, num1, num2);
    }

    if (envoie_et_lit(socketfd, data, reponse, sizeof(reponse)) != 0)
    {
        return -1;
    }

    printf("Message reçu: %s\n", reponse);

    if (sscanf(reponse, "calcule : %lf", resultat) != 1)
    {
        return -1; /* le serveur a renvoyé une erreur */
    }
    return 0;
}

/**
 * Fonction pour envoyer et recevoir un message depuis un client connecté à la socket.
 * Si le message commence par "calcule :", il est envoyé avec envoie_operateur_numeros.
 *
 * @param socketfd Le descripteur de la socket utilisée pour la communication.
 * @return 0 en cas de succès, -1 en cas d'erreur.
 */
int envoie_recois_message(int socketfd)
{
    char data[1024];
    char reponse[1024];

    // Demande à l'utilisateur d'entrer un message
    char message[1001];
    printf("Votre message (max 1000 caractères): ");
    if (fgets(message, sizeof(message), stdin) == NULL)
    {
        return -1; /* fin de l'entrée standard */
    }
    message[strcspn(message, "\n")] = '\0';

    // Exercice 5.5 : message de calcul, ex. "calcule : + 23 45"
    if (strncmp(message, "calcule :", 9) == 0)
    {
        char op;
        double num1, num2, resultat;
        int nb = sscanf(message + 9, " %c %lf %lf", &op, &num1, &num2);

        if (nb == 3)
        {
            return envoie_operateur_numeros(socketfd, op, num1, num2, 2, &resultat);
        }
        if (nb == 2 && op == '~')
        {
            return envoie_operateur_numeros(socketfd, op, num1, 0, 1, &resultat);
        }
        printf("Format attendu : calcule : <op> <num1> <num2>\n");
        return -1;
    }

    // Construit le message avec une étiquette "message: "
    snprintf(data, sizeof(data), "message: %s", message);

    if (envoie_et_lit(socketfd, data, reponse, sizeof(reponse)) != 0)
    {
        return -1;
    }

    // Affiche le message reçu du serveur
    printf("Message reçu: %s\n", reponse);

    return 0; // Succès
}

/**
 * Lit une note (nombre) dans un fichier.
 * @return 0 en cas de succès, -1 en cas d'erreur.
 */
static int lire_note(const char *chemin, double *note)
{
    FILE *f = fopen(chemin, "r");
    if (f == NULL)
    {
        perror(chemin);
        return -1;
    }
    int ok = fscanf(f, "%lf", note);
    fclose(f);
    if (ok != 1)
    {
        printf("Note invalide dans %s\n", chemin);
        return -1;
    }
    return 0;
}

/**
 * Exercice 5.6 : le client lit les notes, le serveur ne fait que les calculs.
 * Pour chaque étudiant.e :
 *   "+ note1 note2" -> somme, "+ somme note3" -> somme, ... , "/ somme 5" -> moyenne
 * Puis pour la classe : somme des moyennes, puis "/ somme 5".
 */
int calcule_notes(int socketfd, const char *dossier)
{
    double notes[NB_NOTES];
    double moyennes[NB_ETUDIANTS];
    double somme, moyenne_classe;
    char chemin[512];

    for (int e = 0; e < NB_ETUDIANTS; e++)
    {
        for (int n = 0; n < NB_NOTES; n++)
        {
            snprintf(chemin, sizeof(chemin), "%s/%d/note%d.txt", dossier, e + 1, n + 1);
            if (lire_note(chemin, &notes[n]) != 0)
            {
                return -1;
            }
        }

        printf("\n=== Étudiant.e %d ===\n", e + 1);

        // "+ note1 note2"
        if (envoie_operateur_numeros(socketfd, '+', notes[0], notes[1], 2, &somme) != 0)
            return -1;
        // "+ somme note3", "+ somme note4", "+ somme note5"
        for (int n = 2; n < NB_NOTES; n++)
        {
            if (envoie_operateur_numeros(socketfd, '+', somme, notes[n], 2, &somme) != 0)
                return -1;
        }
        printf("Somme des notes : %g\n", somme);

        // "/ somme 5"
        if (envoie_operateur_numeros(socketfd, '/', somme, NB_NOTES, 2, &moyennes[e]) != 0)
            return -1;
        printf("Moyenne : %g\n", moyennes[e]);
    }

    printf("\n=== Classe ===\n");
    somme = moyennes[0];
    for (int e = 1; e < NB_ETUDIANTS; e++)
    {
        if (envoie_operateur_numeros(socketfd, '+', somme, moyennes[e], 2, &somme) != 0)
            return -1;
    }
    if (envoie_operateur_numeros(socketfd, '/', somme, NB_ETUDIANTS, 2, &moyenne_classe) != 0)
        return -1;
    printf("Moyenne de la classe : %g\n", moyenne_classe);

    return 0;
}

/*
 * Utilisation :
 *   ./client                       -> mode interactif (5.4 et 5.5)
 *   ./client notes [dossier]       -> calcul des notes (5.6), dossier par défaut : ../etudiant
 */
int main(int argc, char *argv[])
{
    int socketfd;

    struct sockaddr_in server_addr;

    /*
     * Creation d'une socket
     */
    socketfd = socket(AF_INET, SOCK_STREAM, 0);
    if (socketfd < 0)
    {
        perror("socket");
        exit(EXIT_FAILURE);
    }

    // détails du serveur (adresse et port)
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    server_addr.sin_addr.s_addr = INADDR_ANY;

    // demande de connection au serveur
    int connect_status = connect(socketfd, (struct sockaddr *)&server_addr, sizeof(server_addr));
    if (connect_status < 0)
    {
        perror("connection serveur");
        exit(EXIT_FAILURE);
    }

    if (argc >= 2 && strcmp(argv[1], "notes") == 0)
    {
        const char *dossier = (argc >= 3) ? argv[2] : "../etudiant";
        int statut = calcule_notes(socketfd, dossier);
        close(socketfd);
        return statut == 0 ? EXIT_SUCCESS : EXIT_FAILURE;
    }

    while (1)
    {
        // appeler la fonction pour envoyer un message au serveur
        if (envoie_recois_message(socketfd) != 0 && feof(stdin))
        {
            break;
        }
    }

    close(socketfd);
    return 0;
}
