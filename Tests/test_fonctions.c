void func1(int lo, int hi, int v[], int val) 
{
	int i;
	for (i = lo; i < hi; i++) 
	{
		v[i] = val;	
	}
}
void func2(int lo, int hi, int v1[], int v2[]) 
{
	int i;
	for (i = lo; i < hi; i++) 
	{
		int tmp = v2[i];
		v2[i] = v1[i];
		v1[i] = tmp;
	}
}
void func3(int lo, int hi, int a, int x[], int y[]) 
{
	int i;
	for (i = lo; i < hi; i++) 
	{
		y[i] = a * x[i] + y[i];
	}
}
int multiplication(int a, int b)
{
	return a*b;
}