#define SPEC

void int_vec_set(int lo, int hi, int v[], int val) 
{
  int i;
  for (i = lo; i < hi; i++) {
    v[i] = val;
  }
}

