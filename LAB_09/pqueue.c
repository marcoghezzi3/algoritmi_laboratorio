#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct pqueue *Pqueue;
typedef int Item;
typedef Item* Heap;
/* crea una coda di priorità vuota che potrà contenere al massimo n Item */
struct pqueue {
  Heap h;
  int size, count;
};

int father(int i);
void swap(Heap h, int i, int j);
void heapify_up(Heap h, int i);
void heapify_down(Heap h, int i, int n);

/* crea una coda di priorità vuota che potrà contenere al massimo n Item */
Pqueue pqueue_new( int n );
/* distrugge la coda di priorità */
void pqueue_destroy( Pqueue pcoda);
/* restituisce la lunghezza della coda di priorità */
int pqueue_length( Pqueue pcoda);
/* inserisce l’Item nella coda di priorità */
void pqueue_insert( Pqueue pcoda, Item item );
/* estrae dalla coda di priorità l’Item con chiave minima */
Item pqueue_extractmin( Pqueue pcoda);
/* restituisce l’Item con chiave minima nella coda di priorità */
Item pqueue_min( Pqueue pcoda);
void print_heap(Pqueue pcoda);

void pqueue_sort(Item a[], int l, int r);

int main(int argc, char const *argv[]) {
  int a[14] = {1,2,5,10,20,7,11,15,16,3,9,15,8,17};
  pqueue_sort(a, 0, 13);
  printf("\n");
  /*for(int i = 0; i < 14; i++)
    pqueue_insert(new, a[i]);

  printf("Heap: ");
  print_heap(new);
  int min = pqueue_extractmin(new);
  printf("\nMinimo: %d\nHeap: ", min);
  print_heap(new);
  printf("\n");*/
  return 0;
  swap(a, 1, 2);
  for(int i = 0; i < 14; i++)
    printf("%d\n", a[i]);
}

int father(int i) {
  return i/2;
}

void swap(Heap h, int i, int j) {
  int tmp = h[i];
  h[i] = h[j];
  h[j] = tmp;

}

void heapify_up(Heap h, int i) {
  if (i>1) {
    int j = father(i);
    if (h[i]<h[j]) {
      swap(h, i, j);
      heapify_up(h, j);
    }
  }
}

void heapify_down(Heap h, int i, int n) {
  if (2*i <= n) {
    int j;
    if (2*i == n)
      j = 2*i;
    else
      j = h[2*i]<h[2*i+1] ? 2*i: 2*i +1;
    if (h[j]<h[i]) {
      swap(h, i, j);
      heapify_down(h, j, n);
    }
  }
}

Pqueue pqueue_new( int n ) {
  Pqueue new = malloc(sizeof(struct pqueue));
  new -> size = n+2;
  new -> count = 1;
  new -> h = malloc(new -> size*sizeof(int));
  return new;
}

void pqueue_destroy(Pqueue pcoda) {
  free(pcoda->h);
  free(pcoda);
}

int pqueue_length(Pqueue pcoda) {
  return pcoda->count;
}

void pqueue_insert( Pqueue pcoda, Item item ) {
  pcoda -> h[pcoda->count] = item;
  heapify_up(pcoda -> h, pcoda->count);
  pcoda -> count += 1;
}

Item pqueue_extractmin(Pqueue pcoda) {
  int min = pcoda -> h[1];
  swap(pcoda->h, 1, pcoda->count-1);
  pcoda -> count -= 1;
  heapify_down(pcoda -> h, 1, pcoda->count-1);
  return min;
}

Item pqueue_min( Pqueue pcoda) {
  return pcoda -> h[1];
}

void print_heap(Pqueue pcoda) {
  for (int i = 1; i < pcoda -> count; i++)
    printf("%d ", pcoda -> h[i]);
}

void pqueue_sort(Item a[], int l, int r) {
  Pqueue new = pqueue_new(r-l+1);
  for(int i = l; i <= r; i++)
    pqueue_insert(new, a[i]);
  while (new -> count > 1) {
    printf("%d ", pqueue_extractmin(new));
  }
  pqueue_destroy(new);
}
