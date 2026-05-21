/* Exercise 5-12. Extend entab and detab to accept 
 * the shorthand entab -m +n to mean tab stops every 
 * n columns, starting at column m. Choose convenient 
 * (for the user) default behavior.
 */

#include <stdio.h>
#include <stdlib.h>

#define MAX 1000
#define TAB 8

int tabhelper(int col, int i, int s);

int main(int argc, *argv[]) { 

	int i = 1;
	int s = TAB;

	if (argc > 1 && argv[1][0] == '-')
		i = atoi(argv[1][1]);
	if (argc > 2 && argv[2][0] == '+')
		s = atoi(argv[2][1]);

	int c, col = 0;

	while ((c = getchar()) != EOF) {
		
		if (c == '\t') {
			int n = tabhelper(col, i, s);

			while (col < n) {
				putchar(' ');
				col++;
			}
		} else {
			putchar(c);

			if (c == '\n')
				col = 0;
			else
				col++;
		}
	return 0;
}

int tabhelper(int col, int i, int s) {
	if (col < s) 
		return s;
	
	int rate = (col - s) / s + 1;

	return s + TAB * rate;
}
