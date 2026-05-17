/*Exercise 5-7. Rewrite readlines to store lines in an array 
  supplied by main, rather than calling alloc to maintain 
  storage. How much faster is the program
*/
#include <stdio.h>
#include <string.h>

#define MAXLINES 5000 // max # of lines

char *lineptr[MAXLINES];
char lines[MAXLINES];

int readlines(char *lineptr[], int nlines);
void writelines(char *lineptr[], int nlines);

void qsort(char *v[], int left, int right);
void swap(char *v[], int i, int j);

int getline_(char s[], int lim);


int main() {
	int nlines; // number of input lines read
	
	if ((nlines = readlines(lineptr, MAXLINES)) >= 0) {
		qsort(lineptr, 0, nlines - 1);
		writelines(lineptr, nlines);
		return 0;
	} else {
		printf("error: input too big to sort\n");
		return -1;
	}
}

int getline_(char s[], int lim) {
	int c, i;

	for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; i++)
		s[i] = c;
	if (c == '\n') {
		s[i] = c;
		++i;
	}
	s[i] = '\0';
	return i;
}

#define MAXLEN 1000 // max len of any input line
		    
char *alloc(int);
static char bufAlloc[MAXLEN];  // alloc storage buf
static char *allocp = bufAlloc; // free pos for alloc

// return ptr to n chars
char *alloc(int n) {
	
	if (bufAlloc + MAXLEN - allocp >= n) {
		allocp += n;
		return allocp - n;
	} else
		return 0;
}

// readlines: read input lines
int readlines(char *lineptr[], int maxlines) {
	int len, nlines;
	char *p, line[MAXLEN];

	nlines = 0;
	while ((len = getline_(line, MAXLEN)) > 0)
		if (nlines >= maxlines || (p = alloc(len)) == NULL)
			return -1;
		else {
			line[len - 1] = '\0';
			strcpy(p, line);
			lineptr[nlines++] = p;
		}
	return nlines;
}

// writelines: write output lines
void writelines(char *lineptr[], int nlines) {
	int i;
	
	for (i = 0; i < nlines; i++)
		printf("%s\n", lineptr[i]);
}

// qsort: sort v[left] ... v[right] into order
void qsort(char *v[], int left, int right) {

	int i, last;
	void swap(char *v[], int i, int j);

	if (left >= right) // do nothing if arr contains
		return;
	swap(v, left, (left + right) / 2);
	last = left;

	for (i = left + 1; i <= right; i++)
		if (strcmp(v[i], v[left]) < 0)
			swap(v, ++last, i);
	swap(v, left, last);
	qsort(v, left, last - 1);
	qsort(v, last + 1, right);
}

// swap: interchange v[i] and v[j]
void swap(char *v[], int i, int j) {
	
	char *temp;

	temp = v[i];
	v[i] = v[j];
	v[j] = temp;
}
