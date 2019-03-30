#include <stdio.h>
#define N 10
int main(int argc, char const *argv[]) {
  int x;
  for (int i = 1; i <= N; i++) {
    x = i*i;
    printf("%d ", x);
  }
  printf("\n");
  return 0;
}
