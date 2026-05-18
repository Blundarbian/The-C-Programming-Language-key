/* Exercise 5-10. Write the program expr, which 
 * evaluates a reverse Polish expression from the 
 * command line, where each operator or operand 
 * is a separate argument. 
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define BUFSIZE 100

int p = 0;
double stack[BUFSIZE];

void push(double f);
double pop(void);

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
		if (isdigit(argv[i][0]))
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
