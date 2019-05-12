#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

char *read_line(void);
char *read_word(void);

int main() {
  char *ch;
  //ch = read_line();
  ch = read_word();
  printf("%s\n", ch);
  return 0;
}

char *read_line(void) {
  char *p, ch;
  int n = 0, size = 2;
  p = malloc(size);
  while((ch=getchar())!='\n') {
    if (n>=size) {
      size*=2;
      p=realloc(p, size);
    }
    if (ch=='\n') {
      p[n]='\0';
      break;
    }
    p[n++]=ch;
  }
  return p;
}

char *read_word(void) {
  char *p, ch;
  int n = 0, size = 2;
  p = malloc(size);
  while((ch=getchar())!='\n') {
    if (n>=size) {
      size*=2;
      p=realloc(p, size);
    }
    if (!isalpha(ch)&&!isdigit(ch)) {
      p[n]='\0';
      break;
    }
    p[n++]=ch;
  }
  return p;
}
