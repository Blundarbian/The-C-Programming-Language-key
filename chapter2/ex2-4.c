#include <stdio.h>

#define SIZE 100

void squeeze(char s1[], char s2[]);

int main(void) {

  char s1[SIZE] = "vinnde";
  char s2[SIZE] = "vince";

  squeeze(s1, s2);

  printf("%s\n", s1);

  return 0;
}

void squeeze(char s1[], char s2[]) {
  int i, j, k;

  for (i = 0; s2[i] != '\0'; i++) {
    j = 0;
    for (k = 0; s1[k] != '\0'; k++) {
      if (s1[k] != s2[i]) {
	s1[j++] = s1[k];
      }
    }
    s1[j] = '\0';
  }
}

