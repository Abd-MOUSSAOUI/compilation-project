//include <stdio.h> for use printf
#include <stdio.h>

void test_if_else()
{
  int c;
  int z;
  if(1<2)
  {
    int a = 45;
    c = 35;
    z = 0;
    int b = a * c - 24 + 33 / z;
    printf("True \n");
  }
  else
  {
    int tab[10];
    c = 90;
    z = 123;
    int d = tab[3] * c - 24 + 33 / z;
    printf("False\n");
  }
}