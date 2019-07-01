#include <stdio.h>
#include <stdlib.h>

struct element {
  int item;
  struct element *next;
};

typedef struct element *List;

typedef struct pqueue *Pqueue;
typedef List Item;
typedef Item* Heap;
/* crea una coda di priorità vuota che potrà contenere al massimo n Item */
struct pqueue {
  Heap h;
  int size, count;
};

void printList(List head);
List insert(int n, List head);

int main(int argc, char const *argv[]) {
  List head = malloc(sizeof(struct element));
  head = NULL;
  head = insert(10, head);
  head = insert(89, head);
  printList(head);
  return 0;
}

List insert(int n, List head) {
  List new_node = malloc(sizeof(struct element));
  new_node -> item = n;
  new_node -> next = head;
  return new_node;
}

void printList(List head) {
  List p = head;
  printf("LISTA:\n[");
  while(p) {
    if (p->next != NULL)
      printf("%d, ", p->item);
    else
      printf("%d", p->item);
    p = p->next;
  }
  printf("]\n\n");
}
