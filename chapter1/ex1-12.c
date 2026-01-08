#include <stdio.h>

int main()
{
  int c, word;
  word = 1;

    while ((c = getchar()) != EOF)
      {
	if (c == ' ' || c == '\t' || c == '\n')
	  word = 0;
	else if (word == 0)
	  {
	    word = 1;
	    putchar('\n');
	  }
	putchar(c);
      }
  return 0;
}
