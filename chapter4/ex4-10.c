#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
#include <string.h>

#define MAXOP 100
#define NUMBER '0'
#define MAXLINE 100

int sp = 0;
int bufp = 0;
char buf[MAXOP];
double val[MAXOP];

int getop(char[]);
void push(double);
double pop(void);
int my_getline(int lim, char s[]);

int main() {

	int type;
	double op2;
	char s[MAXOP];

	while ((type = getop(s)) != EOF) {
		switch (type) {

			case NUMBER:
				push(atof(s));
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

char line[MAXLINE] = { 0 };
int line_index = 0;

enum boolean {NO, YES};
enum boolean read_line = NO;

int getop(char s[]) {

	if (read_line == NO || line[line_index] == '\0') {
		my_getline(MAXLINE, line);
		read_line = YES;
		line_index = 0;
	}
	if (strlen(line) == 0) {
		return EOF;
	}

	int i, c;

	while ((s[0] = c = line[line_index++]) == ' ' || c == '\t')
		;
	s[1] = '\0';

	if (!isdigit(c) && c != '.' && c != '-')
		return c;

	i = 0;

	if (c == '-') {
		if (isdigit(c = line[line_index++]))
			s[++i] = c;
		else {
			if (c != EOF)
				--line_index;
			return '-';
		}
		;
	}

	if (isdigit(c))
		while (isdigit(s[++i] = c = line[line_index++]))
			;
	if (c == '.')
		while (isdigit(s[++i] = c = line[line_index++]))
			;
	s[i] = '\0';
	--line_index;

	return NUMBER;
}

int my_getline(int lim, char s[]) { 

	int c, i;

	for (i = 0; i < lim - 1 && (c = getchar()) != '\n'; i++) {
		s[i] = c;
	}
	if (c == '\n') {
		s[i] = '\n';
		i++;
	}
	s[i] = '\0';
	return i;
}
