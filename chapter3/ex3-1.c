#include <stdio.h>
#define N 8

int binsearch(int x, int v[], int n);

int main(void) {
  int V[N] = {1, 3, 6, 7, 12, 21, 43, 112};
  
  printf("%d\n", binsearch(12, V, N));
  
  return 0;
}


int binsearch(int x, int v[], int n) {
  int low, high, mid;

  low = 0;
  high = n - 1;
  // only one compare in while
  
  while (low < high) {
    mid = (low + high) / 2;

    if (x > v[mid])
      low = mid + 1;
    else
      high = mid;
  }

  if (v[low] == x)
    return low;
  else
    return -1;
}
