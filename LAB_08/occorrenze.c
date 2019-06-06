#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <ctype.h>
#define N 50

struct occorrenza {
  char* word;
  int n;
};
typedef struct occorrenza Occorrenza;

struct bit_node {
  Occorrenza *item;
  struct bit_node *l, *r;
};
typedef struct bit_node *Bit_node;

Bit_node bit_new(char* word);
void bit_printnode(Bit_node p);
Bit_node bit_search(Bit_node p, char* word);
void bist_orderprint(Bit_node p);
void bist_insert(Bit_node* p, char* word);
void bist_inorderprint(Bit_node p);

int main(int argc, char const *argv[]) {
  char a[N], c;
  Bit_node root = NULL;
  char *stop = "STOP";
  while (strcmp(stop, a)!=0) {
    scanf("%s", a);
    char *tmp = malloc(strlen(a));
    strcpy(tmp, a);
    if (strcmp(stop, tmp)==0)
      break;
    for (int i = 0; i < strlen(tmp); i++)
      tmp[i] = tolower(tmp[i]);
    bist_insert(&root, tmp);
  }
  printf("OCCORRENZE DI PAROLE NEL TESTO IN ORDINE ALFABETICO:\n");
  printf("****************************************************\n");
  bist_orderprint(root);
  printf("\nOCCORRENZE DI PAROLE NEL TESTO IN ORDINE INVERSO:\n");
  printf("*************************************************\n");
  bist_inorderprint(root);
  return 0;
}

Bit_node bit_new(char* word) {
  Bit_node root;
  root = malloc(sizeof(struct bit_node));
  root -> item = malloc(sizeof(struct occorrenza));
  root-> item -> word = word;
  root-> item -> n = 1;
  root -> l = NULL;
  root -> r = NULL;
  return root;
}

void bit_printnode(Bit_node p) {
  printf("%s %d\n", p->item->word, p->item->n);
}

Bit_node bit_search(Bit_node p, char* k) {
  int res;
  while (p && (res = strcmp(k, p -> item -> word)) != 0)
    p = res < 0 ? p -> l : p -> r;
  if ( p == NULL )
    return NULL;
  else
    return p;
}

void bist_orderprint(Bit_node p) {
  if (p) {
    bist_orderprint(p->l);
    bit_printnode(p);
    bist_orderprint(p->r);
  }
}

void bist_insert(Bit_node* p, char* word) {
  Bit_node parent, q = *p, new = bit_new(word);
  Bit_node presente = bit_search(q, word);
  /* se l’albero e’ vuoto: */
  if ( q == NULL ) {
    *p = new;
    return;
  }
  /* se la chiave c’e’ gia’ , incremento il valore di n di quella chiave: */
  if (presente) {
    presente -> item -> n += 1;
    return;
  }

  while (q!=NULL) {
    if (strcmp(word, q -> item -> word)<0) {   //se in ordine alfabetico la parola viene prima, devo inserirla prima
      parent = q;
      q = q -> l;
    }
    else {
      parent = q;
      q = q -> r;
    }
  }
  /* altrimenti inserisco il nuovo nodo come figlio di parent: */
  if (strcmp (word, parent -> item -> word) < 0)
    parent -> l = new;
  else
    parent -> r = new;
}

void bist_inorderprint(Bit_node p) {
  if(p) {
    bist_inorderprint(p->r);
    bit_printnode(p);
    bist_inorderprint(p->l);
  }
}
