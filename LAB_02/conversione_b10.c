#include <stdio.h>
#include <math.h>


int main(int argc, char const *argv[]) {
  int b, s;
  scanf("%d %d", &b, &s);
  int count = 0, n = 0;
  while (s!=0) {
    int resto = s%10;
    s/=10;
    n+=resto*pow(b, count);
    count++;

  }
  printf("Il numero in base %d è %d in base 10\n", b, n);
  return 0;
}
