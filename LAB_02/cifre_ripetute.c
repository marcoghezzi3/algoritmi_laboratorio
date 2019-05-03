#include <stdio.h>

int main(int argc, char const *argv[]) {
  int n;
  int cifre[10] = {0};
  int resto;
  scanf("%d", &n);
  while(n!=0) {
    resto=n%10;
    cifre[resto]++;
    n=n/10;
  }
  for (int i = 0; i < 10; i++)
    if (cifre[i]>1)
      printf("%d ", i);
  printf("\n");
  return 0;
}
