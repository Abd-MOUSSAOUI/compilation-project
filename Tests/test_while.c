#include <stdio.h>

void test_while() 
{
    int a = 55;
    while(a > 0)
    {
        printf("a égale à : %d\n",a);
        a--;
    }
    while(1)
    {
        printf("boucle infini...");
    }

}