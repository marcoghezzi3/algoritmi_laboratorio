#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void *newBook(char **book, int n);
void book(char **book, int k, char *name);
void cancel(char **book, int k);
void move(char **book, int from, int to);
void printBook(char **book, int n);

int main(int argc, char const *argv[]) {
  char **registro, ch;
  char *name;
  int n, k;
  int from, to;
  while((ch = getchar())!='f') {
    switch (ch) {
      case 'b':           // n --> nuovo registro di n posti
        scanf("%d", &n);
        registro=newBook(registro, n);
        break;
      case '+':           // k, name --> prenota a nome di name il posto k se è libero
        name = malloc(20*sizeof(char));
        scanf("%d %s", &k, name);
        book(registro, k, name);
        break;
      case '-':
        scanf("%d", &k);  // k --> cancella la prenotazione al posto k
        cancel(registro, k);
        break;
      case 'm':           // from, to --> sposta il cliente da from a to se è possibile
        scanf("%d %d", &from, &to);
        move(registro, from, to);
        break;
      case 'p':           // n --> stampa il registro di n posti
        printBook(registro, n);
        break;

    }
  }
  //registro = newBook(registro, 10);
  //book(registro, 2, "marco");
  return 0;
}

void *newBook(char **book, int n) {
  free(book);
  book = calloc(n, sizeof(char*));
  if (book!=NULL);
    //printf("Allocazione effettuata\n");
  else
    printf("Allocazione non avvenuta\n");
  return book;
}

void book(char **book, int k, char *name) {
  if (book[k]==NULL) {
    book[k]=realloc(book[k], sizeof(name)+1);
    strcpy(book[k], name);
    //printf("Prenotazione avvenuta\n");
  }
  else
    printf("Prenotazione rifiutata\n");
}

void cancel(char **book, int k) {
  if (book[k]!=NULL) {
    book[k]=NULL;
    //printf("Cancellazione effettuata\n");
  }
  else
    printf("Posto %d libero\n", k);
}

void move(char **book, int from, int to) {
  if (book[from]!=NULL && book[to]==NULL) {
    book[to]=book[from];
    book[from]=NULL;
    //printf("Cliente spostato\n");
  }
  else
    printf("move(%d, %d): errore\n", from, to);
}

void printBook(char **book, int n) {
  printf("\nREGISTER[0..%d]\n", n-1);
  for (int i = 0; i < n; i++)
    if(book[i])
      printf("%d-->%s\n", i, book[i]);
  printf("\n");
}
