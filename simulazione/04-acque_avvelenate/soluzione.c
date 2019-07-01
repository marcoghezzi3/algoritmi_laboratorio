#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
l'idea è l'implementazione di un grafo utilizzando le liste di adiacenza
*/

struct listnode {
  int item;
  struct listnode *next;
};
typedef struct listnode *Lista;

struct hydrograph {
  int n, m;
  struct listnode **A;
};
typedef struct hydrograph *Graph;


Graph new_system(int n);
void insert_stations(Graph g, int v, int w );
Graph read_stations( void );
void print_stations( Graph s );
Lista insertList(Lista l,int v);
int isMember(Lista l, int i);

int main(int argc, char const *argv[]) {
  Graph g = read_stations();
  print_stations(g);
  return 0;
}

Graph new_system(int n) {
  Graph g = malloc(sizeof(struct hydrograph));
  if (!g) {
    printf("Errore allocazione\n");
    exit(-1);
  }
  g -> n = n;
  g -> A = calloc(n, sizeof(struct listnode));
  return g;
}

Lista insertList(Lista l, int v) {
  Lista new = malloc(sizeof(struct listnode));
  new -> item = v;
  new -> next = l;
  return new;
}

void insert_stations(Graph g, int v, int w) {
    g->A[v] = insertList(g->A[v],w); //
    if ( v != w )
    g->A[w] = insertList(g->A[w],v);
}

Graph read_stations(void) {
  int n, m, i, v, w;
	Graph s;
	scanf( "%d", &n );
	s = new_system(n);
	scanf( "%d", &m );
	s -> m = m;
	for (i = 0; i < m; i++) {
		scanf( "%d %d", &v, &w );
		insert_stations(s, v, w);
	}
	return s;
}

void print_stations( Graph g ){
  printf("n: %d, m: %d\n", g->n, g->m);
  for (int i = 0; i < g -> n; i++) {
    Lista new = g -> A[i];
    if (new != NULL) {
      printf("Stazione %d: ", i);
      while (new != NULL) {
        printf("%d, ", new -> item);
        new = new -> next;
      }
      printf("\n");
    }

  }
}

int isMember(Lista l, int i) {
  int c = 0;
  while (l != NULL) {
    if (l -> item == i)
      c = 1;
    l = l -> next;
  }
  return c;
}

Lista delete_node (Lista l, int n) {
  if (isMember(l, n)) {
    Lista prev, tmp;
    for (tmp=l, prev=NULL; tmp!=NULL && tmp->item!=n; prev = tmp, tmp = tmp -> next);
    if (tmp==NULL)
      return l;
    if (prev==NULL)
      l -> item = -1;
    else
      tmp -> item = -1;
    return l;
  }
  return l;
}

Lista list_free(Lista l) {
  Lista tmp = l;
  Lista next;
  while(tmp){
    next = tmp->next;
    tmp = delete_node(tmp,tmp->item);
    tmp=next;
  }
  return NULL;
}

void dfs(Graph g, int i, int *aux){
  if(g){
    Lista l;
    aux[i]=1;
    for(l=g->A[i];l;l=l->next){
      if(!aux[l->item] && l->item!=-1)
        dfs(g,l->item,aux);
    }
  }
}

int comp_connesse(graph g){
  int ccc=0;
  if(g){
    int *aux = calloc(g->n,sizeof(int));
    for(int i=0;i<g->n;i++){
      if(!aux[i] && g->A[i]){
        ccc++;
        dfs(g,i,aux);
      }
    }
  }
  return ccc;
}
