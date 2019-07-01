#include <stdio.h>
#include <stdlib.h>

/*
L'idea è quella di utilizzare un grafo non orientato i cui nodi sono i punti di erogazione
e gli archi le tubature che collegano i vari punti. Le aree in cui vengono suddivisi i punti
in caso di tossicità, sono paragonabili alle componenti connesse di un grafo.
*/

struct node {
  int item;
  struct node *next;
};

struct graph {
  int n, m;
  struct node **A;
};
typedef struct graph *Graph;

Graph nuova_tubatura(int n);
void inserisci_stazione(Graph g, int v, int w);
Graph leggi_tubatura(void);
void stampa_tubatura(Graph g);
struct node *stacca_tubatura(struct node *lista, int i);
struct node *elimina_lista(struct node *lista);
void elimina_stazione(Graph g, int n);
void dfs(Graph g, int i, int *aux, int print);
int comp_connesse(Graph g);
void stampa_connesse(Graph g, int n);

int main() {
  Graph g = leggi_tubatura();
  int *valori = calloc(g -> n, sizeof(int));
  printf("\n");
  int soglia;
  scanf("%d", &soglia);
  for (int i = 0; i < g -> n; i++)
    scanf("%d", &valori[i]);
  for (int i = 0; i < g -> n; i++) {
    if (valori[i] > soglia)
      elimina_stazione(g, i);
  }
  printf("\n");
  int n;
  scanf("%d", &n);
  int ccc = comp_connesse(g);
  printf("%d\n", ccc);
  stampa_connesse(g, n);
  //stampa_tubatura(g);
  return 0;
}

Graph nuova_tubatura(int n) {
  Graph new = malloc(sizeof(struct graph));
  if (!new) {
    printf("Errore allocazione");
    exit(-1);
  }
  new -> n = n;
  new -> m = 0;
  new -> A = calloc(n, sizeof(struct node));
  return new;
}

void inserisci_stazione(Graph g, int v, int w) {
  struct node *tmp = malloc(sizeof(struct node));
  tmp -> item = w;
  tmp -> next = g -> A[v];
  g -> A[v] = tmp;
}

Graph leggi_tubatura(void) {
  int n, m, v, w;
  printf("Inserisci numero punti e numero tubazioni (>0): ");
  scanf("%d %d", &n, &m);
  Graph new = nuova_tubatura(n);
  new -> m = m;
  printf("Inserisci collegamento tubature: \n");
  for (int i = 0; i < m; i++) {
    scanf("%d %d", &v, &w);
    inserisci_stazione(new, v, w);
    inserisci_stazione(new, w, v);
  }
  return new;
}

void stampa_tubatura(Graph g) {
  for (int i = 0; i < g -> n; i++) {
    struct node *tmp = g ->A[i];
    if (tmp!=NULL) {
      printf("%d: ", i);
      while(tmp!=NULL) {
        printf("%d, ", tmp -> item);
        tmp = tmp -> next;
      }
      printf("\n");
    }
  }
}

struct node *stacca_tubatura(struct node *lista, int i) {
  struct node *tmp;
  struct node *prev;
  for (tmp = lista, prev = NULL; tmp && tmp -> item != i; prev = tmp, tmp = tmp -> next);
  if (tmp == NULL)
    return lista;
  if (tmp == lista)
    lista -> item = -1;
  else
    tmp -> item = -1;
  return lista;
}

struct node *elimina_lista(struct node *lista) {
  struct node *tmp = lista;
  struct node *next;
  while (tmp) {
    next = tmp -> next;
    tmp = stacca_tubatura(tmp, tmp -> item);
    tmp = next;
  }
  return NULL;
}

void elimina_stazione(Graph g, int n) {
  for (int i = 0; i < g -> n; i++) {
    if (i != n)
      g -> A[i] = stacca_tubatura(g -> A[i], n);
    else
      g -> A[i] = elimina_lista(g -> A[i]);
  }
}

void dfs(Graph g, int i, int *aux, int print) {
  struct node *tmp;
  aux[i] = 1;
  for (tmp = g -> A[i]; tmp; tmp = tmp -> next) {
    if (!aux[tmp -> item] && tmp -> item!=-1) {
      if (print)
        printf("%d ", tmp -> item);
      dfs(g, tmp->item, aux, print);
    }
  }
}

int comp_connesse(Graph g) {
  int count = 0;
  int *aux = calloc(g -> n, sizeof(int));
  for (int i = 0; i < g -> n; i++) {
    if (g -> A[i]) {
      if (!aux[i]) {
        count ++;
        dfs(g, i, aux, 0);
      }
    }
  }
  return count;
}

void stampa_connesse(Graph g, int n) {
  int *aux = calloc(g -> n, sizeof(int));
  printf("%d ", n);
  dfs(g, n, aux, 1);
  printf("\n");
}
