#include <stdio.h>

int main(int argc, char const *argv[]) {
  int h1, m1, s1, h2, m2, s2;
  printf("Primo orario:\n");
  scanf("%d:%d:%d", &h1, &m1, &s1);
  printf("Secondo orario:\n");
  scanf("%d:%d:%d", &h2, &m2, &s2);
  int totale_secondi1=s1+(m1*60)+(h1*60*60);
  int totale_secondi2=s2+(m2*60)+(h2*60*60);
  int differenza = (totale_secondi1>=totale_secondi2)? totale_secondi1-totale_secondi2:totale_secondi2-totale_secondi1;
  int h_tot = differenza/3600;
  differenza=differenza%3600;
  int m_tot = differenza/60;
  int s_tot = differenza%60;
  printf("Intervallo:\n%d:%d:%d\n", h_tot, m_tot, s_tot);
  return 0;
}
