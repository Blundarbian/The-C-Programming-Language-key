#include <stdio.h>

#define SIZE 1000

void escape(char t[], char s[]);
void rescape(char s[], char t[]);
int get_line(char line[], int lim);

int main(void) {
  
  char t[SIZE];
  char s[SIZE];

  
  get_line(t, SIZE);

  escape(s, t);
  printf("%s\n", s);

  rescape(t, t);
  printf("%s\n", t);
  
  return 0;
}

int get_line(char line[], int lim) {
  int c, i;

  i = 0;
  while ((c = getchar()) != EOF && c != '\n' && i < lim - 1) {
    line[i] = c;
    i++;
  }
  
  line[i] = '\0';

  return i;
}

void escape(char t[], char s[]) {
  int i, j;

  for (i = j = 0; s[i] != '\0'; i++, j++) {
    switch (s[i]) {
    case '\a':
      t[j++] = '\\';
      t[j] = 'a';
      break;

    case '\b':
      t[j++] = '\\';
      t[j] = 'b';
      break;

    case '\f':
      t[j++] = '\\';
      t[j] = 'f';
      break;

    case '\n':
      t[j++] = '\\';
      t[j] = 'n';
      break;

    case '\r':
      t[j++] = '\\';
      t[j] = 'r';
      break;

    case '\t':
      t[j++] = '\\';
      t[j] = 't';
      break;

    case '\v':
      t[j++] = '\\';
      t[j] = 'v';
      break;

    case '\\':
      t[j++] = '\\';
      t[j] = '\\';
      break;

    case '\?':
      t[j++] = '\\';
      t[j] = '?';
      break;

    case '\'':
      t[j++] = '\\';
      t[j] = '\'';
      break;

    case '\"':
      t[j++] = '\\';
      t[j] = '"';
      break;

    default:
      t[j] = s[i];
      break;
    }
  }

  if (s[i] == '\0')
    t[j] = s[i];
}

void rescape(char s[], char t[]) {
  int i, j;

  for (i = j = 0; s[i] != '\0'; i++, j++) {
    switch (s[i]) {
    case '\\':
      switch (s[++i]) {
      case 'a':
	t[j] = '\a';
	break;

      case 'b':
	t[j] = '\b';
	break;

      case 'f':
	t[j] = '\f';
	break;

      case 'n':
	t[j] = '\n';
	break;

      case 'r':
	t[j] = '\r';
	break;

      case 't':
	t[j] = '\t';
	break;

      case 'v':
	t[j] = '\v';
	break;

      case '\\':
	t[j] = '\\';
	break;

      case '?':
	t[j] = '\?';
	break;

      case '\'':
	t[j] = '\'';
	break;

      case '"':
	t[j] = '\"';
	break;

      default:
	t[j++] = '\\';
	t[j] = s[i];
	break;
      }
      break;

    default:
      t[j] = s[i];
      break;
    }
  }

  if (s[i] == '\0') {
    t[j] = s[i];
  }
}
