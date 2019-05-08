#include <stdio.h>

void max_secondmax(int a[], int n, int *max, int *second_max);

int main(int argc, char const *argv[]) {
  int a[10];
  int max, second_max;
  for (int i = 0; i < 10; i++)
    scanf("%d", &a[i]);
  max_secondmax(a, 10, &max, &second_max);
  printf("Il massimo è: %d. Il secondo più grande è: %d\n", max, second_max);
  return 0;
}

void max_secondmax(int a[], int n, int *max, int *second_max) {
  int *p;
  *max=*second_max=a[0];
  for (p = a; p < a+n; p++) {
    if (*p>*max) {
      *second_max=*max;
      *max = *p;
    }
    if (*p>*second_max && *p<*max)
      *second_max=*p;
  }

}
