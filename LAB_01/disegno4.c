#include <stdio.h>

int main(int argc, char const *argv[]) {
  int n;
  printf("n = ");
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    for (int j = 1; j <= n+2; j++) {
      if (j==n+2-i || (j==2 && i==n-2) || (j==1 && i == n-3))
        printf("*");
      else
        printf(".");
    }
    printf("\n");
  }
  return 0;
}
