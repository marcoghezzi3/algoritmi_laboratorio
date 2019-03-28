#include <stdio.h>

int main(int argc, char const *argv[]) {
  int a, b, c;
  scanf("%d %d %d", &a, &b, &c);
  if ((a+b>c)&&(a+c>b)&&(b+c)>a) {
    if (a==b && b==c)
      printf("Triangolo equilatero\n");
    else if ((a==b && b!=c) || (a==c && c!=b) || (b==c && b!=a))
      printf("Triangolo isoscele\n");
    else
      printf("Triangolo scaleno\n");

  }
  else
    printf("%d, %d e %d non sono lati di un triangolo\n", a, b, c);
  return 0;
}
