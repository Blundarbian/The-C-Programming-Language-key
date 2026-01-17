#include <stdio.h>

#define SIZE 100

int any(char s1[], char s2[]);

int main(void) {

  char s1[SIZE] = "david";
  char s2[SIZE] = "vince";

  printf("%d\n", any(s1, s2));

  return 0;
}

int any(char s1[], char s2[]) {
  int i, j;

  for (i = 0; s2[i] != '\0'; i++) {
    for (j = 0; s1[j] != '\0'; j++) {
      if (s1[j] == s2[i]) {
	return j; 
      }
    }
  }
  return -1; //if no occurence of s1 char found in s2
}


