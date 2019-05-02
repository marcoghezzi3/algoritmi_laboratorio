#include <stdio.h>
#include <ctype.h>
#define N 100

int main(int argc, char const *argv[]) {
  char ch, string[N]={};
  int count = 0;
  while ((ch=getchar())!='.') {
    string[count++]=ch;
  }
  for(int i = 0; i < count; i++) {
    if (string[i]!=string[count-1-i]) {
      printf("Stringa non palindroma\n");
      return 0;
    }
  }
  printf("Stringa palindroma\n");
  return 0;
}
