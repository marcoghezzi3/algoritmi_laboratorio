#include <stdio.h>
#include <math.h>

int main(int argc, char const *argv[]) {
  int a, b, c;
  scanf("%d %d %d", &a, &b, &c);
  int delta = sqrt((b*b)-4*a*c);
  int ris1, ris2;
  if (delta>=0) {
    ris1=(-b+delta)/2*a;
    ris2=(-b-delta)/2*a;
    printf("X1 = %d, X2= %d\n", ris1, ris2);
  }
  else
    printf("Delta negativo\n");

  return 0;
}
