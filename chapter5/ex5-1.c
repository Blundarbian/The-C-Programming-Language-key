/* Exercise 5-1. As written, getint treats a + or - not 
   followed by a digit as a valid representation of zero.
   Fix it to push such a character back on the input
*/
#include <stdio.h>
#include <ctype.h>

#define BUFF 100

int getint(int *pn);
int getch(void);
void ungetch(int);

char buf[BUFF];
int bufpos = 0;

int main(void) {

	int n, state;

	state = getint(&n);
	if (state == 0) 
		printf("no number found!\n");
	else if (state > 0) 
		printf("Number is %d\n", n);

	return 0;
}

int getint(int *pn) {
	
	int c, sign;

	// white space
	while(isspace(c = getch()))
		;

	// no number
	if(!isdigit(c) && c != EOF && c != '+' && c != '-') {
		ungetch(c);
		return 0;
	}

	//signs
	sign = (c == '-') ? -1 : 1;
	//skip signs
	if (c == '-' || c == '+') 
		c = getch();

	for (*pn = 0; isdigit(c); c = getch())
		*pn = *pn * 10 + (c - '0');

	*pn *= sign;

	if (c != EOF)
		ungetch(c);

	// char returned after the last digit is unget
	return c;
}


// get a pushback char if possible
int getch(void) { 
	return (bufpos > 0) ? buf[--bufpos] : getchar(); 
}

// push char to input 
void ungetch(int c) {
	if (bufpos >= BUFF)
		printf("ungetch: too many characters\n");
	else
		buf[bufpos++] = c;
}
