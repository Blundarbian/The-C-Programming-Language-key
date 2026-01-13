#include <stdio.h>

void remove_inline(void);
void remove_blocks(void);
void handle_string(void);
void handle_consta(void);

int main(void)
{
  int c, d;

  while ((c = getchar()) != EOF)
    {
      if (c == '/')
	{
	  d = getchar();


	  if (d == '/')
	    remove_inline();
	  else if (d == '*')
	    remove_blocks();
	  
	  else
	    {
	      putchar(c);
	      putchar(d);
	    }
	}
      else if (c == '"')
	{
	  putchar(c);
	  handle_string();
	}
      else if (c == '\'')
	handle_consta();

      else
	putchar(c);
	
    }
}

void remove_inline(void)
{
  int c;

  while((c = getchar()) != EOF && c != '\n')
    ;

  if (c == '\n')
    putchar(c);

}

void remove_blocks(void)
{
  int c = getchar();
  int d = getchar();

  while (c != '*' || d != '/' || c == EOF)
    {
      c = d;
      d = getchar();
    }
}

void handle_string(void)
{
  int c, d;
  while ((c = getchar()) != '"')
    {
      putchar(c);

      if (c == '\\')
	{
	  d = getchar();
	  putchar(d);
	}
    }
  putchar(c);
}
	  
void handle_consta(void)
{
  int c, d;

  while ((c = getchar()) != '\'')
    {
      putchar(c);

      if (c == '\\')
	{
	  d = getchar();
	  putchar(d);
	}
    }
  putchar(c);
}
