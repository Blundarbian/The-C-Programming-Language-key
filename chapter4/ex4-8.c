#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
#include <string.h>

#define MAXOP 100
#define NUMBER '0'
#define MATH '1'

int sp = 0;
double val[MAXOP];

int getch(void);
void ungetch(int);
int getop(char[]);
void push(double);
double pop(void);
void unget(char s[]);


int main() {

	int type;
	double op2;
	char s[MAXOP];

	while ((type = getop(s)) != EOF) {
		switch (type) {

			case NUMBER:
				push(atof(s));
				break;

			case MATH:	
				if (strcmp(s, "sin") == 0) {
					push(sin(pop()));
				} else if (strcmp(s, "cos") == 0) {
					push(cos(pop()));
				} else if (strcmp(s, "exp") == 0) {
					push(exp(pop()));
				} else if (strcmp(s, "pow") == 0) {
					op2 = pop();
					push(pow(pop(), op2));
				} else {
					printf("error: math command / function %s unkown\n", s);
				}
				break;

			case '+':
				push(pop() + pop());
				break;

			case '*':
				push(pop() * pop());
				break;

			case '-':
				op2 = pop();
				push(pop() - op2);
				break;

			case 'p':
				op2 = pop();
				printf("\t%.8g\n", op2);
				push(op2);
				break;

			case 'd':
				op2 = pop();
				push(op2);
				push(op2);
				break;

			case 's':
				op2 = pop();
				double op3 = pop();
				push(op2);
				push(op3);
				break;

			case 'c':
				sp = 0;
				break;

			case '/':
				op2 = pop();
				if (op2 != 0.0)
					push(pop() / op2);
				else
					printf("error: zero divisor\n");
				break;

			case '%':
				op2 = pop();
				if (op2 != 0.0)
					push(fmod(pop(), op2));
				else
					printf("error: zero divisor\n");
				break;

			case '\n':
				if (sp > 0)
					printf("\t%.8g\n", pop());
				else
					printf("error: stack empty\n");
				break;

			default:
				printf("error: unknown command %s\n", s);
				break;
		}
	}
	return 0;
}


void push(double f) {
	if (sp < MAXOP)
		val[sp++] = f;
	else
		printf("error: stack full, can't push %g\n", f);
}

double pop(void) {
	if (sp > 0)
		return val[--sp];
	else {
		printf("error: stack empty\n");
		return 0.0;
	}
}

int getop(char s[]) {
	int i, c;

	while ((s[0] = c = getch()) == ' ' || c == '\t')
		;
	s[1] = '\0';
	i = 0;	
	if (islower(c)) {
		while (islower(s[++i] = c = getch())) {
			;
		}
		s[i] = '\0';
		if (c != EOF) {
			ungetch(c);
		}
		return MATH;
	}
	if (!isdigit(c) && c != '.' && c != '-') {
		return c;
	}


	if (c == '-') {
		if (isdigit(c = getch()))
			s[++i] = c;
		else {
			if (c != EOF)
				ungetch(c);
			return '-';
		}
		;
	}

	if (isdigit(c))
		while (isdigit(s[++i] = c = getch()))
			;
	if (c == '.')
		while (isdigit(s[++i] = c = getch()))
			;
	s[i] = '\0';
	if (c != EOF)
		ungetch(c);
	return NUMBER;
}

char push_back = -1;

int getch(void) {
	if (push_back == -1) {
		return getchar();
	} else {
		char r;
		r = push_back;
		push_back = -1;
		return r;
	}
}

void ungetch(int c) {

	push_back = c;
}


