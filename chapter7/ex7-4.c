/* Exercise 7-4. Write a private version of scanf analogous 
 * to minprintf from the previous section.
 */

#include <stdio.h>
#include <ctype.h>
#include <stdarg.h>

void minscanf(char *fmt,...);

void minscanf(char *fmt,...) 
{
	va_list ap;
	char *p, *sval;
	int ival;
	double dval;

	va_start(ap, fmt);
	for (p = fmt; *p; p++)
	{
		if (*p != '%')
		{
			putchar(*p);		
			continue;
		}
	}
}
