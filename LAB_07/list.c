#include <stdio.h>
#include <stdlib.h>

struct element {
  int info;                 //valore dell'elemento
  struct element *next;     //indirizzo del prossimo elemento
};

typedef struct element element;

element* insert(int n, element* head);
void printList(element *head);
int isMember(int n, element* head);
element* delete(int n, element* head);
void destroy(element* head);
int *listToArray(element* head, int n);

int main(int argc, char const *argv[]) {
  element *head = malloc(sizeof(element));
  head = NULL;
  char ch;
  int n, count = 0;
  int *a;
  while((ch = getchar())!='f') {
    switch (ch) {
      case '+':
        scanf("%d", &n);
        if (!isMember(n, head)) {
          head = insert(n, head);
          count++;
        }
        else
          printf("Elemento già nella lista.\n");
        break;
      case '-':
        scanf("%d", &n);
        if (isMember(n, head)) {
          head = delete(n, head);
          count--;
        }
        else
          printf("Elemento non presente nella lista.\n");
        break;
      case '?':
        scanf("%d", &n);
        if (isMember(n, head))
          printf("%d appartiene alla lista.\n", n);
        else
          printf("%d non appartiene alla lista.\n", n);
        break;
      case 'c':
        printf("Lunghezza lista: %d\n", count);
        break;
      case 'p':
        printList(head);
        break;
      case 'd':
        destroy(head);
        count = 0;
        break;
      case 'o':
        a = listToArray(head, count);
        printf("[");
        for (int i = count-1; i >= 0; i--)
          printf("%d ", a[i]);
        printf("]\n");
        break;

    }
  }
  return 0;
}

element* insert(int n, element* head) {
  element* new_node = malloc(sizeof(element));
  new_node -> info = n;
  new_node -> next = head;
  return new_node;
}

void printList(element *head) {
  element* p = head;
  printf("LISTA:\n[");
  while(p) {
    if (p->next != NULL)
      printf("%d, ", p->info);
    else
      printf("%d", p->info);
    p = p->next;
  }
  printf("]\n\n");
}

int isMember(int n, element* head) {
  element* p;
  for (p = head; p != NULL; p = p->next)
    if (p->info == n)
      return 1;
  return 0;
}

element* delete(int n, element* head) {
  element* cur;
  element* prev;
  for (cur = head, prev = NULL; cur != NULL && cur->info!=n; prev = cur, cur = cur->next);
  if (cur == NULL)
    return head;
  else if (prev == NULL)
    head = head -> next;      //n nel primo elemento, la testa si sposta al secondo elemento
  else
    prev -> next = cur -> next;
  free(cur);
  return head;
}


//SISTEMARE
void destroy(element* head) {
  element *prev = NULL;
  element *cur = head;
  if (head->next == NULL)
    free(head);
  else {
    while(head->next!= NULL) {
      prev = head;
      head = head -> next;
      free(prev);
    }
  }
  cur -> next = NULL;

  //delete(0, cur);
  printf("Lista distrutta.\n");
}

int *listToArray(element* head, int n) {
  int *a = malloc(n*sizeof(int));
  for (int i = 0; i < n; i++) {
    a[i] = head->info;
    head = head->next;
  }
  return a;
}
