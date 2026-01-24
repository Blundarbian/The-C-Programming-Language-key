#include <stdio.h>
#include <stdlib.h>
#define SIZE 1000


void itoa(int n, char s[]);
void reverse(char s[]);

int main(void) {
  char s[SIZE];

  itoa(4321, s);
  printf("%s\n", s);
  
  return 0;
}

void itoa(int n, char s[]) {
  // convert n to characters in s
  int i, sign;

  if ((sign = n) < 0) // record sign
    n = -n;
  i = 0;

  do { // generate digits in reverse order
    s[i++] = abs(n % 10) + '0'; // get next digit
  } while ((n /= 10) > 0);

  if (sign < 0)
    s[i++] = '-';
  s[i] = '\0';

  reverse(s);
}

void reverse(char s[]) {
  int i, j;
  char temp;

  for (j = 0; s[j] != '\0'; j++)
    ;
  j--; // last position is null term, so minus 1
  
  for (i = 0; i < j; i++, j--) {
    temp = s[i];
    s[i] = s[j];
    s[j] = temp;
  }
}
