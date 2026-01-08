#include <stdio.h>

#define ASCII 128

int main()
{
  int c, i, j;
  int letter[ASCII];

  for (i = 0; i < ASCII; i++)
    {
      letter[i] = 0;
    }

  while ((c = getchar()) != EOF)
    {
      if (c >= 0 && c <= 128)
	{
	  letter[c] += 1;
	}
    }

  for (i = 0; i < ASCII; i++)
    {
      if (letter[i] != 0)
	{
	  printf("%3d: %d|",i, letter[i]);
       
	  for (j = letter[i]; j > 0; j--)
	    {
	      printf("*");
	      
	    }

	  printf("\n");
	}
    }

  return 0;
}
