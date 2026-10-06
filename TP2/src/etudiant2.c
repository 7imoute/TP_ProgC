#include <stdio.h>
#include <string.h>

#define NB_ETUDIANTS 5

struct Etudiant {
    char nom[30];
    char prenom[30];
    char adresse[100];
    float note1; /* Programmation en C */
    float note2; /* Systeme d'exploitation */
};

int main() {
    struct Etudiant etudiants[NB_ETUDIANTS];

    strcpy(etudiants[0].nom, "Dupont");
    strcpy(etudiants[0].prenom, "Marie");
    strcpy(etudiants[0].adresse, "20, Boulevard Niels Bohr, Lyon");
    etudiants[0].note1 = 16.5;
    etudiants[0].note2 = 12.1;

    strcpy(etudiants[1].nom, "Martin");
    strcpy(etudiants[1].prenom, "Pierre");
    strcpy(etudiants[1].adresse, "22, Boulevard Niels Bohr, Lyon");
    etudiants[1].note1 = 14.0;
    etudiants[1].note2 = 14.1;

    strcpy(etudiants[2].nom, "Durand");
    strcpy(etudiants[2].prenom, "Sophie");
    strcpy(etudiants[2].adresse, "5, Rue de la Republique, Paris");
    etudiants[2].note1 = 12.5;
    etudiants[2].note2 = 15.0;

    strcpy(etudiants[3].nom, "Bernard");
    strcpy(etudiants[3].prenom, "Lucas");
    strcpy(etudiants[3].adresse, "12, Avenue Victor Hugo, Marseille");
    etudiants[3].note1 = 18.0;
    etudiants[3].note2 = 11.5;

    strcpy(etudiants[4].nom, "Petit");
    strcpy(etudiants[4].prenom, "Emma");
    strcpy(etudiants[4].adresse, "8, Place Bellecour, Lyon");
    etudiants[4].note1 = 10.75;
    etudiants[4].note2 = 13.25;

    for (int i = 0; i < NB_ETUDIANTS; i++) {
        printf("Etudiant.e %d :\n", i + 1);
        printf("Nom : %s\n", etudiants[i].nom);
        printf("Prenom : %s\n", etudiants[i].prenom);
        printf("Adresse : %s\n", etudiants[i].adresse);
        printf("Note 1 : %.1f\n", etudiants[i].note1);
        printf("Note 2 : %.1f\n\n", etudiants[i].note2);
    }
    return 0;
}
