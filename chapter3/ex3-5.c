#include <stdio.h>
#include <stdlib.h>
#define SIZE 100

void itob(int n, char s[], int b);
void reverse(char s[]);


int main(void) {
  char s[SIZE];

  itob(420, s, 16);
  printf("%s\n", s);
  
  return 0;
}

void itob(int n, char s[], int b) {

  int i, sign, digit;

  if ((sign = n) < 0)
    n = -n;
    
  i = 0;
    do {
      digit = abs(n % b);
      s[i++] = (digit <= 9) ? digit + '0': digit - 10 + 'a';
      
  } while ((n /= b) > 0);

    if (sign < 0)
      s[i++] = '-';

    s[i] = '\0';
    reverse(s);
}

void reverse(char s[]) {
  int i, j;
  char c;

  for (j = 0; s[j] != '\0'; j++)
    ;
  j--; // remove null term... idk it took me soo long to remeber this T_T 

  for (i = 0; i < j; i++, j--) {
    c = s[i];
    s[i] = s[j];
    s[j] = c;
  }
}
