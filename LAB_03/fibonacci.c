#include <stdio.h>

int fibonacci(int n);
int chiamate = 0;
int main() {
  int n;
  scanf("%d", &n);
  printf("%d\n", fibonacci(n));
  printf("Numero di chiamate della funzione: %d\n", chiamate);
  return 0;
}

int fibonacci(int n){
  chiamate++;
  if (n==1 || n==2)
    return 1;
  else
    return fibonacci(n-1)+fibonacci(n-2);
}
