#include <stdio.h>
#include <ctype.h>

void sostituisci(char a, char b);

int main() {
  char voc;
  scanf("%c ", &voc);
  char ch;
  do {
    ch = getchar();
    sostituisci(voc, ch);
  } while(ch!='.');
  printf("\n");

  return 0;
}

void sostituisci(char a, char b) {
  if (b == 'a' || b == 'e' || b == 'i' || b == 'o' || b == 'u')
    putchar(a);
  else
    putchar(b);
}
