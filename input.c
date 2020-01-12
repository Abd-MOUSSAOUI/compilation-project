#include <stdio.h>
#define M 20
#define N 10

int main()
{
  int i;
  int ty[10];
  int tx[22];

  int j;
  int tmp[M];
  int a[M][N];

  int alpha = 31;
  int beta = 97;


  for (i = 4; i < 3; i++) {
    ty[i] = 5 * tx[i] + ty[i];
  }

  for (i = 0; i < M; i++) {
    for(j=0; j< N; j++) {
      tmp[i] = alpha * a[i][j] * tx[i] + tmp[i];
    }
    ty[i] = beta * ty[i] + tmp[i];
  }


return 0;
}
