#define SPEC

void scopy(int n, int x[], int incx, int y[], int incy) {
  int i;
  for(i = 0; i < n; i++) {
    x[i] = y[i];
  }
}

void sscal(int n, int a, int x[], int incx) {
  int i;
  for(i = 0; i< n; i++) {
    x[i] = a * x[i];
  }
}

void sswap(int n, int x[], int incx, int y[], int incy) {
  int i;
  for(i = 0; i < n; i++) {
    int tmp = y[i];
    y[i] = x[i];
    x[i] = tmp;
  }
}

void saxpy(int n, int a, int x[], int y[]) {
  int i;
  for (i = 0; i < n; i++) {
    y[i] = a * x[i] + y[i];
  }
}

void sgemv(int trans, int m, int n, int alpha, int a[], int x[], int beta, int y[]) {
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

void sgemm(int transa, int transb, int l, int n, int m, int alpha, int a[][], int lda, int b[][], int ldb, int beta, int c[][], int ldc) {
  int i;
  int j;
  int k;

  for(i = 0; i < l; i++) {
    for(j = 0; j< n; j++) {
      c[i][j] = beta * c[i][j];
      for(k = 0; k< m; k++) {
        c[i][j] = c[i][j] + alpha * a[i][k]*b[k][j];
      }
    }
  }
}
