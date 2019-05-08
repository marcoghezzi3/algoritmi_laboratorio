#include <stdio.h>
#include <ctype.h>
#define N 100

char *maiuscolo(char *stringa);

int main() {
  char string[N];
  char ch;
  int count = 0;
  while ((ch=getchar())!='\n') {
    string[count++] = ch;
  }
  printf("%s\n", maiuscolo(string));
  return 0;
}

char *maiuscolo(char *stringa) {
  char *p = stringa;
  while(*stringa!='\0') {
    *stringa = toupper(*stringa);
    stringa++;
  }
  return p;
}
