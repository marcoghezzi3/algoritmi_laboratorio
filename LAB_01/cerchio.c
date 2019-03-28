#include <stdio.h>
#include <math.h>

int main(int argc, char const *argv[]) {
  float raggio;
  scanf("%f", &raggio);
  float area = M_PI*raggio*raggio;
  printf("%f\n", area);
  return 0;
}
