#include <stdio.h>

void primo(int n) {
  int count=0;
  for (int i = 1; i <=n; i++) {
    if (n%i==0)
      count++;
  }
  if (count==2 || n==1)
    printf("%d è un numero primo\n", n);
  else
    printf("%d non è un numero primo\n", n);

}

int main(){
  int n;
  scanf("%d", &n);
  primo(n);
  return 0;
}
