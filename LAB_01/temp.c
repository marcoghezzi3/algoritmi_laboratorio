#include <stdio.h>

int main(int argc, char const *argv[]) {
  int fah = 0;
  scanf("%d", &fah);
  int celsius = (fah-32)*5/9;
  printf("%d gradi Fahrenheit sono %d° Celsius\n", fah, celsius);
  return 0;
}
