#include <stdio.h>
#define N 5

int main(int argc, char const *argv[]) {
  int voto[N][N];
  for(int i = 0; i<N; i++)
    for(int j = 0; j<N; j++) {
      scanf("%d", &voto[i][j]);
    }
  printf("\n");
  for (int i = 0; i<N; i++) {
    int somma = 0;
    printf("%d° studente: ", i+1);
    for (int j = 0; j<N; j++){
      printf("%d ", voto[i][j]);
      somma+=voto[i][j];
    }
    double media = (double)(somma)/N;
    printf("Media: %f\n", media);
  }

  for (int i = 0; i<N; i++) {
    int somma = 0;
    for (int j = 0; j<N; j++){
      //printf("%d ", voto[i][j]);
      somma+=voto[j][i];
    }
    double media = (double)(somma)/N;
    printf("Media %d° esame: %f\n", i+1, media);
  }

  return 0;
}
