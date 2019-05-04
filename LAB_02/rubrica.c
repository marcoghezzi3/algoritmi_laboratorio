#include <stdio.h>
#include <ctype.h>
#define N 50

typedef struct {
  char nome[15];
  char numero[N];
} Contatto;

int main(int argc, char const *argv[]) {
  Contatto rubrica[N];
  int select, counter = 0;
  while (select != 3) {
    printf("\tGestione Rubrica.\n1. Visualizza rubrica\n2. Inserisci numero\n3. Esci\nCosa vuoi fare: ");
    scanf(" %d", &select);
    switch (select) {
      case 1: printf("\n\n");
              for (int i = 0; i < counter; i++) {
                  printf("%d:%s %s\n", i, rubrica[i].nome, rubrica[i].numero);
              }
              printf("\n\n\n");
              break;
      case 2: printf("Inserisci nome: ");
              scanf(" %s", rubrica[counter].nome);
              printf("Inserisci numero: ");
              scanf("%s", rubrica[counter].numero);
              printf("\n");
              counter++;
              break;
    }
  }
  return 0;
}
