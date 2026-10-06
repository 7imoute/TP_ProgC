#ifndef OPERATOR_H
#define OPERATOR_H

int somme(int num1, int num2);
int difference(int num1, int num2);
int produit(int num1, int num2);
int quotient(int num1, int num2);
int modulo(int num1, int num2);
int et(int num1, int num2);
int ou(int num1, int num2);
int negation(int num1, int num2); /* ~num1, num2 est ignore */

/* Selectionne l'operation avec un switch. Renvoie 0 si succes, -1 si erreur. */
int calculer(char op, int num1, int num2, int *resultat);

#endif
