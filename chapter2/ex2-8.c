#include <stdio.h>

unsigned int rightrot(unsigned int x, int n);
int unLen(void);

int main(void) {

  unsigned int x = 15;
  int n = 2;

  printf("%u\n", rightrot(x, n));

  return 0;
}

int unLen(void) {
  int len = 0;
  unsigned int x = (unsigned)~0;

  while (x != 0) {
    x = x >> 1;
    len++;
  }
  return len;
}

unsigned int rightrot(unsigned int x, int n) {
  int len = unLen();
  n = n % len;
  
  unsigned int final_n = ~(~0 << n) & x;
  x = x >> n;
  x = x | (final_n << (len - n));

  return x;
}










