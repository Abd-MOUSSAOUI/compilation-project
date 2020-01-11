#define SPEC

void int_vec_set(int lo, int hi, int v[], int zeb) {
  int i=20;
  while(i < hi) {
    v[i] = zeb;
    hi--;
  }
}
