#define SPEC

void int_vec_set(int lo, int hi, int v[], int zeb) {
  int i=20;
  while(i < hi) {
    v[i] = zeb;
    hi--;
  }
}

void test(int l, int h, int x[], int val) {
  int j=20;
  while(j < h) {
    x[j] = val;
    h--;
  }
}
