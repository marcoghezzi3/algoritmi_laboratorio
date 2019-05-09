#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) {
  char *s = argv[1];
  char *p = s;
  while (*p!='\0'){
    if (*p == 'a'||*p=='e'||*p=='i'||*p=='o'||*p=='u')
      printf("%cf%c", *p, *p);
    else
      printf("%c", *p);
    p++;
  }
  printf("\n");
  return 0;
}
