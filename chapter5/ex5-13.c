/*
 *
 */

#include <stdio.h>
#include <string.h>

#define LINES 1000 // num of lines
#define SIZE 100 // max size of each line
#define DEFAULT 10 // default tail size

char *lines[LINES];
void get_line(char *s);
void printline(void);

int main(int argc, char *argv[]) {
	int i, n = 0;
	
	if (argc == 1) {
		n = DEFAULT;

	} else if (argc == 2 && argv[1][0] == '-') {
		n = atoi(argv[1] + 1);

	} else {
		printf("error: -n syntax not found");
		return 1;
	}

	for (i = 0; i < n; i++) {
		char s[SIZE];
		get_line(s);
	}

	return 0;
}

void get_line(char *s) {
	int c, i = 0;

	while ((c = getchar()) != EOF && c != '\n' && i < SIZE - 1)
		s[i++] = c;

	if (c == '\n')
		s[i++] = c;
	s[i] = '\0';

}

