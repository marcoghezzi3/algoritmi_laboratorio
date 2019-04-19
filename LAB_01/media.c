#include <stdio.h>

int main(int argc, char const *argv[]) {
  int n, somma = 0, count = 1;
  scanf("%d", &n);
  while (n!=0) {
    somma+=n;
    count++;
    scanf("%d", &n);
  }
  count-=1;
  double media = (double)(somma)/count;
  printf("%f\n", media);
  return 0;
}
