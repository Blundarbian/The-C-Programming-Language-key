/* Exercise 5-2. Write getfloat, the floating-point analog 
   of getint. What type does getfloat return as its function 
   value? 
*/

#include <stdio.h>
#include <ctype.h>

#define BUFF 100

int getfloat(double *pn);
int getch(void);
void ungetch(int);

char buf[BUFF];
int bufpos = 0;

int main(void) {

	int state;
	double n;

	state = getfloat(&n);
	if (state == 0) 
		printf("no number found!\n");
	else if (state > 0) 
		printf("Number is %lf\n", n);

	return 0;
}

int getfloat(double *pn) {
	
	int c, sign, pow = 1;

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

	//digits before decimal
	for (*pn = 0; isdigit(c); c = getch()) 
		*pn = *pn * 10 + (c - '0');

	//digits after the decimal
	if (c == '.')
		c = getch();

	while (isdigit(c)) {
		*pn = 10.0 * *pn + (c - '0');
		pow = pow * 10.0;
		c = getch();
	}

	*pn = sign * *pn / pow;

	if (c != EOF)
		ungetch(c);

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
