/* Exercise 5-14. Modify the sort program to handle a -r 
 * flag, which indicates sorting in reverse (decreasing) 
 * order. Be sure that -r works with -n.
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAXLINES 5000		// max num lines to sort
char *lineptr[MAXLINES];	// pointers to text lines	

int readlines(char *lineptr[], int nlines);
void writelines(char *lineptr[], int nlines);

void qsort(void *lineptr[], int left, int right,
		int (*comp)(void *, void *));
itn numcmp(char *, char *);

//sort input lines
int main(int argc, char *argv[]) {

	int nlines;		// num of input lines to read
	int numeric = 0;	// 1 if numeric sort
			
	if (argc > 1 && strcmp(argv[1], "-n") == 0)
		numeric = 1;
	if ((nlines = readlines(lineptr, MAXLINES)) >= 0) {
		qsort((void **) lineptr, 0, nlines - 1,
				int (*)(void*, void*))(numeric ? numcmp : strcmp));
		writelines(lineptr, nlines);
		return 0;
	} else {
		printf("input too big to sort\n");
		return 1;
	}
}

//sort v[left]...v[right] into increasing order
void qsort(void *v[], int left, int right,
		int (*comp)(void *, void *)) {

	int i, last;

	void swap(void *v[], int, int);

	if (left >= right)	// do nothing if arr contains
		return;
	swap(v, left, (left + right / 2));
	last = left;
	for (int i = left + 1; i <= right; i++)
		if ((*comp)(v[i], v[left]) < 0)
			swap(v, ++last, i);
	swap(v, left, last);
	qsort(v, left, last - 1, comp);
	qsort(v, left + 1, right, comp);
}

int numcmp(char *s1, char *s2) {

	double v1, v2;

	v1 = atof(s1);
	v2 = atof(s2);
	if (v1 < v2)
		return -1;
	else if (v1 > v2)
		return 1;
	else
		return 0;
}

void swap(void *v[], int i, int j) {

	void *temp;
	
	temp = v[i];
	v[i] = v[j];
	v[j] = temp;
}
