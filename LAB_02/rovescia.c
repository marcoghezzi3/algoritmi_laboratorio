#include <stdio.h>
#define N 100

int main(int argc, char const *argv[]) {
  int a[N], count = 0;
  for (int i = 0; i < N; i++) {
    scanf("%d", &a[i]);
    if (a[i]==0)
      break;
    count++;
  }
  for (int i = count; i >=0; i--)
    if (a[i]!=0)
      printf("%d ", a[i]);
  printf("\n");
  return 0;
}
