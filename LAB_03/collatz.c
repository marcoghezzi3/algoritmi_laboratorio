#include <stdio.h>

int collatz(int n);

int main() {
  int n, count = 0;
  printf("Numero: ");
  scanf("%d", &n);
  while (n!=1) {
    count++;
    printf("%d ", n);
    n = collatz(n);
  }
  printf("%d ", n);
  printf("\nLunghezza: %d\n", count+1);
  return 0;
}

int collatz(int n) {
  return n%2==0? n/2: n*3+1;
}
