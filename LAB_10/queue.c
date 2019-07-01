#include <stdio.h>
#include <stdlib.h>


struct queue {
  int item;
  struct queue *next;
};
typedef struct queue *Queue;

Queue createqueue() {
  return NULL;
}

Queue enqueue(Queue q, int n) {
  Queue new = malloc(sizeof(struct queue));
  new -> item = n;
  new -> next = NULL;
  if (!new) {
    printf("Allocazione fallita\n");
    exit(-1);
  }
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
    int x = (*q) -> item;
    *q = (*q)->next;
    return x;
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
}                               //utilizzo il * per dargli la variabile puntata dal puntatore

void printqueue(Queue q) {
  while(q) {
    printf("%d ", q -> item);
    q = q -> next;
  }
  printf("\n");
}

int main () {
  Queue q = createqueue();
  q = enqueue(q, 3);
  q = enqueue(q, 5);
  q = enqueue(q, 2);
  q = enqueue(q, 1);
  q = enqueue(q, 4);
  q = enqueue(q, 7);
  printqueue(q);
  int x = dequeue(&q);
  x = dequeue(&q);
  printf("%d\n", x);
  printqueue(q);
  destroyqueue(&q);
  printqueue(q);
  return 0;
}
