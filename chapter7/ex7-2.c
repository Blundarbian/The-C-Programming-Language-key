/* Exercise 7-2. Write a program that will print arbitrary input 
 * in a sensible way. As a minimum, it should print non-graphic 
 * characters in octal or hexadecimal according to local custom, 
 * and break long text lines.
 */

#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 100

int main() {

	char line[SIZE];
	int graphic = 0;
	int nongraphic = 0;

	while (fgets(line, SIZE, stdin) != NULL) {
		for (int i = 0; line[i] != '\0'; i++) {
			if (isalpha(line[i])) graphic++;
			if (isdigit(line[i])) nongraphic++;
		}
		line[strcspn(line, "\n")] = 0;

		if (graphic > 0)
			printf("Graphical: %s\n", line);
		else {
			int val = atoi(line);
			printf("NonGraphical: %o, %x\n", val, val);
		}

		graphic = nongraphic = 0;
	}
	return 0;
}
