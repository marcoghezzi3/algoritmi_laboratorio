#include <stdio.h>
#include <stdlib.h>
#include <time.h>


struct listnode {
  struct listnode *next;
  int item;
};

struct graph {
  int n, m;                     //n numero vertici, m numero archi;
  struct listnode **A;          //array di puntatori a liste di adiacenza;
};
typedef struct graph *Graph;

struct queue {
  struct queue *next;
  int n;
};
typedef struct queue *Queue;

/*
CODA
*/
Queue createqueue();
Queue enqueue(Queue q, int n);
int dequeue(Queue *q);
void destroyqueue(Queue *q);

/*
GRAPH
*/
Graph graph_new(int n);
void graph_destroy(Graph g);
int isMember(struct listnode *l, int n);
void graph_edgeinsert(Graph g, int v, int w);
Graph graph_read(Graph g, FILE *fp);
void graph_print(Graph g);

/*
VISITE
*/
void dfs1(Graph g, int i, int *aux, int print);
void dfs(Graph g);
void bfs1(Graph g, int i, int *aux);
void bfs(Graph g);

/*
PROPRIETA' DEI GRAFI
*/
Graph gen(int n, float p);
int degree(Graph g, int v);
int path(Graph g, int v, int w);
int ccc(Graph g);
void cc(Graph g, int v);
void span1(Graph g, int i, int *aux, int spazi);
void span(Graph g, int v);
int shortestpath(Graph g, int v, int w);


int main() {
  Graph g = graph_new(10);
  FILE *fp = fopen("input.txt", "r");
  g = graph_read(g, fp);
  graph_print(g);
  bfs(g);
  printf("\n%d\n", ccc(g));
  cc(g, 2);
  printf("\n");
  span(g, 2);
  printf("\n");
  printf("%d\n", shortestpath(g, 1, 2));
}

Queue createqueue() {
  return NULL;
}

Queue enqueue(Queue q, int n) {
  Queue new = malloc(sizeof(struct queue));
  new -> n = n;
  new -> next = NULL;
  if (!q)
    return new;
  else {
    Queue tmp = q;
    while (q->next)
      q = q->next;
    q -> next = new;
    return tmp;
  }

}

int dequeue(Queue *q) {
  if (*q) {
    int i = (*q)->n;
    *q = (*q) -> next;
    return i;
  }
  else
    return -1;
}

void destroyqueue(Queue *q) {
  while(*q!=NULL) {
    Queue tmp = *q;
    free(*q);
    *q = tmp -> next;
  }
}

/*
    GRAPH
*/

Graph graph_new(int n) {
  Graph new = malloc(sizeof(struct graph));
  if (!new) {
    printf("Allocazione non riuscita\n" );
    exit(-1);
  }
  new -> n = n;
  new -> m = 0;
  if(!(new -> A = calloc(n, sizeof(struct listnode*))) ) {
    printf("Errore allocazione\n");
    exit(-2);
  }
  return new;
}

void graph_destroy(Graph g) {
  free(g -> A);
  free(g);
}

int isMember(struct listnode *l, int n) {
  struct listnode *tmp = l;
  while (tmp != NULL) {
    if (tmp -> item == n)
      return 1;
    tmp = tmp -> next;
  }
  return 0;
}

void graph_edgeinsert(Graph g, int v, int w) {
  struct listnode *tmp = malloc(sizeof(struct listnode));
  if (!tmp) {
    printf("Errore allocazione\n");
    exit(-3);
  }
  tmp -> item = w;
  tmp -> next = g -> A[v];    //lo metto all'inizio della lista
  g -> A[v] = tmp;
  g -> m += 1;
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
  for (int i = 0; i < g -> n; i++) {
    struct listnode *tmp = g -> A[i];
    if (tmp!=NULL) {
      printf("%d: ", i);
      while (tmp) {
        if (tmp->next)
          printf("%d, ", tmp -> item);
        else
          printf("%d ", tmp -> item);
        tmp = tmp -> next;
      }
      printf("\n");
    }
  }
}

/*
VISITA IN PROFONDITA'
*/
void dfs1(Graph g, int i, int *aux, int print) {
  struct listnode *tmp;
  aux[i] = 1;
  for (tmp = g -> A[i]; tmp; tmp = tmp -> next) {
    if (tmp) {
      if (!aux[tmp -> item]) {
        if (print)
          printf("%d, ", tmp -> item);
        dfs1(g, tmp -> item, aux, print);
      }
    }
  }
}

void dfs(Graph g) {
  int i, *aux = calloc(g -> n, sizeof(int));
  if (!aux) {
    printf("Errore allocazione\n" );
    exit(-4);
  }
  for (int i = 0; i < g -> n; i++) {
    if (g -> A[i]) {
      if (!aux[i]) {
        printf("\n%d, ", i);
        dfs1(g, i, aux, 1);
      }
    }
  }
  free(aux);
}


/*
VISITA IN AMPIEZZA
*/
void bfs1(Graph g, int i, int *aux) {
  struct listnode *tmp;
  Queue q = createqueue();
  q = enqueue(q, i);
  while(q) {
    i = dequeue(&q);
    aux[i] = 1;
    for(tmp = g -> A[i]; tmp; tmp = tmp -> next) {
      if (!aux[tmp -> item]) {
        q = enqueue(q, tmp -> item);
        printf("%d, ", tmp -> item);
        aux[tmp -> item] = 1;
      }
    }
  }
  destroyqueue(&q);
}

void bfs(Graph g) {
  int i, *aux = calloc(g -> n, sizeof(int));
  if (!aux) {
    printf("Errore allocazione\n" );
    exit(-5);
  }
  for (int i = 0; i < g -> n; i++) {
    if (g -> A[i]) {
      if (!aux[i]) {
        printf("\n%d, ", i);
        bfs1(g, i, aux);
      }
    }
  }
  free(aux);
}



/*
PROPRIETA' DEI GRAFI
*/

Graph gen(int n, float p) {
  Graph new = graph_new(n);
  srand(time(NULL));
  for (int i = 0; i < n; i++) {
    int j = 0;
    while (j<n) {
      float r = ((float)(rand()%1000)/1000);
      if (r < p && i != j) {
        if (!isMember(new -> A[i], j) && !isMember(new -> A[j], i)) {
          graph_edgeinsert(new, i, j);
          graph_edgeinsert(new, j, i);
        }
      }
      j++;
    }
  }
  return new;
}

int degree(Graph g, int v) {
  struct listnode *l = g -> A[v];
  int count = 0;
  while(l) {
    l = l -> next;
    count++;
  }
  return count;
}

int path(Graph g, int v, int w) {
  int *aux = calloc(g->n, sizeof(int));
  dfs1(g, v, aux, 0);
  if (aux[w]==1) {
    free(aux);
    return 1;
  }
  free(aux);
  return 0;
}


int ccc(Graph g) {
  int count = 0;
  int *aux = calloc(g -> n, sizeof(int));
  for (int i = 0; i < g -> n; i++) {
    if (g -> A[i]) {
      if (!aux[i]) {
        count++;
        dfs1(g, i, aux, 0);
      }
    }
  }
  return count;
}

void cc(Graph g, int v) {
  int *aux = calloc(g -> n, sizeof(int));
  printf("Elenco dei vertici della componente fortemente connessa contenente %d: ", v);
  dfs1(g, v, aux, 1);
}

void span1(Graph g, int i, int *aux, int spazi) {
  struct listnode *tmp;
  aux[i] = 1;
  for (tmp = g -> A[i]; tmp; tmp = tmp -> next) {
    if (tmp) {
      if (!aux[tmp -> item]) {
        for (int j = 0; j < spazi; j++)
          printf("  ");
        printf("*%d\n", tmp -> item);
        span1(g, tmp -> item, aux, spazi+1);
      }
    }
  }
}

void span(Graph g, int v) {
  int *aux = calloc(g -> n, sizeof(int));
  if (!aux) {
    printf("Errore allocazione\n");
    exit(-6);
  }
  printf("*%d\n", v);
  span1(g, v, aux, 1);
  printf("\n");
}

int shortestpath(Graph g, int v, int w) {
  int *aux = calloc(g -> n, sizeof(int));
  for (int i = 0; i < g ->n; i++)
    aux[i] = -1;
  struct listnode *tmp;
  aux[v] = 0;
  Queue q = createqueue();
  q = enqueue(q, v);
  while(q) {
    int i = dequeue(&q);
    for(tmp = g -> A[i]; tmp; tmp = tmp -> next) {
      if (aux[tmp -> item] == -1) {
        q = enqueue(q, tmp -> item);
        aux[tmp -> item] = aux[i] + 1;
      }
    }
  }
  destroyqueue(&q);
  return aux[w];

}
