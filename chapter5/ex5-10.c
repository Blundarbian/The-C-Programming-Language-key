/* Exercise 5-10. Write the program expr, which 
 * evaluates a reverse Polish expression from the 
 * command line, where each operator or operand 
 * is a separate argument. 
 */
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define BUFSIZE 100

int p = 0;
double stack[BUFSIZE];

void push(double f);
double pop(void);
int options(char *s);

int options(char *s) {
	if (isdigit(s[0])) return 1;

	return 0;
}

void push(double f) {
	if (p != BUFSIZE) {
		stack[p++] = f;
		return; 
	}
	printf("error: push to full stack\n");
	exit(1);
}

double pop(void) {
	if (p != 0) 
		return stack[--p];		

	printf("error: pop on empty stack\n");
	exit(1);
}

int main(int argc, char *argv[]) {

	int i;
	double option;

	for (i = 1; i < argc; i++) {
		if (options(argv[i]))
			push(atof(argv[i]));

		else if (strlen(argv[i]) == 1) {
			// does not check for zero div, or unknown characters...
			switch (argv[i][0]) {
				case '+':
					push(pop() + pop());
					break;
				case '*':
					push(pop() * pop());
					break;
				case '-':
					option = pop();
					push(pop() - option);
					break;
				case '/':
					option = pop();
					push(pop() / option);
					break;
			}
		}
	}

	printf("%f\n", pop());
	
	return 0;
}
