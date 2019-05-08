#include <stdio.h>

int *smallest(int a[], int n);

int main(int argc, char const *argv[]) {
  int a[10];
  for (int i = 0; i < 10; i++)
    scanf("%d", &a[i]);
  printf("%d\n", *smallest(a, 10));
  return 0;
}

int *smallest(int a[], int n) {
  int *min, *p;
  min = &a[0];
  for (p = a; p < a+n; p++) {
    if (*p<*min)
      min = p;
  }
  return min;

}
