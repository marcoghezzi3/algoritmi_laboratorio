#include <stdio.h>

typedef struct {
  float x;
  float y;
} Punto;

typedef struct {
  Punto p1, p2;
} Rettangolo;

int area_rettangolo(Rettangolo *r);
void stampa(Rettangolo *r);
int perimetro_rettangolo(Rettangolo *r);
Punto centro_rettangolo(Rettangolo *r);
int interno(Punto *p, Rettangolo *r);

int main(){
  int x,y;
  Rettangolo r;
  scanf("%f %f", &r.p1.x, &r.p1.y);
  scanf("%f %f", &r.p2.x, &r.p2.y);
  stampa(&r);
  printf("L'area del rettangolo è: %d\n", area_rettangolo(&r));
  printf("Il perimetro del rettangolo è: %d\n", perimetro_rettangolo(&r));
  Punto centro = centro_rettangolo(&r);
  printf("Il centro del rettangolo è: (%.1f, %.1f)\n", centro.x, centro.y);
  Punto prova;
  printf("Inserisci un punto: ");
  scanf("%f %f", &prova.x, &prova.y);
  if (interno(&prova, &r)==0)
    printf("Interno\n");
  else
    printf("Esterno\n");
  return 0;
}

int area_rettangolo(Rettangolo *r) {
  int area;
  int base = r->p2.x - r->p1.x;
  int altezza = r->p2.y - r->p1.y;
  area = base*altezza;
  return area;
}

void stampa(Rettangolo *r) {
  printf("Vertice 1: (%.0f, %.0f)\n", r->p1.x, r->p1.y);
  printf("Vertice 2: (%.0f, %.0f)\n", r->p2.x, r->p2.y);
}

int perimetro_rettangolo(Rettangolo *r) {
  int perimetro;
  int base = r->p2.x - r->p1.x;
  int altezza = r->p2.y - r->p1.y;
  perimetro=(base+altezza)*2;
  return perimetro;
}

Punto centro_rettangolo(Rettangolo *r) {
  Punto p;
  int base=r->p2.x - r->p1.x;
  int altezza=r->p2.y - r->p1.y;
  p.x=(float)base/2+r->p1.x;
  p.y=(float)altezza/2+r->p1.y;
  return p;
}

int interno(Punto *p, Rettangolo *r) {
  if ((p->x<r->p2.x && p->x>r->p1.x)&&(p->y<r->p2.y&&p->y>r->p1.y))
    return 0;
  else
    return 1;
}
