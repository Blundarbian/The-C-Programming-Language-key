#include <stdio.h>
#include <stdlib.h>
#define SIZE 100 

void itoa(int n, char s[], int p);
void reverse(int len, char s[]);

int main(void) {

  char s[SIZE];
  itoa(420, s, 5);
  printf("%s\n", s);
  
  return 0;
}

void itoa(int n, char s[], int p) {
  int i, sign, digit;

  if ((sign = n) < 0)
    n = -n;

  i = 0;
  digit = abs(n);
  do {
    s[i++] = digit % 10 + '0';
  } while ((digit /= 10) > 0);

  if (sign < 0)
    s[i++] = '-';

  while (i < p)
    s[i++] = ' ';

  s[i] = '\0';

  reverse(i, s);
}

void reverse(int len, char s[]) {
  char c;
  int i, j = len - 1;

  for (int i = 0; i < j; i++) {
    c = s[i];
    s[i] = s[j];
    s[j] = c;

    j--;
  }
}
