#include <stdio.h>

int main() {
	// Coucou le test
	int a[5][6];
	a[4][2] = 5+4;

	int b;
	b = a[2*2][0+2] + 4;

	printf("\n");
	printf("\n");

	int i;
	int j;
	for(i=0;i<5;i++)
	{
		for(j=0;j<6;j++)
		{
			printf(" i : ");
			printf(" j : ");
			a[i][j] = i*j;
		}
		printf("\n");
	}

	for(i=0;i<5;i++)
	{
		for(j=0;j<6;j++)
		{
			printf("\n");
		}
	printf("Double boucle");
	}

	return 0;
}