#include <stdio.h>
#define L 40
#define N 30
#define M 20

int add(int a, int b) {
  return a+b;
}

int mult(int a, int b) {
  return a*b;
}

int func(int n, int x[], int y[]) {
  int i;
  for(i = 0; i < n; i++) {
    x[i] = y[i];
  }
}

int main(int argc, int argv)
{
  int i;
  int j;
  int k;
  int x[10];
  int y[10];

  for(i = 0; i < 10; i++) {
    x[i] = x[i] / 2;
  }

  for(i = 0; i < 10; i++) {
    x[i] = y[i];
  }

  for(i = 0; i< 10; i++) {
    x[i] = 2 * x[i];
  }

  for(i = 0; i < 10; i++) {
    int tmp = y[i];
    y[i] = x[i];
    x[i] = tmp;
  }

  for (i = 0; i < 10; i++) {
    y[i] = 5 * x[i] + y[i];
  }

  int a[30][10];
  int tmp1[30];
  for (i = 0; i < 30; i++) {
    for(j=0; j< 10; j++) {
      tmp1[i] = 2 * a[i][j] * x[i] + tmp1[i];
    }
    y[i] = 7 * y[i] + tmp1[i];
  }

  int c[L][N];
  int b[M][N];
  for(i = 0; i < L; i++) {
    for(j = 0; j< N; j++) {
      c[i][j] = 12 * c[i][j];
      for(k = 0; k< M; k++) {
        c[i][j] = c[i][j] + 17 * a[i][k]*b[k][j];
      }
    }
  }

  printf("fin\n");
  return 0;
}
