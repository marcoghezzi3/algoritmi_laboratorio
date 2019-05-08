#include <stdio.h>
#define N 100

void stampa(int a[], int lung);
void scambia(int a[], int i, int j);
int max (int a[], int lung);
void selectionsort(int a[], int n);
void merge(int a[], int sx, int m, int dx);
void mergesort(int a[], int sx, int dx);

int main() {
  int a[N] = {0};
  int lung = 0;
  for (int i = 0; i < N; i++) {
    scanf("%d", &a[i]);
    lung++;
    if (a[i]==0)
      break;
  }
  lung--;
  mergesort(a, 0, lung-1);
  //selectionsort(a, lung);
  stampa(a, lung);
  return 0;

}

void stampa(int a[], int lung) {
  for (int i = 0; i < lung; i++)
    printf("%d ", a[i]);
  printf("\n");
}

void scambia(int a[], int i, int j) {
  int temp = a[i];
  a[i] = a[j];
  a[j] = temp;
}

int max(int a[], int lung) {
  int i = 0;
  int max = a[i];
  for (int j = 1; j < lung; j++) {
    if (a[j]>max) {
      max = a[j];
      i = j;
    }
  }
  return i;
}
void merge(int a[], int sx, int m, int dx) {
  int i1 = m-sx+1;  //dimensione array sinistro
  int i2 = dx-m;    //dimensione array destro
  int L[i1], R[i2];
  int i, j, k;
  for(i = 0; i < i1; i++)
    L[i] = a[sx+i];
  for(j = 0; j < i2; j++)
    R[j] = a[m+1+j];
  i = 0;
  j = 0;
  k = sx;
  while(i<i1 && j<i2) { //finché i e j sono minori dei temp array creati
    if(L[i]<=R[j]) {
      a[k]=L[i];
      i++;
    }
    else {
      a[k]=R[j];
      j++;
    }
    k++;
  }
  while(i<i1) {
    a[k]=L[i];
    k++;
    i++;
  }
  while(j<i2) {
    a[k]=R[j];
    k++;
    j++;
  }
}

void mergesort(int a[], int sx, int dx) {
  if (sx<dx) {
    int m = (sx+dx)/2;
    mergesort(a, sx, m);
    mergesort(a, m+1, dx);
    merge(a, sx, m, dx);
  }
}

void selectionsort(int a[], int n) {
  if (n==1)
    return;
  int i = max(a, n);
  scambia(a, i, n-1);
  selectionsort(a, n-1);
}
