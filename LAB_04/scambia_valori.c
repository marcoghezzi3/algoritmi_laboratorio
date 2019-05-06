#include <stdio.h>

void scambia(int *p, int *q);

int main() {
  int i, j;
  scanf("%d %d", &i, &j);
  scambia(&i, &j);
  printf("%d %d\n", i, j);
  return 0;
}

void scambia(int *p, int *q) {
  int t = *p;
  *p=*q;
  *q=t;
}
