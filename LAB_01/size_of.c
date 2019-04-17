#include <stdio.h>
#include <limits.h>

int main(int argc, char const *argv[]) {
  int n;
  scanf("%d", &n);
  int size = sizeof(n);
  printf("La dimensione in byte di %d è %d\n", n, size);
  printf("L'intervallo possibile è: %d..%d\n", INT_MIN, INT_MAX);
  short a;
  scanf("%hd", &a);
  size = sizeof(a);
  printf("La dimensione in byte di %d è %d \n", a, size);
  printf("L'intervallo possibile è: %d..%d\n", SHRT_MIN, SHRT_MAX);

  char ch;
  scanf (" %c", &ch);
  size = sizeof(ch);
  printf("La dimensione in byte di %c è %d\n", ch, size);
  printf("L'intervallo possibile è: %d..%d\n", SCHAR_MIN, SCHAR_MAX);
  return 0;
}
