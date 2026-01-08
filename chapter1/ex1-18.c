#include <stdio.h>

#define MAX 1000

void blanks(char line[], int len);
int length(char s[], int lim);

int main()
{
  int len;
  char line[MAX];

  while ((len = length(line, MAX)) > 0)
    {
      blanks(line, len);
      printf("%s", line);
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

void blanks(char s[], int len)
{
  int i;

  for (i = 0; i <= len; i++)
    {
      if (s[i]  == ' ' || s[i] == '\t')
	s[i] = '\b';

      else
	i = len + 1;
    }
}
