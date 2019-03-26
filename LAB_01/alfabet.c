#include <stdio.h>
#include <ctype.h>

int main(int argc, char const *argv[]) {
  char lettera;
  char low;
  scanf("%c", &lettera);

  if (('a'<=lettera && lettera<='z') || ('A'<=lettera && lettera<='Z')) {
    low=tolower(lettera);
    if (low=='a'||low=='e'||low=='i'||low=='o'||low=='u')
      printf("%c è una vocale\n", lettera);
    else
      printf("%c è una consonante\n", lettera);
  }
  else
    printf("%c non è un carattere dell'alfabeto\n", lettera);
  return 0;
}
