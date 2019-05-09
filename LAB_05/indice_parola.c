#include <stdio.h>
#include <string.h>

int smallest_word_index(char *s[], int n);

int main(void) {
  char *dict[] = { "ciao", "mondo", "aaa", "funziona", "bene", "questo", "programma"};
  int lun = 7, pos;
  pos = smallest_word_index(dict, lun);
  printf("La parola minima si trova in posizione %d.\n", pos);    //pos parte da 0
  return 0;
}

int smallest_word_index(char *s[], int n) {
  int min = 0;
  int i;
  for (i = 1; i < n; i++) {
    if (strcmp(s[i], s[min])<0)
      min = i;
  }
  return min;
}
