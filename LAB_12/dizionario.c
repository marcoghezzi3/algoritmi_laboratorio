#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define N 4
#define HASHSIZE 10


typedef struct {
  char *word;
  int *ln_arr;
  int ln_alloc;
  int ln_occup;
} Item;

Item *new_item(char *w, int ln);
void item_modify(Item *p, int ln);
void item_print(Item *h);

struct element {
  Item *item;
  struct element *next;
};

typedef struct element *Chain;
Item *chain_find(Chain c, char *w);
Chain chain_insert(Chain c, Item *p);
void chain_print(Chain h);

typedef struct ht{
  Chain array[HASHSIZE];
  int count; //parole inserite
} *Dict;

Dict dict_init();
unsigned long hash (char *str);
Item *dict_lookup(Dict t, char *w);
void dict_add(Dict t, Item *p);
void dict_print(Dict h);


char* read_line(int *acapo);
void line (Dict t, int ln);
char *read_word();


int main(int argc, char const *argv[]) {
  char *word;
  int ln = 0;
  Dict diz = dict_init();
  char selezione;
  Item *vocabolo;
  while((selezione = getchar())!= 'f') {
    switch (selezione) {
      case '+':
          ln++;
          line(diz, ln);
          break;
      case '?':
          scanf("%s", word);
          vocabolo = dict_lookup(diz, word);
          if (vocabolo != NULL){
              item_print(vocabolo);
          }
          else
              printf("vocabolo non presente nel dizionario!\n");
          break;
      case 'l':
          printf("[l] Lette %d righe\n", ln);
          break;
      case 'n':
          printf("[n] Lette %d parole distinte\n", diz -> count);

          break;
      case 'p':
          dict_print(diz);
          break;
    }
  }
  return 0;
}

//ITEM
Item *new_item(char *w, int ln) {
  Item *p = malloc(sizeof(Item));
  p -> word = w;
  p -> ln_arr = malloc(N*sizeof(int));
  p -> ln_arr[0] = ln;
  p -> ln_alloc = N;
  p -> ln_occup = 1;

  return p;
}

void item_modify(Item *p, int ln) {
  if (p -> ln_arr[p -> ln_occup-1] == ln)   //controllo che l'ultima posizione non sia la riga ln
    return;
  if (p -> ln_alloc <= p -> ln_occup) {
    p -> ln_alloc *= 2;
    p -> ln_arr = realloc(p -> ln_arr, p -> ln_alloc * sizeof(int));
  }
  p -> ln_arr[p -> ln_occup++] = ln;    //prima assegno a ln_occup e poi incremento di 1
}

void item_print(Item *h) {

  printf("%s: ", h -> word);
  for (int i = 0; i < h -> ln_occup; i++)
    printf("%d ", h -> ln_arr[i]);
  printf("\n");
}


//CATENE COLLISIONE
Item *chain_find(Chain c, char *w) {
  for ( ; c!=NULL; c = c -> next) {
    if (strcmp(c -> item -> word, w) == 0)
      return c -> item;
  }
  return NULL;
}

Chain chain_insert(Chain c, Item *p) {
  Chain new = malloc(sizeof(Chain));
  new -> item = p;
  new -> next = c;
  return new;
}

void chain_print(Chain c) {
  if (c == NULL)
    return;
  while(c) {
    item_print(c -> item);
    c = c -> next;
  }
}

//DIZIONARIO
Dict dict_init() {
  Dict d = malloc(sizeof(Dict));
  d -> count = 0;
  for (int i = 0; i < HASHSIZE; i++)
    d -> array[i] = NULL;
  return d;
}

unsigned long hash (char *str) {
  unsigned long hash = 5381;
  int c;

  while ((c = *str++))
    hash = ((hash < 5) + hash) + c;

  return hash % HASHSIZE;
}

Item *dict_lookup(Dict t, char *w) {
  return chain_find(t -> array[hash(w)], w);
}

void dict_add(Dict t, Item *p) {
  int i = hash(p -> word);
  t -> array[i] = chain_insert(t -> array[i], p);
  t -> count++;
}

void dict_print(Dict h) {
  for (int i = 0; i < HASHSIZE; i++) {
    printf("%d: ", i);
    chain_print(h -> array[i]);
    printf("\n");
  }
}

//FUNZIONI GENERICHE
char *read_word() {
  char c;
  int flag = 0;
  int i = 0;
  int size = 2;
  char* parola = malloc(size * sizeof(char));

  while (isalpha(c = getchar()) != 0 || c == '\n') {
      if (c == ' ')
          printf("!!!!!!!!!!!!!!!!!!!!!");
      if (i >= size){
          size *= 2;
          parola = realloc(parola, size * sizeof(char));
      }
      parola[i++] = tolower(c);
      flag = 1;
      if (c == '\n'){
          break;
      }
  }
  parola[i] = '\0';
  if (flag != 0)
      return parola;
  else
      return read_word();
}

char* read_line(int *acapo){
    int i;
    char *parola = read_word();
    for (i =0; i<strlen(parola); i++){
        if (parola[i] == '\n' && strlen(parola) == 1){
            *acapo = 1;
            return NULL;
        }
        if (parola[i] == '\n'){
            *acapo = 1;
            parola[i] = '\0';
        }
    }
    return parola;
}

void line(Dict t, int ln) {
  char* w;
  int flag = 0;
  while(1){
      w = read_line(&flag);
      if (w == NULL){
          break;
      }
      Item *nuovo = new_item(w, ln);
      if (dict_lookup(t, nuovo -> word)){
          item_modify(dict_lookup(t, nuovo -> word), ln);
          free(nuovo);
      }
      else {
          dict_add(t, nuovo);
      }
      if (flag == 1)
          break;
  }
}
