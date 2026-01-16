#include <stdio.h>

#define SIZE 10

int main(void) {
  char c;
  char s[SIZE];
  int i;

  while (i < SIZE-1) {
    c = getchar();

    if (c == EOF)
      break;

    if (c == '\n')
      break;

    s[i] = (char)c;
    i++;
  }
	
  printf("%s\n", s);

  return 0;
}

  
  
