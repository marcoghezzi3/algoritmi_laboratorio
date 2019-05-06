#include <stdio.h>

void quadrato(int n);

int main() {
  int n;
  printf("Inserisci un numero: ");
  scanf("%d", &n);
  quadrato(n);
  return 0;
}

void quadrato(int n) {
  int quad[n][n];
  for(int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      quad[i][j]=0;
  int i = 0, count = 0;
  int j = n/2;
  while(count < n*n) {
    quad[i][j]=++count;
    j=(j+1)%n;
    if (i-1<0)
      i=(n+i-1)%n;
    else
      i=i-1;
    if (quad[i][j]!=0) {
      i=(i+2)%n;            //avendo già aggiornato gli indici devo scendere di due righe;
      if (j-1<0)
        j=n+j-1;
      else
        j=j-1;
    }
  }


  for(int i = 0; i < n; i++) {
    for(int j = 0; j < n; j++)
      printf("%d\t", quad[i][j]);
    printf("\n");
  }
}
