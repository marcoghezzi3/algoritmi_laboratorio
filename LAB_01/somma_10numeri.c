#include <stdio.h>

int main(int argc, char const *argv[]) {
  int count = 0;
  int n, somma = 0;
  while (count!=10) {
    count++;
    scanf("%d", &n);
    somma+=n;
  }
  printf("%d\n", somma);
  return 0;
}
