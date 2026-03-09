/* Exercise 5-3. Write a pointer version of the function 
   strcat that we showed in Chapter 2: strcat ( s, t) 
   copies the string t to the end of s.
*/
#include <stdio.h>

void stringcat(char *s, char *t) {
	// end of s
	while (*s) 
		++s;

	// t is copied to end of s
	while ((*s = *t)) {
		++s;
		++t;
	}
}

int main(void) {
	char s[100] = "Five";
	char t[] = " Six, Seven, Eight!";

	printf("s is val: %s\n", s);
	stringcat(s, t);

	printf("s is now: %s\n", s);
	
	return 0;
}
