/* Exercise 7-4. Write a private version of scanf analogous 
 * to minprintf from the previous section.
 */

#include <stdio.h>
#include <ctype.h>
#include <stdarg.h>

void minscanf(char *fmt,...);

void minscanf(char *fmt,...) {

	va_list ap;
	char *p;

	va_start(ap, fmt);
	for (p = fmt; *p; p++) {

		if (*p != '%')
			continue;
	
		switch (*++p) {
			case 'd' :
				int *ip = va_arg(ap, int *);
				scanf("%d", &ival);
				break;

			case 'f' :
				dval = va_arg(ap, double);
				scanf("%lf", &dval);
				break;	

			case 's' :
				for (sval = va_arg(ap, char *); *sval; sval++)
					getchar();
				break;

			case 'o' :
				ival = va_arg(ap, int);
				scanf("%o", &ival);
				break;

			case 'x' : 
				ival = va_arg(ap, int);
				scanf("%x", &ival);
				break;

			default :
				getchar();
				break;
		}
	}
	va_end(ap); 
}

int main() {

	char *hel;
	int dec;
	int oct;
	int hex;

	minscanf("%s\n", &hel);
	printf("%s\n", hel);

	minscanf("%d\n", &dec);

	minscanf("%o\n", &oct);

	minscanf("%x\n", &hex);

	return 0;
}
