#include <stdio.h>

#define MAX 1000
#define LINE_SIZE 8

int read_line(char line[], int max);
void fold_line(char line[], int length);

int main()
{
  int c;
  char line[MAX];

  while ((c = read_line(line, MAX)) > 0)
      fold_line(line, c);

  return 0;
}

int read_line(char line[], int max)
{
  int c, i;
  i = 0;

  while (i < MAX - 3 && (c = getchar()) != EOF && c != '\n')
    {
      line[i] = c;
      i++;
    }

  if (c = '\n')
    {
      line[i] = c;
      i++;
    }

  line[i] = '\0';

  return i;
}

void fold_line(char line[], int length)
{
  int c, blank, i;
  c = 0;
  blank = -1;

  for (i = 0; i < length; i++)
    {
    c++;

    if (line[i] == ' ' || line[i] == '\t')
      blank = i;

    if (c >= LINE_SIZE)
      {
	if (blank != -1)
	  {
	    line[blank] = '\n';
	    c = i - blank;
	    blank = -1;
	  }
	else
	  {
	    putchar('\n');
	    c = 1;
	  }
      }
    putchar(line[i]);
    }
}



