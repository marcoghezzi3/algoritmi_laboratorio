#include <stdio.h>

int potenza(int b, int exp) {
  int n=1;
  for (int i = 0; i < exp; i++)
    n *= b;
  return n;
}

int main() {
  int b, exp;
  scanf("%d %d", &b, &exp);
  printf("%d\n", potenza(b, exp));
  return 0;
}
