/* Exercise 5-5 Write versions of the library functions 
   strncpy, strncat, and strncmp, which operate on at 
   most the first n characters of their argument strings. 
   For example, strncpy(s,t,n) copies at most n characters 
   of t to s. Full descriptions are in Appendix B
*/
#include <stdio.h>
#include <string.h>

//strcpy()
char *stringcopy(char *s, char *ct, int n) {
	char *start = s; // points to beginning of string
	int count = 0;

	while(*ct != '\0' && count < n) {
		*s = *ct;

		s++;
		ct++;
		count++;
	}

	*s = '\0';
	return start;
}

//strcat()
char *stringcat(char *s, char *ct, int n) {
	char *start = s;

	while (*s != '\0') // move to end of string s
		s++;
	while (*ct != '\0' && 0 < n) {
		*s = *ct;
		s++;
		ct++;
		n--;
	}
	*s = '\0';
	return start;
}

//strncmp
int stringcmp(char *cs, char *cst, int n) {
	while (n > 0) {
		if (*cs > *cst) {
			return *cs > *cst;
		} else if (*cs < *cst) {
			return *cs < *cst;
		}
		cs++;
		cst++;
		n--;
	}
	return 0;
}

int main(void) {
	char word1[50] = "Foo ";
	char word2[50] = "Bar ";
	char word3[50] = "Baz.";

	char *copy = stringcopy(word3, word2, strlen(word2));
	char *cat = stringcat(word1, word3, strlen(word3));
	int cmp = stringcmp(word1, word2, strlen(word2));

	printf("%s\n%s\n%d\n", copy, cat, cmp);

	return 0;
}
