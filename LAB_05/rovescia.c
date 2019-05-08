#include <stdio.h>
#include <ctype.h>
#define N 100

int main() {
    int a[N];
    int *p, count = 0;
    for (p = &a[0]; p < &a[N]; p++) {
        int n;
        scanf("%d", &n);
          if (n!=0) {
              *p = n;
              count++;
          }
          else
              break;
    }
    for (p = &a[count-1]; p >= &a[0]; p--)
        printf("%d ", *p);
    return 0;
}