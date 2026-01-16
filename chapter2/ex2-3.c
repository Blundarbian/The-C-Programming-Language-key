#include <stdio.h>

unsigned int htoi(char s[]);

int main(void) {
  
  char s[] = "FED";
  int hex;

  hex = htoi(s);

  printf("%d\n", hex);

  return 0;
}

unsigned int htoi(char s[]) {
  int i, n, hex, digit;
  i = 0;

  if (s[i] == '0') {
    i++;

    if (s[i] == 'x' || s[i] == 'X')
      i++;
  }

  n = 0;
  hex = 1;

  while (hex == 1) {

    if (s[i] >= '0' && s[i] <= '9')
      digit = s[i] - '0';
    else if (s[i] >= 'a' && s[i] <= 'f')
      digit = s[i] - 'a' + 10;
    else if (s[i] >= 'A' && s[i] <= 'F')
      digit = s[i] - 'A' + 10;
    else
      hex = 0;

    if (hex == 1)
      n = 16 * n + digit;

    i++;
  }
  return n;
}
