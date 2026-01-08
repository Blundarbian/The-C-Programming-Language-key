#include <stdio.h>

#define MIN 80
#define MAX 1000

int length(char s[], int lim);

int main()
{
  int len;
  char line[MAX];

  while ((len = length(line, MAX)) > 0)
    if (len > MIN)
      {
	printf("%s\n", line);
      }
  
  return 0;
}

int length(char s[], int lim)
{
  int c, i;

  for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; i++)
    s[i] = c;

  if (c == '\n')
    {
      s[i] = c;
      i++;
    }

  s[i] = '\0';

  return i;
}
