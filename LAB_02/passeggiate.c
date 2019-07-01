#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define N 10

enum {NORD, SUD, EST, OVEST} direzioni;

int main(int argc, char const *argv[]) {
  srand(time(NULL));
  char base[N][N];
  for (int i = 0; i < N; i++)
    for (int j = 0; j < N; j++)
      base[i][j] = '.';
  char ch = 'A';
  int i = 0, j = 0;
  base[i][j] = ch;
  while (ch<'Z') {
    int direzione = rand()%4;
    //printf("%d\n", direzione);
    if ((i==0 || base[i-1][j]!='.') && (i==9 || base[i+1][j]!='.') && (j==0 || base[i][j-1]!='.') && (j==9 || base[i][j+1]!='.'))
            break;
    switch (direzione) {
      case NORD:
        if(i-1>=0 && base[i-1][j]=='.') {
          i = i-1;
          base[i][j] = ++ch;
        }
        break;
      case SUD:
        if(i+1<10 && base[i+1][j]=='.') {
          i = i+1;
          base[i][j] = ++ch;
        }
        break;
      case EST:
        if (j+1<10 && base[i][j+1]=='.') {
          j = j+1;
          base[i][j] = ++ch;
        }
        break;
      case OVEST:
        if(j-1>=0 && base[i][j-1]=='.') {
          j = j-1;
          base[i][j] = ++ch;
        }
        break;
    }

  }
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++)
      printf("%c ", base[i][j]);
    printf("\n");
  }
  return 0;
}
