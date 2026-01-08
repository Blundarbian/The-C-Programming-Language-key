#include <stdio.h>

#define MAXLINE 22

int get_line(char line[], int maxline);
void copy(char to[], char from[]);

int main()
{
  int len, max;
  char line[MAXLINE];
  char longest[MAXLINE];

  max = 0;
  while ((len = get_line(line, MAXLINE)) > 0)
    {
      if (len > max)
	{
	  max = len;
	  
	  copy(longest, line);
	}
      
    }

  if (max > 0)
      printf("%s", longest);

  return 0;
}


int get_line(char s[], int lim)
{
  int c, i, j;

  for (i = 0, j = 0; i < lim-1 && (c=getchar()) != EOF && c != '\n'; i++)
      {
      if (i < lim -1)
	{
	  s[j] = c;
	  j++;
	}
      }
  
  if (c == '\n')
    {
      s[j] = c;
      j++;
    }
  s[i] = '\n';
  return i;
}


void copy(char to[], char from[])
{
  int i;

  i = 0;
  while ((to[i] = from[i]) != '\0')
    {
      ++i;
    }
}
