/*Exercise 5-4. Write the function strend (s, t), 
  which returns 1 if the string t occurs at the 
  end of the string s, and zero otherwise
*/
#include <stdio.h>
#include <string.h>

int strend(char *s, char *t) {
	int slen = strlen(s);
	int tlen = strlen(t);
	if(tlen > slen) //string t is larger than search
		return 0;

	s += slen - 1;
	t += tlen - 1;

	while (tlen > 0) {
		if ((*s-- != *t--))
			return 0;
		tlen--;
	}
	return 1;
}

int main(void) {
	char s[100] = "This is the beginning"; 
	char t[] = "beginning";

	int val = strend(s, t);
	printf("%d\n", val);

	return 0;
}


