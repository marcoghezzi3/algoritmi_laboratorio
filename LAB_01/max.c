#include <stdio.h>

int main(int argc, char const *argv[]) {
  int a, b;
  scanf("%d %d", &a, &b);
  int max;
  max = (b > a)? b: a;
  printf("Il massimo tra %d e %d è: %d\n", a, b, max);
  return 0;
}
