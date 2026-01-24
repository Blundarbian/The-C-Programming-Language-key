#include <stdio.h>

#define SIZE 1000

void expand(char src[], char dest[]);
int get_length(char src[], int lim);

int main(void) {

  char src[SIZE];
  char dest[SIZE];

  get_length(src, SIZE);

  expand(src, dest);
  printf("%s\n", dest);
  
  return 0;
}

void expand(char src[], char dest[]) {
  int i, j;
  char c;

  i = j = 0;
  while ((c = src[i++]) != '\0') {
    if (src[i] == '-' && src[i + 1] >= c) {
      i++;
      while (c < src[i])
	dest[j++] = c++;
    }
    else dest[j++] = c;
  }
  dest[j] = '\0';
}

int get_length(char src[], int lim) {
  int c, i;

  i = 0;
  while ((c = getchar()) != EOF && c != '\n' && i < lim - 1) {
    src[i] = c;
    i++;
  }

  src[i] = '\0';

  return i;
}
