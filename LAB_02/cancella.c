#include <stdio.h>
#include <ctype.h>
#define N 100

int main(int argc, char const *argv[]) {
  char string[N], ch;
  int count = 0;
  while ((ch=getchar())!='\n') {
    string[count++]=ch;

  }
  char delete=string[count-1];
  for(int i = 0; i < count; i++) {
    if (string[i]!=delete)
      printf("%c", string[i]);
  }
  printf("\n");
}
