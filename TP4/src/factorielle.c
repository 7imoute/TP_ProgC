#include <stdio.h>

// Définition de la fonction factorielle
int factorielle(int num) {
  if (num == 0) {
    printf("fact(0): 1\n");
    return 1;
  } else {
    int valeur = num * factorielle(num - 1);
    printf("fact(%d): %d\n", num, valeur);
    return (valeur);
  }
}

int main() {
  int n;
  int valeurs[] = {0, 1, 5, 7, 10, 12};
  int nb_valeurs = sizeof(valeurs) / sizeof(valeurs[0]);

  // Testez la fonction factorielle avec différentes valeurs d'entiers naturels
  for (int i = 0; i < nb_valeurs; i++) {
    n = valeurs[i];
    printf("--- Calcul de %d! ---\n", n);
    printf("%d! = %d\n\n", n, factorielle(n));
  }

  return 0;
}
