#include <stdio.h>

int main(int argc, char const *argv[]) {
  int n, count = 0;
  scanf("%d", &n);
  for (int i = n; i > 0; i--) {
    if (n % i == 0)
      count++;
  }
  if (count == 2 || count == 1)
    printf("%d è un numero primo\n", n);
  else
    printf("%d non è un numero primo\n", n);
  return 0;
}
