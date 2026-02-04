#include <stdio.h>
#include <stdlib.h>

void itoa(int n, char s[]);

int main(void) {

	char s[5];

	itoa(123, s);
	printf("%s\n", s);

	itoa(-123, s);
	printf("%s\n", s);

}

void itoa(int n, char s[]) {

	static int i; // keep i value consisteint for each recursive call

	if (n / 10) { 
		itoa(n / 10, s);

	} else { 
		i = 0;
		if (n < 0) {
			s[i++] = '-';
		}
	}

	s[i++] = abs(n % 10) + '0';
	s[i] = '\0'; // overwriten for each succesive digit

}

