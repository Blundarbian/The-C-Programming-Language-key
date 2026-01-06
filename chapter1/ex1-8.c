#include <stdio.h>

int main()
{
  int blank, tab, new;

  blank = 0;
  tab = 0;
  new = 0;

  int c;

  while ((c = getchar()) != EOF)
    {
      if (c == '\n')
	++new;
      if (c == '\t')
	++tab;
      if (c == ' ')
	++blank;
    }

  printf("Blank: %d\nTabs: %d\nNewLines: %d", blank, tab, new);
}
       
.
