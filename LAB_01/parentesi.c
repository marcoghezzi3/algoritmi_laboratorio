#include <stdio.h>

int main(int argc, char const *argv[]) {
  char ch;
  int count = 0;
  int carat = 1;
  while((ch = getchar())!= '.'){
    if (ch=='(')
      count++;
    else if (ch==')')
      count--;
    if (count<0)
      break;
    carat++;
  }
  if (count == 0)
    printf("La stringa è un'espressione ben parentesizzata\n");
  else if (count<0)
    printf("Carattere %d: troppe parentesi chiuse!\n", carat);
  else
    printf("Carattere %d: mancano parentesi chiuse alla fine!\n", carat-1);
  return 0;
}
