#include <stdio.h>

#define NB_ETUDIANTS 5

int main() {
    char noms[NB_ETUDIANTS][2][30] = {
        {"Dupont", "Marie"},
        {"Martin", "Pierre"},
        {"Durand", "Sophie"},
        {"Bernard", "Lucas"},
        {"Petit", "Emma"}
    };
    char adresses[NB_ETUDIANTS][100] = {
        "20, Boulevard Niels Bohr, Lyon",
        "22, Boulevard Niels Bohr, Lyon",
        "5, Rue de la Republique, Paris",
        "12, Avenue Victor Hugo, Marseille",
        "8, Place Bellecour, Lyon"
    };
    float notesProgC[NB_ETUDIANTS] = {16.5, 14.0, 12.5, 18.0, 10.75};
    float notesSE[NB_ETUDIANTS] = {12.1, 14.1, 15.0, 11.5, 13.25};

    for (int i = 0; i < NB_ETUDIANTS; i++) {
        printf("Etudiant.e %d :\n", i + 1);
        printf("Nom : %s\n", noms[i][0]);
        printf("Prenom : %s\n", noms[i][1]);
        printf("Adresse : %s\n", adresses[i]);
        printf("Note Programmation en C : %.2f\n", notesProgC[i]);
        printf("Note Systeme d'exploitation : %.2f\n\n", notesSE[i]);
    }
    return 0;
}
