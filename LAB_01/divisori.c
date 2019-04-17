#include <stdio.h>

int main(int argc, char const *argv[]) {
  int n;
  scanf("%d", &n);
  int count = 0, b = n;
  printf("I divisori di %d sono:\n", n);
  while (b != 0) {
    if (n % b == 0) {
      printf("%d ", b);
      count++;
    }
    b--;
  }
  printf(".\n%d ha %d divisori\n", n, count);
  return 0;
}
