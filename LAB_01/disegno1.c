#include <stdio.h>

int main(int argc, char const *argv[]) {
  int n;
  scanf("%d", &n);
  for (int i=1; i<=n; i++) {
    for (int j=0; j<n;j++)
      if (i%2!=0)
        printf("+ ");
      else
        printf("o ");
    printf("\n");
  }
  return 0;
}
