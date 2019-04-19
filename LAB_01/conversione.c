#include <stdio.h>

int main(int argc, char const *argv[]) {
  int h, m, s;
  scanf("%d:%d:%d", &h, &m, &s);
  if (h>=24 || m>60 || s>60)
    return 1;
  if (h>=12 && m>0 && s>0) {
    if (h==12)
      printf("%d:%d:%d PM\n", h, m, s);
    else {
      h-=12;
      printf("%d:%d:%d PM\n", h, m, s);
    }
  }
  else
    printf("%d:%d:%d AM\n", h, m, s);
  return 0;
}
