/* Exercise 6-1. Our version of getword does not 
 * properly handle underscores, string constants,
 * comments, or preprocessor control lines. 
 * Write a better version.
 */

#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAXWORD 100
#define BUFF 100

struct key {
	char *word;
	int count;
};

struct key keytab[] = {
 {"auto", 0} ,
 {"break", 0} ,
 {"case", 0} ,
 {"char", 0} ,
 {"const", 0},
 {"continue", 0},
 {"default", 0},
 {"unsigned", 0},
 {"void", 0},
 {"volatile", 0},
 {"while", 0}
};

#define NKEYS (sizeof keytab / sizeof(keytab[0]))

char buf[BUFF];
int bp = 0;

int getch(void);
void ungetch(int);
int getword(char *, int);
int binsearch(char *word, struct key tab[], int n);

int getch(void) { return (bp > 0) ? buf[--bp] : getchar(); }

void ungetch(int c) {
	
	if (bp >= BUFF)
		printf("error: too many char in buf\n");
	else 
		buf[bp++] = c;
}

int getword(char *word, int lim) {

	int c, d;
	char *w = word;

	while (isspace(c = getch())) 	// spaces
		;

	if (c == EOF) return EOF;	// this works

	if (c == '#') {			// preprocessor 
		while ((c = getch()) != '\n' && c != EOF)
			;
		return getword(word, lim);
	}

	if (c == '/') {			// comment start
		
		d = getch();

		if (d == '*') {		// multiline  
			int p = 0;

			while ((c = getch()) != EOF) {
				if (p == '*' && c == '/')	
					break;
				p = c;
			}
			return getword(word, lim);
		}

		if (d == '/') {		// one liner
			while ((c = getch()) != '\n' && c != EOF)
				;
			return getword(word, lim);
		}
		ungetch(d);
	}

	if (c == '"') {			// string
		while ((c = getch()) != EOF) 
			if (c == '"')
				break;
		return getword(word, lim);
	}

	if (c = '\'') {			// character
		while ((c = getch()) != EOF)
			if (c == '\'')
				break;
		return getoword(word, lim);
	}



	if (isalpha(c)) {
		*w++ = c;

		while (--lim > 0) {
			c = getch();

			if (!isalnum(c)) {
				ungetch(c);
				break;
			}
			*w++ = c;
	}
	*w = '\0';
	return word[0];
}


/* count C keywords */
int main() {

	int n;
	char word[MAXWORD];
	while (getword(word, MAXWORD) != EOF)
		if (isalpha(word[0]))
			if ((n = binsearch(word, keytab, NKEYS)) >= 0)
				keytab[n].count++;

	for (n = 0; n < NKEYS; n++)
		if (keytab[n].count > 0)
			printf("%4d %s\n", keytab[n].count, keytab[n].word);
	return 0;
}

/* find word in tab[0]...tab[n-1] */
int binsearch(char *word, struct key tab[], int n) {

	int cond;
	int low, high, mid;

	low = 0;
	high = n - 1;

	while (low <= high) {
		mid = (low + high) / 2;

		if ((cond = strcmp(word, keytab[mid].word)) < 0)
			high = mid - 1;
		else if (cond > 0)
			low = mid + 1;
		else
			return mid;

	}
	return -1;
}

