/* Exercise 7-8. Write a program to print a set of files, 
 * starting each new one on a new page, with a title and 
 * a running page count for each file
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100
#define LINEMAX 15
char *prog;

void printpage(FILE *, FILE *);

void printpage(FILE *in, FILE *out) {

	int c, line = 0;
	int pg = 1;

	while ((c = getc(in)) != EOF) {

		putc(c, out);

		if (c == '\n') {
			line++;

			if (line == LINEMAX) {
				fprintf(stdout, "\n\n\t --- pg %d --- \n\n", pg);
				pg++;
				line = 0;
			}
		}

	}
}

int main(int argc, char *argv[]) {

	prog = argv[0];
	FILE *fp;

	if (argc == 1) {
		fprintf(stderr, "error: no files\n");
		printpage(stdin, stdout);
	}
	else
		while  (--argc > 0) {
			if ((fp = fopen(*++argv, "r")) == NULL) {
				fprintf(stderr, "error: %s cannot open %s\n", prog, *argv);
				exit(1);
			}
			else {
				fprintf(stdout, "\n\n\t --- FILE : %s --- \n\n", *argv);
				printpage(fp, stdout);
				fclose(fp);
			}

			if (ferror(stdout) == 0)
				fprintf(stdout, "File %s written succesfully\n", *argv);
		}
	return 0;
}
