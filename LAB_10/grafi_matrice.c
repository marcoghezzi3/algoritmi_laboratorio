#include <stdio.h>
#include <stdlib.h>

struct graph {
  int n, m;
  int **A;
};
typedef struct graph *Graph;
/* crea un grafo con n nodi */
Graph graph_new(int n );
/* distrugge il grafo g */
void graph_destroy(Graph g );
/* inserisce l’arco (v,w) nel grafo g */
void graph_edgeinsert(Graph g, int v, int w );
/* legge da standard input un grafo (specificare il formato!!) */
Graph graph_read(Graph g, FILE *fp);
/* stampa su standard output un grafo (specificare il formato!!) */
void graph_print(Graph g);

int main(int argc, char const *argv[]) {
  Graph g;
  g = graph_new(10);
  graph_destroy(g);
  FILE *fp = fopen("input.txt", "r");
  g = graph_read(g, fp);
  graph_print(g);
  return 0;
}

Graph graph_new(int n) {
  int i;
  Graph g = malloc(sizeof(struct graph));
  if (!g) {
    printf("Errore di allocazione\n");
    exit(-1);
  }
  g -> A = calloc(n, sizeof(int*));
  for (i = 0; i < n; i++)
    g -> A[i] = calloc(n, sizeof(int));
  g -> n = n;
  return g;
}

void graph_destroy(Graph g) {
  for(int i = 0; i < g -> n; i++) {
    int *j = g -> A[i];
    free(j);
  }
  free(g);
}

void graph_edgeinsert(Graph g, int v, int w) {
  g -> A[v][w] = 1;
  g -> A[w][v] = 1;
  g -> m += 1;
}

Graph graph_read(Graph g, FILE *fp) {
  int v, w;
  while (fscanf(fp, "%d %d", &v, &w)!=EOF) {
    //fscanf(fp, "%d %d", &v, &w);
    graph_edgeinsert(g, v, w);
    //printf("%d %d\n", v, w);
  }
  return g;
}

void graph_print(Graph g) {
  for (int i = 1; i < g -> n; i++) {
    for (int j = 1; j < g -> n; j++)
      printf("%d ", g -> A[i][j]);
    printf("\n");
  }
}
