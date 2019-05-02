#include <stdio.h>
#define N 100

int main(int argc, char const *argv[]) {
  int b, n, resto;
  scanf("%d %d", &b, &n);
  int new[N], count = 0;
  while (n!=0) {
    resto = n % b;
    n = n / b;
    new[count]=resto;
    count++;
  }
  for (int i = count-1; i >= 0; i--)
    printf("%d", new[i]);
  printf("\n");
  return 0;
}
