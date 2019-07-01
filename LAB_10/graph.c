#include <stdio.h>
#include <stdlib.h>

struct node{
  int v;
  struct node *next;
};
typedef struct node *Lista;


struct graph2{
  int n,m;
  Lista *A;  //Matrice adiacenza
};

struct graph{
  int n,m;
  int **A;  //Matrice adiacenza
};

typedef struct graph *Graph;
typedef struct graph2 *Graph2;

void print_list(Lista l);
void listfree(Lista l);
Graph graph_new(int n);  //MATRICE adiacenza
Graph2 graph_new2(int n);
void graph_destroy(Graph g);
void graph_edgeinsert( Graph g,int v,int w ); //MATRICE
Lista graph_edgeinsert2( Lista l,int v); //LISTA
Graph graph_read(Graph g, FILE *fp);
Graph2 graph_read2(Graph2 g, FILE *fp);  //LISTA
void bfs_mat(struct graph *g);
void bfs1_mat(struct graph *g, int i, int* aux);
void bfs_list(struct graph2 *g);
void bfs1_list(struct graph2 *g, int i, int* aux);


Graph graph_new(int n){
  Graph g = malloc(sizeof(struct graph));
  if(!g){
    fprintf(stderr,"Errore di Allocazione\n");exit(-1);
  }
  g -> A = calloc(n, sizeof(int *));
  for(int i=0;i<n;i++){
    g -> A[i] = calloc(n, sizeof(int));
  }
  g -> n = n;
  g -> m = 0;
  return g;
}

Graph2 graph_new2(int n){
  Graph2 g = malloc(sizeof(struct graph2));
  if(!g){
    fprintf(stderr, "Errore di allocazione\n");
  }else{
    g -> n = n;
    g -> A = calloc(n, sizeof(struct node*));
    /*for (int i=0;i<n;i++){
      g -> A[i] = calloc(n,sizeof(struct node));
    }*/
  }
  return g;
}

void graph_destroy(Graph g){
  free(g);
}

struct queue{
  Lista head;
};

typedef struct queue *Queue;

Queue createqueue();
void enqueue(Queue q, int n);
int dequeue(Queue q);
void destroyqueue(Queue q);

Queue createqueue(){
  Queue q = malloc(sizeof(struct queue));
  if(!q)
    printf("Allocazione fallita\n");
  else{
    q -> head=NULL;
    return q;
  }
}

void enqueue(Queue q, int n){
  Lista nodo = malloc(sizeof(struct node));
  if(!nodo){
    printf("Allocazione fallita\n");
  }else{
    nodo -> v = n;
    nodo -> next = NULL;
    if(q -> head == NULL)
      q -> head = nodo;
    else{
      Lista tmp = q -> head;
      while(tmp -> next){
        tmp = tmp -> next;
      }
      tmp->next=nodo;
    }
  }
}

int dequeue(Queue q){
  if(q -> head){
    Lista nodo = q -> head;
    int n = nodo -> v;
    q -> head = q -> head -> next;
    free(nodo);
    return n;
  }

  return -1;
}

int emptyq(Queue q){
  if(q -> head)
    return 1;
  return 0;
}

void destroyqueue(Queue q){
  if(q){
    listfree(q -> head);
    free(q);
  }
}
//CON MATRICE
void graph_edgeinsert( Graph g,int v,int w ){
    g -> A[v][w]=1;
    g -> A[w][v]=1;
}

Lista graph_edgeinsert2( Lista l,int v){ //LISTA
  Lista nodo = malloc(sizeof(struct node));
  nodo -> v = v;
  nodo -> next = l;
  return nodo;
}

int isMember(Lista l,int n){
  Lista tmp=l;
  while(tmp!=NULL){
    if(tmp->v==n)
      return 0;
    tmp=tmp->next;
  }
  return 1;
}

Graph graph_read(Graph g, FILE *fp){
  int i,v1,v2;
  while(fscanf(fp,"%d %d",&v1,&v2)!= EOF){
    graph_edgeinsert(g,v1-1,v2-1);
  }
  return g;
}


Graph2 graph_read2(Graph2 g, FILE *fp){
  int i,v1,v2;
  while(fscanf(fp,"%d %d",&v1,&v2)!= EOF){
    if(isMember(g->A[v1-1],v2)!=0 && isMember(g->A[v2-1],v1)!=0){
      g -> A[v1-1] = graph_edgeinsert2(g -> A[v1-1], v2);
      g -> A[v2-1] = graph_edgeinsert2(g -> A[v2-1], v1);
    }
  }
  return g;
}


void graph_print2(Graph2 g){
  for (int i = 0; i < g -> n; i++) {
    printf("Vertice %d: \n",i+1 );
    print_list(g -> A[i]);
    printf("\n");
  }
}
/*Lista createlist(){
  Lista l = malloc(sizeof(struct node));

}*/

void print_list(Lista l){
  Lista tmp=l;

  if(tmp){
    while(tmp!=NULL){
      printf("%d -->",tmp->v );
      tmp=tmp->next;
    }
    printf("NULL");
  }
}

void listfree(Lista l){
  if(l){
    Lista tmp;
    while(tmp){
      tmp = l -> next;
      free(l);
      l=tmp;
    }
  }
}

void bfs1_mat(Graph g, int i, int* aux){
  Queue q = createqueue();
  enqueue(q,i);
  while(emptyq(q)!=0){
    i = dequeue(q);
    aux[i]=1;
    for(int j = 0;j<g -> n;j++){
      if(aux[j]==0){
        if(g->A[i][j]==1){
          enqueue(q,j);
          printf("%d,",g->A[i][j]);
          aux[j]=1;
        }
      }
    }
  }
  destroyqueue(q);
}

void bfs_mat(Graph g){
  int i , *aux = calloc(g->n,sizeof(int));
  if(!aux) { fprintf(stderr, "Allocazione fallita\n"); exit(-4); }
  for(i=0; i<g->n; i++){
    if(aux[i]==0){
      printf("\n%d,",i+1);
      bfs1_mat(g,i,aux);
    }
  }
}

void bfs_list(struct graph2 *g){
  int i, *aux = calloc(g->n,sizeof(int));
  if(!aux) { fprintf(stderr, "Allocazione fallita\n"); exit(-4); }
  for(i=0 ; i<g->n; i++){
    if(!aux[i]){
      printf("\n%d,",i+1);
      bfs1_list(g,i,aux);
    }
  }

}

void bfs1_list(struct graph2 *g, int i, int* aux){
  Lista l;
  Queue q = createqueue();
  enqueue(q,i);
  while(emptyq(q)!=0){
    int i = dequeue(q);
    aux[i] = 1;
    for(l=g->A[i];l;l=l->next){
      if(aux[l->v-1]==0){
        enqueue(q,l->v-1);
        printf("%d,",l->v-1);
        aux[l->v-1]=1;
      }
    }
  }
}

int main(){
  FILE *fp;
  fp = fopen("grafo.txt", "r"); // read mode

  Graph g = graph_new(5);
  Graph2 g2 = graph_new2(5);  //CON LISTA DI ADIACENZA
  g=graph_read(g,fp);
  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 5; j++) {
      printf("%d",g -> A[i][j]);
  }
    printf("\n");
  }
  fp = fopen("grafo.txt", "r"); // read mode

  g2=graph_read2(g2,fp);

  graph_print2(g2);


  Queue q = createqueue();
  enqueue (q,1);
  enqueue (q,13);
  enqueue (q,3);
  printf("preso dalla coda: %d\n",dequeue(q) );

  printf("preso dalla coda: %d\n",dequeue(q) );
  printf("preso dalla coda: %d\n",dequeue(q) );
  destroyqueue(q);

  bfs_mat(g);
  printf("bfs con lista: \n");
  bfs_list(g2);

}
