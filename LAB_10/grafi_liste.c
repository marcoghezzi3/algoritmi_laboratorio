#include <stdio.h>
#include <stdlib.h>

struct listnode {
  int n;
  struct listnode *next;
};

struct graph {
  int n, m;
  struct listnode **A;
};
typedef struct graph *Graph;

struct queue {
  int item;
  struct queue *next;
};
typedef struct queue *Queue;
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

struct listnode *vertexinsert(struct listnode *p, int k);
void readgraph(Graph g, FILE *fp);
void dfs1(Graph g, int i, int *aux);
void dfs(Graph g);

Queue createqueue();
void enqueue(Queue q, int n);
int dequeue(Queue q);
void destroyqueue(Queue q);

void bfs1(Graph g, int i, int *aux);
void bfs(Graph g);



int main() {
  Graph g = graph_new(10);
  FILE *fp = fopen("input.txt", "r");
  //readgraph(g, fp);
  g = graph_read(g,fp);
  graph_print(g);
  dfs(g);
  graph_destroy(g);
  return 0;
}

Queue createqueue() {
  return NULL;
}

void enqueue(Queue q, int n) {
  Queue new = malloc(sizeof(struct queue));
  new -> item = n;
  if (!new) {
    printf("Allocazione fallita\n");
    exit(-2);
  }
  else {
    Queue tmp = q;
    while(q->next)
      q = q -> next;
    q -> next = new;
  }
}

int dequeue(Queue q) {
  if (q) {
    int i = q -> item;
    q = q -> next;
    return i;
  }
  else
    return -1;
}

void destroyqueue(Queue q) {
  while(q!=NULL) {
    Queue s = q;
    free(q);
    q = s -> next;
  }
}

Graph graph_new(int n) {
  Graph g = malloc(sizeof(struct graph));
  if (!g) {
    printf("Errore allocazione\n" );
    exit(-1);
  }
  g -> n = n;
  g -> m = 0;
  if (!(g -> A = calloc(n, sizeof(struct listnode*)))) {
    printf("Errore allocazione\n");
    exit(-2);
  }
  return g;
}

void graph_destroy(Graph g) {
  free(g -> A);
  free(g);
}

void graph_edgeinsert(Graph g, int v, int w) {
  struct listnode *new = malloc(sizeof(struct listnode));
  //g -> A[v-1] = malloc(sizeof(struct listnode));
  new -> n = w;
  new ->next = g -> A[v-1];
  g -> A[v-1] = new;
  if(g -> A[v-1]==NULL || new==NULL){
    printf("errore malloc graph_edgeinsert\n");
  }
  g->m ++;

}

Graph graph_read(Graph g, FILE *fp) {
  int v, w;
  while (fscanf(fp, "%d %d", &v, &w)!=EOF) {
    graph_edgeinsert(g, v, w);
    graph_edgeinsert(g, w, v);
  }
  return g;
}

void graph_print(Graph g) {
  for (int i = 0; i < (g -> n); i++) {
    struct listnode *new = g -> A[i];
    if(new!=NULL){
      printf("%d: ", i+1);
      while(new != NULL) {
        printf("%d ", new -> n);
        new = new -> next;
      }
      printf("\n");
    }
  }
}

void dfs1(Graph g, int i, int *aux) {
    struct listnode *t;
    aux[i] = 1;
    for(t = g->A[i]; t; t = t->next) {
        if((aux[t->n - 1])==0) {
            printf("%d ",t->n);
            dfs1(g,t->n-1,aux);
        }

    }
}

void dfs(Graph g) {
    int i, *aux = calloc(g->n,sizeof(int));
    if(!aux) { fprintf(stderr,"Errore di Allocazione\n"); exit(-4); }
    for(i = 0; i < g->n; i++)
        if(!aux[i]) {
          if (g -> A[i] != NULL)
            printf("\n%d: ",i+1);
          dfs1(g,i,aux);
        }
    printf("\n");
    free(aux);
}

void bfs1(Graph g, int i, int *aux) {
    struct listnode *t;
    Queue q = createqueue();
    enqueue(q,i);
    while(q) {
        i = dequeue(q);
        aux[i] = 1;
        for(t = g->A[i]; t; t = t->next)
            if(!aux[t->n - 1]) {
                enqueue(q,t->n -1);
                printf("%d,",t->n);
                aux[t->n-1] = 1;
            }
    }
    destroyqueue(q);
}
void bfs(Graph g) {
    int i, *aux = calloc(g->n,sizeof(int));
    if(!aux) {
      fprintf(stderr,"Errore di Allocazione\n"); exit(-4);
    }
    for(i = 0; i < g->n; i++)
        if(!aux[i]) {
            printf("\n%d,",i+1);
            bfs1(g,i,aux);
        }
    free(aux);
}
