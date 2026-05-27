/* Exercise 6-1. Our version of getword does not 
 * properly handle underscores, string constants,
 * comments, or preprocessor control lines. 
 * Write a better version.
 */

#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAXWORD 100

int getword(char *, int);
int binsearch(char *, struct key *, int);

/* count C keywords */
int main()
{
	int n;
	char word[MAXWORD];
	while (getword(word, MAXWORD) != EOF)
		if (isalpha(word[0]))
			if ((n = binsearch(word, keytab, NKEYS)) >= 0)
				keytab[n].count++;

	for (n = 0; n < NKEYS; n++)
		if (keytab[n].count > 0)
			printf("%4d %s\n", keytab[n].count, keytab[n].word);
	return 0;
}
