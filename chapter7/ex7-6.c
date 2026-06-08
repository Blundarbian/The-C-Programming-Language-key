/* Exercise 7-6. Write a program to compare two files, 
 * printing the first line where they differ.
 */

#include <stdio.h>
#include <stdlib.h>

void opentest(FILE *, char *, char *);


FILE *fp1, *fp2;

int main(int argc, char **argv) {

	char *prog = argv[0];

	if (argc !=  3) {
		printf("error: only two files may be compared\n");
		exit(1);

	} else {
		opentest(fp1, prog, argv[1]);
		opentest(fp2, prog, argv[2]);
	}
	return 0;
}

void opentest(FILE *fp, char *prog, char *arg) {
	if ((fp = fopen(arg, "r")) == NULL) {
		printf("error : %s cannot open %s\n", prog, arg);
		exit(2);
	}
	return;
}
