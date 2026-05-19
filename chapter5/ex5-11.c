/* Exercise 5-11. Modify the program entab and detab 
 * (written as exercises in Chapter 1) to accept a 
 * list of tab stops as arguments. Use the default 
 * tab settings if there are no arguments.
 */

#include <stdio.h>
#define TAB 4

void entab(char *s);
void detab(char *s);

int main(int argc, char *argv[]) {

	for (int i = 1; i < argc; i++) {
		printf("Entabed %s: ", argv[i]);
		entab(argv[i]);
		printf("\n");
		printf("Detabed %s: ", argv[i]);
		detab(argv[i]);
		printf("\n");
	}

	return 0;
}

void entab(char *s) {
	char c;
	int space, pos;
	space = pos = 0;

	for (int i = 0; s[i] != '\0'; i++) {
		c = s[i];

		if (c == ' ') {
			space++;
			pos++;

			if (pos % TAB == 0) {
				putchar('\t');
				space = 0;
			} else {
				while (space > 0) {
					putchar(' ');
					space--;
				}

				if (c == '\n')
					pos = 0;
				else
					pos++;
			}
		}
	}
	while (space > 0) {
		putchar(' ');
		space--;
	}
}

void detab(char *s) {
	char c;

	for (int i = 0; s[i] != '\0'; i++) {
		c = s[i];

		if (c == '\t')
			for (int j = 0; j < TAB; j++)
				putchar(' ');
		else
			putchar(c);
	}
}
