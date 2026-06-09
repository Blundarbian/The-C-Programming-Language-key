/* Exercise 7-7. Modify the pattern finding program of Chapter 5 
 * to take its input from a set of named files or, if no files 
 * are named as arguments, from the standard input. Should the file
 * name be printed when a matching line is found?
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100
char *prog;

void patternfind(char *name, char *pattern);

int main(int argc, char **argv) {

	char pattern[MAX];
	prog = argv[0];

	if (argc < 2) {
		fprintf(stderr, "error: %s pattern is req\n", argv[0]);
		exit(1);
	}

	strlcpy(pattern, *++argv, MAX);

	if (argc > 2) {
		while (*++argv)
			patternfind(*argv, pattern);
	}
	else 
		patternfind(NULL, pattern);

	return 0;
}

void patternfind(char *name, char *pattern) {

	FILE *fp;
	char line[MAX];

	if (name == NULL) {
		fprintf(stderr, "error: no file name given\n");
		exit(2);
	}

	if ((fp = fopen(name, "r")) == NULL) {
		fprintf(stderr, "error: %s cannot open %s\n", prog, name);
		exit(3);
	}

	while (fgets(line, MAX, fp) != NULL) {
		if (strstr(line, pattern)) {
			if (name == NULL)
				printf("%s", line);
			else
				printf("%s %s", name, line);
		}
	}
	fclose(fp);
}
