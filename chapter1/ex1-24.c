#include <stdio.h>

#define STACK 100

char stack[STACK];
int stack_position = 0;

void skip_calend(void);
void skip_string(void);
void skip_blocks(void);
void skip_inline(void);
void push(char c);
char pop(void);

int main(void)
{
  int c;
  
  while ((c = getchar()) != EOF)
    {
    if (c == '/')
      {
	c = getchar();
	if (c == '/')
	  skip_inline();
	else if (c == '*')
	  skip_blocks();
      }
    
    else if (c == '"')
      skip_string();
    else if (c == '\'')
      skip_calend();
    else if (c == '{' || c == '[' || c == '(')
      push(c);  //push to global stack
    else if (c == '}' || c == ']' || c == ')')
      {
	char top = pop();
	if (top == '{' && c != '}')
	  {
	    printf("Error: expecting clossing braces!\n");
	    return 1;
	  }
	else if (top == '[' && c != ']')
	  {
	    printf("Error: expecting clossing bracket!\n");
	    return 1;
	  }
	else if (top == '(' && c != ')')
	  {
	    printf("Error: expecting closing parentheses!\n");
	    return 1;
	  }
	else if (top == 0)
	  {
	    printf("There is no matching opening brace, bracket, partentheses\n");
	    return 1;
	  }
      }
    }

  if (stack_position == 0)
    {
      printf("No errors, NICE!\n");
    }
  else
    {
      char top = pop();
      if (top == '{')
	{
	  printf("Error: no closing braces!\n");
	  return 1;
	}
      else if (top == '[')
	{
	  printf("Error: no closing brackets!\n");
	  return 1;
	}
      else
	{
	  printf("Error: no closing parantheses!\n");
	  return 1;
	}
    }
  return 0;
}


void push(char c)
{
  if (stack_position < STACK)
    {
      stack[stack_position] = c;
      ++stack_position;
    }
  else
    printf("Stack is Full!\n");
}  


char pop(void)
{
  if (stack_position > 0)
    {
      --stack_position;
      return stack[stack_position];
    }
  else
    return 0;
}


void skip_inline(void)
{
  int c;

  while ((c = getchar()) != EOF && c != '\n')
    ;
}


void skip_blocks(void)
{
  int c = getchar();
  int d = getchar();

  while (c != '*' || d != '/')
    {
      c = d;  //shift one character over for c and d
      d = getchar();
    }
}


void skip_string(void)
{
  int c;

  while ((c = getchar()) != '"')
    if (c == '\\')
      getchar();
}


void skip_calend(void)
{
  int c;

  while ((c = getchar()) != '\'')
    if (c == '\\')
      getchar();
}
