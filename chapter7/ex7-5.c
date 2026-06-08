/* Exercise 7-5. Rewrite the postfix calculator of Chapter 4 
 * to use scanf and/or sscanf to do the input and number conversion.
 */

#include <stdio.h>
#include <stdlib.h>

#define STACKSIZE 100
#define LINESIZE 100

void push(double n);
double pop();

char line[LINESIZE];
double stack[STACKSIZE];
int sp = 0;

void getinput();
void inputoptions(char *);


int main() {

	getinput();

	return 0;
}

void getinput() {

	char s1[50];

	printf("Postfix calc: 'p' print stack, 'c' clear, +, -, *, /\n");

	while (fgets(line, LINESIZE, stdin) != NULL) {

		if (sscanf(line, "%s", s1) >= 1)
			inputoptions(s1);

		printf("Total value : %6.4lf\n", stack[0]);
	}
}

void inputoptions(char *s) {
	double temp;
	if(sscanf(s, "%lf", &temp) == 1) {
		push(temp);
		return;
	}

	if (s[0] != '\0' && s[1] == '\0') {

		double op2;
		char c = s[0];
		switch (c) {
			case '+' :
				push(pop() + pop());
				break;

			case '*' :
				push(pop() * pop());
				break;

			case '-' :
				op2 = pop();
				push(pop() - op2);
				break;

			case '/' :
				op2 = pop();
				if (op2 != 0.0)
					push(pop() / op2);
				else
					printf("error: zero div\n");
				break;

			case 'p' :
				printf("Current stack size : %d\n", sp);
				for (int i = sp; i >= 0; i--)
					printf("pos : %d, val : %6lf\n", i, stack[i]);
				break;

			case 'c' :
				sp = 0;
				stack[0] = 0;
				break;

			case 'd' :
				sp--;
				break;

			default :
				printf("error: unknown command %s\n", s);
				break;
		}
	}
}

void push(double n) {
	if (sp > STACKSIZE - 1) {
		printf("error: stack full cannot push %lf\n", n);
		return;
	}

	stack[sp++] = n;
}

double pop() {
	if (sp == 0) {
		printf("error: stack empty cannot pop\n");
		return 0.0;
	}
	return stack[--sp];
}
