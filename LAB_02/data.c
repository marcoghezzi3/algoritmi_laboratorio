#include <stdio.h>
#define N 100

typedef struct {
  int giorno;
  int mese;
  int anno;
} Data;

int main(int argc, char const *argv[]) {
  Data date[N];
  Data d;
  int count = 0;
  do {
    printf("Inserisci data nel formato dd/mm/yyyy: ");
    scanf("%d/%d/%d", &d.giorno, &d.mese, &d.anno);
    date[count++]=d;
  } while(d.giorno!=0&&d.mese!=0&&d.anno!=0);
  printf("Inserisci l'ultima data(dd/mm/yyyy): ");
  scanf("%d/%d/%d", &d.giorno, &d.mese, &d.anno);
  printf("Le date prima di %02d/%02d/%04d sono: \n", d.giorno, d.mese, d.anno);
  for(int i = 0; i < count-1; i++) {
    if(date[i].anno<d.anno)
      printf("%02d/%02d/%02d\n", date[i].giorno, date[i].mese, date[i].anno);
    if (date[i].anno==d.anno && date[i].mese<d.mese)
      printf("%02d/%02d/%02d\n", date[i].giorno, date[i].mese, date[i].anno);
    if (date[i].anno==d.anno && date[i].mese==d.mese && date[i].giorno<d.giorno)
      printf("%02d/%02d/%02d\n", date[i].giorno, date[i].mese, date[i].anno);
  }
  return 0;
}
