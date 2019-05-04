#include <stdio.h>
#include <ctype.h>

int main(int argc, char const *argv[]) {
  int r, c;
  scanf("%d %d", &r, &c);
  char mat[r][c];
  char ch;
  scanf("%c", &ch);
  for (int i = 0; i < r; i++) {
    for (int j = 0; j <= c; j++) {
      ch=getchar();
      if (ch!='\n')
      mat[i][j]=ch;
    }
  }
  for (int j = 0; j < c; j++) {
    int temp;
    for (int i = r-1; i>=0; i--) {
      if (mat[i][j]=='*') {
        temp=i;
        break;
      }
    }
    for (int i = temp; i>=0; i--) {
      if(isalpha(mat[i][j])) {
        mat[temp--][j]=mat[i][j];
        mat[i][j]='*';
      }
    }
  }
  printf("\n");
  for (int i = 0; i < r; i++) {
    for (int j = 0; j < c; j++)
      printf("%c", mat[i][j]);
    printf("\n");
  }

  return 0;
}
