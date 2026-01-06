#include <stdio.h>

int main()
{
  int c, x;

  while ((c = getchar()) != EOF)
    {
      x = 0;
      if (c == '\t')
	{
	  putchar('\\');
	  putchar('t');
	  x = 1;
	}
      if (c == '\b')
	{
	  putchar('\\');
	  putchar('b');
	  x = 1;
	}
      if (c == '\\')
	{
	  putchar('\\');
	  putchar('\\');
	}
      if (x == 0)
	putchar(c);
    }
  return 0;
}

      


	    
	   
		 
 
