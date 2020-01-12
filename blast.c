#define SPEC

void axpy(int n, int a, int x[], int y[]) {
  int i;
  for (i = 0; i < n; i++) {
    y[i] = a * x[i] + y[i];
  }
}

void gemv(int trans, int m, int n, int alpha, int a[], int x[], int beta, int y[]) {
  int i;
  int j;
  int tmp[m];

  for (i = 0; i < m; i++) {
    for(j=0; j< n; j++) {
      tmp[i] = alpha * a[i][j] * x[i] + tmp[i];
    }
    y[i] = beta * y[i] + tmp[i];
  }
}
