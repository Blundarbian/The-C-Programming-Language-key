#include <stdio.h>

#define MAX_WORD_SIZE 10

int main()
{
  int c, i, j, count;
  int words[MAX_WORD_SIZE];

  for (i = 0; i < MAX_WORD_SIZE; i++)
    {
      words[i] = 0;
    }

  while ((c = getchar()) != EOF) //find word length count 
    {
      if (c == ' ' || c == '\n' || c == '\t')
	{
	  words[count] += 1;
	  words[0] += 1;
	  count = 0;
	}
      else
	{
	  ++count;
	}
    }

  for (i = 0; i < MAX_WORD_SIZE; i++) //print histogram
    {
      printf("length %d, %d: ", i+1, words[i]);

      for (j = words[i]; j > 0; j--)
	{
	  printf("*");
	}
      
      printf("\n");
    }

  for (i = 0; i < MAX_WORD_SIZE; i++) //print array
    {
      printf("%d ", words[i]);
    }
  
}
