#include <stdio.h>
#include <string.h>
#define N 100

int main(int argc, char const *argv[]) {
  int numeri[N] = {0}, n;
  int count=0;
  do {
    scanf("%d", &n);
    int i;
    for(i = count; i > 0; i--) {
      if (numeri[i-1]>n && n!=0)
        numeri[i]=numeri[i-1];
      else
        break;
    }
    numeri[i]=n;
    count++;
  } while(n!=0);
  for (int i = 0; i < N; i++)
    if (numeri[i]!=0)
      printf("%d ", numeri[i]);
  printf("\n");
  return 0;
}
