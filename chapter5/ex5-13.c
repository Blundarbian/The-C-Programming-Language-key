/* Exercise 5-13. Write the program tail, which prints the last n 
 * lines of its input. By default, n is set to 10, let us say, 
 * but it can be changed by an optional argument so that tail -n 
 * prints the last n lines. The program should behave rationally 
 * no matter how unreasonable the input or the value of n. 
 * Write the program so it makes the best use of available storage;
 * lines should be stored as in the sorting program of 
 * Section 5.6, not in a two-dimensional array of fixed size.
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define BUFSIZE 1000 	// num of chars
#define WORDSIZE 100 	// num of words
#define DEFAULT 10 	// default tail size

char buf[BUFSIZE];
char *words[WORDSIZE];

void get_lines(void);
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

	get_lines();

	for (int i = 0; i < 10; i++)
		printf("%s\n", words[i]);

	return 0;
}

void get_lines() {
	int c, pos, word;
	pos = word = 0;

	words[word] = &buf[pos];
	while ((c = getchar()) != EOF && pos < BUFSIZE - 1) {
		if (c == '\n') {
			buf[pos++] = '\0';
			words[word++] = &buf[pos];
			continue;
		}
		buf[pos++] = c;
	}
	buf[pos++] = '\0';
}

