#include <stdio.h>

int main(int argc, char const *argv[]) {
  int mese, giorno, tot;
  printf("Inserisci il numero del mese (1=gennaio, ...,12 = dicembre): ");
  scanf("%d", &mese);
  printf("Inserisci il giorno di inizio mese (1=lunedì, ..., 7=domenica): ");
  scanf("%d", &giorno);
  if (mese>12 || giorno>7) {
    printf("Errore\n");
    return 1;
  }
  printf("L\tM\tM\tG\tV\tS\tD\n");
  switch (mese) {
    case 11:
    case 4:
    case 6:
    case 9: tot = 30;
            break;
    case 2: tot = 28;
            break;
    default: tot = 31;
            break;
  }
  for(int i = 1; i < giorno; i++) {
    printf("\t");
  }
  int j = giorno+1;
  for (int i = 1; i <= tot; i++) {
    printf("%d\t", i);
    if (j==8) {
      printf("\n");
      j = 1;
    }
    j++;
  }
  printf("\n");
  return 0;
}
