#include <stdio.h>
#include <ctype.h>

int main(int argc, char const *argv[]) {
  int alfabeto[26]={};
  char ch;
  while((ch=tolower(getchar()))!='.') {
    int index=ch-'a';
    alfabeto[index]++;
  }
  for(int i = 0; i < 26; i++) {
    if(alfabeto[i]!=0) {
      printf("%c ", i+65);
      for (int j=0; j < alfabeto[i]; j++)
        printf("*");
      printf("\n");
    }

  }
  return 0;
}
