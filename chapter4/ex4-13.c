#include <stdio.h>
#include <string.h>

void reverse(char s[]);
void do_rev(char s[], int i, int j);

int main(void) {

	char s[] = "Hello, world!";
	printf("%s\n", s);

	reverse(s);
	printf("%s\n", s);

}

void reverse(char s[]) {
	int i = 0;
	int j = strlen(s) - 1;

	do_rev(s, i , j); // recursive helper function
}

void do_rev(char s[], int i, int j) {
	if (i < j) {	

		char temp = s[i];
		s[i] = s[j];
		s[j] = temp;

		do_rev(s, i++, --j); // reverse substring
	}
}
