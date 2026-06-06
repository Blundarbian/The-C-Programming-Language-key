/* Exercise 7-1. Write a program that converts upper case to lower 
 * or lower case to upper, depending on the name it is invoked with, 
 * as found in argv[0].
 */

#include <stdio.h>
#include <string.h>
#include <ctype.h>

enum change { UPPER, LOWER };

int main(int argc, char *argv[]) {
	
	int c;
	enum change opt; 
	if (strcmp(argv[0], "./lower") == 0) 
		opt = LOWER;
	else if (strcmp(argv[0], "./upper") == 0) 
		opt = UPPER;
	else {
		printf("error: %s unrecognized command\n", argv[0]);
		return 1;
	}

	while ((c = getchar()) != EOF) {
		if (opt == LOWER)
			putchar(tolower(c));
		else
			putchar(toupper(c));
	}

	return 0;
}
