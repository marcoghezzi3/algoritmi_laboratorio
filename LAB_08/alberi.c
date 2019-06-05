#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 9

struct bit_node {
  int item;
  struct bit_node *l, *r;
};
typedef struct bit_node *Bit_node;

Bit_node bit_new(int n);
void bit_printnode(Bit_node p);
void bit_preorder(Bit_node p);
void bit_inorder(Bit_node p);
void bit_postorder(Bit_node p);
void bit_printassummary(Bit_node p, int spaces);
Bit_node bit_arr2tree(int a[], int size, int i);

int main(int argc, char const *argv[]) {
  srand(time(NULL));
  /*bit_preorder(root);
  printf("\n");
  bit_inorder(root);
  printf("\n");
  bit_postorder(root);
  printf("\n");*/
  int a[N] = {0};
  for (int i = 0; i < N; i++) {
    a[i] = rand()%50;
  }
  Bit_node root = bit_arr2tree(a, 9, 0);
  bit_printassummary(root, 0);
  return 0;
}

Bit_node bit_new(int n) {
  Bit_node root;
  root = malloc(sizeof(struct bit_node));
  root->l = NULL;
  root->r = NULL;
  root->item = n;
  return root;
}

void bit_printnode(Bit_node p) {
  printf("%d ", p->item);
}

void bit_preorder(Bit_node p) {
  if (p) {
    bit_printnode(p);
    bit_preorder(p->l);
    bit_preorder(p->r);
  }
}

void bit_inorder(Bit_node p) {
  if (p) {
    bit_inorder(p->l);
    bit_printnode(p);
    bit_inorder(p->r);
  }
}

void bit_postorder(Bit_node p) {
  if (p) {
    bit_postorder(p->l);
    bit_postorder(p->r);
    bit_printnode(p);
  }
}

void bit_printassummary(Bit_node p, int spaces) {
  if (p) {
    for (int i = 0; i < spaces; i++)
      printf("  ");
    printf("*");
    spaces++;
    bit_printnode(p);
    printf("\n");
    if (p->r || p->l) {
      if (p->l)
        bit_printassummary(p->l, spaces);
      else {
        for (int i = 0; i < spaces; i++)
          printf("  ");
        printf("*\n");
      }
      if (p->r)
        bit_printassummary(p->r, spaces);
      else {
        for (int i = 0; i < spaces; i++)
          printf("  ");
        printf("*\n");
      }
    }
  }
}


Bit_node bit_arr2tree(int a[], int size, int i) {
  if (i < size) {
    Bit_node p = bit_new(a[i]);
    p->l = bit_arr2tree(a, size, 2*i+1);
    p->r = bit_arr2tree(a, size, 2*i+2);
    return p;
  }
  return NULL;
}
