#include <stdio.h>

unsigned int setbits(unsigned int x, int p, int n, unsigned int y);

int main(void) {

  int p, n;
  p = 6;
  n = 3;
  unsigned int x, y;
  x = 240; // 11110000
  y = 15; // 00001111

  printf("%u\n", setbits(x, p, n, y));

  return 0;
}

unsigned int setbits(unsigned int x, int p, int n, unsigned int y) {

  int last_n = y & ~(~0 << n); // last n bits from y
  printf("%d\n", last_n);
  
  int set = last_n << (p - n); // move new bits to position
  printf("%d\n", set);
  
  int clear = ~(~(~0 << n) << (p - n)); // negate shift by post, negate
  printf("%d\n", clear);

  x = x & clear;
  printf("%d\n", x);

  return x | set;


}
  


