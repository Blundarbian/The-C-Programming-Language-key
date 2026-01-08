#include <stdio.h>

#define MAX 100

void reverse(char string[]);

int main()
{
  int c, i;
  i = 0;

  char string[MAX];

  while ((c = getchar()) != EOF)
    {
      string[i] = c;
      i++;

      if (c == '\n' || i == (MAX - 1)) //stops overflow from reaching reverse
	{
	  string[i] = '\0';
	  reverse(string);
	  i = 0;
	}
    }

  return 0;
}


void reverse(char string[])
{
  int len, i, j;

  len = 0;
  while (string[len] != '\0' &&  string[len] != '\n')
    len++;

  for (j = len - 1; j >= 0; j--)
    putchar(string[j]);

  putchar('\n');
}
  
      
