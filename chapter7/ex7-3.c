/* Exercise 7-3. Revise minprintf to handle more 
 * of the other facilities of printf
 */

#include <stdarg.h>
#include <stdio.h>

void minprintf(char *fmt,...); 
/* ... are variadic functions which can take a 
   varible number of arugments */


void minprintf(char *fmt,...) {

	va_list ap; // point to each unnamed arg in turn 
	char *p, *sval;
	int ival;
	double dval;

	va_start(ap, fmt); // make ap point to first arg
	for (p = fmt; *p; p++) {
		if (*p != '%') {
			putchar(*p);
			continue;
		}
		switch (*++p) {

			case 'd' :
				ival = va_arg(ap, int);
				printf("%d", ival);
				break;

			case 'f' :
				dval = va_arg(ap, double);
				printf("%f", dval);
				break;	

			case 's' :
				for (sval = va_arg(ap, char *); *sval; sval++)
					putchar(*sval);
				break;

			case 'o' :
				ival = va_arg(ap, int);
				printf("%o", ival);
				break;

			case 'x' : 
				ival = va_arg(ap, int);
				printf("%x", ival);
				break;

			default :
				putchar(*p);
				break;
		}
	}
	va_end(ap); // clean up when done
}

int main() {

	char *hel = "Hello, Wolrd!";
	int dec = 12345; 
	int oct = 16;
	int hex = 64;

	minprintf("%s\n", hel);
	minprintf("%d\n", dec);
	minprintf("%o\n", oct);
	minprintf("%x\n", hex);

	return 0;
}
