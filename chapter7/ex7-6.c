/* Exercise 7-6. Write a program to compare two files, 
 * printing the first line where they differ.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LINESIZE 200

FILE *opentest(char *, char *);

int main(int argc, char **argv) {

	FILE *fp1, *fp2;
	char line1[LINESIZE];
	char line2[LINESIZE];
	int linenum = 0;
	char *prog = argv[0];

	if (argc !=  3) {
		printf("error: only two files may be compared\n");
		exit(1);

	} else {
		fp1 = opentest(prog, argv[1]);
		fp2 = opentest(prog, argv[2]);

		char *f1, *f2;

		while (1) {

			f1 = fgets(line1, LINESIZE, fp1); 
			f2 = fgets(line2, LINESIZE, fp2);

			if (f1 == NULL && f2 == NULL) // same lengths
				break;

			if (f1 == NULL || f2 == NULL) { // atleast one is short
				printf("error : files differ in length\n");
				exit(3);
			}


			linenum++;
			if (strcmp(line1, line2) != 0) {
				printf("line number %d\n", linenum);
				printf("file %s : %s", argv[1], line1);
				printf("file %s : %s", argv[2], line2);
				exit(0);
			}
		}
	}
	fclose(fp1);
	fclose(fp2);
	return 0;
}

FILE *opentest(char *prog, char *arg) {

	FILE *fp;
	if ((fp = fopen(arg, "r")) == NULL) {
		printf("error : %s cannot open %s\n", prog, arg);
		exit(2);
	}
	return fp;
}
