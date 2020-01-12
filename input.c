#include <stdio.h>

int main() 
{
int i;
int ty[10];
int tx[22];
for (i = 0; i < 2; i++) 
{
tx[i] = 1;
}
for (i = 2; i < 31; i++) {
tx[i] = 2;
}
for (i = 0; i < 33; i++) {
ty[i] = 2 * 4 + 1;
}
for (i = 4; i < 3*4; i++) {
ty[i] = 5 * tx[i] + ty[i];
}
for (i = 0; i < 33; i++) {
printf("%d ", ty[i]);
}
printf("\n");
return 0;
}