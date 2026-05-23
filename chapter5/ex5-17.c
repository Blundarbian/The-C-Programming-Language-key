/* Exercise 5-17. Add a field-searching capability, so sorting may 
 * bee done on fields within lines, each field sorted according to 
 * an independent set of options. (The index for this book was sorted 
 * with -df for the index category and -n for the page numbers.)
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAXLINES 5000

char *lineptr[MAXLINES];

int readlines(char *lineptr[], int nlines, int folding);
void writelines(char *lineptr[], int nlines);

void myqsort(void *v[], int left, int right,
		int (*comp)(const void *, const void *));

int numcmp(const char *s1, const char *s2);

void swap(void *v[], int i, int j);
void reverseptr(int nlines);

int main(int argc, char *argv[]) {

	int nlines;
	int numeric ,reverse ,folding; // prob should use an enum
	numeric = reverse = folding = 0;

	for (int i = 1; i < argc; i++) {
		if (argv[i][0] == '-')
			for (int j = 1; argv[i][j] != '\0'; j++) {

				switch (argv[i][j]) {
					case 'r':
						reverse = 1;
						break;

					case 'n':
						numeric = 1;
						break;

					case 'f':
						folding = 1;
							break;

					case 'd':
						if (folding == 1)
							folding = 3;
						else
							folding = 2;
							break;

					default:
						printf("error: unknown argument -%c\n", argv[i][j]);
				}
			}
	}

	if ((nlines = readlines(lineptr, MAXLINES, folding)) >= 0) {

		myqsort((void **) lineptr,
				0,
				nlines - 1,
				(int (*)(const void *, const void *))
				(numeric ? numcmp : strcmp));


		if (reverse)
			reverseptr(nlines);

		//writelines(lineptr, nlines);

		return 0;

	} else {
		printf("input too big to sort\n");
		return 1;
	}
}

void myqsort(void *v[], int left, int right,
		int (*comp)(const void *, const void *)) {

	int i, last;

	if (left >= right)
		return;

	swap(v, left, (left + right) / 2);

	last = left;

	for (i = left + 1; i <= right; i++) {
		if ((*comp)(v[i], v[left]) < 0)
			swap(v, ++last, i);
	}

	swap(v, left, last);

	myqsort(v, left, last - 1, comp);
	myqsort(v, last + 1, right, comp);
}

int numcmp(const char *s1, const char *s2) {

	double v1 = atof(s1);
	double v2 = atof(s2);

	if (v1 < v2)
		return -1;
	else if (v1 > v2)
		return 1;
	else
		return 0;
}

void swap(void *v[], int i, int j) {

	void *temp = v[i];
	v[i] = v[j];
	v[j] = temp;
}

//char *lineptr[MAXLINES];
void reverse(int nlines) {
	int i = 0;
	int j = nlines;
	char *temp;

	while (i < j) {
		temp = lineptr[i];
		lineptr[i] = lineptr[j];
		lineptr[j] = temp;
		i++;
		j--;
	}
}
