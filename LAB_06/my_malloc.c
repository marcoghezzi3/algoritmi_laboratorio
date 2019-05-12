#include <stdio.h>
#include <stdlib.h>

void *my_malloc(size_t size);
void *my_realloc(void *p, size_t size);

int main() {
  char *p;
  p = my_malloc(1);
  p = my_realloc(p, 15);
  return 0;
}

void *my_malloc(size_t size) {
  char *p;
  p = malloc(size);
  if (p==NULL) {
    printf("Allocazione fallita\n");
    exit;
  }
  else {
    printf("Allocazione riuscita\n");
    return p;
  }
}

void *my_realloc(void *p, size_t size) {
  p = realloc(p, size);
  if (p==NULL) {
    printf("Reallocazione fallita\n");
    exit;
  }
  else {
    printf("Reallocazione riuscita\n");
    return p;
  }
}
