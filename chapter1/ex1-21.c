#include <stdio.h>

#define TAB 4

int main()
{
  int c;
  unsigned int space, pos;
  space = pos = 0;

  while ((c = getchar()) != EOF)
    {
      if (c == ' ')
	{
	  ++space;

	  if (pos % TAB == 0 && space > 1)
	    {
	      putchar('\t');
	      space = 0;
	    }
	}
      else
	{
	  while (space)
	    {
	      putchar(' ');
	      --space;
	    }

	  if (c == '\n')
	    pos = 0;

	  putchar(c);

	}
    }

  return 0;
}

	      

