#include <stdio.h>

int main(int argc, char const *argv[]) {
  char firstLetter, secondLetter;
  firstLetter = getchar();
  getchar();
  secondLetter = getchar();
  int diff;
  diff = (firstLetter>=secondLetter)? firstLetter-secondLetter+1: secondLetter-firstLetter+1;
  printf("Distanza tra %c e %c è: %d\n", firstLetter, secondLetter, diff);
  return 0;
}
