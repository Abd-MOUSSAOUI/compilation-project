int func(int l, int n, int m, int alpha, int a[][], int b[][], int beta, int c[][])
{
  int i;
  int j;
  int k;

  for(i = 0; i < 40; i++) {
    for(j = 0; j< 30; j++) {
      c[i][j] = 15 * c[i][j];
      for(k = 0; k< 20; k++) {
        c[i][j] = c[i][j] + 75 * a[i][k]*b[k][j];
      }
    }
  }
return 0;
}
