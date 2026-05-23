/* Exercise 5-14. Modify the sort program to handle a -r 
 * flag, which indicates sorting in reverse (decreasing) 
 * order. Be sure that -r works with -n.
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAXLINES 5000

char *lineptr[MAXLINES];

int readlines(char *lineptr[], int nlines);
void writelines(char *lineptr[], int nlines);

void myqsort(void *v[], int left, int right,
             int (*comp)(const void *, const void *));

int numcmp(const char *s1, const char *s2);

void swap(void *v[], int i, int j);
void reverse(int nlines);

int main(int argc, char *argv[]) {

    int nlines;
    int numeric = 0;

    if (argc > 1 && strcmp(argv[1], "-n") == 0)
        numeric = 1;


    if ((nlines = readlines(lineptr, MAXLINES)) >= 0) {

        myqsort((void **) lineptr,
                0,
                nlines - 1,
                (int (*)(const void *, const void *))
                (numeric ? numcmp : strcmp));

	if (argc > 2 && strcmp(argv[2], "-r") == 0)
		reverse(nlines);

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
