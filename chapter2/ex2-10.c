#include <stdio.h>

void lower(int c);

int main(void) {
  int c;

  while ((c = getchar()) != EOF)
    lower(c);

  return 0;
}

void lower(int c) {
  (64 < c && c < 91) ? putchar(c + 32) : putchar(c);
}
