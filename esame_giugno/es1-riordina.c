#include <stdio.h>

void swap(int a[], int i, int j);

int main () {
  int n;
  scanf("%d", &n);
  int a[n];
  for (int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
  }

  int j = n - 1;
  for (int i = 0; i < n; i++) {
    while (a[i] != 0) {
      if (j<i)
        break;
      swap(a, i, j--);
    }
  }

  for (int i = 0; i < n; i++) {
    printf("%d ", a[i]);
  }
  printf("\n");
  return 0;
}

void swap(int a[], int i, int j) {
  int tmp = a[i];
  a[i] = a[j];
  a[j] = tmp;
}
