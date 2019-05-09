#include <stdio.h>

int main(int argc, char *argv[]) {
  char *p = argv[1];
  char *q = p;
  printf("%c", *p);
  while (*++q!='\0') {
    int a = *p;
    int b = *q;
    if (b<a)
      printf("-%c", *q);
    else
      printf("%c", *q);
    p++;

  }
  printf("\n");
  return 0;
}
