#include <stdio.h>

#define TAB 4

int main()
{
  int c;
  unsigned int space;

  while ((c = getchar()) != EOF)
    {
      if (c == '\t')
	  for (space = TAB; space > 0; space--)
	    putchar(' ');
      
      else
	putchar(c);
    }
  
  return 0;
}







