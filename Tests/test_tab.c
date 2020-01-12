//include <stdio.h> for use printf
#include <stdio.h>

int test_tab() 
{
  // test tab et boocle for
  int tab1[5] = {1,2,3,4,5};
  int tab2[5][3][2][8][12];
  int tab3[10];
  int tab4[5][6];
  int i;
  for(i =0;i<10;i++)
  {
    tab3[i] = i+1;
  }
  int j;
  for(i=0;i<5;i++)
  {
    for(j = 0;j<=5;j++)
    {
      tab4[i][j] = (i+4)*(j/2);
      printf("\n");
    }
    printf("\n");
  }
  return 0;
}