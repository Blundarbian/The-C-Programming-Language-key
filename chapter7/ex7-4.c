/* Exercise 7-4. Write a private version of scanf analogous 
 * to minprintf from the previous section.
 */

#include <stdio.h>
#include <ctype.h>
#include <stdarg.h>

void minscanf(char *fmt,...);

void minscanf(char *fmt,...) {

	va_list ap;
	char *p, *sp;
	int *ip;
	double *dp;

	va_start(ap, fmt);
	for (p = fmt; *p; p++) {

		if (*p != '%')
			continue;

		switch (*++p) {
			case 'd' :
				ip = va_arg(ap, int *);
				scanf("%d", ip);
				break;

			case 'f' :
				dp= va_arg(ap, double *);
				scanf("%lf", dp);
				break;	

			case 's' :
				sp = va_arg(ap, char *);
				scanf("%s", sp);
				break;

			case 'o' :
				ip= va_arg(ap, int *);
				scanf("%o", ip);
				break;

			case 'x' : 
				ip = va_arg(ap, int *);
				scanf("%x", ip);
				break;
		}
	}
	va_end(ap); 
}

int main() {

	char hel[100];
	int dec, oct, hex;

	minscanf("%s\n", hel);
	printf("%s\n", hel);

	minscanf("%d\n", &dec);
	printf("%d\n", dec);

	minscanf("%o\n", &oct);
	printf("%o\n", oct);

	minscanf("%x\n", &hex);
	printf("%x\n", hex);

	return 0;
}
