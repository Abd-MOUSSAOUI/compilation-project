void test1(int lo, int hi, int v1[], int v2[]) 
{
    int i;
    for (i = lo; i < hi; i++) {
    int tmp = v2[i];
    v2[i] = v1[i];
    v1[i] = tmp;
  }
}
void test(int l, int h, int v[], int vx)
{
    int j;
    for (j = l; j < h; j--) {
      v[j] = vx;
    }
} 
int main()
{
  int a = 23;
  return 0;
}