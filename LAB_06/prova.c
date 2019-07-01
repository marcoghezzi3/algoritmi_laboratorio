#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  char **name;
} registro;

void *newBook(registro *reg, int n);
void book(registro *reg, int k, char *name);
void printBook(registro *reg, int n);

int main(int argc, char const *argv[]) {
  registro *reg;
  char *name, ch;
  int n, k;
  /*reg = newBook(reg, 10);
  book(reg, 2, "marco");
  printBook(reg, 10);*/
  while((ch = getchar())!='f') {
    switch (ch) {
      case 'b':
        scanf("%d", &n);
        reg=newBook(reg, n);
        break;
      case '+':
        name = malloc(15*sizeof(char));
        scanf("%d %s", &k, name);
        book(reg, k, name);
        break;

    }
  }
  return 0;
}

void *newBook(registro *reg, int n) {
  registro *tmp = malloc(sizeof(registro));
  if (tmp!=NULL) {
    tmp->name = calloc(n, sizeof(char*));
    return tmp;
  }
  else
    return reg;
}

void book(registro *reg, int k, char *name) {
  if ((reg->name[k])==NULL) {
    reg->name[k]=realloc(reg->name[k], sizeof(name)+1);
    strcpy(reg->name[k], name);
    printf("Prenotazione avvenuta\n");
  }
  else
    printf("Prenotazione rifiutata\n");
}

void printBook(registro *reg, int n) {
  for (int i = 0; i < n; i++)
    if(reg->name[i])
      printf("%d-->%s\n", i, reg->name[i]);
}
