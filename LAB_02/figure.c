#include <stdio.h>
#define PI 3.1415926535897

  typedef struct {
    int x,y;
  } Punto;

  typedef struct {
    Punto p1, p2;
  } Rettangolo;

  typedef struct {
    Punto centro;
    int raggio;
  } Cerchio;

  int area_ret(Rettangolo r) {
    int base = r.p1.x-r.p2.x;
    int altezza = r.p1.y-r.p2.y;
    return base*altezza;
  }

  int perimetro_ret(Rettangolo r) {
    int base = r.p1.x-r.p2.x;
    int altezza = r.p1.y-r.p2.y;
    return base*2+altezza*2;
  }

  float area_cerchio(Cerchio c) {
    return c.raggio*c.raggio*PI;
  }

  float circonferenza(Cerchio c){
    return 2*PI*c.raggio;
  }
int main(int argc, char const *argv[]) {
    Rettangolo r;
    Cerchio c;
    printf("Vertice 1: ");
    scanf("%d %d", &r.p1.x, &r.p1.y);
    printf("Vertice 2: ");
    scanf("%d %d", &r.p2.x, &r.p2.y);
    printf("L'area del rettangolo è: %dcm^2. Il perimetro è: %d\n", area_ret(r), perimetro_ret(r));
    printf("Centro e raggio cerchio: " );
    scanf("%d %d %d", &c.centro.x, &c.centro.y, &c.raggio);
    printf("L'area del cerchio è: %f. La circonferenza è: %f\n", area_cerchio(c), circonferenza(c));


    return 0;
  }
