#include <stdio.h>
#include <ctype.h>
#define N 100

int main(int argc, char const *argv[]) {
  char string[N], ch;
  int count = 0;
  char *p, *q;
  while ((ch=getchar())!='.') {
    string[count++]=ch;
  }
  q = &string[count-1];
  for(p = string; p < string+count-1; p++) {
    if (*p!=*q--) {
      printf("Stringa non palindroma\n");
      return 0;
    }
  }
  printf("String palindroma\n");
  return 0;
}
