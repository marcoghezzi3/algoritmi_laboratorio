#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) {
  char *p, *q;
  int T;
  for(int i = 1; i < argc; i++) {
    T = 0;
    p = argv[i];
    int len = strlen(argv[i]);
    q = p+len-1;
    while(*p!='\0') {
      if (*p!=*q) {
        printf("%d: parola non palindroma", i);
        T = 1;
        break;
      }
      q--;
      p++;
    }
    if (!T)
      printf("%d: parola palindroma", i);
    printf("\n");
  }
  return 0;
}
