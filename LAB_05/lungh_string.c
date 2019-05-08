#include <stdio.h>
#define N 100

int lung_stringa(char *s);

int main() {
  char str[N] = {0};
  char *p;
  char ch;
  printf("Inserisci stringa:\n");
  for (p = str; p < str+N; p++) {
    ch = getchar();
    if (ch!='\n')
      *p=ch;
    else
      break;
  }
  printf("Lunghezza stringa: %d\n", lung_stringa(str));
  return 0;
}

int lung_stringa(char *s) {
  int count = 0;
  while(*s++!='\0')
    count++;
  return count;
}
