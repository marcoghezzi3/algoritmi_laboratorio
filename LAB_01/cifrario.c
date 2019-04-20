#include <stdio.h>
#include <ctype.h>

int main(int argc, char const *argv[]) {
  int k;
  char ch;
  scanf("%d ", &k);
  while ((ch=getchar())!='.') {
    if (isalpha(ch)) {
      if(islower(ch))
        putchar('a'+(ch-'a'+k)%26);
      else if (isupper(ch))
        putchar('A'+(ch-'A'+k)%26);
    }
    else
      putchar(ch);
  }
  printf("\n");
  return 0;

}
