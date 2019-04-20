#include <stdio.h>

int main(int argc, char const *argv[]) {
  char ch;
  int dx = 1000, sx = 0;
  do {
    printf("Il numero è %d? ", (dx+sx)/2);
    scanf(" %c", &ch);
    switch (ch) {
      case '<': dx = (dx+sx)/2;
                break;
      case '>': sx = (dx+sx)/2;
                break;
    }

  } while(ch!='=');
  printf("Ho indovinato\n");
  return 0;
}
