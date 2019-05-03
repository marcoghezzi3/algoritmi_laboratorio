#include <stdio.h>
#include <ctype.h>

int main(int argc, char const *argv[]) {
  int alfabeto[26]={};
  char ch;
  while((ch=tolower(getchar()))!=' ') {
    int index=ch-'a';
    alfabeto[index]++;
  }
  while((ch=tolower(getchar()))!='\n') {
    int index=ch-'a';
    alfabeto[index]--;
  }
  for(int i = 0; i < 26; i++) {
    if(alfabeto[i]!=0) {
      printf("Le parole non sono anagrammi.\n");
      return 0;
    }
  }
  printf("Le parole sono anagrammi.\n");
  return 0;
}
