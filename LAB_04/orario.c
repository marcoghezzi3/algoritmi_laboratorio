#include <stdio.h>

void split_time (long int tot_sec, int *h, int *m, int *s);

int main() {
  long int tot_sec;
  int h, m, s;
  scanf("%ld", &tot_sec);
  split_time(tot_sec, &h, &m, &s);
  printf("%02d:%02d:%02d\n", h, m, s);
  return 0;
}

void split_time (long int tot_sec, int *h, int *m, int *s) {
  *h=tot_sec/3600;
  tot_sec%=3600;
  *m=tot_sec/60;
  *s=tot_sec%60;
}
