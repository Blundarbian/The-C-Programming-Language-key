/* Exercise 7-2. Write a program that will print arbitrary input 
 * in a sensible way. As a minimum, it should print non-graphic 
 * characters in octal or hexadecimal according to local custom, 
 * and break long text lines.
 */

#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define SIZE 100

int main() {

	char line[SIZE];
	int graphic, nongraphic = 0;

	while (fgets(line, SIZE, stdin) != NULL) {
		for (int i = 0; line[i] != '\0'; i++) {
		}
	}
	return 0;
}
