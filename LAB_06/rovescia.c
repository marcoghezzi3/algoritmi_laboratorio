#include <stdio.h>
#include <stdlib.h>

void rovescia1();
void rovescia2();

int main() {
  rovescia1();
  //rovescia2();
  return 0;
}

void rovescia1() {
  int *p, n;
  int count = 0, size = 2;
  p=malloc(size);
  do {
    scanf("%d", &n);
    if (count>=size) {
      size*=2;
      p = realloc(p, size);
    }
    if (n==0)
      break;
    p[count++] = n;
  } while(n!=0);
  for(int i = count-1; i>=0; i--)
    printf("%d ", p[i]);
  printf("\n");
}

void rovescia2() {
  int *p, n;
  int count = 0, size = 15;
  p=malloc(size);
  do {
    scanf("%d", &n);
    if (count>=size) {
      size+=10;
      p = realloc(p, size);
    }
    if (n==0)
      break;
    p[count++] = n;
  } while(n!=0);
  for(int i = count-1; i>=0; i--)
    printf("%d ", p[i]);
  printf("\n");
}
