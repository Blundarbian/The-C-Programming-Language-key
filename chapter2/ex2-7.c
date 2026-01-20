#include <stdio.h>

unsigned int invert(unsigned int x, int p, int n);

int main(void) {

  unsigned x = 120;
  int p, n;
  p = 6;
  n = 3;

  printf("%u\n", invert(x, p, n));

  return 0;
}

unsigned int invert(unsigned int x, int p, int n) {

  unsigned int flip = (~(~0 << n)) << (p - n);
  x = x ^ flip; //XOR compare to invert
  return x;
}
