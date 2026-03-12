/* Exercise 5-6. Rewrite appropriate programs from earlier 
   chapters and exercises with pointers instead of array 
   indexing. Good possibilities include getline 
   (Chapters 1 and 4), atoi, itoa, and their variants 
   (Chapters 2, 3, and 4), reverse (Chapter 3), and 
   strindex and getop (Chapter 4). 
 */
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define WORD 50

int atoi(char *s);
void itoa(int n, char *s);
void reverse(char *s);
int strindex(char *s, char *t);
int getop(char *s);
int getch(void);
void ungetch(int c);

// atoi: convert s to integer
int atoi(char *s) {
	int n = 0;

	for ( ; *s >= '0' && *s <= '9'; ++s)
		n = 10 * n + (*s - '0');

	return n;
}

// itoa: convert n to characters in s
void itoa(int n, char *s) {
	char *start = s;
	int sign;

	if ((sign = n) < 0) 	// record sign
		n = -n;		// make n positive
	do {			// generate digits in reverse order
		*s++ = n % 10 + '0';	// get next digit
	} while ((n /= 10) > 0);	// delete it
	if (sign < 0)
		*s++ = '-';
	*s = '\0';
	reverse(start);
}

// reverse: reverse stirng s in place
void reverse(char *s) {
	char *n = s;
	char t;
	
	while(*s)
		s++;
	--s;

	while (n < s) {
		t = *n;
		*n = *s;
		*s = t;

		n++;
		--s;
	}
}

// strindex: returns index of t in s, -1 if none
int strindex(char *s, char *t) {
	char *sptr, *tptr;

	for (sptr = s; *sptr != '\0'; sptr++)	// if both match
		for (tptr = t; *tptr != '\0' && *sptr == *tptr; sptr++, tptr++)
			;	
	if (*tptr == '\0')
		return sptr - s;	// index match

	return -1;			// no match
}

// getop: get the next character or numeric operand

#define BUFSIZE 100
char buf[BUFSIZE];
int bufp = 0;

#define NUMBER '0'	// signal that a number was found
int getop(char *s) {
	int c;

	while ((*s = c = getch()) == ' ' || c == '\t')
		;
	*(s + 1) = '\0';

	if (!isdigit(c) && c != '.')
		return c;		// not a number

	if (isdigit(c))			// integer part
		while (isdigit(*++s = c = getch()))
			;		// incriment then deref 
	if (c == '.')			// fraction part
		while (isdigit(*++s = c = getch()))
			;
	*s = '\0';
	if (c != EOF)
		ungetch(c);
	return NUMBER;
}

// getch: get next character or numberic opperand
int getch(void) {
	return (bufp > 0) ? buf[--bufp] : getchar();
}

// ungetch: push back on input
void ungetch(int c) {
	if (bufp >= BUFSIZE)
		printf("ungetch: too many characters\n");
	else 
		buf[bufp++] = c;
}

int main(void) {
	
	// atoi
	char aword[WORD] = "100";
	char bword[WORD] = "32201";
	char cword[5] = "0123";
	int aval = atoi(aword);	
	int bval = atoi(bword);
	int cval = atoi(cword);
	printf("atio: %d, %d, %d\n", aval, bval, cval);

	// itoa
	char dword[WORD];
	itoa(1, dword);
	char eword[WORD];
	itoa(100, eword);
	char fword[WORD];
	itoa(2129, fword);
	printf("itoa: %s, %s, %s\n", dword, eword, fword);

	// reverse	
	reverse(aword);
	reverse(bword);
	reverse(cword);
	printf("reverse: %s, %s, %s\n", aword, bword, cword);

	// strindex
	char gword[WORD] = "pizzaslices";
	char hword[WORD] = "slices";
	char iword[WORD] = "zzas";
	int dex1 = strindex(gword, hword);
	int dex2 = strindex(hword, gword);
	int dex3 = strindex(gword, iword);
	printf("strindex: %d, %d, %d\n", dex1, dex2, dex3);	

	// getop	
	char jword[WORD];
	int top1 = getop(jword);
	int top2 = getop(jword);
	int top3 = getop(jword);
	printf("getop: %d, %d, %d\n", top1, top2, top3);

	return 0;
}
