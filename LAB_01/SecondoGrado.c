#include <stdio.h>
#include <math.h>

int main(void) {
  float a, b, c;
  float ris1, ris2;
  float delta;
  printf("Inserisci i coefficienti a, b, c di ax^2 + bx + c: \n" );
  scanf("%f \n%f \n %f", &a, &b, &c );
  delta = b*b-4*a*c;
  ris1 = ((-b)+sqrt(delta))/2*a;
  ris2 = ((-b)-sqrt(delta))/2*a;
  if (delta > 0) {
    ris1 = ((-b)+sqrt(delta))/2*a;
    ris2 = ((-b)-sqrt(delta))/2*a;
    printf("%.02f \n%.02f\n",ris1, ris2);
  }
  else if (delta == 0) {
    ris1 = ((-b)+sqrt(delta))/2*a;
    printf("%.02f\n", ris1);
  }
  else {
    float real;
    float imm1;
    real = -b / (2*a);
    imm1 = sqrt(-delta)/(2*a);
    printf("%0.2f + i %0.2f\n", real, imm1);
    printf("%0.2f - i %0.2f\n", real, imm1);
  }
  return 0;
}
